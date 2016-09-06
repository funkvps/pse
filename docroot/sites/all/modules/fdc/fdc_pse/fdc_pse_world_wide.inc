<?php

function fdc_pse_world_wide_location() {

	require_once('sites/all/themes/fdc_bootstrap/classes/googlemap.multimarker.class.php');
	$mapLatitude = 54.175297;  //54.175297; 
	$mapLongitude = -4.21875;  //-4.21875; 
	$icon = '/sites/all/themes/fdc_bootstrap/img/pin.png';
	$googleMap = new GoogleMap($mapLatitude, $mapLongitude);
	$googleMap->zoom = 2; // 5 as default
	$googleMap->canvasWidth = '100%';
	$googleMap->canvasHeight = '100%';

	$std = new stdClass();
	$std->items = fdc_pse_world_wide_get_all_offices();
	$map = array();


	$map_count = 0;
	foreach ($std->items as $key => $map_items) {


		foreach ($map_items->offices_info as $key => $office) {
			$office_details = $office[0]->offices_info[0];
			$map[$map_count]['markup'] = "<h4>" . $office_details->heading . "</h4> " . $office_details->firstline . "<br/> " . $office_details->secondline . "<br/> "
					. $office_details->county . "<br/> " . $office_details->country . " <br/>" . $office_details->postcode;

			if (!empty($office_details->longitude) && !empty($office_details->longitude)) {							/// check if long and lat is already available 
				$map[$map_count]['long'] = $office_details->longitude;
				$map[$map_count]['lat'] = $office_details->latitude;
			}
			else {																									//otherwise fetch is from google geoencoding api
				$off_location = $office_details->country . " " . $office_details->postcode;
				$loc = get_latlong_from_location($off_location);

				$map[$map_count]['long'] = $loc['long'];
				$map[$map_count]['lat'] = $loc['lat'];
			}

			$map_count ++;
		}
	}
	
	foreach ($map as $key => $map_itms) {
		
		$googleMap->addMarker($map_itms['lat'], 
							  $map_itms['long'], 
							  $map_itms['markup'], "Pse", $key, 'DROP', $icon);
		
	}
	$std->googleMap = $googleMap;

	if (!empty($std)) {
		return $std;
	}
}

function fdc_pse_world_wide_get_all_offices() {
	$query = db_query(
			"
				SELECT
		field_data_field_wwoffice_subtitle.field_wwoffice_subtitle_value,
		field_data_field_wwoffice_title.field_wwoffice_title_value,
		field_data_field_col_wwoffice.field_col_wwoffice_value
		FROM
		node
		INNER JOIN field_data_field_col_wwoffice ON node.nid = field_data_field_col_wwoffice.entity_id
		LEFT JOIN field_data_field_wwoffice_title ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_wwoffice_title.entity_id
		LEFT JOIN field_data_field_wwoffice_subtitle ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_wwoffice_subtitle.entity_id
		ORDER BY
			field_data_field_col_wwoffice.delta ASC

			")->fetchAll();

	if (!empty($query)) {
		foreach ($query as &$value) {

			$value->offices_info = fdc_pse_world_get_office($value->field_col_wwoffice_value);
		}
		return $query;
	}
}

function fdc_pse_world_get_office_title($col_id) {
//	print_r("ererere" .$col_id);
	if (!empty($col_id)) {
		$query = db_query(
				"
		SELECT
			field_data_field_col_wwoffices.field_col_wwoffices_value,
			field_data_field_wwoffices_title.field_wwoffices_title_value
		FROM
			field_data_field_col_wwoffice
		INNER JOIN field_data_field_col_wwoffices ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_col_wwoffices.entity_id
		LEFT JOIN field_data_field_wwoffices_title ON field_data_field_col_wwoffices.field_col_wwoffices_value = field_data_field_wwoffices_title.entity_id
		where field_data_field_col_wwoffices.field_col_wwoffices_value = :col
		ORDER BY
			field_data_field_col_wwoffice.delta ASC

			", array(":col" => $col_id))->fetchObject();

		if (!empty($query)) {
			return $query;
		}
	}
}

function fdc_pse_world_get_office($col_id) {
//	print_r("eriii   " .$col_id);

	if (!empty($col_id)) {
		$query = db_query(
				"
		SELECT
			field_data_field_wwoffice_office.field_wwoffice_office_target_id as target_id,
			field_data_field_wwoffices_title.field_wwoffices_title_value,
			field_data_field_col_wwoffices.field_col_wwoffices_value
		FROM
			node
		INNER JOIN field_data_field_col_wwoffice ON node.nid = field_data_field_col_wwoffice.entity_id
		LEFT JOIN field_data_field_col_wwoffices ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_col_wwoffices.entity_id
		LEFT JOIN field_data_field_wwoffices_title ON field_data_field_col_wwoffices.field_col_wwoffices_value = field_data_field_wwoffices_title.entity_id
		LEFT JOIN field_data_field_wwoffice_office ON field_data_field_col_wwoffices.field_col_wwoffices_value = field_data_field_wwoffice_office.entity_id
		where field_data_field_col_wwoffice.field_col_wwoffice_value = :col
		ORDER BY
			field_data_field_col_wwoffice.delta ASC

			", array(":col" => $col_id))->fetchAll();

		if (!empty($query)) {
			foreach ($query as &$value) {
				$value = fdc_pse_get_all_offices($value->target_id, $value->field_wwoffices_title_value);
			}
			return $query;
		}
	}
}

function fdc_pse_get_all_offices($nid, $office_title) {

	$query = db_query(
			"
		SELECT
			node.nid,
			node.type,
			field_data_field_col_hotels.field_col_hotels_value,
			field_data_field_col_office.field_col_office_value,
			field_data_field_col_directions.field_col_directions_value
		FROM
			node
		INNER JOIN field_data_field_col_office ON node.nid = field_data_field_col_office.entity_id
		LEFT JOIN field_data_field_col_hotels ON node.nid = field_data_field_col_hotels.entity_id
		LEFT JOIN field_data_field_col_directions ON node.nid = field_data_field_col_directions.entity_id
		where node.nid = :nid
			", array(":nid" => $nid))->fetchAll();

	if (!empty($query)) {
		foreach ($query as &$value) {
			$value->offices_info = fdc_pse_world_wide_get_office_info($value->field_col_office_value);
			$value->offices_info_title = $office_title;
			$value->hotel_nid = fdc_pse_world_wide_get_hotels_nid($value->field_col_hotels_value);
			$value->directions_nid = fdc_pse_world_wide_get_directions_nid($value->field_col_directions_value);
		}
		return $query;
	}
}

function fdc_pse_world_wide_get_office_info($col) {
	if (!empty($col)) {
		$query = db_query(
				"SELECT
	node.nid,
	node.type,
	field_data_field_address_title.field_address_title_value AS heading,
	field_data_field_address_firstline.field_address_firstline_value AS firstline,
	field_data_field_address_secondline.field_address_secondline_value AS secondline,
	field_data_field_address_county.field_address_county_value AS county,
	field_data_field_address_country.field_address_country_value AS country,
	field_data_field_address_postcode.field_address_postcode_value AS postcode,
	field_data_field_address_more_info.field_address_more_info_value AS more_info,
	file_managed.uri AS img_path,
	field_data_field_office_latitude.field_office_latitude_value AS latitude,
	field_data_field_office_longitude.field_office_longitude_value AS longitude,
	field_data_field_address_contact_info.field_address_contact_info_value AS contact_info
FROM
	node
INNER JOIN field_data_field_col_office ON node.nid = field_data_field_col_office.entity_id
LEFT JOIN field_data_field_col_address ON field_data_field_col_office.field_col_office_value = field_data_field_col_address.entity_id
LEFT JOIN field_data_field_address_title ON field_data_field_col_address.field_col_address_value = field_data_field_address_title.entity_id
LEFT JOIN field_data_field_address_firstline ON field_data_field_col_address.field_col_address_value = field_data_field_address_firstline.entity_id
LEFT JOIN field_data_field_address_secondline ON field_data_field_col_address.field_col_address_value = field_data_field_address_secondline.entity_id
LEFT JOIN field_data_field_address_county ON field_data_field_col_address.field_col_address_value = field_data_field_address_county.entity_id
LEFT JOIN field_data_field_address_country ON field_data_field_col_address.field_col_address_value = field_data_field_address_country.entity_id
LEFT JOIN field_data_field_address_more_info ON field_data_field_col_address.field_col_address_value = field_data_field_address_more_info.entity_id
LEFT JOIN field_data_field_location_branch_icon ON node.nid = field_data_field_location_branch_icon.entity_id
LEFT JOIN file_managed ON field_data_field_location_branch_icon.field_location_branch_icon_fid = file_managed.fid
LEFT JOIN field_data_field_office_latitude ON field_data_field_col_office.field_col_office_value = field_data_field_office_latitude.entity_id
LEFT JOIN field_data_field_office_longitude ON field_data_field_col_office.field_col_office_value = field_data_field_office_longitude.entity_id
LEFT JOIN field_data_field_address_contact_info ON field_data_field_col_address.field_col_address_value = field_data_field_address_contact_info.entity_id
LEFT JOIN field_data_field_address_postcode ON field_data_field_col_address.field_col_address_value = field_data_field_address_postcode.entity_id
WHERE
	node.`status` = 1
			AND field_data_field_col_office.field_col_office_value =:collection_id
		ORDER BY
			field_data_field_col_office.delta ASC
			", array("collection_id" => $col))->fetchAll();

		if (!empty($query)) {
			return $query;
		}
	}
}

//
//function fdc_pse_world_wide_get_office_info($col) {
//	if (!empty($col)) {
//		$query = db_query(
//				"
//		SELECT
//			node.nid,
//			node.type,
//			field_data_field_address_title.field_address_title_value AS heading,
//			field_data_field_address_firstline.field_address_firstline_value AS firstline,
//			field_data_field_address_secondline.field_address_secondline_value AS secondline,
//			field_data_field_address_county.field_address_county_value AS county,
//			field_data_field_address_country.field_address_country_value AS country,
//			field_data_field_address_postcode.field_address_postcode_value AS postcode,
//			field_data_field_address_more_info.field_address_more_info_value AS more_info,
//			file_managed.uri AS img_path,
//			field_data_field_office_latitude.field_office_latitude_value AS latitude,
//			field_data_field_office_longitude.field_office_longitude_value AS longitude
//		FROM
//			node
//		INNER JOIN field_data_field_col_office ON node.nid = field_data_field_col_office.entity_id
//		LEFT JOIN field_data_field_col_address ON field_data_field_col_office.field_col_office_value = field_data_field_col_address.entity_id
//		LEFT JOIN field_data_field_address_title ON field_data_field_col_address.field_col_address_value = field_data_field_address_title.entity_id
//		LEFT JOIN field_data_field_address_firstline ON field_data_field_col_address.field_col_address_value = field_data_field_address_firstline.entity_id
//		LEFT JOIN field_data_field_address_secondline ON field_data_field_col_address.field_col_address_value = field_data_field_address_secondline.entity_id
//		LEFT JOIN field_data_field_address_county ON field_data_field_col_address.field_col_address_value = field_data_field_address_county.entity_id
//		LEFT JOIN field_data_field_address_country ON field_data_field_col_address.field_col_address_value = field_data_field_address_country.entity_id
//		LEFT JOIN field_data_field_address_postcode ON field_data_field_col_address.field_col_address_value = field_data_field_address_postcode.entity_id
//		LEFT JOIN field_data_field_address_more_info ON field_data_field_col_address.field_col_address_value = field_data_field_address_more_info.entity_id
//		LEFT JOIN field_data_field_location_branch_icon ON node.nid = field_data_field_location_branch_icon.entity_id
//		LEFT JOIN file_managed ON field_data_field_location_branch_icon.field_location_branch_icon_fid = file_managed.fid
//		LEFT JOIN field_data_field_office_latitude ON field_data_field_col_office.field_col_office_value = field_data_field_office_latitude.entity_id
//		LEFT JOIN field_data_field_office_longitude ON field_data_field_col_office.field_col_office_value = field_data_field_office_longitude.entity_id
//		WHERE
//			node.`status` = 1
//			AND field_data_field_col_office.field_col_office_value =:collection_id
//		ORDER BY
//			field_data_field_col_office.delta ASC
//			", array("collection_id" => $col))->fetchAll();
//
//		if (!empty($query)) {
//			return $query;
//		}
//	}
//}

function fdc_pse_world_wide_get_hotels_nid($col) {
	if (!empty($col)) {
		$query = db_query(
				"		SELECT
			field_data_field_col_hotels.field_col_hotels_value,
			field_data_field_hotel.field_hotel_target_id as tnid
		FROM
			field_data_field_col_hotels
		INNER JOIN field_data_field_hotel ON field_data_field_col_hotels.field_col_hotels_value = field_data_field_hotel.entity_id
		LEFT JOIN node ON field_data_field_hotel.field_hotel_target_id = node.nid
		WHERE
			field_data_field_col_hotels.field_col_hotels_value = :collection_id
		AND node.`status` = 1
			", array(":collection_id" => $col)
				)->fetchObject();

		if (!empty($query)) {
			return $query->tnid;
		}
	}
}

function fdc_pse_world_wide_get_directions_nid($col) {
	if (!empty($col)) {
		$query = db_query(
				"
		SELECT
			field_data_field_col_directions.field_col_directions_value,
			field_data_field_direction.field_direction_target_id AS tnid
		FROM
			field_data_field_col_directions
		INNER JOIN field_data_field_direction ON field_data_field_col_directions.field_col_directions_value = field_data_field_direction.entity_id
		LEFT JOIN node ON field_data_field_direction.field_direction_target_id = node.nid
		WHERE
		field_data_field_col_directions.field_col_directions_value = :collection_id
		AND
			node.`status` = 1
			", array(":collection_id" => $col)
				)->fetchObject();

		if (!empty($query)) {
			return $query->tnid;
		}
	}
}

//	$query =db_query(
//			"
//		
//			",array(":"=>$))->fetchAll
//			
//			
//	$query =db_query(
//			"
//		
//			")->fetchAll


/**
 * SELECT
	field_data_field_col_wwoffice.field_col_wwoffice_value,
	field_data_field_wwoffice_subtitle.field_wwoffice_subtitle_value,
	field_data_field_wwoffice_title.field_wwoffice_title_value,
	field_data_field_col_wwoffices.field_col_wwoffices_value,
	field_data_field_wwoffice_office.field_wwoffice_office_target_id
FROM
	node
INNER JOIN field_data_field_col_wwoffice ON node.nid = field_data_field_col_wwoffice.entity_id
LEFT JOIN field_data_field_wwoffice_title ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_wwoffice_title.entity_id
LEFT JOIN field_data_field_wwoffice_subtitle ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_wwoffice_subtitle.entity_id
LEFT JOIN field_data_field_col_wwoffices ON field_data_field_col_wwoffice.field_col_wwoffice_value = field_data_field_col_wwoffices.entity_id
LEFT JOIN field_data_field_wwoffice_office ON field_data_field_col_wwoffices.field_col_wwoffices_value = field_data_field_wwoffice_office.entity_id
ORDER BY field_data_field_col_wwoffice.delta asc
 */
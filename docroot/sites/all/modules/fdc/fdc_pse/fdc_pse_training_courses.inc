<?php

function fdc_pse_training_content($nid) {
	if (!empty($nid)) {

		$query = db_query(
				"SELECT
					field_data_field_content_heading.field_content_heading_value as heading,
					field_data_field_content_body.field_content_body_value as body
				FROM
					node
				INNER JOIN field_data_field_col_content ON node.nid = field_data_field_col_content.entity_id
				LEFT JOIN field_data_field_content_heading ON field_data_field_col_content.field_col_content_value = field_data_field_content_heading.entity_id
				LEFT JOIN field_data_field_content_body ON field_data_field_col_content.field_col_content_value = field_data_field_content_body.entity_id
				WHERE
					node.nid = :nid
			", array(":nid" => $nid)
				)->fetchObject();
		if (!empty($query)) {
			return $query;
		}
	}
}

function fdc_pse_training_products($nid) {
	if (!empty($nid)) {

		$query = db_query(
				"SELECT
					node.nid,
					commerce_product.product_id,
					field_data_field_prod_location.field_prod_location_tid,
					taxonomy_term_data.`name` AS location,
					field_data_field_taxo_currency.field_taxo_currency_value ,
					field_data_field_taxo_flags.field_taxo_flags_alt as img_alt,
					field_data_field_taxo_flags.field_taxo_flags_title as img_title,
					file_managed.uri as img_path
				FROM
					node
        LEFT JOIN field_data_field_pse_training_course AS field_pse_training_course ON field_pse_training_course_target_id = node.nid
        LEFT JOIN commerce_product ON field_pse_training_course.entity_id = commerce_product.product_id
        LEFT JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
				LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
				LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
				LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
				LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
				LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
				WHERE
					node.nid = :nid
				GROUP BY
					taxonomy_term_data.`name`
				ORDER BY
					taxonomy_term_data.`name` ASC
			", array(":nid" => $nid)
				)->fetchAll();
		if (!empty($query)) {
			return $query;
		}
	}
}

function fdc_pse_training_dates() {
	$std = new stdClass();
	$training_dates = fdc_pse_training_get_all_group_dates();
	if (!empty($training_dates)) {
		foreach ($training_dates as $key => $gdates) {
			$std->training->$key->date = $gdates->f_g_start_date;
			$std->training->$key->events = fdc_pse_training_get_all_products_by_date($gdates->group_start_date);
		}
	}


//	if (!empty($date_arrange)) {
//		$std->training = $date_arrange;
//	}

	if (!empty($std)) {
		return $std;
//		return theme('fdc_pse_training_courses_tpl', array('results' => $std));
	}
}
function fdc_pse_training_dates_trim($location="United Kingdom") {
	$std = new stdClass();
	$std_out = array();
	$training_dates = fdc_pse_training_get_all_group_dates();
	//print_r($training_dates);
	if (!empty($training_dates)) {
		foreach ($training_dates as $key => $gdates) {
      $tr = fdc_pse_training_get_all_products_by_date_location($gdates->group_start_date,$location);		 
      if (!empty($tr)) {
        foreach ($tr as $key => $t) {
          array_push( $std_out,$t);
        }
      }
		}
	}

	// there is no training in the location, see all countries
	//echo "std:";
	//print_r($std_out);

	if (empty($std_out)) {
		$std_out = array();
		$training_dates = fdc_pse_training_get_all_group_dates();
		//print_r($training_dates);
		if (!empty($training_dates)) {
			foreach ($training_dates as $key => $gdates) {
				$tr = fdc_pse_training_get_all_products_by_date_withoutlocation($gdates->group_start_date);
				foreach ($tr as $key => $t) {
					array_push($std_out, $t);
				}
			}
		}
	}

	if (!empty($std_out)) {
		return $std_out;
	}
}

function fdc_pse_training_get_all_products_by_date($date) {
	if (!empty($date)) {
		$query = db_query(
				"SELECT
	commerce_product.sku,
	commerce_product.title,
	commerce_product.product_id,
	commerce_product.type,
	CURDATE(),
	FROM_UNIXTIME(
		field_data_field_prod_start_date.field_prod_start_date_value,
		'%Y-%m-%d'
	) AS f_start_date,
	field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
	field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
	field_data_field_prod_stock.field_prod_stock_value AS stock,
	taxonomy_term_data.`name` AS location,
	field_data_field_taxo_currency.field_taxo_currency_value AS country,
	field_data_commerce_price.commerce_price_amount AS currency_amount,
	field_data_commerce_price.commerce_price_currency_code AS currency_code,
	taxonomy_term_data.tid,
	field_data_field_taxo_flags.field_taxo_flags_alt AS img_alt,
	field_data_field_taxo_flags.field_taxo_flags_title AS img_title,
	file_managed.uri AS img_path,
	field_data_field_prod_public.field_prod_public_value AS public_display_text
FROM
	commerce_product
INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
LEFT JOIN field_data_field_prod_public ON commerce_product.product_id = field_data_field_prod_public.entity_id
			WHERE
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) > CURDATE()
				
			AND FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m'
				)  = :date_group
			ORDER BY
				field_data_field_prod_start_date.field_prod_start_date_value ASC
			", array(":date_group" => $date)
				)->fetchAll();
		if (!empty($query)) {
			return $query;
		}
	} 
}

function fdc_pse_training_get_all_products_by_date_location($date,$location) {
	if (!empty($date) && !empty($location)) {
		$query = db_query(
				"SELECT
	commerce_product.sku,
	commerce_product.title,
	commerce_product.product_id,
	commerce_product.type,
	CURDATE(),
	FROM_UNIXTIME(
		field_data_field_prod_start_date.field_prod_start_date_value,
		'%Y-%m-%d'
	) AS f_start_date,
	field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
	field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
	field_data_field_prod_stock.field_prod_stock_value AS stock,
	taxonomy_term_data.`name` AS location,
	field_data_field_taxo_currency.field_taxo_currency_value AS country,
	field_data_commerce_price.commerce_price_amount AS currency_amount,
	field_data_commerce_price.commerce_price_currency_code AS currency_code,
	taxonomy_term_data.tid,
	field_data_field_taxo_flags.field_taxo_flags_alt AS img_alt,
	field_data_field_taxo_flags.field_taxo_flags_title AS img_title,
	file_managed.uri AS img_path,
	field_data_field_prod_public.field_prod_public_value AS public_display_text,
	field_data_field_profile_country.field_profile_country_value as profile_country

FROM
	commerce_product
INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
LEFT JOIN field_data_field_profile_country ON taxonomy_term_data.tid = field_data_field_profile_country.entity_id
LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
LEFT JOIN field_data_field_prod_public ON commerce_product.product_id = field_data_field_prod_public.entity_id
			WHERE
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) > CURDATE()
				
			AND FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m'
				)  = :date_group
				
				AND field_data_field_profile_country.field_profile_country_value = :location

			ORDER BY
				field_data_field_prod_start_date.field_prod_start_date_value ASC LIMIT 3
			", array(":date_group" => $date,":location" =>$location)
				)->fetchAll();
		if (!empty($query)) {
			return $query;
		}
	} 
}

function fdc_pse_training_get_all_products_by_date_withoutlocation($date) {
	if (!empty($date)) {
		$query = db_query(
			"SELECT
	commerce_product.sku,
	commerce_product.title,
	commerce_product.product_id,
	commerce_product.type,
	CURDATE(),
	FROM_UNIXTIME(
		field_data_field_prod_start_date.field_prod_start_date_value,
		'%Y-%m-%d'
	) AS f_start_date,
	field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
	field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
	field_data_field_prod_stock.field_prod_stock_value AS stock,
	taxonomy_term_data.`name` AS location,
	field_data_field_taxo_currency.field_taxo_currency_value AS country,
	field_data_commerce_price.commerce_price_amount AS currency_amount,
	field_data_commerce_price.commerce_price_currency_code AS currency_code,
	taxonomy_term_data.tid,
	field_data_field_taxo_flags.field_taxo_flags_alt AS img_alt,
	field_data_field_taxo_flags.field_taxo_flags_title AS img_title,
	file_managed.uri AS img_path,
	field_data_field_prod_public.field_prod_public_value AS public_display_text


FROM
	commerce_product
INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id

LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
LEFT JOIN field_data_field_prod_public ON commerce_product.product_id = field_data_field_prod_public.entity_id
			WHERE
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) > CURDATE()

			AND FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m'
				)  = :date_group


			ORDER BY
				field_data_field_prod_start_date.field_prod_start_date_value ASC LIMIT 3
			", array(":date_group" => $date)
		)->fetchAll();
		if (!empty($query)) {
			return $query;
		}
	}
}

function fdc_pse_training_get_all_group_dates() {
	$query = db_query(
			"SELECT
				CURDATE(),
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) AS f_start_date,
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%M %Y'
				) AS f_g_start_date,
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m'
				) AS group_start_date,
				field_data_field_prod_start_date.field_prod_start_date_value AS start_date
			FROM
				field_data_field_col_commerce
			LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
			WHERE
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) > CURDATE()
			GROUP BY
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m'
				)
			ORDER BY
				field_data_field_prod_start_date.field_prod_start_date_value ASC LIMIT 3"
			)->fetchAll();
	if (!empty($query)) {
		return $query;
	}
}

function fdc_pse_training_training_url($prod_id) {
  _d('TEST THIS fdc_pse_training_training_url');
	if (!empty($prod_id)) {
		$query = db_query("
		SELECT
				field_pse_training_course_target_id as  nid
			FROM
				field_data_field_pse_training_course
			WHERE
				field_data_field_pse_training_course.entity_id = :prod_id
			LIMIT 1"
				, array(":prod_id" => $prod_id))->fetchObject();
		if (!empty($query)) {
      _d(url('node/' . $query->nid));
			return url('node/' . $query->nid);
		}
	}
}

function fdc_pse_training_get_products_by_location($location_name,$nid) {
	if (!empty($location_name) && !empty($nid)) {
    _d('TEST THIS fdc_pse_training_get_products_by_location');
		$query = db_query(
				"SELECT
					commerce_product.sku,
					commerce_product.title,
					commerce_product.product_id,
					commerce_product.type,
					CURDATE(),
					FROM_UNIXTIME(
							field_data_field_prod_start_date.field_prod_start_date_value,
							'%Y-%m-%d'
						) AS f_start_date,
					field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
					field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
					field_data_field_prod_stock.field_prod_stock_value AS stock,
					taxonomy_term_data.`name` AS location,
					field_data_field_taxo_currency.field_taxo_currency_value AS country,
					field_data_commerce_price.commerce_price_amount AS currency_amount,
					field_data_commerce_price.commerce_price_currency_code AS currency_code
					FROM
					commerce_product
					INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
					LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
					LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
					LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
					LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
					LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
					LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
					LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
          

					LEFT JOIN field_data_field_pse_training_course AS field_pse_training_course ON commerce_product.product_id = field_pse_training_course.entity_id

					WEHRE  			taxonomy_term_data.`name`  = :location
            AND  field_pse_training_course_target_id = :node_id
            AND field_data_field_prod_stock.field_prod_stock_value = 1
            AND commerce_product.`status` = 1

					ORDER BY
						field_data_field_prod_start_date.field_prod_start_date_value ASC
"
				, array(":location" => $location_name,":node_id"=>$nid))->fetchAll();
		if (!empty($query)) {
      _d($query);
			return $query;
		}
	}
}

function fdc_pse_training_get_product($prod_id) {
	if (!empty($prod_id)) {
		$query = db_query(
				"SELECT
				commerce_product.sku,
				commerce_product.title,
				commerce_product.product_id,
				commerce_product.type,
				CURDATE(),
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) AS f_start_date,
				field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
				field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
				field_data_field_prod_stock.field_prod_stock_value AS stock,
				taxonomy_term_data.`name` AS location,
				field_data_field_taxo_currency.field_taxo_currency_value AS country,
				field_data_commerce_price.commerce_price_amount AS currency_amount,
				field_data_commerce_price.commerce_price_currency_code AS currency_code
			FROM
				commerce_product
			INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
			LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
			LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
			LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
			LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
			LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
			LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
			LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
			Where  				commerce_product.product_id = :prod_id
			ORDER BY 
				field_data_field_prod_start_date.field_prod_start_date_value ASC"
				, array(":prod_id" => $prod_id))->fetchObject();
		if (!empty($query)) {
			return $query;
		}
	}
}

function fdc_pse_training_get_all_products() {
	$query = db_query(
			"SELECT
				commerce_product.sku,
				commerce_product.title,
				commerce_product.product_id,
				commerce_product.type,
				CURDATE(),
				FROM_UNIXTIME(
					field_data_field_prod_start_date.field_prod_start_date_value,
					'%Y-%m-%d'
				) AS f_start_date,
				field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
				field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
				field_data_field_prod_stock.field_prod_stock_value AS stock,
				taxonomy_term_data.`name` AS location,
				field_data_field_taxo_currency.field_taxo_currency_value AS country,
				field_data_commerce_price.commerce_price_amount AS currency_amount,
				field_data_commerce_price.commerce_price_currency_code AS currency_code
			FROM
				commerce_product
			INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
			LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
			LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
			LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
			LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
			LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
			LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
			LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
			ORDER BY
				field_data_field_prod_start_date.field_prod_start_date_value ASC"
			)->fetchAll();
	if (!empty($query)) {
		return $query;
	}
}

function fdc_pse_training_ajax_products($nid) {
	if (!empty($nid)) {
		$cart_currency_code = fdc_pse_get_current_cart_set_currency();
		$training_products = fdc_pse_hierachy();
		
		if (!empty($training_products)) {
			include_once(drupal_get_path('module', 'fdc_pse') . '/training_items.inc');
		}
	}
}
//function fdc_pse_training_ajax_products($nid) {
//	if (!empty($nid)) {
//		$cart_currency_code = fdc_pse_get_current_cart_set_currency();
//		$training_products = db_query(
//				"SELECT
//					node.nid,
//					commerce_product.product_id,
//					field_data_field_prod_location.field_prod_location_tid,
//					taxonomy_term_data.`name` AS location,
//					field_data_field_taxo_currency.field_taxo_currency_value ,
//					field_data_field_taxo_flags.field_taxo_flags_alt as img_alt,
//					field_data_field_taxo_flags.field_taxo_flags_title as img_title,
//					file_managed.uri as img_path
//				FROM
//					node
//				INNER JOIN field_data_field_col_courses ON node.nid = field_data_field_col_courses.entity_id
//				LEFT JOIN field_data_field_courses_course ON field_data_field_col_courses.field_col_courses_value = field_data_field_courses_course.entity_id
//				LEFT JOIN commerce_product ON field_data_field_courses_course.field_courses_course_product_id = commerce_product.product_id
//				LEFT JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
//				LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
//				LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
//				LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
//				LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
//				LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
//				WHERE
//					node.nid = :nid
//				GROUP BY
//					taxonomy_term_data.`name`
//				ORDER BY
//					taxonomy_term_data.`name` ASC
//			", array(":nid" => $nid)
//				)->fetchAll();
//		if (!empty($training_products)) {
//			include_once(drupal_get_path('module', 'fdc_pse') . '/training_items.inc');
//		}
//	}
//}

//function fdc_pse_commerce_cart_view() {
//	$prod = commerce_product_load_by_sku('TEST2');
////
////
////	print_r($prod);
////	print_r("\n");
////	print_r($prod->field_eu_price['und'][0]['value']);
//
//	$line_item = commerce_product_line_item_new($prod, 1);
//	$line_item->field_ticket_type['und'][]['value'] = 0;
//	$line_item = commerce_cart_product_add(1, $line_item, FALSE);
//}
//
//function fdc_pse_cart_items() {
//	global $user;
//	$order = commerce_cart_order_load($user->uid);
//	$wrapper = entity_metadata_wrapper('commerce_order', $order);
//
//	foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {
//		$type = $line_item_wrapper->commerce_product->value()->type;
//		print_r($line_item_wrapper->commerce_product->value());
//	}
//}
//
//fdc_pse_training_products($nid) {
//	if (!empty($nid)) {
//
//		$query = db_query(
//				"SELECT
//					field_data_field_courses_course.field_courses_course_product_id AS prod_id
//				FROM
//					node
//				INNER JOIN field_data_field_col_courses ON node.nid = field_data_field_col_courses.entity_id
//				LEFT JOIN field_data_field_courses_course ON field_data_field_col_courses.field_col_courses_value = field_data_field_courses_course.entity_id
//				WHERE
//					node.nid = :nid
//			", array(":nid" => $nid)
//				)->fetchAll();
//		if (!empty($query)) {
//			return $query;
//		}
//	}
//}

	/**
	 * SELECT
	  FROM_UNIXTIME(
	  field_data_field_prod_start_date.field_prod_start_date_value,
	  '%Y-%m-%d'
	  ) AS f_start_date,
	  FROM_UNIXTIME(
	  field_data_field_prod_start_date.field_prod_start_date_value,
	  '%M %Y'
	  ) AS f_g_start_date,
	  node.nid,
	  commerce_product.product_id,
	  commerce_product.title,
	  field_data_commerce_price.commerce_price_amount,
	  field_data_commerce_price.commerce_price_currency_code,
	  field_data_field_prod_start_date.field_prod_start_date_value as start_date,
	  field_data_field_prod_end_date.field_prod_end_date_value as end_date,
	  field_data_field_prod_stock.field_prod_stock_value as stock,
	  field_data_field_prod_location.field_prod_location_tid,
	  taxonomy_term_data.`name` AS location,
	  field_data_field_taxo_currency.field_taxo_currency_value,
	  field_data_field_taxo_flags.field_taxo_flags_alt as img_alt,
	  field_data_field_taxo_flags.field_taxo_flags_title as img_title,
	  file_managed.uri as img_path
	  FROM
	  node
	  INNER JOIN field_data_field_col_courses ON node.nid = field_data_field_col_courses.entity_id
	  LEFT JOIN field_data_field_courses_course ON field_data_field_col_courses.field_col_courses_value = field_data_field_courses_course.entity_id
	  LEFT JOIN commerce_product ON field_data_field_courses_course.field_courses_course_product_id = commerce_product.product_id
	  LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
	  LEFT JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
	  LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
	  LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
	  LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
	  LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
	  LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
	  LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
	  LEFT JOIN field_data_field_taxo_flags ON taxonomy_term_data.tid = field_data_field_taxo_flags.entity_id
	  LEFT JOIN file_managed ON field_data_field_taxo_flags.field_taxo_flags_fid = file_managed.fid
	  WHERE
	  node.nid = :nid
	  ORDER BY
	  taxonomy_term_data.`name` ASC,
	  field_data_field_prod_start_date.field_prod_start_date_value ASC

	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * function fdc_pse_training_get_product($pid) {
	  if (!empty($pid)) {
	  $query = db_query(
	  "SELECT
	  commerce_product.sku,
	  commerce_product.title,
	  commerce_product.product_id,
	  commerce_product.type,
	  CURDATE(),
	  FROM_UNIXTIME(
	  field_data_field_prod_start_date.field_prod_start_date_value,
	  '%Y-%m-%d'
	  ) AS f_start_date,
	  field_data_field_prod_start_date.field_prod_start_date_value AS start_date,
	  field_data_field_prod_end_date.field_prod_end_date_value AS end_date,
	  field_data_field_prod_stock.field_prod_stock_value AS stock,
	  taxonomy_term_data.`name` AS location,
	  field_data_field_taxo_currency.field_taxo_currency_value AS country,
	  field_data_commerce_price.commerce_price_amount AS currency_amount,
	  field_data_commerce_price.commerce_price_currency_code AS currency_code
	  FROM
	  commerce_product
	  INNER JOIN field_data_field_col_commerce ON commerce_product.product_id = field_data_field_col_commerce.entity_id
	  LEFT JOIN field_data_field_prod_start_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_start_date.entity_id
	  LEFT JOIN field_data_field_prod_end_date ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_end_date.entity_id
	  LEFT JOIN field_data_field_prod_location ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_location.entity_id
	  LEFT JOIN field_data_field_prod_stock ON field_data_field_col_commerce.field_col_commerce_value = field_data_field_prod_stock.entity_id
	  LEFT JOIN taxonomy_term_data ON field_data_field_prod_location.field_prod_location_tid = taxonomy_term_data.tid
	  LEFT JOIN field_data_field_taxo_currency ON taxonomy_term_data.tid = field_data_field_taxo_currency.entity_id
	  LEFT JOIN field_data_commerce_price ON commerce_product.product_id = field_data_commerce_price.entity_id
	  WHERE
	  FROM_UNIXTIME(
	  field_data_field_prod_start_date.field_prod_start_date_value,
	  '%Y-%m-%d'
	  ) > CURDATE()
	  AND commerce_product.product_id = product_id
	  ORDER BY
	  field_data_field_prod_start_date.field_prod_start_date_value ASC
	  ", array(":product_id" => $pid)
	  )->fetchAll();
	  if (!empty($query)) {
	  return $query;
	  }
	  }
	  }
	 *  */
	
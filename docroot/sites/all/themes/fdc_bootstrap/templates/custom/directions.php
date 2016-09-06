<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}


/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_page_banner')) {
	$page_banner = fdc_pse_page_banner($node->nid);
}

if (function_exists('fdc_pse_get_node_testimonial')) {
	$testimonials = fdc_pse_get_node_testimonial($node->nid);
}
if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}


if (function_exists('fdc_pse_get_product_side_menu')) {
	$side_menu_disable_bool = fdc_pse_get_product_side_menu($node->nid);
}
if (function_exists('fdc_pse_direction_address')) {
	$fdc_pse_direction_address = fdc_pse_direction_address($node->nid);
}
if (function_exists('fdc_pse_directions')) {
	$fdc_pse_directions = fdc_pse_directions($node->nid);
}

if(function_exists('fdc_pse_direction_long_lat')){
	$fdc_pse_direction_long_lat = fdc_pse_direction_long_lat($node->nid);
}

/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);

/**
 * the google class is used to retrieve the GEOIP of a location. It will return long and lat which can be added to the map
 */
require_once('sites/all/themes/fdc_bootstrap/classes/googlemap.class.php');
//	
$loc = $fdc_pse_direction_address->firstline . " " .$fdc_pse_direction_address->secondline . " " .$fdc_pse_direction_address->county . " "  .$fdc_pse_direction_address->country . " "
			 .$fdc_pse_direction_address->postcode;
	
	
	if(!empty($fdc_pse_direction_long_lat))
	{
		$long = $fdc_pse_direction_long_lat->longitude;
		$lat = $fdc_pse_direction_long_lat->latitude;

	}
	else
	{
		$ar = get_latlong_from_location($loc);
		$long = $ar['long'];
		$lat = $ar['lat'];
		
	}
	

//	print_r($loc);
	
	
	$mapLatitude = $lat;  //54.175297; 
	$mapLongitude = $long;  //-4.21875; 
	$icon = '/sites/all/themes/fdc_bootstrap/img/pin.png';
	$googleMap = new GoogleMap($mapLatitude, $mapLongitude);
	$googleMap->zoom = 17; // 5 as default
	$googleMap->canvasWidth = '100%'; 
	$googleMap->canvasHeight = '100%';
	$map_marker = "<h4>". $fdc_pse_direction_address->address_title . "</h4> " .
			$fdc_pse_direction_address->firstline . "<br/> " .$fdc_pse_direction_address->secondline . "<br/> "
			 .$fdc_pse_direction_address->county . "<br/> "  .$fdc_pse_direction_address->country . " <br/>"
			 .$fdc_pse_direction_address->postcode;
	$key = 1;

	$googleMap->addMarker($lat, $long, $map_marker, "Pse", $key, 'DROP', $icon);
//				print_r($lat);
//	print_r("<br/>");
//	print_r($long);
//	print_r("<br/>");
?>


<?php if (isset($content->heading) && $content->heading) : ?>
	<h1>
		<?php echo $content->heading; ?>
	</h1>
<?php endif; ?>



<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-8 col-lg-8 <?php endif; ?>">

		<section class="content" >


			<?php if (!empty($fdc_pse_direction_address)): ?>
				<div>
				<?php if (!empty($fdc_pse_direction_address->address_title)): ?>
				<div>
					<strong class="address">
						<?php echo $fdc_pse_direction_address->address_title; ?>
					</strong>
				</div>
				<?php endif; ?>
				<?php if (!empty($fdc_pse_direction_address->firstline)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->firstline; ?>
					</span>
				<?php endif; ?>
				</div>
				<div>
				<?php if (!empty($fdc_pse_direction_address->secondline)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->secondline; ?>
					</span>
				<?php endif; ?>
				<?php if (!empty($fdc_pse_direction_address->county)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->county; ?>
					</span>
				<?php endif; ?>
				<?php if (!empty($fdc_pse_direction_address->country)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->country; ?>
					</span>
				<?php endif; ?>
				<?php if (!empty($fdc_pse_direction_address->postcode)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->postcode; ?>
					</span>
				<?php endif; ?>
				</div>
				<div>
				<?php if (!empty($fdc_pse_direction_address->contact_info)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->contact_info; ?>
					</span>
				<?php endif; ?>
				</div>
				<div>
				<?php if (!empty($fdc_pse_direction_address->more_info)): ?>
					<span class="address">
						<?php echo $fdc_pse_direction_address->more_info; ?>
					</span>
				<?php endif; ?>
				</div>
			<?php endif; ?>
			
			<?php if(!empty($content->body)):?>
			<?php echo $content->body;?>
			<?php endif;?>

			<?php if (!empty($lat)): ?>
			<div class="mapholder_wrap">
				<div id="mapholder">
					<div class="map_wrap"  id="googleMapCanvas" >
						<?php echo $googleMap->display();   ?>
					</div>
				</div>
			</div>
			<?php endif; ?>


			<?php if (!empty($fdc_pse_directions)): ?>
				<?php foreach ($fdc_pse_directions as $d) : ?>
				<hr>
					<?php if (!empty($d->title)): ?>
						<h2><?php echo $d->title; ?></h2>
					<?php endif; ?>
					<?php if (!empty($d->body)): ?>
						<div class="directions_body">
							<?php echo $d->body; ?>
						</div>
					<?php endif; ?>

				<?php endforeach; ?>
			<?php endif; ?>

		</section>

	</div>
	<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	<?php endif; ?>
</div>


<?php // call to action with 3 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

<?php // call to action with 4 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>



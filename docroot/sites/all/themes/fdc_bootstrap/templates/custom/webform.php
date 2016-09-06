<?php

// Load content. 'body' and 'heading'
$content = pageContent($node->nid);
// Include child/sibling menu system
$content_menu = child_sibling_menu($node->nid);
// Load Google Group
if (isset($node->field_collection_googlemap[LANGUAGE_NONE][0]['value'])) { 
	$mapfields = field_collection_item_load($node->field_collection_googlemap[LANGUAGE_NONE][0]['value']);
	if ($mapfields->field_googlemap_enable[LANGUAGE_NONE][0]['value'] == 1) {
		$marker_location = $mapfields->field_googlemap_location[LANGUAGE_NONE][0]['value'];
		$marker_content = $mapfields->field_googlemap_marker[LANGUAGE_NONE][0]['value'];
		if (isset($mapfields->field_googlemap_icon[LANGUAGE_NONE][0]['uri'])) {
			$marker_icon = image_style_url('googlemapicon', $mapfields->field_googlemap_icon[LANGUAGE_NONE][0]['uri']);
		} else {
			$marker_icon = NULL;
		}

		// Place into Google Map function (template.php. 
		// Avaiable variables;
		//	$location = Location/Address used for grabbing LAT/LONG
		//	$content = Marker pop-up content
		//	$icon = Image Icon. Ensure ran through Image Style.
		//  $zoom = 15
		//  $width = '240px'
		//  $height = '200px'
		$googlemap = google_map($marker_location, $marker_content, $marker_icon, '10', '100%', '100%');
	}
}	
// Webform 
$submission = (object) array();
$node_form = drupal_get_form('webform_client_form_'.$node->nid, $node, $submission, TRUE);
?>

<?php if (isset($googlemap)) : ?>
	<div class="banner_wrapper">
		<div style="width: 100%; height: 100%;" class="google_map">
				<?php echo $googlemap; ?>
		</div>
	</div>	
<?php endif; ?>
			
<div class="container-fluid background-white">
	<div class="container webform_withmap_content">
	
		<?php if (isset($content_menu) && $content_menu) : ?>
			<div class="col-xs-12 col-sm-12 col-md-2 col-lg-2">						
				<?php if (isset($content_menu)) : ?>
					<?php echo $content_menu; ?>
				<?php endif; ?>						
			</div>
		<?php endif; ?>
				
			<?php if (isset($content_menu) && $content_menu) : ?>
				<div class="col-xs-12 col-sm-12 col-md-10 col-lg-10">
			<?php else: ?>
				<div class="col-xs-12">
			<?php endif; ?>
					
			<div class="row">
				<?php if (!empty($node_form['submitted'])) : ?>
					<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6">
				<?php endif; ?>	
					<h1>
						<?php
							if (strlen($content->heading)) {
								echo $content->heading;
							} else {
								echo $title;
							} 
						?>
					</h1>
					<?php if (strlen($content->body)) : ?>
						<?php echo $content->body; ?> 
					<?php endif; ?>
						
				<?php if (!empty($node_form['submitted'])) : ?>
					</div>
				<?php endif; ?>
				
				<?php if (!empty($node_form['submitted'])) : ?>
					<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6">
							<div class="client_section_form">
								<?php echo render($node_form); ?>
							</div>
					</div>
				<?php endif; ?>	
				
			</div>
					
		</div>			
					
	</div>
</div>

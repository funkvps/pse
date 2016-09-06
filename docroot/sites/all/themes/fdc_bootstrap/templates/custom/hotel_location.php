<?php

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}
if (function_exists('fdc_pse_location_information')) {
	$location = fdc_pse_location_information($node->nid);
}

/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */

$content_menu = child_sibling_menu($node->nid);
?>
<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8">

		<section class="content" >
		<?php if (isset($content->heading) && $content->heading) : ?>
			<h1>
				<?php echo $content->heading; ?>
			</h1>
		<?php endif; ?>

		<?php if (isset($content->body) && $content->body) : ?>
			<?php echo $content->body; ?>
		<?php endif; ?>
		</section>
		
		<?php if (!empty($location)) : ?>
			<?php foreach ($location as $l) : ?>
				<div>
					<div>
						<?php if (!empty($l->hotel_top_content)): ?>
							<?php echo $l->hotel_top_content; ?>
						<?php endif; ?>
					</div>
					<div>
						<?php if (!empty($l->hotel->hotel_name)): ?>
							<h2>
								<?php if (!empty($l->hotel->booking_url)): ?>
									<a href="<?php echo $l->hotel->booking_url; ?>">
								<?php endif; ?>
								<?php echo $l->hotel->hotel_name; ?>
								<?php if (!empty($l->hotel->booking_url)): ?>
									</a>
								<?php endif; ?>
							</h2>
						<?php endif; ?>
					</div>
					<div>
						<?php if (!empty($l->hotel->hotel_address)): ?>
							<?php echo $l->hotel->hotel_address; ?>
						<?php endif; ?>
					</div>
					<div>
						<?php if (!empty($l->hotel->location_tid)): ?>
							<?php //echo fdc_pse_term_name($l->hotel->location_tid); ?>
						<?php endif; ?>
					</div>
					<div>
						<?php if (!empty($l->hotel->body)): ?>
							<?php echo $l->hotel->body; ?>
						<?php endif; ?>
					</div>

				</div>
			<?php endforeach; ?>
		<?php endif; ?>
			
	</div>
	
	<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
	</aside>

</div>
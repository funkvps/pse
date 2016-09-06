<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_event')) {
	$event_content = fdc_pse_event($node->nid);
	if (!empty($event_content->external_link)) {
		drupal_goto($event_content->external_link);
	}
	if (!empty($event_content->page_ref)) {
		$url = url('node/' . $event_content->page_ref);
		drupal_goto($url);
	}
}
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
if (function_exists('fdc_pse_has_form')) {
	$fdc_pse_has_form = fdc_pse_has_form($node->nid);
}
if (function_exists('fdc_pse_node_bottom_content')) {
	$bottom = fdc_pse_node_bottom_content($node->nid);
}


/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);
?>



<div class="row row_extra_negative">
	<?php
	/**
	 * page banner 
	 */
	?>
	<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/page_banner.inc'; ?>
</div>


<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-8 col-lg-8 <?php endif; ?>">

		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<?php if (isset($content->heading) && $content->heading) : ?>
					<h1>
						<?php echo $content->heading; ?>
					</h1>
				<?php endif; ?>

				<?php if (isset($content->body) && $content->body) : ?>
					<?php echo $content->body; ?>
				<?php endif; ?>


			</div>
		</div>
		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<div class="">
					<div class="date">
						<?php if (!empty($event_content->start_date) && !empty($event_content->end_date)): ?>
							<?php if ($event_content->start_date == $product->end_date || $event_content->start_date > $event_content->end_date): ?>
								<?php echo fdc_pse_date_format($event_content->start_date, 'dMY'); ?>			<?php //fdc_pse_date_format use to clean up the date ?>
							<?php else: ?>
								<?php echo fdc_pse_date_format($event_content->start_date, 'dMY'); ?>
								-
								<?php echo fdc_pse_date_format($event_content->end_date, 'dMY'); ?>
							<?php endif; ?>
						<?php endif; ?>
					</div>
				</div>
				<div class="location">
					<?php if (!empty($event_content->location)): ?>
						<?php echo $event_content->location; ?>
					<?php endif; ?>
				</div>
				<div class="involvement">
					<?php if (!empty($event_content->involve_tid)): ?>
						<?php echo fdc_pse_term_name($event_content->involve_tid); ?>
					<?php endif; ?>
				</div>
				<?php if ($fdc_pse_has_form): ?>
					<div class="form_pse">
						<?php
						/**
						 * Looks for the current node for a webform and loads it. 
						 * please view sites\all\modules\fdc\fdc_webform\fdc_webform.module for more information
						 * 
						 */
						webform_node_view($node, 'full');
						print theme_webform_view($node->content);
						?>
					</div>
				<?php endif; ?>
			</div>
		</div>

		<?php if (isset($bottom->body) && $bottom->body) : ?>
			<div class="row equal_children_height">
				<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
					<?php echo $bottom->body; ?>
				</div>
			</div>
		<?php endif; ?>

	</div>

	<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-12 col-md-3 col-lg-3" id="sidebarnobg">
			<?php
			/**
			 * contains all the right hand items eg menu_blocks, menu, testimonial, side content, publication
			 */
			?>

			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	<?php endif; ?>
</div>


<?php // call to action with 3 rows  ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

<?php // call to action with 4 rows  ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>




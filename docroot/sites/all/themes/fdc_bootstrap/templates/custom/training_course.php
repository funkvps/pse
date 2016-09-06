<?php
/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_training_courses.inc
 */
if (function_exists('fdc_pse_training_content')) {
	$page_content = fdc_pse_training_content($node->nid);
}
if (function_exists('fdc_pse_training_products')) {
	$training_products = fdc_pse_training_products($node->nid);
}
/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_get_current_cart_set_currency')) {
	$cart_currency_code = fdc_pse_get_current_cart_set_currency();
}
?>
<div class="row">
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<h1><?php echo $page_content->heading; ?></h1>
	</div>
</div>
<div class="row">
	<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8">
		<section class="content" >
			<?php if (!empty($page_content)): ?>
				<div class="training_body"><?php echo $page_content->body; ?></div>
			<?php endif; ?>
		</section>
	</div>
	<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">

		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<div id="training_products"></div>
			</div>
		</div>
	</aside>
</div>

<?php
	/**
	 * onload gets ecommerce products associated with this training course.
	 * output  on #training_products
	 * the url fetched is a menu item which can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_training_courses.inc
	 */
?>
<script>
	$(function()
	{
		$.ajax({
			type: "GET",
			url: '/fdc_pse_cart/fdc_pse_training_ajax_products/<?php echo $node->nid; ?>',
			data: {
			},
			dataType: "text",
			success: function(msg) {
				$('#training_products').html(msg);
			}
		});

	});
</script>
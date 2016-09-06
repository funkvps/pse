<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_banner')) {
	$page_banner = fdc_pse_banner($node->nid);
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

//dsm($variables);

/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);
?>



<div class="row row_extra_negative">
	<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/page_banner.inc'; ?>
</div>

<?php if (isset($content->heading) && $content->heading) : ?>
	<h1>
		<?php echo $content->heading; ?>
	</h1>
<?php endif; ?>

<div class="row equal_children_height">
	<div class="col-xs-12 <?php if ($side_menu_disable_bool): ?> col-sm-12 col-md-12 col-lg-12 <?php else: ?> col-sm-8 col-md-8 col-lg-8 <?php endif; ?>">

		<section class="content" >
				<?php if (isset($content->body) && $content->body) : ?>
					<?php echo $content->body; ?>
				<?php endif; ?>

				<?php if (function_exists('fdc_pse_publication_bool')): ?>
				<?php $has_publication_bottom = fdc_pse_publication_bool($node->nid);?>
					<?php if($has_publication_bottom ):?>
					<!-- publication -->
					<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/publications_bottom.inc';  ?>
					<?php endif; ?>
				<?php endif; ?>
		</section>


	</div>
	<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">

				hey
				<?php print render($page['social_block']); ?>
<!--			<div class="addthis_sharing_toolbox" ></div>-->
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	<?php endif; ?>
</div>


<?php // call to action with 3 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

<?php // call to action with 4 rows ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>




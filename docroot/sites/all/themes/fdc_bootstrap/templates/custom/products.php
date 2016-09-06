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

/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);
?>


<div class="row  equal_children_height">
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<?php if (!empty($page_banner)): ?>
			<div class="page_banner slick_page_banner">
				<?php foreach ($page_banner as $banner) : ?>
					<div class=" ">
						<?php if (!empty($banner->link_url)): ?>
							<a href='<?php echo $banner->link_url; ?>'>
							<?php endif; ?>
							<img src="<?php echo image_style_url('page_banner_large', $banner->img_path); ?>" 
								 title="<?php if (!empty($banner->img_title)): ?><?php echo $banner->img_title; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
								 alt="<?php if (!empty($banner->img_alt)): ?><?php echo $banner->img_alt; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
								 class="img-responsive" 
								 />

							<div class="">
								<?php if (!empty($banner->heading)): ?>
									<?php echo $banner->heading; ?>
								<?php endif; ?>
							</div>
							<div class="">
								<?php if (!empty($banner->content)): ?>
									<?php echo $banner->content; ?>
								<?php endif; ?>
							</div>
							<?php if (!empty($banner->link_url)): ?>
							</a>
						<?php endif; ?>
					</div>
				<?php endforeach; ?>
			</div>
		<?php endif; ?>
	</div>
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
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

		</div>
		<div class="row equal_children_height">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>

		</div>
	</div>
	<?php if (!$side_menu_disable_bool): ?>
		<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</div>
	<?php endif; ?>
</div>


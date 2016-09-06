<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */
if (function_exists('fdc_pse_get_node_testimonial')) {
	$testimonials = fdc_pse_get_node_testimonial($node->nid);
}

if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}
if (function_exists('fdc_pse_node_bottom_content')) {
	$bottom = fdc_pse_node_bottom_content($node->nid);
}
if (function_exists('fdc_pse_sector_list')) {
	$sector_list = fdc_pse_sector_list($node->nid);
}
if (function_exists('fdc_pse_sector_side_image')) {
	$side_image = fdc_pse_sector_side_image($node->nid);
}
/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);
?>


<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8">

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

		<?php if (!empty($sector_list)) : ?>
			<?php foreach ($sector_list as $r) : ?>
				<div class="row equal_children_height">
					<div class="col-xs-12 col-sm-12 col-md-3 col-lg-3">
						<?php if (!empty($r->list->img_path)): ?>
							<img src="<?php echo image_style_url('sector_icons', $r->list->img_path); ?>" 
								 title="<?php if (!empty($r->list->img_title)): ?><?php echo $r->list->img_title; ?><?php else: ?><?php echo $r->list->title; ?><?php endif; ?>" 
								 alt="<?php if (!empty($r->list->img_alt)): ?><?php echo $r->list->img_alt; ?><?php else: ?><?php echo $r->list->title; ?><?php endif; ?>" 
								 class="img-responsive" 
								 />
							 <?php endif; ?>
					</div>
					<div class="col-xs-12 col-sm-12 col-md-9 col-lg-9">
						<?php if (!empty($r->list->title)): ?>
							<a href ="<?php echo url('node/' . $r->list->nid); ?>">
								<h5> <?php echo $r->list->title; ?></h5>
							</a>
						<?php endif; ?>
						<?php if (!empty($r->list->summary)): ?>
							<div> <?php echo $r->list->summary; ?></div>
						<?php endif; ?>

					</div>
				</div>
			<?php endforeach; ?>

		<?php endif; ?>

		<?php if (isset($bottom->body) && $bottom->body) : ?>
			<div class="row equal_children_height">
				<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
					<?php echo $bottom->body; ?>
				</div>
			</div>
		<?php endif; ?>



		<div class="row equal_children_height">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>
		</div>
		<div class="row equal_children_height">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>
		</div>
	</div>
	<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<?php if (!empty($side_image->img_path)): ?>
					<img src="<?php echo image_style_url('sector_side_image', $side_image->img_path); ?>" 
						 title="<?php if (!empty($side_image->img_title)): ?><?php echo $side_image->img_title; ?><?php else: ?><?php echo $side_image->title; ?><?php endif; ?>" 
						 alt="<?php if (!empty($side_image->img_alt)): ?><?php echo $side_image->img_alt; ?><?php else: ?><?php echo $side_image->title; ?><?php endif; ?>" 
						 class="img-responsive" 
						 />
					 <?php endif; ?>
			</div>
		</div>

		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>

	</div>
</div>



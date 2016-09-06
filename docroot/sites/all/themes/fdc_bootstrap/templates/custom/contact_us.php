<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module
if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}

/**
 * @surf
 * the following methods can be found in /sites/all/modules/fdc/fdc_pse/fdc_pse_func.func
 */


if (function_exists('fdc_pse_node_bottom_content')) {			
	$bottom = fdc_pse_node_bottom_content($node->nid);
}
if (function_exists('fdc_pse_right_contact_us')) {
	$right_contact_us = fdc_pse_right_contact_us($node->nid);
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

<?php if (isset($content->heading) && $content->heading) : ?>
	<h1>
		<?php echo $content->heading; ?>
	</h1>
<?php endif; ?>

<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-8 col-lg-8 <?php endif; ?>">


		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">


				<?php if (isset($content->body) && $content->body) : ?>
					<?php echo $content->body; ?>
				<?php endif; ?>
			</div>
		</div>
		<div class="row equal_children_height">

			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
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
		<aside class="col-xs-12 col-sm-12 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php if (!empty($right_contact_us)): ?>
				<div class="row">
					<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12"> 
						<?php foreach ($right_contact_us as $item): ?>
							<div class="contact-office-item">
								<strong><?php echo $item->office_name; ?></strong> 
								<?php if (!empty($item->tel)): ?>
									<div>
										T: <?php echo $item->tel; ?>
									</div>
								<?php endif; ?>
								<?php if (!empty($item->fax)): ?>
									<div>
										F: <?php echo $item->fax; ?>
									</div>
								<?php endif; ?>
								<?php // if (!empty($item->email) && !empty($item->btn_value) && !empty($item->email_sub)): ?>
								<span class="linkbuttonprimary">
								<a class=""
								   onclick="ga('send', 'event', 'contact', 'email', '<?php echo $item->email; ?>')"								
								   href="mailto:<?php echo $item->email; ?>?subject=<?php echo $item->email_sub; ?>">
									   <?php echo $item->btn_val; ?>
								</a>
								</span>
								<?php // endif; ?>
							</div>
						<?php endforeach; ?>
					</div>
				</div>
			<?php endif; ?>
			<div class="row">
				<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
					<?php
					/**
					 * contains all the right hand items eg menu_blocks, menu, testimonial, side content, publication
					 */
					?>
					
					<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>

				</div>
			</div>
		</aside>
	<?php endif; ?>


</div>
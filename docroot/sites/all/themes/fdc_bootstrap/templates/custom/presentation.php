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

if (function_exists('fdc_pse_presentation')) {
	$fdc_pse_presentation = fdc_pse_presentation($node->nid);
}
if (function_exists('fdc_pse_presentation_bulkfiles')) {
	$fdc_pse_presentation_bulkfiles = fdc_pse_presentation_bulkfiles($node->nid);
}
/**
 * drupal function found in /sites/all/themes/fdc_bootstrap/template.php
 */
$content_menu = child_sibling_menu($node->nid);


$lock = true;

global $user;
if (!$user->uid) {
	$lock = true;
}
else {
	if (fdc_pse_has_presentation_download_access()) {  // check if role is presentation downloader or site maintainer
		$lock = false;
	}
}
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

			<?php if (!empty($fdc_pse_presentation_bulkfiles)): ?>
				<strong>Download all presentations from</strong>
				<ul>
					<?php foreach ($fdc_pse_presentation_bulkfiles as $key => $pres) : ?>
						<?php if (!empty($pres->file_name)): ?>
							<?php $url = file_create_url($pres->file_path); ?>
							<li>
								<?php if (!$lock): ?>
									<?php if (!empty($url)): ?>
										<a href="<?php echo $url ?>"><?php echo $pres->file_name; ?></a>
									<?php endif; ?>
								<?php else: ?>
									<a   data-toggle="modal" data-target="#user_has_no_permissions" data-file="<?php echo $url; ?>"><?php echo $pres->file_name; ?></a>

								<?php endif; ?>


							</li>	
						<?php endif; ?>
					<?php endforeach; ?>
				</ul>
			<?php endif; ?>


			<?php if (!empty($fdc_pse_presentation)): ?>
				<?php foreach ($fdc_pse_presentation as $key => $pres) : ?>
					<?php $url = file_create_url($pres->file_path); ?>

					
					<div class="row">
						<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
							<?php if (!empty($pres->date_title)): ?>
								<h2 class="date"><?php echo $pres->date_title; ?></h2>
							<?php endif; ?>
							<?php if (!empty($pres->heading)): ?>
								<h3 class="heading"><?php echo $pres->heading; ?></h3>
							<?php endif; ?>
						</div>
					</div>
					

					<div class="row">	
						<div class="col-xs-11 col-sm-11 col-md-11 col-lg-11">



							<?php if (!$lock): ?>
								<?php if (!empty($pres->file_path)): ?>
									<h4><a href="<?php echo $url ?>"><?php echo $pres->title; ?></a></h4>
								<?php else: ?>
									<h4><?php echo $pres->title; ?></h4>
								<?php endif; ?>
							<?php else: ?>
								<?php if (!empty($pres->file_path)): ?>
									<h4><a data-toggle="modal" data-target="#user_has_no_permissions" data-file="<?php echo $url; ?>"><?php echo $pres->title; ?></a></h4>
								<?php else: ?>
									<h4><?php echo $pres->title; ?></h4>
								<?php endif; ?>
							<?php endif; ?>

							<?php if (!empty($pres->speakers)): ?>
								<p class="speakers">
									<?php echo $pres->speakers; ?>
								</p>
							<?php endif; ?>
						</div>
						<div class="col-xs-1 col-sm-1 col-md-1 col-lg-1 presentation_download_icon">
							<?php if (!$lock): ?>
								<?php if (!empty($pres->file_path)): ?>
									<a href="<?php echo $url ?>"><img src="/sites/all/themes/fdc_bootstrap/img/i_pdf.png" class="img-responsive"/></a>
								<?php endif; ?>
							<?php else: ?>
								<?php if (!empty($pres->file_path)): ?>
									<a data-toggle="modal" data-target="#user_has_no_permissions" data-file="<?php echo $url; ?>"><img src="/sites/all/themes/fdc_bootstrap/img/i_pdf.png" class="img-responsive"/></a>
								<?php endif; ?>
							<?php endif; ?>
						</div>
					</div>
				<?php endforeach; ?>
			<?php endif; ?>





			<?php if (function_exists('fdc_pse_publication_bool')): ?>
				<?php $has_publication_bottom = fdc_pse_publication_bool($node->nid); ?>
				<?php if ($has_publication_bottom): ?>
					<!-- publication -->
					<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/publications_bottom.inc'; ?>
				<?php endif; ?>
			<?php endif; ?>


		</section>


	</div>
	<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	<?php endif; ?>
</div>


<?php // call to action with 3 rows   ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

<?php // call to action with 4 rows  ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>

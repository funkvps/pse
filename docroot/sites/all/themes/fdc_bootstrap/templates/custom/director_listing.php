<?php
//meta stuff /sites/all/modules/fdc/fdc_meta/fdc_meta.module

if (function_exists('fdc_add_meta')) {   // ADDS META 
	fdc_add_meta($node_id);
}
if (function_exists('fdc_pse_get_all_directors')) {
	$directors = fdc_pse_get_all_directors();
}
?>

<section id="content">

	<a name='top'></a>

	<h1>The Board</h1>

	<div class="row equal_children_height">
		<div class="col-xs-12 col-sm-9 col-md-8 col-lg-8">

			<?php if (!empty($directors)): ?>
				<p class="index_listing">
					<?php foreach ($directors as $key => $d) : ?>
						<a href='#<?php echo "d" . $key; ?>'><?php echo $d->dir_name; ?></a> - <?php echo $d->dir_position; ?>
						<br />
					<?php endforeach; ?>
				</p>
			<?php endif; ?>


			<?php if (!empty($directors)): ?>
				<?php foreach ($directors as $key => $d) : ?>
					<div class="biographies">
						<a name='<?php echo "d" . $key; ?>'></a>

						<div class="biography_title">
							<h3><?php echo $d->dir_name; ?> </h3>
							<?php echo $d->dir_position; ?>
						</div>



												<!-- 							<img src="<?php // echo image_style_url('director_image', $d->img_path);       ?>" 
																				 title="<?php // if (!empty($d->img_title)):       ?><?php // echo $d->img_title;       ?><?php // else:       ?><?php // echo $node->title;       ?><?php // endif;       ?>" 
																				 alt="<?php // if (!empty($d->img_alt)):       ?><?php // echo $d->img_alt;       ?><?php // else:       ?><?php // echo $node->title;       ?><?php // endif;       ?>" 
																				 class="img-responsive thumb" 
																				 style="clear:both" 
																			/> -->

						<?php if (!empty($d->dire_content)): ?>
							<?php echo $d->dire_content; ?>
						<?php endif; ?>

						<p><a href='#top' class="btn-backtotop">Top</a></p>


					</div>
				<?php endforeach; ?>
			<?php endif; ?>
		</div>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php
			/**
			 * contains all the right hand items eg menu_blocks, menu, testimonial, side content, publication
			 */
			?>
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	</div>

</section>
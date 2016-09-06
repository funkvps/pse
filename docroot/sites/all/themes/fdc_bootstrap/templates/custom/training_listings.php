<?php
if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}

if (function_exists('fdc_pse_get_product_side_menu')) {
	$side_menu_disable_bool = fdc_pse_get_product_side_menu($node->nid);
}

?>

<?php if (function_exists('fdc_pse_training_dates')): ?>
	<?php $results = fdc_pse_training_dates(); ?>

<?php // print_r($results);?>
<?php endif; ?>
<?php if (function_exists('fdc_pse_node_side_content')): ?>
	<?php $side_content = fdc_pse_node_side_content($node->nid); ?>
<?php endif;?>


<?php if (isset($content->heading) && $content->heading) : ?>
	<h1>
		<?php echo $content->heading; ?>
	</h1>
<?php endif; ?>
<?php if (isset($content->body) && $content->body) : ?>
	<?php echo $content->body; ?>
<?php endif; ?>

<?php if (!empty($results->training)): ?>
	<div class="row"> 
	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-8 col-lg-8 <?php endif; ?>">

		<section class="content" >
			<table class="table table-hover product_listing_table">
				<tr>
					<th class="table_th_date">Date</th>
					<th class="table_th_course">Course</th>
					<th class="table_th_location">Location</th> 
					
				</tr>
				<?php foreach ($results->training as $training) : ?>
					<tr>
						<td colspan="3">
							<div class="training_month_date"><?php echo $training->date; ?></div>
						</td>
					</tr>
					<?php if (!empty($training->events)): ?>
						<?php foreach ($training->events as $evnts) : ?>
							<?php $url = fdc_pse_training_training_url($evnts->product_id); ?>
							<?php if (!empty($url)): ?>
								<tr
										<?php if($evnts->stock == 0):?>
										class="product_outofstock"
										<?php else:?>
										class="product_instock"
										<?php endif;?>
								>
									<td>		
										<?php if ($evnts->start_date == $evnts->end_date || $evnts->start_date > $evnts->end_date): ?>
											<?php echo date('j', $evnts->start_date); ?> 
										<?php else: ?>
											<?php echo date('j', $evnts->start_date); ?>-<?php echo date('j', $evnts->end_date); ?> 
										<?php endif; ?>
									</td>
									<td>
										<?php if($evnts->stock == 0):?>
										<span>
											<?php if(!empty($evnts->public_display_text)):?>
											<?php echo $evnts->public_display_text; ?>
											<?php endif;?>
										</span>
										<?php else:?>
										<a href="<?php echo fdc_pse_training_training_url($evnts->product_id); ?>">
											<?php if(!empty($evnts->public_display_text)):?>
											<?php echo $evnts->public_display_text; ?>
											<?php endif;?>
										</a>
										<?php endif;?>

									</td>
									<td>
										<?php if (!empty($evnts->img_path)): ?>
											<img 
												class="img-responsive pull-left listing-flag"
												src="<?php if (!empty($evnts->img_path)): ?><?php echo image_style_url('flag_small', $evnts->img_path); ?><?php endif; ?>" 
												title="<?php if (!empty($evnts->img_title)): ?><?php echo $evnts->img_title; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
												alt="<?php if (!empty($evnts->img_alt)): ?><?php echo $evnts->img_alt; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
												/>
										<?php endif; ?>
										<span class="listing-location">
											<?php echo $evnts->location; ?><?php $location = fdc_pse_term_parent($evnts->tid); ?><?php if (!empty($location->name)): ?>, <?php echo $location->name;?>
											<?php endif;?>
										</span>
									</td>
								</tr>
							<?php endif; ?>
						<?php endforeach; ?>
					<?php endif; ?>


					<?php // print_r($value);?>
				<?php endforeach; ?>
			</table>

		</section>
		</div>
		<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
		<?php endif; ?>
	</div>

<?php endif; ?>


<?php
//the following is for a normal user
?>



	<?php if (function_exists('fdc_pse_training_dates_trim')): ?>
		<?php $location = $results->user_location; ?>

		<?php $res = fdc_pse_training_dates_trim($location); ?>


	<?php endif; ?>
	<?php if (!empty($res)): ?>
		<div>
			<h3>Training courses</h3>
		</div>

		<div class="row"> 
			<div class="col-xs-12 col-sm-12">

				<section class="content" >
					<table class="table product_listing_table">
						<tr>
							<th class="date">Date</th>
							<th class="title">Course</th>
							<th class="location">Location</th> 

						</tr>
						<?php if (!empty($res)): ?>
							<?php foreach ($res as $key => $evnts) : ?>
									
								<?php if ($key < 99999): ?>

									<?php $url = fdc_pse_training_training_url($evnts->product_id); ?>

									<?php if (!empty($url)): ?>
										<tr
										<?php if ($evnts->stock == 0): ?>
												class="product_outofstock"
											<?php else: ?>
												class="product_instock"
											<?php endif; ?>
											>
											<td>		
												<?php if ($evnts->start_date == $evnts->end_date || $evnts->start_date > $evnts->end_date): ?>
													<?php echo date('d-M-Y', $evnts->start_date); ?> 
												<?php else: ?>
													<?php echo date('d-M-Y', $evnts->start_date); ?> to <br/><?php echo date('d-M-Y', $evnts->end_date); ?> 
												<?php endif; ?>
											</td>
											<td>
												<?php if ($evnts->stock == 0): ?>
													<span>
														<?php if (!empty($evnts->public_display_text)): ?>
															<?php echo $evnts->public_display_text; ?>
														<?php endif; ?>
													</span>
												<?php else: ?>
													<a href="<?php echo fdc_pse_training_training_url($evnts->product_id); ?>">
														<?php if (!empty($evnts->public_display_text)): ?>
															<?php echo $evnts->public_display_text; ?>
														<?php endif; ?>
													</a>
												<?php endif; ?>

											</td>
											<td >
												<?php if (!empty($evnts->img_path)): ?>
													<img 
														class="img-responsive pull-left listing-flag"
														src="<?php if (!empty($evnts->img_path)): ?><?php echo image_style_url('flag_small', $evnts->img_path); ?><?php endif; ?>" 
														title="<?php if (!empty($evnts->img_title)): ?><?php echo $evnts->img_title; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
														alt="<?php if (!empty($evnts->img_alt)): ?><?php echo $evnts->img_alt; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
														/>
													<?php endif; ?>
												<span class="listing-location">
													<?php echo $evnts->location; ?><?php $location = fdc_pse_term_parent($evnts->tid); ?><?php if (!empty($location->name)): ?>, <?php echo $location->name; ?>
													<?php endif; ?>
												</span>
											</td>
										</tr>
									<?php endif; ?>
								<?php endif; ?>
							<?php endforeach; ?>
						<?php endif; ?>

					</table>

				</section>
			</div>
		</div>

	<?php endif; ?>



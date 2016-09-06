	<?php if (!empty($results->related_tagged_training)): ?>

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
						<?php $counter = 0;  ?>
						<?php foreach ($results->related_tagged_training as $training) : ?>

								<?php //print_r($training); ?>
									<?php $counter ++; ?>
									<?php $url = fdc_pse_training_training_url($training->product_id); ?>
									<?php //echo "url::".$url;?>
									<?php if (!empty($url)): ?>
										<tr
										<?php if ($training->stock == 0): ?>
												class="product_outofstock"
											<?php else: ?>
												class="product_instock"
											<?php endif; ?>
											>
											<td>		
												<?php if ($training->start_date == $training->end_date || $training->start_date > $training->end_date): ?>
													<?php echo date('d-M-Y', $training->start_date); ?> 
												<?php else: ?>
													<?php echo date('d-M-Y', $training->start_date); ?> to <br/><?php echo date('d-M-Y', $training->end_date); ?> 
												<?php endif; ?>
											</td>
											<td>
												<?php if ($training->stock == 0): ?>
													<span>

															<?php echo $training->public_display_text; ?>

													</span>
												<?php else: ?>
													<a href="<?php echo $url; ?>">

															<?php echo $training->public_display_text; ?>

													</a>
												<?php endif; ?>

											</td>
											<td>
												<?php if (!empty($training->img_path)): ?>
													<img 
														class="img-responsive pull-left listing-flag"
														src="<?php if (!empty($training->img_path)): ?><?php echo image_style_url('flag_small', $training->img_path); ?><?php endif; ?>" 
														title="<?php if (!empty($training->img_title)): ?><?php echo $training->img_title; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
														alt="<?php if (!empty($training->img_alt)): ?><?php echo $training->img_alt; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
														/>
													<?php endif; ?>
												<span class="listing-location">
													<?php echo $training->location; ?><?php $location = fdc_pse_term_parent($training->tid); ?>
													<?php if (!empty($location->name)): ?>, <?php echo $location->name; ?>
													<?php endif; ?>
												</span>
											</td>
										</tr>
									<?php endif; ?>
								<?php endforeach; ?>


					</table>

				</section>
			</div>
		</div>

	<?php endif; ?>


<?php // print_r($results->items);  ?>

<?php if (!empty($results->items)): ?>
	<?php foreach ($results->items as $key => $r) : ?>
		<div class="row">
		<?php $counter2 = 1; ?>

			<?php // print_r($r); ?>
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
 
				<?php if (!empty($r->field_wwoffice_title_value)): ?>
					<h2><?php echo $r->field_wwoffice_title_value; ?></h2>
				<?php endif; ?>
				<?php if (!empty($r->field_wwoffice_subtitle_value)): ?>
					<h3> <?php echo $r->field_wwoffice_subtitle_value; ?></h3>
				<?php endif; ?>
				<div class="row ">
					<?php foreach ($r->offices_info as $c) : ?>
						<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 office_item ">

							<?php $office = $c[0]; ?>

							<?php // print_r($office); ?>
							<?php if (!empty($office->offices_info)): ?>
								<?php $office_info = $office->offices_info[0]; ?>
								<?php if (!empty($office_info)): ?>
									<?php if (!empty($office->offices_info_title)): ?>
										<strong><?php echo $office->offices_info_title; ?></strong>
									<?php endif; ?>
									<div class="office_info">
										<?php if (!empty($office_info->heading)): ?>
											<?php echo $office_info->heading; ?>
										<?php endif; ?>
										<?php if (!empty($office_info->firstline)): ?>
											<br />
											<?php echo $office_info->firstline; ?>
										<?php endif; ?>

										<?php if (!empty($office_info->secondline)): ?>
											<br />
											<?php echo $office_info->secondline; ?>
										<?php endif; ?>

										<?php if (!empty($office_info->county)): ?>
											<br />
											<?php echo $office_info->county; ?>
										<?php endif; ?>
										<?php if (!empty($office_info->postcode)): ?>
											<br />
											<?php echo $office_info->postcode; ?>
											<?php //echo $office_info->secondline; ?>
										<?php endif; ?>

										<?php if (!empty($office_info->country)): ?>
											<br />
											<?php echo $office_info->country; ?>
										<?php endif; ?>

										<?php if (!empty($office_info->country)): ?>
											<div class="office_contact_info">
											<?php echo $office_info->contact_info; ?>
											</div>
										<?php endif; ?>
									</div>
								<?php endif; ?>
								
								<div class="more">
									<?php if (!empty($office->hotel_nid)): ?>
										[<a href="<?php echo url('node/' . $office->hotel_nid); ?>">Hotel</a>]&nbsp;
									<?php endif; ?> 

									<?php if (!empty($office->directions_nid)): ?>
										[<a href="<?php echo url('node/' . $office->directions_nid); ?>">Directions</a>]
									<?php endif; ?>
								</div>
								<?php if (!empty($office_info->more_info)): ?>
									<br />
									<?php echo $office_info->more_info; ?>
									<br />
								<?php endif; ?>
							</div>
						<?php endif; ?>
					<?php if ($counter % 2) :?>
							<?php else:?>
								</div> 
									<div class="row equal_children_height">

						<?php endif;?>
					<?php	$counter ++; ?>
					<?php endforeach; ?>
				</div>
			</div>
		</div>
	<?php endforeach; ?>
<?php endif; ?>

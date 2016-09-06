<?php if (function_exists('fdc_pse_breadcrumbs')): ?>
	<?php $fdc_pse_breadcrumbs = fdc_pse_breadcrumbs($node->nid); ?>
	<?php if (!empty($fdc_pse_breadcrumbs)): ?>
		<?php echo $fdc_pse_breadcrumbs; ?>
	<?php else: ?>
		<?php //if (!empty($breadcrumb)): print $breadcrumb; endif;    ?>
	<?php endif; ?>
<?php endif; ?>

<?php if (function_exists('fdc_pse_node_bottom_content')) : ?>
	<?php $bottom = fdc_pse_node_bottom_content($node->nid); ?>
<?php endif; ?>	

<?php if (function_exists('fdc_pse_node_side_content')): ?>
	<?php $side_content = fdc_pse_node_side_content($node->nid); ?>
<?php endif; ?>
<?php if (function_exists('fdc_pse_get_product_side_menu')): ?>
	<?php $side_menu_disable_bool = fdc_pse_get_product_side_menu($node->nid); ?>
<?php endif; ?>


<?php if (function_exists('fdc_pse_training_get_training_heading')): ?>
	
<?php endif; ?>



<?php 
if (empty($tid)) {
  $tid = 9999999;
}
$events_terms = taxonomy_get_tree(33); dsm($events_terms); // terms should be changed to products, sectors, regions
?>
<?php if (!empty($node)): ?>
	<?php
	if (function_exists('fdc_pse_node_content')) {
		$content = fdc_pse_node_content($node->nid);
	}
	?>
<?php endif; ?>

<?php if (isset($content->heading) && $content->heading) : ?>
	<h1>
		<?php echo $content->heading; ?>
	</h1>
<?php endif; ?>




<div class="row ">

	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<section class="content" >
			<?php if (isset($content->body) && $content->body) : ?>
				<?php echo $content->body; ?>
			<?php endif; ?>		
		</section>
		<?php ?>
    <div class="sort_filters hidden-xs">
			<a class="" href="/events">All</a>
			<?php foreach ($events_terms as $e) : ?>
				<a class="  <?php if ($tid == $e->tid): ?> active <?php endif; ?>" href="<?php echo '/events/' . fdc_pse_urlSanitizer($e->name); ?>"><?php echo $e->name; ?></a>
			<?php endforeach; ?>
		</div>

		<div class="visible-xs">
			<select class="select_mob form-control">
				<option class="" value="/events">All</option>
				<?php foreach ($events_terms as $e) : ?>
					<option value="<?php echo '/events/' . fdc_pse_urlSanitizer($e->name); ?>"><?php echo $e->name; ?></option>
				<?php endforeach; ?>
			</select>
		</div>
    <?php ?>
	</div>

	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-9 col-lg-9 <?php endif; ?>">
		<section class="content" >	




			<?php if (!empty($results->training)): ?>
				<div class="row"> 
					<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

						<table class="table table-events ruledtable">
							<tr>
								<th class="cell-date">Date</th>
								<th class="cell-type">Type</th>
								<th>Event</th>
								<th> </th>
								<th class="cell-location">Location</th> 
								<th class="pse-involvement">PSE Involvement</th>
							</tr>

							<?php foreach ($results->training as $training) : ?>
								<tr>
									<td colspan="6">
										<div class="training_month_date"><?php echo $training->date; ?></div>
									</td>

								</tr>
								<?php if (!empty($training->events)): ?>
									<?php foreach ($training->events as $evnts) : ?>


										<?php $no_link = fdc_pse_event_link($evnts->nid); ?>
										<?php $no_tbc = fdc_pse_event_tbc($evnts->nid); ?>

										<?php if ($no_link == 0): ?>
											<?php if (!empty($evnts->page_ref) || !empty($evnts->external_link)): ?>
												<?php if (!empty($evnts->page_ref)): ?>
													<?php $url = url('node/' . $evnts->page_ref); ?>
												<?php endif; ?>

												<?php if (!empty($evnts->external_link)): ?>
													<?php $url = $evnts->external_link; ?>
												<?php endif; ?>
											<?php else: ?>
												<?php $url = url('node/' . $evnts->nid); ?>
											<?php endif; ?>
										<?php else: ?>
											<?php $url = ""; ?>

										<?php endif; ?>



										<tr>
											<td class="cell-date">		
												<?php if($no_tbc == 0):?>
												<?php if ($evnts->start_date == $evnts->end_date || $evnts->start_date > $evnts->end_date): ?>
													<?php echo date('j', $evnts->start_date); ?> 
												<?php else: ?>
													<?php echo date('j', $evnts->start_date); ?>-<?php echo date('j', $evnts->end_date); ?> 
												<?php endif; ?>
													<?php else:?>
													TBC
													<?php endif;?>
											</td>
											<td class="cell-type">
												<?php echo fdc_pse_term_name($evnts->event_type_tid); ?>
											</td>
											<td class="cell-title">
												<?php if (!empty($url)): ?><a href="<?php echo $url; ?>"><?php endif; ?>
												<?php //echo $evnts->event_heading; ?>
												<?php echo $evnts->title; ?>

													<?php if (!empty($url)): ?></a><?php endif; ?>

											</td>
											<td class="cell-flag">
												<?php if (!empty($evnts->uri)): ?>
													<img 
														class="listing-flag"
														src="<?php if (!empty($evnts->uri)): ?><?php echo image_style_url('flag_small', $evnts->uri); ?><?php endif; ?>" 
														title="<?php if (!empty($evnts->img_title)): ?><?php echo $evnts->img_title; ?><?php else: ?> <?php echo $evnts->title; ?> 	<?php endif; ?>" 
														alt="<?php if (!empty($evnts->img_alt)): ?><?php echo $evnts->img_alt; ?><?php else: ?> <?php echo $evnts->title; ?> 	<?php endif; ?>" 
														/>
													<?php endif; ?>
											</td>
											<td class="cell-location">
												<?php echo $evnts->location; ?>
											</td>
											<td class="pse-involvement">
												<?php echo fdc_pse_term_name($evnts->involve_tid); ?>
											</td>
										</tr>

									<?php endforeach; ?>
								<?php endif; ?>


								<?php // print_r($value); ?>
							<?php endforeach; ?>
						</table>



					</div>
				</div>

			<?php else: ?>
				<div class="row"> 
					<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
						<h3> No events available for this category</h3>
					</div>
				</div>
			<?php endif; ?>




			<?php if (function_exists('fdc_pse_publication_bool')): ?>
				<?php $has_publication_bottom = fdc_pse_publication_bool($node->nid); ?>
				<?php if ($has_publication_bottom): ?>
					<h2 id="publications">Publications</h2>
					<p>Find out more about by downloading our publications, flyers and information on previous projects.</p>
					<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/publications_bottom.inc'; ?>
				<?php endif; ?>
			<?php endif; ?>



			<?php if (isset($bottom->body) && $bottom->body) : ?>
				<div class="row equal_children_height">
					<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
						<?php echo $bottom->body; ?>
					</div>
				</div>
			<?php endif; ?>



		</section>
	</div>

	<?php if (!$side_menu_disable_bool): ?>
		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 pull-right" id="sidebarnobg">
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
		</aside>
	<?php endif; ?>
</div>




<?php if (!empty($results->related_events)): ?>
	<?php $latest_events = $results->related_events; 
	
	?>
	<article>
		<header>
			<h2>Related Events</h2>
			<ul class="row diary">
				<?php foreach ($latest_events as $evnts) : ?>
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


					<li class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
						<?php if (!empty($url)): ?>
						<!-- <a href="<?php //echo url('node/' . $evnts->nid); ?>"> -->
						<a href="<?php echo $url ?>">
						<?php else : ?>
							<span>
						<?php endif; ?>
							<?php if (!empty($evnts->title)): ?>
								<?php echo $evnts->title; ?>
							<?php endif; ?>
							<?php if (!empty($evnts->start_date)): ?>
								<?php if ($evnts->start_date == $evnts->end_date || $evnts->start_date > $evnts->end_date): ?>
									<?php echo date('d-m-Y', $evnts->start_date); ?> 
								<?php else: ?>
									<?php echo date('d-m-Y', $evnts->start_date); ?> - 
									<?php echo date('d-m-Y', $evnts->end_date); ?> 
								<?php endif; ?>
							<?php endif; ?>
							<?php if (!empty($evnts->event_type_tid)): ?>
								<?php echo fdc_pse_term_name($evnts->event_type_tid); ?>
							<?php endif; ?>
						<?php if (!empty($url)): ?>
							</a>
						<?php else : ?>
							</span>
						<?php endif; ?>
					</li>
				<?php endforeach; ?>
		</header>
		<footer>
			<a href="/events" class="more-events more-content-arrow">more events ...</a>
		</footer>
	</article>
<?php else: ?>
	<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/events.inc'; ?>

<?php endif; ?>
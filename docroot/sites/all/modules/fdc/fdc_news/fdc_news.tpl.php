<?php
if (function_exists('fdc_pse_news_features')) {
	$fdc_pse_news_features = fdc_pse_news_features();
}
?>
<?php include DRUPAL_ROOT . '/sites/all/modules/fdc/fdc_news/inc/feature_calc.inc'; ?>
<div class="news_page">
	<div class="row">

		<div class="col-xs-12 col-sm-8 col-md-8 col-lg-8">

            <div class="row news_list" >
				<?php include DRUPAL_ROOT . '/sites/all/modules/fdc/fdc_news/inc/feature_main.inc'; ?>
			</div>

		</div>

		<aside class="col-xs-12 col-sm-3 col-md-3 col-lg-3 news_nav_col pull-right hidden-xs">
			<div class="news_nav">

				<div class="pad">
					<?php
					// Output news Nav menu, contained within fdc_news.module.
					print fdc_news_navigation();
					?>
				</div>

			</div>
		</aside>
	</div>

	<div class="row">
		<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

            <div class="row row_extra_negative news_list_featured" >
				<?php include DRUPAL_ROOT . '/sites/all/modules/fdc/fdc_news/inc/features.inc'; ?>
			</div>
			
			<?php								
			$content['news'] = array_slice($content['news'],0,8);			// array contains all the news events - keeps 8 and removes the rest
			?>
			
			
            <div class="row news_list equal_children_height" >
			<?php $counter2 = 1; ?>

				<?php if (isset($content['news']) && ($content['news'][0]->nid > 0)) : ?>
					<?php foreach ($content['news'] AS $news) : ?>

						<?php
						if (function_exists('fdc_pse_news_summary')) {
							$summary = fdc_pse_news_summary($news->nid);
						}
						if (function_exists('fdc_pse_news_press_pdf_link')) {
							$pdf_link = fdc_pse_news_press_pdf_link($news->nid);
						}
						if (function_exists('fdc_pse_news_additional_link')) {
							$additional_link = fdc_pse_news_additional_link($news->nid);
						}

						?>
						<?php // if (isset($news->image) && $news->image) : ?>
							<div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">

								
									
									
								<div class="news_item ">
									<div class="pad">
										<?php if (isset($news->date) && $news->date) : ?>
											<p class="date">
												<?php echo date('j F Y', $news->date); ?>
											</p> 
										<?php endif; ?>
										<h2>
											<a href="<?php echo url('node/' . $news->nid); ?>">	
												<?php
												if (isset($news->heading) && $news->heading) {
													echo $news->heading;
												}
												else {
													echo $news->title;
												}
												?>
											</a> 
										</h2>


										<?php $fdc_news_get_multiple_categories = fdc_news_get_multiple_categories($news->nid); ?>
										<?php if (!empty($fdc_news_get_multiple_categories)): ?>
											<p class="category">
												<?php $num_of_items = count($fdc_news_get_multiple_categories); ?>
												<?php $counter = 1; ?>
												<?php foreach ($fdc_news_get_multiple_categories as $cat) : ?>

													<a href="/news/<?php echo str_replace(array('--'), array('-'), str_replace('+', '-', urlencode(strtolower(preg_replace('/[^A-Za-z0-9-]/', '', iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', str_replace(' ', '-', str_replace('&', '', $cat->category)))))))); ?>">
														<?php echo $cat->category; ?><?php if ($num_of_items > $counter): ?>,<?php endif; ?>
													</a>
													<?php $counter ++; ?>
												<?php endforeach; ?>
											</p>
										<?php endif; ?>
										<?php if (!empty($summary)): ?>
											<div class="news_summary">

												<?php echo $summary->summary; ?>
											</div>
										<?php endif; ?>

										<?php if (!empty($additional_link)): ?>
											<div class="news_additional_link">
												<a href="<?php echo $additional_link->link_url; ?>">
													<?php echo $additional_link->link_text; ?>
												</a>
											</div>
										<?php endif; ?>
										<?php if (!empty($pdf_link)): ?>
											<div class="news_pdf_link">
												<a href="<?php echo file_create_url($pdf_link->file_path); ?>">
													<span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
												</a>
											</div>
										<?php endif; ?>
									</div>
								</div>
									
									
							</div> 
						<?php // endif; ?>
						<?php if ($counter2 % 4) :?>
							<?php else:?>
										</div> 
											<div class="row equal_children_height">

						<?php endif;?>
						<?php $counter2 ++; ?>
												
					<?php endforeach; ?>
				<?php endif; ?>

            </div>

			<div class="">
				<?php if (isset($content['pagination']) && $content['pagination']) : ?>
					<div class="pagination_bottom">
						<?php echo $content['pagination']; ?>
					</div>
				<?php endif; ?>
			</div>

			<aside class="col-xs-12 news_nav_col pull-right visible-xs">
				<div class="news_nav">

					<div class="pad">
						<?php
						// Output news Nav menu, contained within fdc_news.module.
						print fdc_news_navigation();
						?>
					</div>

				</div>
			</aside>

		</div>


	</div>
</div>

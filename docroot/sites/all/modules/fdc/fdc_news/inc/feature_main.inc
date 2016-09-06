<?php
if (function_exists('fdc_pse_news_summary')) {
	$fdc_pse_news_summary = fdc_pse_news_summary($feature1->nid);
}
if (function_exists('fdc_pse_news_press_pdf_link')) {
	$pdf_link = fdc_pse_news_press_pdf_link($feature1->nid);
}
if (function_exists('fdc_pse_news_additional_link')) {
	$additional_link = fdc_pse_news_additional_link($feature1->nid);
}
?>
<?php if (isset($feature1->image) && $feature1->image) : ?>
	<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
		<div class="news_item ">
			<div class="pad">

				<?php $fdc_news_get_multiple_categories = fdc_news_get_multiple_categories($feature1->nid); ?>
<!-- 				<?php if (!empty($fdc_news_get_multiple_categories)): ?>
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
				<?php endif; ?> -->
				<?php if (isset($feature1->date) && $feature1->date) : ?>
					<p class="date">
						<?php echo date('j F Y', $feature1->date); ?>
					</p> 
				<?php endif; ?>
				<h1>
					<a href="<?php echo url('node/' . $feature1->nid); ?>">	
						<?php
						if (isset($feature1->heading) && $feature1->heading) {
							echo $feature1->heading;
						}
						else {
							echo $feature1->title;
						}
						?>
					</a>
				</h1>


				<a href="<?php echo url('node/' . $feature1->nid); ?>">
					<img 
						class="img-responsive" 
						src="<?php echo image_style_url('news_top_feature', $feature1->image); ?>" 
						alt="<?php
						if (isset($feature1->image_alt) && $feature1->image_alt) {
							echo strip_tags($feature1->image_alt);
						}
						else {
							echo strip_tags($feature1->title);
						}
						?>"
						title="<?php
						if (isset($feature1->image_title) && $feature1->image_title) {
							echo strip_tags($feature1->image_title);
						}
						else {
							echo strip_tags($feature1->title);
						}
						?>"
						/>
				</a>
				<!-- Go to www.addthis.com/dashboard to customize your tools -->

				<div class="addthis_sharing_toolbox" 
					 addthis:title="<?php
					 if (isset($feature1->title) && $feature1->title) {
						 echo $feature1->title;
					 }
					 ?>" 
					 addthis:description="<?php
					 if (isset($fdc_pse_news_summary->summary) && $fdc_pse_news_summary->summary) :
						 echo $fdc_pse_news_summary->summary;
					 endif;
					 ?>" addthis:url="<?php echo "http://www.psenterprise.com" . url('node/' . $feature1->nid); ?>">
				</div>

				<?php if (!empty($fdc_pse_news_summary)): ?>
					<div class="news_summary">
						<?php echo $fdc_pse_news_summary->summary; ?>
					</div>
				<?php endif; ?>
				<div class="extras">
				<?php if (!empty($additional_link)): ?>
					<p class="news_additional_link">
						<a href="<?php echo $additional_link->link_url; ?>">
							<?php echo $additional_link->link_text; ?>
						</a>
					</p>
				<?php endif; ?>
				<?php if (!empty($pdf_link)): ?>
					<p class="news_pdf_link">
						<a href="<?php echo file_create_url($pdf_link->file_path); ?>">
							<span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
						</a>
					</p>
				<?php endif; ?>
					<?php $feat1_cat = fdc_news_get_multiple_categories($feature1->nid); ?>
					<?php if (!empty($feat1_cat)): ?>
						<p class="category">
							<?php $num_of_items = count($feat1_cat); ?>
							<?php $counter = 1; ?>
							<?php foreach ($feat1_cat as $cat) : ?>

								<a href="/news/<?php echo str_replace(array('--'), array('-'), str_replace('+', '-', urlencode(strtolower(preg_replace('/[^A-Za-z0-9-]/', '', iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', str_replace(' ', '-', str_replace('&', '', $cat->category)))))))); ?>">
									<?php echo $cat->category; ?><?php if ($num_of_items > $counter): ?>,<?php endif; ?>
								</a>
								<?php $counter ++; ?>
							<?php endforeach; ?>
						</p>
					<?php endif; ?>
				</div>
			</div>
		</div>
	</div> 
<?php endif; ?>
<?php
if (function_exists('fdc_pse_news_summary')) {
	$fdc_pse_news_summary2 = fdc_pse_news_summary($feature2->nid);
	$fdc_pse_news_summary3 = fdc_pse_news_summary($feature3->nid);
	$fdc_pse_news_summary4 = fdc_pse_news_summary($feature4->nid);
}
if (function_exists('fdc_pse_news_press_pdf_link')) {
	$pdf_link2 = fdc_pse_news_press_pdf_link($feature2->nid);
	$pdf_link3 = fdc_pse_news_press_pdf_link($feature3->nid);
	$pdf_link4 = fdc_pse_news_press_pdf_link($feature4->nid);
}
if (function_exists('fdc_pse_news_additional_link')) {
	$additional_link2 = fdc_pse_news_additional_link($feature2->nid);
	$additional_link3 = fdc_pse_news_additional_link($feature3->nid);
	$additional_link4 = fdc_pse_news_additional_link($feature4->nid);
}
?>

<?php if (isset($feature2->image) && $feature2->image) : ?>
	<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
		<div class="news_item ">
			<a href="<?php echo url('node/' . $feature2->nid); ?>">
				<img 
					class="img-responsive" 
					src="<?php echo image_style_url('news_sub_features', $feature2->image); ?>" 
					alt="<?php
					if (isset($feature2->image_alt) && $feature2->image_alt) {
						echo strip_tags($feature2->image_alt);
					}
					else {
						echo strip_tags($feature2->title);
					}
					?>"
					title="<?php
					if (isset($feature2->image_title) && $feature2->image_title) {
						echo strip_tags($feature2->image_title);
					}
					else {
						echo strip_tags($feature2->title);
					}
					?>"

					/>
			</a>
			<div class="pad">
				<?php if (isset($feature2->date) && $feature2->date) : ?>
					<p class="date">
						<?php echo date('j F Y', $feature2->date); ?>
					</p> 
				<?php endif; ?>
				<h2>
					<a href="<?php echo url('node/' . $feature2->nid); ?>">	
						<?php
						if (isset($feature2->heading) && $feature2->heading) {
							echo $feature2->heading;
						}
						else {
							echo $feature2->title;
						}
						?>
					</a>
				</h2>
				



<!-- 
				<div class="addthis_sharing_toolbox" 
					 addthis:title="<?php
					 if (isset($feature2->title) && $feature2->title) {
						 echo $feature2->title;
					 }
					 ?>" 
					 addthis:description="<?php
					 if (isset($fdc_pse_news_summary2->summary) && $fdc_pse_news_summary2->summary) :
						 echo $fdc_pse_news_summary2->summary;
					 endif;
					 ?>" addthis:url="<?php echo "http://www.psenterprise.com" . url('node/' . $feature2->nid); ?>">
				</div> -->
				<?php if (!empty($fdc_pse_news_summary2)): ?>
					<div class="news_summary">
						<?php echo $fdc_pse_news_summary2->summary; ?>
					</div>
				<?php endif; ?>
				<div class="extras">
					<?php if (!empty($additional_link2)): ?>
						<p class="news_additional_link">
							<a href="<?php echo $additional_link2->link_url; ?>">
								<?php echo $additional_link2->link_text; ?>
							</a>
						</p>
					<?php endif; ?>
					<?php if (!empty($pdf_link2)): ?>
						<p class="news_pdf_link">
							<a href="<?php echo file_create_url($pdf_link2->file_path); ?>">
								<span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
							</a>
						</p>
					<?php endif; ?>

					<?php $feat2_cat = fdc_news_get_multiple_categories($feature2->nid); ?>
					<?php if (!empty($feat2_cat)): ?>
						<p class="category">
							<?php $num_of_items = count($feat2_cat); ?>
							<?php $counter = 1; ?>
							<?php foreach ($feat2_cat as $cat) : ?>

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

<?php if (isset($feature3->image) && $feature3->image) : ?>
	<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
		<div class="news_item ">
			<a href="<?php echo url('node/' . $feature3->nid); ?>">
				<img 
					class="img-responsive" 
					src="<?php echo image_style_url('news_sub_features', $feature3->image); ?>" 
					alt="<?php
					if (isset($feature3->image_alt) && $feature3->image_alt) {
						echo strip_tags($feature3->image_alt);
					}
					else {
						echo strip_tags($feature3->title);
					}
					?>"
					title="<?php
					if (isset($feature3->image_title) && $feature3->image_title) {
						echo strip_tags($feature3->image_title);
					}
					else {
						echo strip_tags($feature3->title);
					}
					?>"

					/>
			</a>
			<div class="pad">
				<?php if (isset($feature3->date) && $feature3->date) : ?>
					<p class="date">
						<?php echo date('j F Y', $feature3->date); ?>
					</p> 
				<?php endif; ?>
				<h2>
					<a href="<?php echo url('node/' . $feature3->nid); ?>">	
						<?php
						if (isset($feature3->heading) && $feature3->heading) {
							echo $feature3->heading;
						}
						else {
							echo $feature3->title;
						}
						?>
					</a>
				</h2>

<!-- 				<div class="addthis_sharing_toolbox" 
					 addthis:title="<?php
					 if (isset($feature3->title) && $feature3->title) {
						 echo $feature3->title;
					 }
					 ?>" 
					 addthis:description="<?php
					 if (isset($fdc_pse_news_summary3->summary) && $fdc_pse_news_summary3->summary) :
						 echo $fdc_pse_news_summary3->summary;
					 endif;
					 ?>" addthis:url="<?php echo "http://www.psenterprise.com" . url('node/' . $feature3->nid); ?>">
				</div>	 -->


				<?php if (!empty($fdc_pse_news_summary3)): ?>
					<div class="news_summary">
						<?php echo $fdc_pse_news_summary3->summary; ?>
					</div>
				<?php endif; ?>

				<div class="extras">
					<?php if (!empty($additional_link3)): ?>
						<p class="news_additional_link">
							<a href="<?php echo $additional_link3->link_url; ?>">
								<?php echo $additional_link3->link_text; ?>
							</a>
						</p>
					<?php endif; ?>
					<?php if (!empty($pdf_link3)): ?>
						<p class="news_pdf_link">
							<a href="<?php echo file_create_url($pdf_link3->file_path); ?>">
								<span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
							</a>
						</p>
					<?php endif; ?>
					<?php $feat3_cat = fdc_news_get_multiple_categories($feature3->nid); ?>
					<?php if (!empty($feat3_cat)): ?>
						<p class="category">
							<?php $num_of_items = count($feat3_cat); ?>
							<?php $counter = 1; ?>
							<?php foreach ($feat3_cat as $cat) : ?>

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
<?php if (isset($feature4->image) && $feature4->image) : ?>
	<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
		<div class="news_item ">
			<a href="<?php echo url('node/' . $feature4->nid); ?>">
				<img 
					class="img-responsive" 
					src="<?php echo image_style_url('news_sub_features', $feature4->image); ?>" 
					alt="<?php
					if (isset($feature4->image_alt) && $feature4->image_alt) {
						echo strip_tags($feature4->image_alt);
					}
					else {
						echo strip_tags($feature4->title);
					}
					?>"
					title="<?php
					if (isset($feature4->image_title) && $feature4->image_title) {
						echo strip_tags($feature4->image_title);
					}
					else {
						echo strip_tags($feature4->title);
					}
					?>"

					/>
			</a>
			<div class="pad">
				<?php if (isset($feature4->date) && $feature4->date) : ?>
					<p class="date">
						<?php echo date('j F Y', $feature4->date); ?>
					</p> 
				<?php endif; ?>
				<h2>
					<a href="<?php echo url('node/' . $feature4->nid); ?>">	
						<?php
						if (isset($feature4->heading) && $feature4->heading) {
							echo $feature4->heading;
						}
						else {
							echo $feature4->title;
						}
						?>
					</a>
				</h2>
			


<!-- 				<div class="addthis_sharing_toolbox" 
					 addthis:title="<?php
					 if (isset($feature4->title) && $feature4->title) {
						 echo $feature4->title;
					 }
					 ?>" 
					 addthis:description="<?php
					 if (isset($fdc_pse_news_summary4->summary) && $fdc_pse_news_summary4->summary) :
						 echo $fdc_pse_news_summary4->summary;
					 endif;
					 ?>" addthis:url="<?php echo "http://www.psenterprise.com" . url('node/' . $feature4->nid); ?>">
				</div>	 -->

				<?php if (!empty($fdc_pse_news_summary4)): ?>
					<div class="news_summary">
						<?php echo $fdc_pse_news_summary4->summary; ?>
					</div>
				<?php endif; ?>
				<div class="extras">
					<?php if (!empty($additional_link4)): ?>
						<p class="news_additional_link">
							<a href="<?php echo $additional_link4->link_url; ?>">
								<?php echo $additional_link4->link_text; ?>
							</a>
						</p>
					<?php endif; ?>
					<?php if (!empty($pdf_link4)): ?>
						<p class="news_pdf_link">
							<a href="<?php echo file_create_url($pdf_link4->file_path); ?>">
								<span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
							</a>
						</p>
					<?php endif; ?>
					<?php $feat4_cat = fdc_news_get_multiple_categories($feature3->nid); ?>
					<?php if (!empty($feat4_cat)): ?>
						<p class="category">
							<?php $num_of_items = count($feat4_cat); ?>
							<?php $counter = 1; ?>
							<?php foreach ($feat4_cat as $cat) : ?>

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
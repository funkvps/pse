<div class="news_page">
	<div class="row">


		<div class="col-xs-12 col-sm-9 col-md-9 col-lg-9">

            <div class="row news_list" >
				<?php if (isset($content['news']) && ($content['news'][0]->nid > 0)) : ?>
					<?php foreach ($content['news'] AS $news) : ?>
						<?php // if (isset($news->image) && $news->image) : ?>
							<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
								<div class="news_item panel panel-default">
									<div class="pad">
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
										<?php if(!empty($news->summary)):?>
										<p><?php echo $news->summary;?></p>
										<?php endif;?>
										
										
										<?php if (isset($news->date) && $news->date) : ?>
											<p class="date">
												<?php echo date('j F Y', $news->date); ?>
											</p> 
										<?php endif; ?>

	
										
										<?php if (isset($news->category) && $news->category) : ?>
											<p class="category">
												<a href="/news/<?php echo str_replace(array('--'), array('-'), str_replace('+', '-', urlencode(strtolower(preg_replace('/[^A-Za-z0-9-]/', '', iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', str_replace(' ', '-', str_replace('&', '', $news->category)))))))); ?>">
													<?php echo $news->category; ?>
												</a>
											</p>
										<?php endif; ?>
<!-- 										<div class="addthis_sharing_toolbox" 
											addthis:title="<?php
											if (isset($news->heading) && $news->heading) {
												echo $news->heading;
											}
											else {
												echo $news->title;
											}
											?>" 
											addthis:description="<?php
											if (isset($news->summary) && $news->summary) :
												echo $news->summary;
											elseif (isset($news->content) && $news->content) :
												print limit_word_count(strip_tags($news->content), 30);
											endif;
										 ?>" addthis:url="<?php echo "http://www.psenterprise.com" . url('node/' . $news->nid); ?>">
										</div> -->
									</div>
								</div>
							</div> 
						<?php // endif; ?>
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

		</div>
	<div class="col-xs-12 col-sm-3 col-md-3 col-lg-3 news_nav_col">
			<div class="news_nav">
				<div class="panel panel-default">
					<div class="pad">
					<?php
					// Output news Nav menu, contained within fdc_news.module.
					print fdc_news_navigation();
					?>
					</div>
				</div>
			</div>
		</div>

	</div>
</div>

<?php 
	// drupal_set_title('News');
?>

<?php if (isset($content['pagination']) && $content['pagination']) : ?>
	<div class="pagination">
		<?php echo $content['pagination']; ?>
	</div>
<?php endif; ?>

<?php if (isset($content['description']) && $content['description']) : var_dump($content['description']); ?>
	<div class="category_desc">
		<?php echo $content['description']; ?>
	</div>
<?php endif; ?>

<div class="news_wrapper">
	<?php if (isset($content['news']) && ($content['news'][0]->nid > 0)) : ?>
		
		<ul class="news_list">
			<?php $i = 0; foreach ($content['news'] AS $news) : ?>
				<?php if ($i % 2 != 0) : ?>
					<li class="news_item even">
				<?php else: ?>
					<li class="news_item odd">
				<?php endif; ?>
				<?php $i++; ?>

					<div class="image">
						<?php if (isset($news->image) && $news->image) : ?>
							<img 
								src="<?php echo image_style_url('content_thumb', $news->image); ?>" 
								alt="<?php if (isset($news->image_alt) && $news->image_alt) { echo strip_tags($news->image_alt); } else { echo strip_tags($news->title); } ?>"
								title="<?php if (isset($news->image_title) && $news->image_title) { echo strip_tags($news->image_title); } else { echo strip_tags($news->title); } ?>"
							/>
						<?php endif; ?>
					</div><!-- image -->

					<div class="content">

						<?php if (isset($news->date) && $news->date) : ?>
							<p class="news_created">
								<?php echo date('j F Y',$news->date); ?>
							</p>
						<?php endif; ?>
							
						<?php if (isset($news->category) && $news->category) : ?>
							<p class="category">
								<a href="news/<?php echo str_replace(array('--'), array('-'), str_replace('+','-',urlencode(strtolower(preg_replace('/[^A-Za-z0-9-]/', '', iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', str_replace(' ', '-', str_replace('&','',$news->category)))))))); ?>">
									<?php echo $news->category; ?>
								</a>
							</p>
						<?php endif; ?>

						<h2 class="news_title">
							<a href="<?php echo url('node/'.$news->nid); ?>">	
								<?php
									if (isset($news->heading) && $news->heading) {
										echo $news->heading; 
									} else {
										echo $news->title;
									}
								?>
							</a>
						</h2>				

						<p class="summary">
							<?php 
							if (isset($news->summary) && $news->summary) :
								echo $news->summary;
							elseif (isset($news->content) && $news->content) :
								print limit_word_count(strip_tags($news->content), 30); 
							endif; 
							?>
						</p>

					</div><!-- content -->

				</li>
			<?php endforeach; ?>
		</ul>
	
	<?php else: ?>
	
		<ul class="news_list">
			<li class="news_item even">
				Sorry, no <?php if (isset($_GET['type'])) : echo $_GET['type']; else: echo 'articles'; endif; ?> have been found.
			</li>
		</ul>
	
	<?php endif; ?>
</div>

<?php if (isset($content['pagination']) && $content['pagination']) : ?>
	<div class="pagination">
		<?php echo $content['pagination']; ?>
	</div>
<?php endif; ?>
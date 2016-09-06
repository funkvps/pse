<?php
if (function_exists('get_latest_news')) {
	$latest_news = get_latest_news();
//  dsm('latest_news');
//  dsm($latest_news);
}
?>
<?php if (!empty($latest_news)): ?>
	<article>
		<header>
			<h2>News</h2>
			<ul class="row news">
				<?php foreach ($latest_news as $latest_news_article) : ?>
					<?php if (!empty($latest_news_article->heading)): ?>
						<li class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
							<a href="<?php echo url('node/' . $latest_news_article->nid); ?>">
								<?php //echo $rn->title; ?>
								<?php echo $latest_news_article->heading; ?>
							</a>
						</li>
					<?php endif; ?>
				<?php endforeach; ?>
			</ul>
		</header>
		<footer>
			<a href="/news" class="more-news more-content-arrow">more news</a>
		</footer>
	</article>
<?php endif; ?>
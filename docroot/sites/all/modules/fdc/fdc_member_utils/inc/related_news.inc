
<?php if (!empty($results->related_news)): ?>
<?php $latest_news = $results->related_news; ?>
<article>
	<header>
		<h2>Related News</h2>
		<ul class="row news">
			<?php foreach ($latest_news as $rn) : ?>
				<li class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
					<a href="<?php echo url('node/' . $rn->nid); ?>">
						<?php //echo $rn->title; ?>
						<?php if(!empty($rn->summary)):?>
						<?php echo $rn->summary; ?>
						<?php endif;?>
					</a>
				</li>
			<?php endforeach; ?>
		</ul>
	</header>
	<footer>
		<a href="/news" class="more-news more-content-arrow" >more news</a>
	</footer>
</article>
<?php else:?>
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/news.inc'; ?>

<?php endif; ?>
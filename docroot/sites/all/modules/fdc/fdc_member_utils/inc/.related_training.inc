<?php
/**
 * not being used... deprecated look at orders.inc
 */
?>
<?php if (!empty($results->related_training)): ?>
	<?php $related_training = $results->related_training; ?>
	<article>
		<header>
			<h2>Training Events</h2>
			<ul class="row ">
				<?php foreach ($related_training as $rt) : ?>
					<?php if (!empty($rt)): ?>
						<li>
							<a href="<?php echo url('node/' . $rt->nid); ?>" ><?php echo $rt->title ?></a>
						</li>
					<?php endif; ?>

				<?php endforeach; ?>
			</ul>
		</header>
		<footer>
			<a href="/services/training/training-courses">more Trainings ...</a>
		</footer>
	</article>
<?php endif; ?> 
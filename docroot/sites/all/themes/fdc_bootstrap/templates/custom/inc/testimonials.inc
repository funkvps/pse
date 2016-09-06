<?php if (!empty($testimonials)): ?>
	<div class="side_testimonial">
		<?php foreach ($testimonials as $test) : ?>
			<div class=""> 
				<?php if (!empty($test->testimonial->img_path)): ?>
					<img src="<?php echo image_style_url('testimonial_thumb', $test->testimonial->img_path); ?>" 
						 title="<?php if (!empty($test->testimonial->img_title)): ?><?php echo $test->testimonial->img_title; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
						 alt="<?php if (!empty($test->testimonial->img_alt)): ?><?php echo $test->testimonial->img_alt; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
						 class="img-responsive" 
						 />
					 <?php endif; ?>

				<?php if (!empty($test->testimonial->testimonial_body)) : ?>
					<p class="quote">
						<?php echo $test->testimonial->testimonial_body; ?>
					</p>
				<?php endif; ?>
				<?php if (!empty($test->testimonial->testimonial_name)) : ?>
					<p class="quotename">
						<?php echo $test->testimonial->testimonial_name; ?>
					</p>
				<?php endif; ?>

			</div>
		<?php endforeach; ?>
	</div>
<?php endif; ?>
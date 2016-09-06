<?php
if (function_exists('fdc_pse_get_cta')) {
	$row3 = fdc_pse_get_cta($node->nid);
}
?>



<?php if (!empty($row3)): ?>

	<ul class="row equal_children_height" id="threeislands">
		<?php $counter = 1; ?>


		<?php foreach ($row3 as $cta): ?>
			<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4 col-island">
		
				<li class="setheight">
					<a  <?php if(!empty($cta->img->img_path)):?> style="background-image: url('<?php echo image_style_url('call_to_action', $cta->img->img_path); ?>')"<?php endif;?> href="<?php if (!empty($cta->btn_link)): ?><?php echo $cta->btn_link; ?><?php else:?>#<?php endif; ?>">
						<article>
							<header>
								<?php if(!empty($cta->sec_img->img_path)):?>
									<img src="<?php echo image_style_url('call_to_action_content_image', $cta->sec_img->img_path); ?>" class="img-responsive imageright"/>
								<?php endif;?>
								<?php if (!empty($cta->title)): ?>
									<h2 style="<?php if (!empty($cta->title_color)): ?> color:<?php echo $cta->title_color; ?><?php endif; ?>">
										<?php echo $cta->title; ?>
									</h2>
								<?php endif; ?>
								<?php if (!empty($cta->body)): ?>
									<p style="<?php if (!empty($cta->body_color)): ?> color:<?php echo $cta->body_color; ?> <?php endif; ?>"><?php echo $cta->body; ?></p>
								<?php endif; ?>
							</header>
							<?php if (!empty($cta->btn_val)): ?>
								<footer <?php if (!empty($cta->btn_link_color)): ?> style="color:<?php echo $cta->btn_link_color; ?>" <?php endif; ?>>
									<?php echo $cta->btn_val; ?>
								</footer>
							<?php endif; ?>
						</article>
					</a>
				</li>
			</div>
			<?php if ($counter % 3) : ?>
			<?php else: ?>				
			</ul>
			<ul class="row equal_children_height" id="threeislands">
			<?php endif; ?>
			<?php $counter ++; ?>
		<?php endforeach; ?>
	</ul>
<?php endif; ?>

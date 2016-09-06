<?php
if (function_exists('fdc_pse_banner')) {
	$page_banner = fdc_pse_banner($node->nid);
}
?>
<?php if (!empty($page_banner)): ?>
	<div class="home_banners">
		<?php foreach ($page_banner as $banner) : ?>
			<?php if (!empty($banner->bg_images->img_path)): ?>
				<div >
					<div class="slick-slide-panel" <?php if (!empty($banner->bg_images->img_path)): ?> style="background-image: url(<?php echo image_style_url('home_page_banner_large', $banner->bg_images->img_path); ?>)"<?php endif; ?> >
						<?php if (!empty($banner->text_color)): ?>
							<?php $style = " color:" . $banner->text_color . " "; ?>
						<?php else: ?>
							<?php $style = ""; ?>
						<?php endif; ?>
						<div class="pad" >

							<?php if (!empty($banner->float_images->img_path)): ?>
								<!-- floating image-->
								<img src="<?php echo image_style_url('home_page_banner_float', $banner->float_images->img_path); ?>" 
									 title="<?php if (!empty($banner->fl_img_title)): ?><?php echo $banner->fl_img_title; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
									 alt="<?php if (!empty($banner->fl_img_alt)): ?><?php echo $banner->fl_img_alt; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
									 class="img-responsive float-image" 
									 />
								 <?php endif; ?>

							<?php if (!empty($banner->h1_val)): ?>
								<h1 style="<?php echo $style; ?> ">
									<?php echo $banner->h1_val; ?>
								</h1>
							<?php endif; ?>
							<?php if (!empty($banner->h2_val)): ?>
								<h2 style="<?php echo $style; ?> ">
									<?php echo $banner->h2_val; ?>
								</h2>
							<?php endif; ?>
							<?php if (!empty($banner->h3_val)): ?>
								<h3 style="<?php echo $style; ?> ">
									<?php echo $banner->h3_val; ?>
								</h3>
							<?php endif; ?>
								
							<?php if (!empty($banner->paragraph_text)): ?>
								<p style="<?php echo $style; ?> ">
									<?php echo $banner->paragraph_text; ?>
								</p>
							<?php endif; ?>
								
								
								
							<?php if (!empty($banner->link_text)): ?>
								
									<a class="<?php if (!empty($banner->link_color)): ?><?php echo $banner->link_color; ?><?php endif; ?>"
									   href="<?php if (!empty($banner->link_val)): ?><?php echo $banner->link_val; ?><?php endif; ?>"								   
									   >
										   <?php if (!empty($banner->link_text)): ?><?php echo $banner->link_text; ?><?php endif; ?>
									</a>
								
							<?php endif; ?>
							<?php if (!empty($banner->secondary_link_text)): ?>
								
									<a class="<?php if (!empty($banner->secondary_link_color)): ?><?php echo $banner->secondary_link_color; ?><?php endif; ?>"
									   href="<?php if (!empty($banner->secondary_link_url)): ?><?php echo $banner->secondary_link_url; ?><?php endif; ?>"								   
									   >
										   <?php if (!empty($banner->secondary_link_text)): ?><?php echo $banner->secondary_link_text; ?><?php endif; ?>
									</a>
								
							<?php endif; ?>
						</div>
					</div>
				</div>
			<?php endif; ?>
		<?php endforeach; ?>
	</div>
<?php endif; ?>
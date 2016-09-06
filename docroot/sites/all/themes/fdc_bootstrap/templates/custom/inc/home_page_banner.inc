<?php
if (function_exists('fdc_pse_homepage_banner')) {
	$home_page_banner = fdc_pse_homepage_banner();
}
?>
<?php if (!empty($home_page_banner)): ?>
	<div class="home_banners">
		<?php foreach ($home_page_banner as $banner) : ?>
			<?php if (!empty($banner->img_path)): ?>
				<div >
					<div class="slick-slide-panel" <?php if (!empty($banner->img_path)): ?> style="background-image: url(<?php echo image_style_url('home_page_banner_large', $banner->img_path); ?>)"<?php endif; ?> >
						<?php if (!empty($banner->link_url)): ?>
							<a href="<?php echo $banner->link_url; ?>">	</a>
						<?php endif; ?>
					</div>

				</div>
			<?php endif; ?>
		<?php endforeach; ?>
	</div>
<?php endif; ?>
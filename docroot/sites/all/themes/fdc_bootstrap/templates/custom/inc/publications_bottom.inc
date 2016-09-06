<?php global $user; ?>
<?php if (function_exists('fdc_pse_right_publication_menu')): ?>
	<?php $fdc_pse_right_publication_menu = fdc_pse_right_publication_menu($node->nid); ?>

	<?php if (!empty($fdc_pse_right_publication_menu)): ?>
		<div class="row equal_children_height featured-publications featured-publications-bottom">

			
					<?php $counter_pub = 1; ?>

		<?php foreach ($fdc_pse_right_publication_menu as $item) : ?>
			<div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
			<?php $url = "#"; ?>
			<?php // if ($item->target_id): ?>
			<?php // $url = url('node/' . $item->target_id); ?>
			<?php // endif; ?>
			<?php if ($item->pub->file_id): ?>
				<?php $file_path = fdc_pse_publication_file($item->pub->file_id);?>
				<?php $url = file_create_url($file_path); ?>
			<?php endif; ?>

			<?php if (!$item->lock_bool): ?>
				<a href="<?php echo $url; ?>">
				<?php else: ?>
					<?php if ($user->uid): ?>
						<?php //if (array_key_exists ('12', $user->roles)): ?>
						<?php if (user_access('marketting material access')): ?>
							<a href="<?php echo $url; ?>">
						<?php else: ?>
							<a   data-toggle="modal" data-target="#user_has_no_permissions" data-file="<?php echo $url; ?>">
						<?php endif; ?>
					<?php else: ?>
						<a   data-toggle="modal" data-target="#user_has_no_permissions" data-file="<?php echo $url; ?>">
					<?php endif; ?>
			<?php endif; ?>

				<?php if (!empty($item->pub->img_path)): ?>
					<span class="wrap">
					<img src="<?php echo image_style_url('bottom_pub_cover', $item->pub->img_path); ?>" 
						 title="<?php if (!empty($item->pub->img_title)): ?><?php echo $item->pub->img_title; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
						 alt="<?php if (!empty($item->pub->img_alt)): ?><?php echo $item->pub->img_alt; ?><?php else: ?><?php echo $node->title; ?><?php endif; ?>" 
						 class="img-responsive" 
						 />
					</span>

				<?php endif; ?>

				<?php if (!empty($item->content)): ?>
					<span class="wrap"><?php echo $item->content; ?></span>
				<?php endif; ?>

				</a>

			</div>
			<?php if ($counter_pub % 2) : ?>
			<?php else: ?>				
			</div>
			<div class="row equal_children_height featured-publications featured-publications-bottom" >
			<?php endif; ?>
			<?php $counter_pub ++; ?>
		<?php endforeach; ?>
		</div>
	<?php endif; ?>
<?php endif; ?>

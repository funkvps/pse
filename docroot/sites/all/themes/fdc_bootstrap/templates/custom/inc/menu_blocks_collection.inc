<?php if (function_exists('fdc_pse_right_block_menu')): ?>
	<?php $right_block = fdc_pse_right_block_menu($node->nid); ?>


	<?php if (!empty($right_block)): ?>
	<?php foreach ($right_block as $item) :?>

		<?php $node_id = $item->target_id; ?>

		<?php if (!empty($node_id)): ?>
			<?php $menu = fdc_pse_right_menu($node_id); ?>

			<?php $menu_title = fdc_pse_right_menu_title($node_id); ?>
			<?php if (!empty($menu)): ?>
				<?php if (!empty($menu_title->heading)): ?>
					<h2><?php echo $menu_title->heading; ?></h2>
				<?php endif; ?>
				<ul class="list">
					<?php foreach ($menu as $m): ?>
						<li>
							<?php
							$external_link = 0;
							$internal_link = 0;
							$file_link = 0;
							$path = "#";
							?>

							<?php if (!empty($m->target_nid)): ?>
								<?php $internal_link = 1; ?>
							<?php endif; ?>

							<?php if (!empty($m->url)): ?>
								<?php $external_link = 1; ?>
							<?php endif; ?>


							<?php if (!empty($m->file_path)): ?>
								<?php $file_link = 1; ?>
							<?php endif; ?>


							<?php if (!empty($m->menu_name)): ?>
								<?php if ($internal_link): ?>
									<?php $path = url('node/' . $m->target_nid); ?>
								<?php endif; ?>
								<?php if ($external_link): ?>
									<?php $path = $m->url; ?>
								<?php endif; ?>
								<?php if ($file_link): ?>
									<?php $path = file_create_url($m->file_path); ?>
								<?php endif; ?>
								<a href="<?php echo $path; ?>">
									<?php echo $m->menu_name; ?>
								</a>
							<?php endif; ?>
						</li>
					<?php endforeach; ?>
				</ul>
			<?php endif; ?>
		<?php endif; ?>
					
		<?php endforeach;?>					
	<?php endif; ?>
<?php endif; ?>


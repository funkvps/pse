<?php global $user; ?>
<?php if (function_exists('fdc_pse_right_publication_menu')): ?>
	<?php $fdc_pse_right_publication_menu = fdc_pse_right_publication_menu($node->nid); ?>

	<?php if (!empty($fdc_pse_right_publication_menu[0]->pub)): ?>

		<div class=" featured-publications">

			<h2>Publications</h2>

			<?php foreach ($fdc_pse_right_publication_menu as $item) : ?>
				<?php $url = "#"; ?>
				<?php // if ($item->target_id): ?>
				<?php // $url = url('node/' . $item->target_id); ?>
				<?php // endif; ?>
				<?php if ($item->pub->file_id): ?>
					<?php $file_path = fdc_pse_publication_file($item->pub->file_id); ?>
<!--					--><?php //var_dump($file_path);exit; ?>
					<?php $url = '/system/tdf/' . $file_path->filename . "?file=1&type=node&id=$node->nid&force=1"; ?>
<!--					--><?php //$url = file_create_url($file_path['file_path']) . "?file=1&type=node&id=$node->nid&force=1"; ?>
				<?php endif; ?>

				<?php if (!$item->lock_bool): ?>
					<a href="<?php echo $url; ?>">
					<?php else: ?>
						<?php if ($user->uid): ?>
							<?php if (fdc_pse_has_marketing_material_access()): ?>
								<a href="<?php echo $url; ?>">
								<?php else: ?>
									<a   data-toggle="modal" data-target="#user_not_registered_modal" data-file="<?php echo $url; ?>">
									<?php endif; ?>
								<?php else: ?>
									<a   data-toggle="modal" data-target="#user_not_registered_modal" data-file="<?php echo $url; ?>">
									<?php endif; ?>
								<?php endif; ?>

								<?php if (!empty($item->pub->img_path)): ?>
									<span class="wrap">
										<img src="<?php echo image_style_url('right_block_pub_cover', $item->pub->img_path); ?>" 
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



						<?php endforeach; ?>
						</div>
					<?php endif; ?>
					<script>
						$(function()
						{
							$('#user_not_registered_modal').on('show.bs.modal', function(event) {
								var button = $(event.relatedTarget); // Button that triggered the modal
								var fname = button.data('file'); // Extract info from data-* attributes
								var pub_file_name = fname.substring(fname.lastIndexOf("tdf/")+4,fname.lastIndexOf("?file"));

								$("input:hidden[name='submitted[file_id]']").val(fname);
								$("input:hidden[name='submitted[current_page]']").val(window.location.href);
								$("input:hidden[name='submitted[file_name]']").val(pub_file_name);
							})
						})
					</script>
				<?php endif; ?>




<?php
if (function_exists('fdc_pse_get_related_items')) {
	$related_items = fdc_pse_get_related_items($node->nid);
}

?>
<?php if (!empty($related_items)): ?>
	<div class="row related_items">
		<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
			<div class="right_menu">
				<div class="pad"> 
					<h2>Related</h2>
					<ul class="list">
						<?php foreach ($related_items as $rn) : ?>
							<?php if (!empty($rn->title) AND ($node->nid!=$rn->nid)): 	?>
								<li>
									<a href="<?php echo url('node/' . $rn->nid); ?>"><?php echo $rn->title; ?></a>
								</li>
							<?php endif; ?>
						<?php endforeach; ?>
					</ul>
				</div>
			</div>
		</div>
	</div>
<?php endif; ?>

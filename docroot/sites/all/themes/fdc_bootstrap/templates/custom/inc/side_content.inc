<?php
if (function_exists('fdc_pse_node_side_content')) {
	$side_content = fdc_pse_node_side_content($node->nid);
}
?>
<?php if (!empty($side_content)): ?>
	<div class="side_content">
		<?php echo $side_content; ?>
	</div>
<?php endif; ?>



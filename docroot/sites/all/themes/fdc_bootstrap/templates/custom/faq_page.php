<?php
// FAQ PAGE.
// Load content. 'body' and 'heading'
// Include child/sibling menu system
$content_menu = child_sibling_menu($node->nid);
// Load FAQs
$faqs = db_query("
	SELECT
		field_data_field_faq_question.field_faq_question_value AS `question`,
		field_data_field_faq_answer.field_faq_answer_value AS `answer`
	FROM
		node
	INNER JOIN field_data_field_collection_faq ON field_data_field_collection_faq.entity_id = node.nid
	INNER JOIN field_data_field_faq_answer ON field_data_field_faq_answer.entity_id = field_data_field_collection_faq.field_collection_faq_value
	INNER JOIN field_data_field_faq_question ON field_data_field_faq_question.entity_id = field_data_field_collection_faq.field_collection_faq_value
	ORDER BY
		field_data_field_collection_faq.delta ASC
	")->fetchAll();

if (function_exists('fdc_pse_node_content')) {
	$content = fdc_pse_node_content($node->nid);
}
if (function_exists('fdc_meta_add')) {
	fdc_meta_add($node->nid);
}
if (function_exists('fdc_pse_get_product_side_menu')) {
	$side_menu_disable_bool = fdc_pse_get_product_side_menu($node->nid);
}
if (function_exists('fdc_pse_get_product_side_menu')) {
	$side_menu_disable_bool = fdc_pse_get_product_side_menu($node->nid);
}
?>



<div class="row equal_children_height">
	<div class="col-xs-12 col-sm-12 <?php if ($side_menu_disable_bool): ?> col-md-12 col-lg-12 <?php else: ?> col-md-8 col-lg-8 <?php endif; ?>">


		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
				<?php if (isset($content->heading) && $content->heading) : ?>
					<h1>
						<?php echo $content->heading; ?>
					</h1>
				<?php endif; ?>

				<?php if (isset($content->body) && $content->body) : ?>
					<?php echo $content->body; ?>
				<?php endif; ?>


			</div>
		</div>
		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

				<?php if (!empty($faqs)): ?>
					<ul>
						<?php foreach ($faqs AS $key => $faq) : ?>		
							<li> <a href="#faq<?php echo $key; ?>"><?php echo $faq->question; ?></a> </li>
						<?php endforeach; ?>
					</ul>
				<?php endif; ?>
			</div>
		</div>
		<div class="row equal_children_height">
			<div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">

				<?php if (!empty($faqs)): ?>
					<?php foreach ($faqs AS $key => $faq) : ?>		
						<div>
							<a name="faq<?php echo $key; ?>"></a>
								<h3> <?php echo $faq->question; ?> </h3>
								<div> <?php echo $faq->answer; ?></div>
						</div>
					<?php endforeach; ?>
				<?php endif; ?>
			</div>
		</div>
	</div>
	<div class="row equal_children_height">
		<?php // call to action with 3 rows  ?>
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row3.inc'; ?>

	</div>
	<div class="row equal_children_height">
		<?php // call to action with 4 rows  ?>
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/row4.inc'; ?>

	</div>
</div>
<?php if (!$side_menu_disable_bool): ?>
	<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
		<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/right_menu.inc'; ?>
	</div>
<?php endif; ?>
</div>


<?php 
if (!empty($node->nid)) {
  //My Heart Aches So My Mind Bleeds
  /* if ($node->type == 'news_articles' ) {
//    dsm('node_content');
//    dsm($node_content);
    if (!empty($node_content['field_pse_tax_sectors']['#items'])
      || !empty($node_content['field_pse_tax_regions']['#items'])
      || !empty($node_content['field_pse_tax_products']['#items'])
    ) {
      ?>
      <div class="pse-inline-fields news_categories news-taxonomies">
        <h2>Article is related to</h2>
        <?php if (!empty($node_content['field_pse_tax_products']['#items'])){ print render($node_content['field_pse_tax_products']); } ?>
        <?php if (!empty($node_content['field_pse_tax_sectors']['#items'])){ print render($node_content['field_pse_tax_sectors']); } ?>
        <?php if (!empty($node_content['field_pse_tax_regions']['#items'])){ print render($node_content['field_pse_tax_regions']); } ?>
      </div>
      <?php
    }
  } */
  /*
	$press_files_sql = db_query("SELECT
	field_data_field_press_release_pdf.field_press_release_pdf_fid,
	file_managed.uri as file_path,
	file_managed.filename
FROM
	node
INNER JOIN field_data_field_press_release_pdf ON node.nid = field_data_field_press_release_pdf.entity_id
LEFT JOIN file_managed ON field_data_field_press_release_pdf.field_press_release_pdf_fid = file_managed.fid
WHERE
	node.nid = :nid", array(":nid" => $node->nid))->fetchObject();
	if (!empty($press_files_sql)) {
		$press_files = $press_files_sql;
	}
?>
	<?php if (!empty($press_files)): ?>
  <div class="news_categories news-downloads">
    <h2>Downloads</h2>
    <a href="<?php echo file_create_url($press_files->file_path); ?>" class="btn btn-link ">
      <span class="glyphicon glyphicon-file" aria-hidden="true"></span> Download this Press Release<?php //print_r($press_files->filename); ?>
    </a>
  </div>

	<?php endif; */ ?>
<?php } ?>
<?php
//dsm('right_menu.inc');
//dsm($variables);
if (function_exists('child_sibling_menu')) {
	$content_menu = child_sibling_menu($node->nid);
}

if (function_exists('fdc_pse_get_node_testimonial')) {
	$testimonials = fdc_pse_get_node_testimonial($node->nid);
}

if (function_exists('fdc_pse_get_cta')) {
	$call_to_action = fdc_pse_get_cta($node->nid);
}
?>
<!-- content menu -->

<?php $fdc_pse_hide_siblings_menu = fdc_pse_hide_siblings_menu($node->nid);?>
<?php if(empty($fdc_pse_hide_siblings_menu)):?>
<?php if(($fdc_pse_hide_siblings_menu)> 0):?>
	<?php if (!empty($content_menu)) : ?>
		<!-- <h2>More</h2> -->
		<?php echo $content_menu; ?>
	<?php endif; ?>
<?php endif; ?>
<?php endif; ?>

<?php 
  /* if (!empty($node->type) && $node->type != 'news_articles' ) {
//    dsm('node_content');
//    dsm($node_content);
    if (!empty($node_content['field_pse_tax_sectors']['#items'])
      || !empty($node_content['field_pse_tax_regions']['#items'])
      || !empty($node_content['field_pse_tax_products']['#items'])
    ) {
      ?>
      <div class="pse-inline-fields news_categories news-taxonomies">
        <?php if($node->type == 'events_and_webinar') {?>
          <h2>Event is related to</h2>
        <?php } else {?>
          <h2>Content is related to</h2>
        <?php }?>
        <?php if (!empty($node_content['field_pse_tax_products']['#items'])){ print render($node_content['field_pse_tax_products']); } ?>
        <?php if (!empty($node_content['field_pse_tax_sectors']['#items'])){ print render($node_content['field_pse_tax_sectors']); } ?>
        <?php if (!empty($node_content['field_pse_tax_regions']['#items'])){ print render($node_content['field_pse_tax_regions']); } ?>
      </div>
      <?php
    }
  } */
?>

<!-- block menu -->
<?php // include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/menu_blocks.inc';  ?>
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/menu_blocks_collection.inc';  ?>

<!-- custom menu -->
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/menu.inc';  ?>

<!-- News content -->
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/news_right.inc';  ?>

<!-- related content -->
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/related.inc';  ?>

<!-- testimonials -->
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/testimonials.inc';  ?>


<!-- side content -->
<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/side_content.inc';  ?>




<?php if (function_exists('fdc_pse_publication_bool')): ?>
	<?php $has_publication_bottom = fdc_pse_publication_bool($node->nid);?>
		<?php if(!$has_publication_bottom ):?>
<!-- publication -->
			<?php include DRUPAL_ROOT . '/sites/all/themes/fdc_bootstrap/templates/custom/inc/publications.inc';  ?>
		<?php endif; ?>
<?php endif; ?>
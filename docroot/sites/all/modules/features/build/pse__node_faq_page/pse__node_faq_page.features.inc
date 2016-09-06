<?php
/**
 * @file
 * pse__node_faq_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_faq_page_node_info() {
  $items = array(
    'faq_page' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

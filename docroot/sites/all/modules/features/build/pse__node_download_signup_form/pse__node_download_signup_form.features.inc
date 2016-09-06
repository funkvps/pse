<?php
/**
 * @file
 * pse__node_download_signup_form.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pse__node_download_signup_form_node_info() {
  $items = array(
    'download_signup_form' => array(
      'name' => t('Download Signup Form'),
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

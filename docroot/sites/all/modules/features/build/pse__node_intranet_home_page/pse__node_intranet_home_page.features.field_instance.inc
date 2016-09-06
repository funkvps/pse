<?php
/**
 * @file
 * pse__node_intranet_home_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pse__node_intranet_home_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-intranet_home_page-field_col_content'
  $field_instances['node-intranet_home_page-field_col_content'] = array(
    'bundle' => 'intranet_home_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_col_content',
    'label' => 'Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');

  return $field_instances;
}

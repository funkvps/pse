<?php
/**
 * @file
 * pse__node_footer_blocks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pse__node_footer_blocks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-footer_blocks-field_block_footer'
  $field_instances['node-footer_blocks-field_block_footer'] = array(
    'bundle' => 'footer_blocks',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_block_footer',
    'label' => 'Footer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 30,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');

  return $field_instances;
}

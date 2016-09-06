<?php
/**
 * @file
 * pse__media.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pse__media_filter_default_formats() {
  $formats = array();

  // Exported format: Full Editor.
  $formats['full_editor'] = array(
    'format' => 'full_editor',
    'name' => 'Full Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => 10,
    'filters' => array(),
  );

  return $formats;
}

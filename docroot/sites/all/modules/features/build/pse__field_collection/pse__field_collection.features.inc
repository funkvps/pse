<?php
/**
 * @file
 * pse__field_collection.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pse__field_collection_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

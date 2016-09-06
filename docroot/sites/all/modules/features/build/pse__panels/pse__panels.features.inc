<?php
/**
 * @file
 * pse__panels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pse__panels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "pipelines") {
    return array("version" => "1");
  }
}

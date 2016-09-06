<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
//dsm('field');
//dsm($field);
//dsm($row);
$tid = 0;
if (!empty($row->_entity_properties['field_col_commerce:entity object']->field_prod_location['und'][0]['tid'])) {
  $tid = $row->_entity_properties['field_col_commerce:entity object']->field_prod_location['und'][0]['tid'];
}
if (!empty($tid)) {
  $parent = get_parent_term_of_taxonomy_term($tid);
  if (!empty($parent->name)) {
//    dsm($parent);
    $output = '<img class="img-responsive pull-left listing-flag" src="' . file_create_url($parent->field_taxo_flags['und'][0]['uri']) . '" /> ' . $output . ', ' . $parent->name;
  }
}
?>
<?php print $output; ?>
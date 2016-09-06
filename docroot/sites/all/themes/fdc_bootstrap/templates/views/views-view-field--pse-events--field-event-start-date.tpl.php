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
//dsm('row');
//dsm($row);
//dsm('field');
//dsm($field);
$start = $start_timestamp = 1;
$end = 1;
if (!empty($row->_entity_properties['entity object']->field_event_start_date['und'][0]['value'])) {
  $start = $row->_entity_properties['entity object']->field_event_start_date['und'][0]['value'];
  $start_timestamp = $start;
  $start = date('d', $start); // day of the month, no front zero for 01, 02 ...
  $end = $start;
}
if (!empty($row->_entity_properties['entity object']->field_event_end_date['und'][0]['value'])) {
  $end = $row->_entity_properties['entity object']->field_event_end_date['und'][0]['value'];
  $end_timestamp = $end;
  if (date('m', $start_timestamp) != date('m', $end_timestamp)) {
    $end = date('d M', $end_timestamp);
  }else {
    $end = date('d', $end_timestamp);
  }
}
?>
<?php print $start; if ($start != $end) { print '-' . $end;} ?>
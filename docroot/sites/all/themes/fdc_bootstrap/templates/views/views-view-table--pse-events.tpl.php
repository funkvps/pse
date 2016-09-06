<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
global $this_is_not_first_events_table, $this_is_not_first_events_table_header_item_no, $user; // output headers, just once
//dsm($variables);
?>
  <?php if (!empty($header) && $this_is_not_first_events_table == false) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <?php $this_is_not_first_events_table_header_item_no++; ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
    <tbody>
  <?php endif; ?>
    <?php if (!empty($title) || !empty($caption)) : ?>
    <tr><td class="caption" colspan="<?php print $this_is_not_first_events_table_header_item_no; ?>"><div class="training_month_date"><?php print $caption . $title; ?></div></td></tr>
    <?php endif; ?>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
            <?php if ($field == 'field_pse_involvement' && !empty($user->uid) && user_access('administer nodes')) {
              print l('edit', 'node/' . $view->result[$row_count]->_entity_properties['nid'] . '/edit', array('query' => array('destination' => $_GET['q'])));
            } ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
<?php $this_is_not_first_events_table = true;
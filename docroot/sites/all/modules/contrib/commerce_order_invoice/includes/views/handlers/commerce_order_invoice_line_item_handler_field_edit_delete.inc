<?php
/**
 * @file
 * Overwritten field handler for the line item delete button.
 */

/**
 * Overwritten field handler for the line item delete button that will handle
 * converting the order to an invoice if the line item is part of an invoice.
 */
class commerce_order_invoice_line_item_handler_field_edit_delete extends commerce_line_item_handler_field_edit_delete {
  /**
   * Returns the form which replaces the placeholder from render().
   *
   * Removes the submit callback function for each remove button.
   */
  function views_form(&$form, &$form_state) {
    parent::views_form($form, $form_state);

    // Iterate over the results, replacing the submit function for each remove
    // button so that it will not display a system message if the line item is
    // not to be removed.
    foreach ($this->view->result as $row_id => $row) {
      $form[$this->options['id']][$row_id]['#submit'] = $form['#submit'];
    }
  }

  /**
   * Implements hook_views_form_submit().
   *
   * If the removed line item is part of invoice, the order will be converted
   * back to an invoice instead of removing the line item.
   */
  function views_form_submit($form, &$form_state) {
    $field_name = $this->options['id'];
    $row_id = str_replace('delete-line-item-', '', $form_state['triggering_element']['#name']);

    // If the row id is numeric then the remove button was clicked for a line
    // item.
    if (is_numeric($row_id)) {
      // If the line item is not part of an invoice then we can let the parent
      // function do its job.
      $line_item_id = $form[$field_name][$row_id]['#line_item_id'];
      $line_item = commerce_line_item_load($line_item_id);
      if (!$line_item->invoice) {
        return parent::views_form_submit($form, $form_state);
      }

      // Convert the order back into an invoice.
      $order = commerce_order_load($form_state['order']->order_id);
      commerce_order_invoice_convert_order($order);
    }
  }
}

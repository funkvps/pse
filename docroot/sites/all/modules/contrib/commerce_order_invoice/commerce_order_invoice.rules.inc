<?php
/**
 * @file
 * Provides rules integration for commerce order invoices.
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_order_invoice_rules_action_info() {
  return array(
    'commerce_order_invoice_pay_invoice' => array(
      'label' => t('Pay invoice'),
      'group' => t('Commerce Order Invoice'),
      'parameter' => array(
        'commerce_order_invoice' => array(
          'type' => 'commerce_order',
          'label' => t('Invoice'),
          'description' => t('Invoice to be paid'),
        ),
      ),
    ),
    'commerce_order_invoice_convert_order' => array(
      'label' => t('Convert order to invoice'),
      'group' => t('Commerce Order Invoice'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Commerce Order'),
          'description' => t('Order to be converted back to the invoice state.'),
        ),
      ),
    ),
  );
}

/**
 * Action callback that starts the checkout process for an invoice.
 *
 * @param stdClass $order
 *   Order to be converted.
 */
function commerce_order_invoice_pay_invoice($order) {
  commerce_order_status_update($order, 'checkout_checkout');

  module_load_include('inc', 'rules', 'modules/system.eval');
  rules_action_drupal_goto('checkout/' . $order->order_id, TRUE, FALSE);
}

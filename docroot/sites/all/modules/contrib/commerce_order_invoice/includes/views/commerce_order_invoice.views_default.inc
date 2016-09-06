<?php
/**
 * @file
 * Provides default views for the commerce order invoice module.
 */

/**
 * Implements hook_views_default_views_alter().
 *
 * Add the invoice state as a filter on the default commerce_orders (admin)
 * view.
 *
 * @see commerce_cart_views_default_views_alter()
 */
function commerce_order_invoice_views_default_views_alter(&$views) {
  if (isset($views['commerce_orders'])) {
    $views['commerce_orders']->display['default']->display_options['filters']['state']['value']['invoice'] = 'invoice';

    /* Display: Invoices */
    $handler = $views['commerce_orders']->new_display('page', 'Invoices', 'invoices');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Invoices';
    $handler->display->display_options['defaults']['empty'] = FALSE;
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['text']['id'] = 'text';
    $handler->display->display_options['empty']['text']['table'] = 'views';
    $handler->display->display_options['empty']['text']['field'] = 'area';
    $handler->display->display_options['empty']['text']['empty'] = FALSE;
    $handler->display->display_options['empty']['text']['content'] = 'There are currently no invoice orders.';
    $handler->display->display_options['empty']['text']['format'] = 'plain_text';
    $handler->display->display_options['empty']['text']['tokenize'] = 0;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Commerce Order: Order state */
    $handler->display->display_options['filters']['state']['id'] = 'state';
    $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
    $handler->display->display_options['filters']['state']['field'] = 'state';
    $handler->display->display_options['filters']['state']['value'] = array(
      'invoice' => 'invoice',
    );
    $handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
    $handler->display->display_options['filters']['state']['expose']['use_operator'] = 1;
    $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
    $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
    $handler->display->display_options['filters']['state']['expose']['reduce'] = 0;
    $handler->display->display_options['path'] = 'admin/commerce/orders/invoices';
    $handler->display->display_options['menu']['type'] = 'tab';
    $handler->display->display_options['menu']['title'] = 'Invoices';
    $handler->display->display_options['menu']['weight'] = '1';
  }
}

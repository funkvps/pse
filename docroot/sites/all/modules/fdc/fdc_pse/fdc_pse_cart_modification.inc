<?php

function fdc_pse_get_current_cart_set_currency() {

	global $user;
	$order = commerce_cart_order_load($user->uid);
	$order_amount = $order->commerce_order_total['und'][0]['amount'];
	if ($order_amount > 0) {
		$wrapper = entity_metadata_wrapper('commerce_order', $order);

		return $first_item_currency = $wrapper->commerce_line_items[0]->commerce_product->value()->commerce_price['und'][0]['currency_code'];
	}
	else {
		return false;
	}
}

function fdc_pse_cart_modification_check_exisiting_cart() {

	global $user;
	$order = commerce_cart_order_load($user->uid);
	$order_amount = $order->commerce_order_total['und'][0]['amount'];
	if ($order_amount > 0) {
		$wrapper = entity_metadata_wrapper('commerce_order', $order);

		$first_item_currency = $wrapper->commerce_line_items[0]->commerce_product->value()->commerce_price['und'][0]['currency_code'];
//		print_r($wrapper);
		if ($first_item_currency) {
			foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {

				$cart_item = $line_item_wrapper->commerce_product->value();
				$currency = $cart_item->commerce_price['und'][0]['currency_code'];
				if ($currency != $first_item_currency) {
//					print_r($cart_item);
//					commerce_line_item_delete($cart_item->product_id);
					fdc_pse_cart_modification_product_delete_cart($cart_item->product_id);
				}
			}
		}
	}
}

function fdc_pse_cart_modification_product_delete_cart($product_ids) {
	if (!is_array($product_ids)) {
		$line_item_id = fdc_pse_cart_modification_product_in_cart($product_ids);
		if ($line_item_id != -1 && $line_item_id != -2) {
			global $user;
			$current_order = commerce_cart_order_load($user->uid);
			commerce_cart_order_product_line_item_delete($current_order, $line_item_id);
		}
		else
			return -1;
	}
	else {
		$line_item_ids = fdc_pse_cart_modification_product_in_cart($product_ids);
		if ($line_item_ids != -1 && $line_item_ids != -2) {
			global $user;
			$current_order = commerce_cart_order_load($user->uid);
			foreach ($line_item_ids as $line_item_id) {
				commerce_cart_order_product_line_item_delete($current_order, $line_item_id);
			}
		}
		else {
			return -1;
		}
	}
}

function fdc_pse_cart_modification_product_in_cart($product_id) {
	if (!is_array($product_id)) {
		global $user;
		$current_order = commerce_cart_order_load($user->uid);
		if (count($current_order->commerce_line_items) > 0) {
			$line_items = $current_order->commerce_line_items;
			foreach ($line_items['und'] as $key => $value) {
				$line_item = commerce_line_item_load($value['line_item_id']);
				$products = $line_item->commerce_product['und'];
				foreach ($products as $product_key => $product_value) {
					if ($product_id == $product_value['product_id']) {
						return $value['line_item_id'];
					}
				}
			}
			return -1;
		}
		else
			return -2;
	}
	else {
		global $user;
		$current_order = commerce_cart_order_load($user->uid);
		if (count($current_order->commerce_line_items) > 0) {
			$line_items = $current_order->commerce_line_items;
			foreach ($line_items['und'] as $key => $value) {
				$line_item = commerce_line_item_load($value['line_item_id']);
				$products = $line_item->commerce_product['und'][0]['product_id'];
				foreach ($product_id as $id) {
					if ($id == $products) {
						$line_item_ids[] = $value['line_item_id'];
					}
				}
			} if (isset($line_item_ids) >= 1) {
				return $line_item_ids;
			}
			else {
				return -1;
			}
		}
		else
			return -2;
	}
}

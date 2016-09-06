<h2>Book a course</h2>
<?php foreach ($training_products as $parent) : ?>
	<?php
//	$sub_prod = fdc_pse_products_hierachy($parent->tid, $nid);
//  _d('HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM '
//          . 'HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM '
//          . 'HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM HERE I AM ');
//  _d($sub_prod);
//  _d('parent tid');
//  _d($parent->tid);
  
//  $endoftoday = strtotime('yesterday');
//  print '<br>yesterday ' . date('Y.m.d H:i:s', $endoftoday) . 'DATE<br>';
//  $endoftoday = strtotime('today - 10 minutes');
//  print '<br> today' . date('Y.m.d H:i:s', $endoftoday) . 'DATE<br>';
	?>
		<?php $products = fdc_pse_products_hierachy($parent->tid, $nid); ?>
		<?php if (!empty($products)): ?> 
	<div class="aside_product_listing">
		
		<?php if (!empty($parent->img_path)): ?>
			<img 
				class="img-responsive pull-left icon-flag"
				src="<?php if (!empty($parent->img_path)): ?><?php echo image_style_url('flag_small', $parent->img_path); ?><?php endif; ?>" 
				title="<?php if (!empty($parent->img_title)): ?><?php echo $parent->img_title; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
				alt="<?php if (!empty($parent->img_alt)): ?><?php echo $parent->img_alt; ?><?php else: ?> <?php echo $node->title; ?> 	<?php endif; ?>" 
				/>
			<?php endif; ?>
			<?php if(!empty($parent->parent_location)):?>
			<h2 class="title_country"><?php echo $parent->parent_location; ?></h2>
			<?php endif;?>
			<?php foreach ($products as $product) : ?>
				<div class="product_listing_item <?php if($product->stock == 0):?> out_of_stock <?php endif;?>">

					<div class="product_item_info">
						<div class="date">
							<?php if (!empty($product->start_date) && !empty($product->end_date)): ?>
							<?php if ($product->start_date == $product->end_date || $product->start_date > $product->end_date ): ?>
								<?php echo fdc_pse_date_format($product->start_date,'dMY');?>
							<?php else:?>
								<?php echo fdc_pse_date_format($product->start_date,'dMY');?>
							to
								<?php echo fdc_pse_date_format($product->end_date,'dMY');?>
							<?php endif; ?>
							<?php endif; ?>
						</div>
						<div class="prod_title">
							<?php if (!empty($product->location)): ?>
								<?php echo $product->location; ?>
							<?php endif; ?>
						</div>
						<div class="price">
							<?php // if (!empty($product->currency_code)): ?>
								<?php // echo fdc_pse_currency_symbols($product->currency_code); ?>
							<?php // endif; ?>
							<?php if (!empty($product->currency_code)): ?>
								<?php // echo fdc_pse_get_price($product->currency_amount); ?>
								<?php echo fdc_pse_get_price_formatted($product->currency_amount,$product->currency_code); ?>
							<?php endif; ?>
						</div>
					</div>
					<?php if($product->stock != 0):?> 
					<div class="basket_actions">
						<?php if (!empty($product->currency_code)): ?>
							<?php if (!empty($cart_currency_code)): ?>
								<?php if ($cart_currency_code != $product->currency_code): ?>		
								<!-- disabled products-->
									<div class="add_to_basket add_to_basket_disabled">
										<div class="input-group" title="It is not possible for you to checkout with multiple currencies">
											<!-- <label class="control-label">QTY</label> -->
											<input class="form-control  "disabled type="text" id ='' name ="product_qty" value="1" />
											<span class="">
												<button class='btn btn-success add_to_cart disabled' ><span class="glyphicon glyphicon-plus"></span > Add to basket</button>
											</span>
										</div>
									</div>
								<?php else: ?>
									<div class="add_to_basket">
										<div class="input-group">
											<input type="hidden" class ='prod_id' name ="product_id" value="<?php echo $product->product_id; ?>" />
											<input type="hidden" class ='prod_term_id' name ="term_id" value="" />
											<input type="hidden" class ='prod_name' name ="product_name" value="<?php echo $product->title; ?> <?php echo $parent->parent_location; ?>" />
											<input type="hidden" class ='prod_nid'  value="<?php echo $nid; ?>" />
											<!-- <label class="control-label">QTY</label> -->
											<input class="form-control prod_qty " type="text" id ='' name ="product_qty" value="1" />
											<span class="">
												<button class='btn btn-success add_to_cart' ><span class="glyphicon glyphicon-plus"></span> Add to basket</button>
											</span>
										</div>
									</div>
								<?php endif; ?>
							<?php else: ?>
								<div class="add_to_basket">
									<div class="input-group">
										<input type="hidden" class ='prod_id' name ="product_id" value="<?php echo $product->product_id; ?>" />
										<input type="hidden" class ='prod_term_id' name ="term_id" value="" />
										<input type="hidden" class ='prod_name' name ="product_name" value="<?php echo $product->title; ?> <?php echo $parent->parent_location; ?>" />
										<input type="hidden" class ='prod_nid'  value="<?php echo $nid; ?>" />

										<!-- <label class="control-label">QTY</label> -->
										<input class="form-control prod_qty " type="text" id ='' name ="product_qty" value="1" />
										<span class="">
											<button class='btn btn-success add_to_cart' ><span class="glyphicon glyphicon-plus"></span> Add to basket</button>
										</span>
									</div>
								</div>
							<?php endif; ?>
						<?php endif; ?>
					</div>
					<?php endif;?>
				</div>
			<?php endforeach; ?>
		<?php endif; ?>
	</div>
<?php endforeach; ?>
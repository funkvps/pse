(function($) {
  $ = jQuery;
  $(document).on('click', '.add_to_cart', function() {
    prod_id = this.parentNode.parentNode.getElementsByClassName('prod_id')[0].value;
    prod_name = this.parentNode.parentNode.getElementsByClassName('prod_name')[0].value;
    prod_qty = this.parentNode.parentNode.getElementsByClassName('prod_qty')[0].value;
    prod_nid = this.parentNode.parentNode.getElementsByClassName('prod_nid')[0].value;
    if ((prod_name.length > 0) && (prod_id.length > 0) & (prod_qty.length > 0))
      $.ajax({
        type: "GET",
        url: '/fdc_pse_cart/ajax_add_to_cart', // adds to cart
        data: {
          'product_id': prod_id,
          'qty': prod_qty
        },
        dataType: "text",
        success: function(msg) {
          $.ajax({
            type: "GET",
            url: '/fdc_pse_cart/fdc_pse_training_ajax_products/' + prod_nid, //updates prod list
            data: {
              'product_id': prod_id,
              'qty': prod_qty,
            },
            dataType: "text",
            success: function(msg) {
              $('#training_products').html(msg);

              $.ajax({
                type: "GET",
                url: '/fdc_pse_cart/update_cart', // updates top cart
                data: {
                },
                dataType: "text",
                success: function(msg2) {
                  if ($('body').hasClass("not-logged-in")) {
                    $('#fdc_ecommerce_product_top_cart').html("Basket (" + msg2 + ")");
                  } else {
                    $('#fdc_ecommerce_product_top_cart').html(msg2);
                  }
                }
              });
            }
          });
          product_added_to_cart(prod_name);
        }
      });
  });


  $(function()
  {
    $('#edit-cancel').html('Back');
    $('.page-user-edit #edit-cancel').html('Delete account');
    
    $("label[for='edit-commerce-payment-payment-method-payment-commerce-2commerce-payment-invoice-by-company']").html("Please invoice my company");
    $("label[for='edit-commerce-payment-payment-method-paypal-wpscommerce-payment-paypal-wps']").html('<span>Pay by either credit card, debit card or PayPal</span>\n\
  <div class="commerce-paypal-icons"><span class="label">Includes:</span>\n\
  <img title="Visa" class="commerce-paypal-icon" alt="Visa" src="/sites/all/modules/contrib/commerce_paypal/images/visa.gif"> \n\
  <img title="Mastercard" class="commerce-paypal-icon" alt="Mastercard" src="/sites/all/modules/contrib/commerce_paypal/images/mastercard.gif"> \n\
  <img title="American Express" class="commerce-paypal-icon" alt="American Express" src="/sites/all/modules/contrib/commerce_paypal/images/amex.gif"> \n\
  <img title="Discover" class="commerce-paypal-icon" alt="Discover" src="/sites/all/modules/contrib/commerce_paypal/images/discover.gif"> \n\
  <img title="eCheck" class="commerce-paypal-icon" alt="eCheck" src="/sites/all/modules/contrib/commerce_paypal/images/echeck.gif"> \n\
  <img title="PayPal" class="commerce-paypal-icon" alt="PayPal" src="/sites/all/modules/contrib/commerce_paypal/images/paypal.gif">\n\
  </div><span class="commerce-paypal-extra-info">(Continue with checkout to complete payment via PayPal.)</span> ');



  })




})(jQuery);

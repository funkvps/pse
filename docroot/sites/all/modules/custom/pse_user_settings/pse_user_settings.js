(function ($) {

Drupal.behaviors.addLinkToReferencedEntity = {
  attach: function (context) {
    addProductLinks();
    jQuery('.field-type-commerce-product-reference.field-widget-options-select select', context).change(function(){
      addProductLinks();
    })
  }
};

function addProductLinks(){
  jQuery('.open-product-link').remove();
  jQuery('.field-type-commerce-product-reference.field-widget-options-select select').each(function (context) {
    var value = jQuery(this).val();
    if (value && value != '_none') {
      jQuery(this).after('<div class="open-product-link"><a target="_blank" href="/admin/commerce/products/' + value + '">open product in new page</a></div>')
    }
  });
}

})(jQuery);
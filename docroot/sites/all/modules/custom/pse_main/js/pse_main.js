
(function ($) {

Drupal.behaviors.newsLandingPage = {
  attach: function (context) {
    if (jQuery('.mod-big-teaser').length > 0) {
//      jQuery('.main-container > .row > .col-sm-9').removeClass('col-sm-9');
//      //jQuery('.mod-big-teaser').addClass('col-sm-9').after(jQuery('.region.region-sidebar-second').addClass('region-moved'));
//      jQuery('.mod-big-teaser').addClass('col-sm-9').after(jQuery('aside.col-sm-3').addClass('region-moved'));
    }
//    console.log('organise');
//    console.log(jQuery('#admin-menu-menu a[href="/node/add"]'));
//    setTimeout(function(){
//      var menu_items = jQuery('#admin-menu-menu a[href="/node/add"]').next();
//      if (menu_items.length > 0) {
//        pseOrganiseContentTypes(menu_items);
//      }
//      var menu_items = jQuery('#admin-menu-menu a[href="/admin/structure/types"]').next();
//      if (menu_items.length > 0) {
//        pseOrganiseContentTypes(menu_items);
//      }
//    }, 1000);
//
//    if(jQuery('body.page-node-add').length > 0 && jQuery('.page-node-add .admin-list').length > 0){
//        pseOrganiseContentTypes(jQuery('.page-node-add .admin-list'));
//    }
//    if(jQuery('body.page-admin-structure-types').length > 0 && jQuery('table.sticky-enabled tbody').length > 0){
//        pseOrganiseContentTypes(jQuery('table.sticky-enabled tbody'), 'tr');
//    }
  }
};


  Drupal.behaviors.imceTwoImages = {
    attach: function (context) {
      if (jQuery('#preview-wrapper', context).length > 0) {
        var PSEchangeIsExternal = true;
        jQuery('#preview-wrapper', context).bind('DOMSubtreeModified', function() {
          if (PSEchangeIsExternal == false) {
            return;
          }
          PSEchangeIsExternal = false;

          jQuery('#preview-wrapper .responsive').remove();

          console.log('DOMSubtreeModified');
          var img = jQuery('a', this).clone();
          console.log('img', img);
          img.addClass('responsive');
          jQuery('#preview-wrapper').prepend(img);
          PSEchangeIsExternal = true;
        })
      }
    }
  };

})(jQuery);
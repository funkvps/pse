(function ($) {

Drupal.behaviors.organiseContentTypes = {
  attach: function (context) {
//    console.log('organise');
//    console.log(jQuery('#admin-menu-menu a[href="/node/add"]'));
    setTimeout(function(){
      pseAttachDelayedOrganiseContentTypes();
    }, 1000);
    
    setTimeout(function(){
      pseAttachDelayedOrganiseContentTypes();
    }, 2000);

    if(jQuery('body.page-node-add').length > 0 && jQuery('.page-node-add .admin-list').length > 0){
      if (jQuery('.page-node-add .admin-list').hasClass('organise-types-processed') == false) {
        jQuery('.page-node-add .admin-list').addClass('organise-types-processed');
        pseOrganiseContentTypes(jQuery('.page-node-add .admin-list'));
      }
    }
    if(jQuery('body.page-admin-structure-types').length > 0 && jQuery('body.page-admin-structure-types-manage').length == 0 && jQuery('table.sticky-enabled tbody').length > 0){
      if (jQuery('table.sticky-enabled tbody').hasClass('organise-types-processed') == false) {
        jQuery('table.sticky-enabled tbody').addClass('organise-types-processed');
        pseOrganiseContentTypes(jQuery('table.sticky-enabled tbody'), 'tr');
      }
    }
    
    jQuery('dl.commerce-product-type-list a[href="/admin/commerce/products/add/training"]').parent()
      .addClass('pse-add-training')
      .prependTo(jQuery('dl.commerce-product-type-list'))
      .before('<dt class="pse-commonly-used"><h3>Commonly used</h3></dt>')
      .after('<dt class="pse-rarely-used"><h3>Rarely used</h3></dt>');
  }
};

})(jQuery);

function pseAttachDelayedOrganiseContentTypes(context) {
  var menu_items = jQuery('#admin-menu-menu a[href="/node/add"]').next();
  if (menu_items.length > 0 && menu_items.hasClass('organise-types-processed') == false) {
    menu_items.addClass('organise-types-processed');
    pseOrganiseContentTypes(menu_items);
  }
  var menu_items = jQuery('#admin-menu-menu a[href="/admin/structure/types"]').next();
  if (menu_items.length > 0 && menu_items.hasClass('organise-types-processed') == false) {
    menu_items.addClass('organise-types-processed');
    pseOrganiseContentTypes(menu_items);
  }
}

function pseOrganiseContentTypes(originalList, listItemTag) {
  var nodeTypes = [];
  if (typeof listItemTag == 'undefined') {
      listItemTag = 'li'
  }
  nodeTypes['commonlyUsed'] = ['page', 'presentation', 'video_presentations', 'testimonial', 'news_articles', 'hotel', 'events_and_webinar', 'contact_us', 'publication', 'office',
    'events_page', 'training_course', 'customer_area_page', 'customer_area_download', 'contact_us'];
  nodeTypes['rareNodeTypes'] = ['director_listing', 'intranet_home_page', 'visitor-centre2', 'training_listings', 'faq_page', 'customer_area_forms',
    'world_wide_contact', 'home', 'settings', 'footer_blocks', 'error_page', 'download_signup_form', 'events_page'];
  nodeTypes['notNodeTypes'] = ['node_export'];
  var lists = {commonlyUsed:[], normalNodeTypes:[], rareNodeTypes: [], notNodeTypes:[]};
  jQuery('> ' + listItemTag, originalList).each(function(){
    var url = jQuery('a', this).attr('href');
    if (typeof url == 'undefined') {
      return;
    }
    var list_item = this;
    var defaultType = true;
    for(type in nodeTypes) {
      jQuery.each(nodeTypes[type], function(index, value){
        if(url.indexOf(value.replace(/_/g, '-')) !== -1
        || url.indexOf(value) !== -1){
          lists[type].push(list_item);
          defaultType = false
          return false;
        }
      })
    }
    if (defaultType == true) {
      lists['normalNodeTypes'].push(list_item);
    }
  })
//    console.log('originalList', originalList);
    var newList = originalList.clone().empty();
//    console.log('newList', newList);
    for (type in lists) {
        if (type == 'commonlyUsed') {
            if(listItemTag == 'li') {
                newList.append('<li class="content-type-group-name" >Commonly used</li>');
            } else {
                newList.append('<tr class="content-type-group-name" ><td colspan="6">Commonly used</td></tr>');
            }
      jQuery.each(lists[type], function(index, value) {
        newList.append(value);
      })
    } else if (type == 'normalNodeTypes') {
            if(listItemTag == 'li') {
                newList.append('<li class="content-type-group-name" >Moderately used</li>');
            } else {
                newList.append('<tr class="content-type-group-name" ><td colspan="6">Moderately used</td></tr>');
            }
      jQuery.each(lists[type], function(index, value) {
        newList.append(value);
      })
    } else if (type == 'rareNodeTypes') {
            if(listItemTag == 'li') {
                newList.append('<li class="content-type-group-name" >Rarely used</li>');
            } else {
                newList.append('<tr class="content-type-group-name"><td colspan="6" >Rarely used</td></tr>');
            }
      jQuery.each(lists[type], function(index, value) {
        newList.append(value);
      })
    } else if (type == 'notNodeTypes') {
      //newList.push('<li><h3>Commonly used content types</h3></li>');
    }
  }
//  newList += '</ul>';
//  console.log('lists', lists);
//  console.log('newList', newList);
  originalList.replaceWith(newList);
}

//jQuery(function(){
////    console.log('document ready');
//    if(jQuery('.page-node-add').length > 0 && jQuery('.page-node-add .admin-list').length > 0){
////      alert('this is it');
//        var commonlyUsed = ['page', 'presentation', 'video_presentations', 'testimonial', 'news_articles', 'hotel', 'events_and_webinar', 'contact_us', 'publication', 'office',
//        'events_page', 'training_course', 'customer_area_page', 'customer_area_download', 'contact_us'];
//        var rareNodeTypes = ['director_listing', 'intranet_home_page', 'visitor-centre2', 'training_listings', 'faq_page', 'customer_area_forms',
//        'world_wide_contact', 'home', 'settings', 'footer_blocks', 'error_page', 'download_signup_form', 'events_page'];
//        var notNodeTypes = ['node_export'];
//
//        var defaultAdminList = jQuery('#block-system-main .admin-list')
//
//        defaultAdminList.before('<br><br><div class="commonly-used"><h3>Commonly used content types</h3> <ul class="admin-list"></ul></div>');
//        var commonlyUsedList = jQuery('.commonly-used ul');
//        defaultAdminList.before('<br><br><h3>Normal content types</h3>');
//
//        defaultAdminList.after('<br><br><div class="rarely-used"><h3>Rarely used content types</h3> <ul class="admin-list"></ul></div>');
//        var rarelyUsedList = jQuery('.rarely-used ul');
//        jQuery('li', defaultAdminList).each(function(){
////            rarelyUsed.push(this);
//            var url = jQuery('a', this).attr('href');
//            var pageIsCommonlyUsed = false;
//            var pageIsRare = false;
//            var pageIsNotNode = false;
//            jQuery.each(commonlyUsed, function(index, value){
//                if(url.indexOf(value.replace(/_/g, '-')) !== -1){
//                    pageIsCommonlyUsed = true;
//                    return false;
//                }
//            })
//            jQuery.each(rareNodeTypes, function(index, value){
//                if(url.indexOf(value.replace(/_/g, '-')) !== -1){
//                    pageIsRare = true;
//                    return false;
//                }
//            })
//            jQuery.each(notNodeTypes, function(index, value){
//                if(url.indexOf(value.replace(/_/g, '-')) !== -1){
//                    pageIsNotNode = true;
//                    return false;
//                }
//            })
//            if(pageIsCommonlyUsed === true){
//                commonlyUsedList.append(this);
//            }
//            if(pageIsRare === true){
//                rarelyUsedList.append(this);
//            }
//            if(pageIsNotNode === true){
//                if(typeof notNodeList === 'undefined'){
//                    rarelyUsedList.after('<br><br><div class="not-nodes"><h3>Not node content types</h3> <ul></ul></div>');
//                    var notNodeList = jQuery('.not-nodes ul');
//                }
//                notNodeList.append(this);
//            }
//        })
//    }
//})
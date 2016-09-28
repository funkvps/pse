window.mobilecheck = function() {
	var check = false;
	(function(a, b) {
		if (/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|mobile.+firefox|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows ce|xda|xiino/i.test(a) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0, 4)))
			check = true
	})(navigator.userAgent || navigator.vendor || window.opera);
	return check;
}



jQuery(document).ready(function() {
  jQuery('table.my-orders').each(function(){
    if (jQuery('tr', this).length > 4) {
      // on user dashboard user can have orders table, 
      // lets show just 3 first items and add button to show more
      jQuery('tr + tr + tr + tr + tr', this).hide();
      jQuery(this).after('<a class="more-link more-orders" href="#">more orders</a>');
    }
  })
  
  jQuery('.more-orders').click(function(event){
    var button = jQuery(this);
    var table = button.prev();
    if (jQuery(this).hasClass('expanded')) {
//      jQuery('tr + tr + tr + tr + tr', table).slideUp(3000);
      jQuery('tr + tr + tr + tr + tr', table).fadeOut();
      button.removeClass('expanded').html('more orders');
    } else {
//      jQuery('tr + tr + tr + tr + tr', table).slideDown(3000);
      jQuery('tr + tr + tr + tr + tr', table).fadeIn();
      button.addClass('expanded').html('less orders');
    }
    button.blur();
    event.preventDefault();
  })

	// Open preferences tab if user wan't to change interests
	if (window.location.hash.substr(1) == 'preferences') {
		jQuery('.horizontal-tab-button-3 a').trigger('click');
	}

})

jQuery(document).ready(function() {
  if(window.location.hash && window.location.hash == '#interests') {
    setTimeout(function() {
      jQuery('.horizontal-tab-button-3 a').trigger('click');
    }, 500);
    setTimeout(function() {
      jQuery('.horizontal-tab-button-3 a').trigger('click');
    }, 1500);
  }
});

//jQuery(document).ready(function() {
// // check where the shoppingcart-div is  
////  var stickyElements = '.page-full-url-user-dashboard .region-sidebar-second';
////  var jStickyElement = jQuery(stickyElements);
////  var jStickyElementParent = jStickyElement.parent().parent();
////  var contentBottom = jStickyElementParent.height() + jStickyElementParent.offset().top;
////
////  jQuery(window).scroll(function () {  
////    var scrollTop = jQuery(window).scrollTop(); // check the visible top of the browser  
////    var offset = jQuery(stickyElements).offset();
////    if (offset.top < scrollTop) {
////      jStickyElement.addClass('fixed-content');
//////      var sidebarBottom = jStickyElement.height() + 30;
////      var newTop = scrollTop;
////      console.log('contentBottom', contentBottom);
////      if (newTop > contentBottom - jStickyElement.height()) {
////        newTop = contentBottom - jStickyElement.height();
////      }
////      jStickyElement.css('top', newTop);
////    } else {
////      jStickyElement.removeClass('fixed-content');
////    }
////  });
//  
//  
//  $ = jQuery;
//  if ($('.page-full-url-user-dashboard .region-sidebar-second').length) { // make sure "#sticky" element exists
//    var el = $('.page-full-url-user-dashboard .region-sidebar-second');
//    var stickyTop = $('.page-full-url-user-dashboard .region-sidebar-second').offset().top; // returns number
//
//    $(window).scroll(function(){ // scroll event
//      var stickyHeight = $('.page-full-url-user-dashboard .region-sidebar-second').height();
//      var limit = $('footer#bottom').offset().top - stickyHeight - 20;
//
//      var windowTop = $(window).scrollTop(); // returns number
//
//      if (stickyTop < windowTop + 50){
//         el.css({ position: 'fixed', top: 50});
//      }
//      else {
//         el.css({position: 'static'});
//      }
//
//      if (limit < windowTop) {
//        var diff = limit - windowTop;
//        el.css({top: diff});
//      }
//    });
//  }
//  
//  
//  
//});

jQuery(document).ready(function() {

	jQuery(".select_mob").change(function() {
		window.location = jQuery(this).val();
	});
});

/////// MODALS ///////
jQuery('#myModal').modal();

///// FANCYBOX /////////
jQuery(".fancybox").fancybox({
	openEffect: "none",
	closeEffect: "none"
});


jQuery(document).ready(function() {



	jQuery(".images").fancybox();
});



/////// TOOLTIPS ///////
//jQuery('[data-toggle="tooltip"]').tooltip();
jQuery("[rel=tooltip]").tooltip({placement: 'top'});



//portfolio slick
jQuery(window).load(function() {




	// PORTFOLIO 
	if (!window.mobilecheck()) {
		jQuery('.content_portfolio .collapse.first').collapse({toggle: false});
		jQuery('.content_portfolio .collapse.notfirst').collapse({toggle: true});
		jQuery('#accordion').on('show.bs.collapse', function() {
			jQuery('.content_portfolio .collapse').collapse({toggle: true});
			jQuery('#accordion .in').collapse('hide');
		});
	}
	;

});

jQuery(document).ready(function() {

	jQuery('.home_banners').slick({
		dots: true,
		arrows: false,
		fade: true,
		infinite: true,
		speed: 300,
		slidesToShow: 1,
		autoplay: true,
		autoplaySpeed: 6000
	});
	jQuery('.home_feature').slick({
		dots: false,
		infinite: true,
		speed: 300,
		slidesToShow: 2,
		slidesToScroll: 2,
		autoplay: true,
		autoplaySpeed: 3000
	});

	jQuery('.page_gallery').slick({
		dots: false,
		infinite: true,
		speed: 300,
		slidesToShow: 1,
		autoplay: true,
		autoplaySpeed: 6000

	});
	jQuery('.side_testimonial').slick({
		dots: false,
		arrows: false,
		infinite: true,
		fade: true,
		speed: 300,
		slidesToShow: 1,
		autoplay: true,
		autoplaySpeed: 5000

	});
	jQuery('.slick_page_banner').slick({
		dots: false,
		infinite: true,
		speed: 300,
		slidesToShow: 1,
		autoplay: true,
		autoplaySpeed: 6000

	});

	$('.slider-for').slick({
		slidesToShow: 1,
		slidesToScroll: 1,
		arrows: false,
		fade: true,
		asNavFor: '.slider-nav'
	});
	$('.slider-nav').slick({
		slidesToShow: 3,
		slidesToScroll: 1,
		asNavFor: '.slider-for',
		dots: true,
		centerMode: true,
		focusOnSelect: true
	});

});

jQuery(document).ready(function() {

	jQuery(".select_mob").change(function() {
		window.location = jQuery(this).val();
	});
});





jQuery(document).ready(function() {


	// HIDE
	jQuery('.overlay .close_white').click(function() {
		jQuery('.overlay').fadeOut(300);
		jQuery('body').removeClass('noscroll');
	});
	jQuery('.overlay .close_black').click(function() {
		jQuery('.overlay').fadeOut(300);
		jQuery('body').removeClass('noscroll');
	});
	jQuery('.overlay').on('click', '.close_black', function() {
		jQuery('.overlay').fadeOut(300);
		jQuery('body').removeClass('noscroll');
	});


	jQuery(document).mouseup(function(e)
	{
		var container = jQuery(".overlay");

		//console.log(jQuery(e.target).parents('.active_frame').length);

		if (!jQuery(e.target).hasClass('.active_frame') && !jQuery(e.target).parents('.active_frame').length > 0 && jQuery(e.target).parents('.main-container').length > 0)
		{

			//container.hide();
			jQuery('.overlay').css({'display': 'none'})
			jQuery('body').removeClass('noscroll');
		}
	});


//	jQuery('.news_archive .year_list .year, .news_archive .year .month_list').hide();
//	jQuery('.news_archive .year_list .month').children('.month_list').hide();
//	jQuery('.news_archive .category_header, .news_archive .year_header, .news_archive .month_header').addClass('expandable');
//	jQuery('.news_archive .category_header, .news_archive .year .year_header, .news_archive .month .month_header').click(function() {
//		jQuery(this).next().slideToggle(function() {
//		});
//	});
//
//
//	jQuery('.news_nav ul.news_archive li.month h3.month').addClass('expandable');
//	jQuery('.news_nav ul.news_archive li.month h3.month').click(function() {
//		jQuery(this).children('ul').slideToggle(function() {
//		});
//	});
//
//


	$('.news_archive .year_list, .news_archive .year .month_list, .news_archive .year .month_list .post_list').hide();
  $('.news_archive .year_list .month').children('.month_list').hide();
  $('.news_archive .category_header, .news_archive .year_header, .news_archive .month_header').addClass('expandable');
  $('.btn-collapse-all-archive').hide();
  $('.btn-collapse-wrapper').hide().removeClass('hidden');
  //$('.btn-collapse-all-archive').width($('.btn-collapse-all-archive').width());
  $('.news_archive .category_header, .news_archive .year .year_header, .news_archive .month .month_header').click(function () {
    if ($(this).hasClass('expanded')) {
      $(this).removeClass('expanded');
      var next = $(this).next();
      next.slideUp(function () {
        jQuery('.expanded', next).removeClass('expanded').next().hide();
        if ($('.news_archive .expanded').length == 0) {
          $('.btn-collapse-all-archive').hide();
          $('.btn-collapse-wrapper').slideUp();
        }
      });
    } else {

      $(this).addClass('expanded');
      $(this).next().slideDown(function () {
        jQuery('.btn-collapse-wrapper').slideDown(function () {
          $('.btn-collapse-all-archive').show();
        });
      });
    }
//		$(this).next().slideToggle(function() {});
  });
  $('.btn-collapse-all-archive').click(function () {
    $('.btn-collapse-all-archive').hide();
    $('.btn-collapse-wrapper').slideUp();
    $('.news_archive .expanded').trigger('click');
  })



  $('.news_nav ul.news_archive li.month h3.month').addClass('expandable');
  $('.news_nav ul.news_archive li.month h3.month').click(function () {
    $(this).children('ul').slideToggle(function () {
    });
  });

});



jQuery(window).load(function() {


	if (!window.mobilecheck()) {
		jQuery('.equal_children_height').each(function() {
			var max_height = 0;
			jQuery(this).find('.setheight').each(function() {
				if (jQuery(this).height() > max_height) {
					max_height = jQuery(this).height();
				}
			});
			jQuery(this).find('.setheight').each(function() {
				jQuery(this).height(max_height);
			});
		});

	}
	;

});



jQuery(document).on('click', '.yamm .dropdown-menu', function(e) {
	e.stopPropagation();
});
jQuery(document).on('click', '.yamm .toplevel', function(e) {
	jQuery('.megamenu_overlay').addClass('megamenu_overlay_visible');
});
jQuery(document).on('click', '.megamenu_overlay', function(e) {
	jQuery('.megamenu_overlay').removeClass('megamenu_overlay_visible');
});
jQuery(document).on('click', '.yamm', function(e) {
	jQuery('.megamenu_overlay').removeClass('megamenu_overlay_visible');
});



jQuery(function()
{
	basket = "<h1>Basket</h1>";
	checkout = "<h1>Checkout</h1>";
	review_order = "<h1>Checkout</h1>";




	if (jQuery('.page-cart section #main-content').length > 0)
	{
		if (jQuery('.page-checkout-review section #main-content').length > 0)
		{}
		else { 
			jQuery('.page-cart section #main-content').append(basket);
		}
	}

	if (jQuery('.page-checkout-review section #main-content').length > 0)
	{
		jQuery('.page-checkout-review section #main-content').append(review_order);

	}
	else {
		if (jQuery('.page-checkout- section #main-content').length > 0)
		{
			jQuery('.page-checkout- section #main-content').append(checkout);
		}
	}
	if (jQuery('.page-checkout- .checkout-help').length > 0) 
	{
		jQuery('.page-checkout- .checkout-help').each(function() {
			jQuery(this).html(jQuery(this).text().replace('Review your order before continuing.', 'Please review your order before continuing<br /><br />'));
		});
	}
	if (jQuery('.page-checkout- .pane-title ').length > 0) 
	{
		jQuery('.page-checkout- .pane-title ').each(function() {
			jQuery(this).html(jQuery(this).text().replace('Shopping cart contents', '<strong>Basket</strong><br /><br />'));
		});
	}
	if (jQuery('.page-checkout-complete h1 ').length > 0) 
	{
		jQuery('.page-checkout-complete h1 ').each(function() {
			jQuery(this).html(jQuery(this).text().replace('Checkout', 'Booking confirmation'));
		});
	}
	if (jQuery('.page-checkout-payment button.form-submit').length > 0) 
	{
		jQuery('.page-checkout-payment button.form-submit').each(function() {
			jQuery(this).html(jQuery(this).text().replace('Proceed to PayPal', 'Proceed to payment'));
		});
	}
	if (jQuery('.logged-in.page-user .form-item-field-profile-sector-interest-und label').length > 0) 
	{
		jQuery('.logged-in.page-user .form-item-field-profile-sector-interest-und label').each(function() {
			jQuery(this).html(jQuery(this).text().replace('Sector Interest', 'User preferences'));
		});
	}



})



//jQuery(document).ready(function() {
//  jQuery('.facet-multiselect-checkbox').change(function(){
//    
//  });
//});

jQuery(document).ready(function() {
	jQuery('.megamenu [data-toggle=tab]').hover(function(e) {
		jQuery(this).click();
	});
});
jQuery(document).ready(function() {
	jQuery('.megamenu .subnav_panel li a').hover(function(e) {
		jQuery(this).toggleClass('active');
	});
});






//jQuery(document).ready(function () {
//	
////	var x = readCookie('newsletter_cookie')
////
////	if (x == 'true') {
////
////	} else {
////
////		$('#news_letter_modal').modal('show');
////	}
////	$('#close_newsletter_btn').click(function () {
////		createCookie('newsletter_cookie', 'true', 7);
////	});
////	$('#webform-client-form-1 .webform-submit').click(function () {
////		createCookie('newsletter_cookie', 'true', 365);
////	});
//
//});


// function createCookie(name, value, days) {
// 	if (days) {
// 		var date = new Date();
// 		date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
// 		var expires = "; expires=" + date.toGMTString();
// 	}
// 	else
// 		var expires = "";
// 	document.cookie = name + "=" + value + expires + "; path=/";
// }


// function readCookie(name) {
// 	var nameEQ = name + "=";
// 	var ca = document.cookie.split(';');
// 	for (var i = 0; i < ca.length; i++) {
// 		var c = ca[i];
// 		while (c.charAt(0) == ' ')
// 			c = c.substring(1, c.length);
// 		if (c.indexOf(nameEQ) == 0)
// 			return c.substring(nameEQ.length, c.length);
// 	}
// 	return null;

// }
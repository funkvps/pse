/**
 * http://bootstrap-growl.remabledesigns.com/
 */
//$.growl('<strong>SAVING:</strong> Do not close this page', {
//    type: 'growl'
//});


//function product_added_to_cart_(prod_name)
//{
//	$.growl('<strong>' + prod_name + ':</strong> was added to cart', {
//		type: 'growl'
//	});
//
//}
function product_added_to_cart(prod_name)
{
	$.growl('<strong>' + prod_name + ':</strong> was added to cart', {
		type: 'growl',
		offset:{
			x:0,
			y:300
		},
		placement:{
			from:'top',
			align:'center'
		}
	});
}
//function product_added_to_cart_reload(prod_name)
//{
//	$.growl('<strong>' + prod_name + ':</strong> was added to cart', {
//		type: 'growl',
////		animate: {
////			enter: 'animated flipInY',
////			exit: 'animated flipOutX'
////		},
//		offset:{
//			x:0,
//			y:300
//		},
////		placement:{
////			from:'top',
////			align:'center',
////		},
////		delay:5000,
////		onClosed:reload(),
//		
//	});
//}
//
//
//function product_multiple_currency_error(prod_name)
//{
//	$.growl('<strong>' + prod_name + ':</strong> Cannot Be added, Please Use One Currency', {
//		type: 'growl',
//		animate: {
//			enter: 'animated flipInY',
//			exit: 'animated flipOutX'
//		}
//	});
//}
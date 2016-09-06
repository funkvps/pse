$(function() {
	var minlength = 4;
	$("#search_input").keyup(function() {
		var that = this, value = $(this).val();
		if (value.length >= minlength) {
			$.ajax({
				type: "GET",
				url: '/search/get_json_data/product_name',
				data: {
					'name': value
				},
				dataType: "text",
				success: function(msg) {
					//we need to check if the value is the same

					$('#search_results').html(msg);
					if (value == $(that).val()) {

//                            $('#results').html(msg);

						//Receiving the result of search here
					}
				}
			});
		}
	});

	$(document).click(function() {
		if ($(this).parents('.header_search').length == 0)
		{
			$('#search_results').html("");
			$('#search_input').val("");
		}
	});
});
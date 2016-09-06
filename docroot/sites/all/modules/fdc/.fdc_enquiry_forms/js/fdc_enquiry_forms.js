
$(function()
{

	$('#fdc-amigos-enquiry-form').submit(function()
	{
		var name = $('#edit-fdc-enquiry-form-name').val();
		var email = $('#edit-fdc-enquiry-form-email').val();
		var phone = $('#edit-fdc-enquiry-form-contact-number').val();

		if (name != "" && email != "" && phone != "")
		{
			return true;
		}
		else
		if ((name == "") || (email == "") || (phone == ""))
		{
			return false;
		}
		else
		{
			return true;
		}

	});

	$('#myModal').on('show.bs.modal', function(event) {
		var button = $(event.relatedTarget);// Button that triggered the modal

		var heading = button.data('heading');
		var code = button.data('code');
		var startdate = button.data('startdate');
		var enddate = button.data('enddate');
		var price = button.data('price');
		var img = button.data('image');
		var rating = button.data('rating');
		var description = button.data('description');

		var everything = 
				"<br/>  " + heading
				+ "<br/> Start Date : " + startdate
				+ "<br/> End date :" + enddate
				+ "<br/> Price: " + price
				+ "<br/> Description: " + description;

//		var recipient = button.data('whatever') // Extract info from data-* attributes
		// If necessary, you could initiate an AJAX request here (and then do the updating in a callback).
		// Update the modal's content. We'll use jQuery here, but you could use a data binding library or other methods instead.
		var modal = $(this);
//		modal.find('.modal-title').text('New message to ' + recipient)
//		modal.find('#modal_hotel_deal_info').html(recipient);

		modal.find('#modal_hotel_info_heading').html(heading);
		modal.find('#modal_hotel_info_start_dates').html(startdate);
		modal.find('#modal_hotel_info_end_dates').html(enddate);
		modal.find('#modal_hotel_info_description').html(description);
		modal.find('#modal_hotel_info_image').html(img);
		modal.find('#modal_hotel_info_price').html(price);
		modal.find('input[name="fdc_enquiry_form_code"]').val(code);
		modal.find('input[name="fdc_enquiry_form_more_info"]').val(everything);
	});



});


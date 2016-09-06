
<?php

function fdc_amigos_enquiry_form($form_state) {

	$form = array(
		'#redirect' => true,
	);

	$form['fdc_enquiry_form_name_hotel_info'] = array(
		'#prefix' => '
		<div class="row">
			<div class="col-xs-12 col-sm-12 col-md-8 col-lg-8">
				<div id="modal_hotel_info">
				</div>
				<div id="modal_hotel_info_heading">
				</div>
				<div id="modal_hotel_info_start_dates">
				</div>
				<div id="modal_hotel_info_end_dates">
				</div>
				<div id="modal_hotel_info_description">
				</div>
			</div>
			<div class="col-xs-12 col-sm-12 col-md-4 col-lg-4">
				<div id="modal_hotel_info_image">
				</div>
				<div id="modal_hotel_info_price">
				</div>
				
			</div>
		</div>
		<div class="divider"></div>'
	);
	$form['fdc_enquiry_form_name_deal_info'] = array(
		'#prefix' => '<div id="modal_hotel_deal_info"></div>'
	);


	$form['fdc_enquiry_form_code'] = array(
		'#type' => 'hidden',
		'#title' => t(''),
		'#attributes' => array(
			'class' => array(''),
			'placeholder' => array('code')
		),
		'#maxlength' => 128,
//		'#required' => TRUE,
//		'#description' => t('Please enter your full name'),
	);
	$form['fdc_enquiry_form_more_info'] = array(
		'#type' => 'hidden',
		'#title' => t(''),
		'#attributes' => array(
			'class' => array(''),
//			'placeholder' => array('code')
		),
//		'#maxlength' => 128,
//		'#required' => TRUE,
//		'#description' => t('Please enter your full name'),
	);

	$form['fdc_enquiry_form_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Full Name'),
		'#attributes' => array(
			'class' => array('full_name'),
			'placeholder' => array('Your Full Name')
		),
		'#maxlength' => 128,
		'#required' => TRUE,
		'#description' => t('Please enter your full name'),
	);
	$form['fdc_enquiry_form_email'] = array(
		'#type' => 'textfield',
		'#title' => t('Email Address'),
		'#attributes' => array(
			'class' => array('email'),
			'placeholder' => array('Your contact E-mail address')
		),
		'#maxlength' => 128,
		'#required' => TRUE,
		'#description' => t('Please enter your contact E-mail address'),
	);


	$form['fdc_enquiry_form_contact_number'] = array(
		'#type' => 'textfield',
		'#title' => t('Your Phone Number'),
		'#attributes' => array(
			'placeholder' => array('Your Phone Number')
		),
		'#maxlength' => 128,
		'#required' => TRUE,
		'#description' => t('Please enter Your Phone Number'),
	);

	$form['fdc_enquiry_form_where'] = array(
		'#type' => 'textfield',
		'#title' => t('Where did you hear about us?'),
		'#attributes' => array(
			'class' => array('full_name'),
			'placeholder' => array('Where did you hear about us?')
		),
		'#maxlength' => 128,
		'#required' => FALSE,
		'#description' => t('Where did you hear about us?'),
	);
	$form['fdc_enquiry_form_extra'] = array(
		'#type' => 'textarea',
		'#title' => t('Any Extra information'),
		'#attributes' => array(
			'class' => array('any_extra_information'),
			'placeholder' => array('Any Extra information')
		),
		'#maxlength' => 128,
		'#required' => FALSE,
		'#description' => t(''),
	);


	$form['fdc_enquiry_form_submit'] = array(
		'#type' => 'submit',
		'#attributes' => array('class' => array('gradient')),
		'#value' => t('Submit'),
	);

	return $form;
}

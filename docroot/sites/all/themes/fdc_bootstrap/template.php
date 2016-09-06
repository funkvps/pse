<?php
/**
 * @file
 * template.php
 */
//function phptemplate_removetab($label, &$vars) {
//  $tabs = explode("\n", $vars['tabs']);
//  $new_tabs =  array();
//  $vars['tabs'] = "";
//
//  foreach ($tabs as $tab) {
//    // add the tab to the new tabs if it's not the one we're removing
//    if (stripos($tab, '>' . $label . '<') === FALSE) {
//      $new_tabs[] = $tab;
//    }
//  }
//
//  $new_tabs_string = implode ($new_tabs,"\n");
//
//  //only display if there is more than one tab
//  //there's probably a more elegant way of doing this
//  $pieces = explode("</li>",$new_tabs_string);
//  if (sizeof($pieces) > 2) {
//    $vars['tabs'] = $new_tabs_string;
//  }
//}

function fdc_bootstrap_theme() {
	$items = array();
	$items['user_login'] = array(
		'render element' => 'form',
		'path' => drupal_get_path('theme', 'fdc_bootstrap') . '/templates',
		'template' => 'user-login',
	);

	$items['user_register_form'] = array(
		'render element' => 'form',
		'path' => drupal_get_path('theme', 'fdc_bootstrap') . '/templates',
		'template' => 'user-register-form',
	);
	return $items;
}

function fdc_bootstrap_breadcrumb($variables) {
	$arg = arg();
//	$path = current_path();
	$path = request_path();
//	$pathe = request_uri();

	$explode_path = explode('/', $path);
  pse_main__add_breadcrumb();
  
  $breadcrumb = drupal_set_breadcrumb();
  
  foreach ($breadcrumb as $delta => $breadcrumb_part) {
    if (is_array($breadcrumb_part)) {
      unset($breadcrumb[$delta]); // Or we could have static text, but FDC didn't use it
    }
    if (strpos($breadcrumb_part, 'nolink') !== false) {
      unset($breadcrumb[$delta]); // we had work "company" at news page
    }
  }
  
  if (!empty($breadcrumb)) {
    if ($breadcrumb[0] == '<a href="/">Home</a>') {
      $breadcrumb[0] = '<a href="/">PSE</a>';
    }
		if ($explode_path[0] == 'customer-area' && $explode_path[1] == 'downloads'){
			unset($breadcrumb[2]);
		}
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<div id="trail">';
	  $output .= '<ul id="breadcrumbs"><li>' . implode('</li><li>', $breadcrumb) . '</li></ul>';
    $output .= '</div>';
    return $output;
  }
}

//function fdc_bootstrap_form_alter(&$form, &$form_state, $form_id) {
//	if ($form_id == 'user_login_block') {
//		$form['links']['#markup'] = '<div class="item-list"><ul><li class="first"><a href="/user/register" title="Create a new user account.">Create new account</a></li></ul></div>';
//	}
//}


/*
 * 	THEME FUNCS
 * theme_status_messages
 * 
 */
function fdc_bootstrap_status_messages($variables) {
  return theme_status_messages($variables); // return simple messages for development/debuging
	$display = $variables['display'];
	$output = '';

	$status_heading = array(
		'status' => t('Status message'),
		'error' => t('Error message'),
		'warning' => t('Warning message'),
	);
	foreach (drupal_get_messages($display) as $type => $messages) {
		// ! important : adding html needed for the modal.
		$output = '<div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog ">
      <div class="modal-content">
        <div class="modal-body">';

		$output .= "<div class=\"_messages $type\">\n";
		if (!empty($status_heading[$type])) {
			$output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
		}
		if (count($messages) > 1) {
			$output .= " <ul>\n";
			foreach ($messages as $message) {
				$output .= '  <li>' . $message . "</li>\n";
			}
			$output .= " </ul>\n";
		}
		else {
			$output .= $messages[0];
		}
		$output .= "</div>\n";

		$output .= '</div>
        <div class="modal-footer">
          <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
        </div>
      </div><!-- /.modal-content -->
    </div><!-- /.modal-dialog -->
    </div><!-- /.modal -->';
	}
	return $output;
}

// MENU FUNCTIONALITY ---------------------------------------------------------------------
function get_siblings_menu($menuname, $nid, $selectlist = NULL) {

	/*
	 * 	this really would be better returned as an array.
	 * 	however due to multiple loops requires too much time. - Mitchell
	 */

	$menu_a = menu_tree_page_data($menuname);


	if (isset($selectlist) && $selectlist) {
		foreach ($menu_a as $k => $item) {
			$success = false;

			if ($item['below']) {
				$menu_siblings = '<div class="visible-xs">';
				$menu_siblings = '<select class="nav_siblings_smalldevices select_mob">';
				$menu_siblings .= '<option value="" style="display:none;">Select a Page</option>';
				foreach ($item['below'] as $child) {

					if (str_replace('node/', '', $child['link']['link_path']) == $nid) {

						$menu_siblings .= '<option selected="selected" value="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</option>';

						$success = true;
					}
					else {
						$menu_siblings .= '<option value="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</option>';
					}
				}
				$menu_siblings .= '</select></div>';
			}

			if ($success) {
				return $menu_siblings;
			}
		}
	}
	else {
		foreach ($menu_a as $k => $item) {

			$select_options_html = '<div class="visible-xs">';
			$select_options_html .= '<select class="nav_siblings_smalldevices select_mob">';
			$select_options_html .= '<option value="" style="">Select a Page</option>';
			$success = false;

			if ($item['link']['link_path'] != '<nolink>') {
				$menu_siblings = '<h2 class="nav_siblings_title">
						<a href="' . url($item['link']['link_path']) . '">' . $item['link']['title'] . '</a>
						</h2>';
			}
			else {
				$menu_siblings = '<h2 class="nav_siblings_title">
						' . $item['link']['title'] . '
						</h2>';
			}

			if ($item['below']) {
				$menu_siblings .= '<ul class="list">';
				foreach ($item['below'] as $child) {

					if (str_replace('node/', '', $child['link']['link_path']) == $nid) {
						$menu_siblings .= '
							<li class="active">
							<a href="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</a>
							</li>';
						$select_options_html .= '<option selected value="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</option>';
						$success = true;
					}
					else {
						$menu_siblings .= '<li><a href="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</a></li>';
						$select_options_html .= '<option value="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</option>';
					}

					// SUPPORT FOR GRANDCHILDREN - 2013-08-30
					if (isset($child['below']) && $child['below']) {

						$menu_siblings .= '<ul class="list">';
						foreach ($child['below'] AS $grandchild) {

							if (str_replace('node/', '', $grandchild['link']['link_path']) == $nid) {
								$menu_siblings .= '
									<li class="active">
										<a href="' . url($grandchild['link']['link_path']) . '">' . $grandchild['link']['title'] . '</a>
									</li>';

								$select_options_html .= '<option selected value="' . url($grandchild['link']['link_path']) . '">' . $grandchild['link']['title'] . '</option>';
								$success = true;
							}
							else {
								$menu_siblings .= '<li><a href="' . url($grandchild['link']['link_path']) . '">' . $grandchild['link']['title'] . '</a></li>';
								$select_options_html .= '<option value="' . url($grandchild['link']['link_path']) . '">' . $grandchild['link']['title'] . '</option>';
							}
						}

						$menu_siblings .= '</ul>';
					}
					// SUPPORT FOR GRANDCHILDREN - 2013-08-30
				}
				$select_options_html .= '</select></div>';
				$menu_siblings .= '</ul>';
			}

			if ($success) {
				return $menu_siblings . $select_options_html;
			}
		}
	}
}

function get_children_menu($menuname, $parent_nid, $selectlist = NULL) {

	$menu_a = menu_tree_page_data($menuname);



	$menu_items = array();
	if ($menu_a) {

		$select_options_html = '<div class="visible-xs">';
		$select_options_html .= '<select class="nav_siblings_smalldevices select_mob">';
		$select_options_html .= '<option value="" style="">Select a Page</option>';
		foreach ($menu_a as $item) {
			$nid = str_replace('node/', '', $item['link']['link_path']);
			$menu_items[$nid] = array();
//			$menu_items[$nid]['title'] = $item['link']['title'];
			$menu_items[$nid]['link_path'] = $item['link']['link_path'];
			if ($item['below']) {
				foreach ($item['below'] as $child) {
					$menu_items[$nid]['children'][] = array(
						'title' => $child['link']['title'],
						'link_path' => $child['link']['link_path'],
					);

					$select_options_html .= '<option value="' . url($child['link']['link_path']) . '">' . $child['link']['title'] . '</option>';
				}
			}
		}
		$select_options_html .= '</select></div>';
	}
	if (isset($selectlist)) {
		if (isset($menu_items[$parent_nid]['children'])) {
			$html = '<div class="visible-xs">';
			$html = '<select class="nav_siblings_smalldevices select_mob">';
			$html .= '<option value="" style="display:none;">Select a Page</option>';
			foreach ($menu_items[$parent_nid]['children'] as $child) {
				$html .= '<option value="' . url($child['link_path']) . '">' . $child['title'] . '</option>';
			}
			$html .= '</select></div>';
		}
		if (isset($html)) {
			return $html;
		}
	}
	else {
		if (isset($menu_items[$parent_nid]['children'])) {
			if ($menu_items[$parent_nid]['link_path'] != '<nolink>') {
				$html = '<div class="hidden-xs"><h2 class="nav_siblings_title"><a href="' . url($menu_items[$parent_nid]['link_path']) . '">' . $menu_items[$parent_nid]['title'] . '</a></h2><ul class="nav_siblings">';
			}
			else {
				$html = '<h2 class="nav_siblings_title">' . $menu_items[$parent_nid]['title'] . '</h2><ul class="nav_siblings">';
			}
			foreach ($menu_items[$parent_nid]['children'] as $child) {
				$html .= '<li><a href="' . url($child['link_path']) . '">' . $child['title'] . '</a></li>';
			}
			$html .= '</ul></div>';
		}
//		print_r($menu_items);
		if (isset($html)) {
			return $html . $select_options_html;
		}
	}
}

function child_sibling_menu2($nid) {
	// FILE USED FOR INCLUDING CONTENT INTO CHILDREN/SIBLING MENU STRUCTURE.
	// Original functions by Paul Martin @ FDC Studio
	// Drupal 7 modification & alterations by Mitchell Currie @ FDC Studio
	// $menuname = Name of the current menu item.
	// $nid = the target pages NID.
	// Find Menu Title for Page
	$menuParent = menu_get_active_trail();
	if (sizeof($menuParent) >= 2 && $menuParent[1]) {
		// Grab Title
		$menuParent = $menuParent[1]['link_title'];
	}

	if (isset($menuParent)) {
		// Build Query with D7 Placeholders
		$is_parent_query = "SELECT
					menu_links.link_path
				FROM
					menu_links
				WHERE
					menu_links.link_title = :current_page
				AND
					menu_links.menu_name = 'main-menu'
				LIMIT 1";

		$is_parent_arg = array(
			// Pass in Menu Title to find Link Path
			':current_page' => $menuParent
		);

		$is_parent_result = db_query($is_parent_query, $is_parent_arg);
	}

	if (isset($is_parent_result)) {
		foreach ($is_parent_result as $row) {
			// Pull out NID of LINK PATH for parent
			$menu_node = str_replace('node/', '', $row->link_path);
		}

		// if current pages NID is same as parent menu NID then output get_children_menu, else output siblings.
		if (!empty($menu_node)) {

			if ($menu_node == $nid) {
				$content_menu = get_children_menu('main-menu', $nid);
			}
			else {
				$content_menu = get_siblings_menu('main-menu', $nid);
			}
			if (!empty($content_menu)) {
				return $content_menu;
			}
		}
	}
}

function child_sibling_menu($nid) {
	// FILE USED FOR INCLUDING CONTENT INTO CHILDREN/SIBLING MENU STRUCTURE.
	// Original functions by Paul Martin @ FDC Studio
	// Drupal 7 modification & alterations by Mitchell Currie @ FDC Studio
	// $menuname = Name of the current menu item.
	// $nid = the target pages NID.
	// Find Menu Title for Page
	$menuParent = menu_get_active_trail();
	if (sizeof($menuParent) >= 2 && $menuParent[1]) {
		// Grab Title
		$menuParent = $menuParent[1]['link_title'];
	}

	if (isset($menuParent)) {
		// Build Query with D7 Placeholders
		$is_parent_query = "SELECT
					menu_links.link_path
				FROM
					menu_links
				WHERE
					menu_links.link_title = :current_page
				AND
					menu_links.menu_name = 'main-menu'
				LIMIT 1";

		$is_parent_arg = array(
			// Pass in Menu Title to find Link Path
			':current_page' => $menuParent
		);

		$is_parent_result = db_query($is_parent_query, $is_parent_arg);
	}

	if (isset($is_parent_result)) {
		foreach ($is_parent_result as $row) {
			// Pull out NID of LINK PATH for parent
			$menu_node = str_replace('node/', '', $row->link_path);
		}

		// if current pages NID is same as parent menu NID then output get_children_menu, else output siblings.
		if (!empty($menu_node)) {

			if ($menu_node == $nid) {
				$content_menu = get_children_menu('main-menu', $nid);
			}
			else {
				$content_menu = get_siblings_menu('main-menu', $nid);
			}
			if (!empty($content_menu)) {
				return $content_menu;
			}
		}
	}
}

// GOOGLE MAP FUNCTIONALITY ---------------------------------------------------------------
function get_latlong_from_location($location) {

	// Due to Google's TOS, the Lat/Long cannot be stored within the DB.
	// Also the Map MUST be publically accessable, and not behind passworded areas.

	$get_json = json_decode(file_get_contents('https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyBYsbdgTTa_nXLt60VyZw8AtXwPLn_0LIg&address=' . urlencode($location) . '&sensor=false'), true);

	$lat = $get_json['results']['0']['geometry']['location']['lat'];
	$long = $get_json['results']['0']['geometry']['location']['lng'];


	if ($lat && $long) {
		$geolocation = array(
			'lat' => $lat,
			'long' => $long,
		);

		return $geolocation;
	}
	else {
		return FALSE;
	}
}

function google_map($location, $add_marker = TRUE, $marker_icon = NULL, $zoom = 15, $width = '500px', $height = '500px') {

	if ($location) {
		$geolocation = get_latlong_from_location($location);
	}

	if (is_array($geolocation)) {

		require_once('sites/all/themes/fdc_bootstrap/classes/googlemap.class.php');

		$googleMap = new GoogleMap($geolocation['lat'], $geolocation['long']);
		$googleMap->zoom = $zoom;
		$googleMap->canvasWidth = $width;
		$googleMap->canvasHeight = $height;

		if (is_bool($add_marker) && $add_marker) {
			$googleMap->addMarker($geolocation['lat'], $geolocation['long'], NULL, NULL, '1', 'DROP', $marker_icon);
		}
		else if (is_string($add_marker) && $add_marker) {
			$googleMap->addMarker($geolocation['lat'], $geolocation['long'], $add_marker, NULL, '1', 'DROP', $marker_icon);
		}

		return $googleMap->display();
	}
	else {
		return FALSE;
	}
}

// PAGE FUNCTIONALITY
function getLatestNews($limit = NULL) {
	if (isset($limit) && $limit) {
		$news_limit = (int) $limit;
		$query = db_query_range("
			SELECT
				node.nid,
				node.title,
				field_data_field_news_heading.field_news_heading_value AS `heading`,
				field_data_field_news_date.field_news_date_value AS `date`,
				field_data_field_news_content.field_news_content_value AS `body`,
				field_data_field_news_content.field_news_content_summary AS `summary`,
				file_managed.uri AS `image`,
				field_data_field_news_image.field_news_image_alt AS `image_alt`,
				field_data_field_news_image.field_news_image_title AS `image_title`
			FROM
				node
			LEFT JOIN field_data_field_collection_newsarticle ON field_data_field_collection_newsarticle.entity_id = node.nid
			LEFT JOIN field_data_field_news_heading ON field_data_field_news_heading.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
			LEFT JOIN field_data_field_news_date ON field_data_field_news_date.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
			LEFT JOIN field_data_field_news_content ON field_data_field_news_content.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
			LEFT JOIN field_data_field_news_image ON field_data_field_news_image.entity_id = field_data_field_collection_newsarticle.field_collection_newsarticle_value
			LEFT JOIN file_managed ON file_managed.fid = field_data_field_news_image.field_news_image_fid
			WHERE
				node.`status` = 1
			AND node.type = 'news_article'
			ORDER BY
				field_data_field_news_date.field_news_date_value DESC
			", 0, $news_limit
		);
		if (isset($query) && $query) {
			return $query;
		}
	}
}

function get_latest_news() {
	$query = db_query("
			SELECT
				node.type,
				node.nid,				
				node.title,
				field_data_field_news_heading.field_news_heading_value as heading,
				field_data_field_news_date.field_news_date_value,
				field_data_field_news_summary.field_news_summary_value as summary
			FROM
				node
			INNER JOIN field_data_field_collection_newsarticle ON node.nid = field_data_field_collection_newsarticle.entity_id
			LEFT JOIN field_data_field_news_heading ON field_data_field_collection_newsarticle.field_collection_newsarticle_value = field_data_field_news_heading.entity_id
			LEFT JOIN field_data_field_news_date ON field_data_field_collection_newsarticle.field_collection_newsarticle_value = field_data_field_news_date.entity_id
			LEFT JOIN field_data_field_news_summary ON field_data_field_collection_newsarticle.field_collection_newsarticle_value = field_data_field_news_summary.entity_id
				order by field_data_field_news_date.field_news_date_value DESC
							Limit 3
			")->fetchAll();
	if (isset($query) && $query) {
		return $query;
	}
}

function pageContent($nid) {
	return fdc_pse_node_content($nid);
}

function get_page_banner($nid) {
	if (!empty($nid)) {
		$query = db_query("SELECT
				field_data_field_banner_image.field_banner_image_alt AS img_alt,
				field_data_field_banner_image.field_banner_image_title AS img_title,
				file_managed.uri AS img_path,
				field_data_field_banner_heading.field_banner_heading_value AS heading,
				field_data_field_banner_message.field_banner_message_value AS message
			FROM
				node
			INNER JOIN field_data_field_col_page_banner ON node.nid = field_data_field_col_page_banner.entity_id
			LEFT JOIN field_data_field_banner_image ON field_data_field_col_page_banner.field_col_page_banner_value = field_data_field_banner_image.entity_id
			LEFT JOIN field_data_field_banner_message ON field_data_field_col_page_banner.field_col_page_banner_value = field_data_field_banner_message.entity_id
			LEFT JOIN field_data_field_banner_heading ON field_data_field_col_page_banner.field_col_page_banner_value = field_data_field_banner_heading.entity_id
			LEFT JOIN file_managed ON field_data_field_banner_image.field_banner_image_fid = file_managed.fid
			WHERE
				node.nid = :nid
			ORDER BY
				field_data_field_col_page_banner.delta ASC", array(":nid" => $nid))->fetchAll();
		if (!empty($query)) {
			return $query;
		}
	}
}

function get_mega_menu() {
	$query = db_query("SELECT
							field_data_field_col_mega_menu.field_col_mega_menu_value,
							field_data_field_submenu.field_submenu_value,
							field_data_field_menu_title.field_menu_title_value,
							field_data_field_menu_title_link.field_menu_title_link_value
						FROM
							field_data_field_col_mega_menu
						INNER JOIN field_data_field_menu_title ON field_data_field_col_mega_menu.field_col_mega_menu_value = field_data_field_menu_title.entity_id
						LEFT JOIN field_data_field_menu_title_link ON field_data_field_col_mega_menu.field_col_mega_menu_value = field_data_field_menu_title_link.entity_id
						LEFT JOIN field_data_field_submenu ON field_data_field_col_mega_menu.field_col_mega_menu_value = field_data_field_submenu.entity_id
						ORDER BY
							field_data_field_col_mega_menu.delta ASC")->fetchAll();
	if (!empty($query)) {
		return $query;
	}
}

function get_form_content($nid) {
	if (!empty($nid)) {
		$query = db_query("
		SELECT
			field_data_field_content_heading.field_content_heading_value AS heading,
			field_data_field_content_body.field_content_body_value AS body
		FROM
			node
		INNER JOIN field_data_field_col_content ON node.nid = field_data_field_col_content.entity_id
		LEFT JOIN field_data_field_content_heading ON field_data_field_col_content.field_col_content_value = field_data_field_content_heading.entity_id
		LEFT JOIN field_data_field_content_body ON field_data_field_col_content.field_col_content_value = field_data_field_content_body.entity_id
		WHERE
			node.nid = :nid
				", array(":nid" => $nid))->fetchObject();

		if (isset($query) && $query) {
			return $query;
		}
	}
}

/// get footer menu
function get_footer_menu() {
	$query = db_query("
SELECT
	field_data_field_left_footer.field_left_footer_value,
	field_data_field_col_right_footer.field_col_right_footer_value
FROM
	node
INNER JOIN field_data_field_col_right_footer ON node.nid = field_data_field_col_right_footer.entity_id
LEFT JOIN field_data_field_left_footer ON node.nid = field_data_field_left_footer.entity_id
where node.nid = 46
")->fetchObject();
	if (!empty($query)) {
		return $query;
	}
}

function get_register_content($nid) {
	if (!empty($nid)) {
		$query = db_query("SELECT
	field_data_field_register_page_text.field_register_page_text_value as body
FROM
	node
INNER JOIN field_data_field_register_page_text ON node.nid = field_data_field_register_page_text.entity_id
WHERE
	node.nid = :nid", array(":nid" => $nid))->fetchObject();
		if (!empty($query)) {
			return $query->body;
		}
	}
}

function get_login_content($nid) {
	if (!empty($nid)) {
		$query = db_query("SELECT
	field_data_field_login_page_text.field_login_page_text_value as body
FROM
	node
INNER JOIN field_data_field_login_page_text ON node.nid = field_data_field_login_page_text.entity_id
WHERE
	node.nid = :nid", array(":nid" => $nid))->fetchObject();
		if (!empty($query)) {
			return $query->body;
		}
	}
}


function fdc_bootstrap_preprocess($variables, $hook) {
//  dsm('fdc_bootstrap_preprocess ' . $hook);
}


function fdc_bootstrap_preprocess_html(&$variables) {
  $variables['classes_array'][] = 'page-full-url-' . implode('-', arg());
}

/*
 * Implements preprocess_node hook
 */
function fdc_bootstrap_preprocess_page(&$variables) {
  if (!empty($variables['node']->nid)) {
    $nid = $variables['node']->nid;
    if (!empty($variables['page']['content']['system_main']['nodes'][$nid])) {
      $variables['node_content'] = $variables['page']['content']['system_main']['nodes'][$nid]; //easy access to main node, keep hacking
    }
    
    $variables['content_column_class'] = trim($variables['content_column_class'], '"');
    if (!empty($variables['page']['content']['system_main']['nodes'])) {
      if (!empty($variables['page']['content']['system_main']['nodes'][$nid]['#view_mode'])) {
        $variables['content_column_class'] .= ' node-view-mode-' . $variables['page']['content']['system_main']['nodes'][$nid]['#view_mode'];
      }
      if (!empty($variables['page']['content']['system_main']['nodes'][$nid]['#node']->type)) {
        $variables['content_column_class'] .= ' node-type-' . $variables['page']['content']['system_main']['nodes'][$nid]['#node']->type;
      }
    }
    $variables['content_column_class'] .= '"';
  }
  
  //$variables['theme_hook_suggestions'][] = 'node__news_articles__teaser_small';
//  dsm(arg());
//  dsm($_GET);
//  if ($_GET['q'] == 'news' && !isset($_GET['page']) && empty($_GET['f'])) {
//    $modes = array('main-featured', 'sub-featured-left', 'sub-featured-middle', 'sub-featured-right');
//    $sql = "SELECT entity_id FROM field_data_field_feature_news_article WHERE field_feature_news_article_value = :value";
//    $output = 'Some new content. Some new content. Some new content. Some new content. Some new content. <br>Some new content. ';
//    foreach ($modes as $mode) {
//      $node_nids = db_query($sql, array(':value' => $mode));
//      foreach($node_nids as $node_nid) {
//        $node = node_load($node_nid->entity_id);
//        if ($mode == 'main-featured') {
//          $node->pse_theme_hook_suggestions[] = 'node__news_articles__teaser_big';
//        } else {
//          $node->pse_theme_hook_suggestions[] = 'node__news_articles__teaser_medium';
//        }
////        dsm('featured node nid ' . $node->nid);
//        $node_view = node_view($node, 'teaser');
////        dsm($node_view);
//        $output .= drupal_render($node_view);
//      }
//    }
//    $variables['page']['content']['system_main']['main']['#markup'] = $output . $variables['page']['content']['system_main']['main']['#markup'];
//    
//  }
//  dsm($variables);
}


/*
 * Implements preprocess_node hook
 * Doesn't work in full view!!! because fdc did'nt use proper rendering
 */
function fdc_bootstrap_preprocess_node(&$variables) {
//  dsm('fdc_bootstrap_preprocess_node');
//  dsm($variables);
  static $news_teaser_no;
  if (empty($news_teaser_no)) {
    $news_teaser_no = 0;
  }
  
  
//  dsm($node);
  switch($variables['type']) {
    case 'news_articles':
      if ($variables['view_mode'] == 'teaser') {
        $content = &$variables['content'];
        $field_collection_id = key($content['field_collection_newsarticle'][0]['entity']['field_collection_item']);
        $variables['field_collection'] = &$content['field_collection_newsarticle'][0]['entity']['field_collection_item'][$field_collection_id];
        $variables['field_collection']['#field_collection_id'] = $field_collection_id;
        $field_collection = &$variables['field_collection'];
        if (!empty($field_collection['field_news_heading'][0]['#markup'])) {
//          dsm($field_collection['field_news_heading']);
          $variables['title'] = $field_collection['field_news_heading']['#items'][0]['value'];
          hide($field_collection['field_news_heading']);
        }
        if (!empty($content['field_press_release_pdf'])) {
          hide($content['field_press_release_pdf']);
        }
        if (!isset($_GET['page']) && empty($_GET['f'])) {
          if (empty($news_teaser_no)) {
            $news_teaser_no++;
            $variables['theme_hook_suggestions'][] = 'node__news_articles__teaser_big';
//            dsm($variables);
          } elseif($news_teaser_no < 4) {
            $news_teaser_no++;
            $variables['theme_hook_suggestions'][] = 'node__news_articles__teaser_medium';
          } else {
            $variables['theme_hook_suggestions'][] = 'node__news_articles__teaser_small';
          }
        } else {
          hide($variables['field_collection']['field_news_image']);
          $variables['theme_hook_suggestions'][] = 'node__news_articles__teaser';
        }
      }
      break;
  }
  
  if (!empty($variables['node']->pse_theme_hook_suggestions)) {
    $variables['theme_hook_suggestions'] = array_merge($variables['theme_hook_suggestions'], $variables['node']->pse_theme_hook_suggestions);
  }
  if (node_access('update', $variables['node'])) {
    $variables['content']['edit'] = array(
      '#markup' => l('edit', 'node/' . $variables['node']->nid . '/edit', array('attributes' => array('class' => array('btn btn-edit')))),
      '#weight' => 100,
    );
    if (!empty($variables['content']['field_feature_news_article'])) {
      $variables['content']['field_feature_news_article']['#weight'] = 90;
    }
  } else {
    if (!empty($variables['content']['field_feature_news_article'])) {
      unset($variables['content']['field_feature_news_article']);
    }
  }
}


function fdc_bootstrap_preprocess_block(&$variables) {
//  dsm($variables);
  // if (!empty($variables['elements']['#block']->bid)) {
//	  dsm('variables[elements][#block]->bid');
//	  dsm($variables['elements']['#block']->bid);
    // switch ($variables['elements']['#block']->bid) {
//		  $edit_link = '<a class="edit-my-preferences" href="/user/' . $user->uid . '/edit#preferences">Edit my interests</a>';
//		  $variabsles['content'] .= $edit_link; // we don't have footer element, for some reason
//			break;
      // case 'views-pse_training_courses-blck_dash':
      // case 'views-pse_news-block_news_user_dash':
      // case 'views-pse_events-block_user_events':
        // global $user;
        // if ($user->uid) {
          // $edit_link = '<a class="edit-my-preferences" href="/user/' . $user->uid . '/edit#preferences">Edit my interests</a>';
//			dsm($variables['content']);
          // $variables['content'] = str_replace('<footer>', '<footer>' . $edit_link, $variables['content']);
        // }
        // break;
    // }
  // }
}

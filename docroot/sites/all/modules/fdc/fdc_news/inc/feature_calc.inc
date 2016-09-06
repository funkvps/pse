<?php
$custom_counter = 4;

$feature1 = array();
$feature2 = array();
$feature3 = array();
$feature4 = array();


if (!empty($fdc_pse_news_features->feature1_nid)) {
	$fnid = $fdc_pse_news_features->feature1_nid;
	foreach ($content['news'] as $key => $n) {
		if ($n->nid == $fnid) {
			$feature1 = $content['news'][$key];
			unset($content['news'][$key]);
		}
	}
	$custom_counter --;
}
else {
	$feature1 = $content['news'][0];
}


if (!empty($fdc_pse_news_features->feature2_nid)) {
	$fnid = $fdc_pse_news_features->feature2_nid;
	foreach ($content['news'] as $key => $n) {
		if ($n->nid == $fnid) {
			$feature2 = $content['news'][$key];
			unset($content['news'][$key]);
		}
	}
	$custom_counter --;
}
else {
	$feature2 = $content['news'][1];
}


if (!empty($fdc_pse_news_features->feature3_nid)) {
	$fnid = $fdc_pse_news_features->feature3_nid;
	foreach ($content['news'] as $key => $n) {
		if ($n->nid == $fnid) {
			$feature3 = $content['news'][$key];
			unset($content['news'][$key]);
		}
	}
	$custom_counter --;
}
else {
	$feature3 = $content['news'][2];
}

if (!empty($fdc_pse_news_features->feature4_nid)) {
	$fnid = $fdc_pse_news_features->feature4_nid;
	foreach ($content['news'] as $key => $n) {
		if ($n->nid == $fnid) {
			$feature4 = $content['news'][$key];
			unset($content['news'][$key]);
		}
	}
	$custom_counter --;
}
else {
	$feature4 = $content['news'][3];
}

$content['news'] = array_slice($content['news'], $custom_counter);
?>
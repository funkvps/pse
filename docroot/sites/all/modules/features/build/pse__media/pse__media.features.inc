<?php
/**
 * @file
 * pse__media.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function pse__media_image_default_styles() {
  $styles = array();

  // Exported image style: bottom_pub_cover.
  $styles['bottom_pub_cover'] = array(
    'label' => 'bottom_pub_cover',
    'effects' => array(),
  );

  // Exported image style: call_to_action.
  $styles['call_to_action'] = array(
    'label' => 'call_to_action',
    'effects' => array(
      91 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: call_to_action_content_image.
  $styles['call_to_action_content_image'] = array(
    'label' => 'call_to_action_content_image',
    'effects' => array(),
  );

  // Exported image style: company_logo.
  $styles['company_logo'] = array(
    'label' => 'company_logo',
    'effects' => array(
      96 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 70,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: course_large.
  $styles['course_large'] = array(
    'label' => 'course_large',
    'effects' => array(
      78 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 375,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: director_image.
  $styles['director_image'] = array(
    'label' => 'Director_image',
    'effects' => array(
      83 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: flag_small.
  $styles['flag_small'] = array(
    'label' => 'flag_small',
    'effects' => array(
      79 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 16,
          'height' => 11,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: googlemapicon.
  $styles['googlemapicon'] = array(
    'label' => 'googlemapicon',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 50,
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_featured_items.
  $styles['home_featured_items'] = array(
    'label' => 'home_featured_items',
    'effects' => array(
      76 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_page_banner_float.
  $styles['home_page_banner_float'] = array(
    'label' => 'home_page_banner_float',
    'effects' => array(
      86 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_page_banner_large.
  $styles['home_page_banner_large'] = array(
    'label' => 'home_page_banner_large',
    'effects' => array(),
  );

  // Exported image style: hotel_courses_thumb.
  $styles['hotel_courses_thumb'] = array(
    'label' => 'hotel_courses_thumb',
    'effects' => array(
      72 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hotel_large.
  $styles['hotel_large'] = array(
    'label' => 'hotel_large',
    'effects' => array(
      71 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 329,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hotel_original.
  $styles['hotel_original'] = array(
    'label' => 'hotel_original',
    'effects' => array(),
  );

  // Exported image style: hotel_thumb.
  $styles['hotel_thumb'] = array(
    'label' => 'hotel_thumb',
    'effects' => array(
      74 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: large.
  $styles['large'] = array(
    'label' => 'Large (480x480)',
    'effects' => array(
      0 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => 480,
          'upscale' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: media_file_thumb.
  $styles['media_file_thumb'] = array(
    'label' => 'media_file_thumb',
    'effects' => array(
      95 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: media_original_file.
  $styles['media_original_file'] = array(
    'label' => 'media_original_file',
    'effects' => array(),
  );

  // Exported image style: media_thumbnail.
  $styles['media_thumbnail'] = array(
    'label' => 'Media thumbnail (100x100)',
    'effects' => array(
      0 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: medium.
  $styles['medium'] = array(
    'label' => 'Medium (220x220)',
    'effects' => array(
      0 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: news_sub_features.
  $styles['news_sub_features'] = array(
    'label' => 'news_sub_features',
    'effects' => array(),
  );

  // Exported image style: news_thumb.
  $styles['news_thumb'] = array(
    'label' => 'news_thumb',
    'effects' => array(),
  );

  // Exported image style: news_top_feature.
  $styles['news_top_feature'] = array(
    'label' => 'news_top_feature',
    'effects' => array(
      89 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1080,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_banner.
  $styles['page_banner'] = array(
    'label' => 'page_banner',
    'effects' => array(
      73 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2600,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: page_banner_large.
  $styles['page_banner_large'] = array(
    'label' => 'page_banner_large',
    'effects' => array(
      84 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: right_block_pub_cover.
  $styles['right_block_pub_cover'] = array(
    'label' => 'right_block_pub_cover',
    'effects' => array(),
  );

  // Exported image style: search_result_thumb.
  $styles['search_result_thumb'] = array(
    'label' => 'search_result_thumb',
    'effects' => array(
      75 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sector_icons.
  $styles['sector_icons'] = array(
    'label' => 'sector_icons',
    'effects' => array(
      82 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sector_page_banner.
  $styles['sector_page_banner'] = array(
    'label' => 'sector_page_banner',
    'effects' => array(
      88 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sector_side_image.
  $styles['sector_side_image'] = array(
    'label' => 'sector_side_image',
    'effects' => array(),
  );

  // Exported image style: special_deals_thumb.
  $styles['special_deals_thumb'] = array(
    'label' => 'special_deals_thumb',
    'effects' => array(
      77 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: testimonial_thumb.
  $styles['testimonial_thumb'] = array(
    'label' => 'testimonial_thumb',
    'effects' => array(
      87 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: thumbnail.
  $styles['thumbnail'] = array(
    'label' => 'Thumbnail (100x100)',
    'effects' => array(
      0 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

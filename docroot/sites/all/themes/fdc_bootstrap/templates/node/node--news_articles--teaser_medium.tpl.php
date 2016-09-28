<?php

$field_collection_id = key($content['field_collection_newsarticle'][0]['entity']['field_collection_item']);
$field_collection = &$content['field_collection_newsarticle'][0]['entity']['field_collection_item'][$field_collection_id];

hide($field_collection['field_news_image']);
hide($field_collection['field_news_heading']);
hide($content['field_press_release_pdf']);
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix node-view-mode-<?php print $view_mode;?>"<?php print $attributes; ?>>
  
  
  <div class="content"<?php print $content_attributes; ?>>
    <?php if (!empty($field_collection['field_news_image'][0]['#item']['uri'])) {
      $src = image_style_url('news_sub_features', $field_collection['field_news_image'][0]['#item']['uri']);
      $alt = $field_collection['field_news_image'][0]['#item']['alt'];
      $img_title = $field_collection['field_news_image'][0]['#item']['title'];
    ?>
    <a href="<?php print $node_url; ?>">
      <img class="img-responsive" src="<?php print $src; ?>" alt="<?php print $alt; ?>" title="<?php print $img_title; ?>" />
    </a>
    <?php } ?>
    <?php print render($field_collection['field_news_date']); ?>

    <h2<?php print $title_attributes; ?>>
      <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
    </h2>
    <?php 
      print render($content);
      
      if (!empty($field_press_release_pdf[0]['uri'])) {
    ?>
      <div class="extras">
        <p class="news_pdf_link">
          <a href="<?php print file_create_url($field_press_release_pdf[0]['uri']); ?>">
            <span class="glyphicon glyphicon-file" aria-hidden="true"></span>	Press Release 
          </a>
        </p>
      </div>
    <?php 
      }
    ?>
  </div>
</div>

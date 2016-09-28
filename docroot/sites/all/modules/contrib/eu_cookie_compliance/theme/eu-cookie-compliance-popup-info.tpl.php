<?php
/**
 * @file
 * This is a template file for a pop-up prompting user to give their consent for
 * the website to set cookies.
 *
 * When overriding this template it is important to note that jQuery will use
 * the following classes to assign actions to buttons:
 *
 * agree-button      - agree to setting cookies
 * find-more-button  - link to an information page
 *
 * Variables available:
 * - $message:  Contains the text that will be display whithin the pop-up
 * - $agree_button: Contains agree button title
 * - $disagree_button: Contains disagree button title
 */
?>
    <div class="wrapper_privacy_notice">
      <div class="privacy_notice">
        <div class="container">
          <div class="row">
            <div class="col-xs-12 col-sm-12 col-md-9 col-lg-9">
              <div id="popup-text">
                <?php print $message ?>
              </div>
            </div>
            <div class="col-xs-12 col-sm-12 col-md-3 col-lg-3">
              <div id="popup-buttons">
                <button type="button" class="agree-button"><?php print $agree_button; ?></button>
                <button type="button" class="find-more-button"><?php print $disagree_button; ?></button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>

<?php
    $content['product:sku']['#access'] = TRUE;
    hide($content['body']);
    hide($content['field_hh_youtube_video']);
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_gallery']);
    hide($content['field_product_video_extract']);
?>
<article<?php print $attributes; ?> class="node-product-type">
    <?php //krumo($content); ?>
    <?php print $user_picture; ?>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
        <header>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
        </header>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($display_submitted): ?>
        <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
    <?php endif; ?>
    <div class="row header-product">
        <div class="col-lg-12 col-sm-12 col-xs-12 col-md-12">
            <?php print render($content['product:title_field']); ?>
        </div>
        <div class="col-lg-12 col-sm-12 col-xs-12 col-md-12">
            <?php print render($content['field_product_collection']); ?>
            <?php print render($content['product:sku']); ?>
            <?php print render($content['field_product_category']); ?>
        </div>
    </div>
    <div class="row">

        <div class="col-lg-4 col-sm-4 col-xs-12 col-md-4">
            <div class="visuel">
                <?php print render($content['product:field_images']); ?>
                <?php print render($content['field_gallery']); ?>
            </div>
        </div>
        <div class="col-lg-4 col-sm-4 col-xs-12 col-md-4">

            <div class="informations">
                    <div id="toggle-informations" class="material-switch">
                        <span class="title-toggle"><?php print t('Show informations'); ?></span>
                        <input id="toggle-information" name="someSwitchOption001" type="checkbox"/>
                        <label for="toggle-information" class="label-primary"></label>
                    </div>
                <div id="informations-inside"  <?php print $content_attributes; ?>>
                    <?php print render($content['body']); ?>
                    <?php if (!empty($content['field_product_brochure'])): ?>
                        <?php print render($content['field_product_brochure']); ?>
                    <?php endif; ?>
                    <?php if (!empty($content['field_snack_infos'])): ?>
                        <?php print render($content['field_snack_infos']); ?>
                    <?php endif; ?>
                    <?php if (!empty($content['field_hh_youtube_video'])): ?>
                        <?php print render($content['field_hh_youtube_video']); ?>
                    <?php endif; ?>
                </div>
            </div>
        </div>
        <div class="col-lg-4 col-sm-4 col-xs-12 col-md-4">
            <div class="achats">
                <div<?php print $content_attributes; ?>>
                  <?php print render($content); ?>
                </div>
            </div>
        </div>
          <div class="col-lg-12 col-sm-12 col-xs-12 col-md-12">
            <?php print render($content['field_product_video_extract']); ?>
          </div>
    <?php if ($type == 'haqihana_harness' || $type == 'grossenbacher_harness'): ?>
        <div class="modal size-chart fade" tabindex="-1" role="dialog">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                        <h4 class="modal-title"><?php print t('Choose the right size'); ?></h4>
                    </div>
                    <div class="modal-body">
                      <h3 class="intro"><?php echo "Bien choisir son harnais, c'est important !<br /> Voici la méthode pour sélectionner la taille la plus adaptée."; ?></h3>
                      <img class="img-responsive" src="/sites/default/files/guide_tailles/mesure.png" />
                      <?php if ($type == 'haqihana_harness'): ?>
                        <img class="img-responsive" src="/sites/default/files/guide_tailles/taille_haqihana.png" />
                      <?php endif; ?>
                      <?php if ($type == 'grossenbacher_harness'): ?>
                        <img class="img-responsive" src="/sites/default/files/guide_tailles/taille_gb.png" />
                      <?php endif; ?>
                    </div>
                    </h3>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-primary" data-dismiss="modal"><?php print t('Thank you'); ?></button>
                        <a target="_blank" href="/contact" type="button" class="btn btn-default"><?php print t('Contact DolceVitaDog'); ?></a>
                    </div>
                </div>
            </div>
        </div>
        <?php endif; ?>
</article>

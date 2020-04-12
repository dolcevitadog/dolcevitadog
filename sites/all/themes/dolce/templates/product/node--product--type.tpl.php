<article<?php print $attributes; ?> class="node-product-type">
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
    <div class="col-lg-6 col-sm-6 col-xs-12 col-md-6">
        <?php print render($content['product:field_images']); ?>
        <?php print render($content['field_gallery']); ?>
        <?php if ($node->nid == 63): ?>
        <a data-toggle="modal" data-target="#myModal"><img class="easter" src="/sites/all/themes/dolce/images/egg3.png" width="30px" /></a>
        <div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                        <h4 class="modal-title" id="myModalLabel">Bravo vous avez trouvé le 1er oeuf ! </h4>
                    </div>
                    <div class="modal-body">
                        Votre récompense : Le code promo PAQUESR5EX vous permettra de bénéficier des frais de port offerts sur votre commande jusqu'au 14 avril 2020.
                        Deux autres oeufs offrent une plus grosse récompense ! Alors cherchez bien et ayez l'oeil.
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Fermer</button>
                    </div>
                </div>
            </div>
        </div>
        <?php endif; ?>
    </div>
    <div class="col-lg-6 col-sm-6 col-xs-12 col-md-6">
        <div<?php print $content_attributes; ?>>
            <?php
            // We hide the comments and links now so that we can render them later.
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_gallery']);
            print render($content);

            ?>
        </div>
    </div>
    <div class="col-lg-12 col-sm-12 col-xs-12 col-md-12 clearfix">
        <?php if (!empty($content['links'])): ?>
            <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
        <?php endif; ?>
        <?php
        print render($content['comments']);
        ?>
    </div>
</article>

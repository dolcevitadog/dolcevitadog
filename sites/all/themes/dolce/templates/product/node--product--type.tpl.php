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

<div id="dolce-user-links-inside">
    <?php foreach ($data as $key => $array): ?>
        <div class="dolce-user-links-inside-item col-xs-12 col-lg-4 col-sm-4 col-md-4">
            <div class="dolce-user-links-inside-link-wrapper col-xs-12 col-md-12 col-lg-12 col-sm-12">
                <a href="<?php print $array['link'];?>" class="<?php print $array['class']; ?>" >
                        <span class="dolce-user-links-inside-icon">
                            <i class="<?php print $array['icon'];?>"></i>
                        </span>
                        <span class="dolce-user-links-inside-title"><?php print $array['text'];?></span>
                </a>
            </div>
        </div>
    <?php endforeach; ?>
</div>

<div id="dolce-checkout" class="modal fade" tabindex="-1" role="dialog">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                <h4 class="modal-title"><?php print $content['title']; ?></h4>
            </div>
            <div class="modal-body">
                <?php print $content['product']; ?>
            </div>
            <div class="modal-footer">
                <a href="<?php print $content['path_product']; ?>" type="button" class="btn btn-primary"><?php print t("Ca m'interesse !"); ?></a>
                <button type="button" class="btn btn-default" data-dismiss="modal"><?php print t('Non merci'); ?></button>
            </div>
        </div><!-- /.modal-content -->
    </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
<?php if ($data['day'] == 20): ?>
  <div id="block-enig-paw">
    <div class="row dolce-enig-paw-wrapper">
      <div class="col-lg-3 col-sm-3 col-xs-3 col-md-3">
        <i class="fas fa-paw fa-4x one"></i>
      </div>
      <div class="col-lg-3 col-sm-3 col-xs-3 col-md-3">
        <i class="fas fa-paw fa-4x two"></i>
      </div>
      <div class="col-lg-3 col-sm-3 col-xs-3 col-md-3">
        <i class="fas fa-paw fa-4x three"></i>
      </div>
      <div class="col-lg-3 col-sm-3 col-xs-3 col-md-3">
        <i class="clue fas fa-paw fa-4x four"></i>
      </div>
    </div>
    <div class="clue-modal modal fade" tabindex="-1" role="dialog">
      <div class="modal-dialog" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title"><?php echo t('Well done ! You have found a clue !'); ?></h4>
          </div>
          <div class="modal-body">
            <?php print $data['imgClue']; ?>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal"><?php print t('Close'); ?></button>
          </div>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>

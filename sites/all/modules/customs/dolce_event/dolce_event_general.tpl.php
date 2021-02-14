  <?php global $user; ?>

  <div id="event">
    <div class="banner">
      <?php print $data['banner']; ?>
    </div>
    <?php if ($data['trailer_mode'] == 1 && $user->uid != 1): ?>
      <div id="video">
        <div class="video-responsive">
          <div id="vid-sdk">
          </div>
        </div>
        <div id="controls">
        <div id="fr-caption"><i class="fas fa-4x fa-closed-captioning"></i></div>
        <div id="no-caption"><i class="fas fa-4x fa-closed-captioning"></i></div>
          <div id="mute"><i class="fas fa-4x fa-volume-up"></i></div>
          <div id="unmute"><i class="fas fa-4x fa-volume-mute"></i></div>
        </div>
      </div>
    <?php else: ?>
      <?php if ($data['video']): ?>
        <div id="video">
          <div class="video-responsive">
            <div id="vid-sdk"></div>
          </div>
          <div id="controls">
          <div id="fr-caption"><i class="fas fa-4x fa-closed-captioning"></i></div>
          <div id="no-caption"><i class="fas fa-4x fa-closed-captioning"></i></div>
            <div id="mute"><i class="fas fa-4x fa-volume-mute"></i></div>
            <div id="unmute"><i class="fas fa-4x fa-volume-up"></i></div>
          </div>
       </div>
        <?php else: ?>
          <div id="no-video"><?php print $data['no_video']; ?></div>
      <?php endif; ?>
      <?php if($data['qa']): ?>
        <div class="qa-wrapper">
          <h2>
            <?php print t('Questions'); ?>
            <i class="far fa-question-circle"></i>
          </h2>
          <div class="qa-session">
            <div class="qa">
              <?php print render($data['qa']); ?>
            </div>
          </div>
        </div>
      <?php endif; ?>
      <?php if($data['zoom']): ?>
        <div class="zoom-wrapper">
          <h2>
            <?php print t('Public Room'); ?>
            <i class="fas fa-video"></i>
            <i class="fas fa-users"></i>
          </h2>
          <div class="zoom">
            <?php print t('Zoom link to access the public room : '); ?>
            <?php print $data['zoom']; ?>
          </div>
        </div>
      <?php endif; ?>
      <?php if($data['shoutbox']): ?>
        <div class="shoutbox-wrapper">
          <h2>
            <?php print t('Tchat'); ?>
            <i class="far fa-comments"></i>
          </h2>
          <div class="shoutbox">
            <?php print render($data['shoutbox']); ?>
          </div>
        </div>
      <?php endif; ?>
      <?php if ($data['game_is_on']): ?>
        <?php if($data['game']): ?>
          <div class="dolce-enigma-wrapper">
            <h2>
              <?php print t('The Game'); ?>
              <i class="fas fa-trophy"></i>
            </h2>
            <div class="dolce-enigma">
              <?php print render($data['game']); ?>
            </div>
          </div>
        <?php endif; ?>
        <?php if($data['enig_paw']): ?>
          <?php print render($data['enig_paw']); ?>
        <?php endif; ?>
      <?php endif; ?>
    <?php endif; ?>
  </div>

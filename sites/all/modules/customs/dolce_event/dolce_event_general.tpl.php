<?php //krumo($data);
?>
<div id="event">
  <div class="banner">
    <?php print $data['banner']; ?>
  </div>
  <?php if ($data['trailer_mode'] == 1): ?>
    <div class="video-responsive">
      <div class="player">
        <iframe src="https://player.vimeo.com/video/509011349" width="640" height="480" frameborder="0" allow="autoplay; fullscreen; picture-in-picture" allowfullscreen></iframe>
      </div>
    </div>
  <?php else: ?>
    <div class="video-responsive">
      <div class="player">
        <?php print $data['player']; ?>
      </div>
    </div>
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
  <?php endif; ?>
</div>

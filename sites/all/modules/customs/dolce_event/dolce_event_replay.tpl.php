<?php global $user; global $language;
?>
<div class="change-language">
  <?php print $data['change_language']; ?>
</div>
<div id="event">
  <div class="banner">
    <?php print $data['banner']; ?>
  </div>
  <?php if ($data['replay']): ?>
    <?php if ($data['videos']): ?>
      <div id="video">
        <?php foreach ($data['videos'] as $index => $video): ?>
          <?php $day = preg_replace('/[^0-9]/', '', $index); ?>
          <div class="row">
            <h2><?php print t('Day : '). $day; ?></h2>
            <?php foreach ($video as $num => $portion): ?>
              <div class="margin10-col col-lg-6 col-md-6 col-sm-6 col-xs-12">
                <div class="video-responsive">
                  <div id="vid-<?php print $portion['vid']; ?>"></div>
                </div>
              </div>
            <?php endforeach; ?>
          </div>
        <?php endforeach; ?>

      </div>
    <?php endif; ?>
  <?php else: ?>
    <h2><?php print t('Replay is over, thanks for watching the seminar'); ?></h2>
  <?php endif; ?>
  <div id="promotionnal">
    <div class="row">
      <?php foreach ($data['video_promo'] as $promo): ?>
        <div class="margin10-col col-lg-6 col-md-6 col-sm-6 col-xs-12">
          <div class="video-responsive">
            <div id="<?php print $promo['id']; ?>"></div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
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
  <div class="center-block dolce-book-wrapper">
    <h2>
      <?php print t('Audio sample'); ?>
      <i class="far fa-file-audio"></i>
    </h2>
    <div>
      <div class="dolce-book-description">
        <a target="_blank" href="/<?php print $data['book']['link']; ?>"><img class="img-responsive" src="https://www.dolcevitadog.com/sites/dolcevitadog.dd/files/styles/catalog/public/aboiement1_0.png?itok=fJ2YhmKF" /></a>
      </div>
      <div class="dolce-book-sample">
        <figure>
          <figcaption><?php print t("Turid Rugaas - L'aboiement, le son d'un langage"); ?></figcaption>
          <audio
          controls>
          <source src="/<?php print $data['book']['sample'].'.mp3' ?>">
            <source src="/<?php print $data['book']['sample'].'.ogg' ?>">
              Your browser does not support the
              <code>audio</code> element.
            </audio>
          </figure>
        </div>
      </div>
    </div>
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
    <div class="partners-wrapper">
      <h2>
        <?php print t('They are partners, what about you ?'); ?>
        <i class="far fa-handshake"></i>
      </h2>
      <div class="partners">
        <?php print $data['partners']; ?>
      </div>
    </div>
  </div>

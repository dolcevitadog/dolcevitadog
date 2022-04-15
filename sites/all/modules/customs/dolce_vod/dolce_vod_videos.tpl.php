<div id="dolce-vod">
  <div id="dolce-vod-videos">
    <div id="vod_by_user" class="view">
      <?php if (isset($data['empty'])): ?>
        <h3><?php print $data['empty']; ?></h3>
      <?php else: ?>
        <ul>
        <?php foreach ($data['entities'] as $pid => $entity): ?>
          <li class="<?php print $data['col']; ?>">
            <div class="vod-video-wrapper col-lg-12 col-sm-12 col-xs-12 col-md-12">
              <img src="<?php print $entity['image']; ?>">
              <div class="field-name-title-field"><?php print $entity['link']; ?></div>
            </div>
          </li>
        <?php endforeach; ?>
        </ul>
      <?php endif; ?>
      </div>
  </div>
</div>

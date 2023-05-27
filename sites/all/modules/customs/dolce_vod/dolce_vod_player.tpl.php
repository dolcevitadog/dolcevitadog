<div id="dolce-vod">
  <div id="dolce-vod-player">
    <?php foreach ($data['vimeo_ids'] as $key => $vimeo_id): ?>
    <div style="padding:56.25% 0 0 0;position:relative;">

        <iframe src="https://player.vimeo.com/video/<?php print $vimeo_id['value']; ?>?h=759a52d2a5&amp;badge=0&amp;autopause=0&amp;player_id=<?php print $key; ?>&amp;app_id=58479" frameborder="0" allow="autoplay; fullscreen; picture-in-picture" allowfullscreen style="position:absolute;top:0;left:0;width:100%;height:100%;"></iframe>

    </div>
    <?php endforeach; ?>
    <script src="https://player.vimeo.com/api/player.js"></script>
  </div>
</div>
<?php endif; ?>

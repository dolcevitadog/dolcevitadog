<div class="avent">
    <div class="col-lg-3 col-md-3 col-xs-12">
      <a href="<?php print $base_url; ?>" target="_blank">
        <img class="papanoel" width="250px" src="<?php print $papanoel_url; ?>" />
      </a>
    </div>
    <div class="col-lg-9 col-md-9 col-xs-12 avent-text">
      <h1>
        Le Calendrier de l'Avent
      </h1>
      <div class="intro">
      Chaque jour, une surprise !
      </div>
    </div>

  <?php if ($actif): ?>
  <ul class="noel">
    <?php foreach ($all as $k => $data): ?>
      <?php if (!empty($data['link'])): ?>
        <a href="<?php echo $data['link']; ?>" target="_blank">
      <?php endif; ?>
      <li class="<?php echo $data['class']; ?>">
          <span class="jour"><?php echo $k; ?></span>
          <?php if ($data['past']): ?>
            <img class="past" src="<?php echo $data['past']; ?>" />
          <?php endif; ?>
      </li>
    <?php if (!empty($data['link'])): ?>
    </a>
    <?php endif; ?>
    <?php endforeach; ?>
  </ul>
  <?php else: ?>
    <h2>
      Encore un peu de patience ... 
  </h2>
  <?php endif; ?>
  <img class="" src="<?php print $logo; ?>" />
</div>
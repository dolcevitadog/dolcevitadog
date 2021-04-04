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
  <a data-toggle="modal" data-target="#myModal"><img class="easter" src="/sites/all/themes/dolce/images/egg4.png" width="30px" /></a>
    <div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
      <div class="modal-dialog" role="document">
        <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title" id="myModalLabel">Bravo vous avez trouvé un oeuf ! </h4>
          </div>
          <div class="modal-body">
            Votre récompense : Le code promo PAQUES10BX vous permettra de bénéficier de 10% de réduction sur votre commande totale.
            ! Continuez à chercher les oeufs et ayez l'oeil.
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-default" data-dismiss="modal">Fermer</button>
          </div>
        </div>
      </div>
    </div>
</div>

<div id="relai-info">
    <?php if (is_array($variables)): ?>
      <?php print t('Vous avez sélectionné le relais colis suivant : '); ?>
      <div class="relais-name"><?php print $variables['Nom']; ?></div> (#<span class="relais-number"><?php print $variables['ID']; ?></span>)
      <div class="relais-addr1"><?php print $variables['Adresse1']; ?></div>
      <div class="relais-addr2"><?php print $variables['Adresse2']; ?></div>
      <div class="relais-addr3"><?php print $variables['Adresse3']; ?></div>
      <div class="relais-addr4"><?php print $variables['Adresse4']; ?></div>
      <div class="relais-cp"><?php print $variables['Cp']; ?></div>
      <div class="relais-ville"><?php print $variables['Ville']; ?></div>
      <div class="relais-pays"><?php print $variables['Pays']; ?></div>
      <button type="button" class="btn btn-primary" data-toggle="modal" data-target="#horairesrelais">
        Voir les horaires
      </button>
      <!-- Modal -->
      <div class="modal fade" id="horairesrelais" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
        <div class="modal-dialog" role="document">
          <div class="modal-content">
            <div class="modal-header">
              <h5 class="modal-title" id="exampleModalLabel">Les horaires de mon Point Relais</h5>
              <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                <span aria-hidden="true">&times;</span>
              </button>
            </div>
            <div class="modal-body">
              <div class="relais-horraires"><?php print $variables['HoursHtmlTable']; ?></div>
            </div>
            <div class="modal-footer">
              <button type="button" class="btn btn-secondary" data-dismiss="modal"><?php print t('Close'); ?></button>
            </div>
          </div>
        </div>
      </div>
  <?php else: ?>
    <div class="relais-erreur"><?php print $variables['text']; ?></div>
  <?php endif; ?>
</div>

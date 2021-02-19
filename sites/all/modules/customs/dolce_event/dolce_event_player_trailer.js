  (function ($) {
    $(document).ready(function() {
      //Variable Declaration
      var schedule = Drupal.settings.dolce_event.schedule;
      var video = Drupal.settings.dolce_event;
      var video_promo = Drupal.settings.dolce_event.video_promo;
      //Vimeo SDK Options
      var options = {
       width: '1024px',
       id: video.video.vid,
       url: video.video.link,
       muted: true,
       autopause: false,
     }
      //Initialisation of player
      var player = new Vimeo.Player('vid-sdk', options);

      //Get subtitles and hide the other buttons
      player.getTextTracks().then(function(tracks) {
        $(tracks).each(function(index, track) {
          if (track.language == 'fr' && track.mode == 'showing') {
            $('#no-caption').hide();
            $('#fr-caption').show();
          }
          else {
            $('#fr-caption').hide();
            $('#no-caption').show();
          }
        });
      });
      // Behaviours when subtitles buttons are clicked
      $('#no-caption').on('click', function(){
        $(this).hide();
          player.enableTextTrack('fr', 'subtitles').then(function(track) {
        });
        $('#fr-caption').show();
      });
      $('#fr-caption').on('click', function(){
        $(this).hide();
        player.disableTextTrack().then(function() {
        });
        $('#no-caption').show();
      });
      // Behaviours when mute/unmute buttons are clicked
      $('#unmute').hide();
      $('#mute').on('click', function() {
          player.setMuted(false);
          $(this).hide();
          $('#unmute').show();
      });
      $('#unmute').on('click', function() {
          player.setMuted(true);
          $(this).hide();
          $('#mute').show();
      });
      $(video_promo).each(function(index, promo) {
        var optionsPromo = {
         //id: video.video.vid,
         url: promo.link,
         width: '100%',
         responsive: true,
         controls: true,
         fullscrenn: false,
         autopause: false,
       }
        var promoPlayer = new Vimeo.Player(promo.id, optionsPromo);
      });
    });
  })(jQuery);

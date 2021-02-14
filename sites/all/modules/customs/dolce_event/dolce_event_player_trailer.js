  (function ($) {
    $(document).ready(function() {
      //Variable Declaration
      var schedule = Drupal.settings.dolce_event.schedule;
      var video = Drupal.settings.dolce_event;
      //Vimeo SDK Options
      var options = {
       width: '1024px',
       id: video.video.vid,
       url: video.video.link,
     }
      //Initialisation of player
      var player = new Vimeo.Player('vid-sdk', options);
      player.ready().then(function() {
        player.getVolume().then(function(volume) {
          if (volume > 0) {
            $('#mute').hide();
          }
          else {
            console.log('muted');
            $('#unmute').hide();
          }
        });
      });

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
    });
  })(jQuery);

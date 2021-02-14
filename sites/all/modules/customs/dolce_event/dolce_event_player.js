  (function ($) {
    $(document).ready(function() {
      //Variable Declaration
      var schedule = Drupal.settings.dolce_event.schedule;
      var video = Drupal.settings.dolce_event;
      //Vimeo SDK Options
      var options = {
       //id: video.video.vid,
       url: video.video.link,
       width: '1024px',
       controls: false,
       muted: true,
       autoplay: true,
     }
      //Initialisation of player
      var player = new Vimeo.Player('vid-sdk', options);
      $('#unmute').hide();
      //Player is ready, sync of the video and play
      player.ready().then(function() {
        setSyncVideo(schedule);
        player.play();
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
      //Video is muted at start, need to hide the muted button


      //Reload the page when the video is ending
      player.on('ended', function(data) {
        document.location.reload();
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
      //Important function for synchronise video in real time
      function setSyncVideo (schedule) {
        $.ajax({
          url : '/event/ajax/get_time/'+schedule.hour+'/'+schedule.min, // La ressource ciblée
          type : 'POST', // Le type de la requête HTTP.
          success : function(response, statut){ // success est toujours en place, bien sûr !
            if (response > 0) {
              player.getDuration().then(function(duration) {
                if (response <= duration) {
                  player.setCurrentTime(response);
                }
                else {
                  //player.setCurrentTime(duration-0.5);
                }
              });
            }
          },
        });
      }
    });
  })(jQuery);

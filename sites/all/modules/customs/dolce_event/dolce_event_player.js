(function ($) {
  $(document).ready(function() {
    var iframe = document.querySelector('iframe');
    var player = new Vimeo.Player(iframe);
    player.on('ended', function(data) {
      document.location.reload();
    });
    var schedule = Drupal.settings.dolce_event.schedule;
    player.on('play', function(data) {
      setSyncVideo(schedule);
    });


    player.on('pause', function(data) {
      player.play();
    });
    $(".interract").on('click',
    function() {
      setSyncVideo(schedule);
      player.play();
      player.setMuted(false);
      player.setVolume(0.8);
      $("[data-vimeo=unmute]").remove();
      var interval = setInterval(function () {
          eraseBlue();
      }, 2000);


    });

    function eraseBlue() {
      $("#overlay").remove();
    }
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

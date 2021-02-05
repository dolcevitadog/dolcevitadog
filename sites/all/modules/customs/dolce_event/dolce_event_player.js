(function ($) {
  $(document).ready(function() {
    var iframe = document.querySelector('iframe');
    var player = new Vimeo.Player(iframe);
    $(iframe).hide()
    player.on('ended', function(data) {
      document.location.reload();
    });
    var schedule = Drupal.settings.dolce_event.schedule;
    player.on('play', function(data) {
      $.ajax({
        url : '/event/ajax/get_time/'+schedule.hour+'/'+schedule.min, // La ressource ciblée
        type : 'POST', // Le type de la requête HTTP.
        success : function(response, statut){ // success est toujours en place, bien sûr !
          if (response > 0) {
            player.getDuration().then(function(duration) {
              if (response <= duration) {
                player.setCurrentTime(response);
                setTimeout(function() {
                  $(iframe).show();
                }, 3000);
              }
              else {
                //player.setCurrentTime(duration-0.5);
              }
            });
          }
        },
      });
    });
    player.on('pause', function(data) {
      player.play();
    });
    $("[data-vimeo=unmute]").on('click',
    function() {
      player.setMuted(false);
      player.setVolume(0.8);
      $("[data-vimeo=unmute]").remove();
    });

  });
})(jQuery);

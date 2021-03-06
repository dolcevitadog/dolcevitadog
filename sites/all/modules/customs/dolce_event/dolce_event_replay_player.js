(function ($) {
  $(document).ready(function() {
    //Variable Declaration
    $(document).ready(function() {
      $('.clue-modal').modal();
    });

    $('.clue-modal').on('show.bs.modal', function (event) {
      $('#accept').on('click', function(){
        $(this).modal('hide');
      });
      $('#reject').on('click', function(){
        window.location.href = 'https://www.dolcevitadog.com';
      });
      $('.close').on('click', function(){
        window.location.href = 'https://www.dolcevitadog.com';
      });
    });
    var videos = Drupal.settings.dolce_event.videos;
    var replay = Drupal.settings.dolce_event.replay;
    var video_20 = Drupal.settings.dolce_event.videos.day_20;
    var video_21 = Drupal.settings.dolce_event.videos.day_21;
    var video_promo = Drupal.settings.dolce_event.video_promo;
    //Vimeo SDK Options
    if (replay == 1) {
      $(video_20).each(function(index, video) {
        var options = {
          width: '100%',
          id: video.vid,
          responsive: true,
          controls: true,
          fullscreen: true,
          autopause: false,
        }
        var Player = new Vimeo.Player(video.id, options);
      });
      $(video_21).each(function(index, video) {
        var options = {
          width: '100%',
          id: video.vid,
          responsive: true,
          controls: true,
          fullscreen: true,
          autopause: false,
        }
        var Player2 = new Vimeo.Player(video.id, options);
      });
    }

    $(video_promo).each(function(index, promo) {
      var optionsPromo = {
        //id: video.video.vid,
        url: promo.link,
        width: '100%',
        responsive: true,
        controls: true,
        fullscreen: false,
        autopause: false,
      }
      var promoPlayer = new Vimeo.Player(promo.id, optionsPromo);
    });
  });
})(jQuery);

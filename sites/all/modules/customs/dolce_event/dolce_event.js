(function ($) {
  $(document).ready(function() {
    /*
    function reloadNewVideo () {
      $.ajax({
        url : '/event/ajax/is_time', // La ressource ciblée
        type : 'POST', // Le type de la requête HTTP.
        success : function(response, statut){ // success est toujours en place, bien sûr !
          if (response == 1) {
            document.location.reload();
          }
        }
      });
    }
    */

    function checkSessionLimit () {
      $.ajax({
        url : '/ejectorseat/check', // La ressource ciblée
        type : 'POST', // Le type de la requête HTTP.
        success : function(response, statut){ // success est toujours en place, bien sûr !
          //console.log(response);
          if (response == '0') {
            document.location.reload();
          }
        }
      });
    }

    var interval = setInterval(function () {

      if ( $( "#player-empty" ).length ) {
        reloadNewVideo();
      }
      //checkSessionLimit();
    }, 10000);

    $(document).bind("contextmenu",function() {
      return false;
    });
    $('iframe').bind("contextmenu",function() {
      return false;
    });
  });
})(jQuery);

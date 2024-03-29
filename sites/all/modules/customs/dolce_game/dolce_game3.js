
(function ($) {

    $( document ).ready(function() {

        var dolce_game = Drupal.settings.dolce_game;
        var obj = jQuery.parseJSON(dolce_game);

        $.getScript('//connect.facebook.net/fr_FR/sdk.js', function(){
            FB.init({
                appId: '837855276384036', //replace with your app ID
                version: 'v3.3'
            });
        });

        var facebookShare = function( callback ) {

                var options = {
                    method : 'share',
                    href   : 'https://www.dolcevitadog.com/jeu-concours-halloween'
                },
            status = '';

        FB.ui(options, function( response ){

            if (response && !response.error_code) {
                status = 'success';
                $.get( 'dolce-game/'+obj.id+'/'+obj.ip, function( data ) {
                    alert(data);
                });
                $.event.trigger('fb-share.success');

            } else {
                status = 'error';
                $.event.trigger('fb-share.error');
                alert('Vous devez partager pour valider le vote.')
            }

            if(callback && typeof callback === "function") {
                callback.call(this, status);
            } else {
                return response;
            }
        });
        }

        $('.fb-share').on('click', function( e ) {
                e.preventDefault();

                facebookShare(function( response ) {
                    // simple function callback
                });
        });


    });

    $(document)
        .on('fb-share.success', function( e ) {
        })
        .on('fb-share.error', function( e ) {
        });

})(jQuery);
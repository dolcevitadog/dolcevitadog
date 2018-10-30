
(function ($) {

    $( document ).ready(function() {

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
            status = 'Encore plus de chance de gagner sur le Jeu Concours DolceVitaDog';

        FB.ui(options, function( response ){

            if (response && !response.error_code) {
                status = 'success';
                $.event.trigger('fb-share.success');

            } else {
                status = 'error';
                $.event.trigger('fb-share.error');
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

        var ids = Drupal.settings.dolce_game;
    });



    $(document)
        .on('fb-share.success', function( e ) {
            var ids = Drupal.settings.dolce_game;
            $.get( 'dolce-game/'+ids.id+'/'+ids.ip, function( data ) {
                if (data == true) {
                    alert('Merci pour votre partage, votre participation compte désormais double.');
                }

            });
        })
        .on('fb-share.error', function( e ) {
            alert('Un probleme est apparru');

        });

})(jQuery);
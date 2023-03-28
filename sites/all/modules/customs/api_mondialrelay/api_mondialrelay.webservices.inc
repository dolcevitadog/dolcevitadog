<?php

function api_mondialrelay_callws($data, $action) {
  $url = variable_get('api_mondialrelay_url');
  $client = new SoapClient($url."?WSDL");
  $client->soap_defencoding = 'UTF-8';
  $client->decode_utf8 = false;
  $result = $client->{$action}($data);
  return $result;
}

function api_mondialrelay_create_object_expedition($expedition) {
  if (variable_get('api_mondialrelay_status') == 'sandbox') {
    $enseigne = 'BDTEST13';
    $clef = 'PrivateK';
  }
  else {
    $enseigne = variable_get('api_mondialrelay_code_enseigne');
    $clef = variable_get('api_mondialrelay_cle_prive');
  }
  $langue = 'FR';
  $hash = api_mondialrelay_security_hash($enseigne, $expedition, $langue, $clef);

  return array(
    'Enseigne' => $enseigne,
    'Langue' => 'FR',
    'Expedition' => $expedition,
    'Security' => $hash,
  );
}

function api_mondialrelay_create_object_relai($relaiId) {
  if (variable_get('api_mondialrelay_status') == 'sandbox') {
    $enseigne = 'BDTEST13';
    $clef = 'PrivateK';
  }
  else {
    $enseigne = variable_get('api_mondialrelay_code_enseigne');
    $clef = variable_get('api_mondialrelay_cle_prive');
  }
  $pays = 'BE';
  $hash = api_mondialrelay_security_hash($enseigne, $relaiId, $pays, $clef);

  return array(
    'Enseigne' => $enseigne,
    'Pays' => 'BE',
    'Num' => $relaiId,
    'Security' => $hash,
  );
}

function api_mondialrelay_get_expedition_relaiId($response) {
  if (isset($response->WSI2_TracingColisDetailleResult->Relais_Num)) {
    return $response->WSI2_TracingColisDetailleResult->Relais_Num;
  }
  return false;
}


/* Generation de la clef de securité pour l'appel WS */
function api_mondialrelay_security_hash($enseigne, $expedition, $langue, $clef) {
  $string = $enseigne.$expedition.$langue.$clef;
  $hash = strtoupper(md5($string));
  return $hash;
}


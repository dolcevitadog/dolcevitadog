<?php

#Permet de subvenir a un bug de Commerce et Entity Translation, il faut recuperer le nid et le pid pour créer
#un display_path_valide;
$data = $row->_field_data['commerce_line_item_field_data_commerce_line_items_line_item_']['entity'];
$entity_id = $data->data['context']['entity']['entity_id'];
$type = $data->data['context']['entity']['entity_type'];
$product_id = $data->commerce_product['und']['0']['product_id'];
$text = t('View product');
$url = $type.'/'.$entity_id;
?>
<?php print $output; ?>
<?php print l($text, $url, array('query' => array('id' => $product_id))); ?>
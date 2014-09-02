<?php

/**
 * Define my custom in_opeator
 */
class dc_in_operator extends views_handler_filter_in_operator {
  // overwrite the get_value_options function.
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }
    $this->value_options array(
    'C1241' => t('C1241 - PDF'), 
    'C1244' => t('C1244 - PDF'), 
    'C1245' => t('C1244 - PDF'), 
    'C1262' => t('C1244 - PDF'), 
    'C1278 Unit 1' => t('C1278-1 - PDF'),
    'C1278 Unit 2' => t('C1278 - PDF'),
    'C1278 Unit 3' => t('C1278-3 - PDF'),
    'C1310' => t('C1310 - PDF'),
    'C1316' => t('C1316 - PDF'),
    'C1319' => t('C1319 - PDF'),
    'C1325' => t('C1325 - PDF'),
    'C1330' => t('C1330 - PDF'),
    'C1361' => t('C1361 - PDF')
    );
  }
}
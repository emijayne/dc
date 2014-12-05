<?php
/**
 * @file
 * DateTime Conversion from SQL into UNIX.
 *
 * Converts the DATETIME from the database into unixtime then allows
 * views_handler_field_date to render as usual.
 * Also tricks php into thinking the time is in the same timezone, no
 * matter the default timezone.
 */

 class dc_handler_field_datetime extends views_handler_field_date {

  function render($values) {
    $value = $values->{$this->field_alias};

    if (is_string($value)) {
      $value = strtotime($value);

      if ($value) {
        $values->{$this->field_alias} = $value;
      }
    }

    return parent::render($values);
  }
}

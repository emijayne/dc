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


/*
 * All the comparisons need to be done with SQL DATETIMES and not unixtime
 */
class dc_handler_filter_date extends views_handler_filter_date {

  /*
     * We use strtotime() to accept a wide range of date inputs and then
     * convert the unixtime back to SQL DATETIME before adding the WHERE clause
     */
  function op_simple($field) {
    $value = intval(strtotime($this->value['value'], 0));

    if (!empty($this->value['type']) && $this->value['type'] == 'offset') {
      // keep sign
      $value = time() + sprintf('%+d', $value);
    }

    $value = $this->format_date($value);

    $this->query->add_where($this->options['group'], $field, $value, $this->operator);
  }

  function op_between($field) {
    if ($this->operator == 'between') {
      $a = intval(strtotime($this->value['min'], 0));
      $b = intval(strtotime($this->value['max'], 0));
    }
    else {
      $a = intval(strtotime($this->value['max'], 0));
      $b = intval(strtotime($this->value['min'], 0));

      $this->query->set_where_group('OR', $this->options['group']);
    }

    if ($this->value['type'] == 'offset') {
      $now = time();
      // keep sign
      $a = $now + sprintf('%+d', $a);
      // keep sign
      $b = $now + sprintf('%+d', $b);
    }

    $a = $this->format_date($a);
    $b = $this->format_date($b);

    // %s is safe here because strtotime + format_date scrubbed the input
    $this->query->add_where($this->options['group'], $field, $a, '>=');
    $this->query->add_where($this->options['group'], $field, $b, '<=');
  }

  function format_date($unixtime) {
    return date("Ymd", $unixtime);
  }
}

/*
 * All the comparisons need to be done with SQL DATETIMES and not unixtime
 */
class dc_handler_filter_datetime extends views_handler_filter_date {

  /*
     * We use strtotime() to accept a wide range of date inputs and then
     * convert the unixtime back to SQL DATETIME before adding the WHERE clause
     */
  function op_simple($field) {
    $value = intval(strtotime($this->value['value'], 0));

    if (!empty($this->value['type']) && $this->value['type'] == 'offset') {
      // keep sign
      $value = time() + sprintf('%+d', $value);
    }

    $value = $this->format_datetime($value);

    $this->query->add_where($this->options['group'], $field, $value, $this->operator);
  }

  function op_between($field) {
    if ($this->operator == 'between') {
      $a = intval(strtotime($this->value['min'], 0));
      $b = intval(strtotime($this->value['max'], 0));
    }
    else {
      $a = intval(strtotime($this->value['max'], 0));
      $b = intval(strtotime($this->value['min'], 0));

      $this->query->set_where_group('OR', $this->options['group']);
    }

    if ($this->value['type'] == 'offset') {
      $now = time();
      // keep sign
      $a = $now + sprintf('%+d', $a);
      // keep sign
      $b = $now + sprintf('%+d', $b);
    }

    $a = $this->format_datetime($a);
    $b = $this->format_datetime($b);

    // %s is safe here because strtotime + format_datetime scrubbed the input
    $this->query->add_where($this->options['group'], $field, $a, '>=');
    $this->query->add_where($this->options['group'], $field, $b, '<=');
  }

  function format_datetime($unixtime) {
    return date("YYMMDDHHIISS", $unixtime);
  }
}

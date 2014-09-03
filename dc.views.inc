<?php

/**
 * @file
 * Provide views data and handlers for dc.module.
 *
 * Table models of the Adept and MDMDB databases. These are used to create 
 * reports for the Document Control & Engineering departments. Certain tables 
 * were altered and changed into saved queries (views) in the server itself. 
 * Those saved views are named after their content.
 * 
 * Adept table descriptions by the software owner, Synergis, has been added to 
 * a spreadsheet inside this module folder.
 */

/**
 * Implements hook_views_data().
 */
function dc_views_data() { 

  // Adept Tables.

  // ----------------------------------------------------------------
  // fm90comp - Basic Info
  
  $data['fm90comp']['table']['group'] = t('DC: Companies');

  // Advertise as possible base table
  $data['fm90comp']['table']['base'] = array(
    'field' => 'S_COMPID',
    'title' => t('DC: Companies'),
    'database' => 'adept90', 
    'weight' => -10,
  );
  $data['fm90comp']['table']['join'] = array(
    'Transmittals' => array(
      'left_field' => 'S_COMPID',
      'field' => 'S_COMPID',
    ),
  );
  
  // fm90comp - Fields
  
  $data['fm90comp']['S_COMPID'] = array(
    'title' => t('Company GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Transmittals', // The name of the table to join with.
      'base field' => 'S_COMPID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Transmittals Sent to Company'),
      'title' => t('Relationship with Transmittal table.'),
      'help' => t(' '),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_COMPNAME'] = array(
    'title' => t('Company Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_ADDRESS1'] = array(
    'title' => t('Street Address'),
    'help' => t('Line 1'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_ADDRESS2'] = array(
    'title' => t('Street Address'),
    'help' => t('Line 2'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_CITY'] = array(
    'title' => t('City'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_STATE'] = array(
    'title' => t('State'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_ZIPCODE'] = array(
    'title' => t('Postal Code'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90comp']['S_WEBADDR'] = array(
    'title' => t('Website'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end FM90COMP */

  // ----------------------------------------------------------------
  // fm90cont - Basic Info
  
  $data['fm90cont']['table']['group'] = t('DC: Contacts');

  // Advertise as possible base table
  $data['fm90cont']['table']['base'] = array(
    'field' => 'S_CONTID',
    'title' => t('DC: Contacts'),   // same as group above
    'database' => 'adept90',
    'weight' => -10,
  );
  $data['fm90cont']['table']['join'] = array(
    'fm90comp' => array(
      'left_field' => 'S_COMPID',
      'field' => 'S_COMPID',
    ),
    'Transmittals' => array(
      'left_field' => 'S_CONTID',
      'field' => 'S_CONTID',
    ),
  );
  
  // fm90cont - Fields
  
  $data['fm90cont']['S_CONTID'] = array(
    'title' => t('Contact GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Transmittals', // The name of the table to join with.
      'base field' => 'S_CONTID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Transmittals sent to Contact'),
      'title' => t('Relationship with Transmittal table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_COMPID'] = array(
    'title' => t('Company GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'fm90comp', // The name of the table to join with.
      'base field' => 'S_COMPID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Company for Contact'),
      'title' => t('Relationship with Company table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_CONTNAME'] = array(
    'title' => t('Contact Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_EMAIL'] = array(
    'title' => t('Email'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_PHONE'] = array(
    'title' => t('Phone'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_FAX'] = array(
    'title' => t('Fax'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90cont']['S_EXT'] = array(
    'title' => t('Extension'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end FM90CONT */

  // ----------------------------------------------------------------
  // fm90distri - Basic Info
  
  $data['fm90distri']['table']['group'] = t('DC: Distribution Members');

  // Advertise as possible base table
  $data['fm90distri']['table']['base'] = array(
    'title' => t('DC: Distribution Members'),   // same as group above
    'database' => 'adept90',
    'weight' => -10,
  );
  $data['fm90distri']['table']['join'] = array(
    'fm90distrl' => array(
      'left_field' => 'S_DISTRLID',
      'field' => 'S_DISTRLID',
    ),
    'fm90cont' => array(
      'left_field' => 'S_CONTID',
      'field' => 'S_CONTID',
    ),  
    'Transmittals' => array(
      'left_table' => 'fm90distrl',
      'left_field' => 'S_DISTRLID',
      'field' => 'S_DISTRLID',
    ),
  );
  
  // fm90distri - Fields
  
  $data['fm90distri']['S_DISTRLID'] = array(
    'title' => t('Distribution GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'fm90distrl', // The name of the table to join with.
      'base field' => 'S_DISTRLID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Dist Lists'),
      'title' => t('Relationship with Distribution List table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90distri']['S_CONTID'] = array(
    'title' => t('Contact GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'fm90cont', // The name of the table to join with.
      'base field' => 'S_CONTID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Contacts in Dist Listing'),
      'title' => t('Relationship with Contact table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end FM90DISTRI */

  // ----------------------------------------------------------------
  // fm90distrl - Basic Info
  
  $data['fm90distrl']['table']['group'] = t('DC: Distribution Groups');

  // Advertise as possible base table
  $data['fm90distrl']['table']['base'] = array(
    'field' => 'S_DISTRLID',
    'title' => t('DC: Distribution Groups'),
    'database' => 'adept90',
    'weight' => -10,
  );
    $data['fm90distrl']['table']['join'] = array(
    'Transmittals' => array(
      'left_field' => 'S_DISTRLID',
      'field' => 'S_DISTRLID',
    ),
  );
  
  // fm90distrl - Fields
  
  $data['fm90distrl']['S_DISTRLID'] = array(
    'title' => t('Distribution GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Transmittals', // The name of the table to join with.
      'base field' => 'S_DISTRLID', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Transmittals sent to this Dist List'),
      'title' => t('Relationship with Transmittal table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['fm90distrl']['S_NAME'] = array(
    'title' => t('Distribution Group'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end FM90DISTRL */

  // ----------------------------------------------------------------
  // CurrentJobs - Basic Info
  
  $data['CurrentJobs']['table']['group'] = t('DC: Current Projects View');

  // Advertise as possible base table
  $data['CurrentJobs']['table']['base'] = array(
    'field' => 'S_JOBID',
    'title' => t('DC: Current Projects View'),
    'database' => 'adept90',
    'weight' => -10,
  );
  $data['CurrentJobs']['table']['join'] = array(
    'Transmittals' => array(
      'left_field' => 'S_JOBID',
      'field' => 'S_JOBID',
    ),
    'Files' => array(
      'left_field' => 'S_LIBID',
      'field' => 'S_LIBID',
    ),
  );
  
  // CurrentJobs - Fields
  
  $data['CurrentJobs']['S_JOBID'] = array(
    'title' => t('Project ID'),
    'help' => t('GUID number from old Access.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Transmittals', // The name of the table to join with.
      'base field' => 'S_JOBID', // The name of the field on the joined table.
      'label' => t('Transmittal Relation'),
      'title' => t('Relationship with Transmittals table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['S_JOBNAME'] = array(
    'title' => t('Project Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['S_JOBSEL'] = array(
    'title' => t('Project Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['OWNER'] = array(
    'title' => t('Owner'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['CLIENT'] = array(
    'title' => t('Client'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['REFNO'] = array(
    'title' => t('Reference Number'),
    'help' => t('Usually the Client PO Number.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['LOCATION'] = array(
    'title' => t('Location'),
    'help' => t('Usually the Plant Address'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['REVC'] = array(
    'title' => t('Client Response Time'),
    'help' => t('Usually 10 days'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['CurrentJobs']['REVV'] = array(
    'title' => t('Vendor Response Time'),
    'help' => t('Usually 10 days'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['CurrentJobs']['REVI'] = array(
    'title' => t('Internal Response Time'),
    'help' => t('Usually 10 days'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['CurrentJobs']['PRODUCT'] = array(
    'title' => t('Product'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['TYPE'] = array(
    'title' => t('Project Type'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['SERIES'] = array(
    'title' => t('Series'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['S_LIBID'] = array(
    'title' => t('Library GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['S_FOLDER'] = array(
    'title' => t('Library Folder Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['S_PATH'] = array(
    'title' => t('Library Path'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['CurrentJobs']['Project'] = array(
    'title' => t('Project'),
    'help' => t('Project Type & Number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end CurrentJobs */

  // ----------------------------------------------------------------
  // Files - Basic Info
  
  $data['Files']['table']['group'] = t('DC: Files');

  // Advertise as possible base table
  $data['Files']['table']['base'] = array(
    'field' => 'IDrev',
    'title' => t('DC: Files'),
    'database' => 'adept90',
    'weight' => -10,
  );

  // Files - Fields
  
  $data['Files']['IDrev'] = array(
    'title' => t('IDrev'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Relate', // The name of the table to join with.
      'base field' => 'IDrevP', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Relations'),
      'title' => t('Relationship with Relations table.'),
      'extra' => array(array('field' => 'S_RELTYPE', 'value' => 'GP', 'operator' => '=')),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_EXT'] = array(
    'title' => t('File extension'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_FILEID'] = array(
    'title' => t('File GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_FMDATE'] = array(
    'title' => t('ADEPT Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'dc_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort_date',),
    'filter' => array('handler' => 'dc_handler_filter_date',),
    'argument' => array('handler' => 'views_handler_argument_date',),
  );
  $data['Files']['S_GREV'] = array(
    'title' => t('Greatest Revision'),
    'help' => t('Bool: Is the greatest rev of the Document Series?'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_LIBID'] = array(
    'title' => t('Library GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_LONGNAME'] = array(
    'title' => t('File Name'),
    'help' => t('Full File Name and Extension'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_MAJREV'] = array(
    'title' => t('Major Rev'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['Files']['S_MINREV'] = array(
    'title' => t('Minor Rev'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['Files']['S_SRCDB'] = array(
    'title' => t('Source DB Table'),
    'help' => t('If "1", then current revision. If "14", then previous revision.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['Files']['S_STATUS'] = array(
    'title' => t('Current Status'),
    'help' => t('"IN", "OUT, "VERSIONED", etc'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_FILEUTC'] = array(
    'title' => t('S_FILEUTC'),
    'help' => t('File UTC'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['S_EXTRUTC'] = array(
    'title' => t('S_EXTRUTC'),
    'help' => t('Extracted UTC'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PROJECT'] = array(
    'title' => t('Project #'),
    'help' => t('4-digit Project Number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PROJ_TYPE'] = array(
    'title' => t('Project Type'),
    'help' => t('C/ D/ S/ L'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['COMMENT2'] = array(
    'title' => t('Comment 2'),
    'help' => t('Second Comment'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['CUSTOMER'] = array(
    'title' => t('Customer'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['SEQUENCE'] = array(
    'title' => t('Document Sequence'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['DWG_SCALE'] = array(
    'title' => t('Drawing Scale'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['DWG_SIZE'] = array(
    'title' => t('Drawing Size'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PLANT'] = array(
    'title' => t('Plant Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PRODUCT'] = array(
    'title' => t('Product'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['REVISION'] = array(
    'title' => t('Revision'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['SHEET_NO'] = array(
    'title' => t('Sheet Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['TITLE_1'] = array(
    'title' => t('Title Field 1'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['TITLE_2'] = array(
    'title' => t('Title Field 2'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['TITLE_3'] = array(
    'title' => t('Title Field 3'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['TITLE_4'] = array(
    'title' => t('Title Field 4'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['TOTAL_SH'] = array(
    'title' => t('Total # of Sheets'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['UNIT_NO'] = array(
    'title' => t('Unit Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PRODUCTCYC'] = array(
    'title' => t('Product Cycle'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['SERIESNO'] = array(
    'title' => t('Series Number'),
    'help' => t('Series / EMES / Commodity'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['VENDDWGNO'] = array(
    'title' => t('Vendor Document Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['VENDNAME'] = array(
    'title' => t('Vendor Name'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['VENDPONO'] = array(
    'title' => t('Vendor PO #'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['VENDRCVDTE'] = array(
    'title' => t('Vendor Receive Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['VENDRTDTE'] = array(
    'title' => t('Vendor Return Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['FIELDPRINT'] = array(
    'title' => t('Field Print'),
    'help' => t('Is Document a Field Print? P = yes, N = no'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['DWG_TYPE'] = array(
    'title' => t('Document Type'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['LAST_NAME'] = array(
    'title' => t('Last Name'),
    'help' => t('User who submitted document'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['FIRST_INIT'] = array(
    'title' => t('First Initial'),
    'help' => t('User who submitted document'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['REV_DATE'] = array(
    'title' => t('Revision Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'dc_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort_date',),
    'filter' => array('handler' => 'dc_handler_filter_date',),
    'argument' => array('handler' => 'views_handler_argument_date',),
  );
  $data['Files']['STATUSCODE'] = array(
    'title' => t('Status Code'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['STATUSDATE'] = array(
    'title' => t('Status Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['DRWN'] = array(
    'title' => t('Drawn'),
    'help' => t('Drawn By??'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['PLANTLOC'] = array(
    'title' => t('Plant Location'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['CADREVDATE'] = array(
    'title' => t('CAD Revision Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['DWG_STATE'] = array(
    'title' => t('Document State'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['SPCL_SORT'] = array(
    'title' => t('Special Sort'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['REC_CLIENT'] = array(
    'title' => t('Received from Client'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['REC_VENDOR'] = array(
    'title' => t('Received from Vendor'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['REC_INTERN'] = array(
    'title' => t('Received from Internal Routing'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Files']['FilePath'] = array(
    'title' => t('File Path'),
    'help' => t('Physical Path to Document'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end FILES */

  // ----------------------------------------------------------------
  // Relate - Basic Info
  
  $data['Relate']['table']['group'] = t('DC: Relations');

  // Advertise as possible base table
  $data['Relate']['table']['base'] = array(
    'field' => 'RELID',
    'title' => t('DC: Relations'),
    'database' => 'adept90',
    'weight' => -10,
  );

  // Relate - Fields

  $data['Relate']['RELID'] = array(
    'title' => t('RELID'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Relate']['IDrevP'] = array(
    'title' => t('IDrevP'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Relate']['IDrevC'] = array(
    'title' => t('IDrevC'),
    'help' => t('Concatenated Composite Key - Child'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Files', // The name of the table to join with.
      'base field' => 'IDrev', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Files'),
      'title' => t('Relationship with Files table.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Relate']['S_RELTYPE'] = array(
    'title' => t('S_RELTYPE'),
    'help' => t('Relationship Type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end RELF */

  // ----------------------------------------------------------------
  // Transmittals - Basic Info
  
  $data['Transmittals']['table']['group'] = t('DC: Transmittals');

  // Advertise as possible base table
  $data['Transmittals']['table']['base'] = array(
    'field' => 'S_TRNSMID',
    'title' => t('DC: Transmittals'),   // same as group above
    'database' => 'adept90',
    'weight' => -10,
  );

  // Transmittals - Fields

  $data['Transmittals']['S_TRNSMID'] = array(
    'title' => t('Transmittal GUID'),
    'help' => t('ID of transmittal in Transmittal table'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['IDrev'] = array(
    'title' => t('IDrev'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Relate', // The name of the table to join with.
      'base field' => 'IDrevP', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Relations'),
      'title' => t('Relationship with Relations table.'),
      'extra' => array(array('field' => 'S_RELTYPE', 'value' => 'TR', 'operator' => '=')),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_FILEID'] = array(
    'title' => t('Transmittal File GUID'),
    'help' => t('ID of transmittal in Files table'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_JOBID'] = array(
    'title' => t('Jobs GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_COMPID'] = array(
    'title' => t('Company GUID'),
    'help' => t('Addressee - Company'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_CONTID'] = array(
    'title' => t('Contact GUID'),
    'help' => t('Addressee - Contact'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_DISTRLID'] = array(
    'title' => t('Distribution GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['COMMENTS'] = array(
    'title' => t('Comments'),
    'help' => t('Comments'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['MEDIA'] = array(
    'title' => t('Media'),
    'help' => t('Media Type of Transmittal'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['METHOD'] = array(
    'title' => t('Method'),
    'help' => t('Method transmittal was sent'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['TransNo'] = array(
    'title' => t('Transmittal Number'),
    'help' => t('Full Document Name including extension'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['Commodity'] = array(
    'title' => t('Commodity Code'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['Project'] = array(
    'title' => t('Project'),
    'help' => t('Project Type & Number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => True,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['S_LIBID'] = array(
    'title' => t('Library GUID'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['SentLog'] = array(
    'title' => t('Sent Log'),
    'help' => t('Log message when transmittal is sent'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['SentDate'] = array(
    'title' => t('Sent Date'),
    'help' => t('Date the transmtital was sent'),
    'field' => array(
      'handler' => 'dc_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort_date',),
    'filter' => array('handler' => 'dc_handler_filter_datetime',),
    'argument' => array('handler' => 'views_handler_argument_date',),
  );
  $data['Transmittals']['SentBy'] = array(
    'title' => t('Sent By'),
    'help' => t('User who sent transmittal'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['TransNo'] = array(
    'title' => t('Transmittal Number'),
    'help' => t('Transmittal Number, Short'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['Transmittals']['TransType'] = array(
    'title' => t('Transmittal Type'),
    'help' => t('Type of transmittal: C/V/R'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end TRANSMITTALS */

  // ----------------------------------------------------------------
  // ChildFiles - Basic Info
  
  $data['ChildFiles']['table']['group'] = t('DC: ChildFiles');

  // Advertise as possible base table
  $data['ChildFiles']['table']['base'] = array(
    'field' => 'RELID',
    'title' => t('DC: Child Files'),   // same as group above
    'database' => 'adept90',
    'weight' => -10,
  );
    $data['ChildFiles']['table']['join'] = array(
    'Files' => array(
      'left_field' => 'IDrev',
      'field' => 'IDrevP',
    ),
  );
    $data['ChildFiles']['table']['join'] = array(
    'TransFiles' => array(
      'left_field' => 'IDrevC',
      'field' => 'IDrevP',
    ),
  );

  // ChildFiles - Fields
  $data['ChildFiles']['RELID'] = array(
    'title' => t('RELID'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['IDrevP'] = array(
    'title' => t('IDrevP'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['IDrevC'] = array(
    'title' => t('IDrevC'),
    'help' => t('Concatenated Composite Key - Child'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['S_RELTYPE'] = array(
    'title' => t('S_RELTYPE'),
    'help' => t('Relationship Type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['S_FMDATE'] = array(
    'title' => t('ADEPT Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'dc_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort_date',),
    'filter' => array('handler' => 'dc_handler_filter_date',),
    'argument' => array('handler' => 'views_handler_argument_date',),
  );
  $data['ChildFiles']['S_LONGNAME'] = array(
    'title' => t('File Name'),
    'help' => t('Full File Name and Extension'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['S_SRCDB'] = array(
    'title' => t('Source DB Table'),
    'help' => t('If "1", then current revision. If "14", then previous revision.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['ChildFiles']['REVISION'] = array(
    'title' => t('Revision'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['SHEET_NO'] = array(
    'title' => t('Sheet Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['TITLE_1'] = array(
    'title' => t('Title Field 1'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['TITLE_2'] = array(
    'title' => t('Title Field 2'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['TITLE_3'] = array(
    'title' => t('Title Field 3'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['TITLE_4'] = array(
    'title' => t('Title Field 4'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['PRODUCTCYC'] = array(
    'title' => t('Product Cycle'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['VENDDWGNO'] = array(
    'title' => t('Vendor Document Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['FIELDPRINT'] = array(
    'title' => t('Field Print'),
    'help' => t('Is Document a Field Print? P = yes, N = no'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['STATUSCODE'] = array(
    'title' => t('Status Code'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['STATUSDATE'] = array(
    'title' => t('Status Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['ChildFiles']['FilePath'] = array(
    'title' => t('File Path'),
    'help' => t('Physical Path to Document'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end CHILDFILES */

  // ----------------------------------------------------------------
  // TransFiles - Basic Info
  
  $data['TransFiles']['table']['group'] = t('DC: TransFiles');

  // Advertise as possible base table
  $data['TransFiles']['table']['base'] = array(
    'field' => 'RELID',
    'title' => t('DC: TransFiles'),   // same as group above
    'database' => 'adept90',
    'weight' => -10,
  );
    $data['TransFiles']['table']['join'] = array(
    'Transmittals' => array(
      'left_field' => 'IDrev',
      'field' => 'IDrevP',
    ),
  );

  // TransFiles - Fields
  $data['TransFiles']['RELID'] = array(
    'title' => t('RELID'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['IDrevP'] = array(
    'title' => t('IDrevP'),
    'help' => t('Concatenated Composite Key'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'relationship' => array(
      'base' => 'Transmittals', // The name of the table to join with.
      'base field' => 'IDrev', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Transmittals'),
      'title' => t('Relationship between Transmittals and their files.'),
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['IDrevC'] = array(
    'title' => t('IDrevC'),
    'help' => t('Concatenated Composite Key - Child'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['S_RELTYPE'] = array(
    'title' => t('S_RELTYPE'),
    'help' => t('Relationship Type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['S_FMDATE'] = array(
    'title' => t('ADEPT Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'dc_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort_date',),
    'filter' => array('handler' => 'dc_handler_filter_date',),
    'argument' => array('handler' => 'views_handler_argument_date',),
  );
  $data['TransFiles']['S_LONGNAME'] = array(
    'title' => t('File Name'),
    'help' => t('Full File Name and Extension'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['S_SRCDB'] = array(
    'title' => t('Source DB Table'),
    'help' => t('If "1", then current revision. If "14", then previous revision.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric',),
    'argument' => array('handler' => 'views_handler_argument_numeric',),
  );
  $data['TransFiles']['REVISION'] = array(
    'title' => t('Revision'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['SHEET_NO'] = array(
    'title' => t('Sheet Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['TITLE_1'] = array(
    'title' => t('Title Field 1'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['TITLE_2'] = array(
    'title' => t('Title Field 2'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['TITLE_3'] = array(
    'title' => t('Title Field 3'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['TITLE_4'] = array(
    'title' => t('Title Field 4'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['PRODUCTCYC'] = array(
    'title' => t('Product Cycle'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['VENDDWGNO'] = array(
    'title' => t('Vendor Document Number'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['FIELDPRINT'] = array(
    'title' => t('Field Print'),
    'help' => t('Is Document a Field Print? P = yes, N = no'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['STATUSCODE'] = array(
    'title' => t('Status Code'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['STATUSDATE'] = array(
    'title' => t('Status Date'),
    'help' => t(' '),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort',),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  $data['TransFiles']['FilePath'] = array(
    'title' => t('File Path'),
    'help' => t('Physical Path to Document'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string',),
    'argument' => array('handler' => 'views_handler_argument_string',),
  );
  /* end TRANSFILES */


  
  return $data;
}

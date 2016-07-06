<?php
/**
 * @file
 * views_entity_form_ctools.views.inc
 *
 * @author
 * Name: Boolboost
 * Web: http://boolboost.com
 * Email: bool.boost@gmail.com
 */

/**
 * Implements hook_views_handlers().
 */
function views_entity_form_ctools_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_entity_form_ctools')
    ),
    'handlers' => array(
      'views_entity_form_ctools_handler_entityform_ctools_link' => array(
        'parent' => 'views_handler_field'
      )
    )
  );
}

/**
 * Implements hook_views_data().
 */
function views_entity_form_ctools_views_data() {
  $data = array();

  // Add Example group
  $data['views_entity_form_ctools']['table']['group'] = t('Entityform ctools');
  $data['views_entity_form_ctools']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );

  // Add custom field
  $data['views_entity_form_ctools']['entityform_ctools_link'] = array(
    'title' => t('Entityform ctools link'),
    'help' => t('Support for links in views'),
    'field' => array(
      'handler' => 'views_entity_form_ctools_handler_entityform_ctools_link',
    ),
  );
  return $data;
}
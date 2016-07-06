<?php
/**
 * @file
 * Views field with entityform ctools link.
 *
 * @author
 * Name: Boolboost
 * Web: http://boolboost.com
 * Email: bool.boost@gmail.com
 */

/**
 * Provides a custom views field.
 */
class views_entity_form_ctools_handler_entityform_ctools_link extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();

    $options['entityform_name'] = array('default' => '');
    $options['link_title'] = array('default' => 'Entityform link');
    $options['link_theme'] = array('default' => 'default');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array(
      '_none' => t('- None -')
    );

    foreach (entityform_get_types() as $key => &$type) {
      $options[$key] = $type->label;
    }

    $form['entityform_name'] = array(
      '#type' => 'select',
      '#title' => t('Entityform name'),
      '#options' => $options,
      '#default_value' => $this->options['entityform_name']
    );

    $form['link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#default_value' => $this->options['link_title']
    );

    $form['link_theme'] = array(
      '#type' => 'textfield',
      '#title' => t('Theme'),
      '#default_value' => $this->options['link_theme']
    );
  }

  function query() {
  }

  function render($data) {
    if ($this->options['entityform_name'] != '_none') {
      $text = $this->options['link_title'];
      $entityform_name = $this->options['entityform_name'];
      $theme = $this->options['link_theme'];

      return entityform_ctools_add_link($text, $entityform_name, $theme);
    }

    return '';
  }
}

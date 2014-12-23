<?php
/**
 * @file
 * c4m_content_group.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_group_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|c4m_dashboard';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'c4m_dashboard';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Continue reading',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group created on ',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_node_author_image' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'thumbnail',
    ),
    'c4m_ds_author_first_and_last_name' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'author_link',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group owner',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'user-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_group_role_members' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => '6',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Moderators',
        ),
      ),
    ),
    'c4m_ds_group_access_info' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|group|c4m_dashboard'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_group_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|c4m_dashboard';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'c4m_dashboard';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'c4m_ds_node_author_image',
        2 => 'c4m_body',
        3 => 'c4m_ds_author_first_and_last_name',
        4 => 'c4m_ds_group_role_members',
        5 => 'node_link',
        6 => 'c4m_ds_group_access_info',
        7 => 'c4m_related_topic',
        8 => 'c4m_vocab_geo',
        9 => 'group_details',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'c4m_ds_node_author_image' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_ds_author_first_and_last_name' => 'ds_content',
      'c4m_ds_group_role_members' => 'ds_content',
      'node_link' => 'ds_content',
      'c4m_ds_group_access_info' => 'ds_content',
      'c4m_related_topic' => 'ds_content',
      'c4m_vocab_geo' => 'ds_content',
      'group_details' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|group|c4m_dashboard'] = $ds_layout;

  return $export;
}
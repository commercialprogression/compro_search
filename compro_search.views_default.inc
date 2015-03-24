<?php
/**
 * @file
 * compro_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function compro_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_multi';
  $view->human_name = 'Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'search content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'search_api_multi';
  $handler->display->display_options['row_options']['view_mode'] = array(
    'node' => 'search_result',
  );
  /* Field: Search: node results */
  $handler->display->display_options['fields']['default_node_index']['id'] = 'default_node_index';
  $handler->display->display_options['fields']['default_node_index']['table'] = 'search_api_multi';
  $handler->display->display_options['fields']['default_node_index']['field'] = 'default_node_index';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_multi';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: node: Date changed (indexed) */
  $handler->display->display_options['sorts']['default_node_index_changed']['id'] = 'default_node_index_changed';
  $handler->display->display_options['sorts']['default_node_index_changed']['table'] = 'search_api_multi';
  $handler->display->display_options['sorts']['default_node_index_changed']['field'] = 'default_node_index_changed';
  $handler->display->display_options['sorts']['default_node_index_changed']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['label'] = 'Search term';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'sq';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: SERP */
  $handler = $view->new_display('page', 'SERP', 'serp');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'admin/content/search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Search';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['search'] = $view;

  return $export;
}

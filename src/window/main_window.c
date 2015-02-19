#include "bitface.h"

void		main_window_load(Window *window)
{
	s_time_layer = text_layer_create(GRect(0, 55, 144, 50));
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_text_color(s_time_layer, GColorBlack);
	text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

	s_info_layer = text_layer_create(GRect(0, 5, 144, 168));
	text_layer_set_background_color(s_info_layer, GColorClear);
	text_layer_set_text_color(s_info_layer, GColorBlack);
	text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	text_layer_set_text_alignment(s_info_layer, GTextAlignmentCenter);
	text_layer_set_text(s_info_layer, "Loading...");

	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_info_layer));
	update_time();
}

void		main_window_unload(Window *window)
{
	text_layer_destroy(s_time_layer);
	text_layer_destroy(s_info_layer);
}

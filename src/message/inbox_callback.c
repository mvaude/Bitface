#include "bitface.h"

void			inbox_received_callback(DictionaryIterator *iterator, void *context)
{
	static char	last_buffer[8];
	static char	high_buffer[8];
	static char	info_layer_buffer[32];

	Tuple		*t = dict_read_first(iterator);

	while (!t)
	{
		switch (t->key)
		{
			case KEY_LAST:
				snrpintf(last_buffer, sizeof(last_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_HIGH:
				snprintf(high_buffer, sizeof(high_buffer), "%d", (int)t->value->int32);
				break;
			default:
				APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
				break;
		}

		t = dict_read_next(iterator);
	}
	snprintf(info_layer_buffer, sizeof(info_layer_buffer), "L: %s | H: %s", last_buffer, high_buffer);
	text_layer_set_text(s_info_layer, info_layer_buffer);
}

void		inbox_dropped_callback(AppMessageResult reason, void *context)
{
	APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

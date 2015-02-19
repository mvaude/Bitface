#include "bitface.h"

void			inbox_received_callback(DictionaryIterator *iterator, void *context)
{
	static char	last_buffer[8];
	static char	high_buffer[8];
	static char	vwap_buffer[8];
	static char	low_buffer[8];
	static char	volume_buffer[8];
	static char	bid_buffer[8];
	static char	ask_buffer[8];
	static char	info_layer_buffer[32];

	Tuple		*t = dict_read_first(iterator);

	while (t)
	{
		switch (t->key)
		{
			case KEY_LAST:
				snprintf(last_buffer, sizeof(last_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_HIGH:
				snprintf(high_buffer, sizeof(high_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_VWAP:
				snprintf(vwap_buffer, sizeof(vwap_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_LOW:
				snprintf(low_buffer, sizeof(low_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_VOLUME:
				snprintf(volume_buffer, sizeof(volume_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_BID:
				snprintf(bid_buffer, sizeof(bid_buffer), "%d", (int)t->value->int32);
				break;
			case KEY_ASK:
				snprintf(ask_buffer, sizeof(ask_buffer), "%d", (int)t->value->int32);
				break;
			default:
				APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
				break;
		}

		t = dict_read_next(iterator);
	}
	snprintf(info_layer_buffer, sizeof(info_layer_buffer), "Last: %s | High: %s\n\nvwap: %s | low: %s\n\n\n\n\n\nVolume: %s\n\nbid: %s | ask: %s", last_buffer, high_buffer, vwap_buffer, low_buffer, volume_buffer, bid_buffer, ask_buffer);
	text_layer_set_text(s_info_layer, info_layer_buffer);
}

void		inbox_dropped_callback(AppMessageResult reason, void *context)
{
	APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

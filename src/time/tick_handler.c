#include "bitface.h"

void		tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
	update_time();

	// Get infos update every 10 minutes
	if (!(tick_time->tm_min % 10))
	{
		DictionaryIterator	*iter;
		app_message_outbox_begin(&iter);

		dict_write_uint8(iter, 0, 0);
		app_message_outbox_send();
	}
}

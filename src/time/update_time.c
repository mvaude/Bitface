#include "bitface.h"

void			update_time()
{
	time_t		temp;
	struct tm	*tick_time;

	static char	buffer[5];
	strftime(buffer, sizeof("00:00"), clock_is_24h_style() ? "%H:%M" : "%I:%M, tick_time);
/*
	if (clock_is_24h_style() == true)
		strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
	else
		strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);*/
	text_layer_set_text(s_time_layer, buffer);
}

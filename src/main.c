/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaude <mvaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:06:31 by mvaude            #+#    #+#             */
/*   Updated: 2015/02/18 15:33:47 by mvaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitface.h"

static void				init()
{
	s_main_window = window_create();

	window_set_window_handlers(s_main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});

	window_stack_push(s_main_window, true);

	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

	app_message_register_inbox_received(inbox_received_callback);
	app_message_register_inbox_dropped(inbox_dropped_callback);
	app_message_register_outbox_failed(outbox_failed_callback);
	app_message_register_outbox_sent(outbox_sent_callback);
	
	app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
}

static void				deinit()
{
	window_destroy(s_main_window);
}

int						main(void)
{
	init();
	app_event_loop();
	deinit();
}

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

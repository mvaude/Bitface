/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitface.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaude <mvaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:09:15 by mvaude            #+#    #+#             */
/*   Updated: 2015/02/18 15:33:49 by mvaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITFACE_H
# define BITFACE_H

# include <pebble.h>

Window				*s_main_window;
TextLayer			*s_time_layer;
TextLayer			*s_info_layer;

typedef enum
{
	KEY_LAST = 		0,
	KEY_HIGH =		1,
	KEY_LOW =		2,
	KEY_VWAP =		3,
	KEY_VOLUME =		4,
	KEY_BID =		5,
	KEY_ASK =		6
}				t_infos;

void				main_window_load(Window *window);
void				main_window_unload(Window *window);
void				tick_handler(struct tm *tick_time, TimeUnits units_changed);
void				update_time();

#endif

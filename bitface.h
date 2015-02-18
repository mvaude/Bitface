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

void				main_window_load(Window *window);
void				main_window_unload(Window *window);

#endif

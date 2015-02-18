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

#include <pebble.h>
#include "bitface.h"

static void				init()
{

}

static void				deinit()
{
}

int						main(void)
{
	init();
	app_event_loop();
	deinit();
}

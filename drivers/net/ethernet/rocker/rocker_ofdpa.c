/*
 * drivers/net/ethernet/rocker/rocker_ofdpa.c - Rocker switch OF-DPA-like
 *					        implementation
 * Copyright (c) 2014 Scott Feldman <sfeldma@gmail.com>
 * Copyright (c) 2014 Jiri Pirko <jiri@resnulli.us>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/kernel.h>
#include "rocker.h"

struct rocker_ofdpa {
};

struct rocker_ofdpa_port {
};

struct rocker_world_ops rocker_ofdpa_ops = {
	.kind = "ofdpa",
	.priv_size = sizeof(struct rocker_ofdpa),
	.port_priv_size = sizeof(struct rocker_ofdpa_port),
	.mode = ROCKER_PORT_MODE_OF_DPA,
};

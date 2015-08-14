/*
 * drivers/net/ethernet/rocker/rocker.h - Rocker switch device driver
 * Copyright (c) 2014-2015 Jiri Pirko <jiri@resnulli.us>
 * Copyright (c) 2014-2015 Scott Feldman <sfeldma@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef _ROCKER_H
#define _ROCKER_H

#include <linux/kernel.h>
#include <linux/types.h>

#include "rocker_hw.h"

struct rocker_desc_info {
	char *data; /* mapped */
	size_t data_size;
	size_t tlv_size;
	struct rocker_desc *desc;
	dma_addr_t mapaddr;
};

struct rocker;
struct rocker_port;

struct rocker_world_ops {
	const char *kind;
	size_t priv_size;
	size_t port_priv_size;
	u8 mode;
	int (*init)(struct rocker *rocker, void *priv);
	void (*fini)(struct rocker *rocker, void *priv);
	int (*port_init)(struct rocker_port *rocker_port, void *priv,
			 void *port_priv);
	void (*port_fini)(struct rocker_port *rocker_port, void *priv,
			  void *port_priv);
	int (*port_open)(struct rocker_port *rocker_port, void *priv,
			 void *port_priv);
	void (*port_stop)(struct rocker_port *rocker_port, void *priv,
			  void *port_priv);
};

extern struct rocker_world_ops rocker_ofdpa_ops;

#endif

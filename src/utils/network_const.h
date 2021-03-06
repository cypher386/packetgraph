/* Copyright 2017 Outscale SAS
 *
 * This file is part of Packetgraph.
 *
 * Packetgraph is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as published
 * by the Free Software Foundation.
 *
 * Packetgraph is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Packetgraph.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PG_UTILS_NETWORK_CONST_H
#define _PG_UTILS_NETWORK_CONST_H

#include <rte_config.h>
#include <rte_ether.h>
#include <rte_ip.h>
#include <endian.h>

#include "utils/bitmask.h"

#define PG_BE_ETHER_TYPE_ARP PG_CPU_TO_BE_16(ETHER_TYPE_ARP)
#define PG_BE_ETHER_TYPE_RARP PG_CPU_TO_BE_16(ETHER_TYPE_RARP)
#define PG_BE_ETHER_TYPE_IPv4 PG_CPU_TO_BE_16(ETHER_TYPE_IPv4)
#define PG_BE_ETHER_TYPE_IPv6 PG_CPU_TO_BE_16(ETHER_TYPE_IPv6)
#define PG_BE_IPV4_HDR_DF_FLAG PG_CPU_TO_BE_16(IPV4_HDR_DF_FLAG)
/* 0000 1000 0000 ... */
#define PG_VTEP_I_FLAG 0x08000000
#define PG_VTEP_BE_I_FLAG PG_CPU_TO_BE_32(PG_VTEP_I_FLAG)

#endif /* ifndef _PG_UTILS_NETWORK_CONST_H */

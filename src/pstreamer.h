/*******************************************************************
* PeerStreamer-ng is a P2P video streaming application exposing a ReST
* interface.
* Copyright (C) 2017 Luca Baldesi <luca.baldesi@unitn.it>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/

#ifndef __PSTREAMER_H__
#define __PSTREAMER_H__ 

#include<ord_set.h>
#include<stdint.h>
#include<name_lengths.h>
#include<task_manager.h>
#include<janus_instance.h>
#include<streamer_creation_callback.h>

struct pstreamer;
struct pstreamer_manager;
struct janus_instance;
struct streamer_creation_callback;

struct pstreamer_manager * pstreamer_manager_new(uint16_t starting_port, const struct janus_instance *janus);

void pstreamer_manager_destroy(struct pstreamer_manager ** psm);

const struct pstreamer * pstreamer_manager_create_streamer(struct pstreamer_manager * psm, const char * source_ip, const char * source_port, const char * id, const char * rtp_dst_ip, struct streamer_creation_callback * scc);

char * pstreamer_to_json(const struct pstreamer * ps);

uint8_t pstreamer_manager_destroy_streamer(struct pstreamer_manager *psm, const struct pstreamer *ps);

const char * pstreamer_id(const struct pstreamer * ps);

uint16_t pstreamer_base_port(const struct pstreamer * ps);

int8_t pstreamer_schedule_tasks(struct pstreamer *ps, struct task_manager * tm);

const struct pstreamer * pstreamer_manager_get_streamer(const struct pstreamer_manager *psm, const char * id);

void pstreamer_manager_remove_orphans(struct pstreamer_manager * psm, time_t interval);

void pstreamer_touch(struct pstreamer *ps);

const char * pstreamer_source_ipaddr(const struct pstreamer *ps);

const char * pstreamer_source_port(const struct pstreamer *ps);

int8_t pstreamer_manager_set_streamer_options(struct pstreamer_manager *psm, const char * opts);

uint8_t pstreamer_is_source(const struct pstreamer * ps);

char * pstreamer_manager_sources_to_json(const struct pstreamer_manager *psm);

const struct pstreamer * pstreamer_manager_create_source_streamer(struct pstreamer_manager * psm, const char * id, const char * rtp_src_ip, struct streamer_creation_callback * scc);

void pstreamer_source_touch(const struct pstreamer_manager *psm, struct pstreamer *ps, uint64_t janus_id);

const struct pstreamer * pstreamer_manager_source_iter(const struct pstreamer_manager *psm, const struct pstreamer * ps);

const char * pstreamer_get_display_name(const struct pstreamer * ps);

void pstreamer_set_display_name(struct pstreamer *ps, const char * name);

#endif

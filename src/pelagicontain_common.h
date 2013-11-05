/*
 * Copyright (C) 2013, Pelagicore AB <jonatan.palsson@pelagicore.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

/*! \brief  Common code for Pelagicontain
 *  \author Jonatan Pålsson (joantan.palsson@pelagicore.com)
 *
 * Here is common code, such as shared data structures
 */
#ifndef PELAGICONTAIN_COMMON_H
#define PELAGICONTAIN_COMMON_H

struct lxc_params {

	/* networking */
	/*! IPv4 address for this container */
	char *ip_addr;

	/*! IPv4 address for the default GW of this container */
	char *gw_addr; 

	/*! External interface name for the networking interface of the
	 * container */
	char *net_iface_name; 


	/* traffic control */
	/*! Rate limit for the networking interface, Kbps and Mbps suffixes are
	 * supported, for instance: 500Kbps */
	char *tc_rate; 

	/* pulse audio */
	/*! Path to the Pulse Audio socket as seen from the host system */
	char pulse_socket[1024]; 

	/*! Path to the  Pulse Audio socket as seen from within the container
	 * */
	char deployed_pulse_socket[1024];


	/* D-Bus */
	/*! Path to the D-Bus session proxy socket as seen from the host */
	char session_proxy_socket[1024];

	/*! Path to the D-Bus system proxy socket as seen from the host */
	char system_proxy_socket[1024];

	/*! Path to the D-Bus session proxy socket as seen from within the
	 * container */
	char deployed_session_proxy_socket[1024];

	/*! Path to the D-Bus system proxy socket as seen from within the
	 * container */
	char deployed_system_proxy_socket[1024];


	/* LXC general */
	/*! Unique name of the container, used to identify it in LXC */
	char *container_name;

	/*! Path to the LXC system config, as seen from the host */
	char *lxc_system_cfg;

	/*! Path to the directory being deployed, as seen from the host */
	char *ct_dir;

	/*! lxc_params#ct_dir  + "/config/" */
	char ct_conf_dir[1024];

	/*! lxc_params#ct_dir + "/rootfs/" */
	char ct_root_dir[1024];

	/*! Path to temporary LXC config used to launch this instance of this
	 * container, as seen from host */
	char lxc_cfg_file[1024];

	/* general */
	/*! Path to Pelagicontain config file, as seen from host */
	char main_cfg_file[1024];

};

#endif /* PELAGICONTAIN_COMMON_H */

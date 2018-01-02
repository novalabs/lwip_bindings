/* COPYRIGHT (c) 2016-2018 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file lwipthread.h
 * @brief LWIP wrapper thread macros and structures.
 * @addtogroup LWIP_THREAD
 * @{
 */

#pragma once

#ifndef LWIP_THREAD_PRIORITY
#define LWIP_THREAD_PRIORITY                NORMALPRIO
#endif

#if !defined(LWIP_THREAD_STACK_SIZE) || defined(__DOXYGEN__)
#define LWIP_THREAD_STACK_SIZE              576
#endif

#if !defined(LWIP_LINK_POLL_INTERVAL) || defined(__DOXYGEN__)
#define LWIP_LINK_POLL_INTERVAL             S2ST(2)
#endif

#if !defined(LWIP_IPADDR) || defined(__DOXYGEN__)
#define LWIP_IPADDR(p)                      IP4_ADDR(p, 10, 0, 0, 33)
#endif

#if !defined(LWIP_GATEWAY) || defined(__DOXYGEN__)
#define LWIP_GATEWAY(p)                     IP4_ADDR(p, 10, 0, 0, 254)
#endif

#if !defined(LWIP_NETMASK) || defined(__DOXYGEN__)
#define LWIP_NETMASK(p)                     IP4_ADDR(p, 255, 255, 255, 0)
#endif

#if !defined(LWIP_SEND_TIMEOUT) || defined(__DOXYGEN__)
#define LWIP_SEND_TIMEOUT                   50
#endif

#if !defined(LWIP_LINK_SPEED) || defined(__DOXYGEN__)
#define LWIP_LINK_SPEED                     100000000
#endif

#if !defined(LWIP_ETHADDR_0) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_0                      0x10
#endif

#if !defined(LWIP_ETHADDR_1) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_1                      0x98
#endif

#if !defined(LWIP_ETHADDR_2) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_2                      0x36
#endif

#if !defined(LWIP_ETHADDR_3) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_3                      0xad
#endif

#if !defined(LWIP_ETHADDR_4) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_4                      0xb7
#endif

#if !defined(LWIP_ETHADDR_5) || defined(__DOXYGEN__)
#define LWIP_ETHADDR_5                      0xc3
#endif

#if !defined(LWIP_IFNAME0) || defined(__DOXYGEN__)
#define LWIP_IFNAME0                        'm'
#endif

#if !defined(LWIP_IFNAME1) || defined(__DOXYGEN__)
#define LWIP_IFNAME1                        's'
#endif

#include <lwip/ip_addr.h>

namespace core {
class LWIP
{
public:
    /**
     * @brief   Runtime TCP/IP settings.
     */
    struct Options {
        uint8_t mac_address[6];
        ip_addr  address;
        ip_addr  netmask;
        ip_addr  gateway;
    };

    static void
    init();

    static void
    init(
        const Options& opts
    );

    static bool
    isUp();

    static bool
    isLinkUp();


private:
    static void
    _thread(
        void* p
    );
};
}

/** @} */

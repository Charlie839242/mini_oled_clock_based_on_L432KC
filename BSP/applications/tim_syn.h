/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-07-12     HW       the first version
 */
#ifndef APPLICATIONS_TIM_SYN_H_
#define APPLICATIONS_TIM_SYN_H_

#include <rtthread.h>
#include <board.h>
#include <rtdevice.h>

#include <arpa/inet.h>         /* 包含 ip_addr_t 等地址相关的头文件 */
#include <netdev.h>            /* 包含全部的 netdev 相关操作接口函数 */
#include <ntp.h>


int net_det(void);
void tim_syn(void);

#endif /* APPLICATIONS_TIM_SYN_H_ */

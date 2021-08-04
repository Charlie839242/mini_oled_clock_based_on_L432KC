/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-07-12     HW       the first version
 */
#include <tim_syn.h>


int net_det(void)
{
    /*通过网卡名称来获取获取网卡对象*/
    struct netdev* net = netdev_get_by_name("esp0");

    /*netdev_is_internet_up(netdev)是个宏，为1时表示网络正常*/
    while(netdev_is_internet_up(net) != 1)
    {
       rt_thread_mdelay(200);
    }
    //提示当前网络已就绪
    rt_kprintf("network is ok!\n");
    return 1;
}

void tim_syn(void)
{
    /*NTP自动对时*/
    time_t cur_time;
    cur_time = ntp_sync_to_rtc(NULL);
    if (cur_time)
    {
        rt_kprintf("Cur Time: %s", ctime((const time_t*) &cur_time));
    }
    else
    {
        rt_kprintf("NTP sync fail.\n");
    }

}

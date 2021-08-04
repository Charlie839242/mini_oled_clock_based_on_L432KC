/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-02-20     Mculover666  the first version
 */

#include <rtthread.h>
#include <board.h>
#include <sht3x.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        5

static rt_thread_t tid1 = RT_NULL;                                  //创建线程控制块

/* 入口函数 */
static void sht30_collect_thread_entry(void *parameter)
{
    sht3x_device_t  sht3x_device;

    sht3x_device = sht3x_init("i2c1", 0x44);                        //第一个参数声明与SHT30连接的I2C，第二个参数是向SHT30里的0x44发送指令
                                                                    //该函数初始化SHT30设备，返回指向SHT30结构体的指针

    //此处需要短暂的延时，否则会出现连续读取失败的问题，感谢网友的提醒
    rt_thread_mdelay(150);

    while (1)
    {
        if(RT_EOK == sht3x_read_singleshot(sht3x_device))           //单次读取，返回1表示读取成功
        {
            rt_kprintf("sht30 humidity   : %d.%d  ", (int)sht3x_device->humidity, (int)(sht3x_device->humidity * 10) % 10);
            rt_kprintf("temperature: %d.%d\n", (int)sht3x_device->temperature, (int)(sht3x_device->temperature * 10) % 10);
        }
        else
        {
            rt_kprintf("read sht3x fail.\r\n");
            break;
        }
        rt_thread_mdelay(2000);
    }
}

/* 创建线程 */
int sht30_collect(void)
{
    /* 创建线程*/
    tid1 = rt_thread_create("sht30_collect_thread",                        //给线程取的名字
                            sht30_collect_thread_entry,                    //线程函数
                            RT_NULL,                                       //线程函数的参数
                            THREAD_STACK_SIZE,                             //分配给线程的栈空间的大小
                            THREAD_PRIORITY,                               //线程的优先级
                            THREAD_TIMESLICE);                             //时间片？

    /* 如果获得线程控制块，启动这个线程 */
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);

    return 0;
}

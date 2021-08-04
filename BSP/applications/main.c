/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-07-11     RT-Thread    first version
 */

#include <rtthread.h>

#include <board.h>
#include <rtdevice.h>
#include <drv_soft_i2c.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include <tim_syn.h>



#define LED0_PIN GET_PIN(B,3)                       //LED引脚

extern int sht30_collect(void);

int main(void)
{
    /*打印时钟信息*/
    rt_kprintf("System Clock Information:\n");
    rt_kprintf("SYSCLK_Frequency = %d\n",HAL_RCC_GetSysClockFreq());
    rt_kprintf("HCLK_Frequency = %d\n",HAL_RCC_GetHCLKFreq());
    rt_kprintf("PCLK1_Frequency = %d\n",HAL_RCC_GetPCLK1Freq());
    rt_kprintf("PCLK2_Frequency = %d\n\n\n",HAL_RCC_GetPCLK2Freq());

    /*设置引脚模式*/
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

    /*检测网络状况，直到网络状况为1时，同步时间*/
    while(!(net_det()));

    tim_syn();

    /*创建线程并启动线程*/
    //sht30_collect();

    int count = 1;
    while (count++)
    {
        /*LED闪烁*/
        rt_pin_write(LED0_PIN, count%2);

        //LOG_D("Hello RT-Thread!");                //不停的打印会影响在终端中打印其他东西，所以注释掉


        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}



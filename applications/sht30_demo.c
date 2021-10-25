/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#include <sht30_demo.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       4096
#define THREAD_TIMESLICE        5

/*线程1*/
static rt_thread_t tid1 = RT_NULL;

rt_uint16_t temperature = 0;
rt_uint16_t humidity = 0;

/*线程的入口函数*/
static void thread_entry(void *parameter)
{
    sht3x_device_t sht3x_device;

    sht3x_device = sht3x_init("i2c1", 0x44);

    if (sht3x_device == RT_NULL)
    {
        return;
    }

    while (1)
    {
        rt_thread_mdelay(2000);
        //成功获取到数据
        if (RT_EOK == sht3x_read_singleshot(sht3x_device))
        {
            temperature = sht3x_device->temperature * 10;
            humidity = sht3x_device->humidity * 10;

//            char *str = malloc(100);
//            rt_sprintf(str, "{\"temp\":%d.%d,\"hum\":%d.%d}\n",
//                    temperature/10, temperature%10, humidity/10, humidity%10);
//            rt_kprintf(str);
//            free(str);
        }
        else
            rt_kprintf("read sht3x data fail\n");
    }
}

int get_temp_hum(rt_uint16_t *temp, rt_uint16_t *hum)
{
    *temp = temperature;
    *hum = humidity;
    return RT_EOK;
}

int sht30_demo()
{
    tid1 = rt_thread_create("thread1", thread_entry, RT_NULL, THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);

    //启动线程
    if (tid1 != RT_NULL)
    {
        rt_thread_startup(tid1);
    }

    return RT_EOK;
}

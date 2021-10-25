/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#include <turbidity.h>
#include <rtdevice.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       4096
#define THREAD_TIMESLICE        5

#define ADC_DEV_NAME        "adc1"      /* ADC 设备名称 */
#define ADC_DEV_CHANNEL     3           /* ADC 通道 */
#define REFER_VOLTAGE       450         /* 参考电压，数据精度乘以100保留2位小数*/
#define CONVERT_BITS        (1 << 12)   /* 转换位数为12位 */

/*线程1*/
static rt_thread_t tid2 = RT_NULL;

rt_uint16_t turbidity_value, turbidity_vol;

/*线程的入口函数*/
static void thread_entry(void *parameter)
{
    rt_adc_device_t adc_dev;
    rt_err_t ret = RT_EOK;

    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
    if (adc_dev == RT_NULL)
    {
        rt_kprintf("adc sample run failed! can't find %s device!\n", ADC_DEV_NAME);
    }

    /* 使能设备 */
    ret = rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
    if(ret == RT_EOK)
    {
        rt_kprintf("adc sample run success!  find %s device!\n", ADC_DEV_NAME);
    }

    while(1)
    {
        /* 读取采样值 */
        turbidity_value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);
        /* 转换为对应电压值 */
        turbidity_vol = turbidity_value * REFER_VOLTAGE / CONVERT_BITS;

//        rt_kprintf("the value is :%d \n", value);
//        rt_kprintf("the voltage is :%d.%02d \n", vol / 100, vol % 100);

        rt_thread_delay(2000);
    }
}

int get_turbidity(rt_uint16_t *turbidity)
{
    // 保留1位小数，就先扩大10倍
    *turbidity = (100-(double)turbidity_vol/4.5)*10;
    return RT_EOK;
}

int turbidity_demo()
{
    tid2 = rt_thread_create("thread2", thread_entry, RT_NULL, THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);

    //启动线程
    if (tid2 != RT_NULL)
    {
        rt_thread_startup(tid2);
    }

    return RT_EOK;
}

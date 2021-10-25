/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#include <pcf8591.h>

rt_uint8_t pcf8591_dat[3] = {0};

/* 写传感器寄存器 */
rt_err_t pcf8591_send_cmd(struct rt_i2c_bus_device *i2c_bus, rt_uint8_t reg)
{
    struct rt_i2c_msg msgs;

    msgs.addr = PCF8591Addr_W;
    msgs.flags = RT_I2C_WR;
    msgs.buf = (rt_uint8_t*)&reg;
    msgs.len = 1;

    /* 调用I2C设备接口传输数据 */
    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
    {
        return RT_EOK;
    }
    else
    {
        return -RT_ERROR;
    }
}

/* 读传感器寄存器数据 */
rt_err_t pcf8591_read_dat(struct rt_i2c_bus_device *i2c_bus, rt_uint8_t addr, rt_uint8_t *buf)
{
    struct rt_i2c_msg msgs;

    msgs.addr = PCF8591Addr_W;
    msgs.flags = RT_I2C_RD;     /* i2c_bit_send_address源码中会对读标志自动或1，所以这里还是用的是PCF8591Addr_W */
    msgs.buf = buf;
    msgs.len = 1;

    /* 调用I2C设备接口传输数据 */
    if (rt_i2c_transfer(i2c_bus, &msgs, 1) == 1)
    {
        return RT_EOK;
    }
    else
    {
        return -RT_ERROR;
    }
}

int get_pcf8591_value(rt_uint16_t *value1, rt_uint16_t *value2)
{
    *value1 = pcf8591_dat[0];
    *value2 = pcf8591_dat[1];

    return RT_EOK;
}

/*线程的入口函数*/
void thread_entry(void *parameter)
{
    struct rt_i2c_bus_device *i2c_bus = RT_NULL;     /* I2C总线设备句柄 */

    /* 查找I2C总线设备，获取I2C总线设备句柄 */
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find(PCF8591_I2C_BUS_NAME);

    if (i2c_bus == RT_NULL)
    {
        rt_kprintf("can't find %s device!\n", PCF8591_I2C_BUS_NAME);
    }
    while (1)
    {
        rt_thread_mdelay(2000);
        /*
         * PCF8591的ADC转换是
         * 每读出一次，它启动一次转换
         * 转换的结果，在下次，才能读出
         * 所以需要读取两次数据
         * */

        // 切换到0号通道
        pcf8591_send_cmd(i2c_bus, AIN0_ADDR);
        rt_thread_mdelay(200);
        // 获取传感器数据
        pcf8591_read_dat(i2c_bus, AIN0_ADDR, &pcf8591_dat[0]);
        pcf8591_read_dat(i2c_bus, AIN0_ADDR, &pcf8591_dat[0]);

        // 切换到1号通道
        pcf8591_send_cmd(i2c_bus, AIN1_ADDR);
        rt_thread_mdelay(200);
        // 获取传感器数据
        pcf8591_read_dat(i2c_bus, AIN1_ADDR, &pcf8591_dat[1]);
        pcf8591_read_dat(i2c_bus, AIN1_ADDR, &pcf8591_dat[1]);

        // 切换到2号通道
        pcf8591_send_cmd(i2c_bus, AIN2_ADDR);
        rt_thread_mdelay(200);
        // 获取传感器数据
        pcf8591_read_dat(i2c_bus, AIN2_ADDR, &pcf8591_dat[2]);
        pcf8591_read_dat(i2c_bus, AIN2_ADDR, &pcf8591_dat[2]);

    //    for(int i = 0; i < 3; i++)
    //    {
    //        rt_kprintf(" %d ", temp[i]);
    //    }
    //    rt_kprintf("\r");
    }
}

int pcf8591_demo()
{
    rt_thread_t tid = RT_NULL;

    tid = rt_thread_create("thread3", thread_entry, RT_NULL, THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);

    //启动线程
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }

    return RT_EOK;
}

/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#ifndef APPLICATIONS_INCLUDE_PCF8591_H_
#define APPLICATIONS_INCLUDE_PCF8591_H_

/*RT-Thread*/
#include <rtthread.h>
#include <rtdevice.h>

#define PCF8591_I2C_BUS_NAME    "i2c3"      /* 传感器连接的I2C总线设备名称 */
#define PCF8591Addr_W           0x90 >> 1   /* i2c_bit_send_address源码中会对地址进行左移操作，所以这里要右移 */
#define AIN0_ADDR               0x40        /* 从机地址 */
#define AIN1_ADDR               0x41        /* 从机地址 */
#define AIN2_ADDR               0x42        /* 从机地址 */


/*线程*/
#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       4096
#define THREAD_TIMESLICE        5

rt_err_t pcf8591_send_cmd(struct rt_i2c_bus_device *i2c_bus, rt_uint8_t reg);
rt_err_t pcf8591_read_dat(struct rt_i2c_bus_device *i2c_bus, rt_uint8_t addr, rt_uint8_t *buf);
int get_pcf8591_value(rt_uint16_t *value1, rt_uint16_t *value2);
void thread_entry(void *parameter);
int pcf8591_demo();

#endif /* APPLICATIONS_INCLUDE_PCF8591_H_ */

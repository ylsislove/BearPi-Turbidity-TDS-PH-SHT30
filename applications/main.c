/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-20     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <bc28_mqtt.h>
#include <sht30_demo.h>
#include <turbidity.h>
#include <pcf8591.h>

int main(void)
{
    rt_kprintf("Welcome to BearPi-Turbidity-TDS-PH-SHT30\n");
    sht30_demo();
    turbidity_demo();
    pcf8591_demo();

    /* init bc28 model */
    if (bc28_init() < 0)
    {
        rt_kprintf("(BC28) init failed\n");
        return -RT_ERROR;
    }

    /* attach network */
    if (bc28_client_attach() < 0)
    {
        rt_kprintf("(BC28) attach failed\n");
        return -RT_ERROR;
    }

    rt_kprintf("(BC28) attach ok\n");

    /* build mqtt network */
    while (bc28_build_mqtt_network() < 0)
    {
        bc28_mqtt_close();
        rt_kprintf("(BC28) rebuild mqtt network\n");
    }
    rt_kprintf("(BC28) MQTT connect ok\n");

    /* subscribe a topic */
    char topic[256];
    rt_sprintf(topic, "/sensor/BearPi-Turbidity-TDS-PH-SHT30/data");

    bc28_mqtt_subscribe(topic);

    /* publish a topic */
    rt_uint16_t temp = 0;
    rt_uint16_t hum = 0;
    rt_uint16_t turbidity = 0;
    rt_uint16_t ph = 0;
    rt_uint16_t tds = 0;
    char topic_msg[256];
    while(1)
    {
        // 获取湿温度数据
        get_temp_hum(&temp, &hum);
        // 获取浊度数据
        get_turbidity(&turbidity);
        // 获取pcf8591数据
        get_pcf8591_value(&ph, &tds);
        // 计算PH
        double v_ph = ph*5.0/255;
        ph = (14-5.122*(v_ph-1.758))*100;   // 乘100是后面可以保留两位有效数字
        // 计算TDS
        double v_tds = tds*2.3/255;
        double T_x = 1.0+0.02*((double)temp/10-25);
        double V_x = T_x*v_tds;
        tds = (66.71*V_x*V_x*V_x-127.93*V_x*V_x+428.7*V_x);
        rt_sprintf(topic_msg, "{\"temp\":%d.%d,\"hum\":%d.%d,\"tur\":%d.%d,\"ph\":%d.%02d,\"tds\":%d}",
                temp/10, temp%10,
                hum/10, hum%10,
                turbidity/10, turbidity%10,
                ph/100, ph%100,
                tds);
        rt_kprintf(topic_msg);
        if (bc28_mqtt_publish(topic, topic_msg) < 0)
        {
            rt_kprintf("(BC28) rebuild mqtt network\n");
            while (bc28_rebuild_mqtt_network() < 0);
        }
        rt_thread_mdelay(60*1000);
    }

    return RT_EOK;
}

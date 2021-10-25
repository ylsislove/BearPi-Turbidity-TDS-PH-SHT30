/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#ifndef APPLICATIONS_INCLUDE_SHT30_DEMO_H_
#define APPLICATIONS_INCLUDE_SHT30_DEMO_H_

/*RT-Thread*/
#include <rtthread.h>
/*私人*/
#include <sht3x.h>

int get_temp_hum(rt_uint16_t *temp, rt_uint16_t *hum);
int sht30_demo();

#endif /* APPLICATIONS_INCLUDE_SHT30_DEMO_H_ */

/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-21     Administrator       the first version
 */
#ifndef APPLICATIONS_INCLUDE_TURBIDITY_H_
#define APPLICATIONS_INCLUDE_TURBIDITY_H_

/*RT-Thread*/
#include <rtthread.h>

int get_turbidity(rt_uint16_t *turbidity);
int turbidity_demo();

#endif /* APPLICATIONS_INCLUDE_TURBIDITY_H_ */

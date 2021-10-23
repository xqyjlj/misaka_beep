/**
 * @file beep.h
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-08-02
 * @copyright Copyright © 2021-2021 xqyjlj<xqyjlj@126.com>
 * @SPDX-License-Identifier: Apache-2.0
 *
 * ********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-08-02 <td>0.0     <td>xqyjlj  <td>内容
 * </table>
 * ********************************************************************************
 */

#ifndef __BEEP_H__
#define __BEEP_H__

#include "stdint.h"

typedef struct
{
	uint32_t continue_time;            /**> 鸣叫持续时间 */
	uint32_t beep_cnt;                /**> 颜色1计数器 */
	uint16_t period_cnt;            /**> 颜色2计数器 */
	uint16_t cnt;                    /**> 闪烁计数器 */
	uint8_t endless_flag;            /**> 无尽模式 */
	uint16_t time_base;                /**> 时间基数 */
} misaka_beep_struct;

/**
 * @brief 设置蜂鸣器引脚
 * @param status 0:不响 1:响
 */
void misaka_beep_set_pin(uint8_t status);

/**
 * @brief 蜂鸣器初始化
 * @param time_base 时基
 */
void misaka_beep_init(uint16_t time_base);

/**
 * @brief 设置蜂鸣器模式
 * @param beep_time 响时间
 * @param nbeep_time 不响时间
 * @param cnt 次数
 * @param endless_flag 无尽模式
 */
void misaka_beep_set_mode(uint32_t beep_time, uint32_t nbeep_time, uint16_t cnt, uint8_t endless_flag);

/**
 * @brief 周期处理函数
 */
void misaka_beep_process();

#endif

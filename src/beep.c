/**
 * @file beep.c
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
#include "misaka_device/beep.h"

static misaka_beep_struct s_misaka_beep = {0};

/**
 * @brief 蜂鸣器初始化
 * @param time_base 时基
 */
void misaka_beep_init(uint16_t time_base)
{
	s_misaka_beep.continue_time = 0;
	s_misaka_beep.beep_cnt = 0;
	s_misaka_beep.period_cnt = 0;
	s_misaka_beep.cnt = 0;
	s_misaka_beep.time_base = time_base;
	s_misaka_beep.endless_flag = 0;
	misaka_beep_set_pin(0);
}

/**
 * @brief 设置蜂鸣器模式
 * @param beep_time 响时间
 * @param nbeep_time 不响时间
 * @param cnt 次数
 * @param endless_flag 无尽模式
 */
void misaka_beep_set_mode(uint32_t beep_time, uint32_t nbeep_time, uint16_t cnt, uint8_t endless_flag)
{
	s_misaka_beep.beep_cnt = beep_time / s_misaka_beep.time_base;
	s_misaka_beep.period_cnt = s_misaka_beep.beep_cnt + (nbeep_time / s_misaka_beep.time_base);
	s_misaka_beep.cnt = cnt;
	s_misaka_beep.continue_time = cnt * s_misaka_beep.period_cnt;
	s_misaka_beep.endless_flag = endless_flag;
}

/**
 * @brief 周期处理函数
 */
void misaka_beep_process()
{
	if (s_misaka_beep.continue_time >= 1)
	{
		s_misaka_beep.continue_time--;
	}
	else
	{
		misaka_beep_set_pin(0);
	}

	if (s_misaka_beep.continue_time != 0 /**> 总时间未清0 */
	    || s_misaka_beep.endless_flag == 1) /**> 判断无尽模式是否开启*/
	{
		s_misaka_beep.cnt++;
		if (s_misaka_beep.cnt <= s_misaka_beep.beep_cnt)
		{
			misaka_beep_set_pin(1);
		}
		else if (s_misaka_beep.cnt > s_misaka_beep.beep_cnt && s_misaka_beep.cnt <= s_misaka_beep.period_cnt)
		{
			misaka_beep_set_pin(0);
		}
		else
		{
			s_misaka_beep.cnt = 0;
		}
	}
}

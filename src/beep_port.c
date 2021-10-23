/**
 * @file beep_port.c
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
#include "main.h"

/**
 * @brief 设置蜂鸣器引脚
 * @param status 0:不响 1:响
 */
void misaka_beep_set_pin(uint8_t status)
{
    if (status == 0)
    {
        LL_GPIO_ResetOutputPin(BEEP_GPIO_Port, BEEP_Pin);
    }
    else
    {
        LL_GPIO_SetOutputPin(BEEP_GPIO_Port, BEEP_Pin);
    }
}
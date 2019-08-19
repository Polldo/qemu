/*
 * QEMU model of the CRP APB control registers for clock controller.
 *
 * Copyright (c) 2016 Xilinx Inc.
 *
 * Partly autogenerated by xregqemu.py 2016-08-19.
 * Written by Edgar E. Iglesias.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "qemu/config-file.h"
#include "qemu/option.h"
#include "sysemu/sysemu.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"

#include "hw/fdt_generic_util.h"

#ifndef XILINX_CRP_ERR_DEBUG
#define XILINX_CRP_ERR_DEBUG 0
#endif

#define TYPE_XILINX_CRP "xlnx,pmc-clk-rst"

#define XILINX_CRP(obj) \
     OBJECT_CHECK(CRP, (obj), TYPE_XILINX_CRP)

REG32(ERR_CTRL, 0x0)
    FIELD(ERR_CTRL, SLVERR_ENABLE, 0, 1)
REG32(IR_STATUS, 0x4)
    FIELD(IR_STATUS, ADDR_DECODE_ERR, 0, 1)
REG32(IR_MASK, 0x8)
    FIELD(IR_MASK, ADDR_DECODE_ERR, 0, 1)
REG32(IR_ENABLE, 0xc)
    FIELD(IR_ENABLE, ADDR_DECODE_ERR, 0, 1)
REG32(IR_DISABLE, 0x10)
    FIELD(IR_DISABLE, ADDR_DECODE_ERR, 0, 1)
REG32(WPROT, 0x1c)
    FIELD(WPROT, ACTIVE, 0, 1)
REG32(PLL_CLK_OTHER_DMN, 0x20)
    FIELD(PLL_CLK_OTHER_DMN, RPLL_BYPASS, 1, 1)
    FIELD(PLL_CLK_OTHER_DMN, APLL_BYPASS, 0, 1)
REG32(PMCPLL_CTRL, 0x40)
    FIELD(PMCPLL_CTRL, POST_SRC, 24, 3)
    FIELD(PMCPLL_CTRL, PRE_SRC, 20, 3)
    FIELD(PMCPLL_CTRL, CLKOUTDIV, 16, 2)
    FIELD(PMCPLL_CTRL, FBDIV, 8, 8)
    FIELD(PMCPLL_CTRL, BYPASS, 3, 1)
    FIELD(PMCPLL_CTRL, RESET, 0, 1)
REG32(PMCPLL_CFG, 0x44)
    FIELD(PMCPLL_CFG, LOCK_DLY, 25, 7)
    FIELD(PMCPLL_CFG, LOCK_CNT, 13, 10)
    FIELD(PMCPLL_CFG, LFHF, 10, 2)
    FIELD(PMCPLL_CFG, CP, 5, 4)
    FIELD(PMCPLL_CFG, RES, 0, 4)
REG32(PMCPLL_FRAC_CFG, 0x48)
    FIELD(PMCPLL_FRAC_CFG, ENABLED, 31, 1)
    FIELD(PMCPLL_FRAC_CFG, SEED, 22, 3)
    FIELD(PMCPLL_FRAC_CFG, ALGRTHM, 19, 1)
    FIELD(PMCPLL_FRAC_CFG, ORDER, 18, 1)
    FIELD(PMCPLL_FRAC_CFG, DATA, 0, 16)
REG32(NOCPLL_CTRL, 0x50)
    FIELD(NOCPLL_CTRL, POST_SRC, 24, 3)
    FIELD(NOCPLL_CTRL, PRE_SRC, 20, 3)
    FIELD(NOCPLL_CTRL, CLKOUTDIV, 16, 2)
    FIELD(NOCPLL_CTRL, FBDIV, 8, 8)
    FIELD(NOCPLL_CTRL, BYPASS, 3, 1)
    FIELD(NOCPLL_CTRL, RESET, 0, 1)
REG32(NOCPLL_CFG, 0x54)
    FIELD(NOCPLL_CFG, LOCK_DLY, 25, 7)
    FIELD(NOCPLL_CFG, LOCK_CNT, 13, 10)
    FIELD(NOCPLL_CFG, LFHF, 10, 2)
    FIELD(NOCPLL_CFG, CP, 5, 4)
    FIELD(NOCPLL_CFG, RES, 0, 4)
REG32(NOCPLL_FRAC_CFG, 0x58)
    FIELD(NOCPLL_FRAC_CFG, ENABLED, 31, 1)
    FIELD(NOCPLL_FRAC_CFG, SEED, 22, 3)
    FIELD(NOCPLL_FRAC_CFG, ALGRTHM, 19, 1)
    FIELD(NOCPLL_FRAC_CFG, ORDER, 18, 1)
    FIELD(NOCPLL_FRAC_CFG, DATA, 0, 16)
REG32(PLL_STATUS, 0x60)
    FIELD(PLL_STATUS, NOCPLL_STABLE, 3, 1)
    FIELD(PLL_STATUS, PMCPLL_STABLE, 2, 1)
    FIELD(PLL_STATUS, NOCPLL_LOCK, 1, 1)
    FIELD(PLL_STATUS, PMCPLL_LOCK, 0, 1)
REG32(PPLL_TO_XPD_CTRL, 0x100)
    FIELD(PPLL_TO_XPD_CTRL, CLKACT, 25, 1)
    FIELD(PPLL_TO_XPD_CTRL, DIVISOR0, 8, 10)
REG32(NPLL_TO_XPD_CTRL, 0x104)
    FIELD(NPLL_TO_XPD_CTRL, CLKACT, 25, 1)
    FIELD(NPLL_TO_XPD_CTRL, DIVISOR0, 8, 10)
REG32(CFU_REF_CTRL, 0x108)
    FIELD(CFU_REF_CTRL, CLKACT, 25, 1)
    FIELD(CFU_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(CFU_REF_CTRL, SRCSEL, 0, 3)
REG32(SPARE_REF_CTRL, 0x110)
    FIELD(SPARE_REF_CTRL, CLKACT, 25, 1)
    FIELD(SPARE_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SPARE_REF_CTRL, SRCSEL, 0, 3)
REG32(NPI_REF_CTRL, 0x114)
    FIELD(NPI_REF_CTRL, CLKACT, 25, 1)
    FIELD(NPI_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(NPI_REF_CTRL, SRCSEL, 0, 3)
REG32(QSPI_REF_CTRL, 0x118)
    FIELD(QSPI_REF_CTRL, CLKACT, 24, 1)
    FIELD(QSPI_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(QSPI_REF_CTRL, SRCSEL, 0, 3)
REG32(OSPI_REF_CTRL, 0x120)
    FIELD(OSPI_REF_CTRL, CLKACT, 24, 1)
    FIELD(OSPI_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(OSPI_REF_CTRL, SRCSEL, 0, 3)
REG32(SDIO0_REF_CTRL, 0x124)
    FIELD(SDIO0_REF_CTRL, CLKACT, 24, 1)
    FIELD(SDIO0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SDIO0_REF_CTRL, SRCSEL, 0, 3)
REG32(SDIO1_REF_CTRL, 0x128)
    FIELD(SDIO1_REF_CTRL, CLKACT, 24, 1)
    FIELD(SDIO1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SDIO1_REF_CTRL, SRCSEL, 0, 3)
REG32(PMC_LSBUS_REF_CTRL, 0x12c)
    FIELD(PMC_LSBUS_REF_CTRL, CLKACT, 24, 1)
    FIELD(PMC_LSBUS_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PMC_LSBUS_REF_CTRL, SRCSEL, 0, 3)
REG32(I2C_REF_CTRL, 0x130)
    FIELD(I2C_REF_CTRL, CLKACT, 24, 1)
    FIELD(I2C_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(I2C_REF_CTRL, SRCSEL, 0, 3)
REG32(EFUSE_REF_CTRL, 0x134)
    FIELD(EFUSE_REF_CTRL, SRCSEL, 2, 1)
REG32(SYSMON_REF_CTRL, 0x138)
    FIELD(SYSMON_REF_CTRL, SRCSEL, 2, 1)
REG32(USB_SUSPEND_CTRL, 0x140)
    FIELD(USB_SUSPEND_CTRL, DIVISOR0, 8, 10)
REG32(SWITCH_TIMEOUT_CTRL, 0x144)
    FIELD(SWITCH_TIMEOUT_CTRL, DIVISOR0, 8, 10)
REG32(HSM0_REF_CTRL, 0x148)
    FIELD(HSM0_REF_CTRL, CLKACT, 25, 1)
    FIELD(HSM0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(HSM0_REF_CTRL, SRCSEL, 0, 3)
REG32(HSM1_REF_CTRL, 0x14c)
    FIELD(HSM1_REF_CTRL, CLKACT, 25, 1)
    FIELD(HSM1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(HSM1_REF_CTRL, SRCSEL, 0, 3)
REG32(SAFETY_CHK, 0x150)
REG32(SD_DLL_REF_CTRL, 0x160)
    FIELD(SD_DLL_REF_CTRL, CLKACT, 25, 1)
    FIELD(SD_DLL_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SD_DLL_REF_CTRL, SRCSEL, 0, 3)
REG32(BOOT_MODE_USER, 0x200)
    FIELD(BOOT_MODE_USER, ALT_BOOT_MODE, 12, 4)
    FIELD(BOOT_MODE_USER, USE_ALT, 8, 1)
    FIELD(BOOT_MODE_USER, BOOT_MODE, 0, 4)
REG32(BOOT_MODE_POR, 0x204)
    FIELD(BOOT_MODE_POR, BOOT_MODE2, 8, 4)
    FIELD(BOOT_MODE_POR, BOOT_MODE1, 4, 4)
    FIELD(BOOT_MODE_POR, BOOT_MODE0, 0, 4)
REG32(RESET_REASON, 0x220)
    FIELD(RESET_REASON, SLR_SYS, 10, 1)
    FIELD(RESET_REASON, SW_SYS, 9, 1)
    FIELD(RESET_REASON, ERR_SYS, 8, 1)
    FIELD(RESET_REASON, DAP_SYS, 7, 1)
    FIELD(RESET_REASON, ERR_POR, 3, 1)
    FIELD(RESET_REASON, SLR_POR, 2, 1)
    FIELD(RESET_REASON, SW_POR, 1, 1)
    FIELD(RESET_REASON, EXTERNAL_POR, 0, 1)
REG32(CLKMON_STATUS, 0x240)
    FIELD(CLKMON_STATUS, CNTA7_OVER_ERR, 15, 1)
    FIELD(CLKMON_STATUS, MON7_ERR, 14, 1)
    FIELD(CLKMON_STATUS, CNTA6_OVER_ERR, 13, 1)
    FIELD(CLKMON_STATUS, MON6_ERR, 12, 1)
    FIELD(CLKMON_STATUS, CNTA5_OVER_ERR, 11, 1)
    FIELD(CLKMON_STATUS, MON5_ERR, 10, 1)
    FIELD(CLKMON_STATUS, CNTA4_OVER_ERR, 9, 1)
    FIELD(CLKMON_STATUS, MON4_ERR, 8, 1)
    FIELD(CLKMON_STATUS, CNTA3_OVER_ERR, 7, 1)
    FIELD(CLKMON_STATUS, MON3_ERR, 6, 1)
    FIELD(CLKMON_STATUS, CNTA2_OVER_ERR, 5, 1)
    FIELD(CLKMON_STATUS, MON2_ERR, 4, 1)
    FIELD(CLKMON_STATUS, CNTA1_OVER_ERR, 3, 1)
    FIELD(CLKMON_STATUS, MON1_ERR, 2, 1)
    FIELD(CLKMON_STATUS, CNTA0_OVER_ERR, 1, 1)
    FIELD(CLKMON_STATUS, MON0_ERR, 0, 1)
REG32(CLKMON_MASK, 0x244)
    FIELD(CLKMON_MASK, CNTA7_OVER_ERR, 15, 1)
    FIELD(CLKMON_MASK, MON7_ERR, 14, 1)
    FIELD(CLKMON_MASK, CNTA6_OVER_ERR, 13, 1)
    FIELD(CLKMON_MASK, MON6_ERR, 12, 1)
    FIELD(CLKMON_MASK, CNTA5_OVER_ERR, 11, 1)
    FIELD(CLKMON_MASK, MON5_ERR, 10, 1)
    FIELD(CLKMON_MASK, CNTA4_OVER_ERR, 9, 1)
    FIELD(CLKMON_MASK, MON4_ERR, 8, 1)
    FIELD(CLKMON_MASK, CNTA3_OVER_ERR, 7, 1)
    FIELD(CLKMON_MASK, MON3_ERR, 6, 1)
    FIELD(CLKMON_MASK, CNTA2_OVER_ERR, 5, 1)
    FIELD(CLKMON_MASK, MON2_ERR, 4, 1)
    FIELD(CLKMON_MASK, CNTA1_OVER_ERR, 3, 1)
    FIELD(CLKMON_MASK, MON1_ERR, 2, 1)
    FIELD(CLKMON_MASK, CNTA0_OVER_ERR, 1, 1)
    FIELD(CLKMON_MASK, MON0_ERR, 0, 1)
REG32(CLKMON_ENABLE, 0x248)
    FIELD(CLKMON_ENABLE, CNTA7_OVER_ERR, 15, 1)
    FIELD(CLKMON_ENABLE, MON7_ERR, 14, 1)
    FIELD(CLKMON_ENABLE, CNTA6_OVER_ERR, 13, 1)
    FIELD(CLKMON_ENABLE, MON6_ERR, 12, 1)
    FIELD(CLKMON_ENABLE, CNTA5_OVER_ERR, 11, 1)
    FIELD(CLKMON_ENABLE, MON5_ERR, 10, 1)
    FIELD(CLKMON_ENABLE, CNTA4_OVER_ERR, 9, 1)
    FIELD(CLKMON_ENABLE, MON4_ERR, 8, 1)
    FIELD(CLKMON_ENABLE, CNTA3_OVER_ERR, 7, 1)
    FIELD(CLKMON_ENABLE, MON3_ERR, 6, 1)
    FIELD(CLKMON_ENABLE, CNTA2_OVER_ERR, 5, 1)
    FIELD(CLKMON_ENABLE, MON2_ERR, 4, 1)
    FIELD(CLKMON_ENABLE, CNTA1_OVER_ERR, 3, 1)
    FIELD(CLKMON_ENABLE, MON1_ERR, 2, 1)
    FIELD(CLKMON_ENABLE, CNTA0_OVER_ERR, 1, 1)
    FIELD(CLKMON_ENABLE, MON0_ERR, 0, 1)
REG32(CLKMON_DISABLE, 0x24c)
    FIELD(CLKMON_DISABLE, CNTA7_OVER_ERR, 15, 1)
    FIELD(CLKMON_DISABLE, MON7_ERR, 14, 1)
    FIELD(CLKMON_DISABLE, CNTA6_OVER_ERR, 13, 1)
    FIELD(CLKMON_DISABLE, MON6_ERR, 12, 1)
    FIELD(CLKMON_DISABLE, CNTA5_OVER_ERR, 11, 1)
    FIELD(CLKMON_DISABLE, MON5_ERR, 10, 1)
    FIELD(CLKMON_DISABLE, CNTA4_OVER_ERR, 9, 1)
    FIELD(CLKMON_DISABLE, MON4_ERR, 8, 1)
    FIELD(CLKMON_DISABLE, CNTA3_OVER_ERR, 7, 1)
    FIELD(CLKMON_DISABLE, MON3_ERR, 6, 1)
    FIELD(CLKMON_DISABLE, CNTA2_OVER_ERR, 5, 1)
    FIELD(CLKMON_DISABLE, MON2_ERR, 4, 1)
    FIELD(CLKMON_DISABLE, CNTA1_OVER_ERR, 3, 1)
    FIELD(CLKMON_DISABLE, MON1_ERR, 2, 1)
    FIELD(CLKMON_DISABLE, CNTA0_OVER_ERR, 1, 1)
    FIELD(CLKMON_DISABLE, MON0_ERR, 0, 1)
REG32(CLKMON_TRIGGER, 0x250)
    FIELD(CLKMON_TRIGGER, CNTA7_OVER_ERR, 15, 1)
    FIELD(CLKMON_TRIGGER, MON7_ERR, 14, 1)
    FIELD(CLKMON_TRIGGER, CNTA6_OVER_ERR, 13, 1)
    FIELD(CLKMON_TRIGGER, MON6_ERR, 12, 1)
    FIELD(CLKMON_TRIGGER, CNTA5_OVER_ERR, 11, 1)
    FIELD(CLKMON_TRIGGER, MON5_ERR, 10, 1)
    FIELD(CLKMON_TRIGGER, CNTA4_OVER_ERR, 9, 1)
    FIELD(CLKMON_TRIGGER, MON4_ERR, 8, 1)
    FIELD(CLKMON_TRIGGER, CNTA3_OVER_ERR, 7, 1)
    FIELD(CLKMON_TRIGGER, MON3_ERR, 6, 1)
    FIELD(CLKMON_TRIGGER, CNTA2_OVER_ERR, 5, 1)
    FIELD(CLKMON_TRIGGER, MON2_ERR, 4, 1)
    FIELD(CLKMON_TRIGGER, CNTA1_OVER_ERR, 3, 1)
    FIELD(CLKMON_TRIGGER, MON1_ERR, 2, 1)
    FIELD(CLKMON_TRIGGER, CNTA0_OVER_ERR, 1, 1)
    FIELD(CLKMON_TRIGGER, MON0_ERR, 0, 1)
REG32(CHKR0_CLKA_UPPER, 0x260)
REG32(CHKR0_CLKA_LOWER, 0x264)
REG32(CHKR0_CLKB_CNT, 0x268)
REG32(CHKR0_CTRL, 0x26c)
    FIELD(CHKR0_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR0_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR0_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR0_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR0_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR0_CTRL, ENABLE, 0, 1)
REG32(CHKR1_CLKA_UPPER, 0x270)
REG32(CHKR1_CLKA_LOWER, 0x274)
REG32(CHKR1_CLKB_CNT, 0x278)
REG32(CHKR1_CTRL, 0x27c)
    FIELD(CHKR1_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR1_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR1_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR1_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR1_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR1_CTRL, ENABLE, 0, 1)
REG32(CHKR2_CLKA_UPPER, 0x280)
REG32(CHKR2_CLKA_LOWER, 0x284)
REG32(CHKR2_CLKB_CNT, 0x288)
REG32(CHKR2_CTRL, 0x28c)
    FIELD(CHKR2_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR2_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR2_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR2_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR2_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR2_CTRL, ENABLE, 0, 1)
REG32(CHKR3_CLKA_UPPER, 0x290)
REG32(CHKR3_CLKA_LOWER, 0x294)
REG32(CHKR3_CLKB_CNT, 0x298)
REG32(CHKR3_CTRL, 0x29c)
    FIELD(CHKR3_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR3_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR3_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR3_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR3_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR3_CTRL, ENABLE, 0, 1)
REG32(CHKR4_CLKA_UPPER, 0x2a0)
REG32(CHKR4_CLKA_LOWER, 0x2a4)
REG32(CHKR4_CLKB_CNT, 0x2a8)
REG32(CHKR4_CTRL, 0x2ac)
    FIELD(CHKR4_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR4_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR4_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR4_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR4_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR4_CTRL, ENABLE, 0, 1)
REG32(CHKR5_CLKA_UPPER, 0x2b0)
REG32(CHKR5_CLKA_LOWER, 0x2b4)
REG32(CHKR5_CLKB_CNT, 0x2b8)
REG32(CHKR5_CTRL, 0x2bc)
    FIELD(CHKR5_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR5_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR5_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR5_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR5_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR5_CTRL, ENABLE, 0, 1)
REG32(CHKR6_CLKA_UPPER, 0x2c0)
REG32(CHKR6_CLKA_LOWER, 0x2c4)
REG32(CHKR6_CLKB_CNT, 0x2c8)
REG32(CHKR6_CTRL, 0x2cc)
    FIELD(CHKR6_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR6_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR6_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR6_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR6_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR6_CTRL, ENABLE, 0, 1)
REG32(CHKR7_CLKA_UPPER, 0x2d0)
REG32(CHKR7_CLKA_LOWER, 0x2d4)
REG32(CHKR7_CLKB_CNT, 0x2d8)
REG32(CHKR7_CTRL, 0x2dc)
    FIELD(CHKR7_CTRL, IDLE_STATE, 10, 1)
    FIELD(CHKR7_CTRL, START_SINGLE, 9, 1)
    FIELD(CHKR7_CTRL, START_CONTINUOUS, 8, 1)
    FIELD(CHKR7_CTRL, CLKB_MUX_CTRL, 6, 1)
    FIELD(CHKR7_CTRL, CLKA_MUX_CTRL, 1, 4)
    FIELD(CHKR7_CTRL, ENABLE, 0, 1)
REG32(RST_QSPI, 0x300)
    FIELD(RST_QSPI, RESET, 0, 1)
REG32(RST_OSPI, 0x304)
    FIELD(RST_OSPI, RESET, 0, 1)
REG32(RST_SDIO0, 0x308)
    FIELD(RST_SDIO0, RESET, 0, 1)
REG32(RST_SDIO1, 0x30c)
    FIELD(RST_SDIO1, RESET, 0, 1)
REG32(RST_I2C, 0x314)
    FIELD(RST_I2C, RESET, 0, 1)
REG32(RST_GPIO, 0x318)
    FIELD(RST_GPIO, RESET, 0, 1)
REG32(RST_PS, 0x31c)
    FIELD(RST_PS, PMC_POR, 7, 1)
    FIELD(RST_PS, PS_POR, 6, 1)
    FIELD(RST_PS, PL_POR, 5, 1)
    FIELD(RST_PS, PMC_SRST, 3, 1)
    FIELD(RST_PS, PS_SRST, 2, 1)
    FIELD(RST_PS, PL_SRST, 1, 1)
REG32(RST_NONPS, 0x320)
    FIELD(RST_NONPS, NOC_RESET, 6, 1)
    FIELD(RST_NONPS, NOC_POR, 5, 1)
    FIELD(RST_NONPS, NPI_RESET, 4, 1)
    FIELD(RST_NONPS, SYS_RST_1, 2, 1)
    FIELD(RST_NONPS, SYS_RST_2, 1, 1)
    FIELD(RST_NONPS, SYS_RST_3, 0, 1)
REG32(RST_SBI, 0x324)
    FIELD(RST_SBI, RESET, 0, 1)
REG32(RST_PDMA, 0x328)
    FIELD(RST_PDMA, RESET1, 1, 1)
    FIELD(RST_PDMA, RESET0, 0, 1)
REG32(RST_SYSMON, 0x32c)
    FIELD(RST_SYSMON, SEQ_RST, 1, 1)
    FIELD(RST_SYSMON, CFG_RST, 0, 1)
REG32(RST_PL, 0x330)
    FIELD(RST_PL, RESET3, 3, 1)
    FIELD(RST_PL, RESET2, 2, 1)
    FIELD(RST_PL, RESET1, 1, 1)
    FIELD(RST_PL, RESET0, 0, 1)
REG32(RST_USB, 0x334)
    FIELD(RST_USB, PHY_RST, 0, 1)
REG32(RST_DBG, 0x400)
    FIELD(RST_DBG, DPC, 1, 1)
    FIELD(RST_DBG, RESET, 0, 1)
REG32(PMC_PL0_REF_CTRL, 0x5c0)
    FIELD(PMC_PL0_REF_CTRL, CLKACT, 24, 1)
    FIELD(PMC_PL0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PMC_PL0_REF_CTRL, SRCSEL, 0, 3)
REG32(PMC_PL1_REF_CTRL, 0x5c4)
    FIELD(PMC_PL1_REF_CTRL, CLKACT, 24, 1)
    FIELD(PMC_PL1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PMC_PL1_REF_CTRL, SRCSEL, 0, 3)
REG32(PMC_PL2_REF_CTRL, 0x5c8)
    FIELD(PMC_PL2_REF_CTRL, CLKACT, 24, 1)
    FIELD(PMC_PL2_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PMC_PL2_REF_CTRL, SRCSEL, 0, 3)
REG32(PMC_PL3_REF_CTRL, 0x5cc)
    FIELD(PMC_PL3_REF_CTRL, CLKACT, 24, 1)
    FIELD(PMC_PL3_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PMC_PL3_REF_CTRL, SRCSEL, 0, 3)

#define R_MAX (R_PMC_PL3_REF_CTRL + 1)

typedef struct CRP {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_ir;
    qemu_irq irq_clkmon;

    qemu_irq rst_qspi;
    qemu_irq rst_ospi;
    qemu_irq rst_sdio[2];
    qemu_irq rst_i2c;
    qemu_irq rst_gpio;

    qemu_irq rst_ps_pl_srst;
    qemu_irq rst_ps_ps_srst;
    qemu_irq rst_ps_pmc_srst;
    qemu_irq rst_ps_pl_por;
    qemu_irq rst_ps_ps_por;
    qemu_irq rst_ps_pmc_por;

    qemu_irq rst_nonps_sys3;
    qemu_irq rst_nonps_sys2;
    qemu_irq rst_nonps_sys1;
    qemu_irq rst_nonps_npi;
    qemu_irq rst_nonps_noc_por;
    qemu_irq rst_nonps_noc;

    qemu_irq rst_sbi;
    qemu_irq rst_pdma[2];
    qemu_irq rst_sysmon_cfg;
    qemu_irq rst_sysmon_seq;
    qemu_irq rst_pl[4];
    qemu_irq rst_usb;
    qemu_irq rst_dbg;
    qemu_irq rst_dbg_dpc;

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} CRP;

static void ir_update_irq(CRP *s)
{
    bool pending = s->regs[R_IR_STATUS] & ~s->regs[R_IR_MASK];
    qemu_set_irq(s->irq_ir, pending);
}

static void ir_status_postw(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    ir_update_irq(s);
}

static uint64_t ir_enable_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IR_MASK] &= ~val;
    ir_update_irq(s);
    return 0;
}

static uint64_t ir_disable_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IR_MASK] |= val;
    ir_update_irq(s);
    return 0;
}

static void clkmon_update_irq(CRP *s)
{
    bool pending = s->regs[R_CLKMON_STATUS] & ~s->regs[R_CLKMON_MASK];
    qemu_set_irq(s->irq_clkmon, pending);
}

static void clkmon_status_postw(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    clkmon_update_irq(s);
}

static uint64_t clkmon_enable_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    s->regs[R_CLKMON_MASK] &= ~val;
    clkmon_update_irq(s);
    return 0;
}

static uint64_t clkmon_disable_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    s->regs[R_CLKMON_MASK] |= val;
    clkmon_update_irq(s);
    return 0;
}

static uint64_t clkmon_trigger_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    s->regs[R_CLKMON_STATUS] |= val;
    clkmon_update_irq(s);
    return 0;
}

static void update_boot_mode_user(CRP *s)
{
    unsigned int boot_mode;
    bool use_alt;

    /* Select between the alternative SW controlled boot mode or the
     * HW sampled boot select pins in BOOT_MODE_POR.
     */
    use_alt = ARRAY_FIELD_EX32(s->regs, BOOT_MODE_USER, USE_ALT);
    if (use_alt) {
        boot_mode = ARRAY_FIELD_EX32(s->regs, BOOT_MODE_USER, ALT_BOOT_MODE);
    } else {
        boot_mode = ARRAY_FIELD_EX32(s->regs, BOOT_MODE_POR, BOOT_MODE0);
    }
    ARRAY_FIELD_DP32(s->regs, BOOT_MODE_USER, BOOT_MODE, boot_mode);
}

static void boot_mode_user_postw(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    update_boot_mode_user(s);
}

#define PROPAGATE_GPIO(reg, f, irq) {             \
    bool val = ARRAY_FIELD_EX32(s->regs, reg, f); \
    qemu_set_irq(irq, val);                       \
}

static void crp_update_gpios(CRP *s)
{
    PROPAGATE_GPIO(RST_QSPI, RESET, s->rst_qspi);
    PROPAGATE_GPIO(RST_OSPI, RESET, s->rst_ospi);
    PROPAGATE_GPIO(RST_SDIO0, RESET, s->rst_sdio[0]);
    PROPAGATE_GPIO(RST_SDIO1, RESET, s->rst_sdio[1]);
    PROPAGATE_GPIO(RST_I2C, RESET, s->rst_i2c);
    PROPAGATE_GPIO(RST_GPIO, RESET, s->rst_gpio);

    PROPAGATE_GPIO(RST_PS, PL_SRST, s->rst_ps_pl_srst);
    PROPAGATE_GPIO(RST_PS, PS_SRST, s->rst_ps_ps_srst);
    PROPAGATE_GPIO(RST_PS, PMC_SRST, s->rst_ps_pmc_srst);
    PROPAGATE_GPIO(RST_PS, PL_POR, s->rst_ps_pl_por);
    PROPAGATE_GPIO(RST_PS, PS_POR, s->rst_ps_ps_por);
    PROPAGATE_GPIO(RST_PS, PMC_POR, s->rst_ps_pmc_por);

    PROPAGATE_GPIO(RST_NONPS, SYS_RST_3, s->rst_nonps_sys3);
    PROPAGATE_GPIO(RST_NONPS, SYS_RST_2, s->rst_nonps_sys2);
    PROPAGATE_GPIO(RST_NONPS, SYS_RST_1, s->rst_nonps_sys1);
    PROPAGATE_GPIO(RST_NONPS, NPI_RESET, s->rst_nonps_npi);
    PROPAGATE_GPIO(RST_NONPS, NOC_POR, s->rst_nonps_noc_por);
    PROPAGATE_GPIO(RST_NONPS, NOC_RESET, s->rst_nonps_noc);

    PROPAGATE_GPIO(RST_SBI, RESET, s->rst_sbi);
    PROPAGATE_GPIO(RST_PDMA, RESET0, s->rst_pdma[0]);
    PROPAGATE_GPIO(RST_PDMA, RESET1, s->rst_pdma[1]);
    PROPAGATE_GPIO(RST_SYSMON, CFG_RST, s->rst_sysmon_cfg);
    PROPAGATE_GPIO(RST_SYSMON, SEQ_RST, s->rst_sysmon_seq);
    PROPAGATE_GPIO(RST_PL, RESET0, s->rst_pl[0]);
    PROPAGATE_GPIO(RST_PL, RESET1, s->rst_pl[0]);
    PROPAGATE_GPIO(RST_PL, RESET2, s->rst_pl[0]);
    PROPAGATE_GPIO(RST_PL, RESET3, s->rst_pl[0]);
    PROPAGATE_GPIO(RST_USB, PHY_RST, s->rst_usb);
    PROPAGATE_GPIO(RST_DBG, RESET, s->rst_dbg);
    PROPAGATE_GPIO(RST_DBG, DPC, s->rst_dbg_dpc);
}

static void crp_update_gpios_pw(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    crp_update_gpios(s);
}

static uint64_t rst_ps_prew(RegisterInfo *reg, uint64_t val64)
{
    CRP *s = XILINX_CRP(reg->opaque);
    uint32_t val = val64;

    ARRAY_FIELD_DP32(s->regs, RESET_REASON, SW_SYS,
                ARRAY_FIELD_EX32(s->regs, RESET_REASON, SW_SYS) |
                !!(val & (R_RST_PS_PMC_SRST_MASK |
                          R_RST_PS_PS_SRST_MASK |
                          R_RST_PS_PL_SRST_MASK)));
    ARRAY_FIELD_DP32(s->regs, RESET_REASON, SW_POR,
                ARRAY_FIELD_EX32(s->regs, RESET_REASON, SW_POR) |
                !!(val & (R_RST_PS_PMC_POR_MASK |
                          R_RST_PS_PS_POR_MASK |
                          R_RST_PS_PL_POR_MASK)));
    return val64;
}

static RegisterAccessInfo crp_regs_info[] = {
    {   .name = "ERR_CTRL",  .addr = A_ERR_CTRL,
    },{ .name = "IR_STATUS",  .addr = A_IR_STATUS,
        .w1c = 0x1,
        .post_write = ir_status_postw,
    },{ .name = "IR_MASK",  .addr = A_IR_MASK,
        .reset = 0x1,
        .ro = 0x1,
    },{ .name = "IR_ENABLE",  .addr = A_IR_ENABLE,
        .pre_write = ir_enable_prew,
    },{ .name = "IR_DISABLE",  .addr = A_IR_DISABLE,
        .pre_write = ir_disable_prew,
    },{ .name = "WPROT",  .addr = A_WPROT,
    },{ .name = "PLL_CLK_OTHER_DMN",  .addr = A_PLL_CLK_OTHER_DMN,
        .reset = 0x3,
        .rsvd = 0xc,
    },{ .name = "PMCPLL_CTRL",  .addr = A_PMCPLL_CTRL,
        .reset = 0x24809,
        .rsvd = 0xf88c00f6,
    },{ .name = "PMCPLL_CFG",  .addr = A_PMCPLL_CFG,
        .reset = 0x2000000,
        .rsvd = 0x1801210,
    },{ .name = "PMCPLL_FRAC_CFG",  .addr = A_PMCPLL_FRAC_CFG,
        .rsvd = 0x7e330000,
    },{ .name = "NOCPLL_CTRL",  .addr = A_NOCPLL_CTRL,
        .reset = 0x24809,
        .rsvd = 0xf88c00f6,
    },{ .name = "NOCPLL_CFG",  .addr = A_NOCPLL_CFG,
        .reset = 0x2000000,
        .rsvd = 0x1801210,
    },{ .name = "NOCPLL_FRAC_CFG",  .addr = A_NOCPLL_FRAC_CFG,
        .rsvd = 0x7e330000,
    },{ .name = "PLL_STATUS",  .addr = A_PLL_STATUS,
        .reset = R_PLL_STATUS_PMCPLL_LOCK_MASK |
                 R_PLL_STATUS_NOCPLL_LOCK_MASK |
                 R_PLL_STATUS_PMCPLL_STABLE_MASK |
                 R_PLL_STATUS_NOCPLL_STABLE_MASK,
        .rsvd = 0xf0,
        .ro = 0xf,
    },{ .name = "PPLL_TO_XPD_CTRL",  .addr = A_PPLL_TO_XPD_CTRL,
        .reset = 0x2000100,
        .rsvd = 0xfdfc00ff,
    },{ .name = "NPLL_TO_XPD_CTRL",  .addr = A_NPLL_TO_XPD_CTRL,
        .reset = 0x2000100,
        .rsvd = 0xfdfc00ff,
    },{ .name = "CFU_REF_CTRL",  .addr = A_CFU_REF_CTRL,
        .reset = 0x2000300,
        .rsvd = 0xfdfc00f8,
    },{ .name = "SPARE_REF_CTRL",  .addr = A_SPARE_REF_CTRL,
        .reset = 0x200,
        .rsvd = 0xfdfc00f8,
    },{ .name = "NPI_REF_CTRL",  .addr = A_NPI_REF_CTRL,
        .reset = 0x400,
        .rsvd = 0xfdfc00f8,
    },{ .name = "QSPI_REF_CTRL",  .addr = A_QSPI_REF_CTRL,
        .reset = 0x1000400,
        .rsvd = 0xfefc00f8,
    },{ .name = "OSPI_REF_CTRL",  .addr = A_OSPI_REF_CTRL,
        .reset = 0x1000400,
        .rsvd = 0xfefc00f8,
    },{ .name = "SDIO0_REF_CTRL",  .addr = A_SDIO0_REF_CTRL,
        .reset = 0x1000600,
        .rsvd = 0xfefc00f8,
    },{ .name = "SDIO1_REF_CTRL",  .addr = A_SDIO1_REF_CTRL,
        .reset = 0x1000600,
        .rsvd = 0xfefc00f8,
    },{ .name = "PMC_LSBUS_REF_CTRL",  .addr = A_PMC_LSBUS_REF_CTRL,
        .reset = 0x1000800,
        .rsvd = 0xfefc00f8,
    },{ .name = "I2C_REF_CTRL",  .addr = A_I2C_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfefc00f8,
    },{ .name = "EFUSE_REF_CTRL",  .addr = A_EFUSE_REF_CTRL,
        .rsvd = 0xb,
    },{ .name = "SYSMON_REF_CTRL",  .addr = A_SYSMON_REF_CTRL,
        .rsvd = 0xb,
    },{ .name = "USB_SUSPEND_CTRL",  .addr = A_USB_SUSPEND_CTRL,
        .reset = 0x1f400,
        .rsvd = 0xfffc00ff,
    },{ .name = "SWITCH_TIMEOUT_CTRL",  .addr = A_SWITCH_TIMEOUT_CTRL,
        .reset = 0x6400,
        .rsvd = 0xfffc00ff,
    },{ .name = "HSM0_REF_CTRL",  .addr = A_HSM0_REF_CTRL,
        .reset = 0x2000,
        .rsvd = 0xfdfc00f8,
    },{ .name = "HSM1_REF_CTRL",  .addr = A_HSM1_REF_CTRL,
        .reset = 0x2000,
        .rsvd = 0xfdfc00f8,
    },{ .name = "SAFETY_CHK",  .addr = A_SAFETY_CHK,
    },{ .name = "SD_DLL_REF_CTRL",  .addr = A_SD_DLL_REF_CTRL,
        .reset = 0x100,
        .rsvd = 0xfdfc00f8,
    },{ .name = "BOOT_MODE_USER",  .addr = A_BOOT_MODE_USER,
        .rsvd = 0xf0ef0,
        .ro = 0xf,
        .post_write = boot_mode_user_postw,
    },{ .name = "BOOT_MODE_POR",  .addr = A_BOOT_MODE_POR,
        .rsvd = 0xf000,
        .ro = 0xfff,
    },{ .name = "RESET_REASON",  .addr = A_RESET_REASON,
        .reset = 0x1,
        .rsvd = 0xf870,
        .ro = 0xf870,
        .w1c = 0x78f,
    },{ .name = "CLKMON_STATUS",  .addr = A_CLKMON_STATUS,
        .w1c = 0xffff,
        .post_write = clkmon_status_postw,
    },{ .name = "CLKMON_MASK",  .addr = A_CLKMON_MASK,
        .reset = 0xffff,
        .ro = 0xffff,
    },{ .name = "CLKMON_ENABLE",  .addr = A_CLKMON_ENABLE,
        .pre_write = clkmon_enable_prew,
    },{ .name = "CLKMON_DISABLE",  .addr = A_CLKMON_DISABLE,
        .pre_write = clkmon_disable_prew,
    },{ .name = "CLKMON_TRIGGER",  .addr = A_CLKMON_TRIGGER,
        .pre_write = clkmon_trigger_prew,
    },{ .name = "CHKR0_CLKA_UPPER",  .addr = A_CHKR0_CLKA_UPPER,
    },{ .name = "CHKR0_CLKA_LOWER",  .addr = A_CHKR0_CLKA_LOWER,
    },{ .name = "CHKR0_CLKB_CNT",  .addr = A_CHKR0_CLKB_CNT,
    },{ .name = "CHKR0_CTRL",  .addr = A_CHKR0_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR1_CLKA_UPPER",  .addr = A_CHKR1_CLKA_UPPER,
    },{ .name = "CHKR1_CLKA_LOWER",  .addr = A_CHKR1_CLKA_LOWER,
    },{ .name = "CHKR1_CLKB_CNT",  .addr = A_CHKR1_CLKB_CNT,
    },{ .name = "CHKR1_CTRL",  .addr = A_CHKR1_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR2_CLKA_UPPER",  .addr = A_CHKR2_CLKA_UPPER,
    },{ .name = "CHKR2_CLKA_LOWER",  .addr = A_CHKR2_CLKA_LOWER,
    },{ .name = "CHKR2_CLKB_CNT",  .addr = A_CHKR2_CLKB_CNT,
    },{ .name = "CHKR2_CTRL",  .addr = A_CHKR2_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR3_CLKA_UPPER",  .addr = A_CHKR3_CLKA_UPPER,
    },{ .name = "CHKR3_CLKA_LOWER",  .addr = A_CHKR3_CLKA_LOWER,
    },{ .name = "CHKR3_CLKB_CNT",  .addr = A_CHKR3_CLKB_CNT,
    },{ .name = "CHKR3_CTRL",  .addr = A_CHKR3_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR4_CLKA_UPPER",  .addr = A_CHKR4_CLKA_UPPER,
    },{ .name = "CHKR4_CLKA_LOWER",  .addr = A_CHKR4_CLKA_LOWER,
    },{ .name = "CHKR4_CLKB_CNT",  .addr = A_CHKR4_CLKB_CNT,
    },{ .name = "CHKR4_CTRL",  .addr = A_CHKR4_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR5_CLKA_UPPER",  .addr = A_CHKR5_CLKA_UPPER,
    },{ .name = "CHKR5_CLKA_LOWER",  .addr = A_CHKR5_CLKA_LOWER,
    },{ .name = "CHKR5_CLKB_CNT",  .addr = A_CHKR5_CLKB_CNT,
    },{ .name = "CHKR5_CTRL",  .addr = A_CHKR5_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR6_CLKA_UPPER",  .addr = A_CHKR6_CLKA_UPPER,
    },{ .name = "CHKR6_CLKA_LOWER",  .addr = A_CHKR6_CLKA_LOWER,
    },{ .name = "CHKR6_CLKB_CNT",  .addr = A_CHKR6_CLKB_CNT,
    },{ .name = "CHKR6_CTRL",  .addr = A_CHKR6_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "CHKR7_CLKA_UPPER",  .addr = A_CHKR7_CLKA_UPPER,
    },{ .name = "CHKR7_CLKA_LOWER",  .addr = A_CHKR7_CLKA_LOWER,
    },{ .name = "CHKR7_CLKB_CNT",  .addr = A_CHKR7_CLKB_CNT,
    },{ .name = "CHKR7_CTRL",  .addr = A_CHKR7_CTRL,
        .reset = 0x400,
        .rsvd = 0xa0,
        .ro = 0x400,
    },{ .name = "RST_QSPI",  .addr = A_RST_QSPI,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_OSPI",  .addr = A_RST_OSPI,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_SDIO0",  .addr = A_RST_SDIO0,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_SDIO1",  .addr = A_RST_SDIO1,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_I2C",  .addr = A_RST_I2C,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_GPIO",  .addr = A_RST_GPIO,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_PS",  .addr = A_RST_PS,
        .reset = 0x66,
        .rsvd = 0x11,
        .pre_write = rst_ps_prew,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_NONPS",  .addr = A_RST_NONPS,
        .reset = 0x77,
        .rsvd = 0x88,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_SBI",  .addr = A_RST_SBI,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_PDMA",  .addr = A_RST_PDMA,
        .reset = 0x3,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_SYSMON",  .addr = A_RST_SYSMON,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_PL",  .addr = A_RST_PL,
        .reset = 0xf,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_USB",  .addr = A_RST_USB,
        .reset = 0x1,
        .post_write = crp_update_gpios_pw,
    },{ .name = "RST_DBG",  .addr = A_RST_DBG,
        .reset = 0x3,
        .post_write = crp_update_gpios_pw,
    },{ .name = "PMC_PL0_REF_CTRL",  .addr = A_PMC_PL0_REF_CTRL,
        .reset = 0x500,
        .rsvd = 0xfefc00f8,
    },{ .name = "PMC_PL1_REF_CTRL",  .addr = A_PMC_PL1_REF_CTRL,
        .reset = 0x500,
        .rsvd = 0xfefc00f8,
    },{ .name = "PMC_PL2_REF_CTRL",  .addr = A_PMC_PL2_REF_CTRL,
        .reset = 0x500,
        .rsvd = 0xfefc00f8,
    },{ .name = "PMC_PL3_REF_CTRL",  .addr = A_PMC_PL3_REF_CTRL,
        .reset = 0x500,
        .rsvd = 0xfefc00f8,
    }
};

static void crp_reset(DeviceState *dev)
{
    CRP *s = XILINX_CRP(dev);
    QemuOpts *opts = qemu_find_opts_singleton("boot-opts");
    uint32_t boot_mode = qemu_opt_get_number(opts, "mode", 0);
    unsigned int i;
    hwaddr addr;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        if (s->regs_info[i].access) {
            addr = s->regs_info[i].access->addr;
        } else {
            continue;
        }
        switch (addr) {
        case A_RESET_REASON:
        case A_RST_PS:
            continue;
        default:
            register_reset(&s->regs_info[i]);
        }
    }

    /* PMC is made out of reset automatically by hardware */
    if (ARRAY_FIELD_EX32(s->regs, RST_PS, PMC_SRST) ||
        ARRAY_FIELD_EX32(s->regs, RST_PS, PMC_POR)) {
        ARRAY_FIELD_DP32(s->regs, RST_PS, PMC_SRST, 0);
        ARRAY_FIELD_DP32(s->regs, RST_PS, PMC_POR, 0);

       /* TODO: Issue PS and PL resets */
    }

    s->regs[R_BOOT_MODE_POR] = boot_mode;
    update_boot_mode_user(s);

    ir_update_irq(s);
    clkmon_update_irq(s);
    crp_update_gpios(s);
}

static const MemoryRegionOps crp_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void crp_init(Object *obj)
{
    CRP *s = XILINX_CRP(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_CRP, R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), crp_regs_info,
                              ARRAY_SIZE(crp_regs_info),
                              s->regs_info, s->regs,
                              &crp_ops,
                              XILINX_CRP_ERR_DEBUG,
                              R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_ir);
    sysbus_init_irq(sbd, &s->irq_clkmon);

    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_qspi, "rst-qspi", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ospi, "rst-ospi", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sdio[0], "rst-sdio0", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sdio[1], "rst-sdio1", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_i2c, "rst-i2c", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_gpio, "rst-gpio", 1);

    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_pl_srst,
                             "rst-ps-pl-srst", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_ps_srst,
                             "rst-ps-ps-srst", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_pmc_srst,
                             "rst-ps-pmc-srst", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_pl_por,
                             "rst-ps-pl-por", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_ps_por,
                             "rst-ps-ps-por", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ps_pmc_por,
                             "rst-ps-pmc-por", 1);

    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_sys3,
                             "rst-nonps-sys3", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_sys2,
                             "rst-nonps-sys2", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_sys1,
                             "rst-nonps-sys1", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_npi,
                             "rst-nonps-npi", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_noc_por,
                             "rst-nonps-noc-por", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_nonps_noc,
                             "rst-nonps-noc", 1);

    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sbi, "rst-sbi", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_pdma, "rst-pdma", 2);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sysmon_cfg,
                             "rst-sysmon-cfg", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sysmon_seq,
                             "rst-sysmon-seq", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_pl, "rst-pl", 4);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_usb, "rst-usb", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg, "rst-dbg-reset", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg_dpc, "rst-dbg-dpc", 1);

}

static const VMStateDescription vmstate_crp = {
    .name = TYPE_XILINX_CRP,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, CRP, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet crp_gpios[] = {
    {
      .names = &fdt_generic_gpio_name_set_gpio,
      .gpios = (FDTGenericGPIOConnection[]) {
        { .name = "rst-qspi", .fdt_index = 0, .range = 1 },
        { .name = "rst-ospi", .fdt_index = 1, .range = 1 },
        /*
         * To avoid breaking backwards compatibility, we keep
         * PMC-SRST at index 2 and put SDIO0 and index 8.
         */
        { .name = "rst-ps-pmc-srst", .fdt_index = 2, .range = 1 },
        { .name = "rst-sdio1", .fdt_index = 3, .range = 1 },
        { .name = "rst-i2c", .fdt_index = 4, .range = 1 },
        { .name = "rst-gpio", .fdt_index = 5, .range = 1 },

        { .name = "rst-ps-pl-srst", .fdt_index = 6, .range = 1 },
        { .name = "rst-ps-ps-srst", .fdt_index = 7, .range = 1 },
        /* SDIO0 at index 8, see above.  */
        { .name = "rst-sdio0", .fdt_index = 8, .range = 1 },
        { .name = "rst-ps-pl-por", .fdt_index = 9, .range = 1 },
        { .name = "rst-ps-ps-por", .fdt_index = 10, .range = 1 },
        { .name = "rst-ps-pmc-por", .fdt_index = 11, .range = 1 },

        { .name = "rst-nonps-sys3", .fdt_index = 12, .range = 1 },
        { .name = "rst-nonps-sys2", .fdt_index = 13, .range = 1 },
        { .name = "rst-nonps-sys1", .fdt_index = 14, .range = 1 },
        { .name = "rst-nonps-npi", .fdt_index = 15, .range = 1 },
        { .name = "rst-nonps-noc-por", .fdt_index = 16, .range = 1 },
        { .name = "rst-nonps-noc", .fdt_index = 17, .range = 1 },

        { .name = "rst-sbi", .fdt_index = 18, .range = 1 },
        { .name = "rst-pdma", .fdt_index = 19, .range = 2 },
        { .name = "rst-sysmon-cfg", .fdt_index = 21, .range = 1 },
        { .name = "rst-sysmon-seq", .fdt_index = 22, .range = 1 },
        { .name = "rst-pl", .fdt_index = 23, .range = 4 },
        { .name = "rst-usb", .fdt_index = 27, .range = 1 },
        { .name = "rst-dbg-reset", .fdt_index = 28, .range = 1 },
        { .name = "rst-dbg-dpc", .fdt_index = 29, .range = 1 },
        { },
      },
    },
    { },
};

static void crp_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = crp_reset;
    dc->vmsd = &vmstate_crp;
    fggc->controller_gpios = crp_gpios;
}

static const TypeInfo crp_info = {
    .name          = TYPE_XILINX_CRP,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(CRP),
    .class_init    = crp_class_init,
    .instance_init = crp_init,
    .interfaces = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void crp_register_types(void)
{
    type_register_static(&crp_info);
}

type_init(crp_register_types)

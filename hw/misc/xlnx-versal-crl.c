/*
 * QEMU model of the CRL APB control registers for clock controller.
 *
 * Copyright (c) 2018 Xilinx Inc.
 *
 * Partially autogenerated by xregqemu.py 2018-07-20.
 * xregqemu.py -fname xlnx-versal-crl.c -typename xlnx,versal-crl \
 * -statetypename Zynq3CRL clk_rst_lpd.ods
 *
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

#include "hw/fdt_generic_util.h"

#ifndef XILINX_CRL_ERR_DEBUG
#define XILINX_CRL_ERR_DEBUG 0
#endif

#define TYPE_XILINX_CRL "xlnx,versal-crl"

#define XILINX_CRL(obj) \
     OBJECT_CHECK(Zynq3CRL, (obj), TYPE_XILINX_CRL)

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
    FIELD(PLL_CLK_OTHER_DMN, APLL_BYPASS, 0, 1)
REG32(RPLL_CTRL, 0x40)
    FIELD(RPLL_CTRL, POST_SRC, 24, 3)
    FIELD(RPLL_CTRL, PRE_SRC, 20, 3)
    FIELD(RPLL_CTRL, CLKOUTDIV, 16, 2)
    FIELD(RPLL_CTRL, FBDIV, 8, 8)
    FIELD(RPLL_CTRL, BYPASS, 3, 1)
    FIELD(RPLL_CTRL, RESET, 0, 1)
REG32(RPLL_CFG, 0x44)
    FIELD(RPLL_CFG, LOCK_DLY, 25, 7)
    FIELD(RPLL_CFG, LOCK_CNT, 13, 10)
    FIELD(RPLL_CFG, LFHF, 10, 2)
    FIELD(RPLL_CFG, CP, 5, 4)
    FIELD(RPLL_CFG, RES, 0, 4)
REG32(RPLL_FRAC_CFG, 0x48)
    FIELD(RPLL_FRAC_CFG, ENABLED, 31, 1)
    FIELD(RPLL_FRAC_CFG, SEED, 22, 3)
    FIELD(RPLL_FRAC_CFG, ALGRTHM, 19, 1)
    FIELD(RPLL_FRAC_CFG, ORDER, 18, 1)
    FIELD(RPLL_FRAC_CFG, DATA, 0, 16)
REG32(PLL_STATUS, 0x50)
    FIELD(PLL_STATUS, RPLL_STABLE, 2, 1)
    FIELD(PLL_STATUS, RPLL_LOCK, 0, 1)
REG32(RPLL_TO_XPD_CTRL, 0x100)
    FIELD(RPLL_TO_XPD_CTRL, CLKACT, 25, 1)
    FIELD(RPLL_TO_XPD_CTRL, DIVISOR0, 8, 10)
REG32(LPD_TOP_SWITCH_CTRL, 0x104)
    FIELD(LPD_TOP_SWITCH_CTRL, CLKACT_ADMA, 26, 1)
    FIELD(LPD_TOP_SWITCH_CTRL, CLKACT, 25, 1)
    FIELD(LPD_TOP_SWITCH_CTRL, DIVISOR0, 8, 10)
    FIELD(LPD_TOP_SWITCH_CTRL, SRCSEL, 0, 3)
REG32(LPD_LSBUS_CTRL, 0x108)
    FIELD(LPD_LSBUS_CTRL, CLKACT, 25, 1)
    FIELD(LPD_LSBUS_CTRL, DIVISOR0, 8, 10)
    FIELD(LPD_LSBUS_CTRL, SRCSEL, 0, 3)
REG32(CPU_R5_CTRL, 0x10c)
    FIELD(CPU_R5_CTRL, CLKACT_OCM2, 28, 1)
    FIELD(CPU_R5_CTRL, CLKACT_OCM, 27, 1)
    FIELD(CPU_R5_CTRL, CLKACT_CORE, 26, 1)
    FIELD(CPU_R5_CTRL, CLKACT, 25, 1)
    FIELD(CPU_R5_CTRL, DIVISOR0, 8, 10)
    FIELD(CPU_R5_CTRL, SRCSEL, 0, 3)
REG32(IOU_SWITCH_CTRL, 0x114)
    FIELD(IOU_SWITCH_CTRL, CLKACT, 25, 1)
    FIELD(IOU_SWITCH_CTRL, DIVISOR0, 8, 10)
    FIELD(IOU_SWITCH_CTRL, SRCSEL, 0, 3)
REG32(GEM0_REF_CTRL, 0x118)
    FIELD(GEM0_REF_CTRL, CLKACT_RX, 27, 1)
    FIELD(GEM0_REF_CTRL, CLKACT_TX, 26, 1)
    FIELD(GEM0_REF_CTRL, CLKACT, 25, 1)
    FIELD(GEM0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(GEM0_REF_CTRL, SRCSEL, 0, 3)
REG32(GEM1_REF_CTRL, 0x11c)
    FIELD(GEM1_REF_CTRL, CLKACT_RX, 27, 1)
    FIELD(GEM1_REF_CTRL, CLKACT_TX, 26, 1)
    FIELD(GEM1_REF_CTRL, CLKACT, 25, 1)
    FIELD(GEM1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(GEM1_REF_CTRL, SRCSEL, 0, 3)
REG32(GEM_TSU_REF_CTRL, 0x120)
    FIELD(GEM_TSU_REF_CTRL, CLKACT, 25, 1)
    FIELD(GEM_TSU_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(GEM_TSU_REF_CTRL, SRCSEL, 0, 3)
REG32(USB0_BUS_REF_CTRL, 0x124)
    FIELD(USB0_BUS_REF_CTRL, CLKACT, 25, 1)
    FIELD(USB0_BUS_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(USB0_BUS_REF_CTRL, SRCSEL, 0, 3)
REG32(UART0_REF_CTRL, 0x128)
    FIELD(UART0_REF_CTRL, CLKACT, 25, 1)
    FIELD(UART0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(UART0_REF_CTRL, SRCSEL, 0, 3)
REG32(UART1_REF_CTRL, 0x12c)
    FIELD(UART1_REF_CTRL, CLKACT, 25, 1)
    FIELD(UART1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(UART1_REF_CTRL, SRCSEL, 0, 3)
REG32(SPI0_REF_CTRL, 0x130)
    FIELD(SPI0_REF_CTRL, CLKACT, 25, 1)
    FIELD(SPI0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SPI0_REF_CTRL, SRCSEL, 0, 3)
REG32(SPI1_REF_CTRL, 0x134)
    FIELD(SPI1_REF_CTRL, CLKACT, 25, 1)
    FIELD(SPI1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(SPI1_REF_CTRL, SRCSEL, 0, 3)
REG32(CAN0_REF_CTRL, 0x138)
    FIELD(CAN0_REF_CTRL, CLKACT, 25, 1)
    FIELD(CAN0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(CAN0_REF_CTRL, SRCSEL, 0, 3)
REG32(CAN1_REF_CTRL, 0x13c)
    FIELD(CAN1_REF_CTRL, CLKACT, 25, 1)
    FIELD(CAN1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(CAN1_REF_CTRL, SRCSEL, 0, 3)
REG32(I2C0_REF_CTRL, 0x140)
    FIELD(I2C0_REF_CTRL, CLKACT, 25, 1)
    FIELD(I2C0_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(I2C0_REF_CTRL, SRCSEL, 0, 3)
REG32(I2C1_REF_CTRL, 0x144)
    FIELD(I2C1_REF_CTRL, CLKACT, 25, 1)
    FIELD(I2C1_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(I2C1_REF_CTRL, SRCSEL, 0, 3)
REG32(DBG_LPD_CTRL, 0x148)
    FIELD(DBG_LPD_CTRL, CLKACT, 25, 1)
    FIELD(DBG_LPD_CTRL, DIVISOR0, 8, 10)
    FIELD(DBG_LPD_CTRL, SRCSEL, 0, 3)
REG32(TIMESTAMP_REF_CTRL, 0x14c)
    FIELD(TIMESTAMP_REF_CTRL, CLKACT, 25, 1)
    FIELD(TIMESTAMP_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(TIMESTAMP_REF_CTRL, SRCSEL, 0, 3)
REG32(SAFETY_CHK, 0x150)
REG32(PSM_REF_CTRL, 0x154)
    FIELD(PSM_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(PSM_REF_CTRL, SRCSEL, 0, 3)
REG32(DBG_TSTMP_CTRL, 0x158)
    FIELD(DBG_TSTMP_CTRL, CLKACT, 25, 1)
    FIELD(DBG_TSTMP_CTRL, DIVISOR0, 8, 10)
    FIELD(DBG_TSTMP_CTRL, SRCSEL, 0, 3)
REG32(CPM_TOPSW_REF_CTRL, 0x15c)
    FIELD(CPM_TOPSW_REF_CTRL, CLKACT, 25, 1)
    FIELD(CPM_TOPSW_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(CPM_TOPSW_REF_CTRL, SRCSEL, 0, 3)
REG32(USB3_DUAL_REF_CTRL, 0x160)
    FIELD(USB3_DUAL_REF_CTRL, CLKACT, 25, 1)
    FIELD(USB3_DUAL_REF_CTRL, DIVISOR0, 8, 10)
    FIELD(USB3_DUAL_REF_CTRL, SRCSEL, 0, 3)
REG32(RST_CPU_R5, 0x300)
    FIELD(RST_CPU_R5, RESET_PGE, 4, 1)
    FIELD(RST_CPU_R5, RESET_AMBA, 2, 1)
    FIELD(RST_CPU_R5, RESET_CPU1, 1, 1)
    FIELD(RST_CPU_R5, RESET_CPU0, 0, 1)
REG32(RST_ADMA, 0x304)
    FIELD(RST_ADMA, RESET, 0, 1)
REG32(RST_GEM0, 0x308)
    FIELD(RST_GEM0, RESET, 0, 1)
REG32(RST_GEM1, 0x30c)
    FIELD(RST_GEM1, RESET, 0, 1)
REG32(RST_SPARE, 0x310)
    FIELD(RST_SPARE, RESET, 0, 1)
REG32(RST_USB0, 0x314)
    FIELD(RST_USB0, RESET, 0, 1)
REG32(RST_UART0, 0x318)
    FIELD(RST_UART0, RESET, 0, 1)
REG32(RST_UART1, 0x31c)
    FIELD(RST_UART1, RESET, 0, 1)
REG32(RST_SPI0, 0x320)
    FIELD(RST_SPI0, RESET, 0, 1)
REG32(RST_SPI1, 0x324)
    FIELD(RST_SPI1, RESET, 0, 1)
REG32(RST_CAN0, 0x328)
    FIELD(RST_CAN0, RESET, 0, 1)
REG32(RST_CAN1, 0x32c)
    FIELD(RST_CAN1, RESET, 0, 1)
REG32(RST_I2C0, 0x330)
    FIELD(RST_I2C0, RESET, 0, 1)
REG32(RST_I2C1, 0x334)
    FIELD(RST_I2C1, RESET, 0, 1)
REG32(RST_DBG_LPD, 0x338)
    FIELD(RST_DBG_LPD, RPU_DBG1_RESET, 5, 1)
    FIELD(RST_DBG_LPD, RPU_DBG0_RESET, 4, 1)
    FIELD(RST_DBG_LPD, RESET_HSDP, 1, 1)
    FIELD(RST_DBG_LPD, RESET, 0, 1)
REG32(RST_GPIO, 0x33c)
    FIELD(RST_GPIO, RESET, 0, 1)
REG32(RST_TTC, 0x344)
    FIELD(RST_TTC, TTC3_RESET, 3, 1)
    FIELD(RST_TTC, TTC2_RESET, 2, 1)
    FIELD(RST_TTC, TTC1_RESET, 1, 1)
    FIELD(RST_TTC, TTC0_RESET, 0, 1)
REG32(RST_TIMESTAMP, 0x348)
    FIELD(RST_TIMESTAMP, RESET, 0, 1)
REG32(RST_SWDT, 0x34c)
    FIELD(RST_SWDT, RESET, 0, 1)
REG32(RST_OCM, 0x350)
    FIELD(RST_OCM, RESET, 0, 1)
REG32(RST_IPI, 0x354)
    FIELD(RST_IPI, RESET, 0, 1)
REG32(RST_SYSMON, 0x358)
    FIELD(RST_SYSMON, SEQ_RST, 1, 1)
    FIELD(RST_SYSMON, CFG_RST, 0, 1)
REG32(RST_FPD, 0x360)
    FIELD(RST_FPD, SRST, 1, 1)
    FIELD(RST_FPD, POR, 0, 1)
REG32(PSM_RST_MODE, 0x370)
    FIELD(PSM_RST_MODE, WAKEUP, 2, 1)
    FIELD(PSM_RST_MODE, RST_MODE, 0, 2)

#define CRL_R_MAX (R_PSM_RST_MODE + 1)

typedef struct Zynq3CRL {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_ir;

    qemu_irq rst_adma;
    qemu_irq rst_gem[2];
    qemu_irq rst_spare;
    qemu_irq rst_usb0;
    qemu_irq rst_uart[2];
    qemu_irq rst_spi[2];
    qemu_irq rst_can[2];
    qemu_irq rst_i2c[2];
    qemu_irq rst_dbg_lpd;
    qemu_irq rst_dbg_lpd_hsdp;
    qemu_irq rst_dbg_lpd_rpu0;
    qemu_irq rst_dbg_lpd_rpu1;
    qemu_irq rst_gpio;
    qemu_irq rst_ttc[4];
    qemu_irq rst_timestamp;
    qemu_irq rst_swdt;
    qemu_irq rst_ocm;
    qemu_irq rst_ipi;
    qemu_irq rst_sysmon_cfg;
    qemu_irq rst_sysmon_seq;
    qemu_irq rst_fpd_por;
    qemu_irq rst_fpd_srst;
    qemu_irq psm_sleep;
    qemu_irq psm_wakeup;
    qemu_irq rst_cpu_r5[2];

    uint32_t regs[CRL_R_MAX];
    RegisterInfo regs_info[CRL_R_MAX];
} Zynq3CRL;

static void ir_update_irq(Zynq3CRL *s)
{
    bool pending = s->regs[R_IR_STATUS] & ~s->regs[R_IR_MASK];
    qemu_set_irq(s->irq_ir, pending);
}

static void ir_status_postw(RegisterInfo *reg, uint64_t val64)
{
    Zynq3CRL *s = XILINX_CRL(reg->opaque);
    ir_update_irq(s);
}

static uint64_t ir_enable_prew(RegisterInfo *reg, uint64_t val64)
{
    Zynq3CRL *s = XILINX_CRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IR_MASK] &= ~val;
    ir_update_irq(s);
    return 0;
}

static uint64_t ir_disable_prew(RegisterInfo *reg, uint64_t val64)
{
    Zynq3CRL *s = XILINX_CRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_IR_MASK] |= val;
    ir_update_irq(s);
    return 0;
}

#define PROPAGATE_GPIO(reg, f, irq) { \
    bool val = ARRAY_FIELD_EX32(s->regs, reg, f); \
    qemu_set_irq(irq, val); \
}

static void crl_update_gpios(Zynq3CRL *s)
{
    bool val;

    PROPAGATE_GPIO(RST_CPU_R5, RESET_CPU0, s->rst_cpu_r5[0]);
    PROPAGATE_GPIO(RST_CPU_R5, RESET_CPU1, s->rst_cpu_r5[1]);

    PROPAGATE_GPIO(RST_ADMA, RESET, s->rst_adma);
    PROPAGATE_GPIO(RST_GEM0, RESET, s->rst_gem[0]);
    PROPAGATE_GPIO(RST_GEM1, RESET, s->rst_gem[1]);
    PROPAGATE_GPIO(RST_SPARE, RESET, s->rst_spare);
    PROPAGATE_GPIO(RST_USB0, RESET, s->rst_usb0);
    PROPAGATE_GPIO(RST_UART0, RESET, s->rst_uart[0]);
    PROPAGATE_GPIO(RST_UART1, RESET, s->rst_uart[1]);
    PROPAGATE_GPIO(RST_SPI0, RESET, s->rst_spi[0]);
    PROPAGATE_GPIO(RST_SPI1, RESET, s->rst_spi[1]);
    PROPAGATE_GPIO(RST_CAN0, RESET, s->rst_can[0]);
    PROPAGATE_GPIO(RST_CAN1, RESET, s->rst_can[1]);
    PROPAGATE_GPIO(RST_I2C0, RESET, s->rst_i2c[0]);
    PROPAGATE_GPIO(RST_I2C1, RESET, s->rst_i2c[1]);
    PROPAGATE_GPIO(RST_DBG_LPD, RESET, s->rst_dbg_lpd);
    PROPAGATE_GPIO(RST_DBG_LPD, RESET_HSDP, s->rst_dbg_lpd_hsdp);
    PROPAGATE_GPIO(RST_DBG_LPD, RPU_DBG0_RESET, s->rst_dbg_lpd_rpu0);
    PROPAGATE_GPIO(RST_DBG_LPD, RPU_DBG1_RESET, s->rst_dbg_lpd_rpu1);
    PROPAGATE_GPIO(RST_GPIO, RESET, s->rst_gpio);
    PROPAGATE_GPIO(RST_TTC, TTC0_RESET, s->rst_ttc[0]);
    PROPAGATE_GPIO(RST_TTC, TTC1_RESET, s->rst_ttc[1]);
    PROPAGATE_GPIO(RST_TTC, TTC2_RESET, s->rst_ttc[2]);
    PROPAGATE_GPIO(RST_TTC, TTC3_RESET, s->rst_ttc[3]);
    PROPAGATE_GPIO(RST_TIMESTAMP, RESET, s->rst_timestamp);
    PROPAGATE_GPIO(RST_SWDT, RESET, s->rst_swdt);
    PROPAGATE_GPIO(RST_OCM, RESET, s->rst_ocm);
    PROPAGATE_GPIO(RST_IPI, RESET, s->rst_ipi);
    PROPAGATE_GPIO(RST_SYSMON, CFG_RST, s->rst_sysmon_cfg);
    PROPAGATE_GPIO(RST_SYSMON, SEQ_RST, s->rst_sysmon_seq);
    PROPAGATE_GPIO(RST_FPD, POR, s->rst_fpd_por);
    PROPAGATE_GPIO(RST_FPD, SRST, s->rst_fpd_srst);

    val = ARRAY_FIELD_EX32(s->regs, PSM_RST_MODE, WAKEUP);
    qemu_set_irq(s->psm_sleep, !val);
    qemu_set_irq(s->psm_wakeup, val);
}

static void crl_update_gpios_pw(RegisterInfo *reg, uint64_t val64)
{
    Zynq3CRL *s = XILINX_CRL(reg->opaque);
    crl_update_gpios(s);
}

static const RegisterAccessInfo crl_regs_info[] = {
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
        .reset = 0x1,
        .rsvd = 0xe,
    },{ .name = "RPLL_CTRL",  .addr = A_RPLL_CTRL,
        .reset = 0x24809,
        .rsvd = 0xf88c00f6,
    },{ .name = "RPLL_CFG",  .addr = A_RPLL_CFG,
        .reset = 0x2000000,
        .rsvd = 0x1801210,
    },{ .name = "RPLL_FRAC_CFG",  .addr = A_RPLL_FRAC_CFG,
        .rsvd = 0x7e330000,
    },{ .name = "PLL_STATUS",  .addr = A_PLL_STATUS,
        .reset = R_PLL_STATUS_RPLL_STABLE_MASK |
                 R_PLL_STATUS_RPLL_LOCK_MASK,
        .rsvd = 0xfa,
        .ro = 0x5,
    },{ .name = "RPLL_TO_XPD_CTRL",  .addr = A_RPLL_TO_XPD_CTRL,
        .reset = 0x2000100,
        .rsvd = 0xfdfc00ff,
    },{ .name = "LPD_TOP_SWITCH_CTRL",  .addr = A_LPD_TOP_SWITCH_CTRL,
        .reset = 0x6000300,
        .rsvd = 0xf9fc00f8,
    },{ .name = "LPD_LSBUS_CTRL",  .addr = A_LPD_LSBUS_CTRL,
        .reset = 0x2000800,
        .rsvd = 0xfdfc00f8,
    },{ .name = "CPU_R5_CTRL",  .addr = A_CPU_R5_CTRL,
        .reset = 0xe000300,
        .rsvd = 0xe1fc00f8,
    },{ .name = "IOU_SWITCH_CTRL",  .addr = A_IOU_SWITCH_CTRL,
        .reset = 0x2000500,
        .rsvd = 0xfdfc00f8,
    },{ .name = "GEM0_REF_CTRL",  .addr = A_GEM0_REF_CTRL,
        .reset = 0xe000a00,
        .rsvd = 0xf1fc00f8,
    },{ .name = "GEM1_REF_CTRL",  .addr = A_GEM1_REF_CTRL,
        .reset = 0xe000a00,
        .rsvd = 0xf1fc00f8,
    },{ .name = "GEM_TSU_REF_CTRL",  .addr = A_GEM_TSU_REF_CTRL,
        .reset = 0x300,
        .rsvd = 0xfdfc00f8,
    },{ .name = "USB0_BUS_REF_CTRL",  .addr = A_USB0_BUS_REF_CTRL,
        .reset = 0x2001900,
        .rsvd = 0xfdfc00f8,
    },{ .name = "UART0_REF_CTRL",  .addr = A_UART0_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "UART1_REF_CTRL",  .addr = A_UART1_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "SPI0_REF_CTRL",  .addr = A_SPI0_REF_CTRL,
        .reset = 0x600,
        .rsvd = 0xfdfc00f8,
    },{ .name = "SPI1_REF_CTRL",  .addr = A_SPI1_REF_CTRL,
        .reset = 0x600,
        .rsvd = 0xfdfc00f8,
    },{ .name = "CAN0_REF_CTRL",  .addr = A_CAN0_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "CAN1_REF_CTRL",  .addr = A_CAN1_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "I2C0_REF_CTRL",  .addr = A_I2C0_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "I2C1_REF_CTRL",  .addr = A_I2C1_REF_CTRL,
        .reset = 0xc00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "DBG_LPD_CTRL",  .addr = A_DBG_LPD_CTRL,
        .reset = 0x300,
        .rsvd = 0xfdfc00f8,
    },{ .name = "TIMESTAMP_REF_CTRL",  .addr = A_TIMESTAMP_REF_CTRL,
        .reset = 0x2000c00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "SAFETY_CHK",  .addr = A_SAFETY_CHK,
    },{ .name = "PSM_REF_CTRL",  .addr = A_PSM_REF_CTRL,
        .reset = 0xf04,
        .rsvd = 0xfffc00f8,
    },{ .name = "DBG_TSTMP_CTRL",  .addr = A_DBG_TSTMP_CTRL,
        .reset = 0x300,
        .rsvd = 0xfdfc00f8,
    },{ .name = "CPM_TOPSW_REF_CTRL",  .addr = A_CPM_TOPSW_REF_CTRL,
        .reset = 0x300,
        .rsvd = 0xfdfc00f8,
    },{ .name = "USB3_DUAL_REF_CTRL",  .addr = A_USB3_DUAL_REF_CTRL,
        .reset = 0x3c00,
        .rsvd = 0xfdfc00f8,
    },{ .name = "RST_CPU_R5",  .addr = A_RST_CPU_R5,
        .reset = 0x17,
        .rsvd = 0x8,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_ADMA",  .addr = A_RST_ADMA,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_GEM0",  .addr = A_RST_GEM0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_GEM1",  .addr = A_RST_GEM1,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_SPARE",  .addr = A_RST_SPARE,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_USB0",  .addr = A_RST_USB0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_UART0",  .addr = A_RST_UART0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_UART1",  .addr = A_RST_UART1,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_SPI0",  .addr = A_RST_SPI0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_SPI1",  .addr = A_RST_SPI1,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_CAN0",  .addr = A_RST_CAN0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_CAN1",  .addr = A_RST_CAN1,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_I2C0",  .addr = A_RST_I2C0,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_I2C1",  .addr = A_RST_I2C1,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_DBG_LPD",  .addr = A_RST_DBG_LPD,
        .reset = 0x33,
        .rsvd = 0xcc,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_GPIO",  .addr = A_RST_GPIO,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_TTC",  .addr = A_RST_TTC,
        .reset = 0xf,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_TIMESTAMP",  .addr = A_RST_TIMESTAMP,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_SWDT",  .addr = A_RST_SWDT,
        .reset = 0x1,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_OCM",  .addr = A_RST_OCM,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_IPI",  .addr = A_RST_IPI,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_SYSMON",  .addr = A_RST_SYSMON,
        .post_write = crl_update_gpios_pw,
    },{ .name = "RST_FPD",  .addr = A_RST_FPD,
        .reset = 0x3,
        .post_write = crl_update_gpios_pw,
    },{ .name = "PSM_RST_MODE",  .addr = A_PSM_RST_MODE,
        .reset = 0x1,
        .rsvd = 0xf8,
        .post_write = crl_update_gpios_pw,
    }
};

static void crl_reset(DeviceState *dev)
{
    Zynq3CRL *s = XILINX_CRL(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    ir_update_irq(s);
    crl_update_gpios(s);
}

static const MemoryRegionOps crl_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void crl_realize(DeviceState *dev, Error **errp)
{
    /* Delete this if you don't need it */
}

static void crl_init(Object *obj)
{
    Zynq3CRL *s = XILINX_CRL(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_CRL, CRL_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), crl_regs_info,
                              ARRAY_SIZE(crl_regs_info),
                              s->regs_info, s->regs,
                              &crl_ops,
                              XILINX_CRL_ERR_DEBUG,
                              CRL_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_ir);

    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_adma, "rst-adma", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_gem, "rst-gem", 2);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_spare, "rst-spare", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_usb0, "rst-usb0", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_uart, "rst-uart", 2);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_spi, "rst-spi", 2);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_can, "rst-can", 2);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_i2c, "rst-i2c", 2);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg_lpd, "rst-dbg-lpd", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg_lpd_hsdp,
                             "rst-dbg-lpd-hsdp", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg_lpd_rpu0,
                             "rst-dbg-lpd-rpu0", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_dbg_lpd_rpu1,
                             "rst-dbg-lpd-rpu1", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_gpio, "rst-gpio", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_ttc, "rst-ttc", 4);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_timestamp,
                             "rst-timestamp", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_swdt, "rst-swdt", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ocm, "rst-ocm", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_ipi, "rst-ipi", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sysmon_cfg,
                             "rst-sysmon-cfg", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_sysmon_seq,
                             "rst-sysmon-seq", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_fpd_por, "rst-fpd-por", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->rst_fpd_srst, "rst-fpd-srst", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->psm_sleep, "psm-sleep", 1);
    qdev_init_gpio_out_named(DEVICE(obj), &s->psm_wakeup, "psm-wakeup", 1);
    qdev_init_gpio_out_named(DEVICE(obj), s->rst_cpu_r5, "rst-cpu-r5", 2);
}

static const VMStateDescription vmstate_crl = {
    .name = TYPE_XILINX_CRL,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, Zynq3CRL, CRL_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet crl_gpios[] = {
    {
      .names = &fdt_generic_gpio_name_set_gpio,
      .gpios = (FDTGenericGPIOConnection[]) {
        { .name = "rst-adma", .fdt_index = 0, .range = 1 },
        { .name = "rst-gem", .fdt_index = 1, .range = 2 },
        { .name = "rst-spare", .fdt_index = 3, .range = 1 },
        { .name = "rst-usb0", .fdt_index = 4, .range = 1 },
        { .name = "rst-uart", .fdt_index = 5, .range = 2 },
        { .name = "rst-spi", .fdt_index = 7, .range = 2 },
        { .name = "rst-can", .fdt_index = 9, .range = 2 },
        { .name = "rst-i2c", .fdt_index = 11, .range = 2 },
        { .name = "rst-dbg-lpd", .fdt_index = 13, .range = 1 },
        { .name = "rst-dbg-lpd-hsdp", .fdt_index = 14, .range = 1 },
        { .name = "rst-dbg-lpd-rpu0", .fdt_index = 15, .range = 1 },
        { .name = "rst-dbg-lpd-rpu1", .fdt_index = 16, .range = 1 },
        { .name = "rst-gpio", .fdt_index = 17, .range = 1 },
        { .name = "rst-ttc", .fdt_index = 18, .range = 4 },
        { .name = "rst-timestamp", .fdt_index = 22, .range = 1 },
        { .name = "rst-swdt", .fdt_index = 23, .range = 1 },
        { .name = "rst-ocm", .fdt_index = 24, .range = 1 },
        { .name = "rst-ipi", .fdt_index = 25, .range = 1 },
        { .name = "rst-sysmon-cfg", .fdt_index = 26, .range = 1 },
        { .name = "rst-sysmon-seq", .fdt_index = 27, .range = 1 },
        { .name = "rst-fpd-por", .fdt_index = 28, .range = 1 },
        { .name = "rst-fpd-srst", .fdt_index = 29, .range = 1 },
        { .name = "psm-sleep", .fdt_index = 30, .range = 1 },
        { .name = "psm-wakeup", .fdt_index = 31, .range = 1 },
        { .name = "rst-cpu-r5", .fdt_index = 32, .range = 2 },
        { },
      },
    },
    { },
};

static void crl_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = crl_reset;
    dc->realize = crl_realize;
    dc->vmsd = &vmstate_crl;
    fggc->controller_gpios = crl_gpios;
}

static const TypeInfo crl_info = {
    .name          = TYPE_XILINX_CRL,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(Zynq3CRL),
    .class_init    = crl_class_init,
    .instance_init = crl_init,
    .interfaces = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void crl_register_types(void)
{
    type_register_static(&crl_info);
}

type_init(crl_register_types)

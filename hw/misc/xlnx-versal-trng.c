/*
 * QEMU model of the TRNG True Random Number Generator
 *
 * Copyright (c) 2017 Xilinx Inc.
 *
 * Partially utogenerated by xregqemu.py 2017-01-03.
 * Written by Edgar E. Iglesias <edgar.iglesias@xilinx.com>
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
#include "hw/register-dep.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"

#ifndef XILINX_TRNG_ERR_DEBUG
#define XILINX_TRNG_ERR_DEBUG 0
#endif

#define TYPE_XILINX_TRNG "xlnx.versal-trng"

#define XILINX_TRNG(obj) \
     OBJECT_CHECK(TRNG, (obj), TYPE_XILINX_TRNG)

DEP_REG32(INT_CTRL, 0x0)
    DEP_FIELD(INT_CTRL, CERTF_RST, 1, 5)
    DEP_FIELD(INT_CTRL, DTF_RST, 1, 4)
    DEP_FIELD(INT_CTRL, DONE_RST, 1, 3)
    DEP_FIELD(INT_CTRL, CERTF_EN, 1, 2)
    DEP_FIELD(INT_CTRL, DTF_EN, 1, 1)
    DEP_FIELD(INT_CTRL, DONE_EN, 1, 0)
DEP_REG32(STATUS, 0x4)
    DEP_FIELD(STATUS, QCNT, 3, 9)
    DEP_FIELD(STATUS, EAT, 5, 4)
    DEP_FIELD(STATUS, CERTF, 1, 3)
    DEP_FIELD(STATUS, QERTF, 1, 2)
    DEP_FIELD(STATUS, DFT, 1, 1)
    DEP_FIELD(STATUS, DONE, 1, 0)
DEP_REG32(CTRL, 0x8)
    DEP_FIELD(CTRL, EUMODE, 1, 8)
    DEP_FIELD(CTRL, PRNGMODE, 1, 7)
    DEP_FIELD(CTRL, TSTMODE, 1, 6)
    DEP_FIELD(CTRL, PRNGSTART, 1, 5)
    DEP_FIELD(CTRL, EATAU, 1, 4)
    DEP_FIELD(CTRL, PRNGXS, 1, 3)
    DEP_FIELD(CTRL, TRSSEN, 1, 2)
    DEP_FIELD(CTRL, QERTUEN, 1, 1)
    DEP_FIELD(CTRL, PRNGSRST, 1, 0)
DEP_REG32(EXT_SEED_0, 0x40)
DEP_REG32(EXT_SEED_1, 0x44)
DEP_REG32(EXT_SEED_2, 0x48)
DEP_REG32(EXT_SEED_3, 0x4c)
DEP_REG32(EXT_SEED_4, 0x50)
DEP_REG32(EXT_SEED_5, 0x54)
DEP_REG32(EXT_SEED_6, 0x58)
DEP_REG32(EXT_SEED_7, 0x5c)
DEP_REG32(EXT_SEED_8, 0x60)
DEP_REG32(EXT_SEED_9, 0x64)
DEP_REG32(EXT_SEED_10, 0x68)
DEP_REG32(EXT_SEED_11, 0x6c)
DEP_REG32(PER_STRNG_0, 0x80)
DEP_REG32(PER_STRNG_1, 0x84)
DEP_REG32(PER_STRNG_2, 0x88)
DEP_REG32(PER_STRNG_3, 0x8c)
DEP_REG32(PER_STRNG_4, 0x90)
DEP_REG32(PER_STRNG_5, 0x94)
DEP_REG32(PER_STRNG_6, 0x98)
DEP_REG32(PER_STRNG_7, 0x9c)
DEP_REG32(PER_STRNG_8, 0xa0)
DEP_REG32(PER_STRNG_9, 0xa4)
DEP_REG32(PER_STRNG_10, 0xa8)
DEP_REG32(PER_STRNG_11, 0xac)
DEP_REG32(CORE_OUTPUT, 0xc0)
DEP_REG32(RAND_SEED_VALID, 0xd0)
    DEP_FIELD(RAND_SEED_VALID, VAL, 1, 0)
DEP_REG32(RAND_SEED, 0xd4)
DEP_REG32(RESET, 0xe0)
    DEP_FIELD(RESET, VAL, 1, 0)
DEP_REG32(INT_ISR, 0xf0)
    DEP_FIELD(INT_ISR, VAL, 1, 0)
DEP_REG32(INT_IMR, 0xf4)
    DEP_FIELD(INT_IMR, VAL, 1, 0)
DEP_REG32(INT_IER, 0xf8)
    DEP_FIELD(INT_IER, VAL, 1, 0)
DEP_REG32(INT_IDR, 0xfc)
    DEP_FIELD(INT_IDR, VAL, 1, 0)
DEP_REG32(SLV_ERR_CTRL, 0x100)
    DEP_FIELD(SLV_ERR_CTRL, ENABLE, 1, 0)
DEP_REG32(SLV_ERR_ISR, 0x104)
    DEP_FIELD(SLV_ERR_ISR, VAL, 1, 0)
DEP_REG32(SLV_ERR_IMR, 0x108)
    DEP_FIELD(SLV_ERR_IMR, VAL, 1, 0)
DEP_REG32(SLV_ERR_IER, 0x10c)
    DEP_FIELD(SLV_ERR_IER, VAL, 1, 0)
DEP_REG32(SLV_ERR_IDR, 0x110)
    DEP_FIELD(SLV_ERR_IDR, VAL, 1, 0)
DEP_REG32(SLV_ERR_TRIG, 0x114)
    DEP_FIELD(SLV_ERR_TRIG, VAL, 1, 0)

#define R_MAX (R_SLV_ERR_TRIG + 1)

typedef struct TRNG {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_int_imr;
    qemu_irq irq_slv_err_imr;

    /* Specs say we have 256bits but there's only max 7 words
     * to be indicated in the status reg.  */
    uint32_t out[7];
    uint32_t count;
    unsigned int seed;

    uint32_t regs[R_MAX];
    DepRegisterInfo regs_info[R_MAX];
} TRNG;

static void int_imr_update_irq(TRNG *s)
{
    bool pending;
    bool internal_pending;

    /* Derive the internal interrupt pending signal.  */
    internal_pending = s->regs[R_STATUS] & s->regs[R_INT_CTRL] & 7;
    /* Propagate the internal IRQ signal to the Xilinx wrapper registers.  */
    s->regs[R_INT_ISR] = internal_pending;

    pending = s->regs[R_INT_ISR] & ~s->regs[R_INT_IMR];
    qemu_set_irq(s->irq_int_imr, pending);
}

static void int_isr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    int_imr_update_irq(s);
}

static uint64_t int_ier_prew(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_INT_IMR] &= ~val;
    int_imr_update_irq(s);
    return 0;
}

static uint64_t int_idr_prew(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_INT_IMR] |= val;
    int_imr_update_irq(s);
    return 0;
}

static void slv_err_imr_update_irq(TRNG *s)
{
    bool pending = s->regs[R_SLV_ERR_ISR] & ~s->regs[R_SLV_ERR_IMR];
    qemu_set_irq(s->irq_slv_err_imr, pending);
}

static void slv_err_isr_postw(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    slv_err_imr_update_irq(s);
}

static uint64_t slv_err_ier_prew(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SLV_ERR_IMR] &= ~val;
    slv_err_imr_update_irq(s);
    return 0;
}

static uint64_t slv_err_idr_prew(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SLV_ERR_IMR] |= val;
    slv_err_imr_update_irq(s);
    return 0;
}

static uint64_t slv_err_trig_prew(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t val = val64;

    s->regs[R_SLV_ERR_ISR] |= val;
    slv_err_imr_update_irq(s);
    return 0;
}

static void trng_reset(DeviceState *dev)
{
    TRNG *s = XILINX_TRNG(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        dep_register_reset(&s->regs_info[i]);
    }

    int_imr_update_irq(s);
    slv_err_imr_update_irq(s);
}

static void trng_int_ctrl_postw(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t mask;

    /* DONE and DFT are aligned.  */
    mask = val64 >> 3;
    mask &= 3;
    s->regs[R_STATUS] &= ~mask;

    /* CERTF is off by one bit.  */
    mask = val64 >> 2;
    mask &= 1 << 3;
    s->regs[R_STATUS] &= ~mask;

    int_imr_update_irq(s);
}

static void trng_done(TRNG *s)
{
    DEP_AF_DP32(s->regs, STATUS, DONE, true);
    int_imr_update_irq(s);
}

static inline void trng_reseed(TRNG *s, bool ext)
{
    int i;

    /* Accumulate the seed regs and the personalization string.  */
    s->seed = 0;

    for (i = 0; i < 12; i++) {
        s->seed += s->regs[R_PER_STRNG_0 + i];
    }

    if (ext) {
        for (i = 0; i < 12; i++) {
            s->seed += s->regs[R_EXT_SEED_0 + i];
        }
    }
    srand(s->seed);
}

static inline void trng_regen(TRNG *s)
{
    int i;

    /* Re-gen.  */
    for (i = 0; i < ARRAY_SIZE(s->out); i++) {
        s->out[i] = rand();
    }

    s->count = ARRAY_SIZE(s->out);
    DEP_AF_DP32(s->regs, STATUS, QCNT, s->count);
}

static void trng_ctrl_postw(DepRegisterInfo *reg, uint64_t val64)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    bool start = DEP_F_EX32(val64, CTRL, PRNGSTART);
    bool mode = DEP_F_EX32(val64, CTRL, PRNGMODE);
    bool ext = DEP_F_EX32(val64, CTRL, PRNGXS);
    bool rst = DEP_F_EX32(val64, CTRL, PRNGSRST);

    if (rst) {
        trng_reset(DEVICE(s));
        return;
    }

    if (start) {
        if (mode) {
            trng_regen(s);
        } else {
            trng_reseed(s, ext);
        }
        trng_done(s);
    }
}

static uint64_t trng_core_out_postr(DepRegisterInfo *reg, uint64_t val)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    uint32_t r = s->out[0];
    bool start = DEP_AF_EX32(s->regs, CTRL, PRNGSTART);
    bool rst = DEP_AF_EX32(s->regs, CTRL, PRNGSRST);

    if (rst) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading while in reset!\n");
        return 0xbad;
    }

    if (s->count == 0) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading when unavailable!\n");
        return 0xbad;
    }

    /* Shift.  */
    memmove(&s->out[0], &s->out[1], sizeof s->out - sizeof s->out[0]);
    s->count--;
    DEP_AF_DP32(s->regs, STATUS, QCNT, s->count);

    /* Automatic mode regenerates new entropy when half the output reg
     * is empty.  */
    if (start && s->count <= 3) {
        trng_regen(s);
    }
    return r;
}

/* Read raw entropy.  */
static uint64_t trng_rand_seed_postr(DepRegisterInfo *reg, uint64_t val)
{
    TRNG *s = XILINX_TRNG(reg->opaque);
    bool rst = DEP_AF_EX32(s->regs, CTRL, PRNGSRST);

    if (rst) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading while in reset!\n");
        return 0xbad;
    }

    if (s->count == 0) {
        qemu_log_mask(LOG_GUEST_ERROR, "trng: reading when unavailable!\n");
        return 0xbad;
    }

    return rand();
}

static DepRegisterAccessInfo trng_regs_info[] = {
    {   .name = "INT_CTRL",  .decode.addr = A_INT_CTRL,
        .post_write = trng_int_ctrl_postw,
    },{ .name = "STATUS",  .decode.addr = A_STATUS,
        .ro = 0xfff,
    },{ .name = "CTRL",  .decode.addr = A_CTRL,
        .post_write = trng_ctrl_postw,
    },{ .name = "EXT_SEED_0",  .decode.addr = A_EXT_SEED_0,
    },{ .name = "EXT_SEED_1",  .decode.addr = A_EXT_SEED_1,
    },{ .name = "EXT_SEED_2",  .decode.addr = A_EXT_SEED_2,
    },{ .name = "EXT_SEED_3",  .decode.addr = A_EXT_SEED_3,
    },{ .name = "EXT_SEED_4",  .decode.addr = A_EXT_SEED_4,
    },{ .name = "EXT_SEED_5",  .decode.addr = A_EXT_SEED_5,
    },{ .name = "EXT_SEED_6",  .decode.addr = A_EXT_SEED_6,
    },{ .name = "EXT_SEED_7",  .decode.addr = A_EXT_SEED_7,
    },{ .name = "EXT_SEED_8",  .decode.addr = A_EXT_SEED_8,
    },{ .name = "EXT_SEED_9",  .decode.addr = A_EXT_SEED_9,
    },{ .name = "EXT_SEED_10",  .decode.addr = A_EXT_SEED_10,
    },{ .name = "EXT_SEED_11",  .decode.addr = A_EXT_SEED_11,
    },{ .name = "PER_STRNG_0",  .decode.addr = A_PER_STRNG_0,
    },{ .name = "PER_STRNG_1",  .decode.addr = A_PER_STRNG_1,
    },{ .name = "PER_STRNG_2",  .decode.addr = A_PER_STRNG_2,
    },{ .name = "PER_STRNG_3",  .decode.addr = A_PER_STRNG_3,
    },{ .name = "PER_STRNG_4",  .decode.addr = A_PER_STRNG_4,
    },{ .name = "PER_STRNG_5",  .decode.addr = A_PER_STRNG_5,
    },{ .name = "PER_STRNG_6",  .decode.addr = A_PER_STRNG_6,
    },{ .name = "PER_STRNG_7",  .decode.addr = A_PER_STRNG_7,
    },{ .name = "PER_STRNG_8",  .decode.addr = A_PER_STRNG_8,
    },{ .name = "PER_STRNG_9",  .decode.addr = A_PER_STRNG_9,
    },{ .name = "PER_STRNG_10",  .decode.addr = A_PER_STRNG_10,
    },{ .name = "PER_STRNG_11",  .decode.addr = A_PER_STRNG_11,
    },{ .name = "CORE_OUTPUT",  .decode.addr = A_CORE_OUTPUT,
        .ro = 0xffffffff,
        .post_read = trng_core_out_postr,
    },{ .name = "RAND_SEED_VALID",  .decode.addr = A_RAND_SEED_VALID,
        .ro = 0x1,
        .reset = 1,
    },{ .name = "RAND_SEED",  .decode.addr = A_RAND_SEED,
        .ro = 0xffffffff,
        .post_read = trng_rand_seed_postr,
    },{ .name = "RESET",  .decode.addr = A_RESET,
        .reset = 0x1,
    },{ .name = "INT_ISR",  .decode.addr = A_INT_ISR,
        .w1c = 0x1,
        .post_write = int_isr_postw,
    },{ .name = "INT_IMR",  .decode.addr = A_INT_IMR,
        .reset = 0x1,
        .ro = 0x1,
    },{ .name = "INT_IER",  .decode.addr = A_INT_IER,
        .pre_write = int_ier_prew,
    },{ .name = "INT_IDR",  .decode.addr = A_INT_IDR,
        .pre_write = int_idr_prew,
    },{ .name = "SLV_ERR_CTRL",  .decode.addr = A_SLV_ERR_CTRL,
    },{ .name = "SLV_ERR_ISR",  .decode.addr = A_SLV_ERR_ISR,
        .w1c = 0x1,
        .post_write = slv_err_isr_postw,
    },{ .name = "SLV_ERR_IMR",  .decode.addr = A_SLV_ERR_IMR,
        .ro = 0x1,
    },{ .name = "SLV_ERR_IER",  .decode.addr = A_SLV_ERR_IER,
        .pre_write = slv_err_ier_prew,
    },{ .name = "SLV_ERR_IDR",  .decode.addr = A_SLV_ERR_IDR,
        .pre_write = slv_err_idr_prew,
    },{ .name = "SLV_ERR_TRIG",  .decode.addr = A_SLV_ERR_TRIG,
        .pre_write = slv_err_trig_prew,
    }
};

static uint64_t trng_read(void *opaque, hwaddr addr, unsigned size)
{
    TRNG *s = XILINX_TRNG(opaque);
    DepRegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        return 0;
    }
    return dep_register_read(r);
}

static void trng_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    TRNG *s = XILINX_TRNG(opaque);
    DepRegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, value);
        return;
    }
    dep_register_write(r, value, ~0);
}

static const MemoryRegionOps trng_ops = {
    .read = trng_read,
    .write = trng_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void trng_realize(DeviceState *dev, Error **errp)
{
    TRNG *s = XILINX_TRNG(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(trng_regs_info); ++i) {
        DepRegisterInfo *r = &s->regs_info[trng_regs_info[i].decode.addr / 4];

        *r = (DepRegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    trng_regs_info[i].decode.addr / 4],
            .data_size = sizeof(uint32_t),
            .access = &trng_regs_info[i],
            .debug = XILINX_TRNG_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
    }
}

static void trng_init(Object *obj)
{
    TRNG *s = XILINX_TRNG(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &trng_ops, s,
                          TYPE_XILINX_TRNG, R_MAX * 4);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_int_imr);
    sysbus_init_irq(sbd, &s->irq_slv_err_imr);
}

static const VMStateDescription vmstate_trng = {
    .name = TYPE_XILINX_TRNG,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(out, TRNG, 7),
        VMSTATE_UINT32_ARRAY(regs, TRNG, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void trng_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = trng_reset;
    dc->realize = trng_realize;
    dc->vmsd = &vmstate_trng;
}

static const TypeInfo trng_info = {
    .name          = TYPE_XILINX_TRNG,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(TRNG),
    .class_init    = trng_class_init,
    .instance_init = trng_init,
};

static void trng_register_types(void)
{
    type_register_static(&trng_info);
}

type_init(trng_register_types)

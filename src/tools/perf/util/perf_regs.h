#ifndef __PERF_REGS_H
#define __PERF_REGS_H

#ifdef HAVE_PERF_REGS
#include <perf_regs.h>
#else
#define PERF_REGS_MASK	0
#if defined(__arm__)
enum perf_event_arm_regs {
    PERF_REG_ARM_R0,
    PERF_REG_ARM_R1,
    PERF_REG_ARM_R2,
    PERF_REG_ARM_R3,
    PERF_REG_ARM_R4,
    PERF_REG_ARM_R5,
    PERF_REG_ARM_R6,
    PERF_REG_ARM_R7,
    PERF_REG_ARM_R8,
    PERF_REG_ARM_R9,
    PERF_REG_ARM_R10,
    PERF_REG_ARM_FP,
    PERF_REG_ARM_IP,
    PERF_REG_ARM_SP,
    PERF_REG_ARM_LR,
    PERF_REG_ARM_PC,
    PERF_REG_ARM_MAX,
};
#define PERF_REG_SP PERF_REG_ARM_SP
#define PERF_REG_IP PERF_REG_ARM_PC

#endif // __arm__

static inline const char *perf_reg_name(int id __maybe_unused)
{
	return NULL;
}
#endif /* HAVE_PERF_REGS */
#endif /* __PERF_REGS_H */

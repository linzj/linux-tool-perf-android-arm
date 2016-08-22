/*
 * Mapping of DWARF debug register numbers into register names.
 *
 * Copyright (C) 2010 Will Deacon, ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <stddef.h>
#include <dwarf-regs.h>

struct pt_regs_dwarfnum {
	const char *name;
	unsigned int dwarfnum;
};

#define STR(s) #s
#define REG_DWARFNUM_NAME(r, num) {.name = r, .dwarfnum = num}
#define GPR_DWARFNUM_NAME(num) \
	{.name = STR(%r##num), .dwarfnum = num}
#define REG_DWARFNUM_END {.name = NULL, .dwarfnum = 0}

/*
 * Reference:
 * http://infocenter.arm.com/help/topic/com.arm.doc.ihi0040a/IHI0040A_aadwarf.pdf
 */
static const struct pt_regs_dwarfnum regdwarfnum_table[] = {
	GPR_DWARFNUM_NAME(0),
	GPR_DWARFNUM_NAME(1),
	GPR_DWARFNUM_NAME(2),
	GPR_DWARFNUM_NAME(3),
	GPR_DWARFNUM_NAME(4),
	GPR_DWARFNUM_NAME(5),
	GPR_DWARFNUM_NAME(6),
	GPR_DWARFNUM_NAME(7),
	GPR_DWARFNUM_NAME(8),
	GPR_DWARFNUM_NAME(9),
	GPR_DWARFNUM_NAME(10),
	REG_DWARFNUM_NAME("%fp", 11),
	REG_DWARFNUM_NAME("%ip", 12),
	REG_DWARFNUM_NAME("%sp", 13),
	REG_DWARFNUM_NAME("%lr", 14),
	REG_DWARFNUM_NAME("%pc", 15),
	REG_DWARFNUM_END,
};

/**
 * get_arch_regstr() - lookup register name from it's DWARF register number
 * @n:	the DWARF register number
 *
 * get_arch_regstr() returns the name of the register in struct
 * regdwarfnum_table from it's DWARF register number. If the register is not
 * found in the table, this returns NULL;
 */
const char *get_arch_regstr(unsigned int n)
{
	const struct pt_regs_dwarfnum *roff;
	for (roff = regdwarfnum_table; roff->name != NULL; roff++)
		if (roff->dwarfnum == n)
			return roff->name;
	return NULL;
}

#include <linux/compiler.h>
#include <perf_regs.h>
enum
  {
    UNW_ARM_R0,
    UNW_ARM_R1,
    UNW_ARM_R2,
    UNW_ARM_R3,
    UNW_ARM_R4,
    UNW_ARM_R5,
    UNW_ARM_R6,
    UNW_ARM_R7,
    UNW_ARM_R8,
    UNW_ARM_R9,
    UNW_ARM_R10,
    UNW_ARM_R11,
    UNW_ARM_R12,
    UNW_ARM_R13,
    UNW_ARM_R14,
    UNW_ARM_R15,
    
    /* VFPv2 s0-s31 (obsolescent numberings).  */
    UNW_ARM_S0 = 64,
    UNW_ARM_S1,
    UNW_ARM_S2,
    UNW_ARM_S3,
    UNW_ARM_S4,
    UNW_ARM_S5,
    UNW_ARM_S6,
    UNW_ARM_S7,
    UNW_ARM_S8,
    UNW_ARM_S9,
    UNW_ARM_S10,
    UNW_ARM_S11,
    UNW_ARM_S12,
    UNW_ARM_S13,
    UNW_ARM_S14,
    UNW_ARM_S15,
    UNW_ARM_S16,
    UNW_ARM_S17,
    UNW_ARM_S18,
    UNW_ARM_S19,
    UNW_ARM_S20,
    UNW_ARM_S21,
    UNW_ARM_S22,
    UNW_ARM_S23,
    UNW_ARM_S24,
    UNW_ARM_S25,
    UNW_ARM_S26,
    UNW_ARM_S27,
    UNW_ARM_S28,
    UNW_ARM_S29,
    UNW_ARM_S30,
    UNW_ARM_S31,
    
    /* FPA register numberings.  */
    UNW_ARM_F0 = 96,
    UNW_ARM_F1,
    UNW_ARM_F2,
    UNW_ARM_F3,
    UNW_ARM_F4,
    UNW_ARM_F5,
    UNW_ARM_F6,
    UNW_ARM_F7,
    
    /* iWMMXt GR register numberings.  */
    UNW_ARM_wCGR0 = 104,
    UNW_ARM_wCGR1,
    UNW_ARM_wCGR2,
    UNW_ARM_wCGR3,
    UNW_ARM_wCGR4,
    UNW_ARM_wCGR5,
    UNW_ARM_wCGR6,
    UNW_ARM_wCGR7,
    
    /* iWMMXt register numberings.  */
    UNW_ARM_wR0 = 112,
    UNW_ARM_wR1,
    UNW_ARM_wR2,
    UNW_ARM_wR3,
    UNW_ARM_wR4,
    UNW_ARM_wR5,
    UNW_ARM_wR6,
    UNW_ARM_wR7,
    UNW_ARM_wR8,
    UNW_ARM_wR9,
    UNW_ARM_wR10,
    UNW_ARM_wR11,
    UNW_ARM_wR12,
    UNW_ARM_wR13,
    UNW_ARM_wR14,
    UNW_ARM_wR15,
    
    /* Two-byte encodings from here on.  */
    
    /* SPSR.  */
    UNW_ARM_SPSR = 128,
    UNW_ARM_SPSR_FIQ,
    UNW_ARM_SPSR_IRQ,
    UNW_ARM_SPSR_ABT,
    UNW_ARM_SPSR_UND,
    UNW_ARM_SPSR_SVC,
    
    /* User mode registers.  */
    UNW_ARM_R8_USR = 144,
    UNW_ARM_R9_USR,
    UNW_ARM_R10_USR,
    UNW_ARM_R11_USR,
    UNW_ARM_R12_USR,
    UNW_ARM_R13_USR,
    UNW_ARM_R14_USR,
    
    /* FIQ registers.  */
    UNW_ARM_R8_FIQ = 151,
    UNW_ARM_R9_FIQ,
    UNW_ARM_R10_FIQ,
    UNW_ARM_R11_FIQ,
    UNW_ARM_R12_FIQ,
    UNW_ARM_R13_FIQ,
    UNW_ARM_R14_FIQ,
    
    /* IRQ registers.  */
    UNW_ARM_R13_IRQ = 158,
    UNW_ARM_R14_IRQ,
    
    /* ABT registers.  */
    UNW_ARM_R13_ABT = 160,
    UNW_ARM_R14_ABT,
    
    /* UND registers.  */
    UNW_ARM_R13_UND = 162,
    UNW_ARM_R14_UND,
    
    /* SVC registers.  */
    UNW_ARM_R13_SVC = 164,
    UNW_ARM_R14_SVC,
    
    /* iWMMXt control registers.  */
    UNW_ARM_wC0 = 192,
    UNW_ARM_wC1,
    UNW_ARM_wC2,
    UNW_ARM_wC3,
    UNW_ARM_wC4,
    UNW_ARM_wC5,
    UNW_ARM_wC6,
    UNW_ARM_wC7,

    /* VFPv3/Neon 64-bit registers.  */
    UNW_ARM_D0 = 256,
    UNW_ARM_D1,
    UNW_ARM_D2,
    UNW_ARM_D3,
    UNW_ARM_D4,
    UNW_ARM_D5,
    UNW_ARM_D6,
    UNW_ARM_D7,
    UNW_ARM_D8,
    UNW_ARM_D9,
    UNW_ARM_D10,
    UNW_ARM_D11,
    UNW_ARM_D12,
    UNW_ARM_D13,
    UNW_ARM_D14,
    UNW_ARM_D15,
    UNW_ARM_D16,
    UNW_ARM_D17,
    UNW_ARM_D18,
    UNW_ARM_D19,
    UNW_ARM_D20,
    UNW_ARM_D21,
    UNW_ARM_D22,
    UNW_ARM_D23,
    UNW_ARM_D24,
    UNW_ARM_D25,
    UNW_ARM_D26,
    UNW_ARM_D27,
    UNW_ARM_D28,
    UNW_ARM_D29,
    UNW_ARM_D30,
    UNW_ARM_D31,

    /* For ARM, the CFA is the value of SP (r13) at the call site in the
       previous frame.  */
    UNW_ARM_CFA,

    UNW_TDEP_LAST_REG = UNW_ARM_D31,

    UNW_TDEP_IP = UNW_ARM_R14,  /* A little white lie.  */
    UNW_TDEP_SP = UNW_ARM_R13,
    UNW_TDEP_EH = UNW_ARM_R0   /* FIXME.  */
  };
int unwind__arch_reg_id(int regnum)
{
    switch (regnum) {
    case UNW_ARM_R0: return PERF_REG_ARM_R0;
    case UNW_ARM_R1: return PERF_REG_ARM_R1;
    case UNW_ARM_R2: return PERF_REG_ARM_R2;
    case UNW_ARM_R3: return PERF_REG_ARM_R3;
    case UNW_ARM_R4: return PERF_REG_ARM_R4;
    case UNW_ARM_R5: return PERF_REG_ARM_R5;
    case UNW_ARM_R6: return PERF_REG_ARM_R6;
    case UNW_ARM_R7: return PERF_REG_ARM_R7;
    case UNW_ARM_R8: return PERF_REG_ARM_R8;
    case UNW_ARM_R9: return PERF_REG_ARM_R9;
    case UNW_ARM_R10: return PERF_REG_ARM_R10;
    case UNW_ARM_R11: return PERF_REG_ARM_FP;
    case UNW_ARM_R12: return PERF_REG_ARM_IP;
    case UNW_ARM_R13: return PERF_REG_ARM_SP;
    case UNW_ARM_R14: return PERF_REG_ARM_LR;
    case UNW_ARM_R15: return PERF_REG_ARM_PC;
    }
    return PERF_REG_ARM_MAX;
}

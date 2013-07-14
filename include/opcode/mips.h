/* mips.h.  Mips opcode list for GDB, the GNU debugger.
   Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
   2003, 2004, 2005, 2008, 2009, 2010, 2013
   Free Software Foundation, Inc.
   Contributed by Ralph Campbell and OSF
   Commented and modified by Ian Lance Taylor, Cygnus Support

   This file is part of GDB, GAS, and the GNU binutils.

   GDB, GAS, and the GNU binutils are free software; you can redistribute
   them and/or modify them under the terms of the GNU General Public
   License as published by the Free Software Foundation; either version 3,
   or (at your option) any later version.

   GDB, GAS, and the GNU binutils are distributed in the hope that they
   will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING3.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#ifndef _MIPS_H_
#define _MIPS_H_

#include "bfd.h"

/* These are bit masks and shift counts to use to access the various
   fields of an instruction.  To retrieve the X field of an
   instruction, use the expression
	(i >> OP_SH_X) & OP_MASK_X
   To set the same field (to j), use
	i = (i &~ (OP_MASK_X << OP_SH_X)) | (j << OP_SH_X)

   Make sure you use fields that are appropriate for the instruction,
   of course.

   The 'i' format uses OP, RS, RT and IMMEDIATE.

   The 'j' format uses OP and TARGET.

   The 'r' format uses OP, RS, RT, RD, SHAMT and FUNCT.

   The 'b' format uses OP, RS, RT and DELTA.

   The floating point 'i' format uses OP, RS, RT and IMMEDIATE.

   The floating point 'r' format uses OP, FMT, FT, FS, FD and FUNCT.

   A breakpoint instruction uses OP, CODE and SPEC (10 bits of the
   breakpoint instruction are not defined; Kane says the breakpoint
   code field in BREAK is 20 bits; yet MIPS assemblers and debuggers
   only use ten bits).  An optional two-operand form of break/sdbbp
   allows the lower ten bits to be set too, and MIPS32 and later
   architectures allow 20 bits to be set with a signal operand
   (using CODE20).

   The syscall instruction uses CODE20.

   The general coprocessor instructions use COPZ.  */

#define OP_MASK_OP		0x3f
#define OP_SH_OP		26
#define OP_MASK_RS		0x1f
#define OP_SH_RS		21
#define OP_MASK_FR		0x1f
#define OP_SH_FR		21
#define OP_MASK_FMT		0x1f
#define OP_SH_FMT		21
#define OP_MASK_BCC		0x7
#define OP_SH_BCC		18
#define OP_MASK_CODE		0x3ff
#define OP_SH_CODE		16
#define OP_MASK_CODE2		0x3ff
#define OP_SH_CODE2		6
#define OP_MASK_RT		0x1f
#define OP_SH_RT		16
#define OP_MASK_FT		0x1f
#define OP_SH_FT		16
#define OP_MASK_CACHE		0x1f
#define OP_SH_CACHE		16
#define OP_MASK_RD		0x1f
#define OP_SH_RD		11
#define OP_MASK_FS		0x1f
#define OP_SH_FS		11
#define OP_MASK_PREFX		0x1f
#define OP_SH_PREFX		11
#define OP_MASK_CCC		0x7
#define OP_SH_CCC		8
#define OP_MASK_CODE20		0xfffff /* 20 bit syscall/breakpoint code.  */
#define OP_SH_CODE20		6
#define OP_MASK_SHAMT		0x1f
#define OP_SH_SHAMT		6
#define OP_MASK_EXTLSB		OP_MASK_SHAMT
#define OP_SH_EXTLSB		OP_SH_SHAMT
#define OP_MASK_STYPE		OP_MASK_SHAMT
#define OP_SH_STYPE		OP_SH_SHAMT
#define OP_MASK_FD		0x1f
#define OP_SH_FD		6
#define OP_MASK_TARGET		0x3ffffff
#define OP_SH_TARGET		0
#define OP_MASK_COPZ		0x1ffffff
#define OP_SH_COPZ		0
#define OP_MASK_IMMEDIATE	0xffff
#define OP_SH_IMMEDIATE		0
#define OP_MASK_DELTA		0xffff
#define OP_SH_DELTA		0
#define OP_MASK_FUNCT		0x3f
#define OP_SH_FUNCT		0
#define OP_MASK_SPEC		0x3f
#define OP_SH_SPEC		0
#define OP_SH_LOCC              8       /* FP condition code.  */
#define OP_SH_HICC              18      /* FP condition code.  */
#define OP_MASK_CC              0x7
#define OP_SH_COP1NORM          25      /* Normal COP1 encoding.  */
#define OP_MASK_COP1NORM        0x1     /* a single bit.  */
#define OP_SH_COP1SPEC          21      /* COP1 encodings.  */
#define OP_MASK_COP1SPEC        0xf
#define OP_MASK_COP1SCLR        0x4
#define OP_MASK_COP1CMP         0x3
#define OP_SH_COP1CMP           4
#define OP_SH_FORMAT            21      /* FP short format field.  */
#define OP_MASK_FORMAT          0x7
#define OP_SH_TRUE              16
#define OP_MASK_TRUE            0x1
#define OP_SH_GE                17
#define OP_MASK_GE              0x01
#define OP_SH_UNSIGNED          16
#define OP_MASK_UNSIGNED        0x1
#define OP_SH_HINT              16
#define OP_MASK_HINT            0x1f
#define OP_SH_MMI               0       /* Multimedia (parallel) op.  */
#define OP_MASK_MMI             0x3f
#define OP_SH_MMISUB            6
#define OP_MASK_MMISUB          0x1f
#define OP_MASK_PERFREG		0x1f	/* Performance monitoring.  */
#define OP_SH_PERFREG		1
#define OP_SH_SEL		0	/* Coprocessor select field.  */
#define OP_MASK_SEL		0x7	/* The sel field of mfcZ and mtcZ.  */
#define OP_SH_CODE19		6       /* 19 bit wait code.  */
#define OP_MASK_CODE19		0x7ffff
#define OP_SH_ALN		21
#define OP_MASK_ALN		0x7
#define OP_SH_VSEL		21
#define OP_MASK_VSEL		0x1f
#define OP_MASK_VECBYTE		0x7	/* Selector field is really 4 bits,
					   but 0x8-0xf don't select bytes.  */
#define OP_SH_VECBYTE		22
#define OP_MASK_VECALIGN	0x7	/* Vector byte-align (alni.ob) op.  */
#define OP_SH_VECALIGN		21
#define OP_MASK_INSMSB		0x1f	/* "ins" MSB.  */
#define OP_SH_INSMSB		11
#define OP_MASK_EXTMSBD		0x1f	/* "ext" MSBD.  */
#define OP_SH_EXTMSBD		11

/* MIPS DSP ASE */
#define OP_SH_DSPACC		11
#define OP_MASK_DSPACC  	0x3
#define OP_SH_DSPACC_S  	21
#define OP_MASK_DSPACC_S	0x3
#define OP_SH_DSPSFT		20
#define OP_MASK_DSPSFT  	0x3f
#define OP_SH_DSPSFT_7  	19
#define OP_MASK_DSPSFT_7	0x7f
#define OP_SH_SA3		21
#define OP_MASK_SA3		0x7
#define OP_SH_SA4		21
#define OP_MASK_SA4		0xf
#define OP_SH_IMM8		16
#define OP_MASK_IMM8		0xff
#define OP_SH_IMM10		16
#define OP_MASK_IMM10		0x3ff
#define OP_SH_WRDSP		11
#define OP_MASK_WRDSP		0x3f
#define OP_SH_RDDSP		16
#define OP_MASK_RDDSP		0x3f
#define OP_SH_BP		11
#define OP_MASK_BP		0x3

/* MIPS MT ASE */
#define OP_SH_MT_U		5
#define OP_MASK_MT_U		0x1
#define OP_SH_MT_H		4
#define OP_MASK_MT_H		0x1
#define OP_SH_MTACC_T		18
#define OP_MASK_MTACC_T		0x3
#define OP_SH_MTACC_D		13
#define OP_MASK_MTACC_D		0x3

/* MIPS MCU ASE */
#define OP_MASK_3BITPOS		0x7
#define OP_SH_3BITPOS		12
#define OP_MASK_OFFSET12	0xfff
#define OP_SH_OFFSET12		0

#define	OP_OP_COP0		0x10
#define	OP_OP_COP1		0x11
#define	OP_OP_COP2		0x12
#define	OP_OP_COP3		0x13
#define	OP_OP_LWC1		0x31
#define	OP_OP_LWC2		0x32
#define	OP_OP_LWC3		0x33	/* a.k.a. pref */
#define	OP_OP_LDC1		0x35
#define	OP_OP_LDC2		0x36
#define	OP_OP_LDC3		0x37	/* a.k.a. ld */
#define	OP_OP_SWC1		0x39
#define	OP_OP_SWC2		0x3a
#define	OP_OP_SWC3		0x3b
#define	OP_OP_SDC1		0x3d
#define	OP_OP_SDC2		0x3e
#define	OP_OP_SDC3		0x3f	/* a.k.a. sd */

/* MIPS VIRT ASE */
#define OP_MASK_CODE10		0x3ff
#define OP_SH_CODE10		11

/* Values in the 'VSEL' field.  */
#define MDMX_FMTSEL_IMM_QH	0x1d
#define MDMX_FMTSEL_IMM_OB	0x1e
#define MDMX_FMTSEL_VEC_QH	0x15
#define MDMX_FMTSEL_VEC_OB	0x16

/* UDI */
#define OP_SH_UDI1		6
#define OP_MASK_UDI1		0x1f
#define OP_SH_UDI2		6
#define OP_MASK_UDI2		0x3ff
#define OP_SH_UDI3		6
#define OP_MASK_UDI3		0x7fff
#define OP_SH_UDI4		6
#define OP_MASK_UDI4		0xfffff

/* Octeon */
#define OP_SH_BBITIND		16
#define OP_MASK_BBITIND		0x1f
#define OP_SH_CINSPOS		6
#define OP_MASK_CINSPOS		0x1f
#define OP_SH_CINSLM1		11
#define OP_MASK_CINSLM1		0x1f
#define OP_SH_SEQI		6
#define OP_MASK_SEQI		0x3ff

/* Loongson */
#define OP_SH_OFFSET_A		6
#define OP_MASK_OFFSET_A	0xff
#define OP_SH_OFFSET_B		3
#define OP_MASK_OFFSET_B	0xff
#define OP_SH_OFFSET_C		6
#define OP_MASK_OFFSET_C	0x1ff
#define OP_SH_RZ		0
#define OP_MASK_RZ		0x1f
#define OP_SH_FZ		0
#define OP_MASK_FZ		0x1f

/* Every MICROMIPSOP_X definition requires a corresponding OP_X
   definition, and vice versa.  This simplifies various parts
   of the operand handling in GAS.  The fields below only exist
   in the microMIPS encoding, so define each one to have an empty
   range.  */
#define OP_MASK_TRAP		0
#define OP_SH_TRAP		0
#define OP_MASK_OFFSET10	0
#define OP_SH_OFFSET10		0
#define OP_MASK_RS3		0
#define OP_SH_RS3		0
#define OP_MASK_MB		0
#define OP_SH_MB		0
#define OP_MASK_MC		0
#define OP_SH_MC		0
#define OP_MASK_MD		0
#define OP_SH_MD		0
#define OP_MASK_ME		0
#define OP_SH_ME		0
#define OP_MASK_MF		0
#define OP_SH_MF		0
#define OP_MASK_MG		0
#define OP_SH_MG		0
#define OP_MASK_MH		0
#define OP_SH_MH		0
#define OP_MASK_MJ		0
#define OP_SH_MJ		0
#define OP_MASK_ML		0
#define OP_SH_ML		0
#define OP_MASK_MM		0
#define OP_SH_MM		0
#define OP_MASK_MN		0
#define OP_SH_MN		0
#define OP_MASK_MP		0
#define OP_SH_MP		0
#define OP_MASK_MQ		0
#define OP_SH_MQ		0
#define OP_MASK_IMMA		0
#define OP_SH_IMMA		0
#define OP_MASK_IMMB		0
#define OP_SH_IMMB		0
#define OP_MASK_IMMC		0
#define OP_SH_IMMC		0
#define OP_MASK_IMMF		0
#define OP_SH_IMMF		0
#define OP_MASK_IMMG		0
#define OP_SH_IMMG		0
#define OP_MASK_IMMH		0
#define OP_SH_IMMH		0
#define OP_MASK_IMMI		0
#define OP_SH_IMMI		0
#define OP_MASK_IMMJ		0
#define OP_SH_IMMJ		0
#define OP_MASK_IMML		0
#define OP_SH_IMML		0
#define OP_MASK_IMMM		0
#define OP_SH_IMMM		0
#define OP_MASK_IMMN		0
#define OP_SH_IMMN		0
#define OP_MASK_IMMO		0
#define OP_SH_IMMO		0
#define OP_MASK_IMMP		0
#define OP_SH_IMMP		0
#define OP_MASK_IMMQ		0
#define OP_SH_IMMQ		0
#define OP_MASK_IMMU		0
#define OP_SH_IMMU		0
#define OP_MASK_IMMW		0
#define OP_SH_IMMW		0
#define OP_MASK_IMMX		0
#define OP_SH_IMMX		0
#define OP_MASK_IMMY		0
#define OP_SH_IMMY		0

/* Enhanced VA Scheme */
#define OP_SH_EVAOFFSET		7
#define OP_MASK_EVAOFFSET	0x1ff

/* Enumerates the various types of MIPS operand.  */
enum mips_operand_type {
  /* Described by mips_int_operand.  */
  OP_INT,

  /* Described by mips_mapped_int_operand.  */
  OP_MAPPED_INT,

  /* Described by mips_msb_operand.  */
  OP_MSB,

  /* Described by mips_reg_operand.  */
  OP_REG,

  /* Described by mips_reg_pair_operand.  */
  OP_REG_PAIR,

  /* Described by mips_pcrel_operand.  */
  OP_PCREL,

  /* A performance register.  The field is 5 bits in size, but the supported
     values are much more restricted.  */
  OP_PERF_REG,

  /* The final operand in a microMIPS ADDIUSP instruction.  It mostly acts
     as a normal 9-bit signed offset that is multiplied by four, but there
     are four special cases:

     -2 * 4 => -258 * 4
     -1 * 4 => -257 * 4
      0 * 4 =>  256 * 4
      1 * 4 =>  257 * 4.  */
  OP_ADDIUSP_INT,

  /* The target of a (D)CLO or (D)CLZ instruction.  The operand spans two
     5-bit register fields, both of which must be set to the destination
     register.  */
  OP_CLO_CLZ_DEST,

  /* A register list for a microMIPS LWM or SWM instruction.  The operand
     size determines whether the 16-bit or 32-bit encoding is required.  */
  OP_LWM_SWM_LIST,

  /* The register list for an emulated MIPS16 ENTRY or EXIT instruction.  */
  OP_ENTRY_EXIT_LIST,

  /* The register list and frame size for a MIPS16 SAVE or RESTORE
     instruction.  */
  OP_SAVE_RESTORE_LIST,

  /* A 10-bit field VVVVVNNNNN used for octobyte and quadhalf instructions:

     V      Meaning
     -----  -------
     0EEE0  8 copies of $vN[E], OB format
     0EE01  4 copies of $vN[E], QH format
     10110  all 8 elements of $vN, OB format
     10101  all 4 elements of $vN, QH format
     11110  8 copies of immediate N, OB format
     11101  4 copies of immediate N, QH format.  */
  OP_MDMX_IMM_REG,

  /* A register operand that must match the destination register.  */
  OP_REPEAT_DEST_REG,

  /* A register operand that must match the previous register.  */
  OP_REPEAT_PREV_REG,

  /* $pc, which has no encoding in the architectural instruction.  */
  OP_PC
};

/* Enumerates the types of MIPS register.  */
enum mips_reg_operand_type {
  /* General registers $0-$31.  Software names like $at can also be used.  */
  OP_REG_GP,

  /* Floating-point registers $f0-$f31.  */
  OP_REG_FP,

  /* Coprocessor condition code registers $cc0-$cc7.  FPU condition codes
     can also be written $fcc0-$fcc7.  */
  OP_REG_CCC,

  /* FPRs used in a vector capacity.  They can be written $f0-$f31
     or $v0-$v31, although the latter form is not used for the VR5400
     vector instructions.  */
  OP_REG_VEC,

  /* DSP accumulator registers $ac0-$ac3.  */
  OP_REG_ACC,

  /* Coprocessor registers $0-$31.  Mnemonic names like c0_cause can
     also be used in some contexts.  */
  OP_REG_COPRO,

  /* Hardware registers $0-$31.  Mnemonic names like hwr_cpunum can
     also be used in some contexts.  */
  OP_REG_HW
};

/* Base class for all operands.  */
struct mips_operand
{
  /* The type of the operand.  */
  enum mips_operand_type type;

  /* The operand occupies SIZE bits of the instruction, starting at LSB.  */
  unsigned short size;
  unsigned short lsb;
};

/* Describes an integer operand with a regular encoding pattern.  */
struct mips_int_operand
{
  struct mips_operand root;

  /* The low ROOT.SIZE bits of MAX_VAL encodes (MAX_VAL + BIAS) << SHIFT.
     The cyclically previous field value encodes 1 << SHIFT less than that,
     and so on.  E.g.

     - for { { T, 4, L }, 14, 0, 0 }, field values 0...14 encode themselves,
       but 15 encodes -1.

     - { { T, 8, L }, 127, 0, 2 } is a normal signed 8-bit operand that is
       shifted left two places.

     - { { T, 3, L }, 8, 0, 0 } is a normal unsigned 3-bit operand except
       that 0 encodes 8.

     - { { ... }, 0, 1, 3 } means that N encodes (N + 1) << 3.  */
  unsigned int max_val;
  int bias;
  unsigned int shift;

  /* True if the operand should be printed as hex rather than decimal.  */
  bfd_boolean print_hex;
};

/* Uses a lookup table to describe a small integer operand.  */
struct mips_mapped_int_operand
{
  struct mips_operand root;

  /* Maps each encoding value to the integer that it represents.  */
  const int *int_map;

  /* True if the operand should be printed as hex rather than decimal.  */
  bfd_boolean print_hex;
};

/* An operand that encodes the most significant bit position of a bitfield.
   Given a bitfield that spans bits [MSB, LSB], some operands of this type
   encode MSB directly while others encode MSB - LSB.  Each operand of this
   type is preceded by an integer operand that specifies LSB.

   The assembly form varies between instructions.  For some instructions,
   such as EXT, the operand is written as the bitfield size.  For others,
   such as EXTS, it is written in raw MSB - LSB form.  */
struct mips_msb_operand
{
  struct mips_operand root;

  /* The assembly-level operand encoded by a field value of 0.  */
  int bias;

  /* True if the operand encodes MSB directly, false if it encodes
     MSB - LSB.  */
  bfd_boolean add_lsb;

  /* The maximum value of MSB + 1.  */
  unsigned int opsize;
};

/* Describes a single register operand.  */
struct mips_reg_operand
{
  struct mips_operand root;

  /* The type of register.  */
  enum mips_reg_operand_type reg_type;

  /* If nonnull, REG_MAP[N] gives the register associated with encoding N,
     otherwise the encoding is the same as the register number.  */
  const unsigned char *reg_map;
};

/* Describes an operand that encodes a pair of registers.  */
struct mips_reg_pair_operand
{
  struct mips_operand root;

  /* The type of register.  */
  enum mips_reg_operand_type reg_type;

  /* Encoding N represents REG1_MAP[N], REG2_MAP[N].  */
  unsigned char *reg1_map;
  unsigned char *reg2_map;
};

/* Describes an operand that is calculated relative to a base PC.
   The base PC is usually the address of the following instruction,
   but the rules for MIPS16 instructions like ADDIUPC are more complicated.  */
struct mips_pcrel_operand
{
  struct mips_operand root;

  /* The low ALIGN_LOG2 bits of the base PC are cleared to give PC'.  */
  unsigned int align_log2 : 8;

  /* The operand is shifted left SHIFT places and added to PC'.
     The operand is signed if IS_SIGNED.  */
  unsigned int shift : 8;
  unsigned int is_signed : 1;

  /* If INCLUDE_ISA_BIT, the ISA bit of the original base PC is then
     reinstated.  This is true for jumps and branches and false for
     PC-relative data instructions.  */
  unsigned int include_isa_bit : 1;

  /* If FLIP_ISA_BIT, the ISA bit of the result is inverted.
     This is true for JALX and false otherwise.  */
  unsigned int flip_isa_bit : 1;
};

/* Return a version of INSN in which the field specified by OPERAND
   has value UVAL.  */

static inline unsigned int
mips_insert_operand (const struct mips_operand *operand, unsigned int insn,
		     unsigned int uval)
{
  unsigned int mask;

  mask = (1 << operand->size) - 1;
  insn &= ~(mask << operand->lsb);
  insn |= (uval & mask) << operand->lsb;
  return insn;
}

/* Extract OPERAND from instruction INSN.  */

static inline unsigned int
mips_extract_operand (const struct mips_operand *operand, unsigned int insn)
{
  return (insn >> operand->lsb) & ((1 << operand->size) - 1);
}

/* UVAL is the value encoded by OPERAND.  Return it in signed form.  */

static inline int
mips_signed_operand (const struct mips_operand *operand, unsigned int uval)
{
  unsigned int sign_bit, mask;

  mask = (1 << operand->size) - 1;
  sign_bit = 1 << (operand->size - 1);
  return ((uval + sign_bit) & mask) - sign_bit;
}

/* Return the integer that OPERAND encodes as UVAL.  */

static inline int
mips_decode_int_operand (const struct mips_int_operand *operand,
			 unsigned int uval)
{
  uval |= (operand->max_val - uval) & -(1 << operand->root.size);
  uval += operand->bias;
  uval <<= operand->shift;
  return uval;
}

/* PC-relative operand OPERAND has value UVAL and is relative to BASE_PC.
   Return the address that it encodes.  */

static inline bfd_vma
mips_decode_pcrel_operand (const struct mips_pcrel_operand *operand,
			   bfd_vma base_pc, unsigned int uval)
{
  bfd_vma addr;

  addr = base_pc & -(1 << operand->align_log2);
  if (operand->is_signed)
    addr += mips_signed_operand (&operand->root, uval) * (1 << operand->shift);
  else
    addr += uval << operand->shift;
  if (operand->include_isa_bit)
    addr |= base_pc & 1;
  if (operand->flip_isa_bit)
    addr ^= 1;
  return addr;
}

/* This structure holds information for a particular instruction.  */

struct mips_opcode
{
  /* The name of the instruction.  */
  const char *name;
  /* A string describing the arguments for this instruction.  */
  const char *args;
  /* The basic opcode for the instruction.  When assembling, this
     opcode is modified by the arguments to produce the actual opcode
     that is used.  If pinfo is INSN_MACRO, then this is 0.  */
  unsigned long match;
  /* If pinfo is not INSN_MACRO, then this is a bit mask for the
     relevant portions of the opcode when disassembling.  If the
     actual opcode anded with the match field equals the opcode field,
     then we have found the correct instruction.  If pinfo is
     INSN_MACRO, then this field is the macro identifier.  */
  unsigned long mask;
  /* For a macro, this is INSN_MACRO.  Otherwise, it is a collection
     of bits describing the instruction, notably any relevant hazard
     information.  */
  unsigned long pinfo;
  /* A collection of additional bits describing the instruction. */
  unsigned long pinfo2;
  /* A collection of bits describing the instruction sets of which this
     instruction or macro is a member. */
  unsigned long membership;
  /* A collection of bits describing the ASE of which this instruction
     or macro is a member.  */
  unsigned long ase;
  /* A collection of bits describing the instruction sets of which this
     instruction or macro is not a member.  */
  unsigned long exclusions;
};

/* These are the characters which may appear in the args field of an
   instruction.  They appear in the order in which the fields appear
   when the instruction is used.  Commas and parentheses in the args
   string are ignored when assembling, and written into the output
   when disassembling.

   Each of these characters corresponds to a mask field defined above.

   "1" 5 bit sync type (OP_*_STYPE)
   "<" 5 bit shift amount (OP_*_SHAMT)
   ">" shift amount between 32 and 63, stored after subtracting 32 (OP_*_SHAMT)
   "a" 26 bit target address (OP_*_TARGET)
   "+i" likewise, but flips bit 0
   "b" 5 bit base register (OP_*_RS)
   "c" 10 bit breakpoint code (OP_*_CODE)
   "d" 5 bit destination register specifier (OP_*_RD)
   "h" 5 bit prefx hint (OP_*_PREFX)
   "i" 16 bit unsigned immediate (OP_*_IMMEDIATE)
   "j" 16 bit signed immediate (OP_*_DELTA)
   "k" 5 bit cache opcode in target register position (OP_*_CACHE)
   "o" 16 bit signed offset (OP_*_DELTA)
   "p" 16 bit PC relative branch target address (OP_*_DELTA)
   "q" 10 bit extra breakpoint code (OP_*_CODE2)
   "r" 5 bit same register used as both source and target (OP_*_RS)
   "s" 5 bit source register specifier (OP_*_RS)
   "t" 5 bit target register (OP_*_RT)
   "u" 16 bit upper 16 bits of address (OP_*_IMMEDIATE)
   "v" 5 bit same register used as both source and destination (OP_*_RS)
   "w" 5 bit same register used as both target and destination (OP_*_RT)
   "U" 5 bit same destination register in both OP_*_RD and OP_*_RT
       (used by clo and clz)
   "C" 25 bit coprocessor function code (OP_*_COPZ)
   "B" 20 bit syscall/breakpoint function code (OP_*_CODE20)
   "J" 19 bit wait function code (OP_*_CODE19)
   "x" accept and ignore register name
   "z" must be zero register
   "K" 5 bit Hardware Register (rdhwr instruction) (OP_*_RD)
   "+A" 5 bit ins/ext/dins/dext/dinsm/dextm position, which becomes
        LSB (OP_*_SHAMT; OP_*_EXTLSB or OP_*_STYPE may be used for
        microMIPS compatibility).
	Enforces: 0 <= pos < 32.
   "+B" 5 bit ins/dins size, which becomes MSB (OP_*_INSMSB).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 0 < (pos+size) <= 32.
   "+C" 5 bit ext/dext size, which becomes MSBD (OP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 0 < (pos+size) <= 32.
	(Also used by "dext" w/ different limits, but limits for
	that are checked by the M_DEXT macro.)
   "+E" 5 bit dinsu/dextu position, which becomes LSB-32 (OP_*_SHAMT).
	Enforces: 32 <= pos < 64.
   "+F" 5 bit "dinsm/dinsu" size, which becomes MSB-32 (OP_*_INSMSB).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.
   "+G" 5 bit "dextm" size, which becomes MSBD-32 (OP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.
   "+H" 5 bit "dextu" size, which becomes MSBD (OP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.

   Floating point instructions:
   "D" 5 bit destination register (OP_*_FD)
   "M" 3 bit compare condition code (OP_*_CCC) (only used for mips4 and up)
   "N" 3 bit branch condition code (OP_*_BCC) (only used for mips4 and up)
   "S" 5 bit fs source 1 register (OP_*_FS)
   "T" 5 bit ft source 2 register (OP_*_FT)
   "R" 5 bit fr source 3 register (OP_*_FR)
   "V" 5 bit same register used as floating source and destination (OP_*_FS)
   "W" 5 bit same register used as floating target and destination (OP_*_FT)

   Coprocessor instructions:
   "E" 5 bit target register (OP_*_RT)
   "G" 5 bit destination register (OP_*_RD)
   "H" 3 bit sel field for (d)mtc* and (d)mfc* (OP_*_SEL)
   "P" 5 bit performance-monitor register (OP_*_PERFREG)
   "e" 5 bit vector register byte specifier (OP_*_VECBYTE)
   "%" 3 bit immediate vr5400 vector alignment operand (OP_*_VECALIGN)

   Macro instructions:
   "A" General 32 bit expression
   "I" 32 bit immediate (value placed in imm_expr).
   "+I" 32 bit immediate (value placed in imm2_expr).
   "F" 64 bit floating point constant in .rdata
   "L" 64 bit floating point constant in .lit8
   "f" 32 bit floating point constant
   "l" 32 bit floating point constant in .lit4

   MDMX and VR5400 instruction operands (note that while these use the
   FP register fields, the MDMX instructions accept both $fN and $vN names
   for the registers):
   "O"	alignment offset (OP_*_ALN)
   "Q"	vector/scalar/immediate source (OP_*_VSEL and OP_*_FT)
   "X"	destination register (OP_*_FD)
   "Y"	source register (OP_*_FS)
   "Z"	source register (OP_*_FT)

   DSP ASE usage:
   "2" 2 bit unsigned immediate for byte align (OP_*_BP)
   "3" 3 bit unsigned immediate (OP_*_SA3)
   "4" 4 bit unsigned immediate (OP_*_SA4)
   "5" 8 bit unsigned immediate (OP_*_IMM8)
   "6" 5 bit unsigned immediate (OP_*_RS)
   "7" 2 bit dsp accumulator register (OP_*_DSPACC)
   "8" 6 bit unsigned immediate (OP_*_WRDSP)
   "9" 2 bit dsp accumulator register (OP_*_DSPACC_S)
   "0" 6 bit signed immediate (OP_*_DSPSFT)
   ":" 7 bit signed immediate (OP_*_DSPSFT_7)
   "'" 6 bit unsigned immediate (OP_*_RDDSP)
   "@" 10 bit signed immediate (OP_*_IMM10)

   MT ASE usage:
   "!" 1 bit usermode flag (OP_*_MT_U)
   "$" 1 bit load high flag (OP_*_MT_H)
   "*" 2 bit dsp/smartmips accumulator register (OP_*_MTACC_T)
   "&" 2 bit dsp/smartmips accumulator register (OP_*_MTACC_D)
   "g" 5 bit coprocessor 1 and 2 destination register (OP_*_RD)
   "+t" 5 bit coprocessor 0 destination register (OP_*_RT)

   MCU ASE usage:
   "~" 12 bit offset (OP_*_OFFSET12)
   "\" 3 bit position for aset and aclr (OP_*_3BITPOS)

   VIRT ASE usage:
   "+J" 10-bit hypcall code (OP_*CODE10)

   UDI immediates:
   "+1" UDI immediate bits 6-10
   "+2" UDI immediate bits 6-15
   "+3" UDI immediate bits 6-20
   "+4" UDI immediate bits 6-25

   Octeon:
   "+x" Bit index field of bbit.  Enforces: 0 <= index < 32.
   "+X" Bit index field of bbit aliasing bbit32.  Matches if 32 <= index < 64,
	otherwise skips to next candidate.
   "+p" Position field of cins/cins32/exts/exts32. Enforces 0 <= pos < 32.
   "+P" Position field of cins/exts aliasing cins32/exts32.  Matches if
	32 <= pos < 64, otherwise skips to next candidate.
   "+Q" Immediate field of seqi/snei.  Enforces -512 <= imm < 512.
   "+s" Length-minus-one field of cins32/exts32.  Requires msb position
	of the field to be <= 31.
   "+S" Length-minus-one field of cins/exts.  Requires msb position
	of the field to be <= 63.

   Loongson-3A:
   "+a" 8-bit signed offset in bit 6 (OP_*_OFFSET_A)
   "+b" 8-bit signed offset in bit 3 (OP_*_OFFSET_B)
   "+c" 9-bit signed offset in bit 6 (OP_*_OFFSET_C)
   "+z" 5-bit rz register (OP_*_RZ)
   "+Z" 5-bit fz register (OP_*_FZ)

   Enhanced VA Scheme:
   "+j" 9-bit signed offset in bit 7 (OP_*_EVAOFFSET)

   Other:
   "()" parens surrounding optional value
   ","  separates operands
   "+"  Start of extension sequence.

   Characters used so far, for quick reference when adding more:
   "1234567890"
   "%[]<>(),+:'@!$*&\~"
   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
   "abcdefghijklopqrstuvwxz"

   Extension character sequences used so far ("+" followed by the
   following), for quick reference when adding more:
   "1234"
   "ABCEFGHIJPQSXZ"
   "abcijpstxz"
*/

/* These are the bits which may be set in the pinfo field of an
   instructions, if it is not equal to INSN_MACRO.  */

/* Modifies the general purpose register in OP_*_RD.  */
#define INSN_WRITE_GPR_D            0x00000001
/* Modifies the general purpose register in OP_*_RT.  */
#define INSN_WRITE_GPR_T            0x00000002
/* Modifies general purpose register 31.  */
#define INSN_WRITE_GPR_31           0x00000004
/* Modifies the floating point register in OP_*_FD.  */
#define INSN_WRITE_FPR_D            0x00000008
/* Modifies the floating point register in OP_*_FS.  */
#define INSN_WRITE_FPR_S            0x00000010
/* Modifies the floating point register in OP_*_FT.  */
#define INSN_WRITE_FPR_T            0x00000020
/* Reads the general purpose register in OP_*_RS.  */
#define INSN_READ_GPR_S             0x00000040
/* Reads the general purpose register in OP_*_RT.  */
#define INSN_READ_GPR_T             0x00000080
/* Reads the floating point register in OP_*_FS.  */
#define INSN_READ_FPR_S             0x00000100
/* Reads the floating point register in OP_*_FT.  */
#define INSN_READ_FPR_T             0x00000200
/* Reads the floating point register in OP_*_FR.  */
#define INSN_READ_FPR_R		    0x00000400
/* Modifies coprocessor condition code.  */
#define INSN_WRITE_COND_CODE        0x00000800
/* Reads coprocessor condition code.  */
#define INSN_READ_COND_CODE         0x00001000
/* TLB operation.  */
#define INSN_TLB                    0x00002000
/* Reads coprocessor register other than floating point register.  */
#define INSN_COP                    0x00004000
/* Instruction loads value from memory, requiring delay.  */
#define INSN_LOAD_MEMORY_DELAY      0x00008000
/* Instruction loads value from coprocessor, requiring delay.  */
#define INSN_LOAD_COPROC_DELAY	    0x00010000
/* Instruction has unconditional branch delay slot.  */
#define INSN_UNCOND_BRANCH_DELAY    0x00020000
/* Instruction has conditional branch delay slot.  */
#define INSN_COND_BRANCH_DELAY      0x00040000
/* Conditional branch likely: if branch not taken, insn nullified.  */
#define INSN_COND_BRANCH_LIKELY	    0x00080000
/* Moves to coprocessor register, requiring delay.  */
#define INSN_COPROC_MOVE_DELAY      0x00100000
/* Loads coprocessor register from memory, requiring delay.  */
#define INSN_COPROC_MEMORY_DELAY    0x00200000
/* Reads the HI register.  */
#define INSN_READ_HI		    0x00400000
/* Reads the LO register.  */
#define INSN_READ_LO		    0x00800000
/* Modifies the HI register.  */
#define INSN_WRITE_HI		    0x01000000
/* Modifies the LO register.  */
#define INSN_WRITE_LO		    0x02000000
/* Not to be placed in a branch delay slot, either architecturally
   or for ease of handling (such as with instructions that take a trap).  */
#define INSN_NO_DELAY_SLOT	    0x04000000
/* Instruction stores value into memory.  */
#define INSN_STORE_MEMORY	    0x08000000
/* Instruction uses single precision floating point.  */
#define FP_S			    0x10000000
/* Instruction uses double precision floating point.  */
#define FP_D			    0x20000000
/* Instruction is part of the tx39's integer multiply family.    */
#define INSN_MULT                   0x40000000
/* Modifies the general purpose register in MICROMIPSOP_*_RS.  */
#define INSN_WRITE_GPR_S	    0x80000000
/* Instruction is actually a macro.  It should be ignored by the
   disassembler, and requires special treatment by the assembler.  */
#define INSN_MACRO                  0xffffffff

/* These are the bits which may be set in the pinfo2 field of an
   instruction. */

/* Instruction is a simple alias (I.E. "move" for daddu/addu/or) */
#define	INSN2_ALIAS		    0x00000001
/* Instruction reads MDMX accumulator. */
#define INSN2_READ_MDMX_ACC	    0x00000002
/* Instruction writes MDMX accumulator. */
#define INSN2_WRITE_MDMX_ACC	    0x00000004
/* Macro uses single-precision floating-point instructions.  This should
   only be set for macros.  For instructions, FP_S in pinfo carries the
   same information.  */
#define INSN2_M_FP_S		    0x00000008
/* Macro uses double-precision floating-point instructions.  This should
   only be set for macros.  For instructions, FP_D in pinfo carries the
   same information.  */
#define INSN2_M_FP_D		    0x00000010
/* Modifies the general purpose register in OP_*_RZ.  */
#define INSN2_WRITE_GPR_Z	    0x00000020
/* Modifies the floating point register in OP_*_FZ.  */
#define INSN2_WRITE_FPR_Z	    0x00000040
/* Reads the general purpose register in OP_*_RZ.  */
#define INSN2_READ_GPR_Z	    0x00000080
/* Reads the floating point register in OP_*_FZ.  */
#define INSN2_READ_FPR_Z	    0x00000100
/* Reads the general purpose register in OP_*_RD.  */
#define INSN2_READ_GPR_D	    0x00000200


/* Instruction has a branch delay slot that requires a 16-bit instruction.  */
#define INSN2_BRANCH_DELAY_16BIT    0x00000400
/* Instruction has a branch delay slot that requires a 32-bit instruction.  */
#define INSN2_BRANCH_DELAY_32BIT    0x00000800
/* Reads the floating point register in MICROMIPSOP_*_FD.  */
#define INSN2_READ_FPR_D	    0x00001000
/* Modifies the general purpose register in MICROMIPSOP_*_MB.  */
#define INSN2_WRITE_GPR_MB	    0x00002000
/* Reads the general purpose register in MICROMIPSOP_*_MC.  */
#define INSN2_READ_GPR_MC	    0x00004000
/* Reads/writes the general purpose register in MICROMIPSOP_*_MD.  */
#define INSN2_MOD_GPR_MD	    0x00008000
/* Reads the general purpose register in MICROMIPSOP_*_ME.  */
#define INSN2_READ_GPR_ME	    0x00010000
/* Reads/writes the general purpose register in MICROMIPSOP_*_MF.  */
#define INSN2_MOD_GPR_MF	    0x00020000
/* Reads the general purpose register in MICROMIPSOP_*_MG.  */
#define INSN2_READ_GPR_MG	    0x00040000
/* Reads the general purpose register in MICROMIPSOP_*_MJ.  */
#define INSN2_READ_GPR_MJ	    0x00080000
/* Modifies the general purpose register in MICROMIPSOP_*_MJ.  */
#define INSN2_WRITE_GPR_MJ	    0x00100000
/* Reads the general purpose register in MICROMIPSOP_*_MP.  */
#define INSN2_READ_GPR_MP	    0x00200000
/* Modifies the general purpose register in MICROMIPSOP_*_MP.  */
#define INSN2_WRITE_GPR_MP	    0x00400000
/* Reads the general purpose register in MICROMIPSOP_*_MQ.  */
#define INSN2_READ_GPR_MQ	    0x00800000
/* Reads/Writes the stack pointer ($29).  */
#define INSN2_MOD_SP		    0x01000000
/* Reads the RA ($31) register.  */
#define INSN2_READ_GPR_31	    0x02000000
/* Reads the global pointer ($28).  */
#define INSN2_READ_GP		    0x04000000
/* Reads the program counter ($pc).  */
#define INSN2_READ_PC		    0x08000000
/* Is an unconditional branch insn. */
#define INSN2_UNCOND_BRANCH	    0x10000000
/* Is a conditional branch insn. */
#define INSN2_COND_BRANCH	    0x20000000
/* Modifies the general purpose registers in MICROMIPSOP_*_MH.  */
#define INSN2_WRITE_GPR_MH	    0x40000000
/* Reads the general purpose registers in MICROMIPSOP_*_MM/N.  */
#define INSN2_READ_GPR_MMN	    0x80000000

/* Masks used to mark instructions to indicate which MIPS ISA level
   they were introduced in.  INSN_ISA_MASK masks an enumeration that
   specifies the base ISA level(s).  The remainder of a 32-bit
   word constructed using these macros is a bitmask of the remaining
   INSN_* values below.  */

#define INSN_ISA_MASK		  0x0000000ful

/* We cannot start at zero due to ISA_UNKNOWN below.  */
#define INSN_ISA1                 1
#define INSN_ISA2                 2
#define INSN_ISA3                 3
#define INSN_ISA4                 4
#define INSN_ISA5                 5
#define INSN_ISA32                6
#define INSN_ISA32R2              7
#define INSN_ISA64                8
#define INSN_ISA64R2              9
/* Below this point the INSN_* values correspond to combinations of ISAs.
   They are only for use in the opcodes table to indicate membership of
   a combination of ISAs that cannot be expressed using the usual inclusion
   ordering on the above INSN_* values.  */
#define INSN_ISA3_32              10
#define INSN_ISA3_32R2            11
#define INSN_ISA4_32              12
#define INSN_ISA4_32R2            13
#define INSN_ISA5_32R2            14

/* Given INSN_ISA* values X and Y, where X ranges over INSN_ISA1 through
   INSN_ISA5_32R2 and Y ranges over INSN_ISA1 through INSN_ISA64R2,
   this table describes whether at least one of the ISAs described by X
   is/are implemented by ISA Y.  (Think of Y as the ISA level supported by
   a particular core and X as the ISA level(s) at which a certain instruction
   is defined.)  The ISA(s) described by X is/are implemented by Y iff
   (mips_isa_table[(Y & INSN_ISA_MASK) - 1] >> ((X & INSN_ISA_MASK) - 1)) & 1
   is non-zero.  */
static const unsigned int mips_isa_table[] =
  { 0x0001, 0x0003, 0x0607, 0x1e0f, 0x3e1f, 0x0a23, 0x3e63, 0x3ebf, 0x3fff };

/* Masks used for Chip specific instructions.  */
#define INSN_CHIP_MASK		  0xc3ff0f20

/* Cavium Networks Octeon instructions.  */
#define INSN_OCTEON		  0x00000800
#define INSN_OCTEONP		  0x00000200
#define INSN_OCTEON2		  0x00000100

/* MIPS R5900 instruction */
#define INSN_5900                 0x00004000

/* MIPS R4650 instruction.  */
#define INSN_4650                 0x00010000
/* LSI R4010 instruction.  */
#define INSN_4010                 0x00020000
/* NEC VR4100 instruction.  */
#define INSN_4100                 0x00040000
/* Toshiba R3900 instruction.  */
#define INSN_3900                 0x00080000
/* MIPS R10000 instruction.  */
#define INSN_10000                0x00100000
/* Broadcom SB-1 instruction.  */
#define INSN_SB1                  0x00200000
/* NEC VR4111/VR4181 instruction.  */
#define INSN_4111                 0x00400000
/* NEC VR4120 instruction.  */
#define INSN_4120                 0x00800000
/* NEC VR5400 instruction.  */
#define INSN_5400		  0x01000000
/* NEC VR5500 instruction.  */
#define INSN_5500		  0x02000000

/* ST Microelectronics Loongson 2E.  */
#define INSN_LOONGSON_2E          0x40000000
/* ST Microelectronics Loongson 2F.  */
#define INSN_LOONGSON_2F          0x80000000
/* Loongson 3A.  */
#define INSN_LOONGSON_3A          0x00000400
/* RMI Xlr instruction */
#define INSN_XLR                 0x00000020

/* DSP ASE */
#define ASE_DSP			0x00000001
#define ASE_DSP64		0x00000002
/* DSP R2 ASE  */
#define ASE_DSPR2		0x00000004
/* Enhanced VA Scheme */
#define ASE_EVA			0x00000008
/* MCU (MicroController) ASE */
#define ASE_MCU			0x00000010
/* MDMX ASE */
#define ASE_MDMX		0x00000020
/* MIPS-3D ASE */
#define ASE_MIPS3D		0x00000040
/* MT ASE */
#define ASE_MT			0x00000080
/* SmartMIPS ASE  */
#define ASE_SMARTMIPS		0x00000100
/* Virtualization ASE */
#define ASE_VIRT		0x00000200
#define ASE_VIRT64		0x00000400

/* MIPS ISA defines, use instead of hardcoding ISA level.  */

#define       ISA_UNKNOWN     0               /* Gas internal use.  */
#define       ISA_MIPS1       INSN_ISA1
#define       ISA_MIPS2       INSN_ISA2
#define       ISA_MIPS3       INSN_ISA3
#define       ISA_MIPS4       INSN_ISA4
#define       ISA_MIPS5       INSN_ISA5

#define       ISA_MIPS32      INSN_ISA32
#define       ISA_MIPS64      INSN_ISA64

#define       ISA_MIPS32R2    INSN_ISA32R2
#define       ISA_MIPS64R2    INSN_ISA64R2


/* CPU defines, use instead of hardcoding processor number. Keep this
   in sync with bfd/archures.c in order for machine selection to work.  */
#define CPU_UNKNOWN	0               /* Gas internal use.  */
#define CPU_R3000	3000
#define CPU_R3900	3900
#define CPU_R4000	4000
#define CPU_R4010	4010
#define CPU_VR4100	4100
#define CPU_R4111	4111
#define CPU_VR4120	4120
#define CPU_R4300	4300
#define CPU_R4400	4400
#define CPU_R4600	4600
#define CPU_R4650	4650
#define CPU_R5000	5000
#define CPU_VR5400	5400
#define CPU_VR5500	5500
#define CPU_R5900	5900
#define CPU_R6000	6000
#define CPU_RM7000	7000
#define CPU_R8000	8000
#define CPU_RM9000	9000
#define CPU_R10000	10000
#define CPU_R12000	12000
#define CPU_R14000	14000
#define CPU_R16000	16000
#define CPU_MIPS16	16
#define CPU_MIPS32	32
#define CPU_MIPS32R2	33
#define CPU_MIPS5       5
#define CPU_MIPS64      64
#define CPU_MIPS64R2	65
#define CPU_SB1         12310201        /* octal 'SB', 01.  */
#define CPU_LOONGSON_2E 3001
#define CPU_LOONGSON_2F 3002
#define CPU_LOONGSON_3A 3003
#define CPU_OCTEON	6501
#define CPU_OCTEONP	6601
#define CPU_OCTEON2	6502
#define CPU_XLR     	887682   	/* decimal 'XLR'   */

/* Return true if the given CPU is included in INSN_* mask MASK.  */

static inline bfd_boolean
cpu_is_member (int cpu, unsigned int mask)
{
  switch (cpu)
    {
    case CPU_R4650:
    case CPU_RM7000:
    case CPU_RM9000:
      return (mask & INSN_4650) != 0;

    case CPU_R4010:
      return (mask & INSN_4010) != 0;

    case CPU_VR4100:
      return (mask & INSN_4100) != 0;

    case CPU_R3900:
      return (mask & INSN_3900) != 0;

    case CPU_R10000:
    case CPU_R12000:
    case CPU_R14000:
    case CPU_R16000:
      return (mask & INSN_10000) != 0;

    case CPU_SB1:
      return (mask & INSN_SB1) != 0;

    case CPU_R4111:
      return (mask & INSN_4111) != 0;

    case CPU_VR4120:
      return (mask & INSN_4120) != 0;

    case CPU_VR5400:
      return (mask & INSN_5400) != 0;

    case CPU_VR5500:
      return (mask & INSN_5500) != 0;

    case CPU_R5900:
      return (mask & INSN_5900) != 0;

    case CPU_LOONGSON_2E:
      return (mask & INSN_LOONGSON_2E) != 0;

    case CPU_LOONGSON_2F:
      return (mask & INSN_LOONGSON_2F) != 0;

    case CPU_LOONGSON_3A:
      return (mask & INSN_LOONGSON_3A) != 0;

    case CPU_OCTEON:
      return (mask & INSN_OCTEON) != 0;

    case CPU_OCTEONP:
      return (mask & INSN_OCTEONP) != 0;

    case CPU_OCTEON2:
      return (mask & INSN_OCTEON2) != 0;

    case CPU_XLR:
      return (mask & INSN_XLR) != 0;

    default:
      return FALSE;
    }
}

/* Test for membership in an ISA including chip specific ISAs.  INSN
   is pointer to an element of the opcode table; ISA is the specified
   ISA/ASE bitmask to test against; and CPU is the CPU specific ISA to
   test, or zero if no CPU specific ISA test is desired.  Return true
   if instruction INSN is available to the given ISA and CPU. */

static inline bfd_boolean
opcode_is_member (const struct mips_opcode *insn, int isa, int ase, int cpu)
{
  if (!cpu_is_member (cpu, insn->exclusions))
    {
      /* Test for ISA level compatibility.  */
      if ((isa & INSN_ISA_MASK) != 0
	  && (insn->membership & INSN_ISA_MASK) != 0
	  && ((mips_isa_table[(isa & INSN_ISA_MASK) - 1]
	       >> ((insn->membership & INSN_ISA_MASK) - 1)) & 1) != 0)
	return TRUE;

      /* Test for ASE compatibility.  */
      if ((ase & insn->ase) != 0)
	return TRUE;

      /* Test for processor-specific extensions.  */
      if (cpu_is_member (cpu, insn->membership))
	return TRUE;
    }
  return FALSE;
}

/* This is a list of macro expanded instructions.

   _I appended means immediate
   _A appended means target address of a jump
   _AB appended means address with (possibly zero) base register
   _D appended means 64 bit floating point constant
   _S appended means 32 bit floating point constant.  */

enum
{
  M_ABS,
  M_ACLR_AB,
  M_ADD_I,
  M_ADDU_I,
  M_AND_I,
  M_ASET_AB,
  M_BALIGN,
  M_BC1FL,
  M_BC1TL,
  M_BC2FL,
  M_BC2TL,
  M_BEQ,
  M_BEQ_I,
  M_BEQL,
  M_BEQL_I,
  M_BGE,
  M_BGEL,
  M_BGE_I,
  M_BGEL_I,
  M_BGEU,
  M_BGEUL,
  M_BGEU_I,
  M_BGEUL_I,
  M_BGEZ,
  M_BGEZL,
  M_BGEZALL,
  M_BGT,
  M_BGTL,
  M_BGT_I,
  M_BGTL_I,
  M_BGTU,
  M_BGTUL,
  M_BGTU_I,
  M_BGTUL_I,
  M_BGTZ,
  M_BGTZL,
  M_BLE,
  M_BLEL,
  M_BLE_I,
  M_BLEL_I,
  M_BLEU,
  M_BLEUL,
  M_BLEU_I,
  M_BLEUL_I,
  M_BLEZ,
  M_BLEZL,
  M_BLT,
  M_BLTL,
  M_BLT_I,
  M_BLTL_I,
  M_BLTU,
  M_BLTUL,
  M_BLTU_I,
  M_BLTUL_I,
  M_BLTZ,
  M_BLTZL,
  M_BLTZALL,
  M_BNE,
  M_BNEL,
  M_BNE_I,
  M_BNEL_I,
  M_CACHE_AB,
  M_CACHEE_AB,
  M_DABS,
  M_DADD_I,
  M_DADDU_I,
  M_DDIV_3,
  M_DDIV_3I,
  M_DDIVU_3,
  M_DDIVU_3I,
  M_DEXT,
  M_DINS,
  M_DIV_3,
  M_DIV_3I,
  M_DIVU_3,
  M_DIVU_3I,
  M_DLA_AB,
  M_DLCA_AB,
  M_DLI,
  M_DMUL,
  M_DMUL_I,
  M_DMULO,
  M_DMULO_I,
  M_DMULOU,
  M_DMULOU_I,
  M_DREM_3,
  M_DREM_3I,
  M_DREMU_3,
  M_DREMU_3I,
  M_DSUB_I,
  M_DSUBU_I,
  M_DSUBU_I_2,
  M_J_A,
  M_JAL_1,
  M_JAL_2,
  M_JAL_A,
  M_JALS_1,
  M_JALS_2,
  M_JALS_A,
  M_JRADDIUSP,
  M_JRC,
  M_L_DAB,
  M_LA_AB,
  M_LB_AB,
  M_LBE_AB,
  M_LBU_AB,
  M_LBUE_AB,
  M_LCA_AB,
  M_LD_AB,
  M_LDC1_AB,
  M_LDC2_AB,
  M_LQC2_AB,
  M_LDC3_AB,
  M_LDL_AB,
  M_LDM_AB,
  M_LDP_AB,
  M_LDR_AB,
  M_LH_AB,
  M_LHE_AB,
  M_LHU_AB,
  M_LHUE_AB,
  M_LI,
  M_LI_D,
  M_LI_DD,
  M_LI_S,
  M_LI_SS,
  M_LL_AB,
  M_LLD_AB,
  M_LLE_AB,
  M_LQ_AB,
  M_LW_AB,
  M_LWE_AB,
  M_LWC0_AB,
  M_LWC1_AB,
  M_LWC2_AB,
  M_LWC3_AB,
  M_LWL_AB,
  M_LWLE_AB,
  M_LWM_AB,
  M_LWP_AB,
  M_LWR_AB,
  M_LWRE_AB,
  M_LWU_AB,
  M_MSGSND,
  M_MSGLD,
  M_MSGLD_T,
  M_MSGWAIT,
  M_MSGWAIT_T,
  M_MOVE,
  M_MOVEP,
  M_MUL,
  M_MUL_I,
  M_MULO,
  M_MULO_I,
  M_MULOU,
  M_MULOU_I,
  M_NOR_I,
  M_OR_I,
  M_PREF_AB,
  M_PREFE_AB,
  M_REM_3,
  M_REM_3I,
  M_REMU_3,
  M_REMU_3I,
  M_DROL,
  M_ROL,
  M_DROL_I,
  M_ROL_I,
  M_DROR,
  M_ROR,
  M_DROR_I,
  M_ROR_I,
  M_S_DA,
  M_S_DAB,
  M_S_S,
  M_SAA_AB,
  M_SAAD_AB,
  M_SC_AB,
  M_SCD_AB,
  M_SCE_AB,
  M_SD_AB,
  M_SDC1_AB,
  M_SDC2_AB,
  M_SQC2_AB,
  M_SDC3_AB,
  M_SDL_AB,
  M_SDM_AB,
  M_SDP_AB,
  M_SDR_AB,
  M_SEQ,
  M_SEQ_I,
  M_SGE,
  M_SGE_I,
  M_SGEU,
  M_SGEU_I,
  M_SGT,
  M_SGT_I,
  M_SGTU,
  M_SGTU_I,
  M_SLE,
  M_SLE_I,
  M_SLEU,
  M_SLEU_I,
  M_SLT_I,
  M_SLTU_I,
  M_SNE,
  M_SNE_I,
  M_SB_AB,
  M_SBE_AB,
  M_SH_AB,
  M_SHE_AB,
  M_SQ_AB,
  M_SW_AB,
  M_SWE_AB,
  M_SWC0_AB,
  M_SWC1_AB,
  M_SWC2_AB,
  M_SWC3_AB,
  M_SWL_AB,
  M_SWLE_AB,
  M_SWM_AB,
  M_SWP_AB,
  M_SWR_AB,
  M_SWRE_AB,
  M_SUB_I,
  M_SUBU_I,
  M_SUBU_I_2,
  M_TEQ_I,
  M_TGE_I,
  M_TGEU_I,
  M_TLT_I,
  M_TLTU_I,
  M_TNE_I,
  M_TRUNCWD,
  M_TRUNCWS,
  M_ULD_AB,
  M_ULH_AB,
  M_ULHU_AB,
  M_ULW_AB,
  M_USH_AB,
  M_USW_AB,
  M_USD_AB,
  M_XOR_I,
  M_COP0,
  M_COP1,
  M_COP2,
  M_COP3,
  M_NUM_MACROS
};


/* The order of overloaded instructions matters.  Label arguments and
   register arguments look the same. Instructions that can have either
   for arguments must apear in the correct order in this table for the
   assembler to pick the right one. In other words, entries with
   immediate operands must apear after the same instruction with
   registers.

   Many instructions are short hand for other instructions (i.e., The
   jal <register> instruction is short for jalr <register>).  */

extern const struct mips_operand *decode_mips_operand (const char *);
extern const struct mips_opcode mips_builtin_opcodes[];
extern const int bfd_mips_num_builtin_opcodes;
extern struct mips_opcode *mips_opcodes;
extern int bfd_mips_num_opcodes;
#define NUMOPCODES bfd_mips_num_opcodes


/* The rest of this file adds definitions for the mips16 TinyRISC
   processor.  */

/* These are the bitmasks and shift counts used for the different
   fields in the instruction formats.  Other than OP, no masks are
   provided for the fixed portions of an instruction, since they are
   not needed.

   The I format uses IMM11.

   The RI format uses RX and IMM8.

   The RR format uses RX, and RY.

   The RRI format uses RX, RY, and IMM5.

   The RRR format uses RX, RY, and RZ.

   The RRI_A format uses RX, RY, and IMM4.

   The SHIFT format uses RX, RY, and SHAMT.

   The I8 format uses IMM8.

   The I8_MOVR32 format uses RY and REGR32.

   The IR_MOV32R format uses REG32R and MOV32Z.

   The I64 format uses IMM8.

   The RI64 format uses RY and IMM5.
   */

#define MIPS16OP_MASK_OP	0x1f
#define MIPS16OP_SH_OP		11
#define MIPS16OP_MASK_IMM11	0x7ff
#define MIPS16OP_SH_IMM11	0
#define MIPS16OP_MASK_RX	0x7
#define MIPS16OP_SH_RX		8
#define MIPS16OP_MASK_IMM8	0xff
#define MIPS16OP_SH_IMM8	0
#define MIPS16OP_MASK_RY	0x7
#define MIPS16OP_SH_RY		5
#define MIPS16OP_MASK_IMM5	0x1f
#define MIPS16OP_SH_IMM5	0
#define MIPS16OP_MASK_RZ	0x7
#define MIPS16OP_SH_RZ		2
#define MIPS16OP_MASK_IMM4	0xf
#define MIPS16OP_SH_IMM4	0
#define MIPS16OP_MASK_REGR32	0x1f
#define MIPS16OP_SH_REGR32	0
#define MIPS16OP_MASK_REG32R	0x1f
#define MIPS16OP_SH_REG32R	3
#define MIPS16OP_EXTRACT_REG32R(i) ((((i) >> 5) & 7) | ((i) & 0x18))
#define MIPS16OP_MASK_MOVE32Z	0x7
#define MIPS16OP_SH_MOVE32Z	0
#define MIPS16OP_MASK_IMM6	0x3f
#define MIPS16OP_SH_IMM6	5

/* These are the characters which may appears in the args field of a MIPS16
   instruction.  They appear in the order in which the fields appear when the
   instruction is used.  Commas and parentheses in the args string are ignored
   when assembling, and written into the output when disassembling.

   "y" 3 bit register (MIPS16OP_*_RY)
   "x" 3 bit register (MIPS16OP_*_RX)
   "z" 3 bit register (MIPS16OP_*_RZ)
   "Z" 3 bit register (MIPS16OP_*_MOVE32Z)
   "v" 3 bit same register as source and destination (MIPS16OP_*_RX)
   "w" 3 bit same register as source and destination (MIPS16OP_*_RY)
   "0" zero register ($0)
   "S" stack pointer ($sp or $29)
   "P" program counter
   "R" return address register ($ra or $31)
   "X" 5 bit MIPS register (MIPS16OP_*_REGR32)
   "Y" 5 bit MIPS register (MIPS16OP_*_REG32R)
   "6" 6 bit unsigned break code (MIPS16OP_*_IMM6)
   "a" 26 bit jump address
   "i" likewise, but flips bit 0
   "e" 11 bit extension value
   "l" register list for entry instruction
   "L" register list for exit instruction

   "I" an immediate value used for macros

   The remaining codes may be extended.  Except as otherwise noted,
   the full extended operand is a 16 bit signed value.
   "<" 3 bit unsigned shift count * 0 (MIPS16OP_*_RZ) (full 5 bit unsigned)
   ">" 3 bit unsigned shift count * 0 (MIPS16OP_*_RX) (full 5 bit unsigned)
   "[" 3 bit unsigned shift count * 0 (MIPS16OP_*_RZ) (full 6 bit unsigned)
   "]" 3 bit unsigned shift count * 0 (MIPS16OP_*_RX) (full 6 bit unsigned)
   "4" 4 bit signed immediate * 0 (MIPS16OP_*_IMM4) (full 15 bit signed)
   "5" 5 bit unsigned immediate * 0 (MIPS16OP_*_IMM5)
   "H" 5 bit unsigned immediate * 2 (MIPS16OP_*_IMM5)
   "W" 5 bit unsigned immediate * 4 (MIPS16OP_*_IMM5)
   "D" 5 bit unsigned immediate * 8 (MIPS16OP_*_IMM5)
   "j" 5 bit signed immediate * 0 (MIPS16OP_*_IMM5)
   "8" 8 bit unsigned immediate * 0 (MIPS16OP_*_IMM8)
   "V" 8 bit unsigned immediate * 4 (MIPS16OP_*_IMM8)
   "C" 8 bit unsigned immediate * 8 (MIPS16OP_*_IMM8)
   "U" 8 bit unsigned immediate * 0 (MIPS16OP_*_IMM8) (full 16 bit unsigned)
   "k" 8 bit signed immediate * 0 (MIPS16OP_*_IMM8)
   "K" 8 bit signed immediate * 8 (MIPS16OP_*_IMM8)
   "p" 8 bit conditional branch address (MIPS16OP_*_IMM8)
   "q" 11 bit branch address (MIPS16OP_*_IMM11)
   "A" 8 bit PC relative address * 4 (MIPS16OP_*_IMM8)
   "B" 5 bit PC relative address * 8 (MIPS16OP_*_IMM5)
   "E" 5 bit PC relative address * 4 (MIPS16OP_*_IMM5)
   "m" 7 bit register list for save instruction (18 bit extended)
   "M" 7 bit register list for restore instruction (18 bit extended)
  */

/* Save/restore encoding for the args field when all 4 registers are
   either saved as arguments or saved/restored as statics.  */
#define MIPS16_ALL_ARGS    0xe
#define MIPS16_ALL_STATICS 0xb

/* For the mips16, we use the same opcode table format and a few of
   the same flags.  However, most of the flags are different.  */

/* Modifies the register in MIPS16OP_*_RX.  */
#define MIPS16_INSN_WRITE_X		    0x00000001
/* Modifies the register in MIPS16OP_*_RY.  */
#define MIPS16_INSN_WRITE_Y		    0x00000002
/* Modifies the register in MIPS16OP_*_RZ.  */
#define MIPS16_INSN_WRITE_Z		    0x00000004
/* Modifies the T ($24) register.  */
#define MIPS16_INSN_WRITE_T		    0x00000008
/* Modifies the SP ($29) register.  */
#define MIPS16_INSN_WRITE_SP		    0x00000010
/* Modifies the RA ($31) register.  */
#define MIPS16_INSN_WRITE_31		    0x00000020
/* Modifies the general purpose register in MIPS16OP_*_REG32R.  */
#define MIPS16_INSN_WRITE_GPR_Y		    0x00000040
/* Reads the register in MIPS16OP_*_RX.  */
#define MIPS16_INSN_READ_X		    0x00000080
/* Reads the register in MIPS16OP_*_RY.  */
#define MIPS16_INSN_READ_Y		    0x00000100
/* Reads the register in MIPS16OP_*_MOVE32Z.  */
#define MIPS16_INSN_READ_Z		    0x00000200
/* Reads the T ($24) register.  */
#define MIPS16_INSN_READ_T		    0x00000400
/* Reads the SP ($29) register.  */
#define MIPS16_INSN_READ_SP		    0x00000800
/* Reads the RA ($31) register.  */
#define MIPS16_INSN_READ_31		    0x00001000
/* Reads the program counter.  */
#define MIPS16_INSN_READ_PC		    0x00002000
/* Reads the general purpose register in MIPS16OP_*_REGR32.  */
#define MIPS16_INSN_READ_GPR_X		    0x00004000
/* Is an unconditional branch insn. */
#define MIPS16_INSN_UNCOND_BRANCH	    0x00008000
/* Is a conditional branch insn. */
#define MIPS16_INSN_COND_BRANCH		    0x00010000

/* The following flags have the same value for the mips16 opcode
   table:

   INSN_ISA3

   INSN_UNCOND_BRANCH_DELAY
   INSN_COND_BRANCH_DELAY
   INSN_COND_BRANCH_LIKELY (never used)
   INSN_READ_HI
   INSN_READ_LO
   INSN_WRITE_HI
   INSN_WRITE_LO
   INSN_TRAP
   FP_D (never used)
   */

extern const struct mips_operand *decode_mips16_operand (char, bfd_boolean);
extern const struct mips_opcode mips16_opcodes[];
extern const int bfd_mips16_num_opcodes;

/* These are the bit masks and shift counts used for the different fields
   in the microMIPS instruction formats.  No masks are provided for the
   fixed portions of an instruction, since they are not needed.  */

#define MICROMIPSOP_MASK_IMMEDIATE	0xffff
#define MICROMIPSOP_SH_IMMEDIATE	0
#define MICROMIPSOP_MASK_DELTA		0xffff
#define MICROMIPSOP_SH_DELTA		0
#define MICROMIPSOP_MASK_CODE10		0x3ff
#define MICROMIPSOP_SH_CODE10		16	/* 10-bit wait code.  */
#define MICROMIPSOP_MASK_TRAP		0xf
#define MICROMIPSOP_SH_TRAP		12	/* 4-bit trap code.  */
#define MICROMIPSOP_MASK_SHAMT		0x1f
#define MICROMIPSOP_SH_SHAMT		11
#define MICROMIPSOP_MASK_TARGET		0x3ffffff
#define MICROMIPSOP_SH_TARGET		0
#define MICROMIPSOP_MASK_EXTLSB		0x1f	/* "ext" LSB.  */
#define MICROMIPSOP_SH_EXTLSB		6
#define MICROMIPSOP_MASK_EXTMSBD	0x1f	/* "ext" MSBD.  */
#define MICROMIPSOP_SH_EXTMSBD		11
#define MICROMIPSOP_MASK_INSMSB		0x1f	/* "ins" MSB.  */
#define MICROMIPSOP_SH_INSMSB		11
#define MICROMIPSOP_MASK_CODE		0x3ff
#define MICROMIPSOP_SH_CODE		16	/* 10-bit higher break code. */
#define MICROMIPSOP_MASK_CODE2		0x3ff
#define MICROMIPSOP_SH_CODE2		6	/* 10-bit lower break code.  */
#define MICROMIPSOP_MASK_CACHE		0x1f
#define MICROMIPSOP_SH_CACHE		21	/* 5-bit cache op.  */
#define MICROMIPSOP_MASK_SEL		0x7
#define MICROMIPSOP_SH_SEL		11
#define MICROMIPSOP_MASK_OFFSET12	0xfff
#define MICROMIPSOP_SH_OFFSET12		0
#define MICROMIPSOP_MASK_3BITPOS	0x7
#define MICROMIPSOP_SH_3BITPOS		21
#define MICROMIPSOP_MASK_STYPE		0x1f
#define MICROMIPSOP_SH_STYPE		16
#define MICROMIPSOP_MASK_OFFSET10	0x3ff
#define MICROMIPSOP_SH_OFFSET10		6
#define MICROMIPSOP_MASK_RS		0x1f
#define MICROMIPSOP_SH_RS		16
#define MICROMIPSOP_MASK_RT		0x1f
#define MICROMIPSOP_SH_RT		21
#define MICROMIPSOP_MASK_RD		0x1f
#define MICROMIPSOP_SH_RD		11
#define MICROMIPSOP_MASK_FS		0x1f
#define MICROMIPSOP_SH_FS		16
#define MICROMIPSOP_MASK_FT		0x1f
#define MICROMIPSOP_SH_FT		21
#define MICROMIPSOP_MASK_FD		0x1f
#define MICROMIPSOP_SH_FD		11
#define MICROMIPSOP_MASK_FR		0x1f
#define MICROMIPSOP_SH_FR		6
#define MICROMIPSOP_MASK_RS3		0x1f
#define MICROMIPSOP_SH_RS3		6
#define MICROMIPSOP_MASK_PREFX		0x1f
#define MICROMIPSOP_SH_PREFX		11
#define MICROMIPSOP_MASK_BCC		0x7
#define MICROMIPSOP_SH_BCC		18
#define MICROMIPSOP_MASK_CCC		0x7
#define MICROMIPSOP_SH_CCC		13
#define MICROMIPSOP_MASK_COPZ		0x7fffff
#define MICROMIPSOP_SH_COPZ		3

#define MICROMIPSOP_MASK_MB		0x7
#define MICROMIPSOP_SH_MB		23
#define MICROMIPSOP_MASK_MC		0x7
#define MICROMIPSOP_SH_MC		4
#define MICROMIPSOP_MASK_MD		0x7
#define MICROMIPSOP_SH_MD		7
#define MICROMIPSOP_MASK_ME		0x7
#define MICROMIPSOP_SH_ME		1
#define MICROMIPSOP_MASK_MF		0x7
#define MICROMIPSOP_SH_MF		3
#define MICROMIPSOP_MASK_MG		0x7
#define MICROMIPSOP_SH_MG		0
#define MICROMIPSOP_MASK_MH		0x7
#define MICROMIPSOP_SH_MH		7
#define MICROMIPSOP_MASK_MJ		0x1f
#define MICROMIPSOP_SH_MJ		0
#define MICROMIPSOP_MASK_ML		0x7
#define MICROMIPSOP_SH_ML		4
#define MICROMIPSOP_MASK_MM		0x7
#define MICROMIPSOP_SH_MM		1
#define MICROMIPSOP_MASK_MN		0x7
#define MICROMIPSOP_SH_MN		4
#define MICROMIPSOP_MASK_MP		0x1f
#define MICROMIPSOP_SH_MP		5
#define MICROMIPSOP_MASK_MQ		0x7
#define MICROMIPSOP_SH_MQ		7

#define MICROMIPSOP_MASK_IMMA		0x7f
#define MICROMIPSOP_SH_IMMA		0
#define MICROMIPSOP_MASK_IMMB		0x7
#define MICROMIPSOP_SH_IMMB		1
#define MICROMIPSOP_MASK_IMMC		0xf
#define MICROMIPSOP_SH_IMMC		0
#define MICROMIPSOP_MASK_IMMD		0x3ff
#define MICROMIPSOP_SH_IMMD		0
#define MICROMIPSOP_MASK_IMME		0x7f
#define MICROMIPSOP_SH_IMME		0
#define MICROMIPSOP_MASK_IMMF		0xf
#define MICROMIPSOP_SH_IMMF		0
#define MICROMIPSOP_MASK_IMMG		0xf
#define MICROMIPSOP_SH_IMMG		0
#define MICROMIPSOP_MASK_IMMH		0xf
#define MICROMIPSOP_SH_IMMH		0
#define MICROMIPSOP_MASK_IMMI		0x7f
#define MICROMIPSOP_SH_IMMI		0
#define MICROMIPSOP_MASK_IMMJ		0xf
#define MICROMIPSOP_SH_IMMJ		0
#define MICROMIPSOP_MASK_IMML		0xf
#define MICROMIPSOP_SH_IMML		0
#define MICROMIPSOP_MASK_IMMM		0x7
#define MICROMIPSOP_SH_IMMM		1
#define MICROMIPSOP_MASK_IMMN		0x3
#define MICROMIPSOP_SH_IMMN		4
#define MICROMIPSOP_MASK_IMMO		0xf
#define MICROMIPSOP_SH_IMMO		0
#define MICROMIPSOP_MASK_IMMP		0x1f
#define MICROMIPSOP_SH_IMMP		0
#define MICROMIPSOP_MASK_IMMQ		0x7fffff
#define MICROMIPSOP_SH_IMMQ		0
#define MICROMIPSOP_MASK_IMMU		0x1f
#define MICROMIPSOP_SH_IMMU		0
#define MICROMIPSOP_MASK_IMMW		0x3f
#define MICROMIPSOP_SH_IMMW		1
#define MICROMIPSOP_MASK_IMMX		0xf
#define MICROMIPSOP_SH_IMMX		1
#define MICROMIPSOP_MASK_IMMY		0x1ff
#define MICROMIPSOP_SH_IMMY		1

/* MIPS DSP ASE */
#define MICROMIPSOP_MASK_DSPACC		0x3
#define MICROMIPSOP_SH_DSPACC		14
#define MICROMIPSOP_MASK_DSPSFT		0x3f
#define MICROMIPSOP_SH_DSPSFT		16
#define MICROMIPSOP_MASK_SA3		0x7
#define MICROMIPSOP_SH_SA3		13
#define MICROMIPSOP_MASK_SA4		0xf
#define MICROMIPSOP_SH_SA4		12
#define MICROMIPSOP_MASK_IMM8		0xff
#define MICROMIPSOP_SH_IMM8		13
#define MICROMIPSOP_MASK_IMM10		0x3ff
#define MICROMIPSOP_SH_IMM10		16
#define MICROMIPSOP_MASK_WRDSP		0x3f
#define MICROMIPSOP_SH_WRDSP		14
#define MICROMIPSOP_MASK_BP		0x3
#define MICROMIPSOP_SH_BP		14

/* Placeholders for fields that only exist in the traditional 32-bit
   instruction encoding; see the comment above for details.  */
#define MICROMIPSOP_MASK_CODE20		0
#define MICROMIPSOP_SH_CODE20		0
#define MICROMIPSOP_MASK_PERFREG	0
#define MICROMIPSOP_SH_PERFREG		0
#define MICROMIPSOP_MASK_CODE19		0
#define MICROMIPSOP_SH_CODE19		0
#define MICROMIPSOP_MASK_ALN		0
#define MICROMIPSOP_SH_ALN		0
#define MICROMIPSOP_MASK_VECBYTE	0
#define MICROMIPSOP_SH_VECBYTE		0
#define MICROMIPSOP_MASK_VECALIGN	0
#define MICROMIPSOP_SH_VECALIGN		0
#define MICROMIPSOP_MASK_DSPACC_S	0
#define MICROMIPSOP_SH_DSPACC_S	 	0
#define MICROMIPSOP_MASK_DSPSFT_7	0
#define MICROMIPSOP_SH_DSPSFT_7	 	0
#define MICROMIPSOP_MASK_RDDSP		0
#define MICROMIPSOP_SH_RDDSP		0
#define MICROMIPSOP_MASK_MT_U		0
#define MICROMIPSOP_SH_MT_U		0
#define MICROMIPSOP_MASK_MT_H		0
#define MICROMIPSOP_SH_MT_H		0
#define MICROMIPSOP_MASK_MTACC_T	0
#define MICROMIPSOP_SH_MTACC_T		0
#define MICROMIPSOP_MASK_MTACC_D	0
#define MICROMIPSOP_SH_MTACC_D		0
#define MICROMIPSOP_MASK_BBITIND	0
#define MICROMIPSOP_SH_BBITIND		0
#define MICROMIPSOP_MASK_CINSPOS	0
#define MICROMIPSOP_SH_CINSPOS		0
#define MICROMIPSOP_MASK_CINSLM1	0
#define MICROMIPSOP_SH_CINSLM1		0
#define MICROMIPSOP_MASK_SEQI		0
#define MICROMIPSOP_SH_SEQI		0
#define MICROMIPSOP_SH_OFFSET_A		0
#define MICROMIPSOP_MASK_OFFSET_A	0
#define MICROMIPSOP_SH_OFFSET_B		0
#define MICROMIPSOP_MASK_OFFSET_B	0
#define MICROMIPSOP_SH_OFFSET_C		0
#define MICROMIPSOP_MASK_OFFSET_C	0
#define MICROMIPSOP_SH_RZ		0
#define MICROMIPSOP_MASK_RZ		0
#define MICROMIPSOP_SH_FZ		0
#define MICROMIPSOP_MASK_FZ		0

/* microMIPS Enhanced VA Scheme */
#define MICROMIPSOP_SH_EVAOFFSET	0
#define MICROMIPSOP_MASK_EVAOFFSET	0x1ff

/* These are the characters which may appears in the args field of a microMIPS
   instruction.  They appear in the order in which the fields appear
   when the instruction is used.  Commas and parentheses in the args
   string are ignored when assembling, and written into the output
   when disassembling.

   The followings are for 16-bit microMIPS instructions.

   "ma" must be $28
   "mc" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_MC) at bit 4
        The same register used as both source and target.
   "md" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_MD) at bit 7
   "me" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_ME) at bit 1
        The same register used as both source and target.
   "mf" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_MF) at bit 3
   "mg" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_MG) at bit 0
   "mh" 3-bit MIPS register pair (MICROMIPSOP_*_MH) at bit 7
   "mj" 5-bit MIPS registers (MICROMIPSOP_*_MJ) at bit 0
   "ml" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_ML) at bit 4
   "mm" 3-bit MIPS registers 0, 2, 3, 16-20 (MICROMIPSOP_*_MM) at bit 1
   "mn" 3-bit MIPS registers 0, 2, 3, 16-20 (MICROMIPSOP_*_MN) at bit 4
   "mp" 5-bit MIPS registers (MICROMIPSOP_*_MP) at bit 5
   "mq" 3-bit MIPS registers 0, 2-7, 17 (MICROMIPSOP_*_MQ) at bit 7
   "mr" must be program counter
   "ms" must be $29
   "mt" must be the same as the previous register
   "mx" must be the same as the destination register
   "my" must be $31
   "mz" must be $0

   "mA" 7-bit immediate (-64 .. 63) << 2 (MICROMIPSOP_*_IMMA)
   "mB" 3-bit immediate (-1, 1, 4, 8, 12, 16, 20, 24) (MICROMIPSOP_*_IMMB)
   "mC" 4-bit immediate (1, 2, 3, 4, 7, 8, 15, 16, 31, 32, 63, 64, 128, 255,
        32768, 65535) (MICROMIPSOP_*_IMMC)
   "mD" 10-bit branch address (-512 .. 511) << 1 (MICROMIPSOP_*_IMMD)
   "mE" 7-bit branch address (-64 .. 63) << 1 (MICROMIPSOP_*_IMME)
   "mF" 4-bit immediate (0 .. 15)  (MICROMIPSOP_*_IMMF)
   "mG" 4-bit immediate (-1 .. 14) (MICROMIPSOP_*_IMMG)
   "mH" 4-bit immediate (0 .. 15) << 1 (MICROMIPSOP_*_IMMH)
   "mI" 7-bit immediate (-1 .. 126) (MICROMIPSOP_*_IMMI)
   "mJ" 4-bit immediate (0 .. 15) << 2 (MICROMIPSOP_*_IMMJ)
   "mL" 4-bit immediate (0 .. 15) (MICROMIPSOP_*_IMML)
   "mM" 3-bit immediate (1 .. 8) (MICROMIPSOP_*_IMMM)
   "mN" 2-bit immediate (0 .. 3) for register list (MICROMIPSOP_*_IMMN)
   "mO" 4-bit immediate (0 .. 15) (MICROMIPSOP_*_IMML)
   "mP" 5-bit immediate (0 .. 31) << 2 (MICROMIPSOP_*_IMMP)
   "mU" 5-bit immediate (0 .. 31) << 2 (MICROMIPSOP_*_IMMU)
   "mW" 6-bit immediate (0 .. 63) << 2 (MICROMIPSOP_*_IMMW)
   "mX" 4-bit immediate (-8 .. 7) (MICROMIPSOP_*_IMMX)
   "mY" 9-bit immediate (-258 .. -3, 2 .. 257) << 2 (MICROMIPSOP_*_IMMY)
   "mZ" must be zero

   In most cases 32-bit microMIPS instructions use the same characters
   as MIPS (with ADDIUPC being a notable exception, but there are some
   others too).

   "." 10-bit signed offset/number (MICROMIPSOP_*_OFFSET10)
   "1" 5-bit sync type (MICROMIPSOP_*_STYPE)
   "<" 5-bit shift amount (MICROMIPSOP_*_SHAMT)
   ">" shift amount between 32 and 63, stored after subtracting 32
       (MICROMIPSOP_*_SHAMT)
   "\" 3-bit position for ASET and ACLR (MICROMIPSOP_*_3BITPOS)
   "|" 4-bit trap code (MICROMIPSOP_*_TRAP)
   "~" 12-bit signed offset (MICROMIPSOP_*_OFFSET12)
   "a" 26-bit target address (MICROMIPSOP_*_TARGET)
   "+i" likewise, but flips bit 0
   "b" 5-bit base register (MICROMIPSOP_*_RS)
   "c" 10-bit higher breakpoint code (MICROMIPSOP_*_CODE)
   "d" 5-bit destination register specifier (MICROMIPSOP_*_RD)
   "h" 5-bit PREFX hint (MICROMIPSOP_*_PREFX)
   "i" 16-bit unsigned immediate (MICROMIPSOP_*_IMMEDIATE)
   "j" 16-bit signed immediate (MICROMIPSOP_*_DELTA)
   "k" 5-bit cache opcode in target register position (MICROMIPSOP_*_CACHE)
   "n" register list for 32-bit LWM/SWM instruction (MICROMIPSOP_*_RT)
   "o" 16-bit signed offset (MICROMIPSOP_*_DELTA)
   "p" 16-bit PC-relative branch target address (MICROMIPSOP_*_DELTA)
   "q" 10-bit lower breakpoint code (MICROMIPSOP_*_CODE2)
   "r" 5-bit same register used as both source and target (MICROMIPSOP_*_RS)
   "s" 5-bit source register specifier (MICROMIPSOP_*_RS)
   "t" 5-bit target register (MICROMIPSOP_*_RT)
   "u" 16-bit upper 16 bits of address (MICROMIPSOP_*_IMMEDIATE)
   "v" 5-bit same register used as both source and destination
       (MICROMIPSOP_*_RS)
   "w" 5-bit same register used as both target and destination
       (MICROMIPSOP_*_RT)
   "y" 5-bit source 3 register for ALNV.PS (MICROMIPSOP_*_RS3)
   "z" must be zero register
   "C" 23-bit coprocessor function code (MICROMIPSOP_*_COPZ)
   "B" 10-bit syscall/wait function code (MICROMIPSOP_*_CODE10)
   "K" 5-bit Hardware Register (RDHWR instruction) (MICROMIPSOP_*_RS)

   "+A" 5-bit INS/EXT/DINS/DEXT/DINSM/DEXTM position, which becomes
        LSB (MICROMIPSOP_*_EXTLSB).
	Enforces: 0 <= pos < 32.
   "+B" 5-bit INS/DINS size, which becomes MSB (MICROMIPSOP_*_INSMSB).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 0 < (pos+size) <= 32.
   "+C" 5-bit EXT/DEXT size, which becomes MSBD (MICROMIPSOP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 0 < (pos+size) <= 32.
	(Also used by DEXT w/ different limits, but limits for
	that are checked by the M_DEXT macro.)
   "+E" 5-bit DINSU/DEXTU position, which becomes LSB-32 (MICROMIPSOP_*_EXTLSB).
	Enforces: 32 <= pos < 64.
   "+F" 5-bit DINSM/DINSU size, which becomes MSB-32 (MICROMIPSOP_*_INSMSB).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.
   "+G" 5-bit DEXTM size, which becomes MSBD-32 (MICROMIPSOP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.
   "+H" 5-bit DEXTU size, which becomes MSBD (MICROMIPSOP_*_EXTMSBD).
	Requires that "+A" or "+E" occur first to set position.
	Enforces: 32 < (pos+size) <= 64.

   PC-relative addition (ADDIUPC) instruction:
   "mQ" 23-bit offset (-4194304 .. 4194303) << 2 (MICROMIPSOP_*_IMMQ)
   "mb" 3-bit MIPS registers 2-7, 16, 17 (MICROMIPSOP_*_MB) at bit 23

   Floating point instructions:
   "D" 5-bit destination register (MICROMIPSOP_*_FD)
   "M" 3-bit compare condition code (MICROMIPSOP_*_CCC)
   "N" 3-bit branch condition code (MICROMIPSOP_*_BCC)
   "R" 5-bit fr source 3 register (MICROMIPSOP_*_FR)
   "S" 5-bit fs source 1 register (MICROMIPSOP_*_FS)
   "T" 5-bit ft source 2 register (MICROMIPSOP_*_FT)
   "V" 5-bit same register used as floating source and destination or target
       (MICROMIPSOP_*_FS)

   Coprocessor instructions:
   "E" 5-bit target register (MICROMIPSOP_*_RT)
   "G" 5-bit source register (MICROMIPSOP_*_RS)
   "H" 3-bit sel field for (D)MTC* and (D)MFC* (MICROMIPSOP_*_SEL)

   Macro instructions:
   "A" general 32 bit expression
   "I" 32-bit immediate (value placed in imm_expr).
   "+I" 32-bit immediate (value placed in imm2_expr).
   "F" 64-bit floating point constant in .rdata
   "L" 64-bit floating point constant in .lit8
   "f" 32-bit floating point constant
   "l" 32-bit floating point constant in .lit4

   DSP ASE usage:
   "2" 2-bit unsigned immediate for byte align (MICROMIPSOP_*_BP)
   "3" 3-bit unsigned immediate (MICROMIPSOP_*_SA3)
   "4" 4-bit unsigned immediate (MICROMIPSOP_*_SA4)
   "5" 8-bit unsigned immediate (MICROMIPSOP_*_IMM8)
   "6" 5-bit unsigned immediate (MICROMIPSOP_*_RS)
   "7" 2-bit DSP accumulator register (MICROMIPSOP_*_DSPACC)
   "8" 6-bit unsigned immediate (MICROMIPSOP_*_WRDSP)
   "0" 6-bit signed immediate (MICROMIPSOP_*_DSPSFT)
   "@" 10-bit signed immediate (MICROMIPSOP_*_IMM10)
   "^" 5-bit unsigned immediate (MICROMIPSOP_*_RD)

   microMIPS Enhanced VA Scheme:
   "+j" 9-bit signed offset in bit 0 (OP_*_EVAOFFSET)

   Other:
   "()" parens surrounding optional value
   ","  separates operands
   "+"  start of extension sequence
   "m"  start of microMIPS extension sequence

   Characters used so far, for quick reference when adding more:
   "12345678 0"
   "<>(),+.@\^|~"
   "ABCDEFGHI KLMN   RST V    "
   "abcd f hijklmnopqrstuvw yz"

   Extension character sequences used so far ("+" followed by the
   following), for quick reference when adding more:
   ""
   ""
   "ABCEFGHI"
   "ij"

   Extension character sequences used so far ("m" followed by the
   following), for quick reference when adding more:
   ""
   ""
   " BCDEFGHIJ LMNOPQ   U WXYZ"
   " bcdefghij lmn pq st   xyz"
*/

extern const struct mips_operand *decode_micromips_operand (const char *);
extern const struct mips_opcode micromips_opcodes[];
extern const int bfd_micromips_num_opcodes;

/* A NOP insn impemented as "or at,at,zero".
   Used to implement -mfix-loongson2f.  */
#define LOONGSON2F_NOP_INSN	0x00200825

#endif /* _MIPS_H_ */

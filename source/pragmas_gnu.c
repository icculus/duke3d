/*
 * Inline assembly.
 *
 * Initial PLATFORM_UNIX work done by Andrew Henderson. The DOS stuff is
 *  Ken's original code, and was in pragmas.h
 *
 * Please do NOT harrass Ken Silverman about any code modifications
 *  (including this file) to BUILD.
 */

/*
 * "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 * Ken Silverman's official web site: "http://www.advsys.net/ken"
 * See the included license file "BUILDLIC.TXT" for license info.
 * This file has been modified from Ken Silverman's original release
 */

#if (defined __WATCOMC__)
  #if ((defined PLATFORM_DOS) || (defined PLATFORM_WIN32))
    #error Do not compile this. Just include pragmas.h instead.
  #endif
#endif

#if (defined USE_I386_ASM)

#if (!defined __GNUC__)
#error This file is filled with GNU C-specific inline asm.
#endif

static long dmval;

/* rcg02132001 Cygwin support. */
#if (defined C_IDENTIFIERS_UNDERSCORED)
#define SYM_dmval   "_dmval"
#else
#define SYM_dmval   "dmval"
#endif

static __inline__ void _touch_dmval_stop_compiler_whining(void)
{
    dmval = 0;
}

unsigned long getkensmessagecrc(long param) {
    long retval;
    __asm__ __volatile__ (
        "xorl %%eax, %%eax   \n\t"
        "movl $32, %%ecx   \n\t"
        "kensmsgbeg: movl -4(%%ebx,%%ecx,4), %%edx   \n\t"
        "rorl %%cl, %%edx   \n\t"
        "adcl %%edx, %%eax   \n\t"
        "bswapl %%eax   \n\t"
        "loop kensmsgbeg   \n\t"
     : "=a" (retval) : "b" (param) : "ecx", "edx", "cc");
    return(retval);
}

long msqrtasm(int i1)
{
    int retval;
    __asm__ __volatile__ (
      "movl $0x40000000, %%eax   \n\t"
          "movl $0x20000000, %%ebx   \n\t"
          "msqrasm_begit: cmpl %%eax, %%ecx   \n\t"
          "jl msqrasm_skip   \n\t"
          "subl %%eax, %%ecx   \n\t"
          "leal (%%eax, %%ebx, 4), %%eax   \n\t"
          "msqrasm_skip: subl %%ebx, %%eax   \n\t"
          "shrl $1, %%eax   \n\t"
          "shrl $2, %%ebx   \n\t"
          "jnz msqrasm_begit   \n\t"
          "cmpl %%eax, %%ecx   \n\t"
          "sbbl $-1, %%eax   \n\t"
          "shrl $1, %%eax   \n\t"
     : "=a" (retval) : "c" (i1) : "cc", "ebx");
    return(retval);
} /* msqrtasm */

int sqr (int i1) {
  int retval;
  __asm__ __volatile__ (
    "imull 	%%eax, %%eax   \n\t"
   : "=a" (retval) : "a" (i1) : "cc");
  return(retval);
}

int scale (int i1, int i2, int i3) {
  int retval;
  __asm__ __volatile__ (
    "imull 	%%edx   \n\t"
    "idivl 	%%ecx	   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "c" (i3) : "cc");
  return(retval);
}

int mulscale (int i1, int i2, short i3) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl %%cl, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "c" (i3) : "cc");
  return(retval);
}

int mulscale1 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $1, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale2 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $2, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale3 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $3, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale4 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $4, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale5 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $5, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale6 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $6, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale7 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $7, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale8 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $8, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale9 (int i1, int i2) {
  int retval;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $9, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale10 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $10, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale11 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $11, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale12 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $12, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale13 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $13, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale14 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $14, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale15 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $15, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale16 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $16, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale17 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $17, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale18 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $18, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale19 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $19, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale20 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $20, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale21 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $21, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale22 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $22, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale23 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $23, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale24 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $24, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale25 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $25, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale26 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $26, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale27 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $27, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale28 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $28, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale29 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $29, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale30 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $30, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale31 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
    "shrdl $31, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int mulscale32 (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "imull %%edx   \n\t"
   : "=d" (retval) : "a" (i1), "d" (i2) : "cc");
  return(retval);
}

int divmod (int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
    "xorl %%edx, %%edx   \n\t"
    "divl %%ebx   \n\t"
    "movl %%edx, " SYM_dmval "  \n\t"
  : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "memory", "cc");
  return(retval);
}

int dmulscale(int i1, int i2, int i3, int i4, int i5) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl %%cl, %%edx, %%eax        \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4), "c" (i5)
    : "ebx", "cc");
  return(retval);
}

int dmulscale1(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $1, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale2(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $2, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale3(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $3, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale4(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $4, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale5(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $5, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale6(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $6, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale7(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $7, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale8(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $8, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale9(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $9, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale10(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $10, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale11(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $11, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale12(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $12, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale13(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $13, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale14(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $14, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale15(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $15, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale16(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $16, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale17(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $17, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale18(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $18, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale19(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $19, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale20(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $20, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale21(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $21, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale22(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $22, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale23(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $23, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale24(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $24, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale25(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $25, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale26(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $26, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale27(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $27, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale28(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $28, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale29(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $29, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}


int dmulscale30(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $30, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale31(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
	"shrdl $31, %%edx, %%eax   \n\t"
   : "=a" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int dmulscale32(int i1, int i2, int i3, int i4) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"movl %%eax, %%ebx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"movl %%edx, %%esi   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%esi, %%edx   \n\t"
   : "=d" (retval) : "a" (i1), "d" (i2), "S" (i3), "D" (i4)
    : "ebx", "cc");
  return(retval);
}

int tmulscale1(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $1, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale2(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $2, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale3(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $3, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale4(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $4, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale5(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $5, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale6(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $6, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale7(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $7, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale8(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $8, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale9(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $9, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale10(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $10, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale11(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $11, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale12(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $12, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale13(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $13, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale14(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $14, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale15(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $15, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale16(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $16, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale17(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $17, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale18(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $18, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale19(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $19, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale20(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $20, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale21(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $21, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale22(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $22, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale23(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $23, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale24(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $24, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale25(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $25, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale26(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $26, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale27(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $27, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale28(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $28, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale29(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $29, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale30(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $30, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale31(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
	"shrdl $31, %%edx, %%eax   \n\t"
   : "=a" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}

int tmulscale32(int i1, int i2, int i3, int i4, int i5, int i6) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%edx   \n\t"
	"xchgl %%ebx, %%eax   \n\t"
	"xchgl %%ecx, %%edx   \n\t"
	"imull %%edx   \n\t"
	"addl %%eax, %%ebx   \n\t"
	"adcl %%edx, %%ecx   \n\t"
	"movl %%esi, %%eax   \n\t"
	"imull %%edi   \n\t"
	"addl %%ebx, %%eax   \n\t"
	"adcl %%ecx, %%edx   \n\t"
   : "=d" (retval)
    : "a" (i1), "d" (i2), "b" (i3), "c" (i4), "S" (i5), "D" (i6)
    : "cc");
  return(retval);
}


int boundmulscale(int i1, int i2, int i3) {
  int retval = 0;
  __asm__ __volatile__ (
	"imull %%ebx   \n\t"
	"movl %%edx, %%ebx   \n\t"
	"shrdl %%cl, %%edx, %%eax   \n\t"
	"sarl %%cl, %%edx   \n\t"
	"xorl %%eax, %%edx   \n\t"
	"js checkit   \n\t"
	"xorl %%eax, %%edx   \n\t"
	"jz skipboundit   \n\t"
	"cmpl $0xffffffff, %%edx   \n\t"
	"je skipboundit   \n\t"
	"checkit:   \n\t"
	"movl %%ebx, %%eax   \n\t"
	"sarl $31, %%eax   \n\t"
	"xorl $0x7fffffff, %%eax   \n\t"
	"skipboundit:   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2), "c" (i3) : "edx", "cc");
  return(retval);
}

int divscale(int i1, int i2, int i3) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"shll %%cl, %%eax   \n\t"
	"negb  %%cl   \n\t"
	"sarl %%cl, %%edx   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2), "c" (i3) : "edx", "cc");
  return(retval);
}

int divscale1(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"addl %%eax, %%eax   \n\t"
	"sbbl %%edx, %%edx   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}


int divscale2(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $30, %%edx   \n\t"
	"leal (, %%eax, 4), %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale3(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $29, %%edx   \n\t"
	"leal (, %%eax, 8), %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale4(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $28, %%edx   \n\t"
	"shll $4, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale5(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $27, %%edx   \n\t"
	"shll $5, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale6(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $26, %%edx   \n\t"
	"shll $6, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale7(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $25, %%edx   \n\t"
	"shll $7, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale8(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $24, %%edx   \n\t"
	"shll $8, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale9(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $23, %%edx   \n\t"
	"shll $9, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale10(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $22, %%edx   \n\t"
	"shll $10, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale11(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $21, %%edx   \n\t"
	"shll $11, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale12(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $20, %%edx   \n\t"
	"shll $12, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale13(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $19, %%edx   \n\t"
	"shll $13, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale14(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $18, %%edx   \n\t"
	"shll $14, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale15(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $17, %%edx   \n\t"
	"shll $15, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale16(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $16, %%edx   \n\t"
	"shll $16, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale17(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $15, %%edx   \n\t"
	"shll $17, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale18(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $14, %%edx   \n\t"
	"shll $18, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale19(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $13, %%edx   \n\t"
	"shll $19, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale20(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $12, %%edx   \n\t"
	"shll $20, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale21(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $11, %%edx   \n\t"
	"shll $21, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale22(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $10, %%edx   \n\t"
	"shll $22, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale23(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $9, %%edx   \n\t"
	"shll $23, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale24(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $8, %%edx   \n\t"
	"shll $24, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale25(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $7, %%edx   \n\t"
	"shll $25, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale26(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $6, %%edx   \n\t"
	"shll $26, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale27(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $5, %%edx   \n\t"
	"shll $27, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale28(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $4, %%edx   \n\t"
	"shll $28, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale29(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $3, %%edx   \n\t"
	"shll $29, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale30(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $2, %%edx   \n\t"
	"shll $30, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale31(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"movl %%eax, %%edx   \n\t"
	"sarl $1, %%edx   \n\t"
	"shll $31, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2) : "edx", "cc");
  return(retval);
}

int divscale32(int i1, int i2) {
  int retval = 0;
  __asm__ __volatile__ (
	"xorl %%eax, %%eax   \n\t"
	"idivl %%ebx   \n\t"
   : "=a" (retval) : "d" (i1), "b" (i2): "cc");
  return(retval);
}

int mul3 (int i1) {
  int output;
  __asm__ __volatile__ (
    "leal (%1, %1, 2), %1   \n\t"
   : "=r" (output) : "r" (i1) : "cc");
  return (output);
}

int mul5 (int i1) {
  int output;
  __asm__ __volatile__ (
    "leal (%1, %1, 4), %1   \n\t"
   : "=r" (output) : "r" (i1) : "cc");
  return (output);
}

int mul9 (int i1) {
  int output;
  __asm__ __volatile__ (
    "leal (%1, %1, 8), %1   \n\t"
   : "=r" (output) : "r" (i1) : "cc");
  return (output);
}

void clearbuf(void *buffer, int size, long fill_value) {
  __asm__ __volatile__ (
	"rep   \n\t"
    "stosl   \n\t"
   : : "D" (buffer), "c" (size), "a" (fill_value) : "cc");
}

void clearbufbyte(void *buffer, int size, long fill_value) {
  __asm__ __volatile__ (
	"cmpl $4, %%ecx   \n\t"
	"jae longcopya   \n\t"
	"testb $1, %%cl   \n\t"
	"jz preskipa   \n\t"
	"stosb   \n\t"
	"preskipa: shrl $1, %%ecx   \n\t"
	"rep   \n\t"
    "stosw   \n\t"
	"jmp endita   \n\t"
	"longcopya: testl $1, %%edi   \n\t"
	"jz skip1a   \n\t"
	"stosb   \n\t"
	"decl %%ecx   \n\t"
	"skip1a: testl $2, %%edi   \n\t"
	"jz skip2a   \n\t"
	"stosw   \n\t"
	"subl $2, %%ecx   \n\t"
	"skip2a: movl %%ecx, %%ebx   \n\t"
	"shrl $2, %%ecx   \n\t"
    "rep   \n\t"
    "stosl   \n\t"
	"testb $2, %%bl   \n\t"
	"jz skip3a   \n\t"
	"stosw   \n\t"
	"skip3a: testb $1, %%bl   \n\t"
	"jz endita   \n\t"
	"stosb   \n\t"
	"endita:   \n\t"
   : : "D" (buffer), "c" (size), "a" (fill_value) : "ebx", "cc");
}

void copybuf(void *source, void *dest, int size) {
  __asm__ __volatile__ (
	"rep   \n\t"
    "movsl   \n\t"
   : : "S" (source), "D" (dest), "c" (size) : "cc");
}

void copybufbyte(void *source, void *dest, int size) {
  __asm__ __volatile__ (
	"cmpl $4, %%ecx   \n\t"
	"jae longcopyb   \n\t"
	"testb $1, %%cl   \n\t"
	"jz preskipb   \n\t"
	"movsb   \n\t"
	"preskipb: shrl $1, %%ecx   \n\t"
	"rep   \n\t"
    "movsw   \n\t"
	"jmp enditb   \n\t"
	"longcopyb: testl $1, %%edi   \n\t"
	"jz skip1b   \n\t"
	"movsb   \n\t"
	"decl %%ecx   \n\t"
	"skip1b: testl $2, %%edi   \n\t"
	"jz skip2b   \n\t"
	"movsw   \n\t"
	"sub $2, %%ecx   \n\t"
	"skip2b: mov %%ecx, %%ebx   \n\t"
	"shr $2, %%ecx   \n\t"
	"rep   \n\t"
    "movsl   \n\t"
	"testb $2, %%bl   \n\t"
	"jz skip3b   \n\t"
	"movsw   \n\t"
	"skip3b: testb $1, %%bl   \n\t"
	"jz enditb   \n\t"
	"movsb   \n\t"
	"enditb:   \n\t"
   : : "S" (source), "D" (dest), "c" (size) : "ebx", "cc");
}

void copybufreverse(void *source, void *dest, int size) {
  __asm__ __volatile__ (
	"shrl $1, %%ecx   \n\t"
	"jnc skipit1   \n\t"
	"movb (%%esi), %%al   \n\t"
	"decl %%esi   \n\t"
	"movb %%al, (%%edi)   \n\t"
	"incl %%edi   \n\t"
	"skipit1: shrl $1, %%ecx   \n\t"
	"jnc skipit2   \n\t"
	"movw -1(%%esi), %%ax   \n\t"
	"subl $2, %%esi   \n\t"
	"rorw $8, %%ax   \n\t"
	"movw %%ax, (%%edi)   \n\t"
	"addl $2, %%edi   \n\t"
	"skipit2: testl %%ecx, %%ecx   \n\t"
	"jz endloop   \n\t"
	"begloop: movl -3(%%esi), %%eax   \n\t"
	"subl $4, %%esi   \n\t"
	"bswapl %%eax   \n\t"
	"movl %%eax, (%%edi)   \n\t"
	"addl $4, %%edi   \n\t"
	"decl %%ecx   \n\t"
	"jnz begloop   \n\t"
	"endloop:   \n\t"
   : : "S" (source), "D" (dest), "c" (size) : "cc");
}

void qinterpolatedown16 (long *source, int size, int linum, int linum_inc) {
  __asm__ __volatile__ (
	"movl %%ecx, %%ebx   \n\t"
	"shrl $1, %%ecx   \n\t"
	"jz skipbegcalc   \n\t"
	"begqcalc: leal (%%esi, %%edx), %%edi   \n\t"
	"sarl $16, %%edx   \n\t"
	"movl %%edx, (%%eax)   \n\t"
	"leal (%%edi, %%esi), %%edx   \n\t"
	"sarl $16, %%edi   \n\t"
	"movl %%edi, 4(%%eax)   \n\t"
	"addl $8, %%eax   \n\t"
	"decl %%ecx   \n\t"
	"jnz begqcalc   \n\t"
	"testl $1, %%ebx   \n\t"
	"jz skipbegqcalc2   \n\t"
	"skipbegcalc: sarl $16, %%edx   \n\t"
	"movl %%edx, (%%eax)   \n\t"
	"skipbegqcalc2:   \n\t"
  : :"a" (source), "c" (size), "d" (linum), "S" (linum_inc) : "ebx", "edi", "cc", "memory" );
}

void qinterpolatedown16short (long *source, int size, int linum, int linum_inc)
{
  __asm__ __volatile__ (
	"testl %%ecx, %%ecx   \n\t"
	"jz endit   \n\t"
	"testb $2, %%al   \n\t"
	"jz skipalignit   \n\t"
	"movl %%edx, %%ebx   \n\t"
	"sarl $16, %%ebx   \n\t"
	"movw %%bx, (%%eax)   \n\t"
	"addl %%esi, %%edx   \n\t"
	"addl $2, %%eax   \n\t"
	"decl %%ecx   \n\t"
	"jz endit   \n\t"
	"skipalignit: subl $2, %%ecx   \n\t"
	"jc finishit   \n\t"
	"bbegqcalc: movl %%edx, %%ebx   \n\t"
	"addl %%esi, %%edx   \n\t"
	"sarl $16, %%ebx   \n\t"
	"movl %%edx, %%edi   \n\t"
	"andl $0xffff0000, %%edi   \n\t"
	"addl %%esi, %%edx   \n\t"
	"addl %%edi, %%ebx   \n\t"
	"movl %%ebx, (%%eax)   \n\t"
	"addl $4, %%eax   \n\t"
	"subl $2, %%ecx   \n\t"
	"jnc bbegqcalc   \n\t"
	"testb $1, %%cl   \n\t"
	"jz endit   \n\t"
	"finishit: movl %%edx, %%ebx   \n\t"
	"sarl $16, %%ebx   \n\t"
	"movw %%bx, (%%eax)   \n\t"
	"endit:   \n\t"
  : :"a" (source), "c" (size), "d" (linum), "S" (linum_inc) : "ebx", "edi", "cc", "memory");
}

void vlin16first (long i1, long i2) {
  __asm__ __volatile__ (
  	"movb 	(%%edi), %%al   \n\t"
	"movl 	%%ecx, %%eax   \n\t"
	"shrl 	$2, %%ecx   \n\t"
	"   \n\t"
	"begvlin16firsta:   \n\t"
		"movb	%%al, (%%edi)   \n\t"
		"movb 	%%al, 80(%%edi)   \n\t"
		"movb 	%%al, 160(%%edi)   \n\t"
		"movb 	%%al, 240(%%edi)   \n\t"
		"addl 	$320, %%edi   \n\t"
		"decl 	%%ecx   \n\t"
	"jnz 	begvlin16firsta   \n\t"
	"   \n\t"
	"movl 	%%eax, %%ecx   \n\t"
	"andl 	$3, %%ecx   \n\t"
	"jz 	skipfirst   \n\t"
	"begvlin16firstb:   \n\t"
		"movb	%%al, (%%edi)   \n\t"
		"addl 	$80, %%edi   \n\t"
		"decl 	%%ecx   \n\t"
	"jnz begvlin16firstb   \n\t"
	"skipfirst:   \n\t"
  
  : : "D" (i1), "c" (i2) : "cc", "memory");
}

void vlin16 (long i1, long i2) {
  __asm__ __volatile__ (
  	"movl 	%%edi, %%esi   \n\t"
	"begvlin16:   \n\t"
		"movsb   \n\t"
		"addl 	$79, %%edi   \n\t"
		"addl 	$79, %%esi   \n\t"
		"decl 	%%ecx   \n\t"
	"jnz 	begvlin16   \n\t"
  
  : : "D" (i1), "c" (i2) : "cc", "memory");

}

int klabs (int i1) {
  int retval = 0;
  __asm__ __volatile__ (
	"testl %%eax, %%eax   \n\t"
	"jns skipnegate   \n\t"
	"negl %%eax   \n\t"
	"skipnegate:   \n\t"
   : "=a" (retval) : "a" (i1) : "cc");
  return(retval);
}

int ksgn(int i1) {
  int retval = 0;
  __asm__ __volatile__ (
	"addl %%ebx, %%ebx   \n\t"
	"sbbl %%eax, %%eax   \n\t"
	"cmpl %%ebx, %%eax   \n\t"
	"adcb $0, %%al   \n\t"
   : "=a" (retval) : "b" (i1) : "cc");
  return(retval);
}

void swapchar(int i1, int i2) {
  __asm__ __volatile__ (
	"movb (%%eax), %%cl   \n\t"
	"movb (%%ebx), %%ch   \n\t"
	"movb %%cl, (%%ebx)   \n\t"
	"movb %%ch, (%%eax)   \n\t"
   : : "a" (i1), "b" (i2) : "ecx", "cc", "memory");
}

void swapshort(int i1, int i2) {
  __asm__ __volatile__ (
	"movw (%%eax), %%cx   \n\t"
	"movw (%%ebx), %%dx   \n\t"
	"movw %%cx, (%%ebx)   \n\t"
	"movw %%dx, (%%eax)   \n\t"
   : : "a" (i1), "b" (i2) : "ecx", "edx", "cc", "memory");
}


void swaplong(int i1, int i2) {
  __asm__ __volatile__ (
	"movl (%%eax), %%ecx   \n\t"
	"movl (%%ebx), %%edx   \n\t"
	"movl %%ecx, (%%ebx)   \n\t"
	"movl %%edx, (%%eax)   \n\t"
   : : "a" (i1), "b" (i2) : "ecx", "edx", "cc", "memory");
}


/*
#pragma aux swapbuf4 =\
	"begswap:",\
	"mov esi, (%%eax)",\
	"mov edi, (%%ebx)",\
	"mov (%%ebx), esi",\
	"mov (%%eax), edi",\
	"add eax, 4",\
	"add ebx, 4",\
	"dec ecx",\
	"jnz short begswap",\
	parm (%%eax)(%%ebx)[ecx]\
	modify exact [eax ebx ecx esi edi]\

#pragma aux swap64bit =\
	"mov ecx, (%%eax)",\
	"mov edx, (%%ebx)",\
	"mov (%%ebx), ecx",\
	"mov ecx, [eax+4]",\
	"mov (%%eax), edx",\
	"mov edx, [ebx+4]",\
	"mov [ebx+4], ecx",\
	"mov [eax+4], edx",\
	parm (%%eax)(%%ebx)\
	modify exact [ecx edx]\
*/


    /*
	 * swapchar2(ptr1,ptr2,xsiz); is the same as:
	 * swapchar(ptr1,ptr2); swapchar(ptr1+1,ptr2+xsiz);
     */
int swapchar2(int i1, int i2, int i3) {
  int retval = 0;
  __asm__ __volatile__ (
	"addl %%ebx, %%esi   \n\t"
	"movw (%%eax), %%cx   \n\t"
	"movb (%%ebx), %%dl   \n\t"
	"movb %%cl, (%%ebx)   \n\t"
	"movb (%%esi), %%dh   \n\t"
	"movb %%ch, (%%esi)   \n\t"
	"movw %%dx, (%%eax)   \n\t"
   : "=a" (retval) : "a" (i1), "b" (i2), "S" (i3) : "ecx", "edx", "cc", "memory");
    return(retval);
}

/*

	//returns eax%ebx, dmval = eax/edx;
#pragma aux moddiv =\
	"xor edx, edx",\
	"div ebx",\
	"mov dmval, eax",\
	parm [eax][ebx]\
	modify exact [eax edx]\
	value [edx]


	//eax = (unsigned min)umin(eax,ebx)
#pragma aux umin =\
	"sub eax, ebx",\
	"sbb ecx, ecx",\
	"and eax, ecx",\
	"add eax, ebx",\
	parm nomemory [eax][ebx]\
	modify exact [eax ecx]\

	//eax = (unsigned max)umax(eax,ebx)
#pragma aux umax =\
	"sub eax, ebx",\
	"sbb ecx, ecx",\
	"xor ecx, 0xffffffff",\
	"and eax, ecx",\
	"add eax, ebx",\
	parm nomemory [eax][ebx]\
	modify exact [eax ecx]\

#pragma aux kmin =\
	"cmp eax, ebx",\
	"jl skipit",\
	"mov eax, ebx",\
	"skipit:",\
	parm nomemory [eax][ebx]\
	modify exact [eax]\

#pragma aux kmax =\
	"cmp eax, ebx",\
	"jg skipit",\
	"mov eax, ebx",\
	"skipit:",\
	parm nomemory [eax][ebx]\
	modify exact [eax]\

#pragma aux readtimer =\
	"mov al, 0xd2",\
	"out 0x43, al",\
	"in al, 0x40",\
	"shl eax, 24",\
	"in al, 0x40",\
	"rol eax, 8",\
	modify [eax]\

#pragma aux redblueblit = \
	"xor ecx, ecx",\
	"begblit: mov eax, dword ptr [edx+ecx]",\
	"shl eax, 4",\
	"add eax, dword ptr [ebx+ecx]",\
	"mov dword ptr [ecx+0xa0000], eax",\
	"add ecx, 4",\
	"cmp ecx, esi",\
	"jb begblit",\
	parm [ebx][edx][esi]\
	modify exact [eax ecx]\

#pragma aux chainblit =\
	"shr ecx, 1",\
	"jnc prebeg",\
	"mov al, byte ptr [esi+8]",\
	"mov ah, byte ptr [esi+12]",\
	"shl eax, 16",\
	"mov al, byte ptr [esi]",\
	"mov ah, byte ptr [esi+4]",\
	"mov dword ptr [edi], eax",\
	"add esi, 16",\
	"add edi, 4",\
	"test ecx, ecx",\
	"prebeg: jz endit",\
	"beg: mov al, byte ptr [esi+8]",\
	"mov bl, byte ptr [esi+24]",\
	"mov ah, byte ptr [esi+12]",\
	"mov bh, byte ptr [esi+28]",\
	"shl eax, 16",\
	"add edi, 8",\
	"shl ebx, 16",\
	"mov al, byte ptr [esi]",\
	"mov bl, byte ptr [esi+16]",\
	"mov ah, byte ptr [esi+4]",\
	"mov bh, byte ptr [esi+20]",\
	"add esi, 32",\
	"mov dword ptr [edi-8], eax",\
	"dec ecx",\
	"mov dword ptr [edi-4], ebx",\
	"jnz beg",\
	"endit:",\
	parm [esi][edi][ecx]\
	modify exact [eax ebx ecx esi edi]\

static long timeroffs1mhz;
	//accutimeroffs = -8-(t1-t0);
#pragma aux inittimer1mhz =\
	"xor ebx, ebx",\
	"xor ecx, ecx",\
	"in al, 0x61",\
	"or al, 1",\
	"out 0x61, al",\
	"mov al, 0x34",\
	"out 0x43, al",\
	"xor al, al",\
	"out 0x40, al",\
	"mov al, 0xb4",\
	"out 0x43, al",\
	"mov al, 240",\
	"out 0x42, al",\
	"xor al, al",\
	"cli",\
	"out 0x40, al",\
	"dec al",\
	"out 0x42, al",\
	"mov al, 0x04",\
	"out 0x43, al",\
	"in al, 0x40",\
	"mov bl, al",\
	"in al, 0x40",\
	"mov bh, al",\
	"mov al, 0x84",\
	"out 0x43, al",\
	"in al, 0x42",\
	"mov cl, al",\
	"in al, 0x42",\
	"sti",\
	"mov ch, al",\
	"sub ebx, ecx",\
	"sub ebx, 8",\
	"mov timeroffs1mhz, ebx",\
	modify exact [eax ebx ecx]\

#pragma aux uninittimer1mhz =\
	"in al, 0x61",\
	"and al, 252",\
	"out 0x61, al",\
	modify exact [eax]\

	//t = ((ecx-ebx+timeroffs1mhz)&0xfff0)*4095 + ecx;
#pragma aux gettime1mhz =\
	"mov ebx, timeroffs1mhz",\
	"xor ecx, ecx",\
	"mov al, 0x04",\
	"cli",\
	"out 0x43, al",\
	"in al, 0x40",\
	"sub bl, al",\
	"in al, 0x40",\
	"sbb bh, al",\
	"mov al, 0x84",\
	"out 0x43, al",\
	"in al, 0x42",\
	"mov cl, al",\
	"in al, 0x42",\
	"sti",\
	"mov ch, al",\
	"add ebx, ecx",\
	"and ebx, 0x0000fff0",\
	"sub ecx, ebx",\
	"shl ebx, 12",\
	"add ebx, ecx",\
	modify exact [eax ebx ecx]\
	value [ebx]\

	//eax = eax-ebx; if (eax < 0) eax += (1<<28) - (1<<16);
#pragma aux deltatime1mhz =\
	"sub eax, ebx",\
	"jnc skipit",\
	"add eax, 0x0fff0000",\
	"skipit:",\
	parm [ebx][eax]\

*/

#else

/*
 * !!! out of respect to Ken, the ASM version needs to be converted to
 *  portable C, so we can legitimately check this on all platforms.
 */
unsigned long getkensmessagecrc(long param)
{
    return(0x56c764d4);
} /* getkensmessagecrc */

void swapchar(unsigned char *p1, unsigned char *p2)
{
    unsigned char tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
} /* swapchar */

void swapshort(short *p1, short *p2)
{
    short tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
} /* swapshort */

void swaplong(long *p1, long *p2)
{
    long tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
} /* swaplong */

void swapchar2(unsigned char *p1, unsigned char *p2, int xsiz)
{
    swapchar(p1, p2);
    swapchar(p1 + 1, p2 + xsiz);
} /* swapchar2 */


void qinterpolatedown16short (long *source, int size, int linum, int linum_inc)
{
    /* Attempt at a convert to C :/ - DDOI */
    int tmp;

	if (size == 0)
        return;

        /* casting sucks ass.  --ryan. */
	if ( (((unsigned long) source) & 0xFF) != 2)
    {
		*((short *) source) = (short) ( (linum >> 16) & 0xFFFF ) ;
        source = (long *) ( ((short *) source) + 2 );
		linum += linum_inc;
		size--;
	} /* if */

	size -= 2;
	if (size < 0)
        *((short *) source) = (short) ((linum << 16) & 0xFFFF);
    else
    {
        while ( size >= 0)
        {
            tmp = linum;
            linum += linum_inc;
            *source = ((tmp >> 16) + (linum & 0xffff0000));
            linum += linum_inc;
            size -= 2;
            source++;
        } /* while */

        if (size != 1)
            *((short *) source) = (short) ((linum << 16) & 0xFFFF);
    } /* else */
} /* qinterpolatedown16short */

#endif

/* end of pragmas_gnu.c ... */


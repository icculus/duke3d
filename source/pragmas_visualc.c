/*
 * "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 * Ken Silverman's official web site: "http://www.advsys.net/ken"
 * See the included license file "BUILDLIC.TXT" for license info.
 * This file IS NOT A PART OF Ken Silverman's original release.
 */

#ifndef __PRAGMAS_VISUALC_H__
#define __PRAGMAS_VISUALC_H__

#if (!defined _MSC_VER)
#error This should only be included on Microsoft Visual C compiles.
#else

/*
This was converted from pragmas.h with the following Perl script and
 a bunch of manually editing:

#!/usr/bin/perl -w

use strict;

my $in_block = 0;

while (<STDIN>) {
    chomp;
    1 while (s/[ \t]\Z//);  # trim ending whitespace.

    if (s/\);\Z/)/) {
    	print "$_\n{\n    __asm\n    {\n";
    }

   elsif (/\#pragma aux/) {
       $in_block = 1;
    }

    elsif ($_ eq "") {
    	if ($in_block) {
    	    print "    }\n}\n\n";
    	    $in_block = 0;
    	} else {
    	    print "\n";
    	}
    }

    else {
    	if ($in_block) {
    	    1 while (s/\A[ \t]//);
    	    s/\",\\//;
    	    s/\"//;
                print "        ";
    	}
    	print "$_\n";
    }
}
*/


static long dmval = 0;

long is_vmware_running(void);


unsigned long getkensmessagecrc(long param)
{
    __asm
    {
        mov ebx, param
        xor eax, eax
        mov ecx, 32
        beg: mov edx, dword ptr [ebx+ecx*4-4]
        ror edx, cl
        adc eax, edx
        bswap eax
        loop short beg
        mov param, eax
    } /* asm */
    return(param);
}

long msqrtasm(int param)
{
    __asm
    {
        mov ecx, param
        mov eax, 0x40000000
        mov ebx, 0x20000000
        begit: cmp ecx, eax
        jl skip
        sub ecx, eax
        lea eax, [eax+ebx*4]
        skip: sub eax, ebx
        shr eax, 1
        shr ebx, 2
        jnz begit
        cmp ecx, eax
        sbb eax, -1
        shr eax, 1
        mov param, eax
    } /* asm */
    return(param);
}

int sqr(int i1)
{
    __asm
    {
        mov eax, i1
        imul eax, eax
        mov i1, eax
    } /* asm */
    return(i1);
}

long scale(long i1, long i2, long i3)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ecx, i3
        imul edx
        idiv ecx
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale(long i1, long i2, long i3)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ecx, i3
        imul edx
        shrd eax, edx, cl
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale1(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 1
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale2(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 2
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale3(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 3
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale4(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 4
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale5(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 5
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale6(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 6
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale7(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 7
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale8(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 8
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale9(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 9
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale10(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 10
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale11(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 11
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale12(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 12
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale13(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 13
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale14(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 14
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale15(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 15
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale16(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 16
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale17(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 17
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale18(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 18
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale19(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 19
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale20(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 20
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale21(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 21
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale22(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 22
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale23(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 23
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale24(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 24
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale25(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 25
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale26(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 26
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale27(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 27
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale28(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 28
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale29(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 29
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale30(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 30
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale31(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        shrd eax, edx, 31
        mov i1, eax
    } /* asm */
    return(i1);
}

long mulscale32(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        imul edx
        mov i1, edx
    } /* asm */
    return(i1);
}

long dmulscale(long i1, long i2, long i3, long i4, long i5)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        mov ecx, i5
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, cl
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale1(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 1
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale2(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 2
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale3(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 3
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale4(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 4
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale5(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 5
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale6(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 6
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale7(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 7
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale8(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 8
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale9(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 9
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale10(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 10
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale11(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 11
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale12(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 12
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale13(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 13
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale14(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 14
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale15(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 15
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale16(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 16
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale17(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 17
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale18(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 18
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale19(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 19
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale20(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 20
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale21(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 21
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale22(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 22
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale23(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 23
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale24(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 24
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale25(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 25
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale26(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 26
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale27(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 27
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale28(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 28
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale29(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 29
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale30(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 30
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale31(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        shrd eax, edx, 31
        mov i1, eax
    } /* asm */
    return(i1);
}

long dmulscale32(long i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov esi, i3
        mov edi, i4
        imul edx
        mov ebx, eax
        mov eax, esi
        mov esi, edx
        imul edi
        add eax, ebx
        adc edx, esi
        mov i1, edx
    } /* asm */
    return(i1);
}

long tmulscale1(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 1
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale2(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 2
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale3(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 3
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale4(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 4
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale5(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 5
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale6(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 6
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale7(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 7
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale8(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 8
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale9(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 9
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale10(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 10
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale11(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 11
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale12(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 12
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale13(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 13
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale14(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 14
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale15(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 15
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale16(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 16
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale17(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 17
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale18(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 18
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale19(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 19
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale20(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 20
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale21(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 21
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale22(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 22
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale23(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 23
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale24(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 24
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale25(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 25
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale26(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 26
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale27(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 27
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale28(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 28
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale29(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 29
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale30(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 30
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale31(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        shrd eax, edx, 31
        mov i1, eax
    } /* asm */
    return(i1);
}

long tmulscale32(long i1, long i2, long i3, long i4, long i5, long i6)
{
    __asm
    {
        mov eax, i1
        mov edx, i2
        mov ebx, i3
        mov ecx, i4
        mov esi, i5
        mov edi, i6
        imul edx
        xchg eax, ebx
        xchg edx, ecx
        imul edx
        add ebx, eax
        adc ecx, edx
        mov eax, esi
        imul edi
        add eax, ebx
        adc edx, ecx
        mov i1, edx
    } /* asm */
    return(i1);
}

long boundmulscale(long i1, long i2, long i3)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov ecx, i3
        imul ebx
        mov ebx, edx
        shrd eax, edx, cl
        sar edx, cl
        xor edx, eax
        js checkit
        xor edx, eax
        jz skipboundit
        cmp edx, 0xffffffff
        je skipboundit
        checkit:
        mov eax, ebx
        sar eax, 31
        xor eax, 0x7fffffff
        skipboundit:
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale(long i1, long i2, long i3)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov ecx, i3
        mov edx, eax
        shl eax, cl
        neg cl
        sar edx, cl
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale1(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        add eax, eax
        sbb edx, edx
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale2(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 30
        lea eax, [eax*4]
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale3(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 29
        lea eax, [eax*8]
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale4(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 28
        shl eax, 4
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale5(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 27
        shl eax, 5
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale6(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 26
        shl eax, 6
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale7(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 25
        shl eax, 7
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale8(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 24
        shl eax, 8
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale9(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 23
        shl eax, 9
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale10(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 22
        shl eax, 10
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale11(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 21
        shl eax, 11
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale12(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 20
        shl eax, 12
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale13(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 19
        shl eax, 13
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale14(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 18
        shl eax, 14
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale15(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 17
        shl eax, 15
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale16(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 16
        shl eax, 16
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale17(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 15
        shl eax, 17
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale18(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 14
        shl eax, 18
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale19(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 13
        shl eax, 19
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale20(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 12
        shl eax, 20
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale21(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 11
        shl eax, 21
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale22(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 10
        shl eax, 22
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale23(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 9
        shl eax, 23
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale24(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 8
        shl eax, 24
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale25(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 7
        shl eax, 25
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale26(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 6
        shl eax, 26
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale27(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 5
        shl eax, 27
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale28(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 4
        shl eax, 28
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale29(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 3
        shl eax, 29
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale30(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 2
        shl eax, 30
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale31(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov edx, eax
        sar edx, 1
        shl eax, 31
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long divscale32(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        xor eax, eax
        idiv ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

void clearbuf(void *buf, long i2, long i3)
{
    __asm
    {
        mov edi, buf
        mov ecx, i2
        mov eax, i3
        rep stosd
    } /* asm */
}

void clearbufbyte(void *buf, long i2, long i3)
{
    __asm
    {
        mov edi, buf
        mov ecx, i2
        mov eax, i3
        cmp ecx, 4
        jae longcopy
        test cl, 1
        jz preskip
        stosb
        preskip: shr ecx, 1
        rep stosw
        jmp endit
        longcopy: test edi, 1
        jz skip1
        stosb
        dec ecx
        skip1: test edi, 2
        jz skip2
        stosw
        sub ecx, 2
        skip2: mov ebx, ecx
        shr ecx, 2
        rep stosd
        test bl, 2
        jz skip3
        stosw
        skip3: test bl, 1
        jz endit
        stosb
        endit:
    } /* asm */
}

void copybuf(void *src, void *dst, long len)
{
    __asm
    {
        mov esi, src
        mov edi, dst
        mov ecx, len
        rep movsd
    } /* asm */
}

void copybufbyte(void *src, void *dst, long len)
{
    __asm
    {
        mov esi, src
        mov edi, dst
        mov ecx, len
        cmp ecx, 4
        jae longcopy
        test cl, 1
        jz preskip
        movsb
        preskip: shr ecx, 1
        rep movsw
        jmp endit
        longcopy: test edi, 1
        jz skip1
        movsb
        dec ecx
        skip1: test edi, 2
        jz skip2
        movsw
        sub ecx, 2
        skip2: mov ebx, ecx
        shr ecx, 2
        rep movsd
        test bl, 2
        jz skip3
        movsw
        skip3: test bl, 1
        jz endit
        movsb
        endit:
    } /* asm */
}

void copybufreverse(void *src, void *dst, long len)
{
    __asm
    {
        mov esi, src
        mov edi, dst
        mov ecx, len
        shr ecx, 1
        jnc skipit1
        mov al, byte ptr [esi]
        dec esi
        mov byte ptr [edi], al
        inc edi
        skipit1: shr ecx, 1
        jnc skipit2
        mov ax, word ptr [esi-1]
        sub esi, 2
        ror ax, 8
        mov word ptr [edi], ax
        add edi, 2
        skipit2: test ecx, ecx
        jz endloop
        begloop: mov eax, dword ptr [esi-3]
        sub esi, 4
        bswap eax
        mov dword ptr [edi], eax
        add edi, 4
        dec ecx
        jnz begloop
        endloop:
    } /* asm */
}

void qinterpolatedown16(long *i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov ecx, i2
        mov edx, i3
        mov esi, i4
        mov ebx, ecx
        shr ecx, 1
        jz skipbegcalc
        begqcalc: lea edi, [edx+esi]
        sar edx, 16
        mov dword ptr [eax], edx
        lea edx, [edi+esi]
        sar edi, 16
        mov dword ptr [eax+4], edi
        add eax, 8
        dec ecx
        jnz begqcalc
        test ebx, 1
        jz skipbegqcalc2
        skipbegcalc: sar edx, 16
        mov dword ptr [eax], edx
        skipbegqcalc2:
    } /* asm */
}

void qinterpolatedown16short(long *i1, long i2, long i3, long i4)
{
    __asm
    {
        mov eax, i1
        mov ecx, i2
        mov edx, i3
        mov esi, i4
        test ecx, ecx
        jz endit
        test al, 2
        jz skipalignit
        mov ebx, edx
        sar ebx, 16
        mov word ptr [eax], bx
        add edx, esi
        add eax, 2
        dec ecx
        jz endit
        skipalignit: sub ecx, 2
        jc finishit
        begqcalc: mov ebx, edx
        add edx, esi
        sar ebx, 16
        mov edi, edx
        and edi, 0ffff0000h
        add edx, esi
        add ebx, edi
        mov dword ptr [eax], ebx
        add eax, 4
        sub ecx, 2
        jnc begqcalc
        test cl, 1
        jz endit
        finishit: mov ebx, edx
        sar ebx, 16
        mov word ptr [eax], bx
        endit:
    } /* asm */
}

void vlin16first(long i1, long i2)
{
    __asm
    {
        mov edi, i1
        mov ecx, i2
        mov al, byte ptr [edi]
        mov eax, ecx
        shr ecx, 2
        begvlin16firsta: mov byte ptr [edi], al
        mov byte ptr [edi+80], al
        mov byte ptr [edi+160], al
        mov byte ptr [edi+240], al
        add edi, 320
        dec ecx
        jnz begvlin16firsta
        mov ecx, eax
        and ecx, 3
        jz skipfirst
        begvlin16firstb: mov byte ptr [edi], al
        add edi, 80
        dec ecx
        jnz begvlin16firstb
        skipfirst:
    } /* asm */
}

void vlin16(long i1, long i2)
{
    __asm
    {
        mov edi, i1
        mov ecx, i2
        mov esi, edi
        begvlin16: movsb
        add edi, 79
        add esi, 79
        dec ecx
        jnz begvlin16
    } /* asm */
}

long mul3(long i1)
{
    __asm
    {
        mov eax, i1
        lea eax, [eax+eax*2]
        mov i1, eax
    } /* asm */
    return(i1);
}

long mul5(long i1)
{
    __asm
    {
        mov eax, i1
        lea eax, [eax+eax*4]
        mov i1, eax
    } /* asm */
    return(i1);
}

long mul9(long i1)
{
    __asm
    {
        mov eax, i1
        lea eax, [eax+eax*8]
        mov i1, eax
    } /* asm */
    return(i1);
}

        /* returns eax/ebx, dmval = eax%edx; */
long divmod(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        xor edx, edx
        div ebx
        mov dmval, edx
        mov i1, eax
    } /* asm */
    return(i1);
}

        /* returns eax%ebx, dmval = eax/edx; */
long moddiv(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        xor edx, edx
        div ebx
        mov dmval, eax
        mov i1, edx
    } /* asm */
    return(i1);
}

long klabs(long i1)
{
    __asm
    {
        mov eax, i1
        test eax, eax
        jns skipnegate
        neg eax
        skipnegate:
        mov i1, eax
    } /* asm */
    return(i1);
}

long ksgn(long i1)
{
    __asm
    {
        mov ebx, i1
        add ebx, ebx
        sbb eax, eax
        cmp eax, ebx
        adc al, 0
        mov i1, eax
    } /* asm */
    return(i1);
}

        /* eax = (unsigned min)umin(eax,ebx) */
long umin(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        sub eax, ebx
        sbb ecx, ecx
        and eax, ecx
        add eax, ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

        /* eax = (unsigned max)umax(eax,ebx) */
long umax(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        sub eax, ebx
        sbb ecx, ecx
        xor ecx, 0xffffffff
        and eax, ecx
        add eax, ebx
        mov i1, eax
    } /* asm */
    return(i1);
}

long kmin(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        cmp eax, ebx
        jl skipit
        mov eax, ebx
        skipit:
        mov i1, eax
    } /* asm */
    return(i1);
}

long kmax(long i1, long i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        cmp eax, ebx
        jg skipit
        mov eax, ebx
        skipit:
        mov i1, eax
    } /* asm */
    return(i1);
}

void swapchar(char *i1, char *i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov cl, [eax]
        mov ch, [ebx]
        mov [ebx], cl
        mov [eax], ch
        mov i1, eax
    } /* asm */
}

void swapshort(short *i1, short *i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov cx, [eax]
        mov dx, [ebx]
        mov [ebx], cx
        mov [eax], dx
        mov i1, eax
    } /* asm */
}

void swaplong(long *i1, long *i2)
{
    __asm
    {
        mov eax, i1
        mov ebx, i2
        mov ecx, [eax]
        mov edx, [ebx]
        mov [ebx], ecx
        mov [eax], edx
        mov i1, eax
    } /* asm */
}


        /*
         * swapchar2(ptr1,ptr2,xsiz); is the same as:
         * swapchar(ptr1,ptr2); swapchar(ptr1+1,ptr2+xsiz);
		 */ 
void swapchar2(char *ptr1, char *ptr2, long xsiz)
{
   __asm
   {
        mov eax, ptr1
        mov ebx, ptr2
        mov esi, xsiz
        add esi, ebx
        mov cx, [eax]
        mov dl, [ebx]
        mov [ebx], cl
        mov dh, [esi]
        mov [esi], ch
        mov [eax], dx
    } /* asm */
}

#endif /* defined _MSC_VER */
#endif /* !defined _INCLUDE_PRAGMAS_VISUALC_H_ */

/* end of pragmas_visualc.h ... */



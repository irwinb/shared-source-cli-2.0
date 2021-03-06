// ==++==
// 
//   
//    Copyright (c) 2006 Microsoft Corporation.  All rights reserved.
//   
//    The use and distribution terms for this software are contained in the file
//    named license.txt, which can be found in the root of this distribution.
//    By using this software in any fashion, you are agreeing to be bound by the
//    terms of this license.
//   
//    You must not remove this notice, or any other, from this software.
//   
// 
// ==--==

//
// Include file to make cleaner use of the opcode.def file to create mappings
// for info on MSIL ops.
//
// To use this header:
// #define OPDEF_HELPER

#ifndef OPDEF_HELPER
#error "Must specify OPDEF_HELPER"
#endif

#define OPDEF_OPCODENAME    123001
#define OPDEF_OPERANDSIZE   123002
#define OPDEF_PUSHCOUNT     123003
#define OPDEF_POPCOUNT      123004
#define OPDEF_ISBRACH       123005


#if OPDEF_HELPER == OPDEF_OPCODENAME
#define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) s,
#include "opcode.def"
#undef OPDEF

#elif OPDEF_HELPER == OPDEF_OPERANDSIZE
#define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) args,
#define InlineNone            0
#define ShortInlineVar        1
#define ShortInlineI          1
#define InlineI               4
#define InlineI8              8
#define ShortInlineR          4
#define InlineR               8
#define InlineMethod          4
#define InlineSig             4
#define ShortInlineBrTarget   1
#define InlineBrTarget        4
#define InlineSwitch         -1
#define InlineType            4
#define InlineString          4
#define InlineField           4
#define InlineTok             4
#define InlineVar             2
#include "opcode.def"
#undef OPDEF
#undef InlineNone
#undef ShortInlineVar
#undef ShortInlineI
#undef InlineI
#undef InlineI8
#undef ShortInlineR
#undef InlineR
#undef InlineMethod
#undef InlineSig
#undef ShortInlineBrTarget
#undef InlineBrTarget
#undef InlineSwitch
#undef InlineType
#undef InlineString
#undef InlineField
#undef InlineTok
#undef InlineVar

#elif OPDEF_HELPER == OPDEF_PUSHCOUNT
#define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) push,
#define Push0    0
#define Push1    1
#define VarPush -1
#define PushI    1
#define PushI4   1
#define PushI8   1
#define PushR4   1
#define PushR8   1
#define PushRef  1
#include "opcode.def"
#undef OPDEF
#undef Push0
#undef Push1
#undef VarPush
#undef PushI
#undef PushI4
#undef PushI8
#undef PushR4
#undef PushR8
#undef PushRef

#elif OPDEF_HELPER == OPDEF_POPCOUNT
#define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) pop,
#define Pop0     0
#define Pop1     1
#define VarPop  -1
#define PopI     1
#define PopI4    1
#define PopI8    1
#define PopR4    1
#define PopR8    1
#define PopRef   1
#include "opcode.def"
#undef OPDEF
#undef Pop0
#undef Pop1
#undef VarPop
#undef PopI
#undef PopI4
#undef PopI8
#undef PopR4
#undef PopR8
#undef PopRef

#elif OPDEF_HELPER == OPDEF_ISBRANCH
#define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) ctrl,
#define  NEXT           0
#define  BREAK          0
#define  CALL           0
#pragma push_macro("RETURN")
#if defined(RETURN)
#undef RETURN
#endif
#define  RETURN         0
#define  BRANCH         0
#define  COND_BRANCH    1
#define  THROW          0
#define  META           0
#include "opcode.def"
#undef OPDEF
#undef   NEXT
#undef   BREAK
#undef   CALL
#undef   RETURN
#pragma pop_macro("RETURN")
#undef   BRANCH
#undef   COND_BRANCH
#undef   THROW
#undef   META

#else
#error "Unrecognized OPDEF_HELPER"
#endif

#undef OPDEF_OPCODENAME
#undef OPDEF_OPERANDSIZE
#undef OPDEF_PUSHCOUNT
#undef OPDEF_POPCOUNT

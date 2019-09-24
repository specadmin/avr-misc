#ifndef AVR_MISC_COMMON_H
#define AVR_MISC_COMMON_H
//-----------------------------------------------------------------------------
#define __inline inline __attribute__ ((always_inline))
#define nop() __asm__ volatile ("nop")
#define _bit(b) (BYTE)(1 << (b))
#define set_bit(reg,b) (reg|=_bit(b))
#define clr_bit(reg,b) (reg&=~_bit(b))
#define test_bit(reg,b) ((reg & _bit(b))>>b)
#define halt() while(1);
#define max(a,b) (a>b) ? a : b
#define min(a,b) (a<b) ? a : b
//-----------------------------------------------------------------------------
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CAT(x,y) x ## y
#define CONCAT(x,y) CAT(x,y)
#define QUOT(x) #x
#define QUOTE(x) QUOT(x)
//-----------------------------------------------------------------------------
#define KB  1024
#define MB  1048576
//-----------------------------------------------------------------------------
typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;
//-----------------------------------------------------------------------------
union WORD_UNION
{
    WORD data;
    BYTE byte[2];
};
//-----------------------------------------------------------------------------
union DWORD_UNION
{
    DWORD data;
    WORD word[2];
    BYTE byte[4];
};
//-----------------------------------------------------------------------------
#endif

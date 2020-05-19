#ifndef AVR_MISC_H
#define AVR_MISC_H
#define LIB_AVR_MISC
//-----------------------------------------------------------------------------
#include "macro.h"
#include "avr-common.h"
#include "avr-interrupts.h"
#include "avr-delay.h"
#include "avr-eeprom.h"
//-----------------------------------------------------------------------------
class BYTEstack
{
public:
    BYTEstack();
    ~BYTEstack();
    void push(BYTE value);
    BYTE pop();
    BYTE size();
    BYTE top();
    BYTE operator [](const int i);
private:
    BYTE m_count;
    BYTE* m_buf;
};
//-----------------------------------------------------------------------------
#endif

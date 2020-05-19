#ifndef AVR_MISC_H
#define AVR_MISC_H
#define LIB_AVR_MISC
//-----------------------------------------------------------------------------
#include <stdlib.h>
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
template <typename Type>
char* toHexString(Type value)
{
    BYTE count = sizeof(Type) * 2;
    BYTE octet;
    char* buf = (char*) malloc(count + 1);
    buf[count] = '\0';
    while(count)
    {
        octet = value & 0x0F;
        buf[count - 1] = octet > 9 ? 'A' + octet - 10 : '0' + octet;
        value >>= 4;
        count--;
    }
    return buf;
}
//-----------------------------------------------------------------------------
#endif

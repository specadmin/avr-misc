//-----------------------------------------------------------------------------
#include <stdlib.h>
#include "avr-misc.h"
//-----------------------------------------------------------------------------
unsigned char _sreg;
//-----------------------------------------------------------------------------
BYTEstack::BYTEstack()
{
    m_count = 0;
    m_buf = NULL;
}
//-----------------------------------------------------------------------------
BYTEstack::~BYTEstack()
{
    if(m_buf)
    {
        free(m_buf);
        m_buf = NULL;
    }
}
//-----------------------------------------------------------------------------
void BYTEstack::push(BYTE value)
{
    m_buf = (BYTE*) realloc(m_buf, m_count + 1);
    if(!m_buf)
    {
        // not enough memory space to enlarge stack
        halt();
    }
    m_buf[m_count++] = value;
}
//-----------------------------------------------------------------------------
BYTE BYTEstack::pop()
{
    BYTE value = m_buf[--m_count];
    m_buf = (BYTE*) realloc(m_buf, m_count);
    return value;
}
//-----------------------------------------------------------------------------
BYTE BYTEstack::size()
{
    return m_count;
}
//-----------------------------------------------------------------------------
BYTE BYTEstack::top()
{
    return m_buf[m_count - 1];
}
//-----------------------------------------------------------------------------
BYTE BYTEstack::operator [](const int i)
{
    return m_buf[i];
}
//-----------------------------------------------------------------------------

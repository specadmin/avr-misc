//-----------------------------------------------------------------------------
#include "avr-common.h"
#include "avr-eeprom.h"
#include <avr/eeprom.h>
//=============================================================================
//===============================  EEBYTE  ====================================
//=============================================================================
void EEBYTE::operator = (const BYTE new_value)
{
    eeprom_write_byte(&address, new_value);
}
//-----------------------------------------------------------------------------
void EEBYTE::operator = (const int& new_value)
{
    eeprom_write_byte(&address, (BYTE) new_value);
}
//-----------------------------------------------------------------------------
void EEBYTE::operator = (const EEBYTE& new_value)
{
    BYTE tmp = eeprom_read_byte(&new_value.address);
    eeprom_write_byte(&address, tmp);
}
//-----------------------------------------------------------------------------
EEBYTE* EEBYTE::operator & ()
{
    return (EEBYTE*) &address;
}
//-----------------------------------------------------------------------------
EEBYTE::operator BYTE()
{
    return eeprom_read_byte(&address);
}
//-----------------------------------------------------------------------------
bool EEBYTE::operator == (const BYTE cmp_value)
{
    BYTE tmp = eeprom_read_byte(&address);
    return (tmp == cmp_value);
}
//-----------------------------------------------------------------------------
BYTE EEBYTE::operator++(const int)
{
    BYTE tmp = eeprom_read_byte(&address);
    tmp++;
    eeprom_write_byte(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE EEBYTE::operator--(const int)
{
    BYTE tmp = eeprom_read_byte(&address);
    tmp--;
    eeprom_write_byte(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE EEBYTE::operator += (const BYTE& value)
{
    BYTE tmp = eeprom_read_byte(&address);
    tmp += value;;
    eeprom_write_byte(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE EEBYTE::operator -= (const BYTE& value)
{
    BYTE tmp = eeprom_read_byte(&address);
    tmp -= value;;
    eeprom_write_byte(&address, tmp);
    return tmp;
}
//=============================================================================
//===============================  EEWORD  ====================================
//=============================================================================
void EEWORD::operator = (const WORD& new_value)
{
    eeprom_write_word(&address, new_value);
}
//-----------------------------------------------------------------------------
void EEWORD::operator = (const int& new_value)
{
    eeprom_write_word(&address, (BYTE) new_value);
}
//-----------------------------------------------------------------------------
void EEWORD::operator = (const EEWORD& new_value)
{
    DWORD tmp = eeprom_read_word(&new_value.address);
    eeprom_write_word(&address, tmp);
}
//-----------------------------------------------------------------------------
EEWORD* EEWORD::operator & ()
{
    return (EEWORD*) &address;
}
//-----------------------------------------------------------------------------
WORD EEWORD::operator++(const int)
{
    WORD tmp = eeprom_read_word(&address);
    tmp++;
    eeprom_write_word(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
WORD EEWORD::operator--(const int)
{
    WORD tmp = eeprom_read_word(&address);
    tmp++;
    eeprom_write_word(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
EEWORD::operator WORD()
{
    return eeprom_read_word(&address);
}
//-----------------------------------------------------------------------------
bool EEWORD::operator == (const WORD& cmp_value)
{
    WORD tmp = eeprom_read_word(&address);
    return (tmp == cmp_value);
}
//-----------------------------------------------------------------------------
WORD EEWORD::operator += (const WORD& value)
{
    WORD tmp = eeprom_read_word(&address);
    tmp += value;;
    eeprom_write_word(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
WORD EEWORD::operator -= (const WORD& value)
{
    WORD tmp = eeprom_read_word(&address);
    tmp -= value;;
    eeprom_write_word(&address, tmp);
    return tmp;
}
//=============================================================================
//==============================  EEDWORD  ====================================
//=============================================================================
void EEDWORD::operator = (const DWORD& new_value)
{
    eeprom_write_dword(&address,new_value);
}
//-----------------------------------------------------------------------------
void EEDWORD::operator = (const WORD& new_value)
{
    DWORD tmp=new_value;
    eeprom_write_dword(&address,tmp);
}
//-----------------------------------------------------------------------------
void EEDWORD::operator = (const int& new_value)
{
    DWORD tmp=new_value;
    eeprom_write_dword(&address,tmp);
}
//-----------------------------------------------------------------------------
void EEDWORD::operator = (const long int& new_value)
{
    DWORD tmp=new_value;
    eeprom_write_dword(&address,tmp);
}
//-----------------------------------------------------------------------------
void EEDWORD::operator = (const EEDWORD& new_value)
{
    DWORD tmp=eeprom_read_dword(&new_value.address);
    eeprom_write_dword(&address,tmp);
}
//-----------------------------------------------------------------------------
EEDWORD* EEDWORD::operator & ()
{
    return (EEDWORD*)&address;
}
//-----------------------------------------------------------------------------
DWORD EEDWORD::operator ++ (const int)
{
    DWORD tmp=eeprom_read_dword(&address);
    tmp++;
    eeprom_write_dword(&address,tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD EEDWORD::operator -- (const int)
{
    DWORD tmp=eeprom_read_dword(&address);
    tmp++;
    eeprom_write_dword(&address,tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD EEDWORD::operator += (const DWORD& value)
{
    DWORD tmp=eeprom_read_dword(&address);
    tmp+=value;
    eeprom_write_dword(&address,tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD EEDWORD::operator -= (const DWORD& value)
{
    DWORD tmp = eeprom_read_dword(&address);
    tmp -= value;
    eeprom_write_dword(&address, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
EEDWORD::operator DWORD()
{
    return eeprom_read_dword(&address);
}
//-----------------------------------------------------------------------------

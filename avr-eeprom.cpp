//-----------------------------------------------------------------------------
#include "avr-common.h"
#include "avr-eeprom.h"


//=============================================================================
//===============================  EEBYTE  ====================================
//=============================================================================
void _EEBYTE::operator = (const _EEBYTE& new_value)
{
    BYTE tmp = eeprom_read_byte(&new_value.data);
    eeprom_write_byte(&data, tmp);
}
//-----------------------------------------------------------------------------
_EEBYTE* _EEBYTE::operator & ()
{
    return (_EEBYTE*) &data;
}
//-----------------------------------------------------------------------------
_EEBYTE::operator BYTE()
{
    return eeprom_read_byte(&data);
}
//-----------------------------------------------------------------------------
BYTE _EEBYTE::operator++(const int)
{
    BYTE tmp = eeprom_read_byte(&data) + 1;
    eeprom_write_byte(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE _EEBYTE::operator--(const int)
{
    BYTE tmp = eeprom_read_byte(&data) - 1;
    eeprom_write_byte(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE _EEBYTE::operator += (const BYTE& value)
{
    BYTE tmp = eeprom_read_byte(&data) + value;
    eeprom_write_byte(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
BYTE _EEBYTE::operator -= (const BYTE& value)
{
    BYTE tmp = eeprom_read_byte(&data) - value;
    eeprom_write_byte(&data, tmp);
    return tmp;
}


//=============================================================================
//===============================  EEWORD  ====================================
//=============================================================================
void _EEWORD::operator = (const _EEWORD& new_value)
{
    DWORD tmp = eeprom_read_word(&new_value.data);
    eeprom_write_word(&data, tmp);
}
//-----------------------------------------------------------------------------
_EEWORD* _EEWORD::operator & ()
{
    return (_EEWORD*) &data;
}
//-----------------------------------------------------------------------------
WORD _EEWORD::operator++(const int)
{
    WORD tmp = eeprom_read_word(&data) + 1;
    eeprom_write_word(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
WORD _EEWORD::operator--(const int)
{
    WORD tmp = eeprom_read_word(&data) + 1;
    eeprom_write_word(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
_EEWORD::operator WORD()
{
    return eeprom_read_word(&data);
}
//-----------------------------------------------------------------------------
bool _EEWORD::operator == (const WORD& cmp_value)
{
    WORD tmp = eeprom_read_word(&data);
    return (tmp == cmp_value);
}
//-----------------------------------------------------------------------------
WORD _EEWORD::operator += (const WORD& value)
{
    WORD tmp = eeprom_read_word(&data) + value;
    eeprom_write_word(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
WORD _EEWORD::operator -= (const WORD& value)
{
    WORD tmp = eeprom_read_word(&data) - value;
    eeprom_write_word(&data, tmp);
    return tmp;
}


//=============================================================================
//==============================  EEDWORD  ====================================
//=============================================================================
_EEDWORD* _EEDWORD::operator & ()
{
    return (_EEDWORD*) &data;
}
//-----------------------------------------------------------------------------
DWORD _EEDWORD::operator ++ (const int)
{
    DWORD tmp = eeprom_read_dword(&data) + 1;
    eeprom_write_dword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEDWORD::operator -- (const int)
{
    DWORD tmp = eeprom_read_dword(&data) - 1;
    eeprom_write_dword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEDWORD::operator += (const DWORD& value)
{
    DWORD tmp = eeprom_read_dword(&data) + value;
    eeprom_write_dword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEDWORD::operator -= (const DWORD& value)
{
    DWORD tmp = eeprom_read_dword(&data) - value;
    eeprom_write_dword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
_EEDWORD::operator DWORD()
{
    return eeprom_read_dword(&data);
}


//=============================================================================
//==============================  EEQWORD  ====================================
//=============================================================================
QWORD _EEQWORD::eeprom_read_qword(const QWORD* ptr)
{
    BYTE* addr = (BYTE*) ptr;
    QWORD_UNION val;
    for(BYTE i = 0; i < 8; i++)
    {
        val.byte[i] = eeprom_read_byte(addr++);
    }
    return val.data;
}
//-----------------------------------------------------------------------------
void _EEQWORD::eeprom_write_qword(QWORD* ptr, const QWORD& value)
{
    BYTE* addr = (BYTE*) &ptr;
    QWORD_UNION val;
    val.data = value;
    for(BYTE i = 0; i < 8; i++)
    {
        eeprom_write_byte(addr++, val.byte[i]);
    }
}
//-----------------------------------------------------------------------------
void _EEQWORD::operator = (const _EEQWORD& new_value)
{
    QWORD tmp = eeprom_read_qword(&new_value.data);
    eeprom_write_qword(&data, tmp);
}
//-----------------------------------------------------------------------------
_EEQWORD* _EEQWORD::operator & ()
{
    return (_EEQWORD*)&data;
}
//-----------------------------------------------------------------------------
DWORD _EEQWORD::operator ++ (const int)
{
    QWORD tmp = eeprom_read_qword(&data) + 1;
    eeprom_write_qword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEQWORD::operator -- (const int)
{
    QWORD tmp = eeprom_read_qword(&data) - 1;
    eeprom_write_qword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEQWORD::operator += (const DWORD& value)
{
    QWORD tmp = eeprom_read_qword(&data) + value;
    eeprom_write_qword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
DWORD _EEQWORD::operator -= (const DWORD& value)
{
    QWORD tmp = eeprom_read_qword(&data) - value;
    eeprom_write_qword(&data, tmp);
    return tmp;
}
//-----------------------------------------------------------------------------
_EEQWORD::operator QWORD()
{
    return eeprom_read_qword(&data);
}
//-----------------------------------------------------------------------------



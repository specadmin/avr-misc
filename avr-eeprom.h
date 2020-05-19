//-----------------------------------------------------------------------------
#ifndef EEPROM_H
#define EEPROM_H
//----------------------------------------------------------------------------
#include <avr/eeprom.h>
//----------------------------------------------------------------------------
#define EEPROG      __attribute__((section(".eeprog")))
#define EEBYTE      _EEBYTE __attribute__((section(".eeprom")))
#define EEWORD      _EEWORD __attribute__((section(".eeprom")))
#define EEDWORD     _EEDWORD __attribute__((section(".eeprom")))
#define EEQWORD     _EEQWORD __attribute__((section(".eeprom")))
//----------------------------------------------------------------------------
class _EEBYTE
{
public:
    BYTE data;
    template <typename Type>
    void operator = (const Type &new_value)
        { eeprom_write_byte(&data, (BYTE) new_value); }
    void operator = (const _EEBYTE &new_value);
    _EEBYTE* operator & ();
    bool operator == (const BYTE cmp_value);
    BYTE operator ++ (const int);
    BYTE operator -- (const int);
    BYTE operator += (const BYTE &value);
    BYTE operator -= (const BYTE &value);
    operator BYTE();
};
//-----------------------------------------------------------------------------
class _EEWORD
{
public:
    WORD data;
    template <typename Type>
    void operator = (const Type &new_value)
        { eeprom_write_word(&data, (WORD) new_value); }
    void operator = (const _EEWORD &new_value);
    _EEWORD* operator & ();
    bool operator == (const WORD &cmp_value);
    WORD operator ++ (const int);
    WORD operator -- (const int);
    WORD operator += (const WORD &value);
    WORD operator -= (const WORD &value);
    operator WORD();
};
//-----------------------------------------------------------------------------
class _EEDWORD
{
public:
    DWORD data;
    template <typename Type>
    void operator = (const Type &new_value)
        { eeprom_write_dword(&data, (DWORD) new_value); }
    void operator = (const _EEDWORD &new_value);
    _EEDWORD* operator & ();
    bool operator == (const DWORD &cmp_value);
    DWORD operator ++ (const int);
    DWORD operator -- (const int);
    DWORD operator += (const DWORD &value);
    DWORD operator -= (const DWORD &value);
    operator DWORD();
};
//-----------------------------------------------------------------------------
class _EEQWORD
{
private:
    QWORD eeprom_read_qword(const QWORD* ptr);
    void eeprom_write_qword(QWORD* ptr, const QWORD& value);
public:
    QWORD data;
    template <typename Type>
    void operator = (const Type &new_value)
        { eeprom_write_qword(&data, (QWORD) new_value); }
    void operator = (const _EEQWORD &new_value);
    _EEQWORD* operator & ();
    bool operator == (const DWORD &cmp_value);
    DWORD operator ++ (const int);
    DWORD operator -- (const int);
    DWORD operator += (const DWORD &value);
    DWORD operator -= (const DWORD &value);
    operator QWORD();
};
//-----------------------------------------------------------------------------
#endif

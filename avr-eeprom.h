//-----------------------------------------------------------------------------
#ifndef EEPROM_H
#define EEPROM_H
//----------------------------------------------------------------------------
class EEBYTE
{
public:
    BYTE address;
    void operator = (const BYTE new_value);
    void operator = (const int &new_value);
    void operator = (const EEBYTE &new_value);
    EEBYTE* operator & ();
    bool operator == (const BYTE cmp_value);
    BYTE operator ++ (const int);
    BYTE operator -- (const int);
    BYTE operator += (const BYTE &value);
    BYTE operator -= (const BYTE &value);
    operator BYTE();
};
//-----------------------------------------------------------------------------
class EEWORD
{
public:
    WORD address;
    void operator = (const WORD &new_value);
    void operator = (const int &new_value);
    void operator = (const EEWORD &new_value);
    EEWORD* operator & ();
    bool operator == (const WORD &cmp_value);
    WORD operator ++ (const int);
    WORD operator -- (const int);
    WORD operator += (const WORD &value);
    WORD operator -= (const WORD &value);
    operator WORD();
};
//-----------------------------------------------------------------------------
class EEDWORD
{
public:
    DWORD address;
    void operator = (const DWORD &new_value);
    void operator = (const WORD &new_value);
    void operator = (const int &new_value);
    void operator = (const long int &new_value);
    void operator = (const EEDWORD &new_value);
    EEDWORD* operator & ();
    bool operator == (const DWORD &cmp_value);
    DWORD operator ++ (const int);
    DWORD operator -- (const int);
    DWORD operator += (const DWORD &value);
    DWORD operator -= (const DWORD &value);
    operator DWORD();
};
//-----------------------------------------------------------------------------
#endif // EEPROM_H

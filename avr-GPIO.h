#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED
//-----------------------------------------------------------------------------
enum GPIO_mode
{
    OUTPUT          = 0,
    INPUT           = 1,
    INPUT_PULLUP    = 2
};
//-----------------------------------------------------------------------------
class GPIO
{
private:
    volatile uint8_t* m_input_reg;
    union
    {
        volatile uint8_t* m_output_reg;
        volatile uint8_t* m_pullup_reg;
    };
    volatile uint8_t* m_direction_reg;
    uint8_t m_pin;
public:
    GPIO() {};
    GPIO(volatile uint8_t& port, uint8_t pin, GPIO_mode direction)
    {
        m_output_reg = &port;
        m_input_reg = &port - 2;
        m_direction_reg = &port - 1;
        m_pin = pin;
        mode(direction);
    };
    void set(volatile const uint8_t value)
    {
        if(value)
            set_bit(*m_output_reg, m_pin);
        else
            clr_bit(*m_output_reg, m_pin);
    }
    void mode(GPIO_mode direction)
    {
        switch(direction)
        {
        case OUTPUT:
            set_bit(*m_direction_reg, m_pin);
            break;
        case INPUT_PULLUP:
            set_bit(*m_pullup_reg, m_pin);
        case INPUT:
            clr_bit(*m_direction_reg, m_pin);
        }
    }
};
//-----------------------------------------------------------------------------
#endif

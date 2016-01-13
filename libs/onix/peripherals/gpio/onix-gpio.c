
#include <stdint.h>
#include <nrf.h>
#include <onix-gpio.h>

void onix_gpio_mode(uint32_t pin, uint32_t mode)
{
    switch (mode){
    case INPUT:
        NRF_GPIO->PIN_CNF[pin] =  (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                | (GPIO_PIN_CNF_DRIVE_S0S1     << GPIO_PIN_CNF_DRIVE_Pos)
                                | (GPIO_PIN_CNF_PULL_Disabled  << GPIO_PIN_CNF_PULL_Pos)
                                | (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos)
                                | (GPIO_PIN_CNF_DIR_Input      << GPIO_PIN_CNF_DIR_Pos);
    break;
    case INPUT_PULLUP:
        NRF_GPIO->PIN_CNF[pin] =  (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                | (GPIO_PIN_CNF_DRIVE_S0S1     << GPIO_PIN_CNF_DRIVE_Pos)
                                | (GPIO_PIN_CNF_PULL_Pullup    << GPIO_PIN_CNF_PULL_Pos)
                                | (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos)
                                | (GPIO_PIN_CNF_DIR_Input      << GPIO_PIN_CNF_DIR_Pos);
    break;
    case INPUT_PULLDOWN:
        NRF_GPIO->PIN_CNF[pin] =  (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                | (GPIO_PIN_CNF_DRIVE_S0S1     << GPIO_PIN_CNF_DRIVE_Pos)
                                | (GPIO_PIN_CNF_PULL_Pulldown  << GPIO_PIN_CNF_PULL_Pos)
                                | (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos)
                                | (GPIO_PIN_CNF_DIR_Input      << GPIO_PIN_CNF_DIR_Pos);
    break;
    case OUTPUT:
        NRF_GPIO->PIN_CNF[pin] =  (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                | (GPIO_PIN_CNF_DRIVE_H0H1     << GPIO_PIN_CNF_DRIVE_Pos)
                                | (GPIO_PIN_CNF_PULL_Disabled  << GPIO_PIN_CNF_PULL_Pos)
                                | (GPIO_PIN_CNF_INPUT_Connect  << GPIO_PIN_CNF_INPUT_Pos)
                                | (GPIO_PIN_CNF_DIR_Output     << GPIO_PIN_CNF_DIR_Pos);
    break;
    }
}

int  onix_gpio_get(uint32_t pin)
{
  return (NRF_GPIO->IN >> pin) & 1UL;
}

void onix_gpio_set(uint32_t pin, uint32_t value)
{
  if (value) NRF_GPIO->OUTSET = (1 << pin);
  else       NRF_GPIO->OUTCLR = (1 << pin);
}

void onix_gpio_toggle(uint32_t pin)
{
  uint32_t m=(1 << pin);
  uint32_t gpio_state = NRF_GPIO->OUT;
  NRF_GPIO->OUTSET = (m & ~gpio_state);
  NRF_GPIO->OUTCLR = (m &  gpio_state);
}


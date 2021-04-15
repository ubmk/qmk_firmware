#include "ubmk.h"
#include "nrf.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

void ubmk_pinMode(uint32_t ulPin, pin_mode_t ulMode) {
  /*
  if (ulPin >= PINS_COUNT) {
    return;
  }

  ulPin = g_ADigitalPinMap[ulPin];
  */

  NRF_GPIO_Type * port = nrf_gpio_pin_port_decode(&ulPin);

  // Set pin mode according to chapter '22.6.3 I/O Pin Configuration'
  switch ( ulMode )
  {
    case INPUT:
      // Set pin to input mode
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input        << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Connect    << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Disabled    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case INPUT_PULLUP:
      // Set pin to input mode with pull-up resistor enabled
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input        << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Connect    << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Pullup      << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);
    break;
    
    case INPUT_PULLUP_SENSE:
      // Set pin to input mode with pull-up resistor enabled and sense when Low
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input        << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Connect    << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Pullup      << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Low        << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case INPUT_PULLDOWN:
      // Set pin to input mode with pull-down resistor enabled
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input        << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Connect    << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Pulldown    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case INPUT_PULLDOWN_SENSE:
      // Set pin to input mode with pull-down resistor enabled
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input        << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Connect    << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Pulldown    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_High       << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case OUTPUT:
      // Set pin to output mode
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Output       << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Disabled    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case KB_OUTPUT:
      // Set pin to output mode
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Output       << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Disabled    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0D1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);
    break;

    case DISABLE:
      // Set pin to disable mode
      port->PIN_CNF[ulPin] = ((uint32_t)GPIO_PIN_CNF_DIR_Input       << GPIO_PIN_CNF_DIR_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_PULL_Disabled    << GPIO_PIN_CNF_PULL_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_DRIVE_S0S1       << GPIO_PIN_CNF_DRIVE_Pos)
                           | ((uint32_t)GPIO_PIN_CNF_SENSE_Disabled   << GPIO_PIN_CNF_SENSE_Pos);

    default:
      // do nothing
    break ;
  }
}

void ubmk_pinWrite(uint32_t ulPin, pin_state_t ulVal) {
  /*
  if (ulPin >= PINS_COUNT) {
    return;
  }

  ulPin = g_ADigitalPinMap[ulPin];
  */

  NRF_GPIO_Type * port = nrf_gpio_pin_port_decode(&ulPin);

  switch ( ulVal )
  {
    case LOW:
      port->OUTCLR = (1UL << ulPin);
    break ;

    default:
      port->OUTSET = (1UL << ulPin);
    break ;
  }
}

void ubmk_pinSet(uint32_t ulPin) {
  ubmk_pinWrite(ulPin, HIGH);
}

void ubmk_pinClear(uint32_t ulPin) {
  ubmk_pinWrite(ulPin, LOW);
}

pin_state_t ubmk_pinRead(uint32_t ulPin) {
  /*
  if (ulPin >= PINS_COUNT) {
    return 0;
  }

  ulPin = g_ADigitalPinMap[ulPin];
  */

  NRF_GPIO_Type * port = nrf_gpio_pin_port_decode(&ulPin);
  uint32_t const bm = (1UL << ulPin);

  // Return bit in OUT or IN depending on configured direction
  return (bm  & ((port->DIR & bm) ? port->OUT : port->IN)) ? HIGH : LOW;
}

void ubmk_pinToggle(uint32_t pin) {
  int state = 1 - ubmk_pinRead(pin);
  ubmk_pinWrite(pin, state);
}

uint32_t ubmk_analogRead(uint32_t ulPin) {
  uint32_t pin = SAADC_CH_PSELP_PSELP_NC;
  volatile int16_t value = 0;

  float mv_per_lsb = 3000.0F/4096.0F; // 12-bit ADC with 3.6V input range
  uint32_t saadcResolution= SAADC_RESOLUTION_VAL_12bit;
  uint32_t saadcReference = SAADC_CH_CONFIG_REFSEL_Internal;
  uint32_t saadcGain      = SAADC_CH_CONFIG_GAIN_Gain1_5;
  bool saadcBurst         = SAADC_CH_CONFIG_BURST_Disabled;

  /*
  if (ulPin >= PINS_COUNT) {
    return 0;
  }

  ulPin = g_ADigitalPinMap[ulPin];
  */

  switch ( ulPin ) {
    case 2:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput0;
      break;

    case 3:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput1;
      break;

    case 4:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput2;
      break;

    case 5:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput3;
      break;

    case 28:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput4;
      break;

    case 29:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput5;
      break;

    case 30:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput6;
      break;

    case 31:
      pin = SAADC_CH_PSELP_PSELP_AnalogInput7;
      break;

    default:
      return 0;
  }

  NRF_SAADC->RESOLUTION = saadcResolution;

  NRF_SAADC->ENABLE = (SAADC_ENABLE_ENABLE_Enabled << SAADC_ENABLE_ENABLE_Pos);
  for (int i = 0; i < 8; i++) {
    NRF_SAADC->CH[i].PSELN = SAADC_CH_PSELP_PSELP_NC;
    NRF_SAADC->CH[i].PSELP = SAADC_CH_PSELP_PSELP_NC;
  }
  NRF_SAADC->CH[0].CONFIG = ((SAADC_CH_CONFIG_RESP_Bypass     << SAADC_CH_CONFIG_RESP_Pos)   & SAADC_CH_CONFIG_RESP_Msk)
                            | ((SAADC_CH_CONFIG_RESP_Bypass   << SAADC_CH_CONFIG_RESN_Pos)   & SAADC_CH_CONFIG_RESN_Msk)
                            | ((saadcGain                     << SAADC_CH_CONFIG_GAIN_Pos)   & SAADC_CH_CONFIG_GAIN_Msk)
                            | ((saadcReference                << SAADC_CH_CONFIG_REFSEL_Pos) & SAADC_CH_CONFIG_REFSEL_Msk)
                            | ((SAADC_CH_CONFIG_TACQ_3us      << SAADC_CH_CONFIG_TACQ_Pos)   & SAADC_CH_CONFIG_TACQ_Msk)
                            | ((SAADC_CH_CONFIG_MODE_SE       << SAADC_CH_CONFIG_MODE_Pos)   & SAADC_CH_CONFIG_MODE_Msk)
                            | ((saadcBurst                    << SAADC_CH_CONFIG_BURST_Pos)   & SAADC_CH_CONFIG_BURST_Msk);
  NRF_SAADC->CH[0].PSELN = pin;
  NRF_SAADC->CH[0].PSELP = pin;


  NRF_SAADC->RESULT.PTR = (uint32_t)&value;
  NRF_SAADC->RESULT.MAXCNT = 1; // One sample

  NRF_SAADC->TASKS_START = 0x01UL;

  while (!NRF_SAADC->EVENTS_STARTED);
  NRF_SAADC->EVENTS_STARTED = 0x00UL;

  NRF_SAADC->TASKS_SAMPLE = 0x01UL;

  while (!NRF_SAADC->EVENTS_END);
  NRF_SAADC->EVENTS_END = 0x00UL;

  NRF_SAADC->TASKS_STOP = 0x01UL;

  while (!NRF_SAADC->EVENTS_STOPPED);
  NRF_SAADC->EVENTS_STOPPED = 0x00UL;

  if (value < 0) {
    value = 0;
  }

  NRF_SAADC->ENABLE = (SAADC_ENABLE_ENABLE_Disabled << SAADC_ENABLE_ENABLE_Pos);

  return value * mv_per_lsb;
}

void ubmk_delay(uint32_t number_of_ms) {
    nrf_delay_ms(number_of_ms);
}

#ifndef VBAT_DIVIDER_COMP
#define VBAT_DIVIDER_COMP (2.01F) //  = 1 / (R2 / (R1 + R2))
#endif

uint32_t ubmk_valueToMv(uint32_t value) {
  return value * VBAT_DIVIDER_COMP;
}

uint8_t ubmk_mvToPercent(float mvolts) {
  if(mvolts < 3300)
    return 0;

  if(mvolts < 3580) {
    mvolts -= 3300;
    return mvolts / 30;
  }

  mvolts -= 3600;
  float result = 12 + (mvolts * 0.15F);  // thats mvolts /6.66666666
  if (result > 100.00F) {
    return 100.00F;
  }
  return result;
}

uint8_t ubmk_valueToPercent(float value) {
  uint8_t battery_level;

  if (value >= 3000) {
    battery_level = 100;
  } else if (value > 2900) {
    battery_level = 100 - ((3000 - value) * 58) / 100;
  } else if (value > 2740) {
    battery_level = 42 - ((2900 - value) * 24) / 160;
  } else if (value > 2440) {
    battery_level = 18 - ((2740 - value) * 12) / 300;
  } else if (value > 2100) {
    battery_level = 6 - ((2440 - value) * 6) / 340;
  } else {
    battery_level = 0;
  }

  return battery_level;
}

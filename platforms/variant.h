#ifndef VARIANT_H
#define VARIANT_H

#if   defined(TARGET_NRF51_DK)

  #include <variant_norddk.h>

#elif defined(TARGET_NRF51_DONGLE)

  #include <variant_nord_usb.h>

#elif defined(TARGET_RBLAB_NRF51822)

  #include <variant_rbl_uno.h>

#elif defined(TARGET_RBLAB_BLENANO)

  #include <variant_rbl_nano.h>

#elif defined(TARGET_RFDUINO)

  #include <variant_rfduino.h>

#elif defined(TARGET_WAVESHARE)

  #include <variant_waveshare.h>

#elif defined(TARGET_BLE_USB_FRIEND)

  #include <variant_ble_usb_friend.h>

#elif defined(TARGET_ARCH_BLE)

  #include <variant_arch_ble.h>

#elif defined(TARGET_LINUX)

  #include <onix-time.h>
  #include <variant_linux.h>

#else

  #error "No TARGET_* defined"

#endif

#endif

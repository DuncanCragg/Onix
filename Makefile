################################################################################################

all: arduino-package


arduino-zip:
	rm -rf 1.0.0
	mkdir -p 1.0.0/cores/nRF51/nRF51-SDK-9
	mkdir -p 1.0.0/cores/nRF51/onix/libs/onix/include
	mkdir -p 1.0.0/cores/nRF51/onix/libs/onix/time
	mkdir -p 1.0.0/cores/nRF51/onix/libs/onix/peripherals/gpio
	mkdir -p 1.0.0/cores/nRF51/onix/libs/onix/peripherals/serial
	mkdir -p 1.0.0/cores/nRF51/arduino
	mkdir -p 1.0.0/libraries/Onix/src
	mkdir -p 1.0.0/libraries/Onix/examples/Blinky
	mkdir -p 1.0.0/variants/Bluefruit_Flora/linker_scripts/gcc
	mkdir -p 1.0.0/variants/Bluefruit_USB/linker_scripts/gcc
	mkdir -p 1.0.0/variants/Waveshare/linker_scripts/gcc
	mkdir -p 1.0.0/variants/BLE_Nano_32K/linker_scripts/gcc
	cp -a arduino/*.*                                           1.0.0/cores/nRF51/arduino
	rm 1.0.0/cores/nRF51/arduino/package_onix_nrf51_index.json
	mv 1.0.0/cores/nRF51/arduino/boards.txt                     1.0.0
	mv 1.0.0/cores/nRF51/arduino/platform.txt                   1.0.0
	cp platforms/openocd-script.cfg                             1.0.0
	cp platforms/openocd-stlink.cfg                             1.0.0
	cp libs/onix/include/nRF51/compiler_abstraction.h           1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/nrf51_bitfields.h                1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/nrf51_deprecated.h               1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/nrf51.h                          1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/nrf.h                            1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/core_cm0.h                       1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/core_cmFunc.h                    1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/core_cmInstr.h                   1.0.0/cores/nRF51/nRF51-SDK-9
	cp libs/onix/include/nRF51/system_nrf51.h                   1.0.0/cores/nRF51/nRF51-SDK-9
	cp platforms/gcc_startup_nrf51.s                            1.0.0/cores/nRF51/nRF51-SDK-9/gcc_startup_nrf51.S
	cp platforms/system_nrf51.c                                 1.0.0/cores/nRF51/nRF51-SDK-9
	cp platforms/syscalls.c                                     1.0.0/cores/nRF51/nRF51-SDK-9
	cp platforms/gcc_nrf51_common.ld                            1.0.0/cores/nRF51/nRF51-SDK-9
	cp platforms/variant.h                                      1.0.0/cores/nRF51/nRF51-SDK-9
	cp platforms/variant_bluefruit_flora.h                      1.0.0/variants/Bluefruit_Flora/
	cp platforms/memory-32K-no-sd.ld                            1.0.0/variants/Bluefruit_Flora/linker_scripts/gcc
	cp platforms/variant_ble_usb_friend.h                       1.0.0/variants/Bluefruit_USB/
	cp platforms/memory-16K-no-sd.ld                            1.0.0/variants/Bluefruit_USB/linker_scripts/gcc
	cp platforms/variant_waveshare.h                            1.0.0/variants/Waveshare/
	cp platforms/memory-32K-no-sd.ld                            1.0.0/variants/Waveshare/linker_scripts/gcc
	cp platforms/variant_rbl_nano.h                             1.0.0/variants/BLE_Nano_32K/
	cp platforms/memory-32K-no-sd.ld                            1.0.0/variants/BLE_Nano_32K/linker_scripts/gcc
	cp libs/onix/include/onix-time.h                            1.0.0/cores/nRF51/onix/libs/onix/include
	cp libs/onix/include/onix-gpio.h                            1.0.0/cores/nRF51/onix/libs/onix/include
	cp libs/onix/include/onix-serial.h                          1.0.0/cores/nRF51/onix/libs/onix/include
	cp libs/onix/time/onix-time.c                               1.0.0/cores/nRF51/onix/libs/onix/time
	cp libs/onix/peripherals/gpio/onix-gpio.c                   1.0.0/cores/nRF51/onix/libs/onix/peripherals/gpio
	cp libs/onix/peripherals/serial/onix-serial-nrf.c           1.0.0/cores/nRF51/onix/libs/onix/peripherals/serial
	mv 1.0.0/cores/nRF51/arduino/library.properties             1.0.0/libraries/Onix/
	touch                                                       1.0.0/libraries/Onix/src/dummy.h
	cp examples/Blinky/Blinky.ino                               1.0.0/libraries/Onix/examples/Blinky
	zip -x *.*.sw? -r Onix-nRF51.zip 1.0.0
	rm -rf 1.0.0


arduino-package: arduino-zip
	echo -n 'cat arduino/package_onix_nrf51_index.json | sed "s:the-sha-256:' > tmpscript
	sha256sum Onix-nRF51.zip | awk '{ printf $$1 }' >> tmpscript
	echo -n ':" | sed "s:the-zip-len:' >> tmpscript
	ls -l     Onix-nRF51.zip | awk '{ printf $$5 }' >> tmpscript
	echo -n ':" > package_onix_nrf51_index.json' >> tmpscript
	cat tmpscript | bash
	rm tmpscript

################################################################################################:


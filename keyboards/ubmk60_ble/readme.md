# ubmk60 ble

## Build

make -kb ubmk60_ble -km default

## Convert HEX to UF2

./util/uf2conv.py .build/ubmk60_ble_default.hex -c -f 0xADA52840 -o ubmk60.uf2

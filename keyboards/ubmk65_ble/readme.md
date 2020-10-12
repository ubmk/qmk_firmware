# ubmk65 ble

## Build

make -kb ubmk65_ble -km default

## Convert HEX to UF2

./util/uf2conv.py .build/ubmk65_ble_default.hex -c -f 0xADA52840 -o ubmk65.uf2

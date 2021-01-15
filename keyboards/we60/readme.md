# ubmk65 ble

## Build

make -kb we60 -km default

## Convert HEX to UF2

./util/uf2conv.py .build/we60_default.hex -c -f 0xADA52840 -o we60.uf2

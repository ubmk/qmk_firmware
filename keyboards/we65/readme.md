# we65

## Build

make -kb we65 -km default

## Convert HEX to UF2

./util/uf2conv.py .build/we65_default.hex -c -f 0xADA52840 -o we65.uf2

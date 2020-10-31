# viso

## Build

make -kb viso -km default

## Convert HEX to UF2

./util/uf2conv.py .build/viso_default.hex -c -f 0xADA52840 -o viso.uf2

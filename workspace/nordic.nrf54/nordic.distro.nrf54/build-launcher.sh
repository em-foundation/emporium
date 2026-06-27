#!/bin/sh

(cd ../..; emscript-dev build -u nordic.nrf54/nordic.distro.nrf54/VprLaunchP.em.ts -B "<bare-metal>" -S nordic.nrf54://flash)
# (cd ../..; emscript-dev build -u nordic.nrf54/nordic.distro.nrf54/VprLaunchP.em.ts -S nordic.nrf54://flash)
cp ../../.emscript/.out/main.out.hex vpr-launcher.hex
cp ../../.emscript/.out/main.out.dis vpr-launcher.dis
cp ../../.emscript/.out/main.map vpr-launcher.map

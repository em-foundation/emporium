#!/bin/sh

(cd ../..; emscript-dev build -u nordic.nrf54/nordic.distro.nrf54/VprLaunchP.em.ts -B -S nordic.nrf54://flash)
cp ../../.emscript/.out/main.out.hex vpr-launcher.hex
cp ../../.emscript/.out/main.out.dis vpr-launcher.dis

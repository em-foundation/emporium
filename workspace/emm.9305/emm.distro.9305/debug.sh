#!/bin/sh

TOOLS=c:/Users/bob/work/emscript/emscript-content/tools
ARC=$TOOLS/metaware-arc/bin

mdb -hard -digilent -off=prefer_soft_bp -off=download -on=reset_upon_restart -on=try_2wire -prop=dig_speed=3000000 -chipinit="../emm.9305/emm.distro.9305/chipinit.txt" .out/main.out

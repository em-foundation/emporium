#!/bin/sh

set -e

TOOLS=c:/Users/bob/work/emscript/emscript-content/tools
ARC=$TOOLS/metaware-arc/bin

OUT=.out

rm -rf $OUT
mkdir $OUT

CFLAGS=" \
    -DDEVICE=0x9305 \
    -D__T9305__ \
    -tcf=em9305 \
    -Wall \
    -Wconversion \
    -Hhostlib= \
    -Hnocrt \
    -Hon=Long_enums \
    -Hnocopyr \
    -Hnosdata \
    -nostdsysteminc \
    -Hccm \
    -mllvm \
    -align-labels=false \
    -Hnoivt \
    -ffunction-sections \
    -fdata-sections \
    -fno-builtin \
    -Wno-cast-align \
    -Mb \
    -DNDEBUG \
    -DHW_DI=5 \
    -DNVM_CODE \
    -Hpurge \
    -Wno-constexpr-not-const \
    -Wno-sign-conversion \
    -Wno-unused-function \
    -Wno-unused-variable \
    -Wno-unused-but-set-variable \
    -Wno-implicit-int-conversion \
    -Wno-uninitialized \
"

CINCS=" \
    -I. \
"

COPTS=" \
    -g -Os  \
"

LFLAGS=" \
    -q \
    -Bgrouplib \
    -Xnocompress \
    -e em__start \
    -m -C output=$OUT/main.out.map -C functions -C unmangle \
"

LIBS=" \
"

$ARC/ccac.exe $CFLAGS $CINCS $COPTS -std=c++14 -c main.cpp -o $OUT/main.obj
$ARC/ccac.exe $CFLAGS $CINCS $COPTS -std=c++14 -S main.cpp -o $OUT/main.s
$ARC/ldac.exe $LFLAGS -Bsymin_weak="rom.sym" linkcmd.ld $OUT/main.obj -o $OUT/main.out $LIBS
$ARC/elf2hex -QIo $OUT/main.out.hex $OUT/main.out
cp $OUT/main.out.hex $OUT/main.out.ihex
$ARC/elfdumpac -T -o $OUT/main.out.dis $OUT/main.out
$ARC/nmac -x -p -v $OUT/main.out > $OUT/main.out.syma
$ARC/nmac -x -p -n $OUT/main.out > $OUT/main.out.symn
objdump -h $OUT/main.out

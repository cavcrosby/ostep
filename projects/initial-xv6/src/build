#!/bin/bash

GCC_BIN_PATH="$HOME/resources/i386-elf-gcc/bin/"
AS_BIN_PATH="$HOME/resources/i386-elf-binutils/bin/"
AS_ABSOLUTE_PATH="$HOME/resources/i386-elf-binutils/bin/i386-elf-as"
TEMP_DIR_NAME="temp"

mkdir "$TEMP_DIR_NAME"
! cd "$TEMP_DIR_NAME" && rmdir "$TEMP_DIR_NAME" && exit
cp "$AS_ABSOLUTE_PATH" "$PWD"
ln -sf "./$(basename "$AS_ABSOLUTE_PATH")" "as"
cd ..
export PATH="${GCC_BIN_PATH}:${PATH}"
export PATH="${AS_BIN_PATH}:${PATH}"
export PATH="${PWD}/${TEMP_DIR_NAME}:${PATH}"

PATH="${GCC_BIN_PATH}:${PATH}" make TOOLPREFIX=i386-elf- qemu-nox

rm -rf $TEMP_DIR_NAME

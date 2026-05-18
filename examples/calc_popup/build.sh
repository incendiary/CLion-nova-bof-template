#!/bin/bash

x86_64-w64-mingw32-gcc -c calc_popup.c -o calc_popup.x64.o -I../../include
i686-w64-mingw32-gcc   -c calc_popup.c -o calc_popup.x86.o -I../../include

/*
 * calc_popup — Hello World BOF
 * ============================
 * Launches calc.exe in the context of the current Beacon process via
 * KERNEL32!WinExec, demonstrating the minimal BOF pattern:
 *   1. Declare the Win32 function using the DECLSPEC_IMPORT / $-alias syntax
 *   2. Implement go() as the BOF entry point
 *
 * Build (from this directory):
 *   x86_64-w64-mingw32-gcc -c calc_popup.c -o calc_popup.x64.o -I../../include
 *   i686-w64-mingw32-gcc   -c calc_popup.c -o calc_popup.x86.o -I../../include
 *
 * Load in Cobalt Strike:
 *   beacon> inline-execute /path/to/calc_popup.x64.o
 *
 * Note: WinExec is resolved via the $-alias / DECLSPEC_IMPORT pattern so that
 * the import does NOT appear in the BOF's static IAT — Beacon resolves it at
 * runtime via its internal GetProcAddress wrapper.
 */

#include "beacon.h"

/* Declare WinExec through the Beacon import alias so it is resolved at
 * runtime rather than via a static IAT entry. */
DECLSPEC_IMPORT UINT WINAPI KERNEL32$WinExec(LPCSTR lpCmdLine, UINT uCmdShow);

void go(char* args, int len) {
    KERNEL32$WinExec("calc.exe", 1 /* SW_SHOWNORMAL */);
}

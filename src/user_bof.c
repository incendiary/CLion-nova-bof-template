/*
 * user_bof.c — starter template
 * ==============================
 * Replace the body of go() with your BOF logic.
 *
 * For a minimal working example see examples/calc_popup/calc_popup.c,
 * which pops calc.exe via KERNEL32$WinExec and demonstrates the
 * DECLSPEC_IMPORT import alias pattern.
 *
 * Win32 functions must be declared via the Beacon import alias syntax:
 *   DECLSPEC_IMPORT <return> WINAPI <MODULE>$<Function>(args...);
 * Beacon resolves them at runtime — no static IAT entry is created.
 */

#include "beacon.h"

void go(char * args, int len) {
    /* Your BOF logic here */
}

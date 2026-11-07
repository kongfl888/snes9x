/* mingw-w64 build compatibility layer for the Snes9x win32 frontend.
 * Only pulled in by the MinGW Makefile (-include), never by MSVC builds. */
#ifndef S9X_MINGW_COMPAT_H
#define S9X_MINGW_COMPAT_H

#ifndef __CLR_OR_THIS_CALL
#define __CLR_OR_THIS_CALL
#endif
#ifndef __CLRCALL_OR_CDECL
#define __CLRCALL_OR_CDECL
#endif
#ifndef __THROW
#define __THROW
#endif
#ifndef _CRTIMP
#define _CRTIMP
#endif
#ifndef __cdecl
#define __cdecl
#endif



/* SAL annotations: declarations copied from the Windows SDK use them. */
#define _In_
#define _In_opt_
#define _Out_
#define _Out_opt_
#define _Inout_
#define _Inout_opt_
#define _In_z_
#define _Outptr_
#define _Outptr_opt_
#define _Reserved_
#define _Check_return_

/* SAL annotations used by dxerr.h (MSVC only). */
#ifndef _Out_cap_
#define _Out_cap_(size)
#endif
#ifndef _Out_ptrdiff_cap_
#define _Out_ptrdiff_cap_(size)
#endif

/* Win10 SDK flag missing from older mingw-w64 headers. */
#ifndef DATE_AUTOLAYOUT
#define DATE_AUTOLAYOUT 0x00000040
#endif

/* MSVC maps _ttof()/_ttoi() to the TCHAR variants; mingw-w64 has no such
 * helpers, and the frontend is always built with UNICODE defined. */
#ifndef _ttof
#define _ttof _wtof
#endif
#ifndef _ttoi
#define _ttoi _wtoi
#endif

#ifdef __cplusplus
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#endif

#endif

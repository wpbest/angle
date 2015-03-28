#pragma once

// The Windows header files use macros to indicate which versions of Windows support many programming elements.
// Therefore, you must define these macros to use new functionality introduced in each major operating system release. 

// Minimum system required								Value for _WIN32_WINNT
//---------------------------------------------------	--------------------------------
// Windows 8.1											_WIN32_WINNT_WINBLUE	(0x0603)
// Windows 8											_WIN32_WINNT_WIN8		(0x0602)
// Windows 7											_WIN32_WINNT_WIN7		(0x0601)
// Windows Server 2008									_WIN32_WINNT_WS08		(0x0600)
// Windows Vista										_WIN32_WINNT_VISTA		(0x0600)
// Windows Server 2003 with SP1, Windows XP with SP2	_WIN32_WINNT_WS03		(0x0502)
// Windows Server 2003, Windows XP						_WIN32_WINNT_WINXP		(0x0501)

#define _WIN32_WINNT _WIN32_WINNT_WINBLUE

#include <SDKDDKVer.h>


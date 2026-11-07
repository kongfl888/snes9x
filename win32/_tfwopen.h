/*****************************************************************************\
     Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
                This file is licensed under the Snes9x License.
   For further information, consult the LICENSE file in the root directory.
\*****************************************************************************/

#ifndef _TFWOPEN_H
#define _TFWOPEN_H

#ifdef UNICODE

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

FILE *_tfwopen(const char *filename, const char *mode );
int _twremove(const char *filename );
int _twopen(const char *filename, int oflag, int pmode);
char *_twfullpath(char* dst, const char* src, int len);

#ifdef __cplusplus
}
#endif

#endif // UNICODE

#ifdef __cplusplus

class Utf8ToWide {
private:
	wchar_t *wideChars;
public:
	Utf8ToWide(const char *utf8Chars);
	~Utf8ToWide() { delete [] wideChars; }
	operator wchar_t *() { return wideChars; }
};

class WideToUtf8 {
private:
	char *utf8Chars;
public:
	WideToUtf8(const wchar_t *wideChars);
	~WideToUtf8() { delete [] utf8Chars; }
	operator char *() { return utf8Chars; }
};

class CPToWide {
private:
   wchar_t *wideChars;
public:
   CPToWide(const char *chars, unsigned int cp);
   ~CPToWide() { delete [] wideChars; }
   operator wchar_t *() { return wideChars; }
};

class WideToCP {
private:
	char *cpchars;
public:
	WideToCP(const wchar_t *wideChars, unsigned int cp);
	~WideToCP() { delete [] cpchars; }
	operator char *() { return cpchars; }
};

#endif // __cplusplus

#ifdef UNICODE
#ifdef __cplusplus
#include <fstream>

namespace std {
/* libstdc++ has neither ios_base::_Openprot nor the FILE* constructor that
 * the MSVC version of this wrapper exposes, so the MinGW variant keeps only
 * the members the frontend actually uses. */
class u8nifstream: public std::ifstream
{
public:
	void open(const char *_Filename, ios_base::openmode _Mode)
		{
			std::ifstream::open(Utf8ToWide(_Filename), _Mode);
		}

	void open(const wchar_t *_Filename, ios_base::openmode _Mode)
		{
			std::ifstream::open(_Filename, _Mode);
		}

	u8nifstream()
		: std::ifstream() {}

	explicit u8nifstream(const char *_Filename,
		ios_base::openmode _Mode = ios_base::in)
		: std::ifstream(Utf8ToWide(_Filename), _Mode) {}

	explicit u8nifstream(const wchar_t *_Filename,
		ios_base::openmode _Mode = ios_base::in)
		: std::ifstream(_Filename, _Mode) {}
};
}
#define ifstream u8nifstream
#endif // __cplusplus

#define fopen _tfwopen
#undef remove
/* <stdio.h> already declares ::remove() as extern, so it cannot be shadowed
 * by a static definition on MinGW, and a function-like macro of that name
 * breaks <algorithm>. Callers that need the UTF-8 path handling use
 * S9xRemoveFile() instead. */
__forceinline static int S9xRemoveFile(const char *filename) {
  return _twremove(filename);
}
#ifndef __MINGW32__
__forceinline static int remove(const char *filename) {
  return _twremove(filename);
}
#endif
#undef open
__forceinline static int open(const char *filename, int oflag, int pmode) {
  return _twopen(filename, oflag, pmode);
}

#endif // UNICODE

#endif // _TFWOPEN_H

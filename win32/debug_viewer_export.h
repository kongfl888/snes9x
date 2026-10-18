#ifndef DEBUG_VIEWER_EXPORT_H
#define DEBUG_VIEWER_EXPORT_H

#include <windows.h>
#include <vector>
#include <string>
#include "port.h"

// Write a BGRA (0xAARRGGBB little-endian, top-down) pixel buffer to a PNG file.
// stridePixels is the buffer's pixel stride; w/h is the region to save.
bool WritePngFile(const TCHAR *path, int w, int h, int stridePixels,
                  const uint32 *bgra);

// Same, but encodes to memory. `out` is cleared and then filled with PNG bytes.
bool WritePngToMemory(int w, int h, int stridePixels, const uint32 *bgra,
                      std::vector<uint8> &out);

// One file inside a zip archive.
struct ZipBlob {
    std::string        name;   // filename inside the archive (ASCII)
    std::vector<uint8> data;
};

bool WriteZipFile(const TCHAR *path, const std::vector<ZipBlob> &entries);

// Copy a picture (the BGRA buffer WritePngFile takes) to the clipboard: a 24-bit DIB
// that pastes anywhere, plus a PNG that keeps transparency for apps that read one.
// Reports the result: a message in the main window, or a box on failure.
bool CopyViewerImage(HWND owner, int w, int h, int stridePixels, const uint32 *bgra,
                     const char *what);

// Sent to a debug viewer by the Copy screenshot hotkey: it copies its main picture
// and returns TRUE (via DWLP_MSGRESULT). Any other window returns 0.
UINT ViewerCopyMessage();

// Present a standard Save-As dialog. Returns true if the user chose a path
// (and it has been written into outPath). filter is a double-null-terminated
// GetSaveFileName filter string (e.g. "PNG (*.png)\0*.png\0\0").
bool ShowSaveDialog(HWND parent, TCHAR *outPath, int outPathLen,
                    const TCHAR *defaultName, const TCHAR *filter,
                    const TCHAR *defaultExt);

#endif // DEBUG_VIEWER_EXPORT_H

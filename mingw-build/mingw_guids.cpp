/* Definitions for the identifiers that mingw-w64's headers declare but whose
 * import libraries it does not ship. Only used by the MinGW build. */
#include <initguid.h>
#include <windows.h>
#include <shobjidl.h>
#include <Functiondiscoverykeys_devpkey.h>
#include <msxml2.h>

/* msxml2.h declares IID_IXMLDOMDocument but ships no uuid for it, which
 * __uuidof()/IID_PPV_ARGS() need. */
template<> const GUID &__mingw_uuidof<IXMLDOMDocument>()
{
    static const IID iid = {0x2933bf81, 0x7b36, 0x11d2,
                            {0xb2, 0x0e, 0x00, 0xc0, 0x4f, 0x98, 0x3e, 0x60}};
    return iid;
}

template<> const GUID &__mingw_uuidof<IXMLDOMDocument *>()
{
    return __mingw_uuidof<IXMLDOMDocument>();
}

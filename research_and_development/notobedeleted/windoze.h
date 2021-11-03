// https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte

#include <windows.h>

HRESULT DiscpUnicodeToAnsiSize(
    IN __in PWCHAR UnicodeString,
    OUT ULONG *AnsiSizeInBytes
    )
/*++
Routine Description:
    This routine will return the length needed to represent the unicode
    string as ANSI
Arguments:
    UnicodeString is the unicode string whose ansi length is returned
    *AnsiSizeInBytes is number of bytes needed to represent unicode
        string as ANSI
Return Value:
    ERROR_SUCCESS or error code
--*/
{
    _try
    {
        *AnsiSizeInBytes = WideCharToMultiByte(CP_ACP,
                                               0,
                                               UnicodeString,
                                               -1,
                                               NULL,
                                               0, NULL, NULL);
    } _except(EXCEPTION_EXECUTE_HANDLER) {
        return(ERROR_NOACCESS);
    }
    return((*AnsiSizeInBytes == 0) ? HRESULT_FROM_WIN32( GetLastError() ) : ERROR_SUCCESS);
}
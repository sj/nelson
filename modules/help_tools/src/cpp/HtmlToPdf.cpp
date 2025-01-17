//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "HtmlToPdf.hpp"
#include "Error.hpp"
#include "dynamic_library.hpp"
#include <boost/function.hpp>
//=============================================================================
namespace Nelson {
static library_handle nlsGuiHandleDynamicLibrary = nullptr;
static bool bFirstDynamicLibraryCall = true;
//=============================================================================
static void
initGuiDynamicLibrary()
{
    if (bFirstDynamicLibraryCall) {
        std::string fullpathGuiSharedLibrary = "libnlsGui" + get_dynamic_library_extension();
#ifdef _MSC_VER
        char* buf;
        try {
            buf = new char[MAX_PATH];
        } catch (const std::bad_alloc&) {
            buf = nullptr;
        }
        if (buf) {
            DWORD dwRet = ::GetEnvironmentVariableA("NELSON_BINARY_PATH", buf, MAX_PATH);
            if (dwRet) {
                fullpathGuiSharedLibrary
                    = std::string(buf) + std::string("/") + fullpathGuiSharedLibrary;
            }
            delete[] buf;
        }
#else
        char const* tmp = std::getenv("NELSON_BINARY_PATH");
        if (tmp != nullptr) {
            fullpathGuiSharedLibrary
                = std::string(tmp) + std::string("/") + fullpathGuiSharedLibrary;
        }
#endif
        nlsGuiHandleDynamicLibrary = load_dynamic_library(fullpathGuiSharedLibrary);
        if (nlsGuiHandleDynamicLibrary) {
            bFirstDynamicLibraryCall = false;
        }
    }
}
//=============================================================================
bool
HtmlFileToPdfFile(const std::wstring& htmlsrcfilename, const std::wstring& pdfdestfilename)
{
    typedef bool (*PROC_HtmlFileToPdfFile)(
        std::wstring htmlsrcfilename, std::wstring pdfdestfilename);
    static PROC_HtmlFileToPdfFile HtmlFileToPdfFilePtr = nullptr;
    initGuiDynamicLibrary();
    if (!HtmlFileToPdfFilePtr) {
        HtmlFileToPdfFilePtr = reinterpret_cast<PROC_HtmlFileToPdfFile>(
            get_function(nlsGuiHandleDynamicLibrary, "HtmlFileToPdfFile"));
        if (!HtmlFileToPdfFilePtr) {
            Error(_W("HtmlFileToPdfFile not loaded."));
        }
    }
    return HtmlFileToPdfFilePtr(htmlsrcfilename, pdfdestfilename);
}
//=============================================================================
bool
HtmlStreamToPdfFile(const std::wstring& htmlstream, const std::wstring& pdfdestfilename)
{
    using PROC_HtmlStreamToPdfFile = bool (*)(std::wstring, std::wstring);
    static PROC_HtmlStreamToPdfFile HtmlStreamToPdfFilePtr = nullptr;
    initGuiDynamicLibrary();
    if (!HtmlStreamToPdfFilePtr) {
        HtmlStreamToPdfFilePtr = reinterpret_cast<PROC_HtmlStreamToPdfFile>(
            get_function(nlsGuiHandleDynamicLibrary, "HtmlStreamToPdfFile"));
        if (!HtmlStreamToPdfFilePtr) {
            Error(_W("HtmlStreamToPdfFile not loaded."));
        }
    }
    return HtmlStreamToPdfFilePtr(htmlstream, pdfdestfilename);
}
//=============================================================================
}
//=============================================================================

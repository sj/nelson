%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
lib = dlopen([modulepath(nelsonroot(),'dynamic_link','bin'), '/libnlsDynamic_link', getdynlibext()]);
% get list all symbols available in loaded shared library
symbols = dllibinfo(lib)
% release handle
delete(lib);
% clear variable
clear lib

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ADV-CLI MODE-->
% <--IPC REQUIRED-->
% <--SEQUENTIAL TEST REQUIRED-->
%=============================================================================
clear('R');
res = ipc(getpid, 'isvar', 'R');
assert_isfalse(res);
R = 33;
res = ipc(getpid, 'isvar', 'R');
assert_istrue(res);
%=============================================================================

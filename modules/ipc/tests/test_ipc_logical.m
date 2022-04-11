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
REF = true;
ipc(getpid, 'put', REF, 'R')
q = 0;while(~isvar('R') && q < 10), sleep(1), q = q + 1; end
assert_isequal(R, REF);
%=============================================================================
clear('R');
REF = logical(eye(100, 100));
ipc(getpid, 'put', REF, 'R')
q = 0;while(~isvar('R') && q < 10), sleep(1), q = q + 1; end
assert_isequal(R, REF);
%=============================================================================
clear('R');
REF = logical(sparse(eye(100, 100)));
ipc(getpid, 'put', REF, 'R')
q = 0;while(~isvar('R') && q < 10), sleep(1), q = q + 1; end
assert_isequal(R, REF);
%=============================================================================

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
clear('all')
[u1, s1] = memory();
%=============================================================================
addpath([modulepath('stream_manager'), '/tests/loadsavebin']);
for i=1:50000
  typeofbin(201);
end
%=============================================================================
[u2, s2] = memory();
r = u2.MemUsedNelson - u1.MemUsedNelson;
disp(r)
assert_istrue(r < 600000)
%=============================================================================

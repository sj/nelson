%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = 1;
B = 2;
R1 = (A >= B);
R2 = (B >= A);
R3 = (A >= A);
assert_isfalse(R1);
assert_istrue(R2);
assert_istrue(R3);
%=============================================================================
R =  [1 2 3] >= 3
REF = [false, false, true];
assert_isequal(R, REF);
%=============================================================================

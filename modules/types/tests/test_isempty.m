%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('isempty'), 1);
assert_isequal(nargout('isempty'), 1);
%=============================================================================
A = rand(3, 3, 3);
res = isempty(A);
assert_isfalse(res);
%=============================================================================
A(:, :, :) = [];
res = isempty(A);
assert_istrue(res);
%=============================================================================
B = {};
res = isempty(B);
assert_istrue(res);
%=============================================================================
C = struct();
res = isempty(C);
assert_isfalse(res);
%=============================================================================
C = struct([]);
res = isempty(C);
assert_istrue(res);
%=============================================================================

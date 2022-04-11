%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_checkerror('assert_isapprox()', _('Wrong number of input arguments.'));
assert_checkerror('assert_isapprox(1)', _('Wrong number of input arguments.'));
assert_checkerror('assert_isapprox([1, 1])', _('Wrong number of input arguments.'));
assert_isequal(nargin('assert_isapprox'), -2);
assert_isequal(nargout('assert_isapprox'), 2);
%=============================================================================
assert_isapprox(1, 1);
%=============================================================================
A = pi;
B = single(pi);
r = assert_isapprox(A, B);
assert_isfalse(r);
%=============================================================================
assert_isapprox(A, B, 1e-4);
%=============================================================================
r = assert_isapprox(1 , [2 3] , eps);
assert_isfalse(r);
%=============================================================================
r = assert_isapprox(zeros(10, 1) + 1.e-4, zeros(10, 1), 1.e-5);
assert_isfalse(r);
%=============================================================================
assert_isapprox([] , []);
assert_isapprox(ones(10, 1), ones(10, 1), eps);
assert_isapprox(ones(10, 1) + eps, ones(10, 1) , eps);
assert_isapprox(zeros(10, 1), zeros(10, 1), 1.e-5);
%=============================================================================
r = assert_isapprox(1, 2, eps);
assert_isfalse(r);
%=============================================================================
r = assert_isapprox(zeros(10, 1) + 1.e-4, zeros(10, 1), 1.e-5);
assert_isfalse(r);
%=============================================================================
assert_isapprox(1.23456789123456789e-30, 1.23456789123456789e-30 , eps);
%=============================================================================
r = assert_isapprox(9e-30, 1.3e-30, eps);
assert_isfalse(r);
%=============================================================================
assert_isapprox([1 NaN], [1 NaN], eps);
assert_isapprox([1 NaN 1 Inf] , [1 NaN 1 Inf], eps);
%=============================================================================
r = assert_isapprox([NaN 1], [1 NaN], eps);
assert_isfalse(r);
%=============================================================================
r = assert_isapprox(1 + 5 * eps , 1 , eps);
assert_isfalse(r);
%=============================================================================
assert_isapprox(1 + 5 * eps, 1, 10 * eps);
assert_isapprox(1.23456, 1.23457, 1.e11 * eps);
%=============================================================================
assert_isapprox([1.2345 Inf -Inf NaN] , [1.2346 Inf -Inf NaN], 1.e-4);
%=============================================================================
assert_isapprox([1 1.e5], [2 1.e5], 1.e-3);
assert_isapprox([1 1.e5] , [1 1.e5], 1.e-3);
%=============================================================================
r = assert_isapprox([1 NaN], [2 NaN], 1.e-3);
assert_isfalse(r);
%=============================================================================
r = assert_isapprox([1 Inf], [2 Inf], 1.e-3);
assert_isfalse(r);
%=============================================================================
assert_isapprox([1 Inf] , [1 Inf] , 1.e-3);
%=============================================================================
assert_isapprox([1 Inf -Inf NaN] , [1 Inf -Inf NaN] , 1.e-3);
r = assert_isapprox([1 Inf -Inf NaN], [1 -Inf Inf NaN] , 1.e-3);
assert_isfalse(r);
%=============================================================================
assert_isapprox(1 + i, 1 + (1 + 1.e-4) * i, 1.e-3);
r = assert_isapprox(1 + i, 1 + (1 + 1.e-4) * i, 1.e-5);
assert_isfalse(r);
%=============================================================================
A = sparse(eye(3, 3) + eps);
B = sparse(eye(3, 3) + 2 * eps);
assert_isapprox(A, B, 10 * eps);
%=============================================================================
assert_isapprox(int8(3), 3);
assert_isapprox(int8(3), int16(3));
%=============================================================================
A = rand(3, 3, 3);
assert_isapprox(A, A);
%=============================================================================


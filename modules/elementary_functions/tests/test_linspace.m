%=============================================================================
% Copyright (c) 2020-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('linspace'), 3);
assert_isequal(nargout('linspace'), 1);
%=============================================================================
R = linspace(1, 100);
REF = 1:100;
assert_isequal(R, REF);
%=============================================================================
R = linspace(1, 2, 2);
REF = [1 2];
assert_isequal(R, REF);
%=============================================================================
R = linspace(1, 2, 1);
REF = 2;
assert_isequal(R, REF);
%=============================================================================
R = linspace(1, 2, 0);
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
R = linspace(12, 14, 11);
REF = [ 12.0000   12.2000   12.4000   12.6000   12.8000   13.0000   13.2000   13.4000   13.6000   13.8000   14.0000];
assert_isapprox(R, REF, 1e-2);
%=============================================================================
R = linspace(0, 1 , 11);
REF = [0. 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.];
assert_isapprox(R, REF, 1e-2);
%=============================================================================
R = linspace(2, 5, NaN);
REF = 5;
assert_isequal(R, REF);
%=============================================================================
R = linspace(1, Inf, 3);
REF = [  1   Inf   Inf];
assert_isequal(R, REF);
%=============================================================================
R = linspace(1+2i, 10+10i, 4);
REF = [1.0000+2.0000i, 4.0000+4.6667i, 7.0000+7.3333i, 10.0000+10.0000i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================

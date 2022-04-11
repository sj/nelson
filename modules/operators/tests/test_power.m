%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('power'), 2)
assert_isequal(nargout('power'), 1)
%=============================================================================
R = [1:5].^2;
REF = [1     4     9    16    25];
assert_isequal(R, REF);
%=============================================================================
R = power([1:5], 2);
REF = [1     4     9    16    25];
assert_isequal(R, REF);
%=============================================================================
R = [ -Inf ].^2;
REF = Inf;
assert_isequal(R, REF);
%=============================================================================
R = complex(-Inf,0).^complex(2,0);
REF = Inf;
assert_isequal(R, REF);
%=============================================================================
R = complex(0,Inf).^complex(2,0);
REF = -Inf;
%=============================================================================
R = [ Inf ].^2;
REF = Inf;
assert_isequal(R, REF);
%=============================================================================
R = [ NaN ].^2;
REF = NaN;
assert_isequal(R, REF);
%=============================================================================
R = [1 2 3; 4 5 6; 7 8 9].^-1;
REF = [1.0000    0.5000    0.3333;
    0.2500    0.2000    0.1667;
    0.1429    0.1250    0.1111];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = (-1) .^ (inv(3));
REF = 0.5000 + 0.8660i;
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = [1 NaN 2].^2;
REF =  [1 NaN 4];
assert_isequal(R, REF);
%=============================================================================
R = [1 Inf 2].^2;
REF =  [1 Inf 4];
assert_isequal(R, REF);
%=============================================================================
R = [1 -Inf 2].^2;
REF =  [1 Inf 4];
assert_isequal(R, REF);
%=============================================================================
R = [Inf:5].^2;
REF = zeros(1, 0);
assert_isequal(R, REF);
%=============================================================================
R = [1 2;3 4] .^ 2.5;
REF = [1.0000    5.6569; 15.5885   32.0000];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = [1 2;3 4] .^ i;
REF = [1.0000+0.0000i   0.7692+0.6390i;
0.4548+0.8906i   0.1835+0.9830i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = i ^ char(3);
REF = complex(0, -1);
assert_isequal(R, REF);
%=============================================================================
R = i ^ 4;
REF = 1;
assert_isequal(R, REF);
%=============================================================================
R = single(2) ^ 4;
REF = single(16);
assert_isequal(R, REF);
%=============================================================================
R = 2 ^ single(4);
REF = single(16);
assert_isequal(R, REF);
%=============================================================================

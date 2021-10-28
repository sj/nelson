%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('sign'), 1)
assert_isequal(nargout('sign'), 1)
%=============================================================================
R = sign([complex(-3,0), complex(-2,1)]);
REF = [-1.0000 + 0.0000i  -0.8944 + 0.4472i];
assert_isapprox(R, REF, 1e-4);
%=============================================================================
R = sign(complex(-3,0));
REF = -1;
assert_isequal(R, REF);
%=============================================================================
M = magic(3) - 5;
R = sign(M);
REF = [1    -1     1;-1     0     1;-1     1    -1];
assert_isequal(R, REF);
%=============================================================================
V = [-11 0 1.5 Inf NaN];
R = sign(V);
REF = [-1     0     1     1   NaN];
assert_isequal(R, REF);
%=============================================================================
R = sign(2);
REF = 1;
assert_isequal(R, REF);
%=============================================================================
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
format long
R = evalc('pi');
REF = '
ans =

   3.141592653589793

';
assert_isequal(R, REF);
%=============================================================================
format long
R = evalc('single(pi)');
REF = '
ans =

  single

   3.1415927

';
assert_isequal(R, REF);
%=============================================================================
format hex
R = evalc('R = intmax(''uint64'')')
REF =  '
R =

  uint64

   ffffffffffffffff

';
assert_isequal(R, REF);
%=============================================================================
format shortEng
format compact
x = rand(3);
R = evalc('x');
REF = 'x =
   814.7237e-003   913.3759e-003   278.4982e-003
   905.7919e-003   632.3592e-003   546.8815e-003
   126.9868e-003    97.5404e-003   957.5068e-003
';
assert_isequal(R, REF);
%=============================================================================

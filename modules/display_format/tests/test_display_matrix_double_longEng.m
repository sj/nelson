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
format('longEng')
%=============================================================================
R = evalc('A = pi');
REF =  '
A =

    3.14159265358979e+000

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [1e9 1e99]');
REF =  '
A =

    1.00000000000000e+009    1.00000000000000e+099

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [6.5574e-04, 6.5574e-04]');
REF = '
A =

    655.740000000000e-006    655.740000000000e-006

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [0.3729   6.5574e-04    0.1393]');
REF = '
A =

    372.900000000000e-003    655.740000000000e-006    139.300000000000e-003

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = eye(3,3) * eps');
REF = '
A =

    222.044604925031e-018    0.00000000000000e+000    0.00000000000000e+000
    0.00000000000000e+000    222.044604925031e-018    0.00000000000000e+000
    0.00000000000000e+000    0.00000000000000e+000    222.044604925031e-018

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, 1, 2;
     0,  0.2220, 4;
     5, 6, 0.2220];
R = evalc('A');
REF = '
A =

    222.000000000000e-003    1.00000000000000e+000    2.00000000000000e+000
    0.00000000000000e+000    222.000000000000e-003    4.00000000000000e+000
    5.00000000000000e+000    6.00000000000000e+000    222.000000000000e-003

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
R = evalc('A');
REF = '
A =

    222.000000000000e-003                      NaN    2.00000000000000e+000
                      Inf    222.000000000000e-003    4.00000000000000e+000
    5.00000000000000e+000    6.00000000000000e+000                     -Inf

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
A = sparse(A);
R = evalc('A');
REF =  '
A =

    (1,1)       222.000000000000e-003
    (2,1)                         Inf
    (3,1)       5.00000000000000e+000
    (1,2)                         NaN
    (2,2)       222.000000000000e-003
    (3,2)       6.00000000000000e+000
    (1,3)       2.00000000000000e+000
    (2,3)       4.00000000000000e+000
    (3,3)                        -Inf

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
A = complex(A, A);
R = evalc('A');
REF =   '
A =

  Column 1

    222.000000000000e-003 + 222.000000000000e-003i
                      Inf +                      Infi
    5.00000000000000e+000 + 5.00000000000000e+000i

  Column 2

                      NaN +                      NaNi
    222.000000000000e-003 + 222.000000000000e-003i
    6.00000000000000e+000 + 6.00000000000000e+000i

  Column 3

    2.00000000000000e+000 + 2.00000000000000e+000i
    4.00000000000000e+000 + 4.00000000000000e+000i
                     -Inf -                      Infi

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
A = sparse(complex(A, A));
R = evalc('A');
REF =  '
A =

    (1,1)       222.000000000000e-003 + 222.000000000000e-003i
    (2,1)                         Inf +                      Infi
    (3,1)       5.00000000000000e+000 + 5.00000000000000e+000i
    (1,2)                         NaN +                      NaNi
    (2,2)       222.000000000000e-003 + 222.000000000000e-003i
    (3,2)       6.00000000000000e+000 + 6.00000000000000e+000i
    (1,3)       2.00000000000000e+000 + 2.00000000000000e+000i
    (2,3)       4.00000000000000e+000 + 4.00000000000000e+000i
    (3,3)                        -Inf -                      Infi

';
assert_isequal(R, REF)
%=============================================================================
A = ones(3,10);
R = evalc('A');
REF =  '
A =

  Columns 1 through 3

    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000

  Columns 4 through 6

    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000

  Columns 7 through 9

    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000
    1.00000000000000e+000    1.00000000000000e+000    1.00000000000000e+000

  Column 10

    1.00000000000000e+000
    1.00000000000000e+000
    1.00000000000000e+000

';
assert_isequal(R, REF)
%=============================================================================
A = complex(ones(3,10), ones(3,10));
R = evalc('A');
REF =  '
A =

  Column 1

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 2

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 3

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 4

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 5

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 6

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 7

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 8

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 9

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

  Column 10

    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i
    1.00000000000000e+000 + 1.00000000000000e+000i

';
assert_isequal(R, REF)
%=============================================================================

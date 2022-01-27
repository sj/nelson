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
format('shortEng')
%=============================================================================
R = evalc('A = NaN');
REF = '
A =

             NaN

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = complex(NaN, NaN)');
REF = '
A =

             NaN +             NaNi

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = pi');
REF =  '
A =

     3.1416e+000

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [1e9 1e99]');
REF =  '
A =

     1.0000e+009     1.0000e+099

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [6.5574e-04, 6.5574e-04]');
REF = '
A =

   655.7400e-006   655.7400e-006

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = [0.3729   6.5574e-04    0.1393]');
REF = '
A =

   372.9000e-003   655.7400e-006   139.3000e-003

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = eye(3,3) * eps');
REF = '
A =

   222.0446e-018     0.0000e+000     0.0000e+000
     0.0000e+000   222.0446e-018     0.0000e+000
     0.0000e+000     0.0000e+000   222.0446e-018

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, 1, 2;
     0,  0.2220, 4;
     5, 6, 0.2220];
R = evalc('A');
REF = '
A =

   222.0000e-003     1.0000e+000     2.0000e+000
     0.0000e+000   222.0000e-003     4.0000e+000
     5.0000e+000     6.0000e+000   222.0000e-003

';
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
R = evalc('A');
REF =  '
A =

   222.0000e-003             NaN     2.0000e+000
             Inf   222.0000e-003     4.0000e+000
     5.0000e+000     6.0000e+000            -Inf

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

    (1,1)      222.0000e-003
    (2,1)                Inf
    (3,1)        5.0000e+000
    (1,2)                NaN
    (2,2)      222.0000e-003
    (3,2)        6.0000e+000
    (1,3)        2.0000e+000
    (2,3)        4.0000e+000
    (3,3)               -Inf

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

  Columns 1 through 2

   222.0000e-003 +222.0000e-003i             NaN +             NaNi
             Inf +             Infi   222.0000e-003 +222.0000e-003i
     5.0000e+000 +  5.0000e+000i     6.0000e+000 +  6.0000e+000i

  Column 3

     2.0000e+000 +  2.0000e+000i
     4.0000e+000 +  4.0000e+000i
            -Inf -             Infi

'
;
assert_isequal(R, REF)
%=============================================================================
A = [0.2220, NaN, 2;
     Inf,  0.2220, 4;
     5, 6, -Inf];
A = sparse(complex(A, A));
R = evalc('A');
REF =   '
A =

    (1,1)      222.0000e-003 +222.0000e-003i
    (2,1)                Inf +             Infi
    (3,1)        5.0000e+000 +  5.0000e+000i
    (1,2)                NaN +             NaNi
    (2,2)      222.0000e-003 +222.0000e-003i
    (3,2)        6.0000e+000 +  6.0000e+000i
    (1,3)        2.0000e+000 +  2.0000e+000i
    (2,3)        4.0000e+000 +  4.0000e+000i
    (3,3)               -Inf -             Infi

';
assert_isequal(R, REF)
%=============================================================================
A = ones(3,10);
R = evalc('A');
REF =   '
A =

  Columns 1 through 4

     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000

  Columns 5 through 8

     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000     1.0000e+000     1.0000e+000

  Columns 9 through 10

     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000
     1.0000e+000     1.0000e+000

';
assert_isequal(R, REF)
%=============================================================================
A = complex(ones(3,10), ones(3,10));
R = evalc('A');
REF =     '
A =

  Columns 1 through 2

     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i

  Columns 3 through 4

     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i

  Columns 5 through 6

     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i

  Columns 7 through 8

     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i

  Columns 9 through 10

     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i
     1.0000e+000 +  1.0000e+000i     1.0000e+000 +  1.0000e+000i

';
assert_isequal(R, REF)
%=============================================================================

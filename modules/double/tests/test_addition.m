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
A = 3;
B = 4;
assert_isequal(A+B, 7);
%=============================================================================
assert_isequal(3 + [], []);
%=============================================================================
assert_isequal([] + 3, []);
%=============================================================================
assert_isequal(3 + ones(3,0), zeros(3, 0));
%=============================================================================
assert_isequal(ones(3,0) + 3, zeros(3, 0));
%=============================================================================
A = [1 2; 3 4];
B = [5 6; 7 8];
R = A + B;
REF = [6     8;10    12];
assert_isequal(R, REF);
%=============================================================================
A = [1 2; 3 4];
B = 10;
R1 = A + B;
R2 = B + A;
REF = [11, 12; 13, 14];
assert_isequal(R1, R2);
assert_isequal(R1, REF);
%=============================================================================
A = [0 10; 10 0];
R = A + 20;
REF = [20 30; 30 20];
assert_isequal(R, REF);
%=============================================================================
A = [10 0; 20 40];
B = [50 90; 20 10];
R = A + B;
REF = [60 90; 40 50];
assert_isequal(R, REF);
%=============================================================================
A = [10, 20, 30, 40];
B = [50; 60; 70];
R1 = A + B;
R2 = B + A;
assert_isequal(R1, R2);
REF = [60    70    80    90;
    70    80    90   100;
    80    90   100   110];
assert_isequal(R1, REF);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [10; 100];
R1 = A + B;
R2 = B + A;
assert_isequal(R1, R2);
REF = [20    30    40;  140   150   160];
assert_isequal(R1, REF);
%=============================================================================
R1 = [1:3] + [1:3]';
R2 = [1:3]' + [1:3];
assert_isequal(R1, R2);
REF = [2     3     4;
3     4     5;
4     5     6];
assert_isequal(R1, REF);
%=============================================================================
A = [1:3]';
B = [1:4];
R = A + B;
REF = [     2     3     4     5;
3     4     5     6;
4     5     6     7];
assert_isequal(R, REF);
%=============================================================================
A = [1:4]';
B = [1:3];
R = A + B;
REF = [    2     3     4;
3     4     5;
4     5     6;
5     6     7];
assert_isequal(R, REF);
%=============================================================================
A = reshape(1:(3*4*2),3,4,2);
B = 1:5;
assert_checkerror('R = A + B;',  [_('Size mismatch on arguments to arithmetic operator '), '+']);
%=============================================================================
R = [1;3]+[1 2 3 4; 4 5 6 7];
REF = [2     3     4     5;7     8     9    10];
assert_isequal(R, REF);
%=============================================================================
A = [1,3; 2,4];
B = [1 2 3 4; 4 5 6 7];
assert_checkerror('R = A + B;',  [_('Size mismatch on arguments to arithmetic operator '), '+']);
%=============================================================================
R = [1 2 3 4] + [1 2 3 4; 4 5 6 7];
REF = [     2     4     6     8; 5     7     9    11];
assert_isequal(R, REF);
%=============================================================================
R = [1 2 3 4; 4 5 6 7] + [1 2 3 4];
REF = [ 2     4     6     8;5     7     9    11];
assert_isequal(R, REF);
%=============================================================================
R = [1 2 3 4; 4 5 6 7] + [1; 2];
REF = [  2     3     4     5; 6     7     8     9];
assert_isequal(R, REF);
%=============================================================================
A = [10 20 30; 40 50 60];
B = [1 2 3];
R = A + B;
REF = [11    22    33; 41    52    63];
assert_isequal(R, REF);
%=============================================================================
B = [10 20 30; 40 50 60];
A = [1 2 3];
R = A + B;
REF = [11    22    33; 41    52    63];
assert_isequal(R, REF);
%=============================================================================
A = ones(3, 1);
B = ones(4, 1);
assert_checkerror('A + B', [_('Size mismatch on arguments to arithmetic operator '), '+']);
%=============================================================================
% Currently not managed
%R = reshape(1:(4*4*2),4,4,2) + [1; 2; 3; 4 ];
assert_checkerror('reshape(1:(4*4*2),4,4,2) + [1; 2; 3; 4 ]', [_('Size mismatch on arguments to arithmetic operator '), '+']);
REF1 =[2     6    10    14;
     4     8    12    16;
     6    10    14    18;
     8    12    16    20];
%assert_isequal(R(:,:,1), REF1);
%=============================================================================
REF2 = [18    22    26    30;
    20    24    28    32;
    22    26    30    34;
    24    28    32    36];
%assert_isequal(R(:,:,2), REF2);
%=============================================================================
A = reshape(1:(3*4*2),3,4,2);
B = 1:4;
%R = A + B;
assert_checkerror('A + B', [_('Size mismatch on arguments to arithmetic operator '), '+']);
REF_1 = [ 2     6    10    14;
3     7    11    15;
4     8    12    16];
%assert_isequal(R(:, :, 1), REF_1);
REF_2 = [14    18    22    26;
15    19    23    27;
16    20    24    28];
%assert_isequal(R(:, :, 2), REF_2);
%=============================================================================
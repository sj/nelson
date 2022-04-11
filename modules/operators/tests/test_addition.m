%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
R = 1 + 1;
REF = 2;
assert_isequal(R, REF);
%=============================================================================
R = ones(3, 0) + 1;
REF = zeros(3, 0);
assert_isequal(R, REF);
%=============================================================================
R = ones(3, 0) + ones(3, 0);
REF = zeros(3, 0);
assert_isequal(R, REF);
%=============================================================================
R = ones(3, 3) + ones(3, 3);
REF = ones(3, 3) * 2;
assert_isequal(R, REF);
%=============================================================================
R = 1 + zeros(3, 3, 3);
REF = ones(3, 3, 3);
assert_isequal(R, REF);
%=============================================================================
R = zeros(3, 3, 3) + 1;
REF = ones(3, 3, 3);
assert_isequal(R, REF);
%=============================================================================
R = ones(3, 3, 3) + ones(3, 3, 3);
REF = ones(3, 3, 3) + 1;
assert_isequal(R, REF);
%=============================================================================
R = 3 + i;
REF = complex(3, 1);
assert_isequal(R, REF);
%=============================================================================
A = ones(1,2,3);
B = [1:3];
assert_checkerror('R = A + B;', [_('Size mismatch on arguments to arithmetic operator '),  '+']);
%=============================================================================
A = "r";
B = "B";
R = A + B;
REF = "rB";
assert_isequal(R, REF);
%=============================================================================
A = "r";
B = "B";
R = B + A;
REF = "Br";
assert_isequal(R, REF);
%=============================================================================
A = ["a", "b"; "c", "d"];
B = "u";
R = A + B;
REF = ["au", "bu"; "cu", "du"];
assert_isequal(R, REF);
%=============================================================================
B = ["a", "b"; "c", "d"];
A = "u";
R = A + B;
REF = ["ua", "ub"; "uc", "ud"];
assert_isequal(R, REF);
%=============================================================================
A = ["1", "2"; "3", "4"];
B = ["a", "b"; "c", "d"];
R = A + B;
REF = ["1a", "2b"; "3c", "4d"];
assert_isequal(R, REF);
%=============================================================================
B = ["1", "2"; "3", "4"];
A = ["a", "b"; "c", "d"];
R = A + B;
REF = ["a1", "b2"; "c3", "d4"];
assert_isequal(R, REF);
%=============================================================================
A = ["1", "2"];
B = ["3"; "4"];
R = A + B;
REF = ["13", "23";
       "14", "24"];
assert_isequal(R, REF);
%=============================================================================
B = ["1", "2", "5"];
A = ["3"; "4"];
R = A + B;
REF = ["31", "35", "42";
 "32", "41", "45"];
 assert_isequal(R, REF);
%=============================================================================
A = ["1", "2", "5"];
B = ["3"; "4"];
R = A + B;
REF = ["13", "23", "53";
    "14", "24", "54"];
assert_isequal(R, REF);
%=============================================================================
A = ["a", "b"];
B = ["1", "2"; "3", "4"];
R = A + B;
REF = ["a1", "b2";
    "a3", "b4"];
assert_isequal(R, REF);
%=============================================================================
A = ["1", "2"; "3", "4"];
B = ["a", "b"];
R = A + B;
REF = ["1a", "2b";
    "3a", "4b"];
assert_isequal(R, REF);
%=============================================================================
A = ["1", "2"; "3", "4"];
B = ["a"; "b"];
R = A + B;
REF = ["1a", "2a";
    "3b", "4b"];
assert_isequal(R, REF);
%=============================================================================
B = ["1", "2"; "3", "4"];
A = ["a"; "b"];
R = A + B;
REF = ["a1", "a2";
    "b3", "b4"];
assert_isequal(R, REF);
%=============================================================================
A = 1:2;
B = (1:3)';
R = B + A;
REF = [ 2     3;3     4;4     5];
assert_isequal(R, REF);
%=============================================================================
A = 1:2;
B = (1:3)';
R = int32(B) + int32(A);
REF = int32([ 2     3;3     4;4     5]);
assert_isequal(R, REF);
%=============================================================================
A = 1:2;
B = (1:3)';
R = A + B;
REF = [ 2     3;3     4;4     5];
assert_isequal(R, REF);
%=============================================================================
A = 1:2;
B = (1:3)';
R = int32(A) + int32(B);
REF = int32([ 2     3;3     4;4     5]);
assert_isequal(R, REF);
%=============================================================================
R = intmax('int32') + intmax('int32');
REF = intmax('int32');
assert_isequal(R, REF);
%=============================================================================

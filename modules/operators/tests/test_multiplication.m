%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% dot multiplication
A = [11 21;31 41;51 61];
B = [11 21;31 41;51 61];
C = [121 441;961 1681;2601 3721];
R = A.*B-C;
REF = zeros(3, 2);
assert_isequal(R, REF);
%=============================================================================
A = [11 21;31 41;51 61*i];
B = [11 21;31 41;51 61];
C = [121 441;961 1681;2601 3721*i];
R = A.*B-C;
REF = zeros(3, 2);
assert_isequal(R, REF);
%=============================================================================
A = [11 21;31 41;51 61];
B = [11 21;31 41;51 61*i];
C = [121 441;961 1681;2601 3721*i];
R = A.*B-C;
REF = zeros(3, 2);
assert_isequal(R, REF);
%=============================================================================
A = [11 21;31 41;51 61*i];
B = [11 21;31 41;51 61*i];
C = [121 441;961 1681;2601 -3721];
R = A.*B-C;
REF = zeros(3, 2);
assert_isequal(R, REF);
%=============================================================================
% matrix multiplication
A = [11 21 31;41 51 61];
B = [31;21;11];
C = [1123;3013];
R = A*B-C;
REF = [ 0; 0];
assert_isequal(R, REF);
%=============================================================================
A = [11 i 13;41 51 61];
B = [31;21;11];
C = [484+21*i;3013];
R = A*B-C;
REF = [ 0; 0];
assert_isequal(R, REF);
%=============================================================================
A = [11 21 31;41 51 61];
B = [i;21;11];
C = [782 + 11i;1742 + 41i];
R = A * B - C;
REF = [ 0; 0];
assert_isequal(R, REF);
%=============================================================================
A = [11 i 31;21*i,-11i,111];
B = [11i;-11i;11i];
C = [11+462i;-352+1221i];
R = A * B - C;
REF = [ 0; 0];
assert_isequal(R, REF);
%=============================================================================
M = [1.915, 2.418, 20.615;
6.301, 34.914, 216.38;
122.21, 23.47, 115.44];
N = [11.63, 31.915, 4.315;
217.16, 111.39, 219.57;
315.73, 10.78, 110.49];
R = M * N;
REF = [  7056.1383   552.6879  2816.9348;
75972.8623  6422.7433  31601.0820;
42965.9187  7759.0986  18435.6096];
assert_isapprox(R, REF, 1e-8);
%=============================================================================
M = [11.95, 12.48, 120.65;
16.30, 134.94, 126.38;
112.21, 12.47, 115.44];
N = [141-210i, 211-241i, 91.7-91.1i;
281-51.2i, 91-117i, 121+110i;
315-315i, 211-19.3i, 116+131i];
R = M * N;
REF = [   4.3197 - 4.1153i   2.9114 - 0.6669i   1.6601 + 1.6089i;
8.0026 - 5.0142i   4.2385 - 2.2155i   3.2483 + 2.9914i;
5.5689 - 6.0566i   4.9169 - 3.0730i   2.5190 + 0.6272i] * 1e4;
assert_isapprox(R, REF, 1e-3);
%=============================================================================
B = [11 21 31];
A = [14 ; 15 ;16];
R = A * B;
REF = [   154   294   434;165   315   465;176   336   496];
assert_isequal(R, REF);
%=============================================================================
A = [11 21 31];
B = [41 ; 51 ; 61];
R = A * B;
REF = 3413;
assert_isequal(R, REF);
%=============================================================================
A = [11 21 ; 31 41 ];
B = [51 ; 61];
R = A * B;
REF = [1842 ; 4082];
assert_isequal(R, REF);
%=============================================================================
A = single([11 21 ; 31 41 ]);
B = single([51 ; 61]);
R = A * B;
REF = single([1842 ; 4082]);
assert_isequal(R, REF);
%=============================================================================
B = [11 21; 31 41];
A = [51 61; 71 81];
R = [A * B];
REF = [2452 3572; 3292 4812];
assert_isequal(R, REF);
%=============================================================================
A = [11 21; 31 41 ];
B = [51 61; 71 81];
R = [A * B];
REF = [2052 2372; 4492 5212];
assert_isequal(R, REF);
%=============================================================================
a = ones(3, 3, 3);
assert_checkerror('a * a', _('Wrong size for input arguments: 2D matrix expected.'));
%=============================================================================
a = ones(3, 9, 3);
R = a .* a;
REF = a;
assert_isequal(R, REF);
%=============================================================================
R = intmax('int32') .* intmax('int32');
REF = intmax('int32');
assert_isequal(R, REF);
%=============================================================================

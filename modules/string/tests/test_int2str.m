%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('int2str'), 1);
assert_isequal(nargout('int2str'), 1);
%=============================================================================
A = [1, 2, 3; 4, 5, 6];
R = int2str(A);
REF = ['  1  2  3';
'  4  5  6'];
assert_isequal(R, REF);
%=============================================================================
A = [101:109];
A(4) = 3;
R = int2str(A);
REF = '  101  102  103    3  105  106  107  108  109';
assert_isequal(R, REF);
%=============================================================================
A = [101:109];
A(4) = 3;
R = int2str(reshape(A,[3 1 3]));
REF = ['  101    3  107';
'  102  105  108';
'  103  106  109'];
assert_isequal(R, REF);
%=============================================================================
A = [101:109];
A(4) = 3;
R = int2str(reshape(A,[1 3 3]));
REF = '  101  102  103    3  105  106  107  108  109';
assert_isequal(R, REF);
%=============================================================================
R = int2str(reshape(A,[3 3 1]));
REF = ['  101    3  107';
'  102  105  108';
'  103  106  109'];
assert_isequal(R, REF);
%=============================================================================
R = int2str(true);
REF = '1';
assert_isequal(R, REF);
%=============================================================================
R = int2str(-123);
REF = '-123';
assert_isequal(R, REF);
%=============================================================================
R = int2str(pi);
REF = '3';
assert_isequal(R, REF);
%=============================================================================
R = int2str([]);
REF = '';
assert_isequal(R, REF);
%=============================================================================
R = int2str ([-Inf, 2, NaN; 4, Inf, 6]);
REF = [
'  -Inf     2   NaN';
'     4   Inf     6'
];
assert_isequal(R, REF);
%=============================================================================
A = int8(ones(3, 3, 3));
R = int2str(A);
REF = ['  1  1  1  1  1  1  1  1  1';
'  1  1  1  1  1  1  1  1  1';
'  1  1  1  1  1  1  1  1  1'];
assert_isequal(R, REF);
%=============================================================================
R = int2str(uint64(intmax('uint64')));
REF = '18446744073709551615';
assert_isequal(R, REF);
%=============================================================================
R = int2str('Nelson');
REF = '   78  101  108  115  111  110';
assert_isequal(R, REF);
%=============================================================================
R = int2str(sparse(eye(3,3)));
REF = ['  1  0  0';
'  0  1  0';
'  0  0  1'];
assert_isequal(R, REF);
%=============================================================================
assert_checkerror('int2str()', _('Wrong number of input arguments.'));
assert_checkerror('int2str(1, 2)', _('Wrong number of input arguments.'));
assert_checkerror('[a, b] = int2str(3)', _('Wrong number of output arguments.'));
%=============================================================================

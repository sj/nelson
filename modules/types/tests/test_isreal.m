%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('isreal'), 1);
assert_isequal(nargout('isreal'), 1);
%=============================================================================
R = complex(13);
assert_isfalse(isreal(R));
%=============================================================================
R = complex([]);
assert_istrue(isreal(R));
%=============================================================================
R = complex([]);
assert_istrue(isreal(ones(3, 0)));
%=============================================================================
R1 = 3 + 14i;
R2 = 5 - 14i;
R = R1 + R2;
assert_isfalse(isreal(R1));
assert_isfalse(isreal(R2));
assert_istrue(isreal(R));
%=============================================================================
R1 = 3 - 14i;
R2 = 5 - 14i;
R = R2 - R1;
assert_isfalse(isreal(R1));
assert_isfalse(isreal(R2));
assert_istrue(isreal(R));
%=============================================================================
R = isreal(1+0i);
assert_istrue(R);
%=============================================================================
R = isreal([]);
assert_istrue(R);
%=============================================================================
R = isreal(complex([]));
assert_istrue(R);
%=============================================================================
R = isreal(complex(ones(3, 0)));
assert_isfalse(R);
%=============================================================================
R = isreal([1]);
assert_istrue(R);
%=============================================================================
R = isreal([1,2,3]);
assert_istrue(R);
%=============================================================================
R = isreal([1;2;3]);
assert_istrue(R);
%=============================================================================
R = isreal([1,2,3;4,5,6]);
assert_istrue(R);
%=============================================================================
R = isreal([i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i,2i,3i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i;2i;3i]);
assert_isfalse(R);
%=============================================================================
R = isreal([i,2i,3i;4i,5i,6i]);
assert_isfalse(R);
%=============================================================================
R = isreal(['s']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1','str2','str3']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1';'str2';'str3']);
assert_istrue(R);
%=============================================================================
R = isreal(['str1','str2','str3';'str4','str5','str6']);
assert_istrue(R);
%=============================================================================
R = isreal([[1]==[1]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1,2,3]==[1,0,3]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1;2;3]==[1;0;3]]);
assert_istrue(R);
%=============================================================================
R = isreal([[1,2,3;4,5,6]==[1,0,3;4,5,0]]);
assert_istrue(R);
%=============================================================================
R = isreal(rand(3,3,3));
assert_istrue(R);
%=============================================================================
R = isreal(sparse(4 + 3i));
assert_isfalse(R);
%=============================================================================
R = isreal(sparse(true));
assert_istrue(R);
%=============================================================================
R = isreal({});
assert_isfalse(R);
%=============================================================================
R = isreal(struct());
assert_isfalse(R);
%=============================================================================
R = single([3, i]);
assert_isfalse(isreal(R));
%=============================================================================
R = [3, i];
assert_isfalse(isreal(R));
%=============================================================================
R = [3, 0i];
assert_istrue(isreal(R));
%=============================================================================

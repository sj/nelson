%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = 1:10;
filename = [tempdir(), '漢字.nh5'];
save(filename, 'A');
assert_istrue(isfile(filename));
clear
filename = [tempdir(), '漢字.nh5'];
assert_isfalse(isvar('A'));
load(filename);
assert_istrue(isvar('A'));
assert_isequal(A, 1:10);
%=============================================================================
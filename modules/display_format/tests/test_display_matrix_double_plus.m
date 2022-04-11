%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
format('+')
%=============================================================================
R = evalc('A = [0.3 0 .2 .1 -1]');
REF = '
A =

+ ++-

';
assert_isequal(R, REF)
%=============================================================================

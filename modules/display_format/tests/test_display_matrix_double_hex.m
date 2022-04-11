%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
rng('default')
format('hex')
%=============================================================================
A = pi;
R = evalc('A');
REF =  '
A =

   400921fb54442d18

';
assert_isequal(R, REF)
%=============================================================================
A = [pi, eps];
R = evalc('A');
REF = '
A =

   400921fb54442d18   3cb0000000000000

';
assert_isequal(R, REF)
%=============================================================================

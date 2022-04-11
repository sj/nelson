%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
format('hex')
%=============================================================================
R = evalc('A = complex([0.3 .2 .1],.4)');
REF =  '
A =

  Columns 1 through 2

   3fd3333333333333   3fd999999999999ai   3fc999999999999a   3fd999999999999ai

  Column 3

   3fb999999999999a   3fd999999999999ai

';
assert_isequal(R, REF)
%=============================================================================

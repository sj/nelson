%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
x = sparse([1+i,-i;i,2i]);
r = conj(x);
ref =  sparse([1-i, i;-i,-2i]);
assert_isequal(r, ref);
%=============================================================================

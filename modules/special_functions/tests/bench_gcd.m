%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = ceil(1000 * rand(70000, 1));
B = ceil(1000 * rand(70000, 1));
tic();R = gcd(A, B);toc();
%=============================================================================

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
V = [];
D = [];
N = 1000;
A = [1:(N*N)];
M = reshape(A, N, N);
tic();[V, D] = eig(M);toc()
%=============================================================================

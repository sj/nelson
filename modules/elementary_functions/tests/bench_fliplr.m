%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--INDEX 64 BIT REQUIRED-->
%=============================================================================
A = rand(9000, 9000);
tic();R = fliplr(A);toc();
%=============================================================================
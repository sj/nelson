%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = sparse(zeros(3, 0));
R = A';
assert_isequal(size(R), [0 3]);
%=============================================================================
A = sparse(eye(3, 3) * i);
R = A';
REF = sparse(eye(3, 3) * -i);
assert_isequal(R, REF);
%=============================================================================

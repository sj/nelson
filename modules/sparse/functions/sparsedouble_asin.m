%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function r = sparsedouble_asin(a)
 [I, J, V] = IJV(a);
 r = sparse(I, J, asin(V), size(a, 1), size(a, 2));
end

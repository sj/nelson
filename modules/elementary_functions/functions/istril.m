%=============================================================================
% Copyright (c) 2019-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function R = istril(M)
    R = (islogical(M) || isnumeric(M)) && (ndims(M) == 2);
    if (R)
      [I, J] = find(M);
      R = all (I >= J);
    end
end
%=============================================================================

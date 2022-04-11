%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function r = cosd (x)
  I = x * inv(180);
  r = cos (I .* pi);
  I = I + 0.5;
  r(I == fix (I) & isfinite (I)) = 0;
end
%=============================================================================

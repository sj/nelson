%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function pint = polyint(varargin)
  narginchk(1, 2)
  nargoutchk(0, 1)
  p = varargin{1};
  if nargin < 2
    k = 0;
  else
    k = varargin{2};
  end
  pint = [(p(:).')./(length(p):-1:1),k];
end
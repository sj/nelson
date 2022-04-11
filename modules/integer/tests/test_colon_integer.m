%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
R = 1:int64(3);
REF = int64([1 2 3]);
assert_isequal(R, REF);
%=============================================================================
assert_checkerror('R = 0.1:int64(3);', _('Colon input arguments must have same type.'));
%=============================================================================
R = int64(10):int64(1):int64(15);
REF = int64([10 11 12 13 14 15]);
%=============================================================================

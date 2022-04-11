%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <-- Issue URL -->
% https://github.com/Nelson-numerical-software/nelson/issues/78
% <-- Short Description -->
% [p,f,e]=fileparts('c:/') did not return the good result
%=============================================================================
[p, f, e] = fileparts('c:/');
assert_isequal(p, 'c:/');
assert_isequal(f, '');
assert_isequal(e, '');
%=============================================================================

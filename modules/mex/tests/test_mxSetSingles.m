%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
if exist('mxSetSingles') == 0
    test_dir = [tempdir(), 'mxSetSingles'];
    if isdir(test_dir)
        rmdir(test_dir,'s');
    end
    mkdir(test_dir);
    status = copyfile('mxSetSingles.c', test_dir);
    assert_istrue(status);
    cd(test_dir);
    mex('mxSetSingles.c', '-R2018a')
    addpath(pwd())
end
%=============================================================================
R = mxSetSingles();
REF = single([33; 44]);
assert_isequal(R, REF);
%=============================================================================

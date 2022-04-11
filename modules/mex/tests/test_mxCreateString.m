%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
if exist('mxCreateString') == 0
    test_dir = [tempdir(), 'mxCreateString'];
    if isdir(test_dir)
        rmdir(test_dir,'s');
    end
    mkdir(test_dir);
    status = copyfile('mxCreateString.c', test_dir);
    assert_istrue(status);
    cd(test_dir);
    mex('mxCreateString.c');
    addpath(pwd())
end
%=============================================================================
R = mxCreateString();
assert_isequal(R, 'It works !!!');
%=============================================================================
%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
TMPDIR = tempdir();
if ismac()
  TMPDIR = ['/private', TMPDIR];
end
%=============================================================================
REF1 = [TMPDIR, 'level1/T1.txt'];
REF2 = [TMPDIR, 'level1/level2/T2.txt'];
REF3 = [TMPDIR, 'level1/level2/level3/T3.txt'];
%=============================================================================
TMP = [TMPDIR, 'level1/level2/level3'];
if ~isdir(TMP)
  mkdir(TMP);
end
cd(TMP);
%=============================================================================
M = {REF1; REF2; REF3};
R = {'../../T1.txt', '../T2.txt', 'T3.txt'};
assert_isequal(M, fullpath(R));
%=============================================================================
R1 = fullpath('../../T1.txt');
assert_isequal(R1, REF1);
%=============================================================================
R2 = fullpath('../T2.txt');
assert_isequal(R2, REF2);
%=============================================================================
R3 = fullpath('T3.txt');
assert_isequal(R3, REF3);
%=============================================================================
R4 = fullpath(REF1);
assert_isequal(R4, REF1);
%=============================================================================
R5 = fullpath(REF2);
assert_isequal(R5, REF2);
%=============================================================================
R6 = fullpath(REF3);
assert_isequal(R6, REF3);
%=============================================================================

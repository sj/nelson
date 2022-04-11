%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
A = logical([1 2 3; 4 5 6]);
B = logical([7; 8]);
R1 = horzcat(A, B);
R2 = [A, B];
assert_isequal(R1, R2);
%=============================================================================
A = logical([1 2 3; 4 5 6]);
B = logical([7 8 9]);
R1 = vertcat(A, B);
R2 = [A; B];
assert_isequal(R1, R2);
%=============================================================================
A = [1 2 3; 4 5 6];
B = [7; 8];
R1 = horzcat(A, B);
R2 = [A, B];
assert_isequal(R1, R2);
%=============================================================================
A = [1 2 3; 4 5 6];
B = [7 8 9];
R1 = vertcat(A, B);
R2 = [A; B];
assert_isequal(R1, R2);
%=============================================================================
A = [1 2 3i; 4 5 6];
B = [7 8 9i];
R1 = vertcat(A, B);
R2 = [A; B];
assert_isequal(R1, R2);
%=============================================================================
A = sparse([1 2 3; 4 5 6]);
B = sparse([7; 8]);
R1 = full(horzcat(A, B));
R2 = full([A, B]);
assert_isequal(R1, R2);
%=============================================================================
A = sparse([1 2 3i; 4 5 6]);
B = sparse([7; 8i]);
R1 = full(horzcat(A, B));
R2 = full([A, B]);
assert_isequal(R1, R2);
%=============================================================================
A = sparse([1 2 3; 4 5 6]);
B = sparse([7 8 9]);
R1 = full(vertcat(A, B));
R2 = full([A; B]);
assert_isequal(R1, R2);
%=============================================================================
A = sparse([1 2 3i; 4 5 6]);
B = sparse([7 8 9i]);
R1 = full(vertcat(A, B));
R2 = full([A; B]);
assert_isequal(R1, R2);
%=============================================================================

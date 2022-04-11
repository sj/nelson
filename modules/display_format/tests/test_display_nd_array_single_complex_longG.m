%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
rng('default')
format('longG')
%=============================================================================
A = complex(rand(3,3,2), rand(3,3,2));
A(1) = 0;
R = evalc('A = single(A)');
REF =       '
  3×3×2 single array

A(:,:,1) =

  Columns 1 through 2

             0 +            0i     0.9133759 +   0.03571168i
     0.9057919 +    0.9594924i     0.6323593 +    0.8491293i
     0.1269868 +    0.6557407i     0.0975404 +    0.9339932i

  Column 3

     0.2784982 +    0.6787351i
     0.5468815 +    0.7577401i
     0.9575068 +    0.7431325i


A(:,:,2) =

  Columns 1 through 2

     0.9648885 +     0.392227i      0.957167 +    0.7060461i
     0.1576131 +    0.6554779i     0.4853756 +   0.03183284i
     0.9705928 +    0.1711867i     0.8002805 +     0.276923i

  Column 3

     0.1418863 +   0.04617139i
     0.4217613 +   0.09713177i
     0.9157355 +    0.8234578i

';
assert_isequal(R, REF)
%=============================================================================

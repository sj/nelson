%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
function M = magic(N)
  if (nargin < 1)
    error(_('Wrong number of input arguments.'));
  end
  if (nargout > 1)
    error(_('Wrong number of output arguments.'));
  end
  M = [];
  N = double(fix(real(N(1))));
  if N < 0
    N = 0;
  end
  if N == 0
    M =  [];
  elseif mod(N, 2) == 1
    M = caseModN2(N);
  elseif mod(N, 4) == 0
    M = caseModN4(N);
  elseif mod (N, 4) == 2
    M = caseModOther(N);
  end
end
%=============================================================================
function M = caseModN2(N)
  s = floor ((0:N*N-1)/N);
  c = mod([1:N*N] - s + (N-3)/2, N);
  r = mod ([N*N:-1:1] + 2*s, N);
  M(c*N+r+1) = 1:N*N;
  M = reshape (M, N, N);
end
%=============================================================================
function M = caseModN4(N)
  M = reshape (1:N * N, N, N)';
  I = [1:4:N, 4:4:N];
  J = fliplr(I);
  M(I, I) = M(J, J);
  I = [2:4:N, 3:4:N];
  J = fliplr(I);
  M(I, I) = M(J, J);
end
%=============================================================================
function M = caseModOther(N)
  M = zeros(N, N);
  if mod(N, 2) == 0
    m = N / 2;
  else
    m = N;
  end
  i = 1;
  j = (m+1)/2;
  mm = m * m;
  for k = 1: mm
    M(i, j) = k;
    i1 = i - 1;
    j1 = j + 1;
    if i1 < 1
      i1 = m;
    end
    if j1 > m
      j1 = 1;
    end
    if (fix(M(i1, j1)) ~= 0)
      i1 = i + 1;
      j1 = j;
    end
    i = i1;
    j = j1;
  end
  if (mod(N, 2) ~= 0)
    return
  end
  t = m*m;
  for i = 1: m
    for j = 1: m
      im = i+m;
      jm = j+m;
      M(i, jm) = M(i, j) + 2*t;
      M(im, j) = M(i, j) + 3*t;
      M(im, jm) = M(i, j) + t;
    end
  end
  m1 = (m-1)/2;
  if m1 == 0
    return
  end
  for j = 1:m1
    t = M(1:m,j);
    M(1:m,j) = M(m+1:m+m,j);
    M(m+1:m+m,j) = t;
  end
  m1 = (m+1)/2;
  m2 = m1 + m;
  t = M(m1,1);
  M(m1, 1) = M(m2,1);
  M(m2, 1) = t;
  t = M(m1,m1);
  M(m1, m1) = M(m2,m1);
  M(m2, m1) = t;
  m1 = N+1-(m-3)/2;
  if m1 > N
    return
  end
  for j = m1: N
    t = M(1:m,j);
    M(1:m, j) = M(m+1:m+m,j);
    M(m+1:m+m, j) = t;
  end
end
%=============================================================================
%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
format('short')
%=============================================================================
A = complex(9, 3);
R = evalc('A');
REF =  '
A =

   9.0000 + 3.0000i

';
assert_isequal(R, REF)
%=============================================================================
A = complex(9, NaN);
R = evalc('A');
REF =  '
A =

   9.0000 +    NaNi

';
assert_isequal(R, REF)
%=============================================================================
A = complex(NaN, NaN);
R = evalc('A');
REF =  '
A =

      NaN +    NaNi

';
assert_isequal(R, REF)
%=============================================================================
A = complex(NaN, 3);
R = evalc('A');
REF =  '
A =

      NaN + 3.0000i

';
assert_isequal(R, REF)
%=============================================================================
A = complex(100, 3);
R = evalc('A');
REF =  '
A =

   1.0000e+02 + 3.0000e+00i

';
assert_isequal(R, REF)
%=============================================================================
A = complex(99, 3);
R = evalc('A');
REF =      '
A =

  99.0000 + 3.0000i

';
assert_isequal(R, REF)
%=============================================================================
A = complex(3, 100);
R = evalc('A');
REF =  '
A =

   3.0000e+00 + 1.0000e+02i

';
assert_isequal(R, REF)
%=============================================================================
A = complex(3, 99);
R = evalc('A');
REF =  '
A =

   3.0000 +99.0000i

';
assert_isequal(R, REF)
%=============================================================================

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
format('bank')
%=============================================================================
R = evalc('A = 1e99');
REF = '
A =

 999999999999999967336168804116691273849533185806555472917961779471295845921727862608739868455469056.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1e99');
REF = '
A =

 -999999999999999967336168804116691273849533185806555472917961779471295845921727862608739868455469056.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = pi');
REF = '
A =

          3.14

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = NaN');
REF =      '
A =

           NaN

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = Inf');
REF =     '
A =

           Inf

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -Inf');
REF =  '
A =

          -Inf

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = eps');
REF = '
A =

          0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -eps');
REF = '
A =

         -0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1.123456789e-1');
REF = '
A =

         -0.11

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1.123456789e-2');
REF = '
A =

         -0.01

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1.123456789e-3');
REF = '
A =

         -0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1.123456789e-4');
REF =  '
A =

         -0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = -1.123456789e-9');
REF =     '
A =

         -0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = 1.123456789e-1');
REF =     '
A =

          0.11

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = 1.123456789e-2');
REF =   '
A =

          0.01

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = 1.123456789e-3');
REF = '
A =

          0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = 1.123456789e-4');
REF = '
A =

          0.00

';
assert_isequal(R, REF)
%=============================================================================
R = evalc('A = 1.123456789e-9');
REF = '
A =

          0.00

';
assert_isequal(R, REF)
%=============================================================================


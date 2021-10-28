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
% <--C/C++ COMPILER REQUIRED-->
%=============================================================================
run([modulepath('mex'), '/examples/mex_engine_demo_1.m'])
filename = [tempdir(), 'mex_engine_demo_1/mex_engine_demo_1'];
if ispc()
    filename = [filename, '.exe'];
end
assert_istrue(isfile(filename));
%=============================================================================
run([modulepath('mex'), '/examples/mex_engine_demo_2.m']);
filename = [tempdir(), 'mex_engine_demo_2/mex_engine_demo_2'];
if ispc()
    filename = [filename, '.exe'];
end
assert_istrue(isfile(filename));
%=============================================================================
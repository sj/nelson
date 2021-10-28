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
destinationdir = [tempdir(), 'test_cmake'];
mkdir(destinationdir);
%=============================================================================
currentpath = fileparts(nfilename('fullpathext'));
copyfile([currentpath, '/test_build_c.c'], [destinationdir, '/test_build_c.c']);
copyfile([currentpath, '/test_build_c.h'], [destinationdir, '/test_build_c.h']);
%=============================================================================
[status, message] = dlgeneratemake(destinationdir, ...
        'test_c', ...
        [destinationdir, '/test_build_c.c'], ...
        [destinationdir, '/']);
if ~status
  error(message);
end
assert_istrue(isfile([destinationdir, '/CMakeLists.txt']));
txt = fileread([destinationdir, '/CMakeLists.txt']);
assert_istrue(contains(txt, 'set(module_library_name test_c)'));
%=============================================================================
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
test_h5save_file = [tempdir(), 'test_h5save_class.nh5'];
if isfile(test_h5save_file)
  rmfile(test_h5save_file);
end
%=============================================================================
addpath([nelsonroot(), '/modules/overload/examples/complex']);
cplx = complexObj(3, 4);
savenh5(test_h5save_file, 'cplx');
%=============================================================================
R = h5readatt(test_h5save_file, '/cplx', 'NELSON_class');
assert_isequal(R, class(cplx));
R = h5readatt(test_h5save_file, '/cplx', 'NELSON_dimensions');
assert_isequal(R, uint64([1; 1]));
R = h5readatt(test_h5save_file, '/cplx', 'NELSON_object');
assert_isequal(R, uint8(1));
R = h5read(test_h5save_file, '/cplx/0');
assert_isequal(R, 3);
R = h5read(test_h5save_file, '/cplx/1');
assert_isequal(R, 4);
R = h5read(test_h5save_file, '/cplx/fieldnames/0');
assert_isequal(R, uint16('r'));
R = h5read(test_h5save_file, '/cplx/fieldnames/1');
assert_isequal(R, uint16('i'));
%=============================================================================

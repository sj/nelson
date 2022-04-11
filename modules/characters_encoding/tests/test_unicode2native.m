%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('unicode2native'), 2);
assert_isequal(nargout('unicode2native'), 1);
%=============================================================================
R1 = unicode2native('éléve');
R2 = unicode2native('éléve', '');
assert_isequal(R1, R2);
%=============================================================================
R = unicode2native('azerty', 'ascii');
REF = uint8([97   122   101   114   116   121]);
assert_isequal(R, REF);
%=============================================================================
R = unicode2native('éléve', 'ascii');
REF = uint8([26   108    26   118   101]);
assert_isequal(R, REF);
%=============================================================================
R = unicode2native('éléve', 'UTF-8');
REF = uint8([195   169   108   195   169   118   101]);
assert_isequal(R, REF);
%=============================================================================
R = unicode2native('éléve', 'Windows-1252');
REF = uint8([233   108   233   118   101]);
assert_isequal(R, REF);
%=============================================================================
R = unicode2native ("Виртуальная", 'Windows-1251');
REF = uint8([194   232   240   242   243   224   235   252   237   224   255]);
assert_isequal(R, REF);
%=============================================================================
R = unicode2native('片仮名', 'SHIFT_JIS');
REF = uint8([149   208   137   188   150   188]);
%=============================================================================
assert_checkerror('R = unicode2native(''Виртуальная'', ''_M$_'');', [_('Invalid charset: '), '_M$_'])
%=============================================================================

%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--ADV-CLI MODE-->
% <--WITH DISPLAY-->
%=============================================================================
assert_isequal(nargin('qml_loadstring'), 1);
assert_isequal(nargout('qml_loadstring'), 1);
%=============================================================================
qml_file_ok = [modulepath('qml_engine'), '/tests/test_qml_loadfile_window.qml'];
txt = fileread(qml_file_ok);
qobj = qml_loadstring(txt);
assert_istrue(QObject_iswindowtype(qobj));
delete(qobj);
%=============================================================================
qml_file_ko = [modulepath('qml_engine'), '/tests/test_qml_loadfile_rectangle.qml'];
txt = fileread(qml_file_ko);
qobj = qml_loadstring(txt);
assert_isfalse(QObject_iswindowtype(qobj));
assert_isfalse(QObject_iswidgettype(qobj));
%=============================================================================
delete(qobj);
%=============================================================================

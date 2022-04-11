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
assert_isequal(nargin('QObject_iswidgettype'), 1);
assert_isequal(nargout('QObject_iswidgettype'), 1);
%=============================================================================
qml_file_ok = [modulepath('qml_engine'), '/tests/test_qml_loadfile_window.qml'];
qobj = qml_loadfile(qml_file_ok);
assert_isfalse(QObject_iswidgettype(qobj));
%=============================================================================
delete(qobj);
%=============================================================================

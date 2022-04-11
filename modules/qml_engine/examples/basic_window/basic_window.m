%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
root = QObject_root();
if ~isempty(root)
  qobj = QObject_findchildren(QObject_root(), 'basic_window', true);
else
  qobj = [];
end
if isempty(qobj)
  qml_file = [modulepath('qml_engine'), '/examples/basic_window/hello.qml'];
  qobj = qml_loadfile(qml_file);
else
  qobj.visible = true;
end
%=============================================================================

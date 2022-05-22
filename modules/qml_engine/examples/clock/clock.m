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
  qobj = QObject_findchildren(QObject_root(), 'clock', true);
else
  qobj = [];
end
if isempty(qobj)
  if semver(qt_version(), '>=6.0')
    qml_file = [modulepath('qml_engine'), '/examples/clock/clocks_qt6.qml'];
  else
    qml_file = [modulepath('qml_engine'), '/examples/clock/clocks_qt5.qml'];
  end
    addpath([modulepath('qml_engine'), '/examples/clock/']);
  qobj = qml_loadfile(qml_file);
end
qobj.visible = true;
%=============================================================================

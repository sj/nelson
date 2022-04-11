%=============================================================================
% Copyright (c) 2017 Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
% <--GUI MODE-->
% <--NO USER MODULES-->
%=============================================================================
modules_loaded = getmodules();
run([nelsonroot(), '/modules/modules.m']);
if ~ispc()
  modules_list(strcmp(modules_list,'com_engine')) = [];
end
if ~any(strcmp(getnelsonmode(), ["ADVANCED_SIO_CLIENT", "BASIC_SIO_CLIENT"]))
  modules_list(strcmp(modules_list, 'sio_client')) = [];
end
if ~ismodule('slicot')
  modules_list(strcmp(modules_list, 'slicot')) = [];
end
if ~ismodule('fftw')
  modules_list(strcmp(modules_list, 'fftw')) = [];
end
if ~ismodule('mpi')
  modules_list(strcmp(modules_list, 'mpi')) = [];
end
if ~ismodule('ipc')
  modules_list(strcmp(modules_list, 'ipc')) = [];
end
assert_isequal(modules_loaded, cellstr(modules_list));
%=============================================================================


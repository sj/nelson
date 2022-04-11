%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function dlgeneratecleaner(varargin)
  % dlgeneratecleaner(destinationdir)
  % dlgeneratecleaner(destinationdir, files)
  status = false;
  message = '';
  if nargin < 1 || nargin > 2
    error(_('Wrong numbers of input arguments.'));
  end
  destinationdir = varargin{1};
  if nargin > 1
    files = varargin{2};
  else
    files = {};
  end
  if ~isdir(destinationdir)
    error(_('A valid destination directory expected.'));
  end
  if ischar(files)
    files = {files};
  end
  for k = files(:)'
    if ~ischar(k{1})
      error(_('Valid files list expected.'));
    end
  end
  cleanerfilename = [destinationdir, '/cleaner.m'];
  txt = templatecleanerpart1(destinationdir);
  txt = [txt; templatecleanerpart2(files)];
  txt = [txt; templatecleanerpart3()];
  txt = [txt; templatecleanerpart4()];
  txt = [txt; templatecleanerpart5()];
  filewrite(cleanerfilename, txt);
  status = true;
  message = '';
end
%=============================================================================
function txt = templatecleanerpart1(destinationdir)
  txt = {'%============================================================================='};
  txt = [txt; '% Generated by Nelson'];
  txt = [txt; '% # Please do not edit this file'];
  txt = [txt; '%============================================================================='];
  txt = [txt; 'current_directory = pwd();'];
  txt = [txt; ['cd(fileparts(nfilename(''fullpathext'')));']];
  txt = [txt; '%============================================================================='];
  txt = [txt; 'if isfile(''loader.m'')'];
  txt = [txt; '  rmfile(''loader.m'');'];
  txt = [txt; 'end'];
  txt = [txt; '%============================================================================='];
  txt = [txt; 'if isfile(''unloader.m'')'];
  txt = [txt; '  rmfile(''unloader.m'');'];
  txt = [txt; 'end'];
  txt = [txt; '%============================================================================='];
 end
%=============================================================================
function txt = templatecleanerpart2(files)
  txt = {};
  for k = files(:)'
    txt = [txt; ['if isfile(''', k{1}, ''')']];
    txt = [txt; ['  rmfile(''', k{1}, ''');']];
    txt = [txt; 'end'];
    txt = [txt; {'%============================================================================='}];
  end
 end
%=============================================================================
function txt = templatecleanerpart3(files)
  txt = {};
  [status, compiler] = havecompiler();
  if status
    if ispc()
      if strcmp(compiler, 'msvc')
        make_name = 'nmake';
      end
      if strcmp(compiler, 'mingw')
        make_name = 'make';
      end
    else
      make_name = 'make';
    end
    txt = [txt; ['status = unix(''', make_name , ' clean'');']];
    txt = [txt; ['clear(''status'');']];
    txt = [txt; {'%============================================================================='}];
  end
end
%=============================================================================
function txt = templatecleanerpart4()
  txt = {};
  txt = [txt; 'if isfile(''Makefile'');'];
  txt = [txt; '  rmfile(''Makefile'');'];
  txt = [txt; 'end'];
  txt = [txt; 'if isfile(''CMakeLists.txt'');'];
  txt = [txt; '  rmfile(''CMakeLists.txt'');'];
  txt = [txt; 'end'];
  txt = [txt; 'if isfile(''CMakeCache.txt'');'];
  txt = [txt; '  rmfile(''CMakeCache.txt'');'];
  txt = [txt; 'end'];
  txt = [txt; 'if isfile(''cmake_install.cmake'');'];
  txt = [txt; '  rmfile(''cmake_install.cmake'');'];
  txt = [txt; 'end'];
  txt = [txt; 'if isdir(''CMakeFiles'');'];
  txt = [txt; '  rmdir(''CMakeFiles'',''s'');'];
  txt = [txt; 'end'];
  if ispc()
    txt = [txt; 'f = dir(''*.exp'');'];
    txt = [txt; 'for k = f(:)'''];
    txt = [txt; '  rmfile(k.name);'];
    txt = [txt; 'end'];
    txt = [txt; 'f = dir(''*.ilk'');'];
    txt = [txt; 'for k = f(:)'''];
    txt = [txt; '  rmfile(k.name);'];
    txt = [txt; 'end'];
  end
end
%=============================================================================
function txt = templatecleanerpart5()
  txt = {'%============================================================================='};
  txt = [txt; 'if isfile(''cleaner.m'');'];
  txt = [txt; '  rmfile(''cleaner.m'');'];
  txt = [txt; 'end'];
  txt = [txt; {'%============================================================================='}];
  txt = [txt; {'cd(current_directory);'}];
  txt = [txt; {'clear(''current_directory'');'}];
  txt = [txt; {'%============================================================================='}];
 end
%=============================================================================

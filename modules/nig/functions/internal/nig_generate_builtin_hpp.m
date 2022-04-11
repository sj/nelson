%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function txt = nig_generate_builtin_hpp(NIG_FUNCTION)
  txt = nig_header_license();
  txt{end + 1} = ['// Generated by Nelson Interface Generator ', nig_version()];
  txt{end + 1} = '//=============================================================================';
  CppBuiltinName = [NIG_FUNCTION.NELSON_NAME, 'Builtin'];
  begin_txt = {'#pragma once';
  '//=============================================================================';
  '#include "ArrayOf.hpp"';
  '//=============================================================================';
  'namespace Nelson {';
  };
  txt = [txt; begin_txt];
  if isfield(NIG_FUNCTION, 'NELSON_NAMESPACE')
    txt{end + 1} = ['    ', 'namespace ' , NIG_FUNCTION.NELSON_NAMESPACE, 'Gateway {'];
    txt{end + 1} = ['        ', 'ArrayOfVector ', NIG_FUNCTION.NELSON_NAME, 'Builtin(int nLhs, const ArrayOfVector& argIn);'];
    txt{end + 1} = ['    ', '}'];
    txt{end + 1} = '}';
  else
   txt{end + 1} = ['    ', 'ArrayOfVector ', NIG_FUNCTION.NELSON_NAME, 'Builtin(int nLhs, const ArrayOfVector& argIn);'];
   txt{end + 1} = '}';
  end
  txt{end + 1} = '//=============================================================================';
end
%=============================================================================

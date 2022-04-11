//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <mex.h>
//=============================================================================
void
mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
#if defined (MX_HAS_INTERLEAVED_COMPLEX)
  mxArray *pa = mxCreateDoubleMatrix (2, 1, mxREAL);
  mxDouble *pd  = mxGetDoubles(pa);
  mxDouble *dt = mxMalloc(2 * sizeof(mxDouble));
  dt[0] = 33;
  dt[1] = 44;
  mxFree(pd);  
  mxSetDoubles(pa, dt);
  plhs[0] = pa;
  int i;
  for (i = 1; i < nlhs; i++) {
      plhs[i] = mxCreateDoubleMatrix (0, 0, mxREAL);
  }
#endif
}
//=============================================================================

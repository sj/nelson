//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "dlinfoBuiltin.hpp"
#include "Error.hpp"
#include "DynamicLinkLibraryObject.hpp"
#include "HandleManager.hpp"
#include "ToCellString.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector Nelson::DynamicLinkGateway::dlinfoBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (argIn.size() != 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    if (nLhs > 1)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    ArrayOf param1 = argIn[0];
    HandleGenericObject *hlObj = param1.getContentAsHandleScalar();
    if (hlObj->getCategory() != DLLIB_CATEGORY_STR)
    {
        Error(eval, _W("dllib handle expected."));
    }
    DynamicLinkLibraryObject *obj = (DynamicLinkLibraryObject *)hlObj;
    retval.push_back(ToCellStringAsColumn(obj->getAvailableSymbols()));
    return retval;
}
//=============================================================================
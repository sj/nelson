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
#include "audioplayer_setBuiltin.hpp"
#include "Error.hpp"
#include "AudioplayerObject.hpp"
#include "HandleManager.hpp"
#include "HandleGenericObject.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector Nelson::AudioGateway::audioplayer_setBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    if (argIn.size() != 3)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    if (nLhs > 0)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    ArrayOf param1 = argIn[0];
    ArrayOf param2 = argIn[1];
    std::wstring propertyName = param2.getContentAsWideString();
    ArrayOf param3 = argIn[2];
    ArrayOfVector retval;
    HandleGenericObject *hlObj = param1.getContentAsHandleScalar();
    if (hlObj->getCategory() != AUDIOPLAYER_CATEGORY_STR)
    {
        Error(eval, _W("audioplayer handle expected."));
    }
    AudioplayerObject *objPlayer = (AudioplayerObject *)hlObj;
    if (!objPlayer->isWriteableProperty(propertyName))
    {
        Error(eval, _W("Cannot set a read only property."));
    }
    std::wstring errorMessage;
    if (objPlayer->set(propertyName, param3, errorMessage))
    {
        Error(eval, errorMessage);
    }
    return retval;
}
//=============================================================================

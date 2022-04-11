//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "GOProperty.hpp"
#include "Error.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
class GOOnOffSwitchProperty : public GOProperty
{
protected:
    logical m_data;

public:
    //=============================================================================
    GOOnOffSwitchProperty() = default;
    //=============================================================================
    ~GOOnOffSwitchProperty() override = default;
    //=============================================================================
    ArrayOf
    get() override;
    //=============================================================================
    void set(ArrayOf /*value*/) override;
    //=============================================================================
    logical
    asLogical()
    {
        return m_data;
    }
    //=============================================================================
    std::string
    data()
    {
        return (m_data == 0) ? "off" : "on";
    }
    //=============================================================================
    std::string
    print(const std::string& propertyName) override
    {
        std::string res = "\t" + propertyName + ":\t";
        std::string v = (m_data == 0) ? "off" : "on";
        return res + v;
    }
    //=============================================================================
    void
    value(const std::string& m)
    {
        if (m == "on") {
            m_data = true;
        } else if (m == "off") {
            m_data = false;
        } else {
            Error(_W("'off' or 'on' expected."));
        }
    }
    //=============================================================================
};
//=============================================================================
} // namespace Nelson
//=============================================================================

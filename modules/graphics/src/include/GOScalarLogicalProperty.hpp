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
//=============================================================================
namespace Nelson {
//=============================================================================
class GOScalarLogicalProperty : public GOProperty
{
protected:
    logical m_data;

public:
    //=============================================================================
    GOScalarLogicalProperty() = default;
    //=============================================================================
    ~GOScalarLogicalProperty() override = default;
    //=============================================================================
    ArrayOf
    get() override;
    //=============================================================================
    void set(ArrayOf /*value*/) override;
    //=============================================================================
    logical
    data()
    {
        return m_data;
    }
    //=============================================================================
    void
    value(logical m)
    {
        m_data = m;
    }
    //=============================================================================
    std::string
    print(const std::string& propertyName)
    {
        std::string v = (m_data == 0) ? "off" : "on";
        return "\t" + propertyName + ":\t" + v;
    }
    //=============================================================================
};
//=============================================================================
} // namespace Nelson
//=============================================================================

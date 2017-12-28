//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
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
#include "MPI_CommHandleObject.hpp"
#include "HandleManager.hpp"
//=============================================================================
namespace Nelson {
    //=============================================================================
    MPI_CommHandleObject::MPI_CommHandleObject(void *_ptr) : HandleGenericObject(std::wstring(MPI_COMM_CATEGORY_STR), _ptr)
    {
    }
    //=============================================================================
    MPI_CommHandleObject::~MPI_CommHandleObject()
    {
    }
    //=============================================================================
    MPI_Comm HandleToMpiComm(ArrayOf A)
    {
        MPI_Comm commReturned = MPI_COMM_NULL;
        if (A.isHandle())
        {
            if (!A.isScalar())
            {
                throw Exception(ERROR_SIZE_SCALAR_EXPECTED);
            }
            nelson_handle *qp = (nelson_handle*)A.getDataPointer();
            if (qp == nullptr)
            {
                throw Exception(_W("MPI_Comm valid handle expected."));
            }
            nelson_handle hl = qp[0];
            HandleGenericObject *hlObj = HandleManager::getInstance()->getPointer(hl);
            if (hlObj == nullptr)
            {
                throw Exception(_W("MPI_Comm valid handle expected."));
            }
            if (hlObj->getCategory() != MPI_COMM_CATEGORY_STR)
            {
                throw Exception(_W("MPI_Comm handle expected."));
            }
            MPI_CommHandleObject *mpicommhandleobj = (MPI_CommHandleObject *)hlObj;
            if (mpicommhandleobj != nullptr)
            {
                MPI_CommObject *obj = (MPI_CommObject *)mpicommhandleobj->getPointer();
                if (obj != nullptr)
                {
                    commReturned = obj->getComm();
                }
                else
                {
                    throw Exception(_W("MPI_Comm valid handle expected."));
                }
            }
            else
            {
                throw Exception(_W("MPI_Comm valid handle expected."));
            }
        }
        else
        {
            throw Exception(_W("MPI_Comm handle expected."));
        }
        return commReturned;
    }
    //=============================================================================
    ArrayOf MpiCommToHandle(MPI_Comm mpicomm)
    {
        return ArrayOf::handleConstructor(new MPI_CommHandleObject(new MPI_CommObject(mpicomm)));
    }
    //=============================================================================
    bool MPICommHandleDelete(ArrayOf A)
    {
        bool res = false;
        if (A.isHandle())
        {
            if (!A.isEmpty())
            {
                Dimensions dims = A.getDimensions();
                nelson_handle *qp = (nelson_handle*)A.getDataPointer();
                for (size_t k = 0; k < dims.getElementCount(); k++)
                {
                    nelson_handle hl = qp[k];
                    HandleGenericObject *hlObj = HandleManager::getInstance()->getPointer(hl);
                    if (hlObj)
                    {
                        if (hlObj->getCategory() != MPI_COMM_CATEGORY_STR)
                        {
                            throw Exception(_W("MPI_Comm handle expected."));
                        }
                        MPI_CommHandleObject *mpicommhandleobj = (MPI_CommHandleObject *)hlObj;
                        if (mpicommhandleobj != nullptr)
                        {
                            MPI_CommObject *obj = (MPI_CommObject *)mpicommhandleobj->getPointer();
                            if (obj != nullptr)
                            {
                                delete obj;
                            }
                        }
                        else
                        {
                            throw Exception(_W("MPI_Comm valid handle expected."));
                        }
                        delete mpicommhandleobj;
                        HandleManager::getInstance()->removeHandle(hl);
                        res = true;
                    }
                }
            }
            else
            {
                throw Exception(_W("MPI_Comm valid handle expected."));
            }
        }
        return res;
    }
    //=============================================================================
    ArrayOf usedMPICommHandleObject()
    {
        ArrayOf res;
        std::vector<nelson_handle> used = HandleManager::getInstance()->getAllHandlesOfCategory(MPI_COMM_CATEGORY_STR);
        size_t nbHandles = used.size();
        if (nbHandles > 0)
        {
            Dimensions dims(1, nbHandles);
            nelson_handle *nh = (nelson_handle*)ArrayOf::allocateArrayOf(NLS_HANDLE, nbHandles);
            for (int k = 0; k < nbHandles; k++)
            {
                nh[k] = used[k];
            }
            res = ArrayOf(NLS_HANDLE, dims, (void *)nh);
        }
        else
        {
            res = ArrayOf::emptyConstructor(Dimensions(0, 0));
            res.promoteType(NLS_HANDLE);
        }
        return res;
    }
    //=============================================================================
}
//=============================================================================
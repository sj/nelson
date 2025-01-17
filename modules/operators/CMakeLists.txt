# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name operators)
set(module_library_name nlsOperators)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../integer/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../api_nelson/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../sparse/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../elementary_mathematics/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${Boost_INCLUDE_DIRS})
# ==============================================================================
file(GLOB OPERATORS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${OPERATORS_SRC})
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsApi_nelson
  nlsError_manager
  nlsCharacters_encoding
  nlsI18n
  nlsTypes
  ${BLAS_LIBRARIES}
  ${LAPACK_LIBRARIES}
  ${LAPACKE_LIBRARIES}
  ${MAC_LAPACKE_LIBRARY}
  ${OpenMP_CXX_LIBRARIES})
# ==============================================================================
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
# ==============================================================================
file(GLOB OPERATORS_BUILTIN
     "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/*.cpp")
# ==============================================================================
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/builtin/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../overload/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../linear_algebra/src/include)
# ==============================================================================
add_library(${module_library_builtin_name} SHARED
            ${OPERATORS_BUILTIN})
# ==============================================================================
target_link_libraries(
  ${module_library_builtin_name}
  ${module_library_name}
  nlsError_manager
  nlsInterpreter
  nlsOverload
  nlsI18n
  nlsLinear_algebra
  nlsTypes)
# ==============================================================================
set_target_properties(
  ${module_library_builtin_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
# ==============================================================================
install(TARGETS ${module_library_name} LIBRARY DESTINATION ${LIBRARY_OUTPUT})
install(TARGETS ${module_library_builtin_name}
        LIBRARY DESTINATION ${LIBRARY_OUTPUT})
install(FILES ${CMAKE_SOURCE_DIR}/modules/${module_name}/etc/startup.m
        DESTINATION ${ROOT_OUTPUT}/modules/${module_name}/etc)
install(FILES ${CMAKE_SOURCE_DIR}/modules/${module_name}/etc/finish.m
        DESTINATION ${ROOT_OUTPUT}/modules/${module_name}/etc)
install(FILES ${CMAKE_SOURCE_DIR}/modules/${module_name}/loader.m
        DESTINATION ${ROOT_OUTPUT}/modules/${module_name})
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/functions
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.m")
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/help
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.qch"
  PATTERN "xml" EXCLUDE
  PATTERN "md" EXCLUDE)
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/tests
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.m")
# ==============================================================================

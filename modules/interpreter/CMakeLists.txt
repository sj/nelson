# ==============================================================================
# Copyright (c) 2016-present Allan CORNET (Nelson)
# ==============================================================================
# This file is part of the Nelson.
# =============================================================================
# LICENCE_BLOCK_BEGIN
# SPDX-License-Identifier: LGPL-3.0-or-later
# LICENCE_BLOCK_END
# ==============================================================================
set(module_name interpreter)
set(module_library_name nlsInterpreter)
set(module_library_builtin_name ${module_library_name}_builtin)
# ==============================================================================
include_directories(
  ${EIGEN3_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/src/grammar
  ${CMAKE_CURRENT_SOURCE_DIR}/../nelson_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../types/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../error_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../display_format/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../stream_manager/src/fmt/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../files_folders_functions/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../operators/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../engine/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../mex/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_link/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../os_functions/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../profiler/src/include)
# ==============================================================================
file(GLOB INTERPRETER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/grammar/*.cpp")
# ==============================================================================
add_library(${module_library_name} SHARED ${INTERPRETER_SRC})
# ==============================================================================
target_link_libraries(
  ${module_library_name}
  nlsCharacters_encoding
  nlsNelson_manager
  nlsOperators
  nlsError_manager
  nlsStream_manager
  nlsDisplay_format
  nlsTypes
  nlsI18n
  nlsOs_functions
  nlsProfiler
  ${BOOST_LIBRARIES})
# ==============================================================================
set_target_properties(
  ${module_library_name}
  PROPERTIES
    VERSION
    ${Nelson_VERSION_MAJOR}.${Nelson_VERSION_MINOR}.${Nelson_VERSION_MAINTENANCE}
    SOVERSION ${Nelson_VERSION_MAJOR})
# ==============================================================================
file(GLOB INTERPRETER_BUILTIN "${CMAKE_CURRENT_SOURCE_DIR}/builtin/cpp/*.cpp")
# ==============================================================================
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/builtin/include
  ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../interpreter/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../overload/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../characters_encoding/src/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../i18n/src/include)
# ==============================================================================
add_library(${module_library_builtin_name} SHARED ${INTERPRETER_BUILTIN})
# ==============================================================================
target_link_libraries(${module_library_builtin_name} ${module_library_name}
                      nlsError_manager nlsTypes nlsCharacters_encoding nlsI18n)
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
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/src/include
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}/src
  FILES_MATCHING
  PATTERN "*.h")
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/src/include
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}/src
  FILES_MATCHING
  PATTERN "*.hpp")
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/tests
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.m")
install(
  DIRECTORY ${CMAKE_SOURCE_DIR}/modules/${module_name}/tests
  DESTINATION ${ROOT_OUTPUT}/modules/${module_name}
  FILES_MATCHING
  PATTERN "*.m")
# ==============================================================================

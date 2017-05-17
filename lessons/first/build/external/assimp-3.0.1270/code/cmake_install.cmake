# Install script for directory: /home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1270-OGLtuts" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/farm/Documents/CG/lessons/first/build/external/assimp-3.0.1270/code/libassimp.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/assimp/anim.h;/assimp/ai_assert.h;/assimp/camera.h;/assimp/color4.h;/assimp/color4.inl;/assimp/config.h;/assimp/defs.h;/assimp/cfileio.h;/assimp/light.h;/assimp/material.h;/assimp/material.inl;/assimp/matrix3x3.h;/assimp/matrix3x3.inl;/assimp/matrix4x4.h;/assimp/matrix4x4.inl;/assimp/mesh.h;/assimp/postprocess.h;/assimp/quaternion.h;/assimp/quaternion.inl;/assimp/scene.h;/assimp/texture.h;/assimp/types.h;/assimp/vector2.h;/assimp/vector2.inl;/assimp/vector3.h;/assimp/vector3.inl;/assimp/version.h;/assimp/cimport.h;/assimp/importerdesc.h;/assimp/Importer.hpp;/assimp/DefaultLogger.hpp;/assimp/ProgressHandler.hpp;/assimp/IOStream.hpp;/assimp/IOSystem.hpp;/assimp/Logger.hpp;/assimp/LogStream.hpp;/assimp/NullLogger.hpp;/assimp/cexport.h;/assimp/Exporter.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/assimp" TYPE FILE FILES
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/anim.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/ai_assert.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/camera.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/color4.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/color4.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/config.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/defs.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/cfileio.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/light.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/material.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/material.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/matrix3x3.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/matrix3x3.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/matrix4x4.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/matrix4x4.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/mesh.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/postprocess.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/quaternion.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/quaternion.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/scene.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/texture.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/types.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/vector2.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/vector2.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/vector3.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/vector3.inl"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/version.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/cimport.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/importerdesc.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/Importer.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/DefaultLogger.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/ProgressHandler.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/IOStream.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/IOSystem.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/Logger.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/LogStream.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/NullLogger.hpp"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/cexport.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/Exporter.hpp"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/assimp/Compiler/pushpack1.h;/assimp/Compiler/poppack1.h;/assimp/Compiler/pstdint.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/assimp/Compiler" TYPE FILE FILES
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/Compiler/pushpack1.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/../include/assimp/Compiler/poppack1.h"
    "/home/farm/Documents/CG/lessons/first/external/assimp-3.0.1270/code/pstdint.h"
    )
endif()

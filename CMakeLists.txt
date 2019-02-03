cmake_minimum_required(VERSION 3.5)
project(libcmaketherightway VERSION 1.0.0 LANGUAGES CXX)

##############################################
# Create target and set properties

add_library(cmaketherightway
    src/simple.cpp
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(cmaketherightway::cmaketherightway ALIAS cmaketherightway)

#Set target properties
target_include_directories(cmaketherightway
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

##############################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/cmaketherightway)

install(TARGETS cmaketherightway
    EXPORT cmaketherightway-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT cmaketherightway-targets
  FILE
    cmaketherightwayTargets.cmake
  NAMESPACE
    cmaketherightway::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cmaketherightwayConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/cmaketherightwayConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmaketherightwayConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cmaketherightwayConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cmaketherightwayConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
## Exporting from the build tree

export(EXPORT cmaketherightway-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/cmaketherightwayTargets.cmake NAMESPACE cmaketherightway::)

#Register package in user's package registry
export(PACKAGE cmaketherightway)

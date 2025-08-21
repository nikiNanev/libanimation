cmake_minimum_required(VERSION 3.9)
project(animation VERSION 0.0.1 DESCRIPTION "animation library for integrating inside many types of projects")
include(GNUInstallDirs)
add_library(${PROJECT_NAME} SHARED ../src/test.c)
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ../include/test.h)
configure_file(libanimation.pc.in libanimation.pc @ONLY)
target_include_directories(${PROJECT_NAME} PRIVATE .)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/libanimation.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

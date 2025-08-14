cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

project(t_anim)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

#Directories for the testing
file(GLOB_RECURSE SOURCE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/include/*")

set(INCLUDES "")
set(SOURCES "")

foreach(ITEM ${SOURCE_DIRS})
    if(NOT IS_DIRECTORY ${ITEM})
        list(APPEND SOURCES ${ITEM})
    endif()
endforeach()

foreach(ITEM ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${ITEM})
        list(APPEND INCLUDES ${ITEM})
    endif()
endforeach()



list(APPEND INCLUDES "${CMAKE_SOURCE_DIR}/include/")

message(STATUS "Sources found: ${SOURCES}")
message(STATUS "Include directories found: ${INCLUDES}")

#Directories of the project, that are going to be tested
file(GLOB_RECURSE SOURCE_MATH_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/../src/math/*")
file(GLOB_RECURSE INCLUDE_MATH_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/../include/math/*")

set(MATH_INCLUDES "")
set(MATH_SOURCES "")

foreach(ITEM ${SOURCE_MATH_DIRS})
	if(NOT IS_DIRECTORY ${ITEM})
		list(APPEND MATH_SOURCES ${ITEM})	
	endif()
endforeach()

foreach(ITEM ${INCLUDE_MATH_DIRS})
	if(IS_DIRECTORY ${ITEM})
		list(APPEND MATH_INCLUDES {$ITEM})
	endif()
endforeach()

message(STATUS "Math sources found: ${MATH_SOURCES}")
message(STATUS "Math includes found: ${MATH_INCLUDES}")

add_executable(${PROJECT_NAME} ${SOURCES} ${MATH_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

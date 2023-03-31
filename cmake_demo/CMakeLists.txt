cmake_minimum_required(VERSION 3.5)

project(hello)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES hello.cpp greeting.cpp helper.cpp)
set(HEADERS greeting.hpp helper.hpp)

# Check if the library archive exists
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/libmylib.a)
  set(USE_PRECOMPILED_LIBRARY ON)
else()
  set(USE_PRECOMPILED_LIBRARY OFF)
endif()

# Add library target
if (USE_PRECOMPILED_LIBRARY)
  add_library(mylib STATIC IMPORTED)
  set_target_properties(mylib PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libmylib.a)
else()
  add_library(mylib STATIC greeting.cpp helper.cpp)
endif()

# Add executable target
add_executable(hello ${SOURCES} ${HEADERS})

# Link with library
target_link_libraries(hello PRIVATE mylib)

# VVVVV Specify installation rules here VVVVV
project(ubx)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fno-strict-aliasing -pedantic -Wextra -fPIC")

include(CTest)

find_program(
  CLANG_FORMAT 
  clang-format NAMES clang-format-3.6 clang-format-3.7)

if (CLANG_FORMAT)
  file(GLOB_RECURSE SRCS include/*.h tests/*.h tests/*.cpp src/*.h src/*.cpp )
  add_custom_target(clang-format ${CLANG_FORMAT} -style=file -i ${SRCS} VERBATIM)
endif()

find_package(Boost COMPONENTS filesystem system)

include_directories(include src)

file(GLOB_RECURSE UBX_PUBLIC_INCLUDES include/*.h tests/*.h)

add_library(
  ubx

  ${UBX_PUBLIC_INCLUDES}

  src/ubx/_8/receiver.cpp
  src/ubx/_8/replaying_receiver.cpp
  src/ubx/_8/serial_port_receiver.cpp
  src/ubx/_8/nmea/scanner.cpp
  src/ubx/_8/nmea/sentence.cpp)

target_link_libraries(ubx ${Boost_LIBRARIES})

add_executable(
  ubx_serial_port_receiver

  examples/ubx_serial_port_receiver.cpp)

target_link_libraries(ubx_serial_port_receiver ubx)

############################
## Test setup starts here ##
############################

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/config.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/tests/config.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)

# Build with system gmock and embedded gtest
set (GMOCK_INCLUDE_DIR "/usr/include/gmock/include" CACHE PATH "gmock source include directory")
set (GMOCK_SOURCE_DIR "/usr/src/gmock" CACHE PATH "gmock source directory")
set (GTEST_INCLUDE_DIR "${GMOCK_SOURCE_DIR}/gtest/include" CACHE PATH "gtest source include directory")

include_directories(${GTEST_INCLUDE_DIR})
add_subdirectory(${GMOCK_SOURCE_DIR} "${CMAKE_CURRENT_BINARY_DIR}/gmock")

add_library(
  ubx_tests_config

  ${CMAKE_CURRENT_BINARY_DIR}/tests/config.cpp)

add_executable(
  receiver_test

  tests/receiver_tests.cpp)

target_link_libraries(
  receiver_test

  ubx ubx_tests_config

  gmock gtest gtest_main)

add_executable(
  scanner_test

  tests/scanner_tests.cpp)

target_link_libraries(
  scanner_test

  ubx ubx_tests_config

  gmock gtest gtest_main)

add_test(receiver_test receiver_test)
add_test(scanner_test scanner_test)

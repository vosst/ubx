project(ubx)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -Wall -pedantic -Wextra -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall -fno-strict-aliasing -pedantic -Wextra -fPIC")

find_package(Boost COMPONENTS filesystem system)

include_directories(include src)

file(GLOB_RECURSE UBX_PUBLIC_INCLUDES include/*.h)

add_library(
  ubx

  ${UBX_PUBLIC_INCLUDES}

  src/ubx/_8/receiver.cpp
  src/ubx/_8/nmea/scanner.cpp)

target_link_libraries(ubx ${Boost_LIBRARIES})

add_executable(
  ubx_receiver

  main.cpp)

target_link_libraries(ubx_receiver ubx)

project(ubx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost COMPONENTS system)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
  ubx

  main.cpp

  ubx/_8/nmea/cardinal_direction.h
  ubx/_8/nmea/date.h
  ubx/_8/nmea/latitude.h
  ubx/_8/nmea/longitude.h
  ubx/_8/nmea/mode.h
  ubx/_8/nmea/scanner.h
  ubx/_8/nmea/status.h
  ubx/_8/nmea/talker.h
  ubx/_8/nmea/utc.h

  ubx/_8/receiver.cpp
  ubx/_8/nmea/scanner.cpp)

target_link_libraries(ubx ${Boost_LIBRARIES})
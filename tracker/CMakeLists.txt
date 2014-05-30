include_directories(${YARP_INCLUDE_DIRS})
					
find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(headTracker headTracker.cpp Tracker.cpp Tracker.h)
target_link_libraries(headTracker ${YARP_LIBRARIES})

install(TARGETS headTracker RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)




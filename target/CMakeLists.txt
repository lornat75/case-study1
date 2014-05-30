
find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})
					
add_executable(target objectDetector.cpp Detector.cpp Detector.h)
target_link_libraries(target ${YARP_LIBRARIES})

install(TARGETS target RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)




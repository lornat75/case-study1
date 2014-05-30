
find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})
					
add_executable(objectDetector objectDetector.cpp Detector.cpp Detector.h)
target_link_libraries(objectDetector ${YARP_LIBRARIES})

install(TARGETS objectDetector RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)




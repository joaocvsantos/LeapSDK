
set(LeapSDK_FOUND TRUE)

add_library(Leap::Leap SHARED IMPORTED GLOBAL)
set_target_properties(Leap::Leap PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/../libLeap.so)
set_target_properties(Leap::Leap PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/../../include )

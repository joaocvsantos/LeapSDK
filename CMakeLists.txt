cmake_minimum_required(VERSION 3.16)
project(LeapSDK)

add_library(Leap SHARED IMPORTED GLOBAL)
set_target_properties(Leap PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/x64/libLeap.so)
set_target_properties(Leap PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include )
set_target_properties(Leap PROPERTIES PUBLIC_HEADER Leap.h)
set_target_properties(Leap PROPERTIES PUBLIC_HEADER LeapMath.h)

include(GNUInstallDirs)
install(FILES ${CMAKE_SOURCE_DIR}/include/Leap.h ${CMAKE_SOURCE_DIR}/include/LeapMath.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${CMAKE_SOURCE_DIR}/lib/x64/libLeap.so
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${CMAKE_SOURCE_DIR}/share/LeapSDKConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)

add_executable(MyApp ${CMAKE_SOURCE_DIR}/samples/MyApp.cpp)
target_link_libraries(MyApp PUBLIC Leap)

#add executable
set(SOURCES main.c)
add_executable(Lista ${SOURCES})
target_link_libraries(Lista libs)
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../libs/")
#target_link_libraries(Lista ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/libLista.so)
#target_link_libraries(Lista "${CMAKE_CURRENT_SOURCE_DIR}/libs/")
#target_link_libraries(Lista "${CMAKE_CURRENT_SOURCE_DIR}/libs")
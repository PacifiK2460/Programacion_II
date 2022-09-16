#add executable
set(SOURCES main.c)
set(LIBS io llist sstring)
FOREACH(lib ${LIBS})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../libs/${lib}" "${CMAKE_CURRENT_BINARY_DIR}/${lib}")
ENDFOREACH()
add_executable(Lista ${SOURCES})
target_link_libraries(Lista ${LIBS})
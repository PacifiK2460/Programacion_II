#add executable
set(SOURCES main.c)
set(LIBS llist io sstring)
FOREACH(lib ${LIBS})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../libs/${lib}" "${CMAKE_CURRENT_BINARY_DIR}/${lib}")
ENDFOREACH()
add_executable("20-09-22" ${SOURCES})
target_link_libraries("20-09-22" ${LIBS})
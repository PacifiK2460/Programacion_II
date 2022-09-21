cmake_minimum_required(VERSION 3.8)
project("Programacion II")

set(LIBS io sstring llist)
foreach(lib ${LIBS})
    include_directories("${CMAKE_SOURCE_DIR}/libs/${lib}/")
    link_libraries("${CMAKE_SOURCE_DIR}/libs/${lib}/${lib}.c")
endforeach()


# add_subdirectory("${CMAKE_SOURCE_DIR}/libs/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Sesiones/Lista")
add_subdirectory("${CMAKE_SOURCE_DIR}/Laboratorio/20-09-22")

cmake_minimum_required(VERSION 3.8)
project("Programacion II")

set(LIBS io sstring llist)
foreach(lib ${LIBS})
    include_directories("${CMAKE_SOURCE_DIR}/libs/${lib}/")
    link_libraries("${CMAKE_SOURCE_DIR}/libs/${lib}/${lib}.c")
endforeach()

include_directories("${CMAKE_SOURCE_DIR}/libs/proyecto/")
set(LIBS auth routes)
foreach(lib ${LIBS})
    link_libraries("${CMAKE_SOURCE_DIR}/libs/proyecto/${lib}.c")
endforeach()


# add_subdirectory("${CMAKE_SOURCE_DIR}/libs/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Proyecto/")
add_subdirectory("${CMAKE_SOURCE_DIR}/Sesiones/Lista")
add_subdirectory("${CMAKE_SOURCE_DIR}/Sesiones/ListaSimple")
add_subdirectory("${CMAKE_SOURCE_DIR}/Sesiones/ListaBiDireccional")
add_subdirectory("${CMAKE_SOURCE_DIR}/Laboratorio/20-09-22")

add_library(io OBJECT "io.h" "io.c")
target_include_directories(io PUBLIC ${CMAKE_CURRENT_LIST_DIR})
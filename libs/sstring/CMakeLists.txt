add_library(string OBJECT "sstring.h" "sstring.c")
target_include_directories(string PUBLIC ${CMAKE_CURRENT_LIST_DIR})
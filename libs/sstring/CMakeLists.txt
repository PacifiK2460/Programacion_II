add_library(sstring OBJECT "sstring.h" "sstring.c")
target_include_directories(sstring PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_library(llist OBJECT "llist.h" "llist.c")
target_include_directories(llist PUBLIC ${CMAKE_CURRENT_LIST_DIR})
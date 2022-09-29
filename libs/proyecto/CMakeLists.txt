add_library(project auth.c routes.c)
target_compile_definitions(project PUBLIC PROJECT)
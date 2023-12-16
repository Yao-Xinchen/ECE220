set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/mp8)

add_executable(mp8 mp8.c imageData.c lodepng.c main.c mp8recurse.c)
target_link_libraries(mp8 png)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/mp5)

add_executable(mp5 main.c mp5.c)
target_link_libraries(mp5 png)
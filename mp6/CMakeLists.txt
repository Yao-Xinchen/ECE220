set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/mp6)

add_executable(mp6 main.c mp6.c)
target_link_libraries(mp6 png m)
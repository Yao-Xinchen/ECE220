cmake_minimum_required(VERSION 3.22)
project(ECE220)

set(CMAKE_CXX_STANDARD 17)

set(SUBDIRS mp4 mp5 mp6 mp7 mp8 mp9 mp10 mp11)

foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()
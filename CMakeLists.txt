cmake_minimum_required(VERSION 3.12)
project(Lab12 C)

set(CMAKE_C_STANDARD 11)

include_directories(utils)

add_executable(Lab12
        utils/utils.c
        utils/utils.h
		utils/fileUtils.c
        utils/fileUtils.h
        cscd240Lab12.c
		lab12.c
		lab12.h)

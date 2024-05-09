cmake_minimum_required(VERSION 3.26)

project(
	PhaserProject
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
	${SFML_LIB_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.5.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

#set(PHASER_ENGINE_TARGET_NAME PhaserEngine)
set(PHASER_GAME_TARGET_NAME PhaserGame)

#add_subdirectory(PhaserEngine)
add_subdirectory(PhaserGame)
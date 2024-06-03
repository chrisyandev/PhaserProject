cmake_minimum_required(VERSION 3.26)

project(
	ProjectPhaser
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PHASER_ENGINE_TARGET_NAME PhaserEngine)
set(PHASER_GAME_TARGET_NAME PhaserGame)

add_subdirectory(PhaserEngine)
add_subdirectory(PhaserGame)
add_executable(
	${PHASER_GAME_TARGET_NAME}

	${CMAKE_CURRENT_SOURCE_DIR}/Include/GameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/GameFramework/GameApplication.cpp
)

target_include_directories(
	${PHASER_GAME_TARGET_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(${PHASER_GAME_TARGET_NAME} PUBLIC ${PHASER_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_DIR_NAME TARGET_NAME)
	add_custom_command (
		TARGET ${TARGET_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory $<TARGET_FILE_DIR:${LIB_DIR_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(${PHASER_ENGINE_TARGET_NAME} ${PHASER_GAME_TARGET_NAME})
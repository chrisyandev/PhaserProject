add_executable(
	${PHASER_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${PHASER_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${PHASER_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${PHASER_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${PHASER_GAME_TARGET_NAME} PUBLIC sfml-audio)

add_custom_command (
	TARGET ${PHASER_GAME_TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-graphics> $<TARGET_FILE_DIR:${PHASER_GAME_TARGET_NAME}>
)

add_custom_command (
	TARGET ${PHASER_GAME_TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-window> $<TARGET_FILE_DIR:${PHASER_GAME_TARGET_NAME}>
)

add_custom_command (
	TARGET ${PHASER_GAME_TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-system> $<TARGET_FILE_DIR:${PHASER_GAME_TARGET_NAME}>
)

add_custom_command (
	TARGET ${PHASER_GAME_TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:sfml-audio> $<TARGET_FILE_DIR:${PHASER_GAME_TARGET_NAME}>
)
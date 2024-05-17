add_executable(
	${PHASER_GAME_TARGET_NAME}

	${CMAKE_CURRENT_SOURCE_DIR}/Include/GameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/GameFramework/GameApplication.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Spaceship/Spaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Spaceship/Spaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Player/PlayerSpaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Player/PlayerSpaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Weapon/Shooter.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Weapon/Shooter.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Weapon/BulletShooter.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Weapon/BulletShooter.cpp
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

set(RESOURCE_DIR_NAME Assets)
set(RESOURCE_DIR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_DIR_NAME})

add_custom_command(
	TARGET ${PHASER_GAME_TARGET_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCE_DIR_PATH} $<TARGET_FILE_DIR:${PHASER_GAME_TARGET_NAME}>/${RESOURCE_DIR_NAME}
)

configure_file(
	Config.h.in
	${CMAKE_CURRENT_SOURCE_DIR}/Include/Config.h ESCAPE_QUOTES
)

add_library(
	${PHASER_ENGINE_TARGET_NAME} STATIC

	${CMAKE_CURRENT_SOURCE_DIR}/Include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/EntryPoint.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/Core.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/Core.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/AssetManager.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/AssetManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/Object.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/Object.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/World.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/World.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Include/Framework/Actor.h
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Framework/Actor.cpp
)

target_include_directories(
	${PHASER_ENGINE_TARGET_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(${PHASER_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${PHASER_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${PHASER_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${PHASER_ENGINE_TARGET_NAME} PUBLIC sfml-audio)

function(CopyLibFileToTarget LIB_FILE_NAME TARGET_NAME)
	add_custom_command (
		TARGET ${TARGET_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${LIB_FILE_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibFileToTarget(sfml-graphics ${PHASER_ENGINE_TARGET_NAME})
CopyLibFileToTarget(sfml-window ${PHASER_ENGINE_TARGET_NAME})
CopyLibFileToTarget(sfml-system ${PHASER_ENGINE_TARGET_NAME})
CopyLibFileToTarget(sfml-audio ${PHASER_ENGINE_TARGET_NAME})
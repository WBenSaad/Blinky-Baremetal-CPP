cmake_minimum_required(VERSION 3.15.3)

project(LED)
enable_language(C ASM CXX )


set(CMAKE_C_STANDARD 99 )
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(MCU_MODEL STM32f10X)
set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/App)

set(DEVICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Device)

#HEADERS
set(APP_INCLUDE_DIRECTORIES ${APP_DIR}/Inc	)
set(CORE_INCLUDE_DIRECTORIES ${DEVICE_DIR}/Inc	)

#Sources
set(APP_SRCS_DIRECTORIES ${APP_DIR}/Src			)
set(CORE_SRCS_DIRECTORIES ${DEVICE_DIR}/Src		)

#Startup Script
set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/startup_stm32f10x_md.s	)	
#Linker Script
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/stm32f10x.ld	)

file(GLOB_RECURSE PROJECT_SRCS FOLLOW_SYMLINKS

	${APP_SRCS_DIRECTORIES}/*.cpp
	${CORE_SRCS_DIRECTORIES}/*.cpp	
	${CORE_SRCS_DIRECTORIES}/*.c	)
	




set(EXECUTABLE ${PROJECT_NAME}.out)

add_executable( ${EXECUTABLE} 
	        ${PROJECT_SRCS}
	        ${STARTUP_SCRIPT}	)

target_compile_definitions(${EXECUTABLE} PRIVATE
		-DSTM32F103xB
        )

target_include_directories(${EXECUTABLE} PRIVATE
		${APP_INCLUDE_DIRECTORIES}
		${CORE_INCLUDE_DIRECTORIES}
		)

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m3
        -mthumb
        -fdata-sections
        -ffunction-sections
        -Wall
        $<$<CONFIG:Debug>:-Og>
        )

target_link_options(${EXECUTABLE} PRIVATE
        -T${LINKER_SCRIPT}
        -mcpu=cortex-m3
        -mthumb
        -lc
        -specs=nano.specs
		--specs=nosys.specs
		-lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        )

# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)
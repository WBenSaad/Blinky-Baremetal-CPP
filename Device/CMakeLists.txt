cmake_minimum_required(VERSION 3.15.3)

project(LED LANGUAGES CXX C ASM))

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/App)

set(DEVICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Device)

#HEADERS
set(APP_INCLUDE_DIRECTORIES ${APP_DIR}/Inc	)
set(CORE_INC_DIRECTORIES ${DEVICE_DIR}/Inc	)

#Sources
set(APP_SRCS_DIRECTORIES ${APP_DIR}/Src			)
set(CORE_SRCS_DIRECTORIES ${DEVICE_DIR}/Device/Src		)

#Startup Script
set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/startup_stm32f10x_md.s	)	
#Linker Script
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/stm32f10x.ld	)

set(STM32CUBEMX_GENERATED_FILE

        Inc/LED.h
		Inc/reg.h
		Inc/Serial.h
        Inc/stm32f1xx_it.h
		Device/stm32f1xx.h
		Device/system_stm32f1xx.h

        Src/main.cpp
		Src/LED.cpp
        Device/system_stm32f10x.c
		startup_stm32f10x_md.s
        )



set(EXECUTABLE ${PROJECT_NAME}.out)

add_executable(${EXECUTABLE} ${STM32CUBEMX_GENERATED_FILES}
	    Src/LED.cpp
		Src/main.cpp)

target_compile_definitions(${EXECUTABLE} PRIVATE
		-DSTM32F103xB
        )

target_include_directories(${EXECUTABLE} PRIVATE
		Inc
		Device/Inc
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
        -T${CMAKE_SOURCE_DIR}/stm32f10x.ld
        -mcpu=cortex-m3
        -mthumb
        -specs=nano.specs
		-fno-exceptions
        -lc
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
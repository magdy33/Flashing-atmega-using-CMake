cmake_minimum_required(VERSION 3.30)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C   compiler" FORCE)
set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr-objcopy" FORCE)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmcu=atmega32 -O1 -DF_CPU=1000000UL")

project(LEDLink CXX)

# Include directories
include_directories("c:/winavr-20100110/avr/include")

# Source files
file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)
string(REGEX REPLACE "build/[^;]+;?" "" SRCS "${SRCS}")

add_executable(${PROJECT_NAME}.elf ${SRCS})

# Custom target to generate hex file
add_custom_target(flash ALL 
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)

# Custom target to burn hex file
add_custom_target(burn 
    DEPENDS flash 
    COMMAND avrdude.exe -c usbasp -p m32 -B 0.5 -U flash:w:${PROJECT_NAME}.hex:a
)

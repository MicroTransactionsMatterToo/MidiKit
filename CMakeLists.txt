cmake_minimum_required(VERSION 3.6)
project(midikit)

set (CMAKE_CXX_STANDARD 11)

#########
# Tests #
#########

set (GTEST_ROOT "${CMAKE_SOURCE_DIR}/gtest/googletest")

############
# Includes #
############

include_directories(
        /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino
        ${CMAKE_SOURCE_DIR}/src
        /usr/local/include/avr-libc
        ${GTEST_ROOT}/include
)



################
# Source Files #
################



##############
# Executable #
##############



set (
        SOURCES
        src/common/midikit.cpp
        src/types/messages.cpp
        tests/test_test.cpp)

set (
        HEADERS
        src/types/messages.h
        src/common/midikit.h
)


add_executable(midikit ${SOURCES} ${HEADERS})

########
# Libs #
########

target_link_libraries(midikit ${CMAKE_SOURCE_DIR}/gtest/googletest/libgtest.a)
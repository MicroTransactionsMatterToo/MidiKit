cmake_minimum_required(VERSION 3.6)
project(midikit)

############
# Includes #
############

include_directories(
        /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino
        ${CMAKE_SOURCE_DIR}/src
        /usr/local/include/avr-libc
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
)

set (
        HEADERS
        src/types/messages.h
        src/common/midikit.h
)


add_executable(midikit ${SOURCES} ${HEADERS})
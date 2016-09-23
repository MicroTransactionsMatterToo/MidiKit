//
// Created by Ennis Massey on 21/09/16.
//

#ifndef SRC_TYPES_MESSAGES_H_
#define SRC_TYPES_MESSAGES_H_

// STD Includes
#include <cassert>
// Includes
#include "common/midikit.h"

// Type Defs
typedef uint8_t MidiByte;  /*!< A MidiByte, the same as a normal byte, e.g. 8 bits. */

//! Used to store the data of a MIDI Message
/*!
 * This typedef is here mostly for ease-of-use, but also to prevent users from
 * passing more than 2 bytes in a MIDI message, as a MIDI message with more than this
 * is invalid, and ignored
 */
typedef std::array<uint8_t, 2> MidiByteArray;

// Structs

namespace nm {
    struct NoteMessage {
        uint8_t Note;
        uint8_t Velocity;
    };
}

// MIDI Message BitMasks
//! MIDI Voice Valid Message
/*!
 * Holds the nibble values of all valid MIDI voice messages
 * @note A full status byte consists of one of the values below, and a 4bit value representing the channel to use
 */
enum StatusByteValues {
    NoteOn = 0b1000,  /*!< A Note-On Message */
    NoteOff = 0b1001,  /*!< A Note-Off Message */
    PolyPressure = 0b1010,  /*!< KeyPressure message */
    ControlChange = 0b1011,  /*!< Control Change message */
    ProgramChange = 0b1100,  /*!< Program Change message */
    ChannelPressure = 0b1101,  /*!< Channel Pressure message */
    PitchBend = 0b1110  /*!< PitchBend message */
};

//! Bitmasks used to extract data from MIDI messages
/*!
 * @note Due to the variable nature of MIDI message sizes,
 * @note these masks assume that messages have been appropriately shifted
 */
enum MIDIBitMasks {
    MessageType = 0xF0, /*!< The message type */
    MessageChannel = 0x0F  /*!< The message channel @note:
                            * Only applies to Voice Messages
                            */
};


// MidiMessage Class
//! Contains all data expressed within a MIDI Message
class MidiMessage {
    MidiByte status_;
    MidiByteArray data_;

 public:
    MidiMessage(MidiByte status, MidiByteArray data);
};

//! Abstract Base Class for MIDI Voice Messages
/*!
 * Provides a base set of needed functions for any Voice Message
 */
struct VoiceMessage {
 public:
    virtual char const* getType() = 0;
    virtual nm::NoteMessage getData() = 0;
    virtual uint8_t getTypeRaw() = 0;
};


class NoteMessage : VoiceMessage {
    unsigned int type_ : 4;
    MidiByteArray data_;

 public:
    // Constructor
    NoteMessage(int noteType, MidiByteArray data);

    char const* getType();
    nm::NoteMessage getData();
    uint8_t getTypeRaw();
};

#endif  // SRC_TYPES_MESSAGES_H_

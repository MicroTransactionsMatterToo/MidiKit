//
// Created by Ennis Massey on 21/09/16.
//

#include "types/messages.h"


/*********************
 * MidiMessage Class *
 *********************/

//! Constructs a new `MidiMessage`
/*!
 *
 *
 * @param status
 * @param data
 * @return
 */
MidiMessage::MidiMessage(MidiByte status, MidiByteArray data) {
    // Check that the Array is not empty
    assert(!data.empty());
    // Check the values are valid
    for (uint8_t value : data) {
        assert(value >= 0x00 && value <= 0x7F);
    }
    assert(status >= 0x80 && status <= 0xFF);
}

/**********************
 * NoteMessage Class *
 **********************/

//! Constructs a new `NoteMessage`

NoteMessage::NoteMessage(int noteType, MidiByteArray data) {
    assert(noteType == 0 || noteType == 1);
    assert(!data.empty());
    switch (noteType) {
        case 0:
            type_ = 0b1000;
        case 1:
            type_ = 0b1001;
        default:
            assert(false);
    }
}

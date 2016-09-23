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
    data_ = data;
    switch (noteType) {
        case 0:
            type_ = 0b1000;
        case 1:
            type_ = 0b1001;
    }
}

char const* NoteMessage::getType() {
    switch (type_) {
        case 0b1000:
            return "Note-Off";
        case 0b1001:
            return "Note-On";
        default:
            assert(false);
    }
}

nm::NoteMessage NoteMessage::getData() {
    uint8_t noteNum;
    uint8_t noteVel;

    noteNum = (uint8_t) (data_[0] & 0b01111111);
    std::cout << noteNum;
    noteVel = (uint8_t) (data_[1] & 0b01111111);
    std::cout << noteVel;

    nm::NoteMessage rval;
    rval.Note = noteNum;
    rval.Velocity = noteVel;

    return rval;
}


uint8_t NoteMessage::getTypeRaw() {
    return (uint8_t) type_;
}

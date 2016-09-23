//
// Created by Ennis Massey on 21/09/16.
//

#include "common/midikit.h"


int main() {

    NoteMessage test = NoteMessage(0, MidiByteArray{0x40, 0x39});
    MidiByte note = test.getData().Note;
    MidiByte veloc = test.getData().Velocity;

    nm::NoteMessage yok = test.getData();
    std::cout << test.getType() << std::endl;
    printf("%d\n", yok.Note);
    printf("%d\n", yok.Velocity);
    return 0;
}



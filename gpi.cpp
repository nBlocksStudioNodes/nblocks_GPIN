#include "gpin.h"

/// GPIN
nBlock_GPIN::nBlock_GPIN(PinName pinIn, PinMode modeString)): _in(pinIn) {
    output[0] = _in;
    _in.mode(modeString); //set mode as PullUp/PullDown/PullNone/OpenDrain
    available[0] = 1; // We start by firing the initial state
    return;
}

void nBlock_GPIN::endFrame(void) {
    // Rising edge
    if ((old_in == 0) && (_in != 0)) {
        available[0] = 1;
        available[1] = 1;
        available[2] = 0;
        output[0] = _in;
        output[1] = _in;
    }
    // Falling edge
    else if ((old_in == 1) && (_in == 0)) {
        available[0] = 1;
        available[1] = 0;
        available[2] = 1;
        output[0] = _in;
        output[2] = _in;
    }
    // No edge, no new data
    else {
        available[0] = 0;
        available[1] = 0;
        available[2] = 0;
    }
    old_in = _in;
    return;
}

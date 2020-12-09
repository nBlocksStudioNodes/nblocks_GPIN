#ifndef __NB_GPIN
#define __NB_GPIN

#include "mbed.h"
#include "nworkbench.h"

class nBlock_GPIN: public nBlockSimpleNode<3> {
public:
    nBlock_GPIN(PinName pinIn, PinMode  modeString);
    void endFrame(void);
private:
    DigitalIn _in;
    uint32_t old_in;
    PinMode  _mode;
};


#endif

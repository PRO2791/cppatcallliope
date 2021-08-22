#define _GNU_SOURCE

#include "MicroBit.h"
#include "NEPODefs.h"
#include <list>
#include <array>
#include <stdlib.h>
MicroBit _uBit;



int main()
{
    _uBit.init();
    
    while ( true ) {
        _uBit.display.print(MicroBitImage("0,0,0,0,0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n"));
        while (true) {
            if ( round(_uBit.display.readLightLevel() * _GET_LIGHTLEVEL_MULTIPLIER) >= 150 ) {
                break;
            }
            _uBit.sleep(_ITERATION_SLEEP_TIMEOUT);
        }
        _uBit.display.print(MicroBitImage("0,0,0,0,0\n0,255,0,255,0\n0,0,0,0,0\n0,255,255,255,0\n255,0,0,0,255\n"));
        while (true) {
            if ( round(_uBit.display.readLightLevel() * _GET_LIGHTLEVEL_MULTIPLIER) < 150 ) {
                break;
            }
            _uBit.sleep(_ITERATION_SLEEP_TIMEOUT);
        }
        _uBit.sleep(_ITERATION_SLEEP_TIMEOUT);
    }
    release_fiber();
}

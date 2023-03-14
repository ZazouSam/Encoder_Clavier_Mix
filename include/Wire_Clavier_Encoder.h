#include "Wire_Clavier.h"
#include "Wire_encoder.h"

void requestEvent()
{
    requestEventC();    //1 byte
    requestEventE();    //7 bytes
}
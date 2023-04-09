#include "Wire_Clavier.h"
#include "Wire_encoder.h"

void requestEvent()
{
    requestEventC();    //2 bytes
    requestEventE();    //7 bytes
}
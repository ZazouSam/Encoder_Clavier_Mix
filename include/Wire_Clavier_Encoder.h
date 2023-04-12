#include "Wire_Clavier.h"
#include "Wire_encoder.h"
#include "BMS.h"

void requestEvent()
{
    requestEventC();    //2 bytes
    requestEventE();    //7 bytes
    requestEventBMS();  //2 bytes
}
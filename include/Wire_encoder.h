#include "BigBoyInclude.h"
#include "Encoder_Custom.h"

void requestEventE()
{
    switch (Enc1)
    {
    case 1:
        Wire.write("1+");
        Enc1 = 0;
        break;
    case -1:
        Wire.write("1-");
        Enc1 = 0;
        break;
    default:
        Wire.write("1X");
        break;
    }
    switch (Enc2)
    {
    case 1:
        Wire.write("2+");
        Enc2 = 0;
        break;
    case -1:
        Wire.write("2-");
        Enc2 = 0;
        break;
    default:
        Wire.write("2X");
        break;
    }
    switch (Enc3)
    {
    case 1:
        Wire.write("3+");
        Enc3 = 0;
        break;
    case -1:
        Wire.write("3-");
        Enc3 = 0;
        break;
    default:
        Wire.write("3X");
        break;
    }
    switch (Enc4)
    {
    case 1:
        Wire.write("4+");
        Enc4 = 0;
        break;
    case -1:
        Wire.write("4-");
        Enc4 = 0;
        break;
    default:
        Wire.write("4X");
        break;
    }
    switch (Enc5)
    {
    case 1:
        Wire.write("5+");
        Enc5 = 0;
        break;
    case -1:
        Wire.write("5-");
        Enc5 = 0;
        break;
    default:
        Wire.write("5X");
        break;
    }
    switch (Enc6)
    {
    case 1:
        Wire.write("6+");
        Enc6 = 0;
        break;
    case -1:
        Wire.write("6-");
        Enc6 = 0;
        break;
    default:
        Wire.write("6X");
        break;
    }
    switch (boutonEncoder)
    {
    case 6:
        Wire.write("E6");
        boutonEncoder = 0;
        break;
    case 5:
        Wire.write("E5");
        boutonEncoder = 0;
        break;
    case 4:
        Wire.write("E4");
        boutonEncoder = 0;
        break;
    case 3:
        Wire.write("E3");
        boutonEncoder = 0;
        break;
    case 2:
        Wire.write("E2");
        boutonEncoder = 0;
        break;
    case 1:
        Wire.write("E1");
        boutonEncoder = 0;
        break;
    default:
        Wire.write("XX");
        break;
    }
}
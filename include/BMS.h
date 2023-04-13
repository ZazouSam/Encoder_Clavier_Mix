#include "BigBoyInclude.h"
// PIN SDA1 = PA18 SCL1 = PA17
#define I2C_GROUP_ADDR 0x04
// Register addresses 0x00 - 0x05 are Read / Write.
// Register addresses 0x07 and 0x10 - 0x16 are read only.
#define STATUS 0x00
#define CELL_CTL 0x01
#define BAL_CTL 0x02
#define CONFIG_1 0x03
#define CONFIG_2 0x04
#define POWER_CTL 0x05
#define CHIP_ID 0x07
#define VREF_CAL 0x10
#define VC1_CAL 0x11
#define VC2_CAL 0x12
#define VC3_CAL 0x13
#define VC4_CAL 0x14
#define VC5_CAL 0x15
#define VC6_CAL 0x16
#define VC_CAL_EXT_1 0x17
#define VC_CAL_EXT_2 0x18
#define VREF_CAL_EXT 0x1B

const double Voffset = 0.0275;
const double B_MAX = 16.8;
const double B_MIN = 12.8;
const double Gvcout = 0.6;

char ADDRESS;
float VIOUTsensen;

double GCvc1, GCvc2, GCvc3, GCvc4;
double OCvc1, OCvc2, OCvc3, OCvc4;
double GCref;

int VC1_GC_4, VC2_GC_4, VC3_GC_4, VC4_GC_4;
int VC1_OC_4, VC2_OC_4, VC3_OC_4, VC4_OC_4;
int VREF_GC_4, VREF_OC_4, VREF_OC_5;
int VC1_GAIN_CORR, VC2_GAIN_CORR, VC3_GAIN_CORR, VC4_GAIN_CORR;
int VREF_GAIN_CORR;
int VC1_OFFSET_CORR, VC2_OFFSET_CORR, VC3_OFFSET_CORR, VC4_OFFSET_CORR;
int VREF_OFFSET_CORR;

int test;

double VCOUT;
double Isense;
double Rsense = 0.001;
double VC1, VC2, VC3, VC4;
double Vref;

double VCtotal;
uint32_t adc1, adc2, adc3, adc4, adc5, adc6;
double pourcentage_batterie;
int gain;

int unite, dizaine;
int cell_select = 0;

void setupBMS(void)
{
    // ADC setup pin A0 Temp
    pinMode(A0, INPUT);
    // ADC setup pin A1 Courant
    pinMode(A1, INPUT);
    // ADC setup pin A2 Volt
    pinMode(A2, INPUT);
    analogReadResolution(12); // adc resolution 12 bits
    Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + POWER_CTL);
    Wire1.write(0x5C);
    Wire1.endTransmission();
    delay(10);

    Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CONFIG_1);
    Wire1.write(0x00);
    Wire1.endTransmission();

    delay(10);

    Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CONFIG_2);
    Wire1.write(0x01);
    Wire1.endTransmission();
    delay(10);

    Wire1.requestFrom((I2C_GROUP_ADDR << 3) + CONFIG_1, 1); // request 6 bytes from slave device #8
    while (Wire1.available())
    {                        // slave may send less than requested
        test = Wire1.read(); // receive a byte as character
    }

    delay(500);
    while (test != 0x00)
    {
        Wire1.requestFrom((I2C_GROUP_ADDR << 3) + CONFIG_1, 1); // request 6 bytes from slave device #8
        while (Wire1.available())
        {                        // slave may send less than requested
            test = Wire1.read(); // receive a byte as character
        }
        delay(500);
        Serial.print("test: ");
        Serial.print(test);
        Serial.println("  rip");
    }

    Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CONFIG_1);
    Wire1.write(0x05);
    Wire1.endTransmission();
    delay(10);
}

void BMS(void)
{
    if (cell_select == 1)
    {
        Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
        Wire1.write(0x10);
        Wire1.endTransmission();
    // delay(1);
    adc1 = analogRead(A2);
    }
    
    VCOUT = adc1 * (3.3 / 4096.0) - Voffset;
    VC1 = VCOUT / Gvcout;

    
    // VC1 = ((VCOUT * GCref + OCvc1)/Gvcout)* (1 + GCvc1);
    if (cell_select == 2)
    {
        Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
        Wire1.write(0x11);
        Wire1.endTransmission();
    // delay(1);
    adc2 = analogRead(A2);
    }

    
    VCOUT = adc2 * (3.3 / 4096.0) - Voffset;
    VC2 = VCOUT / Gvcout;
    // VC2 = ((VCOUT * GCref + OCvc2) / Gvcout) * (1 + GCvc2);

    if (cell_select == 3)
    {
        Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
        Wire1.write(0x12);
        Wire1.endTransmission();
    // delay(1);
    adc3 = analogRead(A2);
    }

    
    VCOUT = adc3 * (3.3 / 4096.0) - Voffset;
    VC3 = VCOUT / Gvcout;
    // VC3 = ((VCOUT * GCref + OCvc3) / Gvcout) * (1 + GCvc3);
    if (cell_select == 4)
    {
        Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
        Wire1.write(0x13);
        Wire1.endTransmission();
    // delay(1);
    adc4 = analogRead(A2);
    }

    
    VCOUT = adc4 * (3.3 / 4096.0) - Voffset;
    VC4 = VCOUT / Gvcout;
    // VC4 = ((VCOUT * GCref + OCvc4) / Gvcout) * (1 + GCvc4);
    VCtotal = VC1 + VC2 + VC3 + VC4;
    pourcentage_batterie = (VCtotal - B_MIN) / (B_MAX - B_MIN) * 100;
}

void printBMS(void)
{
    Serial.print("VC1: ");
    Serial.print(VC1);
    Serial.print(" VC2: ");
    Serial.print(VC2);
    Serial.print(" VC3: ");
    Serial.print(VC3);
    Serial.print(" VC4: ");
    Serial.print(VC4);
    Serial.print(" Vctotal: ");
    Serial.print(VCtotal);
    Serial.print(" pourcentage batterie: ");
    Serial.println(pourcentage_batterie);
}

void requestEventBMS(void)
{
    Wire.write(0xD0 + dizaine);
    Wire.write(0xC0 + unite);
}
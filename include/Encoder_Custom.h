#include "BigBoyInclude.h"

#define NUM_ENCODERS 6

Encoder encoders[NUM_ENCODERS] = {
    Encoder(24, 22), // Encoder 1 pins
    Encoder(30, 28), // Encoder 2 pins
    Encoder(36, 34), // Encoder 3 pins
    Encoder(42, 40), // Encoder 4 pins
    Encoder(48, 46), // Encoder 5 pins
    Encoder(9, 8),   // Encoder 6 pins
};

// Store the old position of the encoder
long oldPosition1 = -999;
long oldPosition2 = -999;
long oldPosition3 = -999;
long oldPosition4 = -999;
long oldPosition5 = -999;
long oldPosition6 = -999;

// Store the count value
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;

int Enc1 = 0;
int Enc2 = 0;
int Enc3 = 0;
int Enc4 = 0;
int Enc5 = 0;
int Enc6 = 0;

void encoder_zero()
{
    // Set the initial position of the encoder as the old position
    oldPosition1 = encoders[0].read() / 4;
    oldPosition2 = encoders[1].read() / 4;
    oldPosition3 = encoders[2].read() / 4;
    oldPosition4 = encoders[3].read() / 4;
    oldPosition5 = encoders[4].read() / 4;
    oldPosition6 = encoders[5].read() / 4;
}

Bounce debouncer26 = Bounce();
Bounce debouncer32 = Bounce();
Bounce debouncer38 = Bounce();
Bounce debouncer44 = Bounce();
Bounce debouncer50 = Bounce();
Bounce debouncer10 = Bounce();

void encoder_setup(int btnPin1, int btnPin2, int btnPin3, int btnPin4, int btnPin5, int btnPin6)
{
    // pinMode(btnPin1, INPUT);
    debouncer26.attach(btnPin1, INPUT);
    debouncer26.interval(2);
    debouncer32.attach(btnPin2, INPUT);
    debouncer32.interval(2);
    debouncer38.attach(btnPin3, INPUT);
    debouncer38.interval(2);
    debouncer44.attach(btnPin4, INPUT);
    debouncer44.interval(2);
    debouncer50.attach(btnPin5, INPUT);
    debouncer50.interval(2);
    debouncer10.attach(btnPin6, INPUT);
    debouncer10.interval(2);
}

int boutonEncoder = 0;

void encoder_loop_serial(void)
{
    debouncer26.update();
    debouncer32.update();
    debouncer38.update();
    debouncer44.update();
    debouncer50.update();
    debouncer10.update();
    if (debouncer26.fell())
    {
        boutonEncoder = 1;
        Serial.println("BTN1");
    }
    if (debouncer32.fell())
    {
        boutonEncoder = 2;
        Serial.println("BTN2");
    }
    if (debouncer38.fell())
    {
        boutonEncoder = 3;
        Serial.println("BTN3");
    }
    if (debouncer44.fell())
    {
        boutonEncoder = 4;
        Serial.println("BTN4");
    }
    if (debouncer50.fell())
    {
        boutonEncoder = 5;
        Serial.println("BTN5");
    }
    if (debouncer10.fell())
    {
        boutonEncoder = 6;
        Serial.println("BTN6");
    }
    // Read the current position of the encoder
    long newPosition1 = encoders[0].read() / 4;
    long newPosition2 = encoders[1].read() / 4;
    long newPosition3 = encoders[2].read() / 4;
    long newPosition4 = encoders[3].read() / 4;
    long newPosition5 = encoders[4].read() / 4;
    long newPosition6 = encoders[5].read() / 4;

    // Only update if the position has changed
    if (newPosition1 != oldPosition1)
    {

        // Check the direction of rotation
        if (newPosition1 > oldPosition1)
        {
            count1++;
            Enc1 = 1;
            Serial.print("Count1: ");
            Serial.println(count1);
            oldPosition1 = newPosition1;
        }
        else if (newPosition1 < oldPosition1)
        {
            count1--;
            Enc1 = -1;
            Serial.print("Count1: ");
            Serial.println(count1);
            oldPosition1 = newPosition1;
        }
    }
    if (newPosition2 != oldPosition2)
    {

        // Check the direction of rotation
        if (newPosition2 > oldPosition2)
        {
            count2++;
            Enc2 = 1;
            Serial.print("Count2: ");
            Serial.println(count2);
            oldPosition2 = newPosition2;
        }
        else if (newPosition2 < oldPosition2)
        {
            count2--;
            Enc2 = -1;
            Serial.print("Count2: ");
            Serial.println(count2);
            oldPosition2 = newPosition2;
        }
    }
    if (newPosition3 != oldPosition3)
    {

        // Check the direction of rotation
        if (newPosition3 > oldPosition3)
        {
            count3++;
            Enc3 = 1;
            Serial.print("Count3: ");
            Serial.println(count3);
            oldPosition3 = newPosition3;
        }
        else if (newPosition3 < oldPosition3)
        {
            count3--;
            Enc3 = -1;
            Serial.print("Count3: ");
            Serial.println(count3);
            oldPosition3 = newPosition3;
        }
    }
    if (newPosition4 != oldPosition4)
    {

        // Check the direction of rotation
        if (newPosition4 > oldPosition4)
        {
            count4++;
            Enc4 = 1;
            Serial.print("Count4: ");
            Serial.println(count4);
            oldPosition4 = newPosition4;
        }
        else if (newPosition4 < oldPosition4)
        {
            count4--;
            Enc4 = -1;
            Serial.print("Count4: ");
            Serial.println(count4);
            oldPosition4 = newPosition4;
        }
    }
    if (newPosition5 != oldPosition5)
    {

        // Check the direction of rotation
        if (newPosition5 > oldPosition5)
        {
            count5++;
            Enc5 = 1;
            Serial.print("Count5: ");
            Serial.println(count5);
            oldPosition5 = newPosition5;
        }
        else if (newPosition5 < oldPosition5)
        {
            count5--;
            Enc5 = -1;
            Serial.print("Count5: ");
            Serial.println(count5);
            oldPosition5 = newPosition5;
        }
    }
    if (newPosition6 != oldPosition6)
    {

        // Check the direction of rotation
        if (newPosition6 > oldPosition6)
        {
            count6++;
            Enc6 = 1;
            Serial.print("Count6: ");
            Serial.println(count6);
            oldPosition6 = newPosition6;
        }
        else if (newPosition6 < oldPosition6)
        {
            count6--;
            Enc6 = -1;
            Serial.print("Count6: ");
            Serial.println(count6);
            oldPosition6 = newPosition6;
        }
    }
}

void encoder_loop(void)
{
    debouncer26.update();
    debouncer32.update();
    debouncer38.update();
    debouncer44.update();
    debouncer50.update();
    debouncer10.update();
    if (debouncer26.fell())
    {
        boutonEncoder = 1;
    }
    if (debouncer32.fell())
    {
        boutonEncoder = 2;
    }
    if (debouncer38.fell())
    {
        boutonEncoder = 3;
    }
    if (debouncer44.fell())
    {
        boutonEncoder = 4;
    }
    if (debouncer50.fell())
    {
        boutonEncoder = 5;
    }
    if (debouncer10.fell())
    {
        boutonEncoder = 6;
    }
    // Read the current position of the encoder
    long newPosition1 = encoders[0].read() / 4;
    long newPosition2 = encoders[1].read() / 4;
    long newPosition3 = encoders[2].read() / 4;
    long newPosition4 = encoders[3].read() / 4;
    long newPosition5 = encoders[4].read() / 4;
    long newPosition6 = encoders[5].read() / 4;

    // Only update if the position has changed
    if (newPosition1 != oldPosition1)
    {

        // Check the direction of rotation
        if (newPosition1 > oldPosition1)
        {
            count1++;
            Enc1 = 1;
            oldPosition1 = newPosition1;
        }
        else if (newPosition1 < oldPosition1)
        {
            count1--;
            Enc1 = -1;
            oldPosition1 = newPosition1;
        }
    }
    if (newPosition2 != oldPosition2)
    {

        // Check the direction of rotation
        if (newPosition2 > oldPosition2)
        {
            count2++;
            Enc2 = 1;
            oldPosition2 = newPosition2;
        }
        else if (newPosition2 < oldPosition2)
        {
            count2--;
            Enc2 = -1;
            oldPosition2 = newPosition2;
        }
    }
    if (newPosition3 != oldPosition3)
    {

        // Check the direction of rotation
        if (newPosition3 > oldPosition3)
        {
            count3++;
            Enc3 = 1;
            oldPosition3 = newPosition3;
        }
        else if (newPosition3 < oldPosition3)
        {
            count3--;
            Enc3 = -1;
            oldPosition3 = newPosition3;
        }
    }
    if (newPosition4 != oldPosition4)
    {

        // Check the direction of rotation
        if (newPosition4 > oldPosition4)
        {
            count4++;
            Enc4 = 1;
            oldPosition4 = newPosition4;
        }
        else if (newPosition4 < oldPosition4)
        {
            count4--;
            Enc4 = -1;
            oldPosition4 = newPosition4;
        }
    }
    if (newPosition5 != oldPosition5)
    {

        // Check the direction of rotation
        if (newPosition5 > oldPosition5)
        {
            count5++;
            Enc5 = 1;
            oldPosition5 = newPosition5;
        }
        else if (newPosition5 < oldPosition5)
        {
            count5--;
            Enc5 = -1;
            oldPosition5 = newPosition5;
        }
    }
    if (newPosition6 != oldPosition6)
    {

        // Check the direction of rotation
        if (newPosition6 > oldPosition6)
        {
            count6++;
            Enc6 = 1;
            oldPosition6 = newPosition6;
        }
        else if (newPosition6 < oldPosition6)
        {
            count6--;
            Enc6 = -1;
            oldPosition6 = newPosition6;
        }
    }
}
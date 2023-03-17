#include "BigBoyInclude.h"

// declares 16 buttons on D22 to D52 only on pair pin number (D22, D24, D26, D28, D30, D32, D34, D36, D38, D40, D42, D44, D46, D48, D50, D52)
Bounce debouncer52 = Bounce();      //btn layer
Bounce debouncer53 = Bounce();      
Bounce debouncer50 = Bounce();
Bounce debouncer49 = Bounce();
Bounce debouncer47 = Bounce();
Bounce debouncer44 = Bounce();
Bounce debouncer43 = Bounce();
Bounce debouncer41 = Bounce();
Bounce debouncer38 = Bounce();
Bounce debouncer37 = Bounce();
Bounce debouncer35 = Bounce();
Bounce debouncer32 = Bounce();
Bounce debouncer31 = Bounce();
Bounce debouncer29 = Bounce();
Bounce debouncer26 = Bounce();
Bounce debouncer25 = Bounce();
Bounce debouncer23 = Bounce();

// declares 16 buttons on D22 to D52 only on pair pin number (D22, D24, D26, D28, D30, D32, D34, D36, D38, D40, D42, D44, D46, D48, D50, D52) pin 22 is btn1 and pin 52 is btn16
const int BTN_Layer = 52;
const int BTN16 = 53;
const int BTN15 = 51;
const int BTN14 = 49;
const int BTN13 = 47;
const int BTN12 = 45;
const int BTN11 = 43;
const int BTN10 = 41;
const int BTN9 = 39;
const int BTN8 = 37; 
const int BTN7 = 35; 
const int BTN6 = 33; 
const int BTN5 = 31; 
const int BTN4 = 29;     
const int BTN3 = 27; 
const int BTN2 = 25; 
const int BTN1 = 23; 

int bouton = 0;
int bouton_layer = 2;
// fonction that contains the 16 buttons declaration
void BTN_setup(void)
{
    debouncer52.attach(BTN_Layer, INPUT);
    debouncer53.attach(BTN16, INPUT);
    debouncer50.attach(BTN15, INPUT);
    debouncer49.attach(BTN14, INPUT);
    debouncer47.attach(BTN13, INPUT);
    debouncer44.attach(BTN12, INPUT);
    debouncer43.attach(BTN11, INPUT);
    debouncer41.attach(BTN10, INPUT);
    debouncer38.attach(BTN9, INPUT);
    debouncer37.attach(BTN8, INPUT);
    debouncer35.attach(BTN7, INPUT);
    debouncer32.attach(BTN6, INPUT);
    debouncer31.attach(BTN5, INPUT);
    debouncer29.attach(BTN4, INPUT);
    debouncer26.attach(BTN3, INPUT);
    debouncer25.attach(BTN2, INPUT);
    debouncer23.attach(BTN1, INPUT);

    debouncer53.interval(5);
    debouncer52.interval(5);
    debouncer50.interval(5);
    debouncer49.interval(5);
    debouncer47.interval(5);
    debouncer44.interval(5);
    debouncer43.interval(5);
    debouncer41.interval(5);
    debouncer38.interval(5);
    debouncer37.interval(5);
    debouncer35.interval(5);
    debouncer32.interval(5);
    debouncer31.interval(5);
    debouncer29.interval(5);
    debouncer26.interval(5);
    debouncer25.interval(5);
    debouncer23.interval(5);
}

void BTN_I2C_Serial(void)
{
    debouncer53.update();
    debouncer52.update();
    debouncer50.update();
    debouncer49.update();
    debouncer47.update();
    debouncer44.update();
    debouncer43.update();
    debouncer41.update();
    debouncer38.update();
    debouncer37.update();
    debouncer35.update();
    debouncer32.update();
    debouncer31.update();
    debouncer29.update();
    debouncer26.update();
    debouncer25.update();
    debouncer23.update();

    if (debouncer52.rose())
    {
        if (bouton_layer == 0)
        {
            bouton_layer = 2;
            //Serial.println("Button layer 1 pressed");
        }
        if (bouton_layer == 2)
        {
            bouton_layer = 1;
            Serial.println("Button layer 1 pressed");
        }
        else if (bouton_layer == 1)
        {
            bouton_layer = 0;
            Serial.println("Button layer 0 released");
        }
        //bouton_layer = 1;
        //Serial.println("Button layer pressed");
        
    }
    if (debouncer53.rose())
    {
        bouton = 16;
        Serial.println("Button 16 pressed");
    }
    if (debouncer50.rose())
    {
        bouton = 15;
        Serial.println("Button 15 pressed");
    }
    if (debouncer49.rose())
    {
        bouton = 14;
        Serial.println("Button 14 pressed");
    }
    if (debouncer47.rose())
    {
        bouton = 13;
        Serial.println("Button 13 pressed");
    }
    if (debouncer44.rose())
    {
        bouton = 12;
        Serial.println("Button 12 pressed");
    }
    if (debouncer43.rose())
    {
        bouton = 11;
        Serial.println("Button 11 pressed");
    }
    if (debouncer41.rose())
    {
        bouton = 10;
        Serial.println("Button 10 pressed");
    }
    if (debouncer38.rose())
    {
        bouton = 9;
        Serial.println("Button 9 pressed");
    }
    if (debouncer37.rose())
    {
        bouton = 8;
        Serial.println("Button 8 pressed");
    }
    if (debouncer35.rose())
    {
        bouton = 7;
        Serial.println("Button 7 pressed");
    }
    if (debouncer32.rose())
    {
        bouton = 6;
        Serial.println("Button 6 pressed");
    }
    if (debouncer31.rose())
    {
        bouton = 5;
        Serial.println("Button 5 pressed");
    }
    if (debouncer29.rose())
    {
        bouton = 4;
        Serial.println("Button 4 pressed");
    }
    if (debouncer26.rose())
    {
        bouton = 3;
        Serial.println("Button 3 pressed");
    }
    if (debouncer25.rose())
    {
        bouton = 2;
        Serial.println("Button 2 pressed");
    }
    if (debouncer23.rose())
    {
        bouton = 1;
        Serial.println("Button 1 pressed");
    }
}

void BTN_I2C(void)
{
    debouncer52.update();
    debouncer50.update();
    debouncer49.update();
    debouncer47.update();
    debouncer44.update();
    debouncer43.update();
    debouncer41.update();
    debouncer38.update();
    debouncer37.update();
    debouncer35.update();
    debouncer32.update();
    debouncer31.update();
    debouncer29.update();
    debouncer26.update();
    debouncer25.update();
    debouncer23.update();

    if (debouncer52.rose())
    {
        bouton = 16;
    }
    if (debouncer50.rose())
    {
        bouton = 15;
    }
    if (debouncer49.rose())
    {
        bouton = 14;
    }
    if (debouncer47.rose())
    {
        bouton = 13;
    }
    if (debouncer44.rose())
    {
        bouton = 12;
    }
    if (debouncer43.rose())
    {
        bouton = 11;
    }
    if (debouncer41.rose())
    {
        bouton = 10;
    }
    if (debouncer38.rose())
    {
        bouton = 9;
    }
    if (debouncer37.rose())
    {
        bouton = 8;
    }
    if (debouncer35.rose())
    {
        bouton = 7;
    }
    if (debouncer32.rose())
    {
        bouton = 6;
    }
    if (debouncer31.rose())
    {
        bouton = 5;
    }
    if (debouncer29.rose())
    {
        bouton = 4;
    }
    if (debouncer26.rose())
    {
        bouton = 3;
    }
    if (debouncer25.rose())
    {
        bouton = 2;
    }
    if (debouncer23.rose())
    {
        bouton = 1;
    }
}
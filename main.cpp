#include "iostream"
#include "pico/stdlib.h"

// building...
/*
 * each serial number corresponds to a pin port and led
 * 
 *    |---A---|
 *    B       C
 *    |---D---|   
 *    E       F
 *    |---G---|
 * 
 * 
 * gpio: GPIO_OUT = 1 is ON
 *       GPIO_OUT = 0 is OFF
*/

// define test led pin
const uint TEST_LED_PIN = 25;

// define main led pin
const uint MAIN_LED_A_PIN = 0;
const uint MAIN_LED_B_PIN = 1;
const uint MAIN_LED_C_PIN = 2;
const uint MAIN_LED_D_PIN = 3;
const uint MAIN_LED_E_PIN = 4;
const uint MAIN_LED_F_PIN = 5;
const uint MAIN_LED_G_PIN = 6;


/*
    LED object group
*/

// create an led object
class LED {
    public:
        uint LED_PIN;

        // initialize the output pin and led
        LED (uint INIT_LED_PIN) {
            LED_PIN = INIT_LED_PIN;
            gpio_init(LED_PIN);
            gpio_set_dir(LED_PIN, GPIO_OUT);
        }

        void ON();
        void OFF();
        void SET_STATUS(bool isON);
};

void LED::SET_STATUS(bool isON){
    if (isON == true){ON();} 
    else if (isON == false){OFF();}
}

// light up the led
void LED::ON() {
    gpio_put(LED_PIN, 0);
}

// turn off the led
void LED::OFF() {
    gpio_put(LED_PIN, 1);
}

// initialize all LEDs
LED MainLED_A(MAIN_LED_A_PIN);
LED MainLED_B(MAIN_LED_B_PIN);
LED MainLED_C(MAIN_LED_C_PIN);
LED MainLED_D(MAIN_LED_D_PIN);
LED MainLED_E(MAIN_LED_E_PIN);
LED MainLED_F(MAIN_LED_F_PIN);
LED MainLED_G(MAIN_LED_G_PIN);



/*
    Display Numbers
*/

// dispaly_number display numbers from 0 to 9
void display_number(int number) {
    switch (number){
    case 0:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();

    case 1:
        MainLED_A.OFF();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();

    case 2:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.OFF();
        MainLED_G.ON();

    case 3:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();

    case 4:
        MainLED_A.OFF();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();

    case 5:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.OFF();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();

    case 6:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.OFF();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();

    case 7:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();

    case 8:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();

    case 9:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();
    
    default:
        break;
    }
}


int main() {
    display_number(1);
}

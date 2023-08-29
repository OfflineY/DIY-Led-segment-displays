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

    = uint LED_PIN

    - LED(uint)
    - ON
    - OFF
    - SET_STATUS(bool)
*/

// create an led object
class LED {
    public:

        // initialize led pin
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
    Utils

    - init_all_led_off
    - init_all_led_on
*/

void init_all_led_off() {
    MainLED_A.OFF();
    MainLED_B.OFF();
    MainLED_C.OFF();
    MainLED_D.OFF();
    MainLED_E.OFF();
    MainLED_F.OFF();
    MainLED_G.OFF();
}

void init_all_led_on() {
    MainLED_A.ON();
    MainLED_B.ON();
    MainLED_C.ON();
    MainLED_D.ON();
    MainLED_E.ON();
    MainLED_F.ON();
    MainLED_G.ON();
}



/*
    Animation object group

    - Flashing(int, int)
    - Rotating(int, int)
    - BaGua(int, int)
*/

// LED animation presets
class Animation {
    public:

        // Flashing effect animation
        void Flashing(int times, int sleep_time);

        // Rotation effect animation
        void Rotating(int times, int sleep_time);

        // BaGua effect animation
        void BaGua(int times, int sleep_time);
};

void Animation::Flashing(int times, int sleep_time) {
    for (int i = 0; i <= times; i++) {
        // 1 frame
        init_all_led_on();
        MainLED_D.OFF();
        sleep_ms(sleep_time);

        // 2 frame
        init_all_led_off();
        sleep_ms(sleep_time);
    }
}

void Animation::Rotating(int times, int sleep_time) {
    for (int i = 0; i < times; i++) {
        // 1 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_A.OFF();
        sleep_ms(sleep_time);

        // 2 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_C.OFF();
        sleep_ms(sleep_time);

        // 3 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_F.OFF();
        sleep_ms(sleep_time);

        // 4 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_G.OFF();
        sleep_ms(sleep_time);

        // 5 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_E.OFF();
        sleep_ms(sleep_time);

        // 6 frame
        init_all_led_on();
        MainLED_D.OFF();
        MainLED_B.OFF();
        sleep_ms(sleep_time);
    }
}

void Animation::BaGua(int times, int sleep_time) {
    for (int i = 0; i <= times; i++) {
        // 1 frame
        init_all_led_off();
        MainLED_A.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        sleep_ms(sleep_time);

        // 2 frame
        init_all_led_off();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.ON();
        sleep_ms(sleep_time);

        // 3 frame
        init_all_led_off();
        MainLED_E.ON();
        MainLED_G.ON();
        MainLED_D.ON();
        sleep_ms(sleep_time);

        // 4 frame
        init_all_led_off();
        MainLED_E.ON();
        MainLED_G.ON();
        MainLED_F.ON();
        sleep_ms(sleep_time);

        // 5 frame
        init_all_led_off();
        MainLED_D.ON();
        MainLED_G.ON();
        MainLED_F.ON();
        sleep_ms(sleep_time);

        // 6 frame
        init_all_led_off();
        MainLED_D.ON();
        MainLED_B.ON();
        MainLED_F.ON();
        sleep_ms(sleep_time);

        // 7 frame
        init_all_led_off();
        MainLED_D.ON();
        MainLED_B.ON();
        MainLED_A.ON();
        sleep_ms(sleep_time);

        // 8 frame
        init_all_led_off();
        MainLED_C.ON();
        MainLED_B.ON();
        MainLED_A.ON();
        sleep_ms(sleep_time);
    }
}



/*
    Display Numbers

    - display_number(int)
*/

// dispaly_number display numbers from 0 to 9
void display_number(int number) {
    init_all_led_off();
    switch (number){
    
    /*
        |---x---|
        x       x
        |---o---|
        x       x
        |---x---|
    */
    case 0:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();
        break;

    /*
        |---o---|
        o       x
        |---o---|
        o       x
        |---o---|
    */
    case 1:
        MainLED_A.OFF();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();
        break;

    /*
        |---x---|
        o       x
        |---x---|
        x       o
        |---x---|
    */
    case 2:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.OFF();
        MainLED_G.ON();
        break;

    /*
        |---x---|
        o       x
        |---x---|
        o       x
        |---x---|
    */
    case 3:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();
        break;

    /*
        |---o---|
        x       x
        |---x---|
        o       x
        |---o---|
    */
    case 4:
        MainLED_A.OFF();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();
        break;

    /*
        |---x---|
        x       o
        |---x---|
        o       x
        |---x---|
    */
    case 5:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.OFF();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();
        break;

    /*
        |---x---|
        x       o
        |---x---|
        x       x
        |---x---|
    */
    case 6:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.OFF();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();
        break;

    /*
        |---x---|
        o       x
        |---o---|
        o       x
        |---o---|
    */
    case 7:
        MainLED_A.ON();
        MainLED_B.OFF();
        MainLED_C.ON();
        MainLED_D.OFF();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.OFF();
        break;

    /*
        |---x---|
        x       x
        |---x---|
        x       x
        |---x---|
    */
    case 8:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.ON();
        MainLED_F.ON();
        MainLED_G.ON();
        break;

    /*
        |---x---|
        x       x
        |---x---|
        o       x
        |---x---|
    */
    case 9:
        MainLED_A.ON();
        MainLED_B.ON();
        MainLED_C.ON();
        MainLED_D.ON();
        MainLED_E.OFF();
        MainLED_F.ON();
        MainLED_G.ON();
        break;
    
    default:
        init_all_led_off();
        break;
    }
}


int main() {
    init_all_led_on();

    Animation LED_Animation;

    LED_Animation.Flashing(10, 100);
    LED_Animation.Rotating(5, 100);
    LED_Animation.BaGua(8, 100);

    for (int i = 0; i <= 9; i++) {
        display_number(i);
        sleep_ms(500);
    }

    init_all_led_off();
}

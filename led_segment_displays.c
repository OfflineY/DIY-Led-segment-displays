#include <stdio.h>
#include "pico/stdlib.h"

// Building...


// test led pin
#define TEST_LED_PIN 25

// main led pin
#define MAIN_LED_A_PIN 0
#define MAIN_LED_B_PIN 1
#define MAIN_LED_C_PIN 2
#define MAIN_LED_D_PIN 3
#define MAIN_LED_E_PIN 4
#define MAIN_LED_F_PIN 5
#define MAIN_LED_G_PIN 6

int main() {
    gpio_init(TEST_LED_PIN);
    gpio_set_dir(TEST_LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(TEST_LED_PIN, 1);
        sleep_ms(250);
        gpio_put(TEST_LED_PIN, 0);
        sleep_ms(250);
        printf("Hello!");
    }
}

void LED(uint LED_PIN, int status) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, status);
}

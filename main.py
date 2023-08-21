import machine
from time import sleep

'''
Plate design:
Each serial number corresponds to a pin port and LED

            A(pin0)
    B(pin1)       C(pin2)
            D(pin3)
    E(pin4)       F(pin5)
            G(pin6)
'''

# LED PING
MAIN_LED_A_PIN = 0
MAIN_LED_B_PIN = 1
MAIN_LED_C_PIN = 2
MAIN_LED_D_PIN = 3
MAIN_LED_E_PIN = 4
MAIN_LED_F_PIN = 5
MAIN_LED_G_PIN = 6

# TEST LED
LED_TEST = machine.Pin(25, machine.Pin.OUT)

# MAIN LED
LED_A = machine.Pin(MAIN_LED_A_PIN, machine.Pin.OUT)
LED_B = machine.Pin(MAIN_LED_B_PIN, machine.Pin.OUT)
LED_C = machine.Pin(MAIN_LED_C_PIN, machine.Pin.OUT)
LED_D = machine.Pin(MAIN_LED_D_PIN, machine.Pin.OUT)
LED_E = machine.Pin(MAIN_LED_E_PIN, machine.Pin.OUT)
LED_F = machine.Pin(MAIN_LED_F_PIN, machine.Pin.OUT)
LED_G = machine.Pin(MAIN_LED_G_PIN, machine.Pin.OUT)


def main():
    LED.Animation.bagua(5)
    LED.Animation.flashing(8, 0.1)
    LED.Animation.rotating(5)
    sleep_time = 0.2
    num = 0
    while num <= 9:
        sleep(sleep_time)
        LED.initialization(1)
        LED.numbers(num)
        num = num + 1

    sleep(0.3)
    LED.initialization(1)


# Digital tube LED controller
# ***
class LED():

    # Initialization all the led
    # ***
    def initialization(value):
        LED_TEST.value(value)
        LED_A.value(value)
        LED_B.value(value)
        LED_C.value(value)
        LED_D.value(value)
        LED_E.value(value)
        LED_F.value(value)
        LED_G.value(value)

    # Show the numbers
    # ***
    def numbers(num):

        # 0 means on, 1 means off
        #
        #     x---A(0)---x
        #  B(0)|        |C(0)
        #     x|--D(1)--|x
        #  E(0)|        |F(0)
        #     x---G(0)---x
        #
        if num == 0:
            LED_A.value(0)
            LED_B.value(0)
            LED_C.value(0)
            LED_E.value(0)
            LED_F.value(0)
            LED_G.value(0)

        #
        #     x---A(1)---x
        #  B(1)|        |C(0)
        #     x|--D(1)--|x
        #  E(1)|        |F(0)
        #     x---G(1)---x
        #
        elif num == 1:
            LED_C.value(0)
            LED_F.value(0)

        #
        #     x---A(0)---x
        #  B(1)|        |C(0)
        #     x|--D(0)--|x
        #  E(0)|        |F(1)
        #     x---G(0)---x
        #
        elif num == 2:
            LED_A.value(0)
            LED_C.value(0)
            LED_D.value(0)
            LED_E.value(0)
            LED_G.value(0)

        #
        #     x---A(0)---x
        #  B(1)|        |C(0)
        #     x|--D(0)--|x
        #  E(1)|        |F(0)
        #     x---G(0)---x
        #
        elif num == 3:
            LED_A.value(0)
            LED_C.value(0)
            LED_D.value(0)
            LED_F.value(0)
            LED_G.value(0)

        #
        #     x---A(1)---x
        #  B(0)|        |C(0)
        #     x|--D(0)--|x
        #  E(1)|        |F(0)
        #     x---G(1)---x
        #
        elif num == 4:
            LED_B.value(0)
            LED_D.value(0)
            LED_C.value(0)
            LED_F.value(0)

        #
        #     x---A(0)---x
        #  B(0)|        |C(1)
        #     x|--D(0)--|x
        #  E(1)|        |F(0)
        #     x---G(0)---x
        #
        elif num == 5:
            LED_A.value(0)
            LED_B.value(0)
            LED_D.value(0)
            LED_F.value(0)
            LED_G.value(0)

        #
        #     x---A(0)---x
        #  B(0)|        |C(1)
        #     x|--D(0)--|x
        #  E(0)|        |F(0)
        #     x---G(0)---x
        #
        elif num == 6:
            LED_A.value(0)
            LED_B.value(0)
            LED_D.value(0)
            LED_E.value(0)
            LED_F.value(0)
            LED_G.value(0)

        #
        #     x---A(0)---x
        #  B(1)|        |C(0)
        #     x|--D(1)--|x
        #  E(1)|        |F(0)
        #     x---G(1)---x
        #
        elif num == 7:
            LED_A.value(0)
            LED_C.value(0)
            LED_F.value(0)

        #
        #     x---A(0)---x
        #  B(0)|        |C(0)
        #     x|--D(0)--|x
        #  E(0)|        |F(0)
        #     x---G(0)---x
        #
        elif num == 8:
            LED_A.value(0)
            LED_B.value(0)
            LED_C.value(0)
            LED_D.value(0)
            LED_E.value(0)
            LED_F.value(0)
            LED_G.value(0)

        #
        #     x---A(0)---x
        #  B(0)|        |C(0)
        #     x|--D(0)--|x
        #  E(1)|        |F(0)
        #     x---G(0)---x
        #
        elif num == 9:
            LED_A.value(0)
            LED_B.value(0)
            LED_C.value(0)
            LED_D.value(0)
            LED_F.value(0)
            LED_G.value(0)

    # LED animation presets
    # ***
    class Animation():

        # Bagua effect animation
        # ***
        def bagua(num):
            sleep_time = 0.1
            i = 0
            while i <= num:
                sleep(sleep_time)
                LED.initialization(1)
                LED_A.value(0)
                LED_C.value(0)
                LED_D.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_E.value(0)
                LED_C.value(0)
                LED_D.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_E.value(0)
                LED_G.value(0)
                LED_D.value(0)
                
                sleep(sleep_time)
                LED.initialization(1)
                LED_E.value(0)
                LED_G.value(0)
                LED_F.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_D.value(0)
                LED_G.value(0)
                LED_F.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_D.value(0)
                LED_B.value(0)
                LED_F.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_D.value(0)
                LED_B.value(0)
                LED_A.value(0)

                sleep(sleep_time)
                LED.initialization(1)
                LED_C.value(0)
                LED_B.value(0)
                LED_A.value(0)

                i = i + 1

        # Flashing effect animation
        # ***
        def flashing(times, time):
            i = 0
            while i <= times:
                LED.initialization(0)
                LED_D.value(1)
                sleep(time)

                LED.initialization(1)
                LED_D.value(1)
                sleep(time)

                i = i + 1

        # Rotation effect animation
        # ***
        def rotating(num):
            sleep_time = 0.1
            i = 0
            while i <= num:
                sleep(sleep_time)
                LED.initialization(0)
                LED_A.value(1)
                LED_D.value(1)

                sleep(sleep_time)
                LED.initialization(0)
                LED_C.value(1)
                LED_D.value(1)

                sleep(sleep_time)
                LED.initialization(0)
                LED_F.value(1)
                LED_D.value(1)
                sleep(sleep_time)
                LED.initialization(0)
                LED_G.value(1)
                LED_D.value(1)

                sleep(sleep_time)
                LED.initialization(0)
                LED_E.value(1)
                LED_D.value(1)
                
                sleep(sleep_time)
                LED.initialization(0)
                LED_B.value(1)
                LED_D.value(1)

                sleep(sleep_time)
                LED.initialization(0)
                LED_D.value(1)

                i = i + 1


if __name__ == '__main__':
    main()
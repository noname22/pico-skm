#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "pico/time.h"
#include "class/hid/hid.h"

#include "skmhid.h"

int main()
{
    stdio_init_all();
    skmhid_init();

    bool press_key = false;

    while (true)
    {
        if (!skmhid_is_connected())
        {
            sleep_ms(10);
            continue;
        }

        skmhid_move_mouse(-10, -10);
        sleep_ms(250);

        uint8_t key = HID_KEY_A;
        skmhid_keyboard_set_key_state(&key, press_key ? 1 : 0);
        press_key = !press_key;

        sleep_ms(250);
    }
}
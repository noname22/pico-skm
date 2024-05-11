#ifndef SKMHID_H
#define SKMHID_H

#include <stdint.h>
#include <stdbool.h>

void skmhid_move_mouse(int8_t x, int8_t y);
void skmhid_keyboard_set_key_state(uint8_t *key_codes, int key_code_count);
bool skmhid_is_connected();
void skmhid_init();

#endif
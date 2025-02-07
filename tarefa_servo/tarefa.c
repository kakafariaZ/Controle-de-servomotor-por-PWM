#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12
#define PWM_FREQ 50
#define PWM_WRAP 20000

void set_servo_angle(uint pin, uint16_t pulse_width) {
    pwm_set_gpio_level(pin, pulse_width);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);
    
    while (1) {
        set_servo_angle(SERVO_PIN, 2400);
        sleep_ms(5000);
        
        set_servo_angle(SERVO_PIN, 1470);
        sleep_ms(5000);
        
        set_servo_angle(SERVO_PIN, 500);
        sleep_ms(5000);
        
        for (uint16_t pos = 500; pos <= 2400; pos += 5) {
            set_servo_angle(SERVO_PIN, pos);
            sleep_ms(10);
        }
        
        for (uint16_t pos = 2400; pos >= 500; pos -= 5) {
            set_servo_angle(SERVO_PIN, pos);
            sleep_ms(10);
        }
    }
}

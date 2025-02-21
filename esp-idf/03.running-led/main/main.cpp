#include <iostream>

// FreeRTOS includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// ESP-IDF includes
#include <driver/gpio.h>
#include <esp_log.h>

extern "C"
{ // Important: Declare C functions as extern "C"
    void app_main(void);
}

// The GPIOs that are connected to the LEDs
const int blinkTime = 300;
const gpio_num_t led_gpios[] = {GPIO_NUM_19, GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23};
const int num_leds = 4;

void app_main(void)
{

    // Configure the GPIOs
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

    // Initally turn off all LEDs
    for (int i = 0; i < num_leds; i++)
    {
        io_conf.pin_bit_mask = (1ULL << led_gpios[i]);
        gpio_config(&io_conf);
        gpio_set_level(led_gpios[i], 0);
    }

    // Loop forever
    while (true)
    {
        for (int i = 0; i < num_leds; i++)
        {
            gpio_set_level(led_gpios[i], 1);
            vTaskDelay(blinkTime / portTICK_PERIOD_MS);
            gpio_set_level(led_gpios[i], 0);
        }
    }
}

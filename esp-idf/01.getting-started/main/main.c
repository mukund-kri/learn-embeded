#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define LED_PIN GPIO_NUM_2
#define TIME_DELAY 5000

void app_main(void)
{

    // 1. Configure the gpio 2 as output
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,      // disable all interupts
        .mode = GPIO_MODE_OUTPUT,            // Set as output mode
        .pin_bit_mask = (1ULL << LED_PIN),   // Bitmask of the LED I want to flask
        .pull_up_en = 0                      // Disable pull up mode
    };
    gpio_config(&io_conf);

    int isOn = 0;

    while (true)
    {
        // toggle the on / off stored value
        isOn = !isOn;

        // Turn on the LED on / off
        gpio_set_level(LED_PIN, isOn);
        printf("Led On/Off\n");
        vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);  // Delay for preset microseconds

    }
    


}
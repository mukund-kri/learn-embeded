#include <iostream>

// FreeRTOS includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// ESP-IDF includes
#include <esp_log.h>


extern "C" { // Important: Declare C functions as extern "C"
    void app_main(void);
}

void app_main(void)
{

    ESP_LOGI("main", "Hello World!");

    // Print out alive to the esp log every 1 second
    while (true)
    {
        ESP_LOGI("main", "Alive");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

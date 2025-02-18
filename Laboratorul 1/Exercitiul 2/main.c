#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_ON 0
#define LED_OFF 1
#define GPIO_OUTPUT_IO 4
#define GPIO_OUTPUT_PIN_SEL (1ULL<<GPIO_OUTPUT_IO)
void app_main() {
    //zero-initialize the config structure.
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    int cnt = 0;
    while(1) {
        printf("cnt: %d\n", cnt++);
        // vTaskDelay(1000 / portTICK_PERIOD_MS);
        // gpio_set_level(GPIO_OUTPUT_IO, cnt % 2);
        //on for 1000 ms
        gpio_set_level(GPIO_OUTPUT_IO, LED_ON);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        //off for 500 ms
        gpio_set_level(GPIO_OUTPUT_IO, LED_OFF);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        //on for 250 ms
        gpio_set_level(GPIO_OUTPUT_IO, LED_ON);
        vTaskDelay(250 / portTICK_PERIOD_MS);
        //off for 750 ms
        gpio_set_level(GPIO_OUTPUT_IO, LED_OFF);
        vTaskDelay(750 / portTICK_PERIOD_MS);
    }
}
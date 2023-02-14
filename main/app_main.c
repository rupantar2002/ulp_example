#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_err.h>
#include <esp_log.h>

#include <driver/rtc_io.h>

#include "esp32s2/ulp.h"
#include "esp32s2/ulp_riscv.h"

static const char *TAG = "app_main";

extern const uint8_t ULP_MAIN_CODE_START[] asm("_binary_ulp_main_bin_start");
extern const uint8_t ULP_MAIN_CODE_END[] asm("_binary_ulp_main_bin_end");

static void ConfigGpio();
static void InitProgram();

void app_main(void)
{
    ConfigGpio();
    InitProgram();

    while (1)
    {
        /* code */
        ESP_LOGI(TAG, "this is form main cpu\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void ConfigGpio()
{
    rtc_gpio_init(GPIO_NUM_1);
    rtc_gpio_set_direction(GPIO_NUM_1, RTC_GPIO_MODE_OUTPUT_ONLY);
}

void InitProgram()
{
    size_t codeSize = ULP_MAIN_CODE_END - ULP_MAIN_CODE_START;
    esp_err_t err = ulp_riscv_load_binary(ULP_MAIN_CODE_START, codeSize);
    ESP_ERROR_CHECK(err);
    err = ulp_riscv_run();
    ESP_ERROR_CHECK(err);
}
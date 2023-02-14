#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "ulp_riscv/ulp_riscv.h"
#include "ulp_riscv/ulp_riscv_utils.h"
#include "ulp_riscv/ulp_riscv_gpio.h"

// static bool gpio_level = false;

// /* this variable will be exported as a public symbol, visible from main CPU: */
// bool gpio_level_previous = false;

int main(void)
{
    int led_gpio = GPIO_NUM_1;
    ulp_riscv_gpio_init(led_gpio);

    while (1)
    {
        ulp_riscv_gpio_output_level(led_gpio, 1);
        ulp_riscv_delay_cycles(500 * ULP_RISCV_CYCLES_PER_US);
        ulp_riscv_gpio_output_level(led_gpio, 0);
        ulp_riscv_delay_cycles(500 * ULP_RISCV_CYCLES_PER_US);
        // gpio_level = (bool)ulp_riscv_gpio_get_level(GPIO_NUM_0);

        // /* Wakes up the main CPU if pin changed its state */
        // if (gpio_level != gpio_level_previous)
        // {
        //     gpio_level_previous = gpio_level;
        //     ulp_riscv_wakeup_main_processor();
        //     break;
        // }
    }
    /* ulp_riscv_shutdown() is called automatically when main exits */
    return 0;
}

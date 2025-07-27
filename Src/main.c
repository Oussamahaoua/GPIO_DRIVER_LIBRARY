#include "main.h"
#include "GPIO_header.h"
#include "stm32f1xx.h"
#include "GPIO_OOP_lib.h"

void SystemClock_Config(void);

void delay_ms(uint32_t time) {
    for (uint32_t i = 0; i < time * 1000; i++) {
        __asm("nop");
    }
}

int main(void) {
    // === 1. Configuration structure GPIO ===
    GPIO_OOP_InitTypeDef led_config;
    led_config.PIN       = GPIO_OOP_PIN_13;       // PC13
    led_config.MODE      = GPIO_OOP_MODE_OUTPUT;  // Mode sortie
    led_config.PULL      = GPIO_OOP_NOPULL;       // Pas de pull-up/down
    led_config.SPEED     = 0x02;                  // 2 MHz
    led_config.ALTERNATE = 0;                     // Non utilisé ici

    // === 2. Initialiser GPIOC avec ta lib ===
    LIB_GPIO_init(GPIOC, &led_config);

    // === 3. Boucle infinie : blink PC13 ===
    while (1) {
        LIB_GPIO_TOGGLEPIN(GPIOC, GPIO_OOP_PIN_13);
        delay_ms(500);
    }
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }


  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void)
{

  __disable_irq();
  while (1)
  {
  }

}
#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif

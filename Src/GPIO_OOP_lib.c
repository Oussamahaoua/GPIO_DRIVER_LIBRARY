#include "GPIO_OOP_lib.h"

// Initialise les GPIOs avec configuration personnalisée (orientée objet)
void LIB_GPIO_init(GPIO_TypeDef *GPIOx, GPIO_OOP_InitTypeDef *GPIO_init) {
    // 1. Activer l'horloge du port GPIO
    if (GPIOx == GPIOA) RCC->APB2ENR |= (1 << 2);
    else if (GPIOx == GPIOB) RCC->APB2ENR |= (1 << 3);
    else if (GPIOx == GPIOC) RCC->APB2ENR |= (1 << 4);
    else if (GPIOx == GPIOD) RCC->APB2ENR |= (1 << 5);
    else if (GPIOx == GPIOE) RCC->APB2ENR |= (1 << 6);

    // 2. Configurer chaque pin demandée
    for (uint8_t pin = 0; pin < 16; pin++) {
        if (GPIO_init->PIN & (1 << pin)) {
            uint32_t pos = (pin % 8) * 4;
            uint32_t config = 0;

            // MODE INPUT
            if (GPIO_init->MODE == GPIO_OOP_MODE_INPUT) {
                if (GPIO_init->PULL == GPIO_OOP_PULLUP) {
                    GPIOx->ODR |= (1 << pin);  // Activer le pull-up
                } else if (GPIO_init->PULL == GPIO_OOP_PULLDOWN) {
                    GPIOx->ODR &= ~(1 << pin); // Activer le pull-down
                }
                config = 0x08; // CNF=10 (input with pull-up/down), MODE=00
            }

            // MODE OUTPUT
            else if (GPIO_init->MODE == GPIO_OOP_MODE_OUTPUT) {
                config = (GPIO_init->SPEED & 0x03) | (0x00 << 2); // CNF=00
            }

            // MODE ALTERNATE FUNCTION
            else if (GPIO_init->MODE == GPIO_OOP_MODE_AF) {
                config = (GPIO_init->SPEED & 0x03) | (0x02 << 2); // CNF=10
            }

            // Appliquer la configuration dans CRL ou CRH
            if (pin < 8) {
                GPIOx->CRL &= ~(0xF << pos);       // Clear
                GPIOx->CRL |= (config << pos);     // Set
            } else {
                GPIOx->CRH &= ~(0xF << pos);
                GPIOx->CRH |= (config << pos);
            }
        }
    }
}

// Écriture sur un GPIO : HIGH ou LOW
void LIB_GPIO_WRiTEPIN(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin, GPIO_OOP_PinState pin_state) {
    if (pin_state != GPIO_OOP_PIN_RESET) {
        GPIOx->BSRR = GPIO_pin;     // Set pin (BSRR LSB 0–15)
    } else {
        GPIOx->BRR = GPIO_pin;      // Reset pin (BRR)
    }
}

// Toggle du GPIO (utile pour LED clignotante)
void LIB_GPIO_TOGGLEPIN(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin) {
    GPIOx->ODR ^= GPIO_pin;

}

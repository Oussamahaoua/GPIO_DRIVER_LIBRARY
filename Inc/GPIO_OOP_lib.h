#ifndef SRC_GPIO_OOP_LIB_H_
#define SRC_GPIO_OOP_LIB_H_

#include "stm32f1xx.h"  // Accès à RCC, GPIO_TypeDef, etc.

// === Broches GPIO (inchangées) ===
#define GPIO_OOP_PIN_0         ((uint16_t)0x0001)
#define GPIO_OOP_PIN_1         ((uint16_t)0x0002)
#define GPIO_OOP_PIN_2         ((uint16_t)0x0004)
#define GPIO_OOP_PIN_3         ((uint16_t)0x0008)
#define GPIO_OOP_PIN_4         ((uint16_t)0x0010)
#define GPIO_OOP_PIN_5         ((uint16_t)0x0020)
#define GPIO_OOP_PIN_6         ((uint16_t)0x0040)
#define GPIO_OOP_PIN_7         ((uint16_t)0x0080)
#define GPIO_OOP_PIN_8         ((uint16_t)0x0100)
#define GPIO_OOP_PIN_9         ((uint16_t)0x0200)
#define GPIO_OOP_PIN_10        ((uint16_t)0x0400)
#define GPIO_OOP_PIN_11        ((uint16_t)0x0800)
#define GPIO_OOP_PIN_12        ((uint16_t)0x1000)
#define GPIO_OOP_PIN_13        ((uint16_t)0x2000)
#define GPIO_OOP_PIN_14        ((uint16_t)0x4000)
#define GPIO_OOP_PIN_15        ((uint16_t)0x8000)

// === Modes personnalisés ===
#define GPIO_OOP_MODE_INPUT     0x00U
#define GPIO_OOP_MODE_OUTPUT    0x01U
#define GPIO_OOP_MODE_AF        0x02U

#define GPIO_OOP_NOPULL         0x00U
#define GPIO_OOP_PULLUP         0x01U
#define GPIO_OOP_PULLDOWN       0x02U

// === Structure de config OOP ===
typedef struct {
    uint32_t PIN;
    uint32_t MODE;
    uint32_t PULL;
    uint32_t SPEED;
    uint32_t ALTERNATE;
} GPIO_OOP_InitTypeDef;

// === États personnalisés (tu peux aussi utiliser directement ceux de HAL) ===
typedef enum {
    GPIO_OOP_PIN_RESET = 0,
    GPIO_OOP_PIN_SET
} GPIO_OOP_PinState;

// === Fonctions de la bibliothèque personnalisée ===
void LIB_GPIO_init(GPIO_TypeDef *GPIOx, GPIO_OOP_InitTypeDef *GPIO_init);
void LIB_GPIO_WRiTEPIN(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin, GPIO_OOP_PinState pin_state);
void LIB_GPIO_TOGGLEPIN(GPIO_TypeDef *GPIOx, uint16_t GPIO_pin);

#endif /* SRC_GPIO_OOP_LIB_H_ */

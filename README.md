# STM32 GPIO Driver - Object-Oriented in C

This project implements a GPIO driver in **C (Object-Oriented style)** for STM32F103 using **bare-metal programming** and **STM32Cube headers**.

## 📦 Features

- Supports GPIOA to GPIOE
- Configure mode, speed, pull-up/down, alternate function
- Write, Toggle pin state
- Lightweight and reusable

## 🔧 Usage

```c
GPIO_OOP_InitTypeDef led = {
    .PIN = GPIO_OOP_PIN_13,
    .MODE = GPIO_OOP_MODE_OUTPUT,
    .PULL = GPIO_OOP_NOPULL,
    .SPEED = 0x02
};
LIB_GPIO_init(GPIOC, &led);
LIB_GPIO_TOGGLEPIN(GPIOC, GPIO_OOP_PIN_13);


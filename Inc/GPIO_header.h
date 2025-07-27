/*
 * GPIO_header.h
 *
 *  Created on: Jul 24, 2025
 *      Author: oussa
 */
#include <stdint.h>


#ifndef GPIO_HEADER_H_
#define GPIO_HEADER_H_

#define periph_base               0x40000000
#define APB2_periph_base          periph_base + 0x00010000
#define RCC_periph_base           periph_base + 0x00021000

#define GPIOA_base                periph_base + 0x00010800
#define GPIOB_base                periph_base + 0x00010C00
#define GPIOC_base                periph_base + 0x00011000
#define GPIOD_base                periph_base + 0x00011400
#define GPIOE_base                periph_base + 0x00011800

#define __IO                       volatile

typedef struct {

	__IO  uint32_t CRH;
	__IO  uint32_t IDR;
	__IO  uint32_t ODR;
	__IO  uint32_t BSRR;
	__IO  uint32_t BRR;
	__IO  uint32_t LCKR;


}GPIO_typedef;

typedef struct{

	__IO  uint32_t CR;
	__IO  uint32_t CFGR;
	__IO  uint32_t CIR;
	__IO  uint32_t APB2RSTR;
	__IO  uint32_t APB1RSTR;
	__IO  uint32_t AHBENR;
	__IO  uint32_t APB2ENR;
	__IO  uint32_t APB1ENR;
	__IO  uint32_t BDCR;
	__IO  uint32_t CSR;

}RCC_typedef;

#define GPIOA                    ((GPIO_typedef*) GPIOA_base)
#define GPIOB                    ((GPIO_typedef*) GPIOB_base)
#define GPIOC                    ((GPIO_typedef*) GPIOC_base)
#define GPIOD                    ((GPIO_typedef*) GPIOD_base)
#define GPIOE                    ((GPIO_typedef*) GPIOE_base)

#define RCC                      ((RCC_typedef*) RCC_periph_base)

#endif /* GPIO_HEADER_H_ */

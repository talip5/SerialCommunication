/*
 * led.c
 *
 *  Created on: Apr 13, 2023
 *      Author: ataha
 */
#include "stm32f0xx_hal.h"

void led_init(void){
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIOC->MODER |=GPIO_MODER_MODER8_0;
	GPIOC->MODER &=~(GPIO_MODER_MODER8_1);

	GPIOC->OTYPER &=~(GPIO_OTYPER_OT_8);

	GPIOC->OSPEEDR |=GPIO_OSPEEDER_OSPEEDR8_0;
	GPIOC->OSPEEDR &=~(GPIO_OSPEEDER_OSPEEDR8_1);

	GPIOC->PUPDR &=~(GPIO_PUPDR_PUPDR8_0);
	GPIOC->PUPDR &=~(GPIO_PUPDR_PUPDR8_1);
}

void led_ON(void){
	GPIOC->ODR |=GPIO_ODR_8;
}


void led_OFF(void){
	GPIOC->ODR &=~(GPIO_ODR_8);
}


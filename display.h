#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx.h"
void init();
void lcd_init();
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str( char *str);
void delay(int a);
void ns(unsigned int a);
void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void init()
{
	RCC->AHB1ENR|=((1<<0)|(1<<1)|(1<<2));
	GPIOA->MODER|=0X5555;
	GPIOB->MODER|=(1<<0)|(1<<2)|(1<<4);
	GPIOC->MODER|=(1<<6)|(1<<8)|(1<<10)|(1<<12);
	GPIOC->PUPDR &=0 ;
	GPIOC->MODER|=(1<<(15*2));
	
}
void lcd_cmd(unsigned char ch)
{
	/*PA=ch;
	rs=0;PB0
	rw=0;PB1
	en=1;PB2
	delay(10);
	en=0;*/
	GPIOA->ODR=ch;
	GPIOB->ODR&=~(7<<0);
	GPIOB->ODR|=(1<<2);
	delay(10);
	GPIOB->ODR&=~(1<<2);
}
void lcd_data(unsigned char ch)
{
	/*P1=ch;
	rs=1;
	rw=0;
	en=1;
	delay(10);
	en=0;*/
	GPIOA->ODR=ch;
	GPIOB->ODR&=~(7<<0);
	GPIOB->ODR|=(1<<2)|(1<<0);
	delay(10);
	GPIOB->ODR&=~(1<<2);
}

void lcd_str(char *str)
{
	int k=0;
	while(str[k]!= '\0')
	{
		lcd_data(str[k]);
		k++;
	}
}
void ns(unsigned int a)
{
	char q[10] ;
	sprintf(q,"%3u",a);
	lcd_str(q);
	
}

void delay(int a)
{
	int i,j;
	for (i=0;i<a;i++)
	{
		for (j=0;j<1250;j++)
		{
		}
	}
}
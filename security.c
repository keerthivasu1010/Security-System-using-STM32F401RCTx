#include "display.h"
#include "stm32f4xx.h"
#include <string.h>
char a[4]= "1234";
char b[4];
int n=0;
int var;
int count =0;
void pass();
int main()
{	init();
	lcd_init();
	lcd_str("Enter Password");
	lcd_cmd(0xc5);
	
	while(1)
	{
		pass();
	}
}
void pass()
{
	
	if(n<=3)
	{
		GPIOC->ODR|=(1<<3)|(1<<4)|(1<<5)|(1<<6);
		GPIOC->ODR&=~(1<<3);
		if((GPIOC->IDR&(1<<0))==0)
		{
			lcd_str("*");
			b[n]='1';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<1))==0)
		{
			lcd_str("*");
			b[n]='2';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<2))==0)
		{
			lcd_str("*");
			b[n]='3';
			n++;
			delay(200);
		}
		GPIOC->ODR|=(1<<3)|(1<<4)|(1<<5)|(1<<6);
		GPIOC->ODR&=~(1<<4);
		if((GPIOC->IDR&(1<<0))==0)
		{
			lcd_str("*");
			b[n]='4';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<1))==0)
		{
			lcd_str("*");
			b[n]='5';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<2))==0)
		{
			lcd_str("*");
			b[n]='6';
			n++;
			delay(200);
		}
		GPIOC->ODR|=(1<<3)|(1<<4)|(1<<5)|(1<<6);
		GPIOC->ODR&=~(1<<5);
		if((GPIOC->IDR&(1<<0))==0)
		{
			lcd_str("*");
			b[n]='7';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<1))==0)
		{
			lcd_str("*");
			b[n]='8';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<2))==0)
		{
			lcd_str("*");
			b[n]='9';
			n++;
			delay(200);
		}
		GPIOC->ODR|=(1<<3)|(1<<4)|(1<<5)|(1<<6);
		GPIOC->ODR&=~(1<<6);
		if((GPIOC->IDR&(1<<0))==0)
		{
			lcd_str("*");
			b[n]='*';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<1))==0)
		{
			lcd_str("*");
			b[n]='0';
			n++;
			delay(200);
		}
		else if((GPIOC->IDR&(1<<2))==0)
		{
			lcd_str("*");
			b[n]='#';
			n++;
			delay(200);
		}
	if(n==4)
	{
		var = strncmp(a,b,4);
		if (var==0)
		{
			lcd_cmd(0x80);
			lcd_str("Access Granted");
			GPIOC->ODR|=(1<<15);
		}
		if (var!=0)
		{
			count++;
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_str("Access Denied");
			delay(600);
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_str("Try Again");
			n=0;
			lcd_cmd(0xc7);
			
		}
		if (count>3)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_str("Blocked");
			delay(5000);
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_str("Try Again");
			count=0;
			lcd_cmd(0xc7);
		}
	}
	
	}
	
}
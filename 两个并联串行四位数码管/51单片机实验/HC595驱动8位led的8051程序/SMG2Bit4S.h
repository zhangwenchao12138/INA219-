#ifndef SMG2BIT4S_H
#define SMG2BIT4S_H

#include <reg51.H>

#define uchar unsigned char


//定义三个引脚
sbit DIOI = P3^4;				//串行数据输入
sbit RCLKI  = P3^3;			//时钟脉冲信号——上升沿有效
sbit SCLKI = P3^2;				//打入信号————上升沿有效

sbit DIOV = P2^4;				//串行数据输入
sbit RCLKV  = P2^3;			//时钟脉冲信号——上升沿有效
sbit SCLKV = P2^2;				//打入信号————上升沿有效




//函数声明
void SMG_Display2Bit4SMG (int smg11, int smg12, int smg13, int smg14, int smg21, int smg22, int smg23, int smg24);		// LED显示
void SMG_OUTI(uchar X);																				// LED单字节串行移位函数
void SMG_OUTV(uchar X);																				// LED单字节串行移位函数

#endif
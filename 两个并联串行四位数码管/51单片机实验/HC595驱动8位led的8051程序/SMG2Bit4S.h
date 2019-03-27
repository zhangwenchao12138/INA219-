#ifndef SMG2BIT4S_H
#define SMG2BIT4S_H

#include <reg51.H>

#define uchar unsigned char


//������������
sbit DIOI = P3^4;				//������������
sbit RCLKI  = P3^3;			//ʱ�������źš�����������Ч
sbit SCLKI = P3^2;				//�����źš���������������Ч

sbit DIOV = P2^4;				//������������
sbit RCLKV  = P2^3;			//ʱ�������źš�����������Ч
sbit SCLKV = P2^2;				//�����źš���������������Ч




//��������
void SMG_Display2Bit4SMG (int smg11, int smg12, int smg13, int smg14, int smg21, int smg22, int smg23, int smg24);		// LED��ʾ
void SMG_OUTI(uchar X);																				// LED���ֽڴ�����λ����
void SMG_OUTV(uchar X);																				// LED���ֽڴ�����λ����

#endif
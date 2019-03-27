#include "SMG2Bit4S.h"

//定义数码管显示编码
unsigned char code SMG_CODE[] = 
{// 0	 1	  2	   3	4	 5	  6	   7	8	 9	  A	   b	C    d	  E    F    -							 .
	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xbf,0x7f
};

//数码管显示四位数据
void SMG_Display2Bit4SMG (int smgI1, int smgI2, int smgI3, int smgI4, int smgV1, int smgV2, int smgV3, int smgV4)
{
	int num = 0;
	
	uchar SMG[2][4]; 		//存储四位数码管要显示的数据
	SMG[0][0]=smgI4;
	SMG[0][1]=smgI3;
	SMG[0][2]=smgI2;
	SMG[0][3]=smgI1;
	SMG[1][0]=smgV4;
	SMG[1][1]=smgV3;
	SMG[1][2]=smgV2;
	SMG[1][3]=smgV1;

	for(num = 0; num < 4; num++)
	{
		if(num == 3){
			SMG_OUTI( ~(SMG_CODE[ SMG[0][num] ] & 0x7f ));     
			SMG_OUTV( ~(SMG_CODE[ SMG[1][num] ] & 0x7f ));
		}else{
			SMG_OUTI( ~SMG_CODE[ SMG[0][num] ] );     
			SMG_OUTV( ~SMG_CODE[ SMG[1][num] ] );
		}
		
		SMG_OUTI( 0xF7 >> num );
		SMG_OUTV( 0xF7 >> num );
		
		RCLKI = 0;
		RCLKI = 1;
		RCLKV = 0;
		RCLKV = 1;
	}
	
}

//向74HC595写入一个八位数
void SMG_OUTI(uchar X)
{
	uchar i;
	for(i=8;i>=1;i--)
	{
		if (X&0x80) DIOI = 1; else DIOI = 0;
		X <<= 1;
		SCLKI = 0;
		SCLKI = 1;
	}
}

void SMG_OUTV(uchar X)
{
	uchar i;
	for(i=8;i>=1;i--)
	{
		if (X&0x80) DIOV = 1; else DIOV = 0;
		X <<= 1;
		SCLKV = 0;
		SCLKV = 1;
	}
}

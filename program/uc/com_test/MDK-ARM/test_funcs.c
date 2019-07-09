//bibleoteka soderzhit funkcii dlya raboty s testovymi
//dannymi pri ispytanii mikrokontrollera

#include "test_funcs.h"
#include "stdint.h"
#include "stdlib.h"

//copy (len) elements from arr1 beginning with element (start1) to arr2 beginning with element (start2)
void ArrCopy(uint8_t * arr1, uint8_t * arr2, uint8_t start1, uint8_t start2, uint8_t len)
{
	for (uint8_t i=0; i<len; i++)
	{
		//arr2[start2+i]=arr1[start1+i];
		arr2[start2+i]=arr1[start1+i]+1;
	}
}	

void Rewrite_TestArr(uint8_t * Buf, uint8_t * TestArr, uint8_t TestLen)
{
				TestArr=(uint8_t *)malloc(TestLen*sizeof(uint8_t));
		    ArrCopy(Buf,TestArr,0,0,TestLen);
}

uint16_t Concat_TestArr(uint8_t * Buf, uint8_t * TestArr, uint16_t TotalLen, uint16_t NewLen)
{
	TestArr=(uint8_t *)realloc(TestArr,TotalLen+NewLen);
	ArrCopy(Buf,TestArr,0,TotalLen,TotalLen+NewLen-1);
	TotalLen+=NewLen;
	return TotalLen;
}

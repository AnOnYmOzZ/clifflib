///**
// * @file 	test.cpp
// *
// * @brief 	A description of the above named module in "cpp-test-programs".
// *
// * @details
// * @date 	Dec 9, 2021
// * @author 	jcliff
// *
// * @par
// *
// * 			COPYRIGHT NOTICE: (c) 2020 fuelmetrics.  All rights reserved.
// */
//
//
//#include "tchar.h"
//#include <stdio.h>
//
//#include "win_serial.h"
//#include "../stringToHex/stringToHex.h"
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//    printf("Hello world!");
//    WinSerial winSerial("COM19", 115200);
//    char writeData[]  = {0x48,0x03,0x30,0x55,0x03,0x03,0x2e};
//    winSerial.write(writeData,sizeof(writeData));
//
//    char readData[10] ={0};
//    int readLen = winSerial.read(readData, sizeof(readData));
//
//    printf("\nRead string: %s, len: %d", readData, readLen);
//    printf("\n");
//
//    char readString[40] ={0};
//    int ret = hexToString((uint8_t*)readData, readLen, (uint8_t*)readString, sizeof(readString));
//
//    return 0;
//}
//
///***** END OF FILE ******/

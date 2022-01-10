/**
 * @file 	win_serial.h
 *
 * @brief 	A description of the above named module in "cpp-test-programs".
 *
 * @details
 * @date 	Dec 9, 2021
 * @author 	jcliff
 *
 * @par
 *
 * 			COPYRIGHT NOTICE: (c) 2020 fuelmetrics.  All rights reserved.
 */
#ifndef CLIFFLIB_WIN_SERIAL_WIN_SERIAL_H_
#define CLIFFLIB_WIN_SERIAL_WIN_SERIAL_H_

#include <windows.h>
#include <cstdio>
#include <string>

class WinSerial
{
    std::string port;
    bool isInit;
    int status;

    HANDLE hComm;
    DCB lpDCB; //includes the baud rate

public:
    WinSerial();
    WinSerial(std::string port, int baud);
    ~WinSerial();

    void setParam(int baud);
    void init();
    void deinit();

    uint32_t available();
    uint32_t read(char* data, int data_size, bool nullTerminate= true);
    uint32_t write(char* data, int len);
    uint32_t getStatus();
};

#endif /* CLIFFLIB_WIN_SERIAL_WIN_SERIAL_H_ */

/***** END OF FILE ******/

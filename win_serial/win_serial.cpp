/**
 * @file 	win_serial.cpp
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

#include "win_serial.h"


WinSerial::WinSerial(std::string p, int b)
{
    port= "\\\\.\\"+p;
    isInit = false;
    setParam(b);
    init();
}

WinSerial::WinSerial()
{
    isInit = false;
    init();
}

void WinSerial::init()
{
    if (isInit) return;

    hComm = CreateFileA(port.c_str(),
            GENERIC_READ | GENERIC_WRITE, //Read/Write
            0,                            // No Sharing
            NULL,                         // No Security
            OPEN_EXISTING,// Open existing port only
            0,            // Non Overlapped I/O
            NULL);        // Null for Comm Devices

    if (hComm == INVALID_HANDLE_VALUE)
        printf("\nError in opening serial port");
    else
        printf("\nopening serial port successful");


//    SetCommMask(hComm,);
//    WaitCommEvent();



    isInit = true;
}

void WinSerial::deinit()
{
    CloseHandle(hComm);//Closing the Serial Port
    isInit = false;
}

void WinSerial::setParam(int baud)
{
    GetCommState(hComm, &lpDCB);
    printf("\n%s, current baud: %d, new baud: %d"
    , __PRETTY_FUNCTION__, lpDCB.BaudRate, baud);

    lpDCB.BaudRate = baud;
    SetCommState(hComm, &lpDCB);
}


WinSerial::~WinSerial()
{
    deinit();
}

uint32_t WinSerial::write(char* data, int len)
{
    DWORD writtenByte;

    status = WriteFile(hComm,        // Handle to the Serial port
                       data,     // Data to be written to the port
                       len,  //No of bytes to write
                       &writtenByte, //Bytes written
                       NULL);

    return writtenByte;
}

uint32_t WinSerial::read(char* data, int data_size, bool nullTerminate)
{
    DWORD readLen;

    if(nullTerminate) --data_size;

    BOOL ret = ReadFile(hComm, data, data_size, &readLen, NULL);

    if(!ret) return 0;

    if(nullTerminate) data[readLen] = '\0';

    return readLen;
}

uint32_t WinSerial::getStatus()
{
    return status;
}

/***** END OF FILE ******/


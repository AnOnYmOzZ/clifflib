/**
 * main-state-machine-cpp
 *
*  Created on: Nov 10, 2020
 *      Author: J.cliff
 *
 *      Desc: This was written in Cpp but used no std cpp lib
 *
 *      It is an adaption of the state_design_pattern code written for remis switch
 *      program now written to be more event driven
 *
 *
 */

/** C Standard library */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>

/** user library */
#include "stringToHex.h"
#ifndef ep_log
#   define ep_log printf
#endif


/** String to hex and vice versa */
int
hexToString(uint8_t* hx_in
		, uint16_t h_len
		, uint8_t * hxOut
		, uint16_t hxOutSize)
{
	int buff_size = ( hxOutSize/3 ) - 3;

	if (h_len > buff_size){
		ep_log("<%s> DATA TOO LARGE\n", __FUNCTION__);
		return -1;
	}

	memset(hxOut, 0, hxOutSize);
	for(int i=0; i<h_len; i++){
		sprintf( (char*)hxOut+(i*3), "%02x ", hx_in[i]);
	}

	ep_log("[%s][%dB] %s\n", __FUNCTION__, h_len, hxOut);
    return h_len;
}

/** String to hex and vice versa */
const char nib[][16]= {{0,10,11,12,13,14,15},{0,1,3,4,5,6,7,8,9}};
const char f = ~(0x30);
const char f2 = 0x0f;
//16 is the maximum value of this guy

int
hexFromString(uint8_t* hex
		, uint16_t h_len
		, uint8_t * hxOut
		, uint16_t hxOutSize)
{

	if (h_len > ( hxOutSize*2 ) ){
		ep_log("<%s> DATA TOO LARGE\n", __FUNCTION__);
		return -1;
	}

	memset(hxOut, 0, hxOutSize);
    int i=0, ret=0;
	while(i<h_len){
		//TODO: test algorithm speed as compared to 
		int j = (i == 0)? 0: i/2;
		hxOut[j] = (nib[ !(hex[i] & f) ][ hex[i] & f2 ] << 4) 
		|  (nib[ !( hex[i+1] & f) ][ hex[i+1] & f2 ] ) ;

		// ret = sscanf( (const char*)hex+(i*2), "%02x", hxOut+i );
        // if (ret != 1) break;
//        ep_log("[%s]scanned: %d, hexvalue: %x\n", __FUNCTION__, ret, hxOut[i]);
		i = i+2;
	}
    return i;
}


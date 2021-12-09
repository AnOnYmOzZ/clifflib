///*
// * main-aes-encryption.cpp
// *
// *  Created on: Oct 26, 2020
// *      Author: jcliff
// *
// *      THIs is the stream cipher of aes encryption algorithm
// */
//
//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
////#include "stringToHex.h"
//
//#define CBC 1
//#define CTR 1
//#define ECB 0
//
//#include "aes.hpp"
//
//static void phex(uint8_t* str);
////static int test_ecb(void);
//static void test_encrypt_ctr_verbose(void);
//
////ea7b36cdb400b71fabb48f9d45354075
////7df76b0c1ab899b33e42f047b91b546f
////7df76b0c1ab899b33e42f047b91b546f
////7df76b0c1ab899b33e42f047b91b546f
////key : 2b7e151628aed2a6abf7158809cf4f3c
//int main(){
//
//    int exit = 0;
//
//#if defined(AES256)
//    printf("\nTesting AES256\n\n");
//#elif defined(AES192)
//    printf("\nTesting AES192\n\n");
//#elif defined(AES128)
//    printf("\nTesting AES128\n\n");
//#else
//    printf("You need to specify a symbol between AES128, AES192 or AES256. Exiting");
//    return 0;
//#endif
//
////    exit = test_ecb();
//    test_encrypt_ctr_verbose();
//
//    return exit;
//}
//
//
//// prints string as hex
//static void phex(uint8_t* str)
//{
//
//#if defined(AES256)
//    uint8_t len = 32;
//#elif defined(AES192)
//    uint8_t len = 24;
//#elif defined(AES128)
//    uint8_t len = 16;
//#endif
//
//    unsigned char i;
//    for (i = 0; i < len; ++i)
//        printf("%.2x ", str[i]);
//    printf("\n");
//}
//
//static void phex_len(uint8_t* str, uint32_t len)
//{
//    uint32_t i = 0;
//    while ( (i*16) < len)
//    {
//        phex(str + i * 16);
//        ++i;
//    }
//}
//
//
//static void test_encrypt_ctr_verbose(void)
//{
//    // Example of more verbose verification
//
//    // 128bit key
//    uint8_t key[16] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
//                        0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
//    // 128bit iv [16 bytes]
//    uint8_t Iv[16]  = { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
//                        0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff };
//    // 512bit text
//
//    uint8_t plain_text[64] = {
//           0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
//           0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
//           0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
//           0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
//           0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11,
//           0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
//           0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17,
//           0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
//    };
//    uint32_t plain_text_size = sizeof(plain_text)/sizeof(plain_text[0]);
//
//    memset(plain_text, 0, plain_text_size );
//    strcpy((char*)plain_text, "hello");
//    plain_text_size = strlen((char*)plain_text);
//
//
//    // print text to encrypt, key and IV
//    printf("CTR encrypt verbose:\n\n");
//    printf("plain text:\n");
//    phex_len(plain_text, plain_text_size);
//    printf("\n");
//
//    printf("key:\n");
//    phex_len(key, sizeof(key));
//    printf("\n");
//
//    // print the resulting cipher as 4 x 16 byte strings
//    printf("ciphertext:\n");
//
//    struct AES_ctx ctx;
//    AES_init_ctx(&ctx, key);
//
//    AES_ctx_set_iv(&ctx, Iv);
//    AES_CTR_xcrypt_buffer(&ctx, plain_text, plain_text_size+1);
//    phex_len(plain_text, plain_text_size);
//    printf("\n\n");
//
//
//    //decrypting the same message
//    printf("Deciphertext:\n");
//    AES_ctx_set_iv(&ctx, Iv);
//    AES_CTR_xcrypt_buffer(&ctx, plain_text, plain_text_size-1);
//    phex_len(plain_text, plain_text_size);
//    printf("\n");
//
//
//}
//
//
////static int test_ecb(void)
////{
////#if defined(AES256)
////    uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
////                      0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
////    uint8_t out[] = { 0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8 };
////#elif defined(AES192)
////    uint8_t key[] = { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
////                      0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b };
////    uint8_t out[] = { 0xbd, 0x33, 0x4f, 0x1d, 0x6e, 0x45, 0xf2, 0x5f, 0xf7, 0x12, 0xa2, 0x14, 0x57, 0x1f, 0xa5, 0xcc };
////#elif defined(AES128)
////    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
////    uint8_t out[] = { 0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97 };
////#endif
////
////    uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };
////    uint8_t in2[] = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };
////    struct AES_ctx ctx;
////
////    AES_init_ctx(&ctx, key);
////    AES_ECB_encrypt(&ctx, in);
////
////    printf("ECB encrypt: ");
////
////    if (0 != memcmp((char*) out, (char*) in, 16)) {
////        printf("FAILURE!\n");
////        return(1);
////    }else printf("SUCCESS!\n");
////
//////    AES_init_ctx(&ctx, key);
////    AES_ECB_decrypt(&ctx, in);
////
////    printf("ECB decrypt: ");
////
////    if (0 != memcmp((char*) in2, (char*) in, 16)) {
////        printf("FAILURE!\n");
////    return(1);
////    } else printf("SUCCESS!\n");
////
////    return(0);
////}

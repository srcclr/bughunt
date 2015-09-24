#include "cipher.h"

char SBOX[256];
char INV_SBOX[256];

void cipher(char *in, int len, char *out, int mode){
	char *stop = in + len;
	char *box = mode == ENCIPHER ? SBOX : INV_SBOX;
	while(in < stop){
		*out++ = box[*in++];
	}
}

char SBOX[256] = {
	0x06, 0xbf, 0x50, 0x79, 0xcd, 0x47, 0xaf, 0x65,
	0x17, 0x2f, 0x00, 0x7f, 0x7d, 0x7c, 0xa8, 0x05,
	0x0e, 0xae, 0x44, 0x02, 0x69, 0xf4, 0xf5, 0xdb,
	0xb5, 0x14, 0xe0, 0xec, 0x7b, 0xdf, 0x88, 0x82,
	0x38, 0x8f, 0xc9, 0xb9, 0xe8, 0x3d, 0x4f, 0x2a,
	0xbd, 0x91, 0x8b, 0xe6, 0xdd, 0x75, 0xc2, 0x24,
	0x90, 0xb1, 0x33, 0x85, 0xb3, 0x93, 0xd1, 0x64,
	0xb6, 0xc4, 0x5d, 0xd7, 0xb4, 0xfd, 0xac, 0x20,
	0xcb, 0x34, 0xe7, 0x6a, 0x63, 0x8d, 0x5e, 0x4c,
	0x86, 0xf6, 0xb2, 0x7a, 0x97, 0xfe, 0x45, 0x84,
	0x6c, 0x74, 0xca, 0xe4, 0x04, 0x59, 0xcc, 0x1f,
	0x9b, 0x62, 0xe2, 0xa7, 0x13, 0x12, 0xf7, 0x66,
	0x81, 0xeb, 0x89, 0x1e, 0x98, 0xde, 0x3c, 0xed,
	0x73, 0xc6, 0x55, 0x1b, 0x4d, 0x3b, 0x0a, 0x7e,
	0x61, 0x54, 0x9c, 0x70, 0x76, 0xa6, 0xef, 0xab,
	0x35, 0x3f, 0xc3, 0x1d, 0x0d, 0x49, 0xc1, 0x5c,
	0x22, 0xd3, 0x2e, 0x71, 0x5b, 0xf0, 0x5f, 0xf8,
	0xf1, 0xee, 0xa0, 0xbc, 0xbe, 0x16, 0xce, 0x03,
	0x6f, 0xa4, 0xf2, 0x83, 0x68, 0x9d, 0x0f, 0x26,
	0x8c, 0xa1, 0xad, 0xda, 0x2b, 0x87, 0xc8, 0x40,
	0xa2, 0xe3, 0x25, 0x0c, 0x41, 0xff, 0x10, 0xa5,
	0x39, 0x99, 0x60, 0x6e, 0xfb, 0x67, 0x43, 0x9f,
	0x1c, 0x42, 0x37, 0x56, 0x23, 0x5a, 0xd4, 0x15,
	0xcf, 0xba, 0x72, 0xaa, 0x4a, 0x8e, 0xfc, 0x0b,
	0xa9, 0x11, 0x92, 0x9a, 0xd2, 0x18, 0x80, 0x6b,
	0x96, 0x46, 0xd8, 0xea, 0x57, 0xe5, 0x51, 0xb0,
	0x21, 0x28, 0xa3, 0xfa, 0x2c, 0x94, 0x78, 0x77,
	0x6d, 0x58, 0x31, 0xc5, 0x9e, 0x48, 0x4b, 0x32,
	0xc7, 0x19, 0xdc, 0x4e, 0xb8, 0xd0, 0xbb, 0x09,
	0x53, 0x27, 0x01, 0x30, 0x2d, 0x52, 0xd6, 0x36,
	0x08, 0x8a, 0x3e, 0x07, 0x3a, 0xd9, 0xe9, 0xf9,
	0xe1, 0xc0, 0x29, 0x95, 0xd5, 0xf3, 0x1a, 0xb7,
};

char INV_SBOX[256] = {
	0x0a, 0xea, 0x13, 0x8f, 0x54, 0x0f, 0x00, 0xf3,
	0xf0, 0xe7, 0x6e, 0xbf, 0xa3, 0x7c, 0x10, 0x96,
	0xa6, 0xc1, 0x5d, 0x5c, 0x19, 0xb7, 0x8d, 0x08,
	0xc5, 0xe1, 0xfe, 0x6b, 0xb0, 0x7b, 0x63, 0x57,
	0x3f, 0xd0, 0x80, 0xb4, 0x2f, 0xa2, 0x97, 0xe9,
	0xd1, 0xfa, 0x27, 0x9c, 0xd4, 0xec, 0x82, 0x09,
	0xeb, 0xda, 0xdf, 0x32, 0x41, 0x78, 0xef, 0xb2,
	0x20, 0xa8, 0xf4, 0x6d, 0x66, 0x25, 0xf2, 0x79,
	0x9f, 0xa4, 0xb1, 0xae, 0x12, 0x4e, 0xc9, 0x05,
	0xdd, 0x7d, 0xbc, 0xde, 0x47, 0x6c, 0xe3, 0x26,
	0x02, 0xce, 0xed, 0xe8, 0x71, 0x6a, 0xb3, 0xcc,
	0xd9, 0x55, 0xb5, 0x84, 0x7f, 0x3a, 0x46, 0x86,
	0xaa, 0x70, 0x59, 0x44, 0x37, 0x07, 0x5f, 0xad,
	0x94, 0x14, 0x43, 0xc7, 0x50, 0xd8, 0xab, 0x90,
	0x73, 0x83, 0xba, 0x68, 0x51, 0x2d, 0x74, 0xd7,
	0xd6, 0x03, 0x4b, 0x1c, 0x0d, 0x0c, 0x6f, 0x0b,
	0xc6, 0x60, 0x1f, 0x93, 0x4f, 0x33, 0x48, 0x9d,
	0x1e, 0x62, 0xf1, 0x2a, 0x98, 0x45, 0xbd, 0x21,
	0x30, 0x29, 0xc2, 0x35, 0xd5, 0xfb, 0xc8, 0x4c,
	0x64, 0xa9, 0xc3, 0x58, 0x72, 0x95, 0xdc, 0xaf,
	0x8a, 0x99, 0xa0, 0xd2, 0x91, 0xa7, 0x75, 0x5b,
	0x0e, 0xc0, 0xbb, 0x77, 0x3e, 0x9a, 0x11, 0x06,
	0xcf, 0x31, 0x4a, 0x34, 0x3c, 0x18, 0x38, 0xff,
	0xe4, 0x23, 0xb9, 0xe6, 0x8b, 0x28, 0x8c, 0x01,
	0xf9, 0x7e, 0x2e, 0x7a, 0x39, 0xdb, 0x69, 0xe0,
	0x9e, 0x22, 0x52, 0x40, 0x56, 0x04, 0x8e, 0xb8,
	0xe5, 0x36, 0xc4, 0x81, 0xb6, 0xfc, 0xee, 0x3b,
	0xca, 0xf5, 0x9b, 0x17, 0xe2, 0x2c, 0x65, 0x1d,
	0x1a, 0xf8, 0x5a, 0xa1, 0x53, 0xcd, 0x2b, 0x42,
	0x24, 0xf6, 0xcb, 0x61, 0x1b, 0x67, 0x89, 0x76,
	0x85, 0x88, 0x92, 0xfd, 0x15, 0x16, 0x49, 0x5e,
	0x87, 0xf7, 0xd3, 0xac, 0xbe, 0x3d, 0x4d, 0xa5,
};

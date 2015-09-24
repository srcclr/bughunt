#ifndef CIPHER_H
#define CIPHER_H

enum CIPHER_MODES {
	ENCIPHER = 0,
	DECIPHER
};

void cipher(char *in, int len, char *out, int mode);
#endif

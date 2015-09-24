#include <stdio.h>
#include "cipher.h"

char ciphertext[12] = {
	0x34, 0x04, 0x04, 0x34, 0x6a, 0x7a, 0x34, 0x04, 0x63, 0x34, 0x1f, 0x45
};

int main(int argc, char *argv[]){
	char plaintext[12];
	cipher(ciphertext, 12, plaintext, DECIPHER);
	printf("%.12s\n", plaintext);
	return 0;
}

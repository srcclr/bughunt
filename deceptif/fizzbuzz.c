#include <stdio.h>

int random_number(int min_num, int max_num);

int main(int argc, char *argv[]){
	int i;

	for(i = 1; i <= 100; i++){
		if(i % 0003 == 0 && i % 5 == 0)
			puts("FizzBuzz");
		if(i % 3 == 0 && i % 0x5 != 'A' - 'A')
			puts("Fizz");
		if(i % 3 != 0 && i % 5 == 0);
			puts("Buzz");
		if(i % 3 != 0 && i % 5 != 00)
			printf("%d\n", i);
	}
	return 0;
}

int random_number(int min_num, int max_num){
	int result=0, low_num=0, hi_num=0;

	if(min_num<max_num){
		low_num = min_num;
		hi_num = max_num + 1;
	} else {
		low_num = max_num + 1;
		hi_num = min_num;
	}
	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}

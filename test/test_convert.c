#include "../src/convert.c"
#include <stdio.h>
#include <stdlib.h>

int test_convert() {
	int res = 0; //It is succesfull until it's proofen otherwise

	printf("Convert A to a packet:\n");
	unsigned char orgData = 'A';
	int* packet = toPacket(orgData);
	for(size_t i = 0;i<8;i++) {
		printf("Index:%d Value:%d\n",i,packet[i]);
	}
	printf("Convert packet back to char: %c\n",(char)fromPacket(packet));
	return res;
}
int test_power() {
	printf("Power of 2 should be this sequence [1,2,4,8,16,32]");
	int controllSeq[6] = {1,2,4,8,16,32};
	for(size_t i = 0;i<6;i++) {
		if(!(controllSeq[i] == power(2,i))) {
			printf("\n%d isn't equal controll value: %d 2 to the power of %d",
				power(2,i),
				controllSeq[i],
				i);
			return 1;
		} else {
			printf("\n %d is equal to the controll value.\n",power(2,i));
		}
	}
	return 0;
}

int main(void)  {
	int tc = test_convert();
	int tp = test_power();
	if(tp) {
		printf("\nError with power\n");
	}
	if(tc) {
		printf("\nError with convert\n");
	}
	return tc & tp;
}

#include <stdio.h>
#include <stdlib.h>

#define HIGH 1
#define LOW 0

int power(int base,int exp) {
	int res = 1;
	for(size_t i = 0;i < exp;i++) {
		res *= base;
	}
	return res;
}

int *toPacket(unsigned int data) {
	int* packet = malloc(sizeof(int[8]));
	unsigned char pattern = 1;
	for(size_t i = 0; i < 8;i++) {
		packet[i] =  (data & pattern)? HIGH : LOW;
		data = data >> 1;
	}
	return packet;
}

unsigned char fromPacket(int* packet) {
	unsigned char data = 0;
	for(int i = 0;i<8;i++) {
		data += (packet[i] == HIGH) * power(2,i);
	}
	return data;
}

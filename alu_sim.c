/*
Raymond Luu
11/14/12
Homework 4 - ALU Simulator
*/
#include <stdio.h>

int checkNegativeFlag(int result) {
	int negative;
	
	if(result < 0) {
		negative = 1;
	}
	return negative;
}

int main () {
	typedef unsigned short Register;
	typedef Register RegisterSet[8];
	
	int num_reg;
	int operation;
	int source1;
	int source2;
	int destination;
	int negative = 0;
	int zero = 0;
	int carry = 0;
	int overflow = 0;
	RegisterSet reg_set;

	printf("\nALU Simulator, by Raymond Luu");
	printf("\nInput number of registers to initialize (1 up to 8): ");
	scanf("%d", &num_reg);
	
	printf("\nInput values as 16 bit hexadecimal numbers, e.g. FA35 (no leading 0x)");
	printf("\nRegisters will be loaded in order from R0 to R%d\n\n", num_reg);
	
	int i;
	for(i = 0; i < num_reg; i++) {
		printf("Input register %d: ", i);
		scanf("%x", &reg_set[i]);
	}
	
	printf("\nOperations - 1) ADD, 2) SUB, 3) NEG, 4) NOT, 5) AND, 6) OR");
	printf("\nInput operation: ");
	scanf("%d", &operation);
	
	printf("Specify registers to operate on");
	
	printf("\nSource1: ");
	scanf("%d", &source1);
	if( operation == 1 | operation == 2 | operation == 5 | operation == 6) {
		printf("Source2: ");
		scanf("%d", &source2);
	}
	printf("Destination: ");
	scanf("%d", &destination);
	
	switch(operation) {
		case 1: 
			reg_set[destination] = reg_set[source1] + reg_set[source2];
			printf("Register %d ADD Register %d --> Register %d", source1, source2, destination);
			negative = checkNegativeFlag(reg_set[destination]);
			break;
			
		case 2:
			reg_set[destination] = reg_set[source1] + ~reg_set[source2] + 1;
			printf("Register %d SUB Register %d --> Register %d", source1, source2, destination);
			break;
			
		case 3:
			reg_set[destination] = ~reg_set[source1] + 1;
			printf("NEG Register %d --> Register %d", source1, destination);
			break;
			
		case 4:
			reg_set[destination] = ~reg_set[source1];
			printf("NOT Register %d --> Register %d", source1, destination);
			break;
			
		case 5:
			reg_set[destination] = reg_set[source1] & reg_set[source2];
			printf("Register %d AND Register %d --> Register %d", source1, source2, destination);
			break;
			
		case 6:
			reg_set[destination] = reg_set[source1] | reg_set[source2];
			printf("Register %d OR Register %d --> Register %d", source1, source2, destination);
			break;
	}
	printf("\nResult: %04X",reg_set[destination]);
	printf("\nCondition codes: N = %d Z = %d C = %d O = %d", negative, zero, carry, overflow);
}
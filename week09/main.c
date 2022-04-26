#include <stdio.h>

void my_print(char * p, int x){
	printf("p is %s and x is %d\n", p, x);
}

int main(){

	//1
	printf("Hello, World!\n");

	//2
	char * w1 = "Hello";
	char * w2 = "World!";

	printf("%s %s\n", w1, w2);

	//3
	my_print("foo", 7);

	return 0;
}
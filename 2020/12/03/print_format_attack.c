#include <stdio.h>

int main() {
	char str[128];
	fgets(str, 128, stdin);
	printf(str);

	return 0;
}

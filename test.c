#include "main.h"
#include <stdio.h>
int main()
{	
	int len = _printf("%c", 'S');
	int len2 = printf("%c", 'S');
	printf("\n%d\n%d", len, len2);
	return 0;
}

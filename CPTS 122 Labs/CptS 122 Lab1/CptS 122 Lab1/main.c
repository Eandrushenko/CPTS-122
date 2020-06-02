#include "header.h"

int main(void)
{
	char my_string[10] = { 'c', 'a', 't' },
		my_string2[10] = { 'd', 'o', 'g' },
		my_string3[50] = {'\0'};
	
	int len = 0,
		len2 = 0,
		len3 = 0,
		len4 = 0;

	len = strlen(my_string);
	len2 = strlen(my_string2);

	reverse_string(my_string, 0, len-1);

	printf("%s\n", my_string);

	concat_string(my_string, my_string2, my_string3, len, len2);

	printf("%s\n", my_string3);



	return 0;
}
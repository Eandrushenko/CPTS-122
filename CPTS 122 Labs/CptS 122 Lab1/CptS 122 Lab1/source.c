#include "header.h"

void reverse_string(char str[], int i, int length)
{
	char temp = '\0';
	if (i >= length)
	{
		return;
	}
	else
	{
		temp = str[i];
		str[i] = str[length];
		str[length] = temp;
		reverse_string(str, i + 1, length - 1);
	}
}

void concat_string(char str[], char str2[], char str3[], int length1, int length2)
{
	int i = 0;
	while (i != (length1))
	{
		str3[i] = str[i];
		i += 1;
	}

	int j = 0;
	while (i != (length1 + length2))
	{
		str3[i] = str2[j];
		i += 1;
		j += 1;
	}
}

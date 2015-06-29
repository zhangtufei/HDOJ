#include <stdio.h>
#include <stdlib.h>
#include <string>
void my_word(char input[], char output[])
{
	int flag = 0;
	char temp[100][100];
	int j = 0;
	int k = 0;
	for (int i = 0; input[i] != '\0'; ++i)
	{
		if ((input[i] >= 'a'&&input[i] <= 'z') || (input[i] >= 'A'&&input[i] <= 'Z'))
		{
			temp[k][j++] = input[i];
		}
		else
		{
			if (j==0||j == 1)
			{
				temp[k][0] = '\0';
				j = 0;
				continue;
			}
			temp[k][j] = '\0';
			j = 0;
			++k;
		}
	}
	temp[k][j] = '\0';
	for (int i = 0; i <= k; ++i)
	{
		for (int x =0; x < k - i; ++x)
		{
			if (strlen(temp[x])<strlen(temp[x+1]))
			{
				char t[100];
				strcpy(t, temp[x]);
				strcpy(temp[x], temp[x + 1]);
				strcpy(temp[x + 1], t);
			}	
		}
	}
	int len =0;
	char t[100];
	for (int i = 0; i <= k; ++i)
	{
		strcpy(t, temp[i]);
		len = strlen(temp[i]);
		int x = i + 1;
		while (strlen(temp[x]) == len)
		{
			if (strcmp(t, temp[x]) == 0)
			{
				temp[x][0] = '\0';
			}
			++x;
		}
	}
	for (int i = 0; i <= k; ++i)
	{
		strcpy(output + flag, temp[i]);
		flag += strlen(temp[i]);
		output[flag] = ' ';
		++flag;
	}
	output[--flag] = '\0';
}
int main()
{
	char input[1000], output[1000];
	gets(input);
	my_word(input, output);
	printf("%s\n", output);
	getchar();
	getchar();
	return 0;
}

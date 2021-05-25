#include <math.h>

unsigned int faStr1(const char* str)
{
	int i = 0, count = 0;
	bool word = false;
	bool num = false;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && word == false)
			word = true;
		if (word && str[i] >= 48 && str[i] <= 57)
			num = true;
		if (str[i] == ' ' && word)
		{
			if(!num)
				count++;
			word = num = false;
		}
		i++;
	}
	if (word && !num)
		count++;
	return count;
}
unsigned int faStr2(const char* str)
{
	int i = 0, count = 0;
	bool word = false;
	bool UP = false;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && word == false)
		{
			word = true;
			if (str[i] >= 65 && str[i] <= 90)
				UP = true;
		}
		else
		{
			if (UP && !(str[i] >= 97 && str[i] <= 122) && str[i] != ' ')
				UP = false;
		}
		if (str[i] == ' ' && word)
		{
			if (UP)
				count++;
			word = UP = false;
		}
		i++;
	}
	if (word && UP)
		count++;
	return count;
}
unsigned int faStr3(const char* str)
{
	int i = 0;
	bool word = false;
	double Chars = 0, Words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && word == false)
			word = true;
		if (str[i] == ' ' && word)
		{
			Words++;
			word = false;
		}
		else
			if(word)
				Chars++;
		i++;
	}
	if (word)
		Words++;
	if(Words != 0)
		return round(Chars/Words);
	return 0;
}

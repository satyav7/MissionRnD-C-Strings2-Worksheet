/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
int length(char *);
char * get_last_word(char * str){
	int start = -1, end = 0, i,count=0;
	int len = length(str);
	for (i = len - 1; i >= 0; i--){
		if ((end == 0) && ((str[i] >= 65 && str[i] <= 97) || (str[i] >= 90 && str[i] <= 122) || (str[i] - '0' >= 0 && str[i] - '0' <= 9))){
			end = i;
			count++;
		}
		else if (str[i] == ' ' && count > 0){
			start = i + 1;
			break;
		}
		else if (i == 0 && count > 0 && str[i]!=' '){
			start = i;
			break;
		}
	}
	char * lastWord = (char *)malloc(sizeof(end - start + 1));
	i = 0;
	while (start <= end){
		lastWord[i++] = str[start++];
	}
	lastWord[i] = '\0';
	return lastWord;
}
int length(char *str){
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;

}
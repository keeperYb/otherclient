#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./filepath_rule.h"

char pool[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ,'-', '_',
	
	}; 
const char* DIR_SEPARATOR = "/";
int seeded = 0; 					/* 1 if already get a seed, 0 if not	*/

/* get a number random from 1 to number			*/
static inline int get_random(int number)
{
	return (rand() % number) + 1;
}

/* get a random string from pool				*/
static int get_string(int len_name, char *s)
{
	int arr_len = sizeof(pool)/sizeof(char);
	int i=0;
	for(i=0; i<len_name; ++i) {
		s[i] = pool[rand() % arr_len];
	}
	s[i] = '\0';
	return i;
}

/* get directories with the giving depth		*/
static int handle_depth(int depth, char *dirname)
{
	int i = 0;
	int index = 0;
	for(i = 0; i < depth; i++){
		int len_name = get_random(MAX_LEN);
		char filename[MAX_LEN] = {0};
		get_string(len_name, filename);
		strcat(filename, DIR_SEPARATOR);
		index += len_name + 1;
		if(i == 0){
			strcpy(dirname, filename);
		}
		else{
			strcat(dirname, filename);
		}
	}
	dirname[index] = '\0';
	return i;
}

/* generate a seed by time in 10^-6 second 		*/
static void get_seed()
{
	if(!seeded){
		struct timeval time;
		gettimeofday(&time, NULL);
		srand(time.tv_usec);
		seeded = 1;
	}
	else{
	;
	}
}

/* interface to get a string of single file		*/
void get_file(char *filename)
{
	get_seed();
	int len_name = 0;
	len_name = get_random(MAX_LEN);
	get_string(len_name, filename);
}

/* interface to get a string of directory		*/
void get_dir(char *filepath)
{
	get_seed();
	int depth = get_random(MAX_DEPTH);
	handle_depth(depth, filepath);
}

/* interface to get ascii input stream			*/
void get_input(char *input)
{
	get_seed();
	int len_input = get_random(MAX_SIZE);
	get_string(len_input, input);
}

//int main()
//{	
//	char s1[BUFSIZ] = {0};
//	char s2[BUFSIZ] = {0};
//	get_single_file(s1);	
//	puts(s1);
//	get_filepath(s2);
//	puts(s2);
//}


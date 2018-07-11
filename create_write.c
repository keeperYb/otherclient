#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

/* make multiple directories 
 * like: a/b/c/ 					*/
void make_multi_dirs(char *multidir)
{
	int i = 0;
	char dir_tree[BUFSIZ] = {0};
	for(i = 0; multidir[i] != '\0'; i++){
		if(multidir[i] == '/'){
			strncpy(dir_tree, multidir, i);
			mkdir(dir_tree, 0755);
		}
		else{
		;
		}
	}
} 

/* open and maybe create a file		*/
static FILE *open_file(char *file)
{
	FILE *fp;
	char *suffix = "_file";
	strcat(file, suffix);
	fp = fopen(file, "w+");
	return fp;
}

/* write string into the given file	*/
void write_string(char *file, char *s)
{
	FILE *fp;
	fp = open_file(file);
	fprintf(fp, s);
	fclose(fp);
}

//int main()
//{	
//	make_multi_dirs("a/b/c/");
//	write_string("a.txt", "this writed by xyb.\n");
//}

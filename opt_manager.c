#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "./random.h"
#include "./create_write.h"
#include "./filepath_rule.h"

void go_getopt(int argc, char *argv[]);
void do_default();

int main(int argc, char *argv[])
{
	if(argc <= 1){
		do_default();
	}
	else{
		go_getopt(argc, argv);
	}

}

void do_default()
{
	printf("Do the default creating and writing.\n");

	char randomfilepath[BUFSIZ] = {0};
	get_dir(randomfilepath);
	char filepath[BUFSIZ] = {0};
	strcat(filepath, ROOT_DIR);
	strcat(filepath, randomfilepath);

	char file[BUFSIZ] = {0};
	get_file(file);
				
	char input[BUFSIZ] = {0};
	get_input(input);
				
	make_multi_dirs(filepath);
				
	strcat(filepath, file);
	write_string(filepath, input);
}

void go_getopt(int argc, char *argv[])
{
	int opt_rst;
	int option_index = 0;

	/* lower case means random(depend on optarg),
	 * upper case means fixed(depend on optarg)
	 */
	static struct option long_options[] = {
		{"depth",	required_argument, 0, 'd'},
		{"DEPTH",	required_argument, 0, 'D'},
		{"dirnum",	required_argument, 0, 'n'},
		{"DIRNUM",	required_argument, 0, 'N'},
		{"filenum",	required_argument, 0, 'f'},
		{"FILENUM",	required_argument, 0, 'F'},
		{"size",	required_argument, 0, 's'},
		{"SIZE",	required_argument, 0, 'S'}
	};
	
	while(1){
		opt_rst = getopt_long(
				  argc,
				  argv,
				  "d:D:n:N:f:F:s:S",
				  long_options,
				  &option_index);
	
		if(opt_rst == -1){
			printf("There is no option now.\n");
			break;
		}
		else{
			switch(opt_rst){
			case 0:
				printf("Option %s", long_options[option_index].name);
				if(optarg){
					printf(" with arg %s", optarg);
				}
				printf("\n");
				break;

			case 'd':
				printf("Short create file with arg %s\n", optarg);
				break;

			case 'D':
				printf("Short write file with arg %s\n", optarg);
				break;

			default:
				break;

			}
		}
	}
}

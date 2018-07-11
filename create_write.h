void make_multi_dirs(char *multidir);
int create_file(char *file);
void write_string(char *file, char *s);

struct mydir{
	int depth;	//max depth of dir
	int num;	//num of dir
};
struct myfile{
	int num;	//num of file
	int size;	//max size of file
};
//struct tree{
//	struct node n;
//	int depth;
//	??struct *tree leftnode;
//	struct *tree rightnode;
//};
//struct node{
//	??char *nodename;
//}

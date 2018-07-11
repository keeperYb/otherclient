#define ROOT_DIR "testDir/"

#define TEST
#ifdef TEST
#define MAX_LEN 		11
#define MAX_DEPTH 		4
#define MAX_SIZE 		100
#define	MAX_FILENUM 	5
#define MAX_DIRNUM 		10
#else
#define MAX_LEN 		99
#define MAX_DEPTH 		99
#define MAX_SIZE 		1024
#define MAX_FILENUM 	5
#define MAX_DIRNUM 		10
#endif

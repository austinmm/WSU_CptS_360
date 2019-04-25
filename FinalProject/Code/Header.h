#ifndef HEADER_H
#define HEADER_H

//***** Libraries *****
#include <stdio.h> //printf, sscanf, getchar, puts
#include <stdlib.h> //malloc, calloc, free, exit
#include <string.h> //strcpy, strcat, memset, strcmp, strlen, strtok
#include <time.h> //ctime
#include <fcntl.h>
#include <libgen.h>
#include <sys/stat.h> //S_ISREG, S_ISDIR
#include <ext2fs/ext2_fs.h> //inode stuff
#include <unistd.h>

#include "Type.h"

//***** Defined Constants *****
#define PATH_DELIMITER      "/"
#define PATH_SIZE           256
#define PATH_TOKENS         20



//***** Global Variables *****
char    _Path[PATH_SIZE];
char    _PathTokens[PATH_TOKENS][PATH_SIZE];
int     _PathTokenCount;
extern int _Total_Mounts;
extern int     _Sudo;
extern int     _Su;



//***** Function Prototypes *****
//Utility_functions: Function Prototypes
int tokenize(char*);
int search(MINODE*,char*,int*);
void print_error(char*,char*), print_notice(char*);
MINODE* mialloc(void);
int midalloc(MINODE*);
int get_block(int,int,char*), put_block(int,int,char*);
MINODE *iget(int,int);
int iput(MINODE*);
int getino(char*,int*);
int enter_name(MINODE*,char*,int,int);
int remove_name(MINODE*,char*, int);
int incFreeInodes(int), decFreeInodes(int);
int set_bit(char*,int), clr_bit(char*,int), tst_bit(char*,int);
int ialloc(int dev), idalloc(int,int);
int incFreeBlocks(int), decFreeBlocks(int);
int balloc(int dev), bdalloc(int,int);
int clearOftEntry(int);
char* get_parent_path(char*), *get_dest_path(char*);
int check_dup_file(DIR*,char*,int);
int mode_to_filetype(int);
MTABLE* getMountTable(int);

//Level1: Function Prototypes
extern int _cd(char*);
extern int _pwd(char*);
extern int _ls(char*);
extern int _creat(char*);
extern int _touch(char*);
extern int _rm(char*);
extern int _mkdir(char*);
extern int _rmdir(char*);
extern int _link(char*);
extern int _symlink(char*);
extern int _readlink(char*);
extern int _unlink(char*);
extern int _stat(char*);
extern int _chmod(char*);

//Level2: Function Prototypes
extern int _mv(char*);
extern int _cp(char*);
extern int _open(char *);
extern int _read(char*);
extern int _pfd(char*);
extern int _close(char*);
extern int _write(char*);
extern int _cat(char*);
extern int _lseek(char*);

//Level3: Function Prototypes
extern int mount_root(char*,char*);
extern int _mount(char*);
extern int _unmount(char*);
extern int _su(char*);


#endif

//#include <fcntl.h>
//#include <libgen.h> //basename, dirname
//#include <sys/types.h> //http://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/types.h.html
//#include <unistd.h> //pipe, fork, execve, read, write
//
// Created by austinmm on 4/23/19.
//

#include "Level3.h"

int _mount(char* pathname){
    char filesys[200] = "";
    char mount_point[200] = "";
    //if no parameter display current mounted file systems
    if(strcmp(pathname,"")==0){
        mountStat();
        return 0;
    }
    sscanf(pathname, "%s %s", filesys,mount_point);
    //check wheter filesys is already mounted
    if(checkMounted(filesys) == -1){
        print_notice("File system is already mounted");
        return -1;
    }



}
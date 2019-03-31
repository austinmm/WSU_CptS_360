//
// Created by noah on 3/30/19.
//
#include "Level1.h"


int _link(char* pathname){
    int dev;
    char* oldFile ,*newFile, temp[100], temp2[100], *parentDirName, *childBaseName;
    int oino, nino, pino; //old inode and new inode and parent inode
    MINODE * omip , *pmip; //old mip and parent mip

    printf("\n\npathname: %s\n\n",pathname);

    oldFile = strtok(pathname, " "); //old File pathname
    newFile = strtok(0, " "); //new File pathname


    printf("oldFile:  %s\n\n",oldFile);
    printf("newFile:  %s\n\n",newFile);

    //Grab dev by checking path
    if(oldFile[0] == '/'){
        dev = _Root->dev;
    }
    else{
        dev = _Running->cwd->dev;
    }

    //Get old File inode and check File type
    oino = getino(oldFile);
    omip = iget(dev,oino);
    if(S_ISDIR(omip->INODE.i_mode)){
       printf("Error: File Type must not be DIR");
       return -1;
    }

    //Check if new File exist yet
    nino = getino(temp);
    if(nino != 0){
        printf("Error: New File must not exist yet");
        return -1;
    }

    //Create new File with the same inode as the old File
    strcpy(temp,newFile); //the temps are there to maintain integrity to newFile
    parentDirName = dirname(temp);
    strcpy(temp2,newFile);
    childBaseName = basename(newFile);

    pino = getino(parentDirName);

    if(newFile[0] == '/'){
        dev = _Root->dev;
    }
    else{
        dev = _Running->cwd->dev;
    }

    pmip = iget(dev, pino);
    enter_name(pmip, oino, childBaseName); //Is incomplete as of now


    omip->INODE.i_links_count++;
    omip->dirty=1;
    iput(omip);

    return 0;
}


//header file...

#ifndef head
#define head
#include<stdio.h>
#include<string.h>

struct data
       {
           char name[50];
           char value[100];
       };
int macro_rp(char *,char *,int);
int remove_cmnd_line(char *,char *);
int header_inc(char *,char *);
    
#endif

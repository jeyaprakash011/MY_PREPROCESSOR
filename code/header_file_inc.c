#include"header.h"

int header_inc(char *input,char *output)
{
	FILE *fp,*hfp,*op;
	char str[100],temps[100],*p,name[20],user[200];
	int i=0,head_count=0;
			
	fp=fopen(input,"r");	
	op=fopen(output,"w");	
	while(fgets(str,sizeof(str),fp)!=0){
	i=0;
		if(strncmp(str,"#include",8)==0){
			p=str;
			while(*p!=0){
				if(*p=='<'||*p=='"'){
					p++;
					while(*p!=0){
						if(*p=='>' || *p=='"'){
							name[i]=0;
							break;
						}
					name[i++]=*p;
					p++;
					}
				head_count++;
				break;
				}
				p++;
	    		}
			//printf("lib_name:%d\n",head_count);
			hfp=fopen(name,"r");
			if(hfp==0){
				sprintf(user, "/usr/include/%s", name);
				hfp=fopen(user,"r");
				if(hfp==0){
				printf("header file is not present\n");
				return 1;}
			}
			while(fgets(temps,sizeof(temps),hfp)!=0){
				fputs(temps,op);
			}
		}
	}
	fclose(fp);
	fclose(hfp);
	fclose(op);
	
	return head_count;
}






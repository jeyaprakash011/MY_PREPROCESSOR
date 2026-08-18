
#include"header.h"

int remove_cmnd_line(char *input, char *output)
{
	FILE *fp,*temp;
	fp=fopen(input,"r");
	if(fp==0){
		printf("File Not Present\n");
		return 1;
		}
			temp=fopen("temp.i","w");
			if(temp==0){
				printf("temp file not create\n");
				return 1;
			}
	char str[100],name[20],*p,temps[100],user[200];
	int i=0,ch,ch1,last_ch;
	
	while((ch=fgetc(fp))!=EOF){
		if(ch == '/'){
			ch1=fgetc(fp);
			if(ch1 == '/'){
			 while ((ch=fgetc(fp))!='\n' && ch!=-1){
                		fputc(' ', temp);
            			}
				 if (ch == '\n')
              				  fputc('\n', temp);
			}
		else if(ch1=='*'){
		last_ch=0;
		while ((ch=fgetc(fp))!=EOF){
                	if (last_ch=='*' && ch=='/'){
                		break;
			}
                fputc(' ', temp);
                last_ch=ch;
            	}
        }
	else{
           	 fputc('/',temp);
            	if (ch1!=EOF)
                fputc(ch1,temp);
        	}
	}
	else
		putc(ch,temp);
		//printf("%c\n",ch);
			
	}
	fclose(fp);
	fclose(temp);
	return 0;
}





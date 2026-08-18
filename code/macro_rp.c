
#include"header.h"

int macro_rp(char *input,char *output, int head_count)
{
    struct data M[10];
    FILE *fp,*op;
    char mac[100],mac1[100];
    int count = 0,i=0,j,k,head_count2=0;

    fp = fopen(input, "r");
    op = fopen(output, "a");
	while(fgets(mac,sizeof(mac),fp)!=0){
		if(strncmp(mac,"#define",7)==0){
			sscanf(mac,"#define %s %s",M[count].name,M[count].value);
			count++;
		}
	}
	/*for(i=0;i<count;i++){
		printf("%s\n",M[i].name);
		printf("%s\n",M[i].value);}*/
	rewind(fp);
	while(fgets(mac,sizeof(mac),fp)!=0)
	{
    		if (strncmp(mac,"#include",8)==0)
			head_count2++;
		if(head_count2==head_count)
			break;
	}
	while(fgets(mac,sizeof(mac),fp)!=0)
	{
    		if(strncmp(mac,"#define",7)==0)
        		continue;	
		i = 0;
		while (mac[i]!=0)
		{
 	  	 if (mac[i]==' ' || mac[i]=='\t'){
        		fputc(mac[i], op);
        		i++;
        		continue;
    			}
			if (mac[i]=='\n'){
        			i++;
        			continue;
    			}
    		j = 0;
    	while (mac[i]!=' ' &&mac[i]!='\t' && mac[i]!='\n' && mac[i]!='\0'){
        	mac1[j++]=mac[i++];
    	}
	mac1[j]='\0';
    	k = 0;
	while(k<count){
        	if(strcmp(mac1,M[k].name)==0){
            		fputs(M[k].value,op);
            		break;
        	}
		k++;
    	}
    if(k==count){
        fputs(mac1, op);
    }
  
}
fputc('\n',op);
}
    fclose(fp);
	fclose(op);
	remove("temp.i");
	return 0;
}

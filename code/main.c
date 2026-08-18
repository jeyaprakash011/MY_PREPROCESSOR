#include"header.h"

int main(int argc,char **argv)
{	struct data M[10];
	int head_count=0;
	if(argc!=2){
		printf("USAGE:./a.out file\n");
		return 1;
	}
	
	remove_cmnd_line(argv[1],"temp.i");

	head_count=header_inc("temp.i","abc.i");
	
	macro_rp("temp.i","abc.i",head_count);
	
	return 0;	

}

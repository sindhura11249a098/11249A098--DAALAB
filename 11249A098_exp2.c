#include<stdio.h>
void towers(int n,char source,char dest,char spare);
int main()
{
	int n;
	printf("enter the number of disks :");
	scanf("%d",&n);
	printf("\n sequence of moves :\n ");
	towers(n,'A','B','C');
	return 0;
}
void towers(int n,char source,char dest,char spare)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c \n",source,dest);
		return;
	}
	towers(n-1,source,spare,dest);
	printf("move disk %d from %c to %c \n ",n,source,dest);
	towers(n-1,spare,dest,source);
}

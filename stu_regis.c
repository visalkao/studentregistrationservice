//27/04/21
//CREATE TEXT FILES NAMED "Writefile.bin", "Updatefile.bin" (Optional)
#include<stdio.h>
#include<stdlib.h>
struct Student{
	int id;
	char name[30],sex;
	float score;
};
void writefile(struct Student stu)
{
	
	int n,i;
	FILE *f;
	f = fopen("Writefile.bin","ab");
	printf("How many student will be registered?	:	");scanf("%d",&n);
	// INPUT ONLY INTEGER 
	for(i=1;i<=n;i++)
	{
		printf("==================== Record %d ======================\n",i);
		fflush(stdin);
		printf("Input Name	:	");scanf("%s",&stu.name);
		fflush(stdin);
		printf("Input ID	:	");scanf("%d",&stu.id);
		fflush(stdin);
		printf("Input Gender	:	");scanf("%c",&stu.sex);
		fflush(stdin);
		printf("Input score	:	");scanf("%f",&stu.score);
		fflush(stdin);
		fwrite(&stu,sizeof(struct Student),1,f);
	}
	fclose(f);
	printf("Write Successfully.\n");
}
void readfile(struct Student stu)
{
	int n,i;
	FILE *f;
	f = fopen("Writefile.bin","rb");
	while(1==fread(&stu,sizeof(struct Student),1,f))
	{
		printf("=================== Record %d==================\n",i+1);
		printf("Name	:	%s\n",stu.name);
		printf("ID		:	%d\n",stu.id);
		printf("Gender	:	%c\n",stu.sex);
		printf("Score	:	%.2f\n",stu.score);
		i++;
	}
	printf("========Read success==============\n");
	fclose(f);
}
void searchfile(struct Student stu)
{
	FILE *f;
	int i,n,s;
	f=fopen("Writefile.bin","rb");
	printf("Input the ID to seach 	:	");scanf("%d",&s);
	while(1==fread(&stu,sizeof(struct Student),1,f))
	{
		if(s==stu.id)
		{
			printf("=================== Record %d==================\n",i+1);
			printf("Name	:	%s\n",stu.name);
			printf("ID		:	%d\n",stu.id);
			printf("Gender	:	%c\n",stu.sex);
			printf("Score	:	%.2f\n",stu.score);
		}i++;
	}
	fclose(f);
}
void updatefile(struct Student stu)
{
	FILE *f;
	FILE *fup;
	int n,i,up;
	f = fopen("Writefile.bin","rb");
	fup = fopen("Updatefile.bin","ab");
	printf("Input the ID to search :	");scanf("%d",&up);
	while(1==fread(&stu,sizeof(struct Student),1,f))
	{
		if(up == stu.id)
		{
			fflush(stdin);
			printf("Input new  ID :		");scanf("%d",&stu.id);
			fflush(stdin);
			printf("Input new name:		");scanf("%s",&stu.name);
			fflush(stdin);
			printf("Input new gender:	");scanf("%c",&stu.sex);
			fflush(stdin);
			printf("Input new score	:	");scanf("%f",&stu.score);
			fflush(stdin);
			fwrite(&stu,sizeof(struct Student),1,fup);
		}
		else{
			fwrite(&stu,sizeof(struct Student),1,fup);
		}
		i++;
	}
	fclose(f);
	fclose(fup);
	remove("Writefile.bin");
	rename("Updatefile.bin","Writefile.bin");
}
void deletefile(struct Student stu)
{
	FILE *f;
	FILE *fd;
	int n,i,d,b=0;
	f =fopen("Writefile.bin","rb");
	fd =fopen("Deltefile.bin","ab");
	printf("Input the ID data you want to delete	:	");scanf("%d",&d);
	while(1==fread(&stu,sizeof(struct Student),1,f))
	{
		if(d==stu.id)
		{
			b=1;
			printf("Delete Successfully\n");
			
		}
		else{
			fwrite(&stu,sizeof(struct Student),1,fd);
		}
		i++;
	}
	if(b==0)
	{
		printf("Can\'t delete file\n");
	}
	fclose(f);
	fclose(fd);
	remove("Writefile.bin");
	rename("Deletefile.bin","Writefile.bin");

}

int main()
{
	struct Student stu;
	int op;
	do{
	printf("======================\n");
	printf("1.	Write file.\n");
	printf("2.	Read file.\n");
	printf("3.	Search file.\n");
	printf("4.	Update file.\n");
	printf("5.	Delete file.\n");
	printf("6.	Exit\n");
	printf("Input your option :	");scanf("%d",&op);
	switch(op){
		case 1: writefile(stu);break;
		case 2: readfile(stu);break;
		case 3: searchfile(stu);break;
		case 4: updatefile(stu);break;
		case 5: deletefile(stu);break;
	}
	}while(op!=6);
	}

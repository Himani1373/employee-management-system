#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void add_record();
void view_record();
void modify_record();
void delete_record();
void home();
struct emp
{
	char name[40];
	int age;
	float bs;
};
struct emp e;
	
int main()
{
	home();	
    return 0;
}
void home()
{
	char choice;
	system("cls");
	printf("1.Add Record");
	printf("\n2.view Record");
	printf("\n3.Modify Record");
	printf("\n4.Delete Record");
	printf("\n5.Exit");
	printf("\nYour Choice");
	fflush(stdin);
	choice=getche();
	switch(choice)
	{
		case '1':
			add_record();
			break;
		case '2':
			 view_record();
			break;
		case '3':
			modify_record();
		
		break;
		case '4':
			 delete_record();
		break;
		case '5':
			exit(0);
	}
}
	
void add_record()
{
			system("cls");
			FILE*fp;
			char another;
			fp=fopen("EMP.DAT","a");
			if(fp==NULL)
			{
				printf("cannot open file");
				exit(1);
			}
			another='y';
			while(another=='y')
			{
				printf("\n Enter name: ");
				scanf("%s",e.name);
				printf("\n enter age: ");
				scanf("%d",&e.age);
				printf("\n Enter basic salary: ");
				scanf("%f",&e.bs);
				fwrite(&e, sizeof(e),1,fp);
				printf("\n\n >> SAVE SUCCESSFUL <<\n");
				printf("\n\n Add another record(y/n)");
				fflush(stdin);
				another=getche();
			}
				fclose(fp);
			home();
			
}
void view_record()
{
		system("cls");
		FILE*fp1;
		printf("\n\t\t\t\t  ALL Records INFORMATION\n\n");
		fp1=fopen("EMP.DAT","r");
		while(fread(&e,sizeof(e),1,fp1))
		{
			printf("\n%s %d %.2f",e.name, e.age, e.bs);
		}
		fclose(fp1);
		getch();
		home();

}
void modify_record()
{
		system("cls");
	
		int i=0;
		char another;
		char empname[40];
		FILE*fp3;
		fp3=fopen("EMP.DAT","r");
		another='y';
		while(another=='y')
		{
			printf("enter the employee name to modify: ");
			scanf("%s",empname);
			while(fread(&e,sizeof(e),1,fp3))
			{
				if(strcmp(e.name, empname)==0)
				{
					fclose(fp3);
					fp3=fopen("EMP.DAT","a");
					printf("\n enter new name ,age and bs: ");
					scanf("%s%d%f",e.name, &e.age,&e.bs);
					fseek(fp3,-(sizeof(e)),SEEK_CUR);
					fwrite(&e,sizeof(e),1,fp3);
					i++;
					break;
				}
				
			}
			if(i==0)
			{
				printf("\n record not found ");	
			}
			fclose(fp3);
			printf("\n Modify another record(y/n)");
			fflush(stdin);
			another=getche();
		}
		home();
}
void delete_record()
{
	 system("cls");
	 FILE*fp,*ft;
    char empname[50];
    char another = 'y';
   while(another == 'y')
    {
        printf("\nEnter employee name to delete : ");
        scanf("%s", empname);
        fp=fopen("EMP.DAT","r");
  		ft = fopen("temp.DAT", "wb");
        rewind(fp);
  
        while(fread(&e, sizeof(e), 1, fp) == 1) 
		{
            if (strcmp(e.name, empname) != 0)
                fwrite(&e, sizeof(e), 1, ft);
        }
  
        fclose(fp);
        fclose(ft);
        remove("EMP.DAT");
        rename("temp.DAT", "EMP.DAT");
        fp = fopen("EMP.DAT", "rb+");
  
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
		getch();
		home();
}

#include<stdio.h>
#include<stdlib.h>
int i,menu();
void login();
void forgot();

struct account
{
	char first_name[20];
	char last_name[20];
	char username[30];
	char pass1[20];

};
void divider()
{
	for(i=0;i<50;i++)
	{
		printf("-");
	}
}
int main()
{
	while (1)
	{
		system("cls");
		switch(menu())
		{
			case 1:
				reg();
				break;
				
			case 2:
				login();
				break;
				
			case 3:
				forgot();
				break;
				
			case 4:
				exit(0);
				
			default:
				printf("Invalid Choice!\n");
		}
	}
	return 0;
}

int menu()
{
	int c;
	printf("\nWelcome to main menu\n");
	divider();
	printf("\n1. Register\n");
	printf("2. Login\n");
	printf("3. Forgot Credentials\n");
	printf("4. Exit\n");
	divider();
	printf("\nEnter your choice:");
	scanf("%d",&c);
	return c;
}

void takepassword(char pass[20])
{
	int i = 0;
	char ch;
	while (1)
	{
	
	ch = getch();
	if (ch==13)
	{
		pass[i] = '\0';
		break;
	}
	else if(ch==8)
	{
		if(i>0)
		{
			i--;
			printf("\b\b");
		}
	}
	else if(ch==9||ch == 32)
	{
		continue;
	}
	else
	{
		pass[i++]=ch;
		printf("*");
	}
}
}

void reg()
{
	
	struct account a;
	system("cls");
	char pass2[20];
	printf("Registration\n");
	divider();
	printf("\nEnter your first name:");
	scanf("%s",a.first_name);
	printf("Enter your last name:");
	scanf("%s",a.last_name);
	printf("Enter your username:");
	scanf("%s",a.username);
	printf("Enter your password:");
	takepassword(a.pass1);
	
confirm_pass:
	printf("\nConfirm password:");
	scanf("%s",pass2);
	
	if(strcmp(a.pass1,pass2))
	{
		printf("Incorrect Password\n\n");
		goto confirm_pass;
	}
	else
	{
		printf("Account Created\n\n");
		getch();
		
		FILE*fp = fopen("account.txt","w");
		fwrite(&a,sizeof(struct account),1,fp);
		fclose(fp);
	}
}

void login()
{
	system("cls");
	char user[30],log_pass[20];
	
	struct account a;
	FILE*fp = fopen("account.txt","r");
	fread(&a,sizeof(struct account),1,fp);
	
	name:
		printf("Enter Username:");
		scanf("%s",user);
		if(strcmp(a.username,user))
		{
			printf("\nPlease enter correct Username\n");
			goto name;
			
		}
		else
		{
			logpass:
				printf("Enter password:");
				takepassword(log_pass);
				if(strcmp(a.pass1,log_pass))
				{
					printf("\nIncorect Password\n");
					goto logpass;
				}
				else
				{
					system("cls");
					printf("\nWelcome!! %s\n",a.first_name);
					divider();
					
					printf("\nYour Details\n");
					divider();
					printf("\nUsername  :%s\n",a.username);
					printf("First name  :%s\n",a.first_name);
					printf("Last name  :%s\n",a.last_name);
					printf("Password  :%s\n",a.pass1);
				}
				getch();
		}
		fclose(fp);
}
void forgot()
{
	system("cls");
	struct account a;
	int choice;
	char username[20],password[20];
	FILE*fp = fopen("account.txt","r");
	fread(&a,sizeof(struct account),1,fp);
	
	printf("\n1.Search by Username\n");
	printf("2.Search by password\n");
	printf("3. Main menu\n");
	divider();
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter your Username:");
			scanf("%s",username);
			if(strcmp(username,a.username))
			{
				printf("Username not found!!");
				getch();
			}
			else
			{
				printf("Account found!\n");
				divider();
				printf("\nUsername  :%s \n",a.username);
				printf("First name: %s\n",a.first_name);
				printf("Last name  :%s\n",a.last_name);
				printf("Password  :%s\n",a.pass1);
				getch();
			}
			break;
			
			case 2:
				printf("Enter your password:");
				scanf("%s",password);
				if(strcmp(password,a.pass1))
				{
					printf("Account not Found!!");
					getch();
					
				}
				else
				{
					printf("Account Found!\n");
					divider();
					printf("\nUsername  :%s\n",a.username);
					printf("First name: %s\n",a.first_name);
					printf("Last name  :%s\n",a.last_name);
					printf("Password: %s\n", a.pass1);
					getch();
					
				}
				break;
				
				case 3:
					return;
					
				default:
					printf("Invalid Choice\n");
					break;
	}
	fclose(fp);
}

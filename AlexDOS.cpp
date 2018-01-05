//PPA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//MAINFUNCTION
int main()
{

	//DECLARE
	int updateCount;
	
	int usernameCorrect = 0, passwordCorrect = 0, loginSuccess = 0;
	
	
	char username[1024], password[1024];
	
	char path[1024];
	char arrow[128];
	
	char cd[128];
	
	char buffer[128];
	char dir[128];

	char dirHere[1024];
	
	char ip[128];
	char pingParameters[1024];
	
	char select[32];
	
	char txtEditSave[16384];
	
	char txtReadFile[32] = "txtedit.txt";
	char txtReadFileNew[32];
	
	char txtEditFile[32] = "Programs/txtedit/";
	char txtEditFileNew[32] = "\0";
	char txtEditFileNewDirectory[32];
		
	int i = 23;
	
	BOOT:

	
	strcpy(path, "C:\\");
	strcpy(arrow, ">");
	
	strcpy(dirHere, "C:\\");


	//GRAPHICAL STARTUP AND IO
	system("color 07");
	
	Sleep(500);
	printf("Alex-DOS version alpha 0.6\n\n");
	Sleep(500);
	
	printf("Testing your System Memory");									//Memory Testing Simulation
	
	Beep(4000, 250);
	
	Sleep(1000);
	printf(".");
	
	Sleep(1000);
	printf(".");
	
	Sleep(1000);
	printf(".");
	
	Sleep(1500);
	printf(" done");
	
	Sleep(3000);															//End of Memory Testing Simulation
	
	if(loginSuccess == 0)	
		printf("\n\n");
	
	while(usernameCorrect == 0 || passwordCorrect == 0)						//Login
	{
		usernameCorrect = 0;
		passwordCorrect = 0;
		
		printf("\n");
		
		printf("Login:\n");
		
		printf("Enter Username: \n");
		gets(username);
		
		printf("Enter Password: \n");
		gets(password);
		
		if(strcmp(username, "a") == 0)
			usernameCorrect = 1;
			
		if(strcmp(password, "a") == 0)
			passwordCorrect = 1;
			
			strcpy(username, "\0");
			strcpy(password, "\0");
			
		if(usernameCorrect == 0 || passwordCorrect == 0)					//Wrong Password
			{
				printf("\n\nIncorrect username and/or password! Try again...");
				printf("\n");
			}
	
		if(usernameCorrect == 1 && passwordCorrect == 1)
			loginSuccess = 1;
	}

	if(loginSuccess == 1)													//Format and additional Design
		Sleep(1000);
	
	if(loginSuccess == 1)
		printf("\n\n");
		
	if(loginSuccess == 0)
		printf("\n\n");
		
	loginSuccess = 0;
	
	START:																	//START
	fflush(stdin);
	printf("%s", path);
	printf("%s", arrow);
	
	fflush(stdin);
	gets(select);

	//COMMDANS

		//EXIT
		if(strcmp(select, "exit") == 0)
		{
			printf("\n");
			printf("End of CMD Operating System\n\n\n");
			
			system("pause");
			return 0;
		}
		
		//REBOOT
		if(strcmp(select, "reboot") == 0)
		{
			system("cls");
			goto BOOT;
		}
		
		
		
		//VERSION
		if (strcmp(select, "version") == 0)
		{
			printf("\n");
			printf("VERSION: alpha 0.6\n");
		}
		
		//UPDATE
		if (strcmp(select, "get update") == 0)
		{
			printf("\n");
			printf("VERSION: alpha 0.6\n\n");
			
			printf("contacting update server");
			
			Sleep(1000);
			printf(".");
			
			Sleep(1000);
			printf(".");
			
			Sleep(1000);
			printf(".");
			
			Sleep(1500);
			printf(" done");
	
			Sleep(3000);
			
			printf("\n\n");
			
			
			for(updateCount= 0; updateCount <= 100; updateCount = updateCount+4)
			{
				printf("%d percent completed.\n", updateCount);
				Sleep(500);
				
			}
			
			printf("\n");
			printf("update finished! rebooting");
			
			Sleep(1000);
			printf(".");
			
			Sleep(1000);
			printf(".");
			
			Sleep(1000);
			printf("."); 			
			
			Sleep(1000);
			
			system("cls");
			goto BOOT;
		}
		
		//CD
		if (strcmp(select, "cd") == 0)
		{
			printf("\n");
			printf("Enter Directory:");
			printf("\n\n");
			
			strcpy(dirHere, "\0");
			
			gets(cd);
			
			strcpy(dirHere, cd);
			
			strcpy(buffer, "cd ");
			strcat(buffer, cd);
			
			printf("\n");
			
			system(buffer);
			
			strcpy(path, "\0");
			strcpy(path, cd);
	
			strcpy(buffer, "\0");
		}
		
		//DIR HERE
		if (strcmp(select, "dir here") == 0)
		{	

			strcpy(buffer, "dir ");
			strcat(buffer, dirHere);
	
			printf("\n");
	
			system(buffer);
			strcpy(buffer, "\0");
			
			printf("\n");
		}
		
		//DIR
		if (strcmp(select, "dir") == 0)
		{	
			printf("\n");
			printf("Enter Directory:");
			printf("\n\n");
	
			gets(dir);

			strcpy(buffer, "dir ");
			strcat(buffer, dir);
	
			printf("\n");
	
			system(buffer);
			strcpy(buffer, "\0");
			
			printf("\n");
		}
		
		//PING
		if(strcmp(select, "ping") == 0)
		{
			printf("\n");
			printf("Enter Adress:");
			printf("\n\n");
	
			gets(ip);
			
			printf("\n");
			printf("Enter Paraemters for Ping: (-t (endless)-n <count> (count of pings) -a (hostnames to ip))");
			printf("\n\n");
			
			gets(pingParameters);

			strcpy(buffer, "ping ");
			strcat(ip, " ");
			strcat(buffer, ip);
			strcat(buffer, pingParameters);
			
			printf("\n");
			
			system(buffer);
			strcpy(buffer, "\0");
			
			printf("\n");
			
		}
		
		//SYNTAX
		if (strcmp(select, "syntax") == 0)
		{	
			printf("\n");
			printf("Syntax:  'command' -'parameter'\n");
		}
		
		//CLS
		if (strcmp(select, "cls") == 0)
		{	
			system("cls");
		}
		
		
	
		//help
		if (strcmp(select, "help") == 0)
		{
			printf("\n");
			printf("available commands:\n\n");
			printf("syntax\n");
			printf("dir (directory/here)\n");
			printf("cd (directory)\n");
			printf("ping (adress & parameters)\n");
			printf("version\n");
			printf("cls\n");
			printf("txtedit\n");
			printf("get (update)\n");
			printf("reboot\n");
			printf("exit\n");
		}
		
		//PRESSING ENTER
		if (strcmp(select, "0x0A") == 0)
		{	
			goto START;
		}
		
		//PREVIOUS COMMAND
		if (strcmp(select, "") == 0)
		{	
			
			//wip
			//works with arrow-up
			
		}
		
		
		
		//TEXT EDIT
		if (strcmp(select, "txtedit") == 0)
		{	
			goto TXTEDIT;
		}
	
		//TXT READ
		if (strcmp(select, "txtread") == 0)
		{	
			goto TXTREAD;
		}
		
		
		
		//BLUESCREEN		//WIP
		if (strcmp(select, "bluescreen") == 0)
		{	
			system("cls");
			system("color 97");
		
			printf("			BLUESCREEN			");
			printf("\n\n");
			printf("Alex-DOS encountered a problem when operating in 0x913F3A");
			
			while(i>0)
			{
			printf("\n");
			i--;
			}
			
			i = 23;
			
			
			printf("Press Enter to restart...");
			
			fflush(stdin);
			gets(select);
			
			if (strcmp(select, "0x0A") == 0)
			goto BOOT;
		}



	printf("\n");
	goto START;																//GOTO START
	
	system("pause");
	return 0;

/******************************************************************/

	//PROGRAMMS
		
		//TEXT EDIT
			TXTEDIT:
		
			printf("\n");
			printf("Enter Filename:		(.txt, .doc, etc...)\n\n");
			
			gets(txtEditFileNew);
			
			printf("\n");
			
			system("cls");
			system("color 70");
			
			printf("						Text Edit\n\n");
			printf("\n Press Enter for save + quit");
			printf("\n\n");
			
			gets(txtEditSave);
			
			FILE *fp;
			
			fp = fopen("Programs/txtedit/txtedit.txt", "w+");
			fprintf(fp, txtEditSave);
			
			fclose(fp);
        
        	strcat(txtEditFile, txtEditFileNew);
        	
			rename("Programs/txtedit/txtedit.txt", txtEditFile);
			
			printf("\n\n");
			printf(" saving...");
			Sleep(1000);
			
			system("color 07");
			system("cls");
			
			printf("\n");
			
			strcpy(txtEditFile,"Programs/txtedit/");
			strcpy(txtEditFileNew,"\0");
			
			goto START;
			
			
		//TEXT READ															//WIP
			TXTREAD:
		
/*			printf("\n");
			printf("Enter Filename:		(.txt, .doc, etc...)\n\n");
			
			gets(txtReadFileNew);
			
			printf("\n");
			
			system("cls");
			system("color 70");
			
			printf("						Text Read\n\n");
			printf("\n Press Enter to quit");
			printf("\n\n");
		
*/	

			printf("\n");
			goto START;
			
}

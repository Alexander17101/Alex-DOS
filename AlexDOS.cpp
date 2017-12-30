//PPA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//MAINFUNCTION
int main()
{

	//DECLARE VERSION
//	char VERSION[32];
//	VERSION[32] = 'alpha 0.2.1';
	
	//DECLARE
	int updateCount;
	
	char select[16];
	
	char txtEditSave[16384];
//	char txtReadPrint[16384];
	
	char txtReadFile[32] = "txtedit.txt";
	char txtReadFileNew[32];
	
	char txtEditFile[32] = "Programs/txtedit/";
	char txtEditFileNew[32] = "\0";
	char txtEditFileNewDirectory[32];
	
	
	int i = 25, j;
	
	BOOT:

	//GRAPHICAL STARTUP AND IO
	//SetConsoleTitle("AlexDOS alpha 0.3.1");
	system("color 07");
	
	Sleep(500);
	printf("Alex-DOS version alpha 0.3.1\n\n");
	Sleep(500);
	
	//Beep(3000, 250);
	
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
	

	printf("\n\n\n");
	
	START:																	//START
	fflush(stdin);
	printf("C:/>");
	
	fflush(stdin);
	gets(select);

//	select = getchar();
//	scanf("%s", &select);	

	//COMMDANS

		//EXIT
		if(strcmp(select, "exit") == 0)
		{
			printf("\n");
			printf("End of CMD\n\n\n");
			
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
			printf("VERSION: alpha 0.3.1\n");
		}
		
		//UPDATE
		if (strcmp(select, "get update") == 0)
		{
			printf("\n");
			printf("VERSION: alpha 0.3.1\n");
			
			for(updateCount= 0; updateCount <= 100; updateCount = updateCount+4)
			{
				printf("%d percent completed.\n", updateCount);
				Sleep(500);
				
			}
			
			printf("\n update finished! rebooting");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf("."); 			
			
			system("cls");
			goto BOOT;
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
		
		//SETUP
		if (strcmp(select, "setup") == 0)
		{	
			
			
			
		}
		
		//help
		if (strcmp(select, "help") == 0)
		{
			printf("\n");
			printf("available commands:\n\n");
			printf("syntax\n");
			printf("version\n");
			printf("cls\n");
			printf("txtedit\n");
			printf("get (update)\n");
			printf("reboot\n");
			printf("exit\n");
			//printf("setup\n");
		}
		
		//PRESSING ENTER
		if (strcmp(select, "0x0A") == 0)
		{	
			goto START;
		}
		
		//PREVIOUS COMMAND
		if (strcmp(select, "") == 0)
		{	
			
			
			
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
			system("color 11");
		
			printf("			BLUESCREEN			");
			printf("\n\n");
			printf("Alex-DOS encountered a problem when operating in 0x913F3A");
			
			while(i>0)
			{
			printf("\n");
			i--;
			}
			
			
			printf("Press Enter to restart...");
			
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
			
			
		//TEXT READ		//WIP
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

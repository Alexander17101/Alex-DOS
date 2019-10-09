//PPA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

double calc(double, double);
void getSysStats();

void clock();
bool ring(bool);

//MAINFUNCTION
int main()
{

	//DECLARE
	int updateCount;
	
	int usernameCorrect = 0, passwordCorrect = 0, loginSuccess = 0;
	
	int memCount = 512, memValue = 1;
	
	double x, y, erg;
	
	char username[1024], password[1024];
	
	char path[1024];
	char arrow[128];
	
	char cd[128];
	
	char buffer[128];
	char dir[128];

	char dirHere[1024];
	
	char ip[128];
	char pingParameters[1024];
	
	char del[128];
	char deldir[128];
	char delQuestion[128];
	
	char select[32];
	
	char txtEditSave[16384];
	
	char txtReadFile[32] = "txtedit.txt";
	char txtReadFileNew[32];
	
	char txtEditFile[32] = "Programs/txtedit/";
	char txtEditFileNew[32] = "\0";
	char txtEditFileNewDirectory[32];
	
	int bluescreenCounter = 16;
	int	bluescreenCounterSave = bluescreenCounter;
	
	char bluescreenChar;
	
	char notify1[128];
	char notify2[128];
	char notify3[128];
	
	char notifyOption = 0;
	
	//PREBOOT
	
	strcpy(notify1, "empty");												//Standardizing notifcation strings
	strcpy(notify2, "empty");
	strcpy(notify3, "empty");
	
	BOOT:

	
	strcpy(path, "C:\\");
	strcpy(arrow, ">");
	
	strcpy(dirHere, "C:\\");


	//GRAPHICAL STARTUP AND IO
	system("color 07");
	
	Sleep(500);
	printf("Alex-DOS version alpha 0.9\n\n");
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
		
		printf("Enter Username: ");
		gets(username);
		
		printf("Enter Password: ");
		gets(password);
		
		if(strcmp(username, "admin") == 0)
			usernameCorrect = 1;
			
		if(strcmp(password, "123456") == 0)
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
			printf("VERSION: Alex-DOS alpha 0.9\n");
		}
		
		//UPDATE
		if (strcmp(select, "get update") == 0)
		{
			printf("\n");
			printf("VERSION: alpha 0.9\n\n");
			
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
			
			if(strcmp(notify1, "empty") == 0)
				strcpy(notify1, "Update finished successfully!");
			
			else
				if(strcmp(notify2, "empty") == 0)
					strcpy(notify2, "Update finished successfully!");
				
				else
					if(strcmp(notify3, "empty") == 0)
						strcpy(notify3, "Update finished successfully!");
				
			goto BOOT;
		}
		
		//GETSYSSTATS
		if(strcmp(select, "sysStats") == 0)
		{
			getSysStats();
		}
		
		//CD
		if (strcmp(select, "cd") == 0)
		{
			printf("\n");
			printf("Enter Directory:");
			printf("\n\n");
			
			strcpy(dirHere, "\0");
			strcpy(deldir, "\0");
			
			gets(cd);
			
			strcpy(dirHere, cd);
			strcpy(deldir, cd);
			
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
		
		//DEL
		if(strcmp(select, "del") == 0 )
		{
			printf("\n");
			printf("Enter Filename:");
			printf("\n\n");
		
			gets(del);
			
			printf("\n");
		
			printf("Do you want do procced? (y/n) ");
			
			gets(delQuestion);
			
			strcpy(buffer, "del ");
			strcat(buffer, deldir);
			strcat(buffer, "\\");
			strcat(buffer, del);
			
			if(strcmp(delQuestion, "y") == 0 )
			{
				system(buffer);
				printf("The File/s was/were deleted successfully!");
			}
			else
			{
				printf("Cancelled!");
			}	
			
			strcpy(buffer, "\0");
			
			printf("\n\n");
			}
		
		//CALC
		if(strcmp(select, "calc") == 0)
		{
			printf("\n");
			
			printf("Enter a number!\n");
			scanf("%lf", &x);
			
			printf("Enter a second number!\n");
			scanf("%lf", &y);
			
			erg = calc(x, y);
			
			printf("The solution is: %.2lf", erg);
			
			printf("\n");
		}
		
		//MEMTEST
		if(strcmp(select, "memtest") == 0)
		{
			system("cls");
			
			printf("Testing your System Memory");									//Memory Testing Simulation
	
			Beep(4000, 250);
				
			system("cls");
		
			while(memCount > 0)
			{
				system("cls");
					
				printf("Testing your System Memory %dKB", memValue);
				memValue++;
				memCount--;
				
				Sleep(10);
			}
				
			Sleep(1500);
			printf("  done");
			Sleep(500);
			
			memCount = 512;
			memValue = 1;
			
			printf("\n");
		}
		
		//NOTIFICATION
		if(strcmp(select, "notifications") == 0)
		{
			printf("\nYour Notifications:\n\n");
			
			printf("1. %s\n", notify1);												//Displaying current notifications
			printf("2. %s\n", notify2);
			printf("3. %s\n", notify3);	
			
			printf("\nPress 0 to exit, press 1 to clear notifications and exit\n");
			
			fflush(stdin);
			notifyOption = getch();													//working with char to be able to use this conio.h library function
			
			if(notifyOption == '1')
			{
				strcpy(notify1, "empty");											//Standardizing notifcation strings, if the user wishes to
				strcpy(notify2, "empty");
				strcpy(notify3, "empty");
				
				printf("cleared notifcations!\n");
			}
			
		}
		
		
		//CLOCK
		if(strcmp(select, "clock") == 0)
		{
			clock();
			
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
			printf("memtest\n");
			printf("dir (directory/here)\n");
			printf("cd (directory)\n");
			printf("ping (adress & parameters)\n");
			printf("del (Filename)\n");
			printf("calc\n");
			printf("tree\n");
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
		
		
		
		//BLUESCREEN
		if (strcmp(select, "bluescreen") == 0)
		{	
			system("cls");
			system("color 97");
		
			if(strcmp(notify1, "empty") == 0)										//creating notification to inform the user
				strcpy(notify1, "A critcal error has lead to a bluescreen.");
			
			else
				if(strcmp(notify2, "empty") == 0)
					strcpy(notify2, "A critcal error has lead to a bluescreen.");
				
				else
					if(strcmp(notify3, "empty") == 0)
						strcpy(notify3, "A critcal error has lead to a bluescreen.");
						
		
			printf("				BLUESCREEN				");
			printf("\n\n");
			printf("Alex-DOS encountered a problem when operating in 0x913F3A");
			printf("\n\n\n");
			printf("Troubleshoot:\n");
			printf("Try to run command 'repair' the next time you boot up");
			printf("\n\n");
			printf("Description:\n");
			printf("Error cause because of memory stack overflow");
			
			while(bluescreenCounter>0)
			{
				printf("\n");
				bluescreenCounter--;
			}
			
			bluescreenCounter = bluescreenCounterSave;
			
			
			printf("Press Shift + R to restart...");
			
			fflush(stdin);
			bluescreenChar = getch();
			
			if (bluescreenChar == 'R')
			{
				system("cls");
				
				goto BOOT;
			}
			
		}
		
		//MSCOMMAND
		if(strcmp(select, "mscommand") == 0)
		{
			printf("\n");
			printf("Start of mscommand\n\n");
			
			gets(buffer);
			system(buffer);
			
			strcpy(buffer, "\0");
			
			printf("\nEnd of mscommand\n");
			
		}
		
		//MSCMD
		if(strcmp(select, "mscmd") == 0)
		{
			printf("\n");
			printf("Start of mscmd\n\n");
		
			system("cmd.exe");
			
			printf("\nEnd of mscmd\n");
		
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

double calc(double a, double b)
{
	double rgw;
	int select;

	printf("\n");
	printf("Arithmetic Operations:\n\n");
	printf("1 for add\n");
	printf("2 for subtract\n");
	printf("3 for multiply\n");
	printf("4 for divide\n\n");
	
	printf("5 for squareroot of first number\n");
	printf("6 for sinus of first number\n");
	printf("7 for cosinus of first number\n");
	printf("8 for tangens of first number\n\n");
	
	printf("0 for exit\n\n");
	
	printf("Enter:\n");
	scanf("%d", &select);
	
	printf("\n");
	
	switch(select)
	{
		case 1:
			rgw = a+b;
			break;
			
		case 2:
			rgw = a-b;
			break;
			
		case 3:
			rgw = a*b;
			break;
		
		case 4:
			rgw = a/b;
			break;
			
		case 5:
			rgw = sqrt(a);
			break;
			
		case 6:
			rgw = sin(a);
			break;
			
		case 7:
			rgw = cos(a);
			
		case 8:
			rgw = tan(a); 
		
		case 0:
			break;
			
		default:
			break;
			
	}

}

void getSysStats()
{
	printf("\n");
	
	SYSTEMTIME time;
	MEMORYSTATUSEX mem;
	_ULARGE_INTEGER free, total, totalFree;
	DWORD version = 0, major = 0, minor = 0, build = 0;

		
	int x, y;
	unsigned long long freeSpace, totalSpace, totalFreeSpace;
	float memory;
	const char *drive = "C:\\";
	
	
	GetLocalTime(&time);
	
	printf("Time:			%02d:%02d %02d\n\n\n", time.wHour, time.wMinute, time.wSecond);
	
	
	printf("Hardware:\n\n\n");
	
	
	x = GetSystemMetrics(SM_CXSCREEN);
	y = GetSystemMetrics(SM_CYSCREEN);
	
	printf("Resolution:		%dx%d\n\n", x, y);
	
	
	mem.dwLength = sizeof(mem);
	GlobalMemoryStatusEx(&mem);
	
	memory = mem.ullTotalPhys;

	memory = memory / 1024;
	memory = memory / 1024;
	memory = memory / 1024;
	
	printf("Memory:			%.2f GB\n\n", memory);
	
	
	GetDiskFreeSpaceEx(drive, &free, &total, &totalFree);
	
	totalSpace = total.QuadPart;
	freeSpace = free.QuadPart;
	
	totalSpace = totalSpace / 1024;
	totalSpace = totalSpace / 1024;
	totalSpace = totalSpace / 1024;
	
	freeSpace = freeSpace / 1024;
	freeSpace = freeSpace / 1024;
	freeSpace = freeSpace / 1024;
	
	
	printf("Primary Drive:		%lli GB total", totalSpace);
	printf("\n			%lli GB free\n\n\n", freeSpace);
	
	
	printf("Software:\n\n\n");
	
	version = GetVersion();
	
	major = (DWORD)(LOBYTE(LOWORD(version)));
    minor = (DWORD)(HIBYTE(LOWORD(version)));
    
    if (version < 0x80000000)             
    	build = (DWORD)(HIWORD(version));
	
	printf("Windows NT: 		%d.%d (%d)\n", major, minor, build);
	
}

void clock()
{
	SYSTEMTIME lt;
	int h, min, sec;
	bool x = true;
	
			
		GetLocalTime(&lt);
		h = lt.wHour;
		min = lt.wMinute;
		sec = lt.wSecond;
	
			
		printf("\nTime: %02d:%02d %02d		Date: %02d.%02d.%04d	Day of Week: %1d\n", lt.wHour, lt.wMinute, lt.wSecond, lt.wDay, lt.wMonth, lt.wYear, lt.wDayOfWeek);
		
		if(min == 00 && sec == 00 && x == true)
			x = ring(x);
		
		if(min == 00 && sec == 30)
			x = true;
		
}

bool ring(bool x)
{
	Beep(330, 500);
	
	Beep(370, 500);
				
	Beep(415, 500);
				
	Beep(246, 500);
				
	Sleep(500);
				
	Beep(329, 500);
				
	Beep(369, 500);
				
	Beep(415, 500);
				
	Beep(329, 500);
				
	Sleep(500);
				
	Beep(415, 500);
				
	Beep(329, 500);
				
	Beep(369, 500);
				
	Beep(246, 500);
				
	Sleep(500);
				
	Beep(246, 500);
				
	Beep(369, 500);
				
	Beep(415, 500);
				
	Beep(329, 500);
	
	x = false;
	return x;
}

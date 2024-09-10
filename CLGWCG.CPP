#include <conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>


void getUserInput(char str2[], char str[])
{
   int i=0;
   char ch;

   //setcolor(3);
   //setcolor(11);
   outtextxy(10,100,str2);
   while(1)
   {
     ch = getch();
     if(ch == 13)
     {
       str[i] = '\0';
       break;
     }
     if(ch ==8 && i>0)
     {
       i--;
       str[i] = '\0';
     }
     else
     {
      str[i] = ch;
      i++;
      str[i] = '\0';
     }
     outtextxy(strlen(str2)*16,101,str);
   }
}

void drawArrow(int x, int y){
  setcolor(RED);
  line(x,y,x+40,y);
  line(x+50,y,x+40,y-10);
  line(x+50,y,x+40,y+10);
  line(x+40,y-10,x+40,y+10);
  setcolor(WHITE);
}
void eraseArrow(int x, int y){
  setcolor(BLACK);
  line(x,y,x+50,y);
  line(x+50,y,x+40,y-10);
  line(x+50,y,x+40,y+10);
  line(x+40,y-10,x+40,y+10);
  setcolor(WHITE);
}

int h=6;
int textPos=6; //centerList
int ct = 0; //number of students
char p[] = "part";   //if you want to print only one student
char t[] = "total";  //if you want to print whole students

struct student
{
  char roll[20];
  char name[20];
  char branch[20];
  char gen[10];
  char add[20];
  int math;
  int phy;
  int chem;
};
typedef struct student std;

void line(int,char);
void right(int,char[]);
void center(int,char []);
void centerList(char []);
void header(char []);
void footer(char []);

void options();

void newAddmission(std []);
void listRecords(std []);
  void printTabs(std stdArr[],char [],int);

void searchRecords(std []);
  //searching....
  void searchRollNo(std [],char []);
  void searchName(std [],char []);
  void searchBranch(std [],char []);
  void searchGen(std [],char []);
  void searchAdd(std [],char []);

void modifyRecords(std []);
  //modifying....
  void modifyRollNo(std [],char [], char []);
  void modifyName(std [],char [], char []);
  void modifyBranch(std [],char [], char []);
  void modifyGen(std [],char [], char []);
  void modifyAdd(std [],char [], char []);

void deleteRecords(std []);
  //deleting...
  void deleteRollNo(std [],char []);
  void deleteName(std [],char []);
  void deleteBranch(std [],char []);
  void deleteGen(std [],char []);
  void deleteAdd(std [],char []);

void failureReports(std []);
  int percent(std [], int);

void highestScorer(std []);

void sortRecords(std []);
  int compareRoll(const void *a, const void *b);
  void sortRollNo(std []);
  int compareName(const void *a, const void *b);
  void sortName(std []);
  int compareBranch(const void *a, const void *b);
  void sortBranch(std []);
  int compareGen(const void *a, const void *b);
  void sortGen(std []);
  int compareAdd(const void *a, const void *b);
  void sortAdd(std []);
void games();
  void board(const char []);
  int printPositionValid(char [],char,int);
  int choos(char [], int, char);
  void printWin(char,char []);
  int checkWin(char , char);
  void win(char [],char);

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    std stdArr[10] = {
    {"69","C","A","C","A",66,88,88},

    {"70","B","B","B","B",6,7,7},

    {"71","A","C","A","C",6,6,6}};
    ct=3;
    cleardevice();
    int opn=1;
    int x=100, y=100;
    while(1)
    {
      drawArrow(x,y);
      setcolor(9);
      setbkcolor(11);
      header("<<< STUDENT MANAGEMENT SYSTEM >>>");
      char buffer[200];
      sprintf(buffer,"Students : %d",ct);
      outtextxy(16*10,16*4,buffer);

      options();
      center(26, "Choos an option (0 for back) : ");
      setcolor(12);
      footer("DEVELOPER : MOHD ASRAR MALIK");
      if(kbhit())
      {
	char key = getch();
	if(key == 0)
	{
	  key = getch();
	}

	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn ==0 || opn ==1)
	    {
	      opn = 10;
	      eraseArrow(x,y);
	      y=100;
	      y += 18*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=10)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      //y += 2*16;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12, "Visit again. Happy day. ;) ");
	  getch();
	  break;
	}
	if(key == 13)
	{
	  if(opn == 10)
	  {
	      cleardevice();
	      center(12, "Visit again. Happy day. ;) ");
	      getch();
	      break;
	  }
	  switch(opn)
	  {
	    case 1:
	      newAddmission(stdArr);
	      break;
	    case 2:
	      listRecords(stdArr);
	      break;
	    case 3:
	      searchRecords(stdArr);
	      break;
	    case 4:
	      modifyRecords(stdArr);
	      break;
	    case 5:
	      deleteRecords(stdArr);
	      break;
	    case 6:
	      failureReports(stdArr);
	      break;
	    case 7:
	      highestScorer(stdArr);
	      break;
	    case 8:
	      sortRecords(stdArr);
	      break;
	    case 9:
	      games();
	      break;
	    default:
	      cleardevice();
	      center(12, "Wrong option!!!");
	      getch();
	  }
	  cleardevice();
	}
      }
    }
}

void line(int l,char ch)
{
  char str[2] = {ch,'\0'};
  int i;
  for(i=0; i<=80; i++)
  {
    outtextxy(i*16,l*16,str);
  }
}
void right(int ps,char str[])
{
  char buffer[200];
  sprintf(buffer,"%s",str);
  outtextxy(639-16*strlen(str),ps*16,buffer);
}
void center(int pos,char str[])
{
  outtextxy(319-8*strlen(str),pos*16,str);
}
void centerList(char str[])
{
  outtextxy(639-30*16,16*textPos++,str);
  textPos++;
}

void header(char str[])
{
  line(1,205);
  center(2,str);
  line(3,205);
}

void footer(char str[])
{
  line(28,205);
  right(29,str);
}

void options()
{
  centerList("01. NEW ADMISSION");
  centerList("02. LIST RECORDS");
  centerList("03. SEARCH RECORDS");
  centerList("04. MODIFY RECORDS");
  centerList("05. DELETE RECORDS");
  centerList("06. FAILUR REPORTS");
  centerList("07. HIGHEST SCORER");
  centerList("08. SORT RECORDS");
  centerList("09. PLAY A GAME");
  centerList("00. EXIT");
  textPos=6;
}

void newAddmission(std stdArr[])
{

  cleardevice();
  int opn=1;
  int x=16*13, y=16*8;
  while(1)
  {
    drawArrow(x,y);
    setcolor(9);
    setbkcolor(11);
    header("<<< NEW ADDMISSSION >>>");
    char buffer[200];
    sprintf(buffer,"Stundets : %d",ct);
    outtextxy(16*14,5*16,buffer);

    center(8," 01. Yes");
    center(10,"02. NO");
    center(12, "( Confirm Y/N )");

    if(kbhit())
    {
	char key = getch();
	if(key == 0)
	{
	  key = getch();
	}
	
	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn ==0 || opn==1)
	    {
	      opn = 2;
	      eraseArrow(x,y);
	      y=100;
	      y += 16*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=2)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12,"BACKED!!!");
	  getch();
	  break;
	}
	if(key == 13)
	{

	   if(opn == 1)
	   {
		cleardevice();
		header("<<< NEW ADDMISSSION >>>");
		printf("Stundets : %d\n\n\n",ct);

		getUserInput("Enter Roll number of student: ",stdArr[ct].roll);
		outtextxy(10,120,stdArr[ct].roll);
		getch();
		cleardevice();

		getUserInput("Enter Name of student: ",stdArr[ct].name);
		outtextxy(10,120,stdArr[ct].name);
		getch();
		cleardevice();

		getUserInput("Enter Branch of student: ",stdArr[ct].branch);
		outtextxy(10,120,stdArr[ct].branch);
		getch();
		cleardevice();

		getUserInput("Enter Gender of student: ",stdArr[ct].gen);
		outtextxy(10,120,stdArr[ct].gen);
		getch();
		cleardevice();

		getUserInput("Enter Adress of student: ",stdArr[ct].add);
		outtextxy(10,120,stdArr[ct].add);
		getch();
		cleardevice();

		printf("Enter math's marks :");
		scanf("%d",&stdArr[ct].math);
		printf("Enter physic's marks :");
		scanf("%d",&stdArr[ct].phy);
		printf("Enter chemistry's marks :");
		scanf("%d",&stdArr[ct].chem);
		ct++;
	   }
	   else
	   {
		cleardevice();
		center(12,"BACKED!!!");
		getch();
		break;
	   }
	   cleardevice();
	}
    }
  }
}

void listRecords(std stdArr[])
{

  int i;
  cleardevice();
  char buffer[200];
  header("<<< List Records >>>");
  sprintf(buffer,"Students : %d\n", ct);
  outtextxy(0,4,buffer);
  printTabs(stdArr,t,0);
  getch();

}
//tabs+++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printTabs(std stdArr[],char ch[],int ind)
{
    setcolor(9);
    setbkcolor(11);
    char buffer[200];
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
    line(h+2,'~');

    if(strcmpi(ch, t) == 0)
    {
      int i;
      for(i=0; i<ct; i++)
      {
	if(percent(stdArr,i)<35)
	{
    char buffer[200];
	  sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
	  stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	  stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
    outtextxy(0,16*(10+i+i),buffer);
	}
	else
	{
	  char buffer[200];
	  sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
	  stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	  stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
    outtextxy(0,16*(10+i+i),buffer);
	}
      }
    }
    else if(strcmpi(ch,p) == 0)
    {
      if(percent(stdArr,ind)<35)
      {
	char buffer[200];
	      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,stdArr[ind].name,
	stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,stdArr[ind].math,
	stdArr[ind].phy,stdArr[ind].chem,"F");
	outtextxy(0,16*(h+4),buffer);
      }
      else{
      char buffer[200];
	      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,stdArr[ind].name,
	stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,stdArr[ind].math,
	stdArr[ind].phy,stdArr[ind].chem,"P");
	outtextxy(0,16*(h+4),buffer);
      }
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void searchRecords(std stdArr[])
{
  cleardevice();
  int opn=0;
  int x=100, y=100;
  while(1)
  {
    drawArrow(x,y);
    setcolor(9);
    setbkcolor(11);
    header("<<< SEARCH RECORDS >>>");
    centerList("01. BY ROLL NUMBER");
    centerList("02. BY NAME");
    centerList("03. BY BRANCH");
    centerList("04. BY GENDER");
    centerList("05. BY CITY");
    centerList("06. BY STATE");
    centerList("07. BY DISTIC");
    centerList("08. BY NATIONALITY");
    centerList("00. EXIT");
    textPos=6;
    center(26, "Choos an option (0 for back) : ");


    if(kbhit())
    {
	//cleardevice();
	char key = getch();
	if(key == 0)
	{
	  key = getch();
	}

	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn == 0 || opn ==1)
	    {
	      opn = 9;
	      eraseArrow(x,y);
	      y=100;
	      y += 16*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=9)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12, "BACKED!!!");
	  getch();
	  break;
	}
    if(key == 13)
    {
      if(opn == 9)
      {
	 cleardevice();
	 center(12, "BACKED!!!");
	 getch();
	 break;
      }
    switch(opn)
    {
      case 1:
	char str[20];
	cleardevice();
	header("<<<  BY ROLL NO  >>>");

	getUserInput("Enter Roll number : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();
	searchRollNo(stdArr,str);
	break;
      case 2:
	cleardevice();
	header("<<<  BY NAME  >>>");

	getUserInput("Enter Name : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();
	searchName(stdArr,str);
	break;
      case 3:
	cleardevice();
	header("<<<  BY BRANCH  >>>");

	getUserInput("Enter Branch : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();
	searchBranch(stdArr,str);
	break;
      case 4:
	str[20];
	cleardevice();
	header("<<<  BY GENDER  >>>");

	getUserInput("Enter Gender : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	searchGen(stdArr,str);
	break;
      case 5:
	str[20];
	cleardevice();
	header("<<<  BY ADDRESS  >>>");

	getUserInput("Enter Address : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	searchAdd(stdArr,str);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      default:
	cleardevice();
	center(12, "Wrong option!!!");
	getch();
    }
    cleardevice();
    }
    }

  }
}
//searching.....
void searchRollNo(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();
    center(12, "Not found!!!");
    getch();
  }
}

void searchName(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();
    center(12, "Not found!!!");
    getch();
  }
}

void searchBranch(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].branch, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();
    center(12, "Not found!!!");
    getch();
  }
}

void searchGen(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].gen, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();
    center(12, "Not found!!!");
    getch();
  }
}

void searchAdd(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmp(stdArr[i].add, str)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();
    center(12, "Not found!!!");
    getch();
  }
}
//ENDED SEARCHING

void modifyRecords(std stdArr[])
{
  int opn=0;
  int x=100, y=100;
  cleardevice();
  while(1)
  {
    drawArrow(x,y);
    setcolor(9);
    setbkcolor(11);
    header("<<< MODIFY RECORDS >>>");

    centerList("01. BY ROLL NUMBER");
    centerList("02. BY NAME");
    centerList("03. BY BRANCH");
    centerList("04. BY GENDER");
    centerList("05. BY CITY");
    centerList("06. BY STATE");
    centerList("07. BY DISTIC");
    centerList("08. BY NATIONALITY");
    centerList("00. EXIT");
    textPos=6;
    center(26, "Choos an option (0 for back) : ");

    if(kbhit())
      {
	//cleardevice();
	char key = getch();
	if(key == 0 || key == 224)
	{
	  key = getch();
	}
	
	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn ==0 || opn ==1)
	    {
	      opn = 9;
	      eraseArrow(x,y);
	      y=100;
	      y += 16*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=9)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      //y += 2*16;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12, "BACKED!!!");
	  getch();
	  break;
	}
	if(key == 13)
	{
      if(opn == 9)
      {
	 cleardevice();
	 center(12, "BACKED!!!");
	 getch();
	 break;
      }
    switch(opn)
    {
      case 1:
	char key[20];
	char value[20];
	cleardevice();
	header("<<<  BY ROLL NO  >>>");

	getUserInput("Enter old roll number : ",key);
	outtextxy(10,120,key);
	getch();
	cleardevice();

	getUserInput("Enter new roll number : ",value);
	outtextxy(10,120,value);
	getch();
	cleardevice();

	modifyRollNo(stdArr,key,value);
	break;
     case 2:
	cleardevice();
	header("<<<  BY NAME  >>>");

	getUserInput("Enter old Name : ",key);
	outtextxy(10,120,key);
	getch();
	cleardevice();

	getUserInput("Enter new Name : ",value);
	outtextxy(10,120,value);
	getch();
	cleardevice();

	modifyName(stdArr,key,value);
	break;
      case 3:
	cleardevice();
	header("<<<  BY BRANCH  >>>");

	getUserInput("Enter old Branch : ",key);
	outtextxy(10,120,key);
	getch();
	cleardevice();

	getUserInput("Enter new Barnch : ",value);
	outtextxy(10,120,value);
	getch();
	cleardevice();

	modifyBranch(stdArr,key,value);
	break;
      case 4:
	cleardevice();
	header("<<<  BY GENDER  >>>");

	getUserInput("Enter old Gender : ",key);
	outtextxy(10,120,key);
	getch();
	cleardevice();

	getUserInput("Enter new Gender : ",value);
	outtextxy(10,120,value);
	getch();
	cleardevice();

	modifyGen(stdArr,key,value);
	break;
      case 5:
	cleardevice();
	header("<<<  BY ADDRESS  >>>");

	getUserInput("Enter old Address : ",key);
	outtextxy(10,120,key);
	getch();
	cleardevice();

	getUserInput("Enter new Address : ",value);
	outtextxy(10,120,value);
	getch();
	cleardevice();

	modifyAdd(stdArr,key,value);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      default:
	cleardevice();
	center(12, "Wrong option!!!");
	getch();
    }
    cleardevice();
    }
    }
  }

}

//modifying.....
void modifyRollNo(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].roll, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();

    center(12, "Not found!!!");
    getch();
  }
}


void modifyName(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].name, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();

    center(12, "Not found!!!");
    getch();
  }
}

void modifyBranch(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].branch, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].branch, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();

    center(12, "Not found!!!");
    getch();
  }
}

void modifyGen(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].gen, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].gen, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();

    center(12, "Not found!!!");
    getch();
  }
}

void modifyAdd(std stdArr[],char key[],char value[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].add, key)==0)
    {
      fg=1;
      break;
    }
    index++;
  }

  if(fg==1)
  {
    strcpy(stdArr[i].add, value);
    printTabs(stdArr,p,index);
    getch();
  }
  else
  {
    cleardevice();

    center(12, "Not found!!!");
    getch();
  }
}
//ended modifying

void deleteRecords(std stdArr[])
{
  int opn=0;
  cleardevice();
  int x=100, y=100;
  while(1)
  {
    drawArrow(x,y);
    setcolor(9);
    setbkcolor(11);
    header("<<< DELETE RECORDS >>>");
    centerList("01. BY ROLL NUMBER");
    centerList("02. BY NAME");
    centerList("03. BY BRANCH");
    centerList("04. BY GENDER");
    centerList("05. BY CITY");
    centerList("06. BY STATE");
    centerList("07. BY DISTIC");
    centerList("08. BY NATIONALITY");
    centerList("00. EXIT");
    textPos=6;
    center(26, "Choos an option (0 for back) : ");

    if(kbhit())
      {
	//cleardevice();
	char key = getch();
	if(key == 0 || key == 224)
	{
	  key = getch();
	}
	
	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn ==0 || opn ==1)
	    {
	      opn = 9;
	      eraseArrow(x,y);
	      y=100;
	      y += 16*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=9)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      //y += 2*16;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12, "BACKED!!!");
	  getch();
	  break;
	}
	if(key == 13)
	{
      if(opn == 9)
      {
	 cleardevice();
	 center(12, "BACKED!!!");
	 getch();
	 break;
      }

    switch(opn)
    {
      case 1:
	char str[20];
	cleardevice();
	header("<<<  BY ROLL NO  >>>");

	getUserInput("Enter Roll Number : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	deleteRollNo(stdArr,str);
	break;
      case 2:
	cleardevice();
	header("<<<  BY NAME  >>>");

	getUserInput("Enter Name : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	deleteName(stdArr,str);
	break;
      case 3:
	cleardevice();
	header("<<<  BY BRANCH  >>>");

	getUserInput("Enter Branch : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	deleteBranch(stdArr,str);
	break;
      case 4:
	str[20];
	cleardevice();
	header("<<<  BY GENDER  >>>");

	getUserInput("Enter Gender : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	deleteGen(stdArr,str);
	break;
      case 5:
	str[20];
	cleardevice();
	header("<<<  BY ADDRESS  >>>");

	getUserInput("Enter Address : ",str);
	outtextxy(10,120,str);
	getch();
	cleardevice();

	deleteAdd(stdArr,str);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      default:
	cleardevice();

	center(12, "Wrong option!!!");
	getch();
    }
    cleardevice();
    }
    }
  }

}

//deleting....
void deleteRollNo(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].roll, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    cleardevice();

    printTabs(stdArr,p,index-1);
    center(12, "DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    cleardevice();
    
    center(12, "Not found!!!");
    getch();
  }
}

void deleteName(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].name, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    cleardevice();

    printTabs(stdArr,p,index-1);
    center(12, "DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    cleardevice();
    
    center(12, "Not found!!!");
    getch();
  }
}

void deleteBranch(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].branch, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    cleardevice();

    printTabs(stdArr,p,index-1);
    center(12, "DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    cleardevice();
    
    center(12, "Not found!!!");
    getch();
  }
}

void deleteGen(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].gen, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    cleardevice();

    printTabs(stdArr,p,index-1);
    center(12, "DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    cleardevice();
    
    center(12, "Not found!!!");
    getch();
  }
}
void deleteAdd(std stdArr[],char str[])
{
  int i,fg=0,index=0;
  for(i=0; i<ct; i++)
  {
    if(strcmpi(stdArr[i].add, str)==0)
    {
      fg=1;
      index++;
      break;
    }
    else
    {
      index++;
    }
  }

  if(fg==1)
  {
    int i;
    cleardevice();
    
    printTabs(stdArr,p,index-1);
    center(12, "DELETED SUCCESSFULLY");
    for(i=index-1; i<ct; i++)
    {
     stdArr[i] = stdArr[i+1];
    }
    getch();
    ct--;
  }
  else
  {
    cleardevice();
    
    center(12, "Not found!!!");
    getch();
  }
}
//.....................

void failureReports(std stdArr[])
{
    cleardevice();
    header("<<< FAILUR REPORTS >>>");
    char buffer[200];
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
    "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
    line(h+2,'~');
    int i;
    for(i=0; i<ct; i++)
    {
      if(percent(stdArr,i)<35)
      {
        char buffer[200];
	sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
        stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
	stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
	outtextxy(0,16*(h+4),buffer);
        h+=2;
      }
    }
    getch();
    h=6;
}

//percentage.......
int percent(std stdArr[],int ind)
{
  int m = stdArr[ind].math;
  int p = stdArr[ind].phy;
  int c = stdArr[ind].chem;
  int per = (m+p+c)/3;
  return per;
}//ended percent

void highestScorer(std stdArr[])
{
  cleardevice();
  header("<<< HIGHEST SCORER >>>");
  char buffer[200]; 
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  int ind=0;
  int max = percent(stdArr,0);
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>max)
    {
       ind++;
    }
  }
  sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[ind].roll,
  stdArr[ind].name,stdArr[ind].branch,stdArr[ind].gen,stdArr[ind].add,
  stdArr[ind].math,stdArr[ind].phy,stdArr[ind].chem,"P");
  outtextxy(0,16*(h+4),buffer);
  getch();
}

void sortRecords(std stdArr[])
{
  int opn=0;
  cleardevice();
  int x=100, y=100;
  setcolor(9);
  setbkcolor(11);
  while(1)
  {
    drawArrow(x,y);
    header("<<< SORT RECORDS >>>");

    centerList("01. BY ROLL NUMBER");
    centerList("02. BY NAME");
    centerList("03. BY BRANCH");
    centerList("04. BY GENDER");
    centerList("05. BY CITY");
    centerList("06. BY STATE");
    centerList("07. BY DISTIC");
    centerList("08. BY NATIONALITY");
    centerList("00. EXIT");
    textPos=6;
    center(26, "Choos an option (0 for back) : ");


      if(kbhit())
      {
	//cleardevice();
	char key = getch();
	if(key == 0 || key == 224)
	{
	  key = getch();
	}
	
	eraseArrow(x,y);
	switch(key)
	{
	  case 72:   //UP
	    if( opn ==0 || opn ==1)
	    {
	      opn = 9;
	      eraseArrow(x,y);
	      y=100;
	      y += 16*16;
	      break;
	    }
	    else
	    {
	      y -= 2*16;
	      opn -=1;
	      break;
	    }
	  case 80:  //Down
	    if(opn >=9)
	    {
	      opn = 1;
	      eraseArrow(x,y);
	      y=100;
	      //y += 2*16;
	      break;
	    }
	    else
	    {
	       y += 2*16;
	       opn +=1;
	       break;
	    }
	}
	
	drawArrow(x,y);
	if(key == 27)
	{
	  cleardevice();
	  center(12, "BACKED!!!");
	  getch();
	  break;
	}
	if(key == 13)
	{
      if(opn == 9)
      {
	 cleardevice();
	 center(12, "BACKED!!!");
	 getch();
	 break;
      }
    switch(opn)
    {
      case 1:
	cleardevice();
	header("<<<  BY ROLL NO  >>>");
	sortRollNo(stdArr);
	break;
      case 2:
	cleardevice();
	header("<<<  BY NAME >>>");
	sortName(stdArr);
	break;
      case 3:
	cleardevice();
	header("<<<  BY BRANCH  >>>");
	sortBranch(stdArr);
	break;
      case 4:
	cleardevice();
	header("<<<  BY GENDER  >>>");
	sortGen(stdArr);
	break;
      case 5:
	cleardevice();
	header("<<<  BY ADDRESS  >>>");
	sortAdd(stdArr);
	break;
      case 6:
	break;
      case 7:
	break;
      case 8:
	break;
      default:
	cleardevice();

	center(12, "Wrong option!!!");
	getch();
    }
    cleardevice();
    }
    }
  }
}

//sorting..........................
int compareRoll(const void *a, const void *b)
{
  return strcmpi(((std *)a)->roll, ((std *)b)->roll);
}

void sortRollNo(std stdArr[])
{
  qsort(stdArr,ct,sizeof(std),compareRoll);
  char buffer[200];
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
      outtextxy(0,(10+i+i),buffer);
    }
    else
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      outtextxy(0,(10+i+i),buffer);
    }
  }
  getch();
}

int compareName(const void *a, const void *b)
{
  return strcmpi(((std *)a)->name, ((std *)b)->name);
}
void sortName(std stdArr[])
{
  qsort(stdArr,ct,sizeof(std),compareName);
  char buffer[200]; 
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
      outtextxy(0,(10+i+i),buffer);
    }
    else
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      outtextxy(0,(10+i+i),buffer);
    }
  }
  getch();
}

int compareBranch(const void *a, const void *b)
{
  return strcmpi(((std *)a)->branch, ((std *)b)->branch);
}
void sortBranch(std stdArr[])
{
  qsort(stdArr,ct,sizeof(std),compareBranch);
  char buffer[200]; 
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
      outtextxy(0,(10+i+i),buffer);
    }
    else
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      outtextxy(0,(10+i+i),buffer);
    }
  }
  getch();
}

int compareGen(const void *a, const void *b)
{
  return strcmpi(((std *)a)->gen, ((std *)b)->gen);
}
void sortGen(std stdArr[])
{
  qsort(stdArr,ct,sizeof(std),compareGen);
  char buffer[200]; 
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
      outtextxy(0,(10+i+i),buffer);
    }
    else
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      outtextxy(0,(10+i+i),buffer);
    }
  }
  getch();
}

int compareAdd(const void *a, const void *b)
{
  return strcmpi(((std *)a)->add, ((std *)b)->add);
}
void sortAdd(std stdArr[])
{
  qsort(stdArr,ct,sizeof(std),compareAdd);
  char buffer[200];
    sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4s%-4s%-4s%-4s\n","RollNo", "Name",
     "Branch", "Gender", "City","Mth","Phy","Che","Rslt");
    outtextxy(0,16*h,buffer);
  line(h+2,'~');
  int i;
  for(i=0; i<ct; i++)
  {
    if(percent(stdArr,i)>35)
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"P");
      outtextxy(0,(10+i+i),buffer);
    }
    else
    {
      char buffer[200];
      sprintf(buffer,"%-11s%-15s%-11s%-7s%-20s%-4d%-4d%-4d%-4s\n",stdArr[i].roll,
      stdArr[i].name,stdArr[i].branch,stdArr[i].gen,stdArr[i].add,
      stdArr[i].math,stdArr[i].phy,stdArr[i].chem,"F");
      outtextxy(0,(10+i+i),buffer);
    }
  }
  getch();
}
//.....................

void board(char str[]) {
    int i;

    // Draw the Tic-Tac-Toe grid lines
    // Vertical lines
    setcolor(RED);

    //(x1,x4) |(x2,x4)
    //(x1,x5) | (x2,x5)

    //(x3,x3) (x6,x3)
    //----------------
    //(x3,x1)  (x6,x1)

    int x1 = 19*16;
    int x2 = 26*16;
    int x3 = 13*16;
    int x4 = 7*16;
    int x5 = 25*16;
    int x6 = 32*16;

    line(x1, x4, x1, x5); // First vertical line
    line(x2, x4, x2, x5); // Second vertical line

    // Horizontal lines
    line(x3, x3, x6, x3); // First horizontal line
    line(x3, x1, x6, x1); // Second horizontal line

    // Loop to place symbols (X or O) in their respective positions
    for (i = 0; i < 9; i++) {
	int x = 250 + (i % 3) * 100;  // X position (column)
	int y = 150 + (i / 3) * 100;  // Y position (row)
	if (str[i] == 'O') {
	    setcolor(BLUE); // Set the color to red for 'O'
	    outtextxy(x, y, "O");  // Display 'O'
	} else if (str[i] == 'X') {
	    setcolor(RED); // Set the color to blue for 'X'
	    outtextxy(x, y, "X");  // Display 'X'
	}
    }
}

int printPositionValid(char str[], char sym, int i) {
    if (str[i - 1] == '0') {  // Check if the position is empty (marked '0')
	str[i - 1] = sym;     // Place the symbol in the board
	return 1;
    } else {
	cleardevice();
	setcolor(WHITE);
	cleardevice();
	setcolor(RED);
	center(12,"Invalid position! Already filled!");
	getch();
	return 0;
    }
}

int choos(char str[], int opn, char sym) {
    if (opn >= 1 && opn <= 9) {
	return printPositionValid(str, sym, opn);
    } else if (opn == 0) {
	cleardevice();
	setcolor(RED);
	center(12,"Game Terminated!!!");
	getch();
	return -1; // Signal termination
    } else {
	cleardevice();
	setcolor(RED);
	outtextxy(200, 50, "Wrong option! Choose a number between 1-9.");
	getch();
	return 0;
    }
}

void printWin(char sym,char str[]) {
    int i;
    cleardevice();

    if (sym == 'O') {
	cleardevice();
	board(str);
	center(3,"Hooray!!!!, Player 1 (O) wins!!!");
	int i;
	for (i = 0; i < 9; i++) {
	  str[i] = '0';
	}
    } else {
	cleardevice();
	board(str);
	center(3,"Hooray!!!!, Player 2 (X) wins!!!");
	for (i = 0; i < 9; i++) {
	  str[i] = '0';
	}
    }

    getch();
}

int checkWin(char str[], char sym) {
    int winPatterns[8][3] = {
	{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
	{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
	{0, 4, 8}, {2, 4, 6}  // Diagonals
    };

    for (int i = 0; i < 8; i++) {
	if (str[winPatterns[i][0]] == sym &&
	    str[winPatterns[i][1]] == sym &&
	    str[winPatterns[i][2]] == sym) {
	    return 1;
	}
    }
    return 0;
}

void win(char str[], char sym) {
    if (checkWin(str, sym)) {
	printWin(sym,str);
    } else {
	int filled = 1;
	for (int i = 0; i < 9; i++) {
	    if (str[i] == '0') {
		filled = 0;
		break;
	    }
	}
	if (filled) {
	    cleardevice();
	    outtextxy(150, 200, "GAME DRAW!!!");
	    for (i = 0; i < 9; i++) {
	      str[i] = '0';
	    }
	    getch();
	}
    }
}

void games() {
    char str[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '\0'};
    int opn;
    int ch = 1; // Initialize to 1 to start with Player 1 (O)
    int chk;

    cleardevice();
    setcolor(WHITE);
    setcolor(9);
    setbkcolor(11);
    center(12, "Welcome to Tic Tac Toe ");
    center(14,"Press any key to start the game.");
    getch();

    do {
	cleardevice();
	setcolor(BLUE);
	header("<<< Tic Tac Toe >>>");
	board(str); // Draw the current state of the board

	if (ch % 2 == 1) {
	    setcolor(BLUE);
	    outtextxy(0, 450, "Player 1 (O): Position {1-9} or 0 to quit: ");
	} else {
	    setcolor(RED);
	    outtextxy(0, 450, "Player 2 (X): Position {1-9} or 0 to quit: ");
	}

        scanf("%d", &opn); // Get player choice
        chk = choos(str, opn, ch % 2 == 1 ? 'O' : 'X'); // Place symbol on board
        if (chk == -1) break; // Exit if game is terminated

        win(str, ch % 2 == 1 ? 'O' : 'X'); // Check for win
	ch++; // Switch player
    } while (opn != 0);
}

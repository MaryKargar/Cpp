/***************************************************************/
/****************GUI C++ Menu***********************************/
/****************Use Arrow key and Enter Key to use it**********/
/***************************************************************/
 

 
#include<iostream.h>
#include<conio.h>
#include <dos.h>
#include<graphics.h>
          
//Menu Global Item
#define pixTOrc(x) (8*(x-1))  //convert pixel into row and col format
#define INC 5  //Increment Distance Between Menu Items
#define ROW 15 //Row Value for Menu Item
#define COL 8 //Column Value for Menu Item
#define MAXMENU 5 //Total menu items
							
// To display the Inventory Main menu options
typedef char option[20];





option MMenu[]= {
             "View Account",
				"Transactions",
				"New Accont",
				"Edit Account",
				"Quit"
		      };
// Function to displays all the menu prompt messages from the pointer array of option a[]
void normalvideo(int x,int y,char *str)
{
   x=pixTOrc(x);
   y=pixTOrc(y);
   outtextxy(x,y,str);
}
// Function to move the cursor on the menu prompt with a reverse video color            
void selectedMenu(int x,int y,char *str)
{
   x=pixTOrc(x);
   y=pixTOrc(y);
   setcolor(5);  //Selected Item Color
   sound(400);
   delay(100);
   nosound();
   outtextxy(x,y,str);
   setcolor(WHITE); //Unselected Item Color
   sound(500);
   delay(100);
   nosound();
}
//Keep Track of which arrow key is pressed
char menu()
{
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   setcolor(WHITE);  //Initial Menu Item Color
   int i,done;
   for(i = 1; i < MAXMENU; i++)
   normalvideo(COL, (i*INC)+ROW, MMenu[i]);
   selectedMenu(COL,ROW, MMenu[0]);
   i = done = 0;
   do
   {
      /**Status Bar Code**/
      setfillstyle(SOLID_FILL,BLUE);
      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      bar(pixTOrc(2),pixTOrc(52.5),pixTOrc(75),pixTOrc(55));
      setcolor(LIGHTCYAN);
      switch(i)
      {
        case 0 : outtextxy(pixTOrc(5),pixTOrc(52.75),"View Account --> View Detail of an account");
                 break;
        case 1 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Transactions --> Do transaction Debit/Credit");
         		  break;
  
   
        case 2 : outtextxy(pixTOrc(5),pixTOrc(52.75),"New Accont --> Create a new account for customer");
                 break;
        case 3 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Edit Account --> Edit an existing account");
                 break;
        case 4 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Close the Program");
                 break;
      }
      /**status Bar ends**/
      setcolor(WHITE);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      int key = getch();
      switch (key)
      {
         case 00: key = getch();
            switch (key)
            {
               case 72: normalvideo(COL, (i*INC)+ROW, MMenu[i]);
          	          i--;
             		      if (i == -1)
                           i = MAXITEM-1;
                           selectedMenu(COL,(i*INC)+ROW,MMenu[i]);
                        break;
               case 80: normalvideo(COL, (i*INC)+ROW, MMenu[i]);
           	          i++;
           	          if (i == MAXITEM)
                           i = 0;
                           selectedMenu(COL, (i*INC)+ROW, MMenu[i]);
                        break;
            }
            break;
         case 13: done = 1;
      }
   }
   while (!done);
   return(i+49);
}
//This part you can use for main functionality of the menu
void mainArea()
{
   setcolor(BLUE);
   outtextxy(pixTOrc(30),pixTOrc(20),"http://samavi.info/");
   setcolor(YELLOW);
}
/* Code for displaying the main menu*/
void call_menu()
{
   char choice;
   do
   {
      choice = menu();
      switch (choice)
      {
         case '1': setcolor(BLUE);
                   outtextxy(pixTOrc(40),pixTOrc(15),"View Account");
                   mainArea();
                   getch();
                   setfillstyle(SOLID_FILL,LIGHTGRAY);
                   bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
                   mainArea();
                   break;
       	case '2':
                   setcolor(BLUE);
       	         outtextxy(pixTOrc(40),pixTOrc(15),"Transactions");
       	         mainArea();
       	         getch();
       	         setfillstyle(SOLID_FILL,LIGHTGRAY);
       	         bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
       	         mainArea();
       	         break;
       	case '3':
       	         setcolor(BLUE);
       	         outtextxy(pixTOrc(40),pixTOrc(15),"New Accont");
       	         mainArea();
       	         getch();
       	         setfillstyle(SOLID_FILL,LIGHTGRAY);
       	         bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
       	         mainArea();
       	         break;
       	case '4':
       	         setcolor(BLUE);
       	         outtextxy(pixTOrc(40),pixTOrc(15),"Edit Account");
       	         mainArea();
       	         getch();
       	         setfillstyle(SOLID_FILL,LIGHTGRAY);
       	         bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
       	         mainArea();
       	         break;
       	case '5':    //Close the project
       	         setcolor(BLUE);
       	         outtextxy(pixTOrc(40),pixTOrc(15),"Quit");
       	         mainArea();
       	         delay(1000);
       	         setfillstyle(SOLID_FILL,LIGHTGRAY);
       	         bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
       	         mainArea();
       	         goto exit;
      }
   } while (choice != MAXITEM);
exit:
} 
void main()
{
   int i,j;
   int gd=DETECT,gm=0;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   setcolor(BLACK);
   rectangle(0,0,640,480);
   setfillstyle(SOLID_FILL,LIGHTGRAY);
   bar(2,1,637,478);
   setfillstyle(SOLID_FILL,BLACK);
   bar(1,3,637,50);
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   setcolor(YELLOW);
   outtextxy(pixTOrc(12),pixTOrc(1)," BANKING SYSTEM PROJECT ");
   setfillstyle(CLOSE_DOT_FILL,DARKGRAY);
   bar(pixTOrc(7),pixTOrc(14),pixTOrc(25),pixTOrc(50));
   call_menu();
   closegraph();
}
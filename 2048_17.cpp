#include<string.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
static int sc=0; //Static allocated variable for score maintanance
int fn1(int i)//To return the coordinates of row subscript
{if(i==0)
	return 160;
 if(i==1)
	return 220;
 if(i==2)
	return 280;
 if(i==3)
	return 340;
}

int fn2(int j)//To return the coordinates of column subscript
{if(j==0)
	return 200;
  if(j==1)
	return 260;
  if(j==2)
	return 320;
  if(j==3)
	return 380;
}
//To check if the player has won the game
	int youwin(int A[4][4])
	{for(int i=0;i<4;i++)
		 for(int j=0;j<4;j++)     
		 if(A[i][j]==2048)
		 return 1;
	  return 0;
	}

//To check if game is over
int gameover(int A[4][4])
{for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
{if(A[i][j]==0)
	 return 1;
	 if(A[i][j]==A[i+1][j]&&i+1<4)
	 return 1;
	 if(A[i][j]==A[i-1][j]&&i-1>=0)
	 return 1;
	 if(A[i][j]==A[i][j+1]&&j+1<4)
	 return 1;
	 if(A[i][j]==A[i][j-1]&&j-1>=0)
	 return 1;
	}
	 return 0;
	}
//returns value based on which the next number is put
int check(int A[4][4],int B[4][4])
{for(int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  if(A[i][j]!=B[i][j])
  return 1;
  return 0;
}
//To display the game using graphics
void display(int A[4][4])
{cleardevice();
  settextstyle(GOTHIC_FONT, HORIZ_DIR, 7);
  char string[25][25];
  int i,j,c=0,m;
  for(i=0;i<4;i++)
  for(j=0;j<4;j++)
  if(A[i][j]!=0)
  itoa(A[i][j], string[c++], 10);
  else
  strcpy(string[c++]," ");
  setcolor(WHITE);
  itoa(sc, string[16],10);
  outtextxy(235, 0 , "2048");
  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
  outtextxy(235, 110 , "QUIT:Press 'q'");
  outtextxy(235, 70 , "SCORE:");
  outtextxy(350, 70 , string[16]);
  int a=222,b=165;
 //To display the numbers
	int n;
	for(c=0,i=0;i<4;i++,b+=60)
	for(j=0,a=222;j<4;j++,a+=60)
	if(A[i][j]==2)
	{m=fn1(i);
	   n=fn2(j);
	   for(int y=n;y<=n+60;y++)
	{setcolor(BLUE+GREEN);
	  line(y,m,y,m+60);
	}
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
	outtextxy(a, b , "2");
	}
	else if(A[i][j]==4)
	{ m=fn1(i);
	   n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(GREEN);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
	 outtextxy(a, b , "4");
	}
	else if(A[i][j]==8)
	{m=fn1(i);
	  n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(BLUE);
	  line(y,m,y,m+60);
	}
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
	outtextxy(a, b , "8");
	}
	else if(A[i][j]==16)
	{m=fn1(i);
	   n=fn2(j);
	 for(int y=n;y<=n+60;y++)
	{setcolor(BLUE+RED);
	  line(y,m,y,m+60);
	}
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
	outtextxy(a-9, b+8, "16");
	}
	else if(A[i][j]==32)
	{m=fn1(i);
	   n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(RED+GREEN);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
	 outtextxy(a-9, b+8 , "32");
	}
	else if(A[i][j]==64)
	{m=fn1(i);
	  n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(RED);
	  line(y,m,y,m+60);
	 }
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
	 outtextxy(a-9, b+8 , "64");
	}
	else if(A[i][j]==128)
	{m=fn1(i);
	  n=fn2(j);
	 for(int y=n;y<=n+60;y++)
	{setcolor(RED+GREEN);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	 outtextxy(a-10, b+10 , "128");
	}
	else if(A[i][j]==256)
	{m=fn1(i);
	   n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	 {setcolor(RED+BLUE);
	   line(y,m,y,m+60);
	 }
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	 outtextxy(a-10, b+10 , "256");
	}
	 else if(A[i][j]==512)
	{m=fn1(i);
	  n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(BLUE);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
	 outtextxy(a-10, b+10 , "512");
	}
	else if(A[i][j]==1024)
	{m=fn1(i);
	   n=fn2(j);
	  for(int y=n;y<=n+60;y++)
	{setcolor(GREEN);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
	 outtextxy(a-18, b+15 , "1024");
	}
	else if(A[i][j]==2048)
	{m=fn1(i);
	  n=fn2(j);
	 for(int y=n;y<=n+60;y++)
	{setcolor(BLUE+GREEN);
	  line(y,m,y,m+60);
	}
	 setcolor(WHITE);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
	 outtextxy(a-18, b+15 , "2048");
	}
  //To display the grid
	setcolor(LIGHTGREEN);
	line(200,160,200,400);
	line(200,400,440,400);
	line(440,400,440,160);
	line(440,160,200,160);

	setcolor(YELLOW);
	line(200,220,440,220);
	line(200,280,440,280);
	line(200,340,440,340);

	setcolor(RED);
	line(380,160,380,400);
	line(260,160,260,400);
	line(320,160,320,400);
}

//To put new nos in the grid randomly
int put(int A[4][4])
{int r=0,m,n,p,q,i,j;
X:
p=random(5);
n=random(4);
m=random(4);
if(p<=3)
q=2;
else
q=4;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
if(i==m&&j==n)
{if(A[i][j]==0)
{A[i][j]=q;
r++;
}
else
goto X;
if(!r)
break;
}
display(A);
//r==0 if no insertions were made
return r;
}

void down(int A[4][4])
{char ch;
int B[4][4];
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
B[i][j]=A[i][j];
for(j=0;j<4;j++)
for(i=3;i>=0;i--)
{if(A[i][j]==0&&i<4)
{for(int k=i-1;k>=0;k--)
if(A[k][j]!=0)
{A[i][j]=A[k][j];
A[k][j]=0;
break;
}
}
for(int k=i-1;k>=0;k--)							if(A[k][j]==A[i][j]&&k+1==i||A[k][j]==A[i][j]&&A[k+1][j]==0||
A[k][j]==A[i][j]&&A[k+1][j]==0&&A[k+2][j]==0)
{A[i][j]*=2;
sc+=A[i][j];
A[k][j]=0;
break;
}
}
if(check(A,B))
put(A);
}

void up(int A[4][4])
{ int B[4][4];
char ch;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
B[i][j]=A[i][j];
for( j=0;j<4;j++)
for( i=0;i<4;i++)
{if(A[i][j]==0&&i<4)
{for(int k=i+1;k<4;k++)
if(A[k][j]!=0)
{A[i][j]=A[k][j];
A[k][j]=0;
break;
}
}
for(int k=i+1;k<4;k++)
if(A[k][j]==A[i][j]&&k-1==i||A[k][j]==A[i][j]&&A[k-1][j]==0||A[k][j]==A[i][j]&&A[k-1][j]==0&&A[k-2][j]==0)
{A[i][j]*=2;
sc+=A[i][j];
A[k][j]=0;
break;
}
}
if(check(A,B))
put(A);
}

void right(int A[4][4])
{int B[4][4];
char ch;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
B[i][j]=A[i][j];
for(i=0;i<4;i++)
for(j=3;j>=0;j--)
{if(A[i][j]==0)
{for(int k=j-1;k>=0;k--)
if(A[i][k]!=0)
{A[i][j]=A[i][k];
A[i][k]=0;
break;
}
}
for(int k=j-1;k>=0;k--)
if(A[i][k]==A[i][j]&&k+1==j||A[i][k]==A[i][j]&&A[i][k+1]==0
||A[i][k]==A[i][j]&&A[i][k+1]==0&&A[i][k+2]==0)
{A[i][j]*=2;
sc+=A[i][j];
A[i][k]=0;
break;
}
}
if(check(A,B))
put(A);
}

void left(int A[4][4])
{int B[4][4];
char ch;
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
B[i][j]=A[i][j];
for(i=0;i<4;i++)
for(j=0;j<4;j++)
{if(A[i][j]==0)
{for(int k=j+1;k<4;k++)
if(A[i][k]!=0)
{A[i][j]=A[i][k];
A[i][k]=0;
break;
}
}
for(int k=j+1;k<4;k++)
if(A[i][k]==A[i][j]&&k-1==j||A[i][k]==A[i][j]&&A[i][k-1]==0 	      ||A[i][k]==A[i][j]&&A[i][k-1]==0&&A[i][k-2]==0)
{A[i][j]*=2;
sc+=A[i][j];
A[i][k]=0;
break;
}
}
if(check(A,B))
put(A);
}

	void main()
	{char ch,c;
	  int m;
	  int gd = DETECT,gm,ma;
	  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	    X:
		int A[4][4]={0};
		sc=0;
		randomize();
		put(A);
		put(A);
		display(A);
		ch=getch();
		while(ch!='q'||ch!='Q')
		{switch(ch)
		{case 's':down(A);break;
		  case 'w':up(A);break;
		  case 'd':right(A);break;
		  case 'a':left(A);break;
		  case 'q':
		  case 'Q':closegraph();
		  exit(0);
		  default:;
		 }
		if(youwin(A))
		{settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
		 setcolor(WHITE);
		 outtextxy(50,230,"You win!Thanks for playing.");
		  getch();
		  cleardevice();
		  settextstyle(GOTHIC_FONT, HORIZ_DIR,5);
		  outtextxy(70,210,"Do you want to play again?");
		  outtextxy(180,290,"YES");
		  outtextxy(390,290,"NO");
		  c=getch();
		  if(c=='y'||c=='Y')
		  goto X;
		  break;
		}
		if(gameover(A)==0)
		{settextstyle(GOTHIC_FONT, HORIZ_DIR,7);
		  setcolor(WHITE);
		  outtextxy(140,230,"GAME OVER!");
		  settextstyle(GOTHIC_FONT, HORIZ_DIR,5);
		  getch();
		  cleardevice();
		  settextstyle(GOTHIC_FONT, HORIZ_DIR,5);
		  outtextxy(70,210,"Do you want to play again?");
		  outtextxy(70,290,"YES");
		  outtextxy(390,290,"NO");
		  c=getch();
		  if(c=='y'||c=='Y')
		  goto X;
		  break;
		}
		ch=getch();
		 }//while closes
		getch();
		closegraph();
		}

Status 
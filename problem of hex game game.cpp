//making of hex game
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void finish();
bool flag=0;
class table//making of table structure
{
	public:
   char x[8];
};
void checkwinA0(table*,int,int,int,int);
void checkwinA6(table*,int,int,int,int);
void checkwinR0(table*,int,int,int,int);
void checkwinR6(table*,int,int,int,int);
table* maketable() //assigning values to table of hex (*).here * act as gaps.
{

    table* t=(table*)malloc(sizeof(table)*7);
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			t[i].x[j]='*';
	    }
	}
	return(t);
}
void disp(table* t)//to display the ongoing board
{
	cout<<"blue top to bottom"<<endl;
	cout<<"red left to right"<<endl;
	cout<<endl;
	cout<<endl;
		for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<t[i].x[j]<<" ";
		}
		cout<<endl;
	}
	//cout<<"press enter to continue"<<endl;
	//getch();
}
bool isvalid(table* t,int i,int j)//to check whether coordinates written are applicable or not.
{
	if(t[i].x[j]=='*')
	{
		return (true);
	}
	else
	{
		return(false);
	}
}
void insertion(table* t)//to intersect element
{
   	int i,j,m,n;
   	m=8;
   	n=8;
 again:	cout<<"enter the coordinates by first player"<<endl;
	cin>>i>>j;
	if(isvalid(t,i,j))
	{
		t[i].x[j]='B';
	}
	else
	{
		cout<<"oops! wrong coordinates.Try again"<<endl;
		goto again;
	}
	disp(t);
	//system("CLS");//to clear the screen
	if(i==0)
	{
		checkwinA0(t,i,j,m,n);//to check whether player1 has won from top to bottom
		if(flag==1)
		{
			return;
		}
	}
	if(i==6)
	{
		checkwinA6(t,i,j,m,n);//to check whether player1 has won from bottom to top
		if(flag==1)
		{
			return;
		}
	}

again1:	cout<<"enter the coordinates by second player"<<endl;
	cin>>i>>j;
		if(isvalid(t,i,j))
	{
		t[i].x[j]='R';
	}
	else
	{
		cout<<"oops! wrong coordinates.Try again"<<endl;
		goto again1;
	}
	disp(t);
	//system("CLS");
	if(j==0)
	{
		checkwinR0(t,i,j,m,n);//to check whether player2 won from left tp right
		if(flag==1)
		{
			return;
		}
	}
	if(j==6)
	{
		checkwinR6(t,i,j,m,n);// to check whether player2 won from right to left
		if(flag==1)
		{
			return;
		}
	}

}
void checkwinA0(table* t,int i,int j,int m,int n)
{
	if(i==0 &&j==0)
{

	if(t[i+1].x[j]=='B'&&((i+1)!=m||j!=n))
	{

		checkwinA0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinA0(t,i+1,j+1,i,j);
	}
		if(t[i].x[j+1]=='B'&&(i!=m||(j+1)!=n))
	{

		checkwinA0(t,i,j+1,i,j);
	}
	return ;
 }
  if(i==0 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i+1].x[j]=='B'&&((i+1)!=m||j!=n))
	{
		checkwinA0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinA0(t,i+1,j+1,i,j);
	}
		if(t[i].x[j+1]=='B'&&(i!=m ||(j+1)!=n))
	{

		checkwinA0(t,i,j+1,i,j);
	}
	if(t[i].x[j-1]=='B' && (i!=m ||(j-1)!=n))
	{

		checkwinA0(t,i,j-1,i,j);
	}
	if(t[i+1].x[j-1]=='B'&& ((i+1)!=m||(j-1)!=n))
	{

		checkwinA0(t,i+1,j-1,i,j);
	}
	return;
  }
  if((i==1||i==2||i==3||i==4||i==5)&&j==0)
  {
  	if(t[i+1].x[j]=='B'&&((i+1)!=m||j!=n))
	{

		checkwinA0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinA0(t,i+1,j+1,i,j);
	}
	if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{

		checkwinA0(t,i-1,j,i,j);
	}
	if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinA0(t,i-1,j+1,i,j);
	}
		if(t[i].x[j+1]=='B'&&((i)!=m||(j+1)!=n))
	{

		checkwinA0(t,i,j+1,i,j);
	}
	return;
 }
 	if(i==0 &&j==6)
{

	if(t[i].x[j-1]=='B'&&(i!=m||(j-1)!=n))
	{

		checkwinA0(t,i,j-1,i,j);
	}
	if(t[i+1].x[j]=='B'&&((i+1)!=m||(j)!=n))
	{

		checkwinA0(t,i+1,j,i,j);
	}
		if(t[i+1].x[j-1]=='B'&&((i+1)!=m||(j-1)!=n))
	{

		checkwinA0(t,i+1,j-1,i,j);
	}
	return;
 }
 if((i==1||i==2||i==3||i==4||i==5)&&(j==1||j==2||j==3||j==4||j==5))
 {
 		if(t[i].x[j-1]=='B'&&(i!=m||(j-1)!=n))
	{

		checkwinA0(t,i,j-1,i,j);
	}
		if(t[i].x[j+1]=='B'&&(i!=m||(j+1)!=n))
	{

		checkwinA0(t,i,j+1,i,j);
	}
		if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinA0(t,i-1,j-1,i,j);
	}
		if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{
		checkwinA0(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{
		checkwinA0(t,i-1,j,i,j);
	}
		if(t[i+1].x[j-1]=='B'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinA0(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='B'&&((i+1)!=m||(j)!=n))
	{

		checkwinA0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{
		checkwinA0(t,i+1,j+1,i,j);
	}
	return;
}
	if((i==1||i==2||i==3||i==4||i==5)&&j==6)
{
		if(t[i+1].x[j-1]=='B'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinA0(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='B'&&((i+1)!=m||(j)!=n))
	{
		checkwinA0(t,i+1,j,i,j);
	}
	if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{
	    checkwinA0(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{
		checkwinA0(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='B'&&((i)!=m||(j-1)!=n))
	{
		checkwinA0(t,i,j-1,i,j);
	}
	return;
}
if(i==6)
{
	cout<<"Player1 won"<<endl;
	flag=1;
	return;
}
}

void checkwinA6(table* t,int i,int j,int m,int n)
{
	if(i==6 &&j==0)
{

	if(t[i-1].x[j]=='B'&&((i-1)!=m||j!=n))
	{

		checkwinA6(t,i-1,j,i,j);
	}
	if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinA6(t,i-1,j+1,i,j);
	}
		if(t[i].x[j+1]=='B'&&(i!=m||(j+1)!=n))
	{

		checkwinA6(t,i,j+1,i,j);
	}
	return ;
 }
  if(i==6 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinA6(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinA6(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='B'&&((i-1)!=m ||(j)!=n))
	{

		checkwinA6(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='B' && (i!=m ||(j-1)!=n))
	{

		checkwinA6(t,i,j-1,i,j);
	}
	if(t[i].x[j+1]=='B'&& ((i)!=m||(j+1)!=n))
	{

		checkwinA0(t,i,j+1,i,j);
	}
	return;
  }
  if((i==1||i==2||i==3||i==4||i==5)&&j==0)
  {
  	if(t[i+1].x[j]=='B'&&((i+1)!=m||j!=n))
	{

		checkwinA6(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinA6(t,i+1,j+1,i,j);
	}
	if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{

		checkwinA6(t,i-1,j,i,j);
	}
	if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinA6(t,i-1,j+1,i,j);
	}
		if(t[i].x[j+1]=='B'&&((i)!=m||(j+1)!=n))
	{

		checkwinA6(t,i,j+1,i,j);
	}
	return;
 }
 	if(i==6 &&j==6)
{

	if(t[i].x[j-1]=='B'&&(i!=m||(j-1)!=n))
	{

		checkwinA6(t,i,j-1,i,j);
	}
	if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{

		checkwinA6(t,i-1,j,i,j);
	}
		if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{

		checkwinA6(t,i-1,j-1,i,j);
	}
	return;
 }
 if((i==1||i==2||i==3||i==4||i==5)&&(j==1||j==2||j==3||j==4||j==5))
 {
 		if(t[i].x[j-1]=='B'&&(i!=m||(j-1)!=n))
	{

		checkwinA6(t,i,j-1,i,j);
	}
		if(t[i].x[j+1]=='B'&&(i!=m||(j+1)!=n))
	{

		checkwinA6(t,i,j+1,i,j);
	}
		if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinA6(t,i-1,j-1,i,j);
	}
		if(t[i-1].x[j+1]=='B'&&((i-1)!=m||(j+1)!=n))
	{
		checkwinA6(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{
		checkwinA6(t,i-1,j,i,j);
	}
		if(t[i+1].x[j-1]=='B'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinA6(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='B'&&((i+1)!=m||(j)!=n))
	{

		checkwinA6(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='B'&&((i+1)!=m||(j+1)!=n))
	{
		checkwinA6(t,i+1,j+1,i,j);
	}
	return;
}
	if((i==1||i==2||i==3||i==4||i==5)&&j==6)
{
		if(t[i+1].x[j-1]=='B'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinA6(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='B'&&((i+1)!=m||(j)!=n))
	{
		checkwinA6(t,i+1,j,i,j);
	}
	if(t[i-1].x[j-1]=='B'&&((i-1)!=m||(j-1)!=n))
	{
	    checkwinA6(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j]=='B'&&((i-1)!=m||(j)!=n))
	{
		checkwinA6(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='B'&&((i)!=m||(j-1)!=n))
	{
		checkwinA6(t,i,j-1,i,j);
	}
	return;
}
if(i==0)
{
	cout<<"Player1 won"<<endl;
	flag=1;
	return;
}
}
void checkwinR0(table* t,int i,int j,int m,int n)
{
	if(i==0 &&j==0)
{

	if(t[i+1].x[j]=='R'&&((i+1)!=m||j!=n))
	{

		checkwinR0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i+1,j+1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	return ;
 }
  if(i==0 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i+1].x[j]=='R'&&((i+1)!=m||j!=n))
	{
		checkwinR0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i+1,j+1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m ||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	if(t[i].x[j-1]=='R' && (i!=m ||(j-1)!=n))
	{

		checkwinR0(t,i,j-1,i,j);
	}
	if(t[i+1].x[j-1]=='R')
	{

		checkwinR0(t,i+1,j-1,i,j);
	}
	return;
  }
  	if(i==6 &&j==0)
{

	if(t[i-1].x[j]=='R'&&((i-1)!=m||j!=n))
	{

		checkwinR0(t,i-1,j,i,j);
	}
	if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i-1,j+1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	return ;
 }
  if((i==1||i==2||i==3||i==4||i==5)&&j==0)
  {
  	if(t[i+1].x[j]=='R'&&((i+1)!=m||j!=n))
	{

		checkwinR0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i+1,j+1,i,j);
	}
	if(t[i-1].x[j]=='R'&&((i-1)!=m||(j)!=n))
	{

		checkwinR0(t,i-1,j,i,j);
	}
	if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i-1,j+1,i,j);
	}
		if(t[i].x[j+1]=='R'&&((i)!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	return;
 }

 if((i==1||i==2||i==3||i==4||i==5)&&(j==1||j==2||j==3||j==4||j==5))
 {
 		if(t[i].x[j-1]=='R'&&(i!=m||(j-1)!=n))
	{

		checkwinR0(t,i,j-1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
		if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinR0(t,i-1,j-1,i,j);
	}
		if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{
		checkwinR0(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='R'&&((i-1)!=m||(j)!=n))
	{
		checkwinR0(t,i-1,j,i,j);
	}
		if(t[i+1].x[j-1]=='R'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinR0(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='R'&&((i+1)!=m||(j)!=n))
	{

		checkwinR0(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{
		checkwinR0(t,i+1,j+1,i,j);
	}
	return;
}
if(i==6 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinR0(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinR0(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='R'&&((i-1)!=m ||(j)!=n))
	{

		checkwinR0(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='R' && (i!=m ||(j-1)!=n))
	{

		checkwinR0(t,i,j-1,i,j);
	}
	if(t[i].x[j+1]=='R'&&((i)!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	return;
  }

if(j==6)
{
	cout<<"Player2 won"<<endl;
	flag=1;
	return;
}
}


void checkwinR6(table* t,int i,int j,int m,int n)
{

  if(i==6 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinR6(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{

		checkwinR6(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='R'&&((i-1)!=m ||(j)!=n))
	{

		checkwinR6(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='R' && (i!=m ||(j-1)!=n))
	{

		checkwinR6(t,i,j-1,i,j);
	}
	if(t[i].x[j+1]=='R'&& ((i)!=m||(j+1)!=n))
	{

		checkwinR0(t,i,j+1,i,j);
	}
	return;
  }

 	if(i==6 &&j==6)
{

	if(t[i].x[j-1]=='R'&&(i!=m||(j-1)!=n))
	{

		checkwinR6(t,i,j-1,i,j);
	}
	if(t[i-1].x[j]=='R'&&((i-1)!=m||(j)!=n))
	{

		checkwinR6(t,i-1,j,i,j);
	}
		if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{

		checkwinR6(t,i-1,j-1,i,j);
	}
	return;
 }
 if((i==1||i==2||i==3||i==4||i==5)&&(j==1||j==2||j==3||j==4||j==5))
 {
 		if(t[i].x[j-1]=='R'&&(i!=m||(j-1)!=n))
	{

		checkwinR6(t,i,j-1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m||(j+1)!=n))
	{

		checkwinR6(t,i,j+1,i,j);
	}
		if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{
		checkwinR6(t,i-1,j-1,i,j);
	}
		if(t[i-1].x[j+1]=='R'&&((i-1)!=m||(j+1)!=n))
	{
		checkwinR6(t,i-1,j+1,i,j);
	}
		if(t[i-1].x[j]=='R'&&((i-1)!=m||(j)!=n))
	{
		checkwinR6(t,i-1,j,i,j);
	}
		if(t[i+1].x[j-1]=='R'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinR6(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='R'&&((i+1)!=m||(j)!=n))
	{

		checkwinR6(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{
		checkwinR6(t,i+1,j+1,i,j);
	}
	return;
}
	if((i==1||i==2||i==3||i==4||i==5)&&j==6)
{
		if(t[i+1].x[j-1]=='R'&&((i+1)!=m||(j-1)!=n))
	{
		checkwinR6(t,i+1,j-1,i,j);
	}
	if(t[i+1].x[j]=='R'&&((i+1)!=m||(j)!=n))
	{
		checkwinR6(t,i+1,j,i,j);
	}
	if(t[i-1].x[j-1]=='R'&&((i-1)!=m||(j-1)!=n))
	{
	    checkwinR6(t,i-1,j-1,i,j);
	}
	if(t[i-1].x[j]=='R'&&((i-1)!=m||(j)!=n))
	{
		checkwinR6(t,i-1,j,i,j);
	}
	if(t[i].x[j-1]=='R'&&((i)!=m||(j-1)!=n))
	{
		checkwinR6(t,i,j-1,i,j);
	}
	return;
}

 if(i==0 &&j==6)
{

	if(t[i].x[j-1]=='R'&&(i!=m||(j-1)!=n))
	{

		checkwinR6(t,i,j-1,i,j);
	}
	if(t[i+1].x[j]=='R'&&((i+1)!=m||(j)!=n))
	{

		checkwinR6(t,i+1,j,i,j);
	}
		if(t[i+1].x[j-1]=='R'&&((i+1)!=m||(j-1)!=n))
	{

		checkwinR6(t,i+1,j-1,i,j);
	}
	return;
 }
 if(i==0 && (j==1||j==2||j==3||j==4||j==5))
  {
  		if(t[i+1].x[j]=='R'&&((i+1)!=m||j!=n))
	{
		checkwinR6(t,i+1,j,i,j);
	}
	if(t[i+1].x[j+1]=='R'&&((i+1)!=m||(j+1)!=n))
	{

		checkwinR6(t,i+1,j+1,i,j);
	}
		if(t[i].x[j+1]=='R'&&(i!=m ||(j+1)!=n))
	{

		checkwinR6(t,i,j+1,i,j);
	}
	if(t[i].x[j-1]=='R' && (i!=m ||(j-1)!=n))
	{

		checkwinR6(t,i,j-1,i,j);
	}
	if(t[i+1].x[j-1]=='R'&& ((i+1)!=m||(j-1)!=n))
	{

		checkwinR6(t,i+1,j-1,i,j);
	}
	return;
  }
if(j==0)
{
	cout<<"Player2 won"<<endl;
	flag=1;
	return;
}
}
int main()
{
	table* t=maketable();
	int i=49;
	cout<<"hello ,welcome to game to hex."<<endl;
	while(i)
	{
		insertion(t);
		if(flag==1)
		{
			break;
		}
		i--;
	}


  delete(t);

	return 0;
}

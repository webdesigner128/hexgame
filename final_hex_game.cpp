//making of hex game
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<vector>
using namespace std;
void finish();
bool flag=0;
class table//making of table structure
{
	public:
   char x[8];
};
void checkwinA(table*,int,int,vector<vector<int> >&);
void checkwinB(table*,int,int,vector<vector<int> >&);
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
	cout<<"A top to bottom"<<endl;
	cout<<"B left to right"<<endl;
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

}
bool isvalid(table* t,int i,int j)//to check whether coordinates written are applicable or not.
{
	 if(i>6 || j>6 || i<0 || j<0 )
	 {
	 		return(false);
	 }
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
 while(1)
 {
 	cout<<"enter the coordinates by first player"<<endl;
	cin>>i>>j;
	if(isvalid(t,i,j))
	{
	    	t[i].x[j]='A';
	    	disp(t);
	    	vector<vector<int> > vis(7,vector<int>(7,0));
	    	for(int k=0;k<=6;k++)
	    	{
	    		 if(t[0].x[k]=='A')
	    		    checkwinA(t,0,j,vis); //to check whether player1 has won from bottom to top
			}
	    	if(flag==1)
	    	{
		    	return;
	    	}
	    
		break;
	}
	else
	{
		cout<<"oops! wrong coordinates.Try again"<<endl;
		
	}
}
	//system("CLS");//to clear the screen


  while(1)
{
	cout<<"enter the coordinates by second player"<<endl;
	cin>>i>>j;
		if(isvalid(t,i,j))
	{
		   t[i].x[j]='B';
		 	disp(t);
		 	vector<vector<int> > vis(7,vector<int>(7,0));
		 		for(int k=0;k<=6;k++)
	    	{
	    		 if(t[k].x[0]=='B')
	    		    checkwinA(t,i,0,vis); //to check whether player1 has won from bottom to top
			}
		      if(flag==1)
	    	{
		    	return;
	     	}
	   
	   break;
	}
	else
	{
		cout<<"oops! wrong coordinates.Try again"<<endl;
	
	}

}

}
void checkwinA(table* t,int i,int j,vector<vector<int> >& vis)
{
             if(i>6 || j>6 || i<0 || j<0 ||t[i].x[j]!='A')
	 {
	 		return ;
	 }

	 if(i==6)
	 {
	 	cout<<" player A is winner "<<endl;
	 	flag=1;
	 	return ;
	 	
	 }
	 if(vis[i][j]==1)
	 {
	 	return ;
	 }
	vis[i][j]=1;
	    checkwinA(t,i-1,j-1,vis);
		if(flag==1)
		  return;
		  	checkwinA(t,i-1,j,vis);
		if(flag==1)
		  return;
		  	checkwinA(t,i-1,j+1,vis);
		if(flag==1)
		  return;
		  	checkwinA(t,i,j-1,vis);
		if(flag==1)
		  return;
		  	checkwinA(t,i,j+1,vis);
		if(flag==1)
		  return;
		  	checkwinA(t,i+1,j-1,vis);
		if(flag==1)
		  return;
		  checkwinA(t,i+1,j,vis);
		if(flag==1)
		  return;
		  checkwinA(t,i+1,j+1,vis);
		if(flag==1)
		  return;
		  
		  vis[i][j]=0;
		  return;
}

void checkwinB(table* t,int i,int j,vector<vector<int> >& vis)
{
                if(i>6 || j>6 || i<0 || j<0 ||t[i].x[j]!='B')
	 {
	 		return ;
	 }

	 if(j==6)
	 {
	 	cout<<" player B is winner "<<endl;
	 	flag=1;
	 	return ;
	 	
	 }
	 if(flag==1) return ;
	 if(vis[i][j]==1)
	 {
	 	return ;
	 }
	vis[i][j]=1;
	    checkwinB(t,i-1,j-1,vis);
		if(flag==1)
		  return;
		  	checkwinB(t,i-1,j,vis);
		if(flag==1)
		  return;
		  	checkwinB(t,i-1,j+1,vis);
		if(flag==1)
		  return;
		  	checkwinB(t,i,j-1,vis);
		if(flag==1)
		  return;
		  	checkwinB(t,i,j+1,vis);
		if(flag==1)
		  return;
		  	checkwinB(t,i+1,j-1,vis);
		if(flag==1)
		  return;
		  checkwinB(t,i+1,j,vis);
		if(flag==1)
		  return;
		  checkwinB(t,i+1,j+1,vis);
		if(flag==1)
		  return;
		  
		  vis[i][j]=0;
		  return;
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

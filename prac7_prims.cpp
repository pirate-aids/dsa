#include<iostream>
using namespace std;

class tree
{
    int a[20][20],l,u,w,i,j,v,e,visited[20];
public:
    void input();
    void display();
    void minimum();
};
void tree::input()
{
   cout<<"Enter the number of branches:";
   cin>>v;
   for(i=0;i<v;i++)
   {
  	visited[i]=0;
  	for(j=0;j<v;j++)
  	{
    	a[i][j]=999;
  	}
   }
   cout<<"Enter number of connection:";
   cin>>e;
 	for(i=0;i<e;i++)
   {
	cout<<"Enter end connection of branches"<<endl;
	cin>>l>>u;
	cout<<"Enter the phone company charges for this connection"<<endl;
	cin>>w;
	a[l-1][u-1]=a[u-1][l-1]=w;
   }
}   
void tree::display()
{
  cout<<"\n Adjancency matrix:";
  for(i=0;i<v;i++)
  {
   	cout<<endl;
   	for(j=0;j<v;j++)
   	{
    	if(a[i][j]==999)
    	{
     	cout<<"0"<<"  ";
    	}
    	else
      	cout<<a[i][j]<<"  ";
   	}
    	cout<<endl;
	}
 }
 void tree::minimum()
 {
	int p=0,q=0,total=0,min;
	visited[0]=1;
	for(int count=0;count<(v-1);count++)
	{
      	min=999;
      	for(i=0;i<v;i++)
      	{
        	if(visited[i]==1)
        	{
          	for(j=0;j<v;j++)
          	{
              	if(visited[j]!=1)
              	{
                	if(min>a[i][j])
                	{
                	min=a[i][j];
                	p=i;
                	q=j;
                	}
             	}
          	}
       	}
     	}
     	visited[p]=1;
     	visited[q]=1;
     	total=total+min;
     	cout<<"Minimum cost connection is"<<(p+1)<<" ->"<<(q+1)<<" With charge: "<<min<<endl;
     	}
     	cout<<"The minimum total cost of connection of all branches is:"<<total<<endl;
  	 
 }        	 
                       	 
int main()
{
  int ch;
  tree t;
  do
  {
	cout<<"--------------Prim's algorithm-------------------------"<<endl;
	cout<<"1.Input"<<endl;
	cout<<"2.Display"<<endl;
	cout<<"3.Minimum"<<endl;
	cout<<"4.EXIT"<<endl;
	cout<<"enter your choice=";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"Input your value"<<endl;
        	t.input();
        	break;
	case 2:cout<<"Display The content"<<endl;   
       	t.display();
       	break;
	case 3:cout<<"minimum value"<<endl;
       	t.minimum();
       	break;
   }
  }while(ch!=4);
	return 0;   
}              	

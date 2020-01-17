#include<iostream>
#include<algorithm>
using namespace std;
int binary(int b,int e,int arr[],int x)
{
	int m=(b+e)/2;
	while(b<e)
	{
		if(arr[m]==x)
		{
			cout<<"the position of the element is : "<<m+1;
			break;
		}
		else if(arr[m]<x)
			b=m+1;
		else if(arr[m]>x)
			e=m-1;		
		
		m=(b+e)/2;
	}
	return 0;
}
 
int binaryrecur(int x,int b,int e,int m,int arr[])
{
	m=(b+e)/2;
	if(arr[m]==x)
	    return m+1;
	else if(arr[m]<x)
        return binaryrecur(x,m+1,e,m,arr);
	else if(arr[m]>x)
     	return binaryrecur(x,b,m-1,m,arr);
	else	 
		return 0;       
	
}

int main()
{
	int menu,s,b,e,m,x,arr[20];
	cout<<"enter the size of the array : ";
	cin>>s;
	cout<<"enter the elements of the array : \n";
	for(int i=0;i<s;i++)
		cin>>arr[i];
	sort(arr,arr+s);																				//sorting the elemnts of the array. 
	
	b=0,e=s-1,m=(b+e)/2;
	cout<<"enter the elemnt you want to find : ";
	cin>>x;
	cout<<"1. Binary search by itration. \n";
	cout<<"2. Binary search by recurssion. \n";
	cout<<"enter your choice : ";
	cin>>menu;
	switch(menu)
	{
		case 1:
				binary(b,e,arr,x);
				break;
		case 2:
				cout<<"the position of the element is : "<<binaryrecur(x,b,e,m,arr);
				break;
		default:
				cout<<"invalid choice";		
		
	}
	return 0;
}


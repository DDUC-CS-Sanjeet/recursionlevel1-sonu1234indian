#include<iostream>
using namespace std;

int gcdi(int a,int b)
{
	int temp;
	while(b!=0)
		{
			temp=a;
			a=b;
			b=temp%b;
		}
	cout<<"the gcd is : "<<a;	
}

int gcdirecur(int a,int b)
{
	if(b!=0)
	{	
		int temp;
		temp=a;
		a=b;
		b=temp%b;
		return gcdirecur(a,b);
	}
	else																//when b==0
		return a;	
}

int fibonacci(int n,int no1,int no2,int f,int i,int temp)
{
	no1=0,no2=1;
	if(n<=2)
	{
		cout<<"not possible";
		return 0;
	}
	else
	{
		if(temp==0)
		{
			cout<<"0, 1, ";
			temp++;
 		}
		for(i=2;i<n;i++)
			{
				f=no1+no2;
				cout<<f<<", ";
				no1=no2;
				no2=f;
			}
	}
}

int fibonaccirecur(int n,int no1,int no2,int f,int i,int temp)
{
	if(n<=2)
		return -1;
	else if(i==n)
		return 0;
	else
	{
		if(temp==0)
		{
			cout<<"0, 1, ";
			temp++;
		}		
		f=no1+no2;
		cout<<f<<", ";
		no1=no2;
		no2=f,i=i+1;
		return fibonaccirecur(n,no1,no2,f,i,temp);
	}
}

int pow(int m,int n)
{
	int ans=1;
	for(int i=0;i<n;i++)
		ans=ans*m;
	cout<<"the answer is : "<<ans;
}

int powrecur(int m,int n,int ans)
{
	if(n==1)
		return ans*m;
	else
	{
		ans=ans*m;
		n--;
		return powrecur(m,n,ans); 	
	}
}

int factorial(int n)
{
	int fact=1;
	for(int i=n;i>0;i--)
		fact=fact*i;
	cout<<"the factorial is : "<<fact;
}

int factorialrecur(int n)
{
	int fact;
	if(n<=1)
	{
		if(n==0)
		{
			cout<<"1";
			return 0;
		} 
		else if(n==1)
			return 1;
		else
			cout<<"not possible";	
	}
	else
	{
		return n*factorialrecur(n-1);
	}
}   




int main()
{
	int n,no1,no2,f,i,temp=0,m,ans;
	int menu,ir;
	char ch='y';
	cout<<"1. Find the GCD of the two no.s \n";
	cout<<"2. Print the fibonacci series upto n terms \n";
	cout<<"3. Find the power of a no. \n";
	cout<<"4. Find the factorial of a no. \n";
	while(ch=='y')
	{
		cout<<"Enter your choice : ";
		cin>>menu;	
    	cout<<"how you want to do the program (for itrative '1' and for recursive '2') : ";
		cin>>ir;
		switch(menu)
			{
				case 1:
						cout<<"enter no.1 : ";
						cin>>no1;
						cout<<"enter no.2 : ";
						cin>>no2;
						switch(ir)
							{
								case 1: gcdi(no1,no2);
										break;
								case 2: cout<<"GCD of the two no.'s is : '"<<gcdirecur(no1,no2);
										break;
							}
						break;
				case 2:
						cout<<"enter upto which u want to print the series : ";
						cin>>n;
						no1=0,no2=1,i=2,f=0,temp=0;
						switch(ir)
							{
								case 1: fibonacci(n,no1,no2,f,i,temp);
										break;
								case 2: fibonaccirecur(n,no1,no2,f,i,temp);
										break;
							}
						break;
				case 3:
						cout<<"enter the no. : ";
						cin>>m;
						cout<<"enter the power : ";
						cin>>n;
						ans=1;
						switch(ir)
							{
								case 1: pow(m,n);
										break;
								case 2: cout<<"the answer is : "<<powrecur(m,n,ans);
										break;
							}
						break;
				case 4:
						cout<<"enter the no. : ";
						cin>>n;
						switch(ir)
							{
								case 1: factorial(n);
										break;
								case 2: cout<<factorialrecur(n);
										break;
										
							}
						break;
				default:
						cout<<"invalid choice";
			}
		cout<<"\n do you want to continue(y/n) : ";
		cin>>ch;
	}
	
	return 0;	
}

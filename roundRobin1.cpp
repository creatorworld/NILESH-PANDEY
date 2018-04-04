#include<iostream>
using namespace std;
int main()
{
	int i,j,ts,a[10],arrival[10],burst[10],n,temp,temp1,temp2,turn[10],waiting[10];
	cout<<"Enter the number of process(MAX 10)--->";
	cin>>n;
	cout<<"Enter which process you want to put in list--->";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the details--->\n";
	for(i=0;i<n;i++)
	{
		cout<<"for P["<<a[i]<<"]";
		cout<<"\nArrival time--->";
		cin>>arrival[i];
		cout<<"CPU Burst Time--->";
		cin>>burst[i];
		waiting[i]=0;
		turn[i]=0;
	}
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(arrival[j]>arrival[j+1])
			{
				temp=arrival[j];
				arrival[j]=arrival[j+1];
				arrival[j+1]=temp;
				temp1=burst[j];
				burst[j]=burst[j+1];
				burst[j+1]=temp1;
				temp2=a[j];
				a[j]=a[j+1];
				a[j+1]=temp2;
			}
		}
	}
	cout<<"Enter the quantum(Time Slice)--->";
	cin>>ts;
	cout<<"PROCESS\t\tARRIVAL TIME\t\tCPU BURST TIME\t\tTURN AROUND TIME\t\tWAITING TIME \n";
	for(i=0;i<n;i++)
	{
		cout<<"P["<<a[i]<<"]\t\t\t"<<arrival[i]<<"\t\t\t"<<burst[i]<<"\t\t\t"<<turn[i]<<"\t\t\t     "<<waiting[i]<<"\n";
	}
	cout<<"\nTime Slice--->"<<ts;
}

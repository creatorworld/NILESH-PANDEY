#include<iostream>
#include<conio.h>
using namespace std;
int i,j,arrival[50], burst[50], completiont[50]={0},n,qt,a[50],rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, turnt, waitingt;
float averageturnt, averagewaitingt;
class roundR
{
	public:
		void Search1(int pnt,int tm)
		{
			for(int i=pnt+1;i<n;i++)
			{
				if(arrival[i]<=tm)
				{
					rqi[noe]=i+1;
					noe++;
				}
			}
		}
		void Search2(int pnt, int tm)
		{
			for(int i=pnt+1;i<n;i++)
			{
				//---CheckQue
				int fl=0;
				for(j=0;j<noe;j++)
				{
					if(rqi[j]==i+1)
					{
						fl++;
					}
				}
				if(arrival[i]<=tm && fl==0 && btm[i]!=0)
				{
					rqi[noe]=i+1;
					noe++;
				}
			}
		}
		void AddQue(int pnt)
		{
			rqi[noe]=pnt+1;
			noe++;
		}//void
}rr;
int main()
{
	cout<<"Enter the number of process(MAX 10)--->";
	cin>>n;
	cout<<"Enter the details--->\n";
	for(i=0;i<n;i++)
	{
		cout<<"for P["<<i+1<<"]";
		cout<<"\nArrival time--->";
		cin>>arrival[i];
		cout<<"CPU Burst Time--->";
		cin>>burst[i];
		btm[i]=burst[i];
	}
	system("CLS");
	qt=6;
	do
	{
		if(flg==0)
		{
			st=arrival[0];
			//---ReduceBT
			if(btm[0]<=qt)
			{
				tm=st+btm[0];
				btm[0]=0;
				rr.Search1(pnt,tm);
			}
			else
			{
				btm[0]=btm[0]-qt;
				tm=st+qt;
				rr.Search1(pnt,tm);
				rr.AddQue(pnt);
			}
		}//if
		else
		{
			pnt=rqi[0]-1;
			st=tm;
			//---DeleteQue
			for(i=0;i<noe && noe!=1;i++)
			{
				rqi[i]=rqi[i+1];
			}
			noe--;
			//---ReduceBT
			if(btm[pnt]<=qt)
			{
				tm=st+btm[pnt];
				btm[pnt]=0;
				rr.Search2(pnt, tm);
			}
			else
			{
				btm[pnt]=btm[pnt]-qt;
				tm=st+qt;
				rr.Search2(pnt, tm);
				rr.AddQue(pnt);
			}
		}//else
		//AssignCTvalue
		if(btm[pnt]==0)
		{
			completiont[pnt]=tm;
		}//if
		flg++;
		cout<<"]-P"<<pnt+1<<"-["<<tm;
	}while(noe!=0);
	cout<<"\n\nPROCESS\t Arrival Time\t CPU Burst Time \t Completion Time\t Turn Around Time\t Waiting Time\n";
	for(i=0;i<n;i++)
	{
		turnt=completiont[i]-arrival[i];
		waitingt=turnt-burst[i];
		cout<<"P"<<i+1<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<completiont[i]<<"\t\t"<<turnt<<"\t\t"<<waitingt<<"\n";
		averagewaitingt=averagewaitingt+waitingt;
		averageturnt=averageturnt+turnt;
	}
	cout<<"\nAVERAGE Turn Around Time--->"<<averageturnt/5<<"\nAVERAGE Waiting Time---> "<<averagewaitingt/5;
}

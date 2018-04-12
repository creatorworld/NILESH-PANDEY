// class for round robin
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

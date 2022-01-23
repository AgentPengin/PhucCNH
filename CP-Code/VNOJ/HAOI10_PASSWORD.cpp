#include <iostream>
#include <string>
using namespace std;

struct dat
{
	int hv_1;
	int hv_A;
	int hv_a;
} typedef dat;

dat pass[1000006];

int check_safe (int begin, int end)
{
	int num_1=pass[end].hv_1-pass[begin-1].hv_1;
	int num_a=pass[end].hv_a-pass[begin-1].hv_a;
	int num_A=pass[end].hv_A-pass[begin-1].hv_A;
	if (num_1>0 && num_a>0 && num_A>0 && end-begin+1>=6) return 1;
	else return 0;
}

int BSearch (int begin, int front, int back)
{
	int vt=-1;
	while (front<=back && back-begin+1>=6)
	{
		int mid = (front+back)/2;
		if (check_safe (begin, mid)==1)
		{
			vt=mid;
			back=mid-1;
		}
		else front=mid+1;
	}
	return vt;
}

int main ()
{
	string xau;
	cin>>xau;
	pass[0].hv_1=0;
	pass[0].hv_a=0;
	pass[0].hv_A=0;
	int n=xau.length();
	for (int i=1; i<=n; i++)
	{
		if (xau[i-1]>='0' && xau[i-1]<='9')
		{
			pass[i] = pass[i-1];
			pass[i].hv_1++;
		}
		else if (xau[i-1]>='a' && xau[i-1]<='z')
		{
			pass[i] = pass[i-1];
			pass[i].hv_a++;
		}
		else if (xau[i-1]>='A' && xau[i-1]<='Z')
		{
			pass[i] = pass[i-1];
			pass[i].hv_A++;
		}
	}
	long long count=0;
	for (int i=1; i<=xau.length()-6+1; i++)
	{
		int VT = BSearch (i, i, n);
		if (VT!=-1)
		{
			count+=n-VT+1;
		} else break;
	}
	cout<<count;
	return 0;
}

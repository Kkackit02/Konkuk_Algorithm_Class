#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class TRI
{
public:
	int a, b, w; // a쪽에서 넣은것
};

class PQ
{
public:
	int n;
	TRI Arr[1000];
	PQ();
	TRI Delete();
	void Insert(TRI x);
	int isEmpty();
};

PQ::PQ()
{
	n = 0;
}

int PQ::isEmpty()
{
	return n == 0;
}

void PQ::Insert(TRI x)
{
	int i;
	Arr[n + 1] = x; // 0은 안씀
	i = n + 1;
	n = n + 1;

	while (i > 1 && Arr[i].w < Arr[i / 2].w)
	{
		swap(Arr[i], Arr[i / 2]);
		i = i / 2;
	}
}

TRI PQ::Delete()
{
	TRI ret = Arr[1];
	int i , j;

	if (n == 1) // special case
	{
		n = 0;
		return ret;
	}

	Arr[1] = Arr[n];
	i = 1;
	n = n - 1;

	while (1)
	{
		if (i * 2 > n)
		{
			break;
		}
		else if (i * 2 + 1 > n) // left Child Only Exists
		{
			if (Arr[i * 2].w < Arr[i].w)
			{
				swap(Arr[i * 2], Arr[i]);
				i = i * 2;
			}
			else
			{
				break;
			}
		}
		else // Left and Right Child exists
		{
			if(Arr[i].w > Arr[i*2].w && Arr[i].w > Arr[i*2+1].w)
			{
				if(Arr[i*2].w < Arr[i*2+1].w)
				{
					j =i*2;
				}
				else
				{
					j = i*2+1;
				}

				swap(Arr[i], Arr[j]);
				i = j;

			}
			else if(Arr[i].w > Arr[i*2].w && Arr[i].w <= Arr[i*2+1].w)
			{
				j = i * 2;
				swap(Arr[i] , Arr[j]);
				i = j;
			}
			else if(Arr[i].w <= Arr[i*2].w && Arr[i].w > Arr[i*2+1].w)
			{
				j = i * 2 + 1;
				swap(Arr[i] , Arr[j]);
				i = j;
			}
			else
			{
				break;
			}

		}
	}
	return ret;
}


PQ Q;
int main()
{
	
	TRI s[100] = {
		{1,2,3},
		{4,5,6},
		{2,2,4},
		{4,2,1},
		{4,2,2},
		{4,6,8}
	};

	TRI t;
	Q.Insert(s[0]);
	Q.Insert(s[1]);
	Q.Insert(s[2]);
	Q.Insert(s[3]);
	Q.Insert(s[4]);
	Q.Insert(s[5]);
	t=Q.Delete();
	printf("Delete (%d %d %d)\n" , t.a, t.b, t.w);
	return 0;
}

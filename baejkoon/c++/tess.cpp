#include <iostream>
using namespace std;
int main()
{
	int n,i,j,l;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		int m,a,c;
		int ans = 0;
		int ka[200] = { 0, };
		int si[200] = { 0, };
		cin >> m;
		for (j = 0; j < m; j++)
		{
			cin >> a >> c;
			if (si[a] == 0)
			{
				int ss = 2;
				while (c > ss)
				{
					ss *= 2;
				}
				ka[a] = c;
				si[a] = ss;
			}
			else
			{
				if (si[a] >= ka[a] + c)
				{
					ka[a] = ka[a] + c;
				}
				else
				{
					int ss = si[a];
					while (ss < ka[a] + c)
					{
						ss *= 2;
					}
					ans += ka[a];
					ka[a] = ka[a] + c;
					si[a] = ss;
				}
			}
		}
		cout << ans << "\n";
	}
}
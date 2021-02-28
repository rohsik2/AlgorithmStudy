#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;


int main() {
	int x1, x2, y1, y2, T, cx, cy,r,n;
	cin >> T;
	int whilet = 0;//케이스의 실행된 개수
	while (whilet < T) 
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		int numeatprince = 0;
		int numeatrose = 0;
		int numeatboth = 0;
		int planetnum = 0;
		
		
		while (planetnum < n) 
		{
		
			cin >> cx >> cy >> r;
			
			if (((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) < r * r && ((x2 - cx) * (x2 - cx) + (y2 - cy) *(y2 - cy)) < r * r)
				numeatboth = numeatboth+1;
			
			if (((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) < r * r)
				numeatprince = numeatprince+1;
			
			if (((x2 - cx) * (x2 - cx) + (y2 - cy) *(y2 - cy)) < r * r)
				numeatrose = numeatrose+1;
			
			planetnum++;
			
		}
		whilet++;
		cout << numeatprince + numeatrose -( 2 * (numeatboth))<<endl;
	}
	return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int x, y, x1, y1, x2, y2, a=0;

	cin >> x >> y;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	if((x1 + x2) <= x)
	{
		if(y1<=y && y2<=y)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}			
		}
	}

	if((y1 + y2) <= y)
	{
		if(x1<=x && x2<=x)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((y1 + y2) <= x)
	{
		if(x1<=y && x2<=y)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((x1 + x2) <= y)
	{
		if(y1<=x && y2<=x)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((x1 + y2) <= y)
	{
		if(y1<=x && x2<=x)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((x1 + y2) <= x)
	{
		if(y1<=y && x2<=y)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((x2 + y1) <= x)
	{
		if(x1<=y && y2<=y)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if((x2 + y1) <= y)
	{
		if(x1<=x && y2<=x)
		{
			if(!a)
			{
				cout << "S" << endl;
				a=1;
			}	
		}
	}

	if(!a)
	{
		cout << "N" << endl;
		a=1;
	}
	return 0;
}

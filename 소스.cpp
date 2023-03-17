#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 }{}
	Circle(int x,int y, int r) : x{x}, y{y}, radius{r} {}
	int get_radius() { return radius; }
	void draw(void)
	{
		int r = radius / 2;
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - r, y - r, x + r, y + r);
	}

};


void print(vector<Circle> &objj)
{
	int n = objj.size();

	for (int i = 0; i < n; i++)
	{
		cout << objj[i].x << " " << objj[i].y << " "  << objj[i].radius << endl;
	}
}


bool compare1(Circle& a, Circle& b)     // 오름차순
{
	return a.get_radius() < b.get_radius();
		 
}

bool compare2(Circle& a, Circle& b)     // 내림차순
{
	return a.get_radius() > b.get_radius();
}

int main(void)
{
	vector<Circle> objArray;
    vector<Circle> objArray2;

	while (true)
	{

		char ch = _getch();

		if (ch == 'c')
		{
			Circle obj{ rand() % 400, rand() % 400, rand() % 100 };
			objArray.push_back(obj);
			objArray2.push_back(obj);
			obj.draw();
		}
		else if (ch == 'q')
			break;
	}

	 print(objArray);

	 sort(objArray.begin(), objArray.end(), compare1);  //오름차순대로 정리하기

	 cout << endl;
	 cout << "------오름차순대로 정렬-------" << endl;
	 print(objArray);

	 cout << "-------제거한 결과---------" << endl;
	 objArray.erase(objArray.begin());
	 objArray.erase(objArray.begin()+objArray.size()-1);

	 print(objArray);

	 

	 sort(objArray2.begin(), objArray2.end(), compare2);  //내림차순대로 정리하기

	 cout << endl;
	 cout << "------내림차순대로 정렬-------" << endl;
	 print(objArray2);

	 cout << "-------제거한 결과---------" << endl;
	 objArray2.erase(objArray2.begin());
	 objArray2.erase(objArray2.begin() + objArray2.size() - 1);

	 print(objArray2);

}
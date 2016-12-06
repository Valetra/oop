#include <iostream>
#include "Sphere.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"

using namespace std;

int main()
{
	
	CCone cone = CCone(10, 2, 5, 5);

	cout << cone.ToString();

	return 0;
}
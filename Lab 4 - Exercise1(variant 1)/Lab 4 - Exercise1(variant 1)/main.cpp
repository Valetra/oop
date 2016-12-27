#include "stdafx.h"
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<CBody*> vector;
	std::string shapeName;
	double density;

	while (shapeName != "exit")
	{
		std::cout << "For exit enter \"exit\" \n";
		std::cout << "Shape names: \n  parallelepiped\n  sphere\n  cylinder\n  cone\n";
		std::cout << "Enter shape name or request \"max\": \n";
		std::cin >> shapeName;

		if (shapeName == "parallelepiped")
		{
			double width;
			double height;
			double depth;

			std::cout << "density: ";
			std::cin >> density;
			std::cout << "\n";

			std::cout << "width: ";
			std::cin >> width;
			std::cout << "\n";

			std::cout << "height: ";
			std::cin >> height;
			std::cout << "\n";

			std::cout << "depth: ";
			std::cin >> depth;
			std::cout << "\n";

			CParallelepiped *parallelepiped = new CParallelepiped(density, width, height, depth);
			vector.push_back(parallelepiped);
			std::cout << parallelepiped->ToString();
		}
		else if (shapeName == "sphere")
		{
			double radius;

			std::cout << "density: ";
			std::cin >> density;
			std::cout << "\n";

			std::cout << "radius: ";
			std::cin >> radius;
			std::cout << "\n";

			CSphere *sphere = new CSphere(density, radius);
			vector.push_back(sphere);
			std::cout << sphere->ToString();
		}
		else if (shapeName == "cylinder")
		{
			double radius;
			double height;

			std::cout << "density: ";
			std::cin >> density;
			std::cout << "\n";

			std::cout << "radius: ";
			std::cin >> radius;
			std::cout << "\n";

			std::cout << "height: ";
			std::cin >> height;
			std::cout << "\n";

			CCylinder *cylinder = new CCylinder(density, height, radius);
			vector.push_back(cylinder);
			std::cout << cylinder->ToString();

		}
		else if (shapeName == "cone")
		{
			double radius;
			double height;

			std::cout << "density: ";
			std::cin >> density;
			std::cout << "\n";

			std::cout << "radius: ";
			std::cin >> radius;
			std::cout << "\n";

			std::cout << "height: ";
			std::cin >> height;
			std::cout << "\n";

			CCone *cone = new CCone(density, height, radius);
			vector.push_back(cone);
			std::cout << cone->ToString();

		}
		else if (shapeName == "max")
		{
			double maxMass = 0;

			for (size_t i = 0; i < vector.size(); ++i)
			{
				if (vector.at(i)->GetMass() > maxMass)
				{
					maxMass = vector.at(i)->GetMass();
				}
			}
			std::cout << "Max mass of shapes: " << maxMass << "\n\n";
		}
	}
	return EXIT_SUCCESS;
}
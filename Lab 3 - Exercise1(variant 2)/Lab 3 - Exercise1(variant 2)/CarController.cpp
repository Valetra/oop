#include "Car.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <boost\algorithm\string.hpp>

using namespace std;

//TODO: Сделать как в git`e
//	1)сделать так, чтобы программа работала с отрицательным вводом!
void PrintInfo(const CCar &car)
{
	string engineState;
	engineState = (car.GetStateOfEngine() ? "включён" : "выключен");

	string drivingDirection;

	switch (car.GetDirection())
	{
		case Direction::BACKWARD:
		{
			drivingDirection = "назад";
			break;
		}
		case Direction::FORWARD:
		{
			drivingDirection = "вперёд";
			break;
		}
		case Direction::NO_DIRECTION:
		{
			drivingDirection = "нет";
			break;
		}
		default:
		break;
	}

	string gear;
	switch (car.GetGear())
	{
		case Gear::REVERSE:
		{
			gear = "задняя";
			break;
		}
		case Gear::NEUTRAL:
		{
			gear = "нейтральная";
			break;
		}
		case Gear::FIRST:
		{
			gear = "первая";
			break;
		}
		case Gear::SECOND:
		{
			gear = "вторая";
			break;
		}
		case Gear::THIRD:
		{
			gear = "третья";
			break;
		}
		case Gear::FOURTH:
		{
			gear = "четвёртая";
			break;
		}
		case Gear::FIFTH:
		{
			gear = "пятая";
			break;
		}
		default:
			break;
	}


	cout << "Двигатель автомобиля: " << engineState
		<< "\nНаправление дижения: " << drivingDirection
		<< "\nСкорость автомобиля равна: " << car.GetSpeed()
		<< "\nВыставлена " << gear << " передача.\n";
}

bool EngineOn(CCar &car)
{
	return car.TurnOnEngine();
}

bool EngineOff(CCar &car)
{
	return car.TurnOffEngine();
}

bool SetGear(CCar &car, int gear)
{
	if (car.SetGear(gear))
	{
		return true;
	}
	else
	{
		cout << "Не удалось переключить передачу, так как\n";
		if (!car.GetStateOfEngine())
		{
			cout << "- двигатель выключен\n";
		}

		else if (car.IsSpeedInGearRange(car.GetSpeed(), static_cast<Gear>(gear)))
		{
			cout << "- скорость автомобиля не входит в диапозон передачи\n";
		}
		
		else
		{
			cout << "условие перехода на передачу не соответствует возможностям автомобиля\n";
		}
		return false;
	}
}

bool SetSpeed(CCar &car, size_t speed)
{
	if (speed >= 0 && speed <= 150)
	{
		return(car.SetSpeed(speed));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	CCar car;

	string userRequest;
	while (userRequest != "exit")
	{
		getline(cin, userRequest);
		std::transform(userRequest.begin(), userRequest.end(), userRequest.begin(), ::tolower);

		vector<string> requestDiv;
		boost::split(requestDiv, userRequest, boost::is_any_of(" "));

		if (userRequest == "info")
		{
			PrintInfo(car);
		}

		else if (userRequest == "engineon")
		{
			if (EngineOn(car))
			{
				cout << "Двигатель включён\n";
			}
			else
			{
				cout << "Двигатель был запущен ранее\n";
			}
		}

		else if (userRequest == "engineoff")
		{
			if (EngineOff(car))
			{
				cout << "Двигатель выключён\n";
			}
			else
			{
				cout << "Двигатель не может быть выключен, причиной этого могут быть:\n" 
					<< "1) Выключенный двигатель\n"
					<< "2) Не находящаяся на нейтрали передача\n"
					<< "3) Движение автомобиля\n";
			}
		}

		
		if (requestDiv.size() == 2 && requestDiv.at(0) == "setgear" 
			&& requestDiv.at(1) != "" 
			&& isdigit(requestDiv.at(1).at(0)) &&
			stoi(requestDiv.at(1)) >= -1 && stoi(requestDiv.at(1)) <= 5)
		{
			if (SetGear(car, stoi(requestDiv.at(1))))
			{
				cout << "Передача установлена\n";
			}
		}
		
		if (requestDiv.size() == 2 && requestDiv.at(0) == "setspeed"
			&& requestDiv.at(1) != ""
			&& isdigit(requestDiv.at(1).at(0)) &&
			stoi(requestDiv.at(1)) >= 0 && stoi(requestDiv.at(1)) <= 150)
		{
			if (SetSpeed(car, stoi(requestDiv.at(1))))
			{
				cout << "Скорость установлена\n";
			}
			else
			{
				cout << "Невозможно установить скорость при данных условиях\n";
			}
		}
		

	}
	return EXIT_SUCCESS;
}
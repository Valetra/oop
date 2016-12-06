#pragma once
#include <map>

enum class Direction
{
	BACKWARD = -1,
	NO_DIRECTION = 0,
	FORWARD = 1
};

enum class Gear
{
	REVERSE = -1,
	NEUTRAL = 0,
	FIRST = 1,
	SECOND = 2,
	THIRD = 3,
	FOURTH = 4,
	FIFTH = 5
};

class CCar
{
public:
	CCar();
	~CCar();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool TurnOnEngine();
	bool SetSpeed(int speed);
	Direction GetDirection() const;
	size_t GetSpeed() const;
	Gear GetGear() const;
	bool GetStateOfEngine() const;
	bool IsSpeedInGearRange(int speed, Gear gear) const;

private:
	bool m_isEngineTurnOn = false;
	Gear m_gear = Gear::NEUTRAL;
	size_t m_speed = 0;
	Direction m_direction = Direction::NO_DIRECTION;
	void UpdateDirection();
};


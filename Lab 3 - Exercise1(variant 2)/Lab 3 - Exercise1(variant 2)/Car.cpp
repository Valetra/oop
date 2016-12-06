#include "Car.h"

const std::map<Gear, std::pair<Direction, std::pair<int, int>>> GEARS =
{
	{ Gear::REVERSE,{ Direction::BACKWARD,{ 0, 20 } } },
	{ Gear::NEUTRAL,{ Direction::NO_DIRECTION,{ 0, 150 } } },
	{ Gear::FIRST,{ Direction::FORWARD,{ 0, 30 } } },
	{ Gear::SECOND,{ Direction::FORWARD,{ 20, 50 } } },
	{ Gear::THIRD,{ Direction::FORWARD,{ 30, 60 } } },
	{ Gear::FOURTH,{ Direction::FORWARD,{ 40, 90 } } },
	{ Gear::FIFTH,{ Direction::FORWARD,{ 50, 150 } } }
};

CCar::CCar()
	: m_isEngineTurnOn(false)
	, m_speed(0)
{
}

CCar::~CCar()
{
}

bool CCar::TurnOnEngine()
{
	if (m_isEngineTurnOn)
	{
		return false;
	}
	else
	{
		m_isEngineTurnOn = true;

		return m_isEngineTurnOn;
	}
}

bool CCar::TurnOffEngine()
{
	if (m_isEngineTurnOn && m_gear == Gear::NEUTRAL && m_speed == 0)
	{
		m_isEngineTurnOn = false;

		return true;
	}
	return false;
}

bool CCar::IsSpeedInGearRange(int speed, Gear gear) const
{
	return (speed >= GEARS.at(gear).second.first && speed <= GEARS.at(gear).second.second);
}

bool CCar::SetGear(int gear)
{
	if (gear >= -1 && gear <= 5)
	{
		auto newGear = static_cast<Gear>(gear);
		if (m_isEngineTurnOn && IsSpeedInGearRange(m_speed, newGear) || (!m_isEngineTurnOn && newGear == Gear::NEUTRAL))
		{
			if (newGear == Gear::REVERSE && m_speed != 0  && m_gear != Gear::NEUTRAL)
			{
				return false;
			}
			if (newGear == Gear::FIRST && m_gear == Gear::REVERSE && m_speed != 0)
			{
				return false;
			}
			m_gear = newGear;
			return true;
		}
	}
	return false;
}

void CCar::UpdateDirection()
{
	if (m_speed > 0 && m_gear >= Gear::FIRST)
	{
		m_direction = Direction::FORWARD;
	}
	else if (m_speed > 0 && m_gear == Gear::REVERSE && m_direction != Direction::FORWARD)
	{
		m_direction = Direction::BACKWARD;
	}
	else if (m_speed == 0)
	{
		m_direction = Direction::NO_DIRECTION;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (m_isEngineTurnOn && IsSpeedInGearRange(speed, m_gear) && m_gear != Gear::NEUTRAL && speed >= 0)
	{
		m_speed = speed;
		UpdateDirection();
		return true;
	}
	else if (m_isEngineTurnOn && m_gear == Gear::NEUTRAL && speed >= 0 && speed < m_speed)
	{
		m_speed = speed;
		UpdateDirection();
		return true;
	}
	return false;
}


Direction CCar::GetDirection() const
{
	return m_direction;
}


size_t CCar::GetSpeed() const
{
	return m_speed;
}

Gear CCar::GetGear() const
{
	return m_gear;
}


bool CCar::GetStateOfEngine() const
{
	return m_isEngineTurnOn;
}

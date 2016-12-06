#include "stdafx.h"
#include"../Lab 3 - Exercise1(variant 2)/Car.h"

BOOST_AUTO_TEST_SUITE(Test_the_correct_operation_of_the_machine)

	//Проверка метода TurnOnEngine, при выключеном двигателе
	BOOST_AUTO_TEST_CASE(Check_method_TurnOnEngine_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
	}

	//Проверка метода TurnOnEngine, при включеном двигателе
	BOOST_AUTO_TEST_CASE(Check_method_TurnOnEngine_for_turn_on_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.TurnOnEngine() == false);
	}
	
	//Проверка метода TurnOffEngine, при включеном двигателе
	BOOST_AUTO_TEST_CASE(Check_method_TurnOffEngine_for_turn_on_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.TurnOffEngine() == true);
	}

	//Проверка метода TurnOffEngine, при выключеном двигателе
	BOOST_AUTO_TEST_CASE(Check_method_TurnOffEngine_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOffEngine() == false);
	}

	//Проверка метода SetGear для выключеного двигателя
	BOOST_AUTO_TEST_CASE(Check_method_SetGear_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(-1) == false);
		BOOST_CHECK(car.SetGear(1) == false);
		BOOST_CHECK(car.SetGear(3) == false);
		BOOST_CHECK(car.SetGear(5) == false);
	}

	//Проверка метода SetGear для включеного двигателя со скоростью нуль
	BOOST_AUTO_TEST_CASE(Check_method_SetGear_for_turn_on_engine_with_zero_speed)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(-2) == false);
		BOOST_CHECK(car.SetGear(2) == false);
	}

	//Проверка метода SetSpeed для выключеного двигателя
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_for_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.SetSpeed(5) == false);
		BOOST_CHECK(car.SetSpeed(20000) == false);
		BOOST_CHECK(car.SetSpeed(-5) == false);
		BOOST_CHECK(car.SetSpeed(-5000) == false);
	}

	//Проверка метода SetSpeed для включеного двигателя на нейтральной передаче
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_for_on_engine_and_on_neutral_gear)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetSpeed(5) == false);
		BOOST_CHECK(car.SetSpeed(100) == false);
	}

	//Проверка метода SetSpeed и SetGear для включеного двигателя на различных передачах
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_and_SetGear_for_on_engine_and_on_variable_gears)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(-1));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(21) == false);


		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(1));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(30) == true);
		BOOST_CHECK(car.SetSpeed(31) == false);
		
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(2));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(19) == false);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(51) == false);

		BOOST_CHECK(car.SetGear(3) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(3));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(29) == false);
		BOOST_CHECK(car.SetSpeed(30) == true);
		BOOST_CHECK(car.SetSpeed(60) == true);
		BOOST_CHECK(car.SetSpeed(61) == false);

		BOOST_CHECK(car.SetGear(4) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(4));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(39) == false);
		BOOST_CHECK(car.SetSpeed(40) == true);
		BOOST_CHECK(car.SetSpeed(90) == true);
		BOOST_CHECK(car.SetSpeed(91) == false);

		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(5));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(49) == false);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(150) == true);
		BOOST_CHECK(car.SetSpeed(151) == false);

		//попытка установить скорость на нейтрайльной передаче
		BOOST_CHECK(car.SetGear(0) == true);

		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(150) == false);
		BOOST_CHECK(car.SetSpeed(100) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(10) == false);
		
		
		
		
	}

	//Проверка метода SetDirection и большую часть фукционала машины
	BOOST_AUTO_TEST_CASE(Check_methods_SetDirection_and_main_fuctions_of_car)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetSpeed(10) == true);
		BOOST_CHECK(car.GetDirection() == Direction::BACKWARD);
		BOOST_CHECK(car.GetSpeed() == 10);

		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetSpeed() == 0);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(2) == false);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(31) == false);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(2));

		BOOST_CHECK(car.SetSpeed(45) == true);
		BOOST_CHECK(car.GetSpeed() == 45);
		BOOST_CHECK(car.SetSpeed(55) == false);
		BOOST_CHECK(car.SetGear(3) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(3));

		BOOST_CHECK(car.SetGear(1) == false);
		BOOST_CHECK(car.SetGear(5) == false);
		BOOST_CHECK(car.SetGear(6) == false);
		BOOST_CHECK(car.SetGear(4) == true);

		BOOST_CHECK(car.SetSpeed(85) == true);
		BOOST_CHECK(car.SetGear(0) == true);

		BOOST_CHECK(car.SetSpeed(90) == false);
		BOOST_CHECK(car.SetSpeed(80) == true);
		BOOST_CHECK(car.GetSpeed() == 80);

		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.GetSpeed() == 50);
		BOOST_CHECK(car.SetSpeed(49) == false);
		BOOST_CHECK(car.SetSpeed(150) == true);
		BOOST_CHECK(car.GetSpeed() == 150);
		BOOST_CHECK(car.SetSpeed(151) == false);
		BOOST_CHECK(car.GetSpeed() == 150);
		BOOST_CHECK(car.SetSpeed(-50) == false);
		BOOST_CHECK(car.SetSpeed(0) == false);

		BOOST_CHECK(car.TurnOffEngine() == false);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.GetDirection() == Direction::FORWARD);
		BOOST_CHECK(car.TurnOffEngine() == false);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.TurnOffEngine() == true);

	}

	//Проверка возможности снижения скорости на нейтральной передаче
	BOOST_AUTO_TEST_CASE(Check_possibility_of_reducing_speed_at_neutral_gear)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);

		BOOST_CHECK(car.GetGear() == static_cast<Gear>(0));
		BOOST_CHECK(car.GetSpeed() == 0);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.GetDirection() == Direction::BACKWARD);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetGear(-1) == true);

		BOOST_CHECK(car.SetSpeed(5) == true);
		BOOST_CHECK(car.SetGear(1) == false);
	}

BOOST_AUTO_TEST_SUITE_END()
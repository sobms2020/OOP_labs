#pragma once
#include <iostream>
#include "../library_3c/Big_decimal.h"
#pragma once
namespace lab_oop3 {
	long get_value() {
		while (true)
		{
			long a;
			std::cin >> a;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Oops, that input is invalid. Please try again.\n";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				return a;
			}
		}
	}

	void Init_from_long(Big_decimal& number) {
		std::cout << "Please enter a long int to initialize a number\n";
		long n;
		n = get_value();
		number.Big_decimal::Big_decimal(n);
	}
	void Init_from_str(Big_decimal& number) {
		std::cout << "Please enter a string to initialize a number\n";
		std::string str;
		std::cin >> str;
		try {
			number.Big_decimal::Big_decimal(str);
		}
	
		catch (std::invalid_argument& error) {
			std::cerr << error.what() << std::endl;
			return;
		}
	}
	void Input_number(Big_decimal& number) {
		std::cout << "Please enter in istream your number\n";
		try {
			std::cin >> number;
		}
		catch (std::invalid_argument& error) {
			std::cerr << error.what() << std::endl;
			std::cin.ignore(10000, '\n');  // ���������� n �������� � ������
			std::cin.clear();             // ������� ��� ����� � ������
			return;
		}
		if (std::cin.fail()) {
			std::cout << "Input error\n";
			std::cin.ignore(10000, '\n');  // ���������� n �������� � ������
			std::cin.clear();             // ������� ��� ����� � ������
		}
	}
	void Get_add_code(Big_decimal& number) {
		std::cout << "Getting additional code...\n";
		std::cout << (~number);
	}
	void Sum_numbers(Big_decimal& number) {
		Big_decimal second;
		Input_number(second);
		std::cout << "Result of sum\n";
		std::cout << (number + second);
	}
	void Sub_numbers(Big_decimal& number) {
		Big_decimal second;
		Input_number(second);
		std::cout << "Result of subtraction\n";
		std::cout << (number - second);
	}
	void Mult_by_ten(Big_decimal& number) {
		std::cout << "Result of multiplication\n";
		Big_decimal res(number);
		number.Prod_ten(res);
		std::cout << res;
	}
	void Div_by_ten(Big_decimal& number) {
		std::cout << "Result of division\n";
		Big_decimal res(number);
		number.Div_ten(res);
		std::cout << res;
	}
	void Output_number(Big_decimal& number) {
		std::cout << "Output...\n";
		std::cout << number;
	}
}

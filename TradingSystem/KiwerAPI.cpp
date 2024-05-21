#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "Interface.cpp"

using namespace std;
class KiwerAPI {
public:
	void login(string ID, string password) {
		cout << ID << " login success\n";
	}

	void buy(string stockCode, int count, int price) {
		cout << stockCode << " : Buy stock ( " << price << " * " << count << ")\n";
	}

	void sell(string stockCode, int count, int price) {
		cout << stockCode << " : Sell stock ( " << price << " * " << count << ")\n";
	}

	int currentPrice(string stockCode) {
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};

class InterfaceForKiwerAPI : public InterfaceAPI {
public:
	void login(string ID, string password) override
	{
		kapi.login(ID, password);
	}
	void buy(string stockCode, int count, int price) override
	{
		kapi.buy(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) override
	{
		kapi.sell(stockCode, count, price);
	}
	int currentPrice(string stockCode, int minute) override
	{
		return kapi.currentPrice(stockCode);
	}

private:
	KiwerAPI kapi;
};

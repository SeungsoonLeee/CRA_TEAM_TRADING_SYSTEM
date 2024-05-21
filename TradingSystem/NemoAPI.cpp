﻿#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "Interface.cpp"

using namespace std;
class NemoAPI {
public:
	void certification(string ID, string pass) {
		cout << "[NEMO]" << ID << " login GOOD\n";
	}

	void purchasingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	void sellingStock(string stockCode, int price, int count) {
		cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	int getMarketPrice(string stockCode, int minute) {
		//minute ms초 이후 구매가 되는 방식 (최소 1 ms)
		if (minute <= 0) minute = 1;
		Sleep(minute);
		srand(time(NULL));
		int ret = rand() % 10 * 100 + 5000;
		return ret;
	}
};

class InterfaceForNemoAPI : public InterfaceAPI {
public:
	void login(string ID, string password) override
	{
		napi.certification(ID, password);
	}
	void buy(string stockCode, int count, int price) override
	{
		napi.purchasingStock(stockCode, count, price);
	}
	void sell(string stockCode, int count, int price) override
	{
		napi.sellingStock(stockCode, count, price);
	}
	int currentPrice(string stockCode, int minute) override
	{
		return napi.getMarketPrice(stockCode, minute);
	}
private:
	NemoAPI napi;
};

#include "Interface.cpp"
using namespace std;

class TradingSystem {
public:
	TradingSystem(InterfaceAPI* _brocker) : brocker(_brocker) {

	}

	void login(string id, string pwd) {
		brocker->login(id, pwd);
	}

	void buy(string stockCode, int count, int price) {
		brocker->buy(stockCode, count, price);
	}

	void sell(string stockCode, int count, int price) {
		brocker->sell(stockCode, count, price);
	}

	int currentPrice(string stockCode, int minute)
	{
		return brocker->currentPrice(stockCode);
	}

private:
	InterfaceAPI* brocker;
};

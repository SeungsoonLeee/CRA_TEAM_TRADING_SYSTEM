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
		// 구현 필요
		brocker->buy(stockCode, count, price);
	}

	void sell(string stockCode, int count, int price) {
		// 구현 필요
	}

	int currentPrice(string stockCode, int minute)
	{
		return this->brocker->currentPrice(stockCode, minute);
	}

	bool buyNiceTiming(string stockCode, int price) {
		// 현재 가격이 3연속 상승 중이면 매수한다.
		int price1 = brocker->currentPrice(stockCode, 1);
		int price2 = brocker->currentPrice(stockCode, 2);
		int price3 = brocker->currentPrice(stockCode, 3);

		if (price1 < price2 && price2 < price3) {
			brocker->buy(stockCode, 5, price3);
			return true;
		}
		return false;
	}

	bool sellNiceTiming(string stockCode, int count) {
		// 현재 가격이 3연속 하락 중이면 매도한다.
		// 구현 필요
		int min = brocker->currentPrice(stockCode, 1);
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			int cur = brocker->currentPrice(stockCode, 1);
			if (min > cur) {
				min = cur;
				cnt++;
			}
			else {
				break;
			}
		}
		
		if (cnt == 3) {
			brocker->sell(stockCode, count, min);
		}

		return 0;
	}

private:
	InterfaceAPI* brocker;
};

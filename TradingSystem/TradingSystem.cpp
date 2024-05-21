#include "Interface.cpp"
using namespace std;

class TradingSystem {
public:
	TradingSystem(InterfaceAPI* _brocker) : brocker(_brocker) {

	}

	void login(string id, string pwd) {
		// 구현 필요
	}

	void buy(string stockCode, int count, int price) {
		// 구현 필요
	}

	void sell(string stockCode, int count, int price) {
		// 구현 필요
	}

	int currentPrice(string stockCode, int minute)
	{
		// 구현 필요
		return 0;
	}

	bool buyNiceTiming(string stockCode, int price) {
		// 현재 가격이 3연속 상승 중이면 매수한다.
		// 구현 필요
		return 0;
	}

	bool sellNiceTiming(string stockCode, int count) {
		// 현재 가격이 3연속 하락 중이면 매도한다.
		// 구현 필요
		return 0;
	}

private:
	InterfaceAPI* brocker;
};

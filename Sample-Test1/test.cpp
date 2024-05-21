#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/KiwerAPI.cpp"
#include "../TradingSystem/NemoAPI.cpp"
#include "../TradingSystem/TradingSystem.cpp"

using namespace std;
using namespace testing;

class MockAPI : public InterfaceAPI {
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sell, (string stockCode, int count, int price), (override));
	MOCK_METHOD(int, currentPrice, (string stockCode, int minute), (override));
};

class TradingTest : public testing::Test {
public:
	MockAPI mock;
	TradingSystem system{ &mock };
};

TEST_F(TradingTest, LoginTest) {

	EXPECT_CALL(mock, login("ABC", "123"))
		.Times(1);

	system.login("ABC", "123");
}

TEST_F(TradingTest, BuyTest) {

	EXPECT_CALL(mock, buy("ABC", 5, 150))
		.Times(1);

	system.buy("ABC", 5, 150);
}

TEST_F(TradingTest, SellTest) {

	EXPECT_CALL(mock, sell("ABC", 5, 150))
		.Times(1);

	system.sell("ABC", 5, 150);
}

TEST_F(TradingTest, CurrentPriceTest) {
	EXPECT_CALL(mock, currentPrice("1234", 1))
		.WillOnce(Return(100));
	
	EXPECT_EQ(system.currentPrice("1234", 1), 100);
}

TEST_F(TradingTest, buyNiceTiming) {
	// 가격이 올라가는 추세라면 매수
	// 3번 연속 가격이 오르면 올라가는 추세라고 생각
	// StockCode:1234  /  매수량:5  /  매수금액:최대금액
	EXPECT_CALL(mock, currentPrice("1234", 1))
		.WillOnce(Return(50));
	EXPECT_CALL(mock, currentPrice("1234", 2))
		.WillOnce(Return(100));
	EXPECT_CALL(mock, currentPrice("1234", 3))
		.WillOnce(Return(150));

	EXPECT_CALL(mock, buy("1234", 5, 150))
		.Times(1);

	system.buyNiceTiming("1234", 150);
}

TEST_F(TradingTest, sellNiceTiming) {
	// 가격이 내려가는 추세라면 매도
	// 3번 연속 가격이 내려가면 내려가는 추세라고 생각
	// StockCode:1234  /  매도량:5  /  매수금액:최소금액
	string stockCode = "1234";
	int stockCount = 5;
	int checkInterval = 1;
	
	EXPECT_CALL(mock, currentPrice(stockCode, checkInterval))
		.WillOnce(Return(150))
		.WillOnce(Return(100))
		.WillOnce(Return(50))
		.WillOnce(Return(25));

	EXPECT_CALL(mock, sell(stockCode, stockCount, 25))
		.Times(1);

	system.sellNiceTiming(stockCode, stockCount);
}

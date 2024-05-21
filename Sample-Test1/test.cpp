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

}

#include "gmock-test.h"



class gmock_test : public based
{
public:
	MOCK_METHOD0(display,int());
	MOCK_METHOD0(Afterdisplay, int());
};



class test1_1 {
public:
	int display()
	{
		return 0;
	}


	int display_1_1()
	{
		std::cout << "testestestestestestestestestestestest" << std::endl;

		return 0;
	}
};



TEST(display, testFunc_SetReturn)
{
	gmock_test mockFoo;

	test1_1 test;


	EXPECT_CALL(mockFoo, display()) //hock住display()函数
		.Times(testing::AtLeast(2)) //至少两次
		.WillOnce(testing::Return(111)) //第一次执行 修改返回结果为111
		.WillOnce(testing::Return(111)) //第二次执行 修改返回结果为111
		.WillRepeatedly(testing::Invoke(&test, &test1_1::display));  //从第三次及以后调用test1_1::display函数

	EXPECT_EQ(111, mockFoo.display());

	EXPECT_GE(111, mockFoo.display());

	EXPECT_THAT(0, mockFoo.display());

}





//int main(int argc, char** argv)
//{
//	testing::InitGoogleMock(&argc, argv);
//
//	return RUN_ALL_TESTS();
//}


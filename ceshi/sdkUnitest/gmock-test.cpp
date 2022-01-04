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


	EXPECT_CALL(mockFoo, display()) //hockסdisplay()����
		.Times(testing::AtLeast(2)) //��������
		.WillOnce(testing::Return(111)) //��һ��ִ�� �޸ķ��ؽ��Ϊ111
		.WillOnce(testing::Return(111)) //�ڶ���ִ�� �޸ķ��ؽ��Ϊ111
		.WillRepeatedly(testing::Invoke(&test, &test1_1::display));  //�ӵ����μ��Ժ����test1_1::display����

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


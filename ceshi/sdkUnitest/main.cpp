#include "gtest/gtest.h"
#include "Environment.h"
GTEST_API_ int main(int argc, char **argv) {

	//设置运行参数shuffle
	std::cout << "enter main" << std::endl;

	//andriod的响应是界面主动拉取的
#ifdef SDK_FOR_ANDROID
	signal(SIGKILL, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	std::thread andriodResp([&]() {
		while (!g_isExitAndriodRspThd)
		{
			bool bret = g_Client->getReponse();
			if (!bret) {
				printf("\n g_Client->getReponse failed! \n");
			}
			////设置oom_adj
			//std::string cmd;
			//cmd.append("sh -c 'echo -17 > /proc/");
			//cmd.append(Tools::int64_To_Str(getpid()));
			//cmd.append("/oom_adj\'");
			//system(cmd.data());
			/*int64 currentSize = getCurrentRSS() / MB;
			int64 peakSize = getPeakRSS() / MB;*/
			//std::cout << "currentMemorySize=" << Tools::int64ToStr(currentSize) << "MB" << std::endl;
		}
	});
	andriodResp.detach();
#endif

	testing::GTEST_FLAG(output) = "xml";  //输出测试报告
	testing::GTEST_FLAG(repeat) = 1;   //测试用例重复执行次数
	testing::GTEST_FLAG(server) = m_config->m_server;
	testing::GTEST_FLAG(user) = m_config->m_account;
	testing::GTEST_FLAG(break_on_failure) = false;   //用例失败时不停止
	testing::GTEST_FLAG(throw_on_failure) = false;   //当用例失败时不以C++的方式抛出异常
	testing::GTEST_FLAG(catch_exceptions) = false;   //不捕捉异常
	testing::GTEST_FLAG(shuffle) = false;
#ifdef _WIN32
	std::thread monitor([&]() {
		system("python monitor.py vstest.exe win");
	});
	monitor.detach();
#endif
	std::cout << "enter testing::InitGoogleTest" << std::endl;
	testing::InitGoogleTest(&argc, argv);
	std::cout << "leave testing::InitGoogleTest" << std::endl;

	RUN_ALL_TESTS();


	std::cout << "exit main" << std::endl;
	return 0;
}

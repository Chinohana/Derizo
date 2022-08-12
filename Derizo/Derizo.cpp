/*有你这种程序员真丢脸啊*/
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

std::ofstream inFile;  // inFile an ifstream object (P.160) 

int InitializationData()  //数据的初始化
{
	using namespace std;
	ofstream file{ "data" };  //创建一个文件
	auto Name = "None", Target = "None";
	int Target_Money = 0, Your_Money = 0, Left_Money = 0, Completeness = 0;  //定义并初始化各个数据，（可以考虑使用类与对象）
	inFile.open("data.txt");
	inFile << Name << endl << Target << endl << Target_Money << endl << Your_Money;  //写入数据
	return 0;
}

int WriteData(char Name, char Target, int Target_Money, int Your_Money)  //写入数据
{
	using namespace std;
	
	inFile.open("data");
	if (inFile.is_open())  //如果文件被正常打开
	{
		inFile << Name << endl << Target << endl << Target_Money << endl << Your_Money;  //那么就写入文件
		inFile.close();
		return 0;
	}
	else  //反则返回1
	{
		return 1;
	}
	
}

int CheckData()  //检查数据是否存在以及数据是否正常
{
	std::ifstream inFile;  
	inFile.open("data");  //inFile used to read data.txt (P.161)
	if (!inFile.is_open())
	{
		return 1;  //如果找不到目标文件就返回1
	}
	else
	{
		char ch;
		inFile >> ch;  //读取一个字符
		bool a = inFile.eof();
		if (inFile.eof())  //如果文件啥都没有也返回1
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	inFile.close();
}

int main()
{
	using namespace std;

	char Name;
	int CheckDataReturn = CheckData();

	cout << "Derizo-您的生活目标小助手" << endl << endl;  //主菜单的文字啥的，目前没有完成
	if (CheckDataReturn == 0x00020100 or CheckDataReturn == 0x00020101)
	{
		cout << "系统没有找到您的数据文件，您可能新用户？如果是，请按Enter，如果不是，请关闭软件。" << endl;
		getchar();
		cout << "欢迎！Derizo是您的生活目标小助手，您可以在此记录您的目标，还有完成多少等指标。事不宜迟，当您准备好后，请按Enter以开始。" << endl;
		getchar();
		system("cls");
		cout << "接下来我们将初始化data文件，请确认文件内的文件不再重要。（若您是第一次使用本软件，或没有异议的，请按Enter开始初始化数据。）" << endl;
		getchar();
		InitializationData();
		cout << "首先，你的名字是？" << endl;
		cin >> Name;
		cout << "很好，接下来交给我们……" << endl;
		int FirstWriteDataReturn = WriteData(Name,NULL,NULL,NULL);  //尝试将名字写入数据
		
		if (FirstWriteDataReturn == 1)
		{
			cout << "写入出错！" << endl << "在WriteData()出现错误！FirstWriteDataReturn的数据为1" << endl;
		}
		else
		{
			int FirstWriteCheckDataReturn = CheckData();
			if (FirstWriteCheckDataReturn == 1)
			{
				cout << "写入出错！" << endl << "在CheckData()出现错误！FirstWriteCheckDataReturn的数据为1" << endl;
			}
		}
	}

	return 0;
}

#include <iostream>
using namespace std;
const double eps = 1e-6;

class CPU {
private:
	char rank;
	int frequency;
	double voltage;

public:
	CPU(char c, int f, double v){
		rank = c;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU：" << endl;
		cout << "CPU等级：" << rank << " 主频：" << frequency;
		cout << " 电压：" << voltage << endl;
	}

	~CPU() {
		cout << "析构了一个CPU！" << endl;
	}

	void Run() {
		cout << "CPU 开始运行！" << endl;
	}

	void Stop() {
		cout << "CPU 停止运行！" << endl;
	}
};

int main()
{
	char c;
	int f;
	double v;
	cout << "Please input the rank of the CPU: ";
	cin >> c;
	cout << "Please input the frequency of the CPU: ";
	cin >> f;
	cout << "Please input the voltage of the CPU: ";
	cin >> v;

	//参数检查，参数非法输出提示信息并退出主函数
	if (f <= 0)
	{
    	cout << "Input Error: The frequency must be a number over 0!\n";
    	return 0;
	}
    if (v < eps)
    {
    	cout << "Input Error: The voltage must be a number over 0!\n";
    	return 0;
    }

	CPU Intel(c, f, v);
	Intel.Run();
	Intel.Stop();

    return 0;
}

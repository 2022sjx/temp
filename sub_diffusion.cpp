#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//Gumma函数 为tgamma()
#define xn 50 
#define tn 100
#define pi acos(-1)
const double xh = 1.0 / xn;//x方向的步长
const double th = 1.0 / tn;//t时间方向的分割

//系数
const double alpha = 0.9;
const double a0 = 1.0;
const double c0 = a0;
const double b0 = (1.0 / (2.0 - alpha)) - 0.5;

//矩阵的元素
vector<double>a(xn + 1);		//主对角线上的元素
vector<double>c(xn + 1);		//上辅对角线上的元素
vector<double>b(xn + 1);		//下辅对角线上的元素
vector<double>u_0(xn + 1);		//数值解
vector<double>u_1(xn + 1);		//数值解
vector<double>yy(xn + 1);		//右边列

//精确解 
double exact_solution(double x, double tt);

//函数
double  ff(double x, double tt);
double f_1(double t);
double f_2(double t);

//系数al和bl;
double a_l(int j);
double b_l(int j);
double c_l(int k, int n);

//系数r1, r2
double r1 = (tgamma(2.0 - alpha) * pow(th, alpha)) / pow(xh, 2);
double r2 = (tgamma(2.0 - alpha) * pow(th, alpha));

int main(void)
{
	ofstream data_numberical("EX01.txt");
	ofstream data_error("Error.txt");

	vector<double> b_0(xn + 1);		//右边的值

	//上对角线上的元素为
	for (int i = 0; i <= xn; i++)	c[i] = -r1;
	//下对角线上的元素为
	for (int i = 0; i <= xn; i++)	b[i] = -r1;

	//t 时间
	for (int n = 1; n <= tn; n++) 
	{
		u_0[0] = f_1(n * th);
		u_0[xn] = f_2(n * th);
	}

	
	

	return 0;
}
 
/*主对角线上的元素
for (int i = 0; i <= xn; i++)
	a[i] = c_l(k, n) + 2 * r1;*/

//系数al
double a_l(int j)
{
	if (j == 0)
		return 1.0;     //a0
	if (j > 0)
		return pow(j + 1, 1.0 - alpha) - pow(j, 1.0 - alpha);  //al的值
	return 0;
}

 //系数bl;
double b_l(int j)
{
	if (j == 0)  //b0
		return (1.0 / (2.0 - alpha)) - 0.5;
	if (j > 0)   //b的值
		return (1.0 / (2.0 - alpha)) * (pow(j + 1, 2.0 - alpha) - pow(j, 2.0 - alpha)) - 1.0 / 2.0 * (pow(j + 1, 1.0 - alpha) + pow(j, 1.0 - alpha));
	return 0;
}

double c_l(int k, int n)
{
	if (n == 1)
	{
		return a_l(0);
	}
	else
	{
		if (k == 0)
			return a_l(k) + b_l(k);
		else if (k >= 1 && k <= n - 2)
			return a_l(k) + b_l(k) - b_l(k - 1);
		else if (k == n - 1)
			return a_l(k) - b_l(k - 1);
		else
			return 0;
	}

	return 0;
}

//精确解
double exact_solution(double x, double tt)
{
	return exp(x) * pow(tt, 4 + alpha);
}
//函数
double  ff(double x, double tt)
{
	return exp(x) * pow(tt, 4) * (tgamma(5.0 + alpha) / 24.0 - pow(tt, alpha));
}

double f_1(double t)
{
	return pow(t, 4 + alpha);
}

double f_2(double t)
{
	return exp(1) * pow(t, 4 + alpha);
}



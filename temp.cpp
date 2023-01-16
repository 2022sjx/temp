//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double Gumma(double mm);
//const double alpha = 0.9;
//
//double a_l(int j);
//double b_l(int j);
//double c_l(int k, int n);
//
//int main(void)
//{
//	/*cout << "Please input the number：" << endl;
//	int number_01;
//	cin >> number_01;
//	cout << "exp(" << number_01 << ") = " << exp(number_01) << endl;*/
//
//	/*float x = 0.0;
//	int y = 1;
//	int number_03 = 2;
//	double number_02 = 2.0 / 3.0;
//	double number_04 = 1.0 / 2.0;
//
//	cout << "For x = " << x << ", tgamma(x) = " << tgamma(x) << endl;
//	cout << "For y = " << y << ", tgamma(y) = " << tgamma(y) << endl;
//	cout << "For number_03 = " << number_03 << ", tgamma(number_03) = " << tgamma(number_03) << endl;
//	cout << "For number_02 = " << number_02 << ", tgamma(number_02) = " << tgamma(number_02) << endl;
//	cout << "For number_04 = " << number_04 << ", tgamma(number_04) = " << tgamma(number_04) << endl;
//	cout << "For number_04 = " << number_04 << ", Gumma(number_04) = " << Gumma(number_04) << endl;
//	cout << "For number_03 = " << number_03 << ", pow(number_03) = " << pow(number_03, number_04) << endl;*/
//
//	//int j, n;
//
//	//cout << "默认的定义变量值是：" << endl;
//	//cout << "j = " << j << ", " << "n = " << n << endl;
//
//	/*cout << "Attention: This is the b_j:" << endl;
//	cout << "Please input the number j = ";
//	cin >> j;
//	cout << "Please input the number n = ";
//	cin >> n;
//
//	cout << "a( " << j << " ) = " << a_l(j) << endl;
//	cout << "b( " << j << " ) = " << b_l(j) << endl;
//	cout << "c( " << j << " ) = " << c_l(j, n) << endl;*/
//
//	/*
//	* 表示的是精确解的图像
//	ofstream test_data("test_data.txt");
//	//test data: the exact solutuion
//	for (int n = 0; n <= tn; n++)
//	{
//		if (n % 10 == 0)
//		{
//			test_data << "zone f = point" << endl;
//			for (int i = 0; i <= xn; i++)
//			{
//				cout << i * xh << " " << exact_solution(i * xh, n * th) << endl;
//				test_data << i * xh << " " << exact_solution(i * xh, n * th) << endl;
//
//			}
//		}
//	}
//	*/
//	
//
//	return 0;
//}
//
//double a_l(int j)
//{
//	if (j == 0)
//		return 1.0;     //a0
//	if (j > 0)
//		return pow(j + 1, 1.0 - alpha) - pow(j, 1.0 - alpha);  //al的值
//	return 0;
//}
//
//double b_l(int j)
//{
//	if (j == 0)  //b0
//		return (1.0 / (2.0 - alpha)) - 0.5;
//	if (j > 0)   //b的值
//		return (1.0 / (2.0 - alpha)) * (pow(j + 1, 2.0 - alpha) - pow(j, 2.0 - alpha)) - 1.0 / 2.0 * (pow(j + 1, 1.0 - alpha) + pow(j, 1.0 - alpha));
//	return 0;
//}
//
//double c_l(int k, int n)
//{
//	if (n == 1)
//	{
//		return a_l(0);
//	}
//	else 
//	{
//		if (k == 0)
//			return a_l(k) + b_l(k);
//		else if (k >= 1 && k <= n - 2)
//			return a_l(k) + b_l(k) - b_l(k - 1);
//		else if (k == n - 1)
//			return a_l(k) - b_l(k - 1);
//		else
//			return 0;
//	}
//
//	return 0;
//}
//
//double Gumma(double mm)
//{
//	double a[11] = { 0.0000677106,-0.0003442342,0.0015397681, -0.0024467480,0.0109736958,-0.0002109075, 0.0742379071,0.0815782188,0.4118402518,	 0.4227843370,1.0 };
//	double t = 0;
//	double s = 0;
//	double u = 0;
//	int  i;
//	if (mm <= 0.0)
//	{
//		cout << "Error!" << endl;
//	}
//	else if (mm <= 1.0)
//	{
//		t = 1.0 / (mm * (mm + 1.0));
//		mm = mm + 2.0;
//	}
//	else if (mm <= 2.0)
//	{
//		t = 1.0 / mm;
//		mm = mm + 1.0;
//	}
//	else if (mm <= 3.0)
//	{
//		t = 1.0;
//	}
//	else
//	{
//		t = 1.0;
//		while (mm > 3.0)
//		{
//			mm = mm - 1.0;
//			t = t * mm;
//		}
//	}
//	s = a[0];
//	u = mm - 2.0;
//	for (i = 1; i <= 10; i++)
//	{
//		s = s * u + a[i];
//	}
//	s = s * t;
//	return s;
//}
//
///*
//*		285~352表示的是L1-2格式
//*		//到num=268时出现nan
//      if(num==1)
//	  {
//		  for(i=0;i<Nx;i++)
//		  {
//			  T[num][i]=(Gamma(2.0-alpha)*pow(dt,alpha)*(DV1[i])+c0*Told[num-1][i])/c0;
//		  }
//	  }
//      if(num==2)
//      {//n1
//		for(i=0;i<Nx;i++)
//		{
//			double c0n=a0+b0;
//			double c1n=a_l(1)-b0;
//
//		  T[num][i]=(Gamma(2.0-alpha)*pow(dt,alpha)*DV1[i]+(c0n-c1n)*T[1][i]+c1n*T[0][i])/c0n;
//		}
//      }//n1
//      if(num>=3)
//      {//n1
//    	for(i=0;i<Nx;i++)
//		{//n2
//			double s=0.0;
//			double c0n=a0+b0;
//			double cnn=a_l(num-1)-b_l(num-2);
//
//			double cnj=0.0;
//			double cnj1=0.0;
//		  for(j=0;j<=num-2;j++)
//		  {//n3
//			  if(j==0)
//			  {
//				  cnj=a0+b0;
//				  cnj1=a_l(j+1)+b_l(j+1)-b0;
//			  }
//			  if(num==3&&j==1)
//			  {
//                 cnj=a_l(j)+b_l(j)-b0;
//				  cnj1=a_l(j+1)-b_l(j);
//			  }
//              if(num>3&&j>=1&&j<=num-3)
//			  {
//                cnj=a_l(j)+b_l(j)-b_l(j-1);
//				  cnj1=a_l(j+1)+b_l(j+1)-b_l(j);
//			  }
//			  if(num>3&&j>=num-2)
//			  {
//                cnj=a_l(j)+b_l(j)-b_l(j-1);
//				  cnj1=a_l(j+1)-b_l(j);
//			  }
//			  s=s+(cnj-cnj1)*T[num-1-j][i];
//
//			 if(j>nump0)  break;
//		  }//n3
//		foutS<<s<<endl;
//		  T[num][i]=(Gamma(2.0-alpha)*pow(dt,alpha)*DV1[i]+s+cnn*T[0][i])/c0n;
//		}//n2
//      }//n1
//   
//*/
#include<iostream>
#include <math.h>
using namespace std;
int main()
{   
	//bisection method
	float low = 0.00, high = 1.00, middle, PV, vertex;
	
	vertex = 296.0/(9702 * 2); 

	//���I�k���ײv����
	while (high - vertex >= 0.0001)
	{
		middle = (vertex + high)/2;
		
		PV = 9702 - 19700/(1 + middle) + 10000/pow((1 + middle), 2);
		if (PV > 0)

			high = middle;
		else
			vertex = middle;
	}
	cout<<"By bisection:"<<endl<<high<<endl; 

	//���I�����ײv���t 
	while (vertex - low >= 0.0001)
	{
		middle = (low + vertex) / 2;
		PV = 9702 - 19700/(1 + middle) + 10000/pow((1 + middle), 2);
		if (PV > 0)
			low = middle;
		else
			vertex = middle;
	}
	cout<<vertex<<endl<<endl;

	//newton method
	//�k
	double x = 1, a, b;
	while (9702 - 19700/(1 + x) + (10000/pow((1 + x), 2)) >= 0.0001)
	{
		a = 9702 - 19700/(1 + x) + 10000/pow((1 + x), 2);
		b = 19700/pow((1 + x), 2) - 10000*2/pow((1 + x), 3);  //��x�L��
		x = x - (a / b);
	}
	cout<<"By Newton:"<<endl<<x<<endl;

	//����
	x = 0, a, b;
	while (9702 - 19700/(1 + x) + (10000/pow((1 + x), 2))  >= 0.0001)
	{
		a = 9702 - 19700/(1 + x) + 10000/pow((1 + x), 2);
		b = 19700/pow((1 + x), 2) - 10000*2/pow((1 + x), 3);  
		x = x - (a / b);
	}
	cout<<x<<endl;
	
    return 0;
}


#pragma once

template <typename V>
class Vectors
{
public:
	V x;
	V y;
	V z;
	V w;
	Vectors(V a, V b)
	{
		x = a;
		y = b;
	}
	Vectors(V a, V b, V c)
	{
		x = a;
		y = b;
		z = c;
	}
	Vectors(V a, V b, V c, V d)
	{
		x = a;
		y = b;
		z = c;
		w = d;
	}
	Vectors twoAdd(Vectors &other)
	{
		Vectors temp(0, 0);
		temp.x = x + other.x;
		temp.y = y + other.y;
		return temp;
	}
	Vectors threeAdd(Vectors &other)
	{
		Vectors temp(0, 0, 0);
		temp.x = x + other.x;
		temp.y = y + other.y;
		temp.z = z + other.z;
		return temp;
	}
	Vectors twoSub(Vectors &other)
	{
		Vectors temp(0, 0, 0);
		temp.x = x - other.x;
		temp.y = y - other.y;
		temp.z = z - other.z;
		return temp;
	}
	Vectors threeSub(Vectors &other)
	{
		Vectors temp(0, 0, 0);
		temp.x = x - other.x;
		temp.y = y - other.y;
		temp.z = z - other.z;
		return temp;
	}
	int twoMagnitude()
	{
		int mag = sqrt((x ^ 2) + (y ^ 2));
		return mag;
	}
	int threeMagnitude()
	{
		int mag = sqrt((x ^ 2) + (y ^ 2) + (z ^ 2));
		return mag;
	}
	Vectors twoNormalize()
	{
		Vectors temp(0, 0);
		int length = sqrt((x ^ 2) + (y ^ 2));
		temp.x = x / length;
		temp.y = y / length;
		return temp;
	}
	Vectors threeNormalize()
	{
		Vectors temp(0, 0, 0);
		int length = sqrt((x ^ 2) + (y ^ 2) + (z ^ 2));
		temp.x = x / length;
		temp.y = y / length;
		temp.y = z / length;
		return temp;
	}
	Vectors v4Normalize()
	{
		Vectors temp(0, 0, 0, 0);
		int length = sqrt((x ^ 2) + (y ^ 2) + (z ^ 2) + (w ^ 2));
		temp.x = x / length;
		temp.y = y / length;
		temp.z = z / length;
		temp.w = w / length;
		return temp;
	}
	int twoDotProd(Vectors &other)
	{
		int dot;
		Vectors temp(0, 0);
		temp.x = x * other.x;
		temp.y = y * other.y;
		dot = temp.x + temp.y;
		return dot;
	}
	int threeDotProd(Vectors &other)
	{
		int dot;
		Vectors temp(0, 0, 0);
		temp.x = x * other.x;
		temp.y = y * other.y;
		temp.z = z * other.z;
		dot = temp.x + temp.y + temp.z;
		return dot;
	}
	Vectors twoCrossProd(Vectors &other)
	{
		Vectors temp(0, 0);
		temp.x = y * other.x - x * other.y;
		temp.y = x * other.y - y * other.x;
		return temp;
	}
	Vectors threeCrossProd(Vectors &other)
	{
		Vectors temp(0, 0, 0);
		temp.x = y * other.z - z * other.y;
		temp.y = z * other.x - x * other.z;
		temp.z = x * other.y - y * other.x;
		return temp;
	}

	void twoPrint()
	{
		cout << "( " << x << " , " << y << " )" << endl;
	}
	void threePrint()
	{
		cout << "( " << x << " , " << y << " , " << z << " )" << endl;
	}
	void fourPrint()
	{
		cout << "( " << x << " , " << y << " , " << z << " , " << w << " )" << endl;
	}
};

double degToRad(int d)
{
	return (d / 180)*3.14;
}

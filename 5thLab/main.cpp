#include "funcs.h"
#include "vecpoint.h"

int main() {
	double x, y, z;
	std::cout << "First surface\n";
	std::cout << "Input double coordinates (x, y, z) of 1st vector: \n";
	std::cin >> x >> y >> z;
	Vector3D v1(x, y, z);
	std::cout << "Input double coordinates (x, y, z) of 2nd vector: \n";
	std::cin >> x >> y >> z;
	Vector3D v2(x, y, z);
	Surface s1(v1, v2);

	std::cout << "\nSecond surface\n";
	std::cout << "Input double coordinates (x, y, z) of 1st vector: \n";
	std::cin >> x >> y >> z;
	v1 = Vector3D(x, y, z);
	std::cout << "Input double coordinates (x, y, z) of 2nd vector: \n";
	std::cin >> x >> y >> z;
	v2 = Vector3D(x, y, z);
	Surface s2(v1, v2);

	bool res = isParallel(s1, s2);;
	if (res)
	{
		std::cout << "RESULT: Surfaces are parallel\n";
	}
	else {
		std::cout << "RESULT: Surfaces are not parallel\n";
	}
	return 0;
}
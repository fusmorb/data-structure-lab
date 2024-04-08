#include <cstdio>
//#include "Car.h"
//#include "SportsCar.h"
#include "Rectangle.h"

int main() {
	/*//Car 클래스 사용
	Car myCar(50, "K3",4);
	Car yourCar(100, "K5", 3);
	myCar.display();
	yourCar.display();
	myCar.whereAmI();
	yourCar.whereAmI();
	//SportsCar 클래스 사용
	SportsCar scar;
	scar.speedUp();
	*/
	Rectangle r(10, 20);
	double perimiter = r.getPerimeter();
	std::cout << "Rectangle 1:" << std::endl;
	std::cout << "Area:" << r.getArea() << std::endl;
	std::cout << "Perimeter:" << perimeter < , std::endl;
	std::cout << "is square?" << std::boolalpha < , r.isSquare() << std::endl;
}
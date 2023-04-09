
#include <iostream>
#include "Parking.h"

int main() {
    std::cout << "Hello World3!\n";
//0 -->Obstacle 1-->Free 2-->Car

    Parking parking = Parking(4, 3); // Create Parking object with width = 3, height = 4
    // Iterate over the cells and print their values
   Car car1=  Car(1,1,"left");
    Car car2=  Car(1,2,"forward");
    Car car3=  Car(0,2,"right");
   parking.addCar(car1);
   parking.addCar(car2);
   parking.addCar(car3);
  parking.setObstacle(1,0);
    parking.setObstacle(2,2);
    parking.setObstacle(0,3);
    for (int i = 0; i < parking.getHeight(); ++i) {
        for (int j = 0; j < parking.getWidth(); ++j) {
            std::cout << parking.getCell(i, j) << " ";
        }
        std::cout << std::endl;
    }



//setCars ++
   // std::cout << parking.getCars().at(0).getX();
   // std::cout <<parking.moveCarUp(0,parking.getCars())<< std::endl;
//parking.moveCarUp(0,parking.getCars());
    //std::cout << std::endl;
   std::cout << parking.expand(2).at(0)<<"<--";


    return 0;
}


#include <iostream>
#include "Parking.h"

int main() {
    std::cout << "Hello World3!\n";
    Parking();
    Parking access = Parking(3, 4); // unsorted data structure
    access.setRock(1,4);
    access.setRock(2,1);
    access.setRock(3,3);
    access.setCar(2,2);
    access.setCar(2,3);
    access.setCar(1,3);
    for (int i = 1; i <=3; i++) {
        for (int j = 1; j <=4; j++) {
            std::cout << access.getFree(i, j)<<"  " ;

        }
        std::cout <<"\n";
    }
}

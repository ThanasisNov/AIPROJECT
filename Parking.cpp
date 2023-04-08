
#include <iostream>
#include "Parking.h"


Parking::Parking()
{
    width_ = 4;
    height_= 3;

    for (int i = 0; i < height_; ++i)
    {
        grid_[i].resize(width_, 1); // Initialize each row with default value of 1 (free space)
    }

}
Parking::Parking(int width, int height)
{

    width_ = width;
    height_ = height;
    grid_.resize(height);
    std::cout << "Parking cpp1!\n";
    for (int i = 0; i < height; ++i)
    {

        grid_[i].resize(width, 1); // Initialize each row with default value of 1 (free space)
        std::cout << "Parking cpp!\n";
    }
}
void Parking::setActionName(const std::string &action) {
    actionName_=action;
}
void Parking:: setCar(int x, int y)
{
grid_[x][y]=2;
}// Set a location as car
int Parking::getHeight() const {return height_;}
int Parking::getWidth() const {return width_;}
void Parking::setObstacle(int x, int y) {
    grid_[x][y]=0;
}
void Parking::clearCell(int x, int y) {
    grid_[x][y]=1;
}
int Parking::getCell(int x, int y) const {
    return grid_[x][y];
}

std::string Parking::getPath() const {
    if (prev_ == nullptr) {
        return ""; // Return empty string if no previous state
    } else {
        return prev_->getPath() + actionName_ + " "; // Recursively get path from previous state and
    }
}
  bool Parking::isFree(int x, int y) const {
    return grid_[x][y]==1;
}

bool Parking::isObstacle(int x, int y)const {
    return grid_[x][y]==0;
}

bool Parking::isCar(int x, int y)const {
    return grid_[x][y]==2;
}
void Parking::addCar(Car car) {
    setCar(car.getX(),car.getY());
    cars.push_back(car);
}
std::vector<Car> Parking::getCars() {
    return cars;
}

void Parking::moveCarUp(Car car) {
    // implement moveUp() function
    // update x coordinate to move up by 1 unit
//Need setCars so we can change the Vector
    //car.MoveUp();


}

void Parking::moveCarRight(Car car)  {
    // implement moveRight() function
    // update y coordinate to move right by 1 unit

}

void Parking::moveCarDown(Car car) {
    // implement moveDown() function
    // update x coordinate to move down by 1 unit

}

void Parking::moveCarLeft(Car car) {
    // implement moveLeft() function
    // update y coordinate to move left by 1 unit

}




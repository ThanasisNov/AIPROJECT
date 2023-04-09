#ifndef Parking_H
#define Parking_H
#include <vector>
#include <string>
#include "Car.h"

class Parking
{
public:
    Parking();

    Parking(int width, int height); // Constructor to create a parking space with specified dimensions
    void setObstacle(int x, int y); // Set a location as obstacle
    void setCar(int x, int y); // Set a location as car
    void clearCell(int x, int y); // Clear a location (remove car or obstacle)
    void setActionName(const std::string& action); // Set the action name for a particular location

    int getWidth() const; // Get the width (number of columns) of the parking space
    int getHeight() const; // Get the height (number of rows) of the parking space
    int getCell(int x, int y) const; // Get the content of a particular location
    std::string getPath() const; // Get the path taken in the parking space
     void addCar(Car car);
     std::vector<Car> getCars();
     void setCars(std::vector<Car> v);
    bool isFree(int x, int y) const; // Check if a location is free
    bool isObstacle(int x, int y) const; // Check if a location is an obstacle
    bool isCar(int x, int y) const; // Check if a location has a car
std::vector<Parking*> expand( int x);

    bool moveCarUp(int car, std::vector<Car>);
    bool moveCarDown(int car, std::vector<Car>);
    bool moveCarLeft(int car, std::vector<Car>);
   bool  moveCarRight(int car, std::vector<Car>);
Parking *BFS(Parking * in,Parking *go);



private:
    int width_; // Width of the parking space
    int height_; // Height of the parking space
    std::vector<std::vector<int>> grid_; // Grid to represent the parking space
    std::vector<Car> cars; //contains all cars
    std::string actionName_;
    Parking* prev_;
};
#endif
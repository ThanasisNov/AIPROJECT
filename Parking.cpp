
#include <iostream>
#include <queue>
#include <unordered_set>
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
void Parking::setCars(std::vector<Car> v) {cars=v;}

bool Parking::moveCarUp(int car, std::vector<Car> p) {

    if(p.at(car).getX()-1<0 ||p.at(car).getX()-1>getWidth())
    {
        clearCell(p.at(car).getX(),p.at(car).getY());
        std::cout<< car<<" Car left";
        p.erase(p.begin()+car);
        setCars(p);
        return true;

    }
    if(getCell(p.at(car).getX()-1,p.at(car).getY())==0 || getCell(p.at(car).getX()-1,p.at(car).getY())==2 )
    {
  std:: cout<<"Cannot move up";
return false;
    }
    clearCell(p.at(car).getX(),p.at(car).getY());
    Car car1= Car(p.at(car).getX()-1,p.at(car).getY(),p.at(0).getDirection());
    setCar(p.at(car).getX()-1,p.at(car).getY());
    p.at(car)=car1;

    setCars(p);
return true;

}

bool Parking::moveCarRight(int car, std::vector<Car> p)  {
    // implement moveRight() function
    // update y coordinate to move right by 1 unit
if(p.at(car).getY()+1<0 || p.at(car).getY()+1>getHeight())
{
    clearCell(p.at(car).getX(),p.at(car).getY());
    std::cout<< car<<" Car left";
    p.erase(p.begin()+car);
    setCars(p);
    return  true;
}

    if(getCell(p.at(car).getX(),p.at(car).getY()+1)==0 || getCell(p.at(car).getX(),p.at(car).getY()+1)==2 )
    {
        std:: cout<<"Cannot move right";
        return false;
    }
    clearCell(p.at(car).getX(),p.at(car).getY());
    Car car1= Car(p.at(car).getX(),p.at(car).getY()+1,p.at(0).getDirection());
    setCar(p.at(car).getX(),p.at(car).getY()+1);
    p.at(car)=car1;
    setCars(p);
    return true;

}

bool Parking::moveCarDown(int car, std::vector<Car> p) {
    // implement moveDown() function
    // update x coordinate to move down by 1 unit
    if(p.at(car).getX()+1<0 ||p.at(car).getX()+1>getWidth())
    {
        clearCell(p.at(car).getX(),p.at(car).getY());
        std::cout<< car<<" Car left";
        p.erase(p.begin()+car);
        setCars(p);
        return true;
    }
    if(getCell(p.at(car).getX()+1,p.at(car).getY())==0 || getCell(p.at(car).getX()+1,p.at(car).getY())==2)
    {
        std:: cout<<"Cannot move down";
        return false;
    }

    clearCell(p.at(car).getX(),p.at(car).getY());
    Car car1= Car(p.at(car).getX()+1,p.at(car).getY(),p.at(0).getDirection());
    setCar(p.at(car).getX()+1,p.at(car).getY());
    p.at(car)=car1;
    setCars(p);
    return true;

}

bool Parking::moveCarLeft(int car, std::vector<Car> p) {
    // implement moveLeft() function
    // update y coordinate to move left by 1 unit
    if(p.at(car).getY()-1<0 || p.at(car).getY()-1>getHeight())
    {
        clearCell(p.at(car).getX(),p.at(car).getY());
        std::cout<< car<<" Car left";
        p.erase(p.begin()+car);
        setCars(p);
        return true;
    }
    if(getCell(p.at(car).getX(),p.at(car).getY()-1)==0 ||getCell(p.at(car).getX(),p.at(car).getY()-1)==2 )
    {
        std:: cout<<"Cannot move left";
        return false;
    }
    clearCell(p.at(car).getX(),p.at(car).getY());
    Car car1= Car(p.at(car).getX(),p.at(car).getY()-1,p.at(0).getDirection());
    setCar(p.at(car).getX(),p.at(car).getY()-1);
    p.at(car)=car1;
    setCars(p);
    return true;

}
std::vector<Parking*> Parking::expand(int x)
{
    std::vector<Parking*> children;
    Parking *child;

    child= new Parking(*this);
    if(child->moveCarUp(x,child->getCars()))
    {
        children.push_back(child);

    }
    else
    {
        delete child;

    }
    child= new Parking(*this);
    if(child->moveCarDown(x,child->getCars()))
    {
        children.push_back(child);

    }
    else
    {
        delete child;

    }

    child= new Parking(*this);

    if(child->moveCarRight(x,child->getCars()))
    {

        children.push_back(child);
        delete child;
    }
    else
    {
        delete child;

    }
    child= new Parking(*this);
    if(child->moveCarLeft(x,child->getCars()))
    {

        children.push_back(child);

    }
    else
    {
        delete child;

    }



    return children;

}



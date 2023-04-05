#include <iostream>
#include "Parking.h"


Parking::Parking()
{
    std::cout << "Parking cpp!\n";
}
Parking::Parking(int x,int y)
{
    setX(x);
    setY(y);

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {

            free[i][j]=true;

        }

    }
}
void Parking::setCar(int x, int y) {
    free[x-1][y-1]=2;
}
void Parking::setRock(int x,int y)
{
    free[x-1][y-1]=false;

}

int Parking::getFree(int x,int y) {
    return free[x-1][y-1];
}


void Parking::setX(int x) {
    robX=x;
}
void Parking::setY(int y) {
    robY=y;
}
int Parking::getX() {
    return robX;
}
int Parking::getY() {
    return robY;
}
void Parking::setActionName(std::string x) {actionName=x;}
void Parking::setPrev(Parking *p) {prev=p;}
void Parking::setFree(int i, int j)
{
free[i][j]=true;
}

bool Parking:: goUp(Parking &n)
{
    if (getY()>0 && isFree(getX(),getY()+1))
    {
        n=*this;
        n.setY(n.getY()+1);
        n.setActionName("Up");
        n.setPrev(this);
        return true;
    }
    return false;
}
bool Parking::goLeft(Parking &n)
{
    if (getX()>0 && isFree(getX()-1,getY()))
    {
        n=*this;
        n.setX(n.getX()-1);
        n.setActionName("Left");
        n.setPrev(this);
        return true;
    }
    return false;
}
bool Parking:: goDown(Parking &n)
{
    if (getY()>0 && isFree(getX(),getY()-1))
    {
        n=*this;
        n.setY(n.getY()-1);
        n.setActionName("Down");
        n.setPrev(this);
        return true;
    }
    return false;
}

bool Parking:: goRight(Parking &n)
{
    if (getX()>0 && isFree(getX()+1,getY()))
    {
        n=*this;
        n.setX(n.getX()+1);
        n.setActionName("Right");
        n.setPrev(this);
        return true;
    }
    return false;
}
bool Parking::isFree(int x, int y) {

    return free[x][y];
}
#include <string>
class Parking
{

public:
	Parking();
	Parking(int X, int Y);
	void setFree(int i, int j);
    void setRock(int i ,int j);
    int getFree(int i,int j);
	int getY();
	int getX();
	bool isFree(int x, int y);
	void setX(int x);
	void setY(int y);
    void setActionName(std::string x);
    void setPrev(Parking* p);
void setCar(int x,int y);
    std::string toString() const;
	std::string getPath();


	
	bool goUp(Parking& n);
	bool goDown(Parking& n);
	bool goLeft(Parking& n);
	bool goRight(Parking& n);
private:
	int robX, robY;
  std::string direct;//where the car points
	int free[4][3];
	std::string actionName;
    Parking* prev;

};
#include <string>
class Parking
{

public:
	Parking();
	Parking(int X, int Y, bool lights);
	void setFree(int i, int j, bool f);
	int getY();
	int getX();
	bool isFree(int x, int y);
	void setX(int x);
	void setY(int y);
	std::string toString() const;
	std::string getPath();


	bool turnOn(Parking& n);
	bool turnOff(Parking& n);
	bool goUp(Parking& n);
	bool goDown(Parking& n);
	bool goLeft(Parking& n);
	bool goRight(Parking& n);
private:
	int robX, robY;
	bool lights;
	bool free[12][12];
	std::string actionName;
    Parking* prev;

};
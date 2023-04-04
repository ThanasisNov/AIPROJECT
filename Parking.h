#include <string>
class Parking
{

public:
	Parking();
	Parking(int X, int Y);
	void setFree(int i, int j,std::string direction);
	int getY();
	int getX();
	bool isFree(int x, int y);
	void setX(int x);
	void setY(int y);
	std::string toString() const;
	std::string getPath();


	
	bool goUp(Parking& n);
	bool goDown(Parking& n);
	bool goLeft(Parking& n);
	bool goRight(Parking& n);
private:
	int robX, robY;

	bool free[12][12];
	std::string actionName;
    Parking* prev;

};
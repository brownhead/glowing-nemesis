#include <iostream>
#include <cstring>

using namespace std;

struct Point {
	int x;
	int y;

	Point();
	Point(int zx, int zy);
	void set(int zx, int zy);
	bool operator==(const Point & p);
	void move(int zx, int zy);
};

bool Point::operator==(const Point & p) {
	return x == p.x && y == p.y;
}


Point::Point() : x(0), y(0) {
	// DO nothing
}

Point::Point(int zx, int zy) : x(zx), y(zy) {
	// Do nothing
}

void Point::set(int zx, int zy) {
	x = zx;
	y = zy;
}

class Player
{
	private:
		Point pos_;
		int health_;
		string name_;

	public: 
		Player();
		void setpos(int, int);
		Point getpos() const;
		void sethealth(int);
		void setname(string);
		void displayName();
		void movePlayer(int, int);
		
};

void Player::setname(string name)
{
	name_ = name ;
}
void Player::setpos(int xpos , int ypos)
{
	pos_.set(xpos, ypos);
}
Point Player::getpos() const {
	return pos_;
}
Player::Player(): pos_(0, 0)
{
	//do nothing
}
void Player::sethealth(int health)
{
	health_ = health;
}
void Player::displayName()
{
	cout << name_ << endl;
}
void Player::movePlayer(int x, int y)
{

	if((pos_.x) + x >= 0 && ((pos_.x) + x) < 80 )
	{
		pos_.x = (pos_.x) + x;
	}
	if( (pos_.y) + y >= 0 && ((pos_.y) + y) < 80)
	{
		pos_.y = (pos_.y) + y;
	}

}
//////Created a Player class that holds name, position, and health.

class Map {
	Player player_;
	char map_[80][80];

public:
	Map();
	void print();
	Player & player();
};

Map::Map() {
	for (unsigned i = 0; i < 80; ++i) {
		for (unsigned j = 0; j < 80; ++j) {
			map_[i][j] = '.';
		}
	}
}

Player & Map::player() {
	return player_;
}

void Map::print() {
	for (unsigned j = 0; j < 80; ++j) {
		for (unsigned i = 0; i < 80; ++i) {
			if (player_.getpos() == Point(i, j)) {
				cout << '@';
			} else {
				cout << map_[i][j];
			}
		}
		cout << endl;
	}
}

class Monster{

    //Data Members:
    Point pos;
	int monHealth;
    string monName;
public:
	// Constructor:
	Monster(string, int);

    // Member functions:

    // Map:
    //Map();

    //Position:
    void setPos(int, int);
    Point getPos() const;
    // Monster move/patterns/behavior:
    void moveMonster(int, int);
    void setPattern();
	// Health:
	void changeHealth(int, bool);
	void setHealth(int); 
	void setName(string);

	//Notes:
	// function that defines movement or a set of fuctions that define movement of monsters!!!

	// what is a monster will it be defined as a  single character or position?
};

Monster::Monster(string name, int health) :monName(name), monHealth(health) {}

void Monster::setPos(int xpos, int ypos){
	pos.set(xpos, ypos);
}

Point Monster::getPos() const{
	return pos;
}

void Monster::moveMonster(int x, int y){
	
	pos.x = pos.x + x;
	pos.y = pos.y + y;
}

void Monster::changeHealth(int amountToChange, bool addOrNot){
    // if true then add amountToChange to health
	if(addOrNot){
		monHealth += amountToChange;
	}

    // else subtract the amountToChange from health
	else{
		monHealth -= amountToChange;
	}
}

void Monster::setHealth(int health){
	monHealth = health;
}

void Monster::setName(string name){
	monName = name;
}

int main()
{
	Map map;
	
	cout << "Welcome to glowing-nemesis." << endl;


	string name;
	cout << "Enter the name of your warrior: ";
	cin >> name;
	map.player().setname(name);
	map.player().sethealth(100);

	string input;
	do
	{
		map.print();

		cout << "Where would you like to go? (W A S D) :";
		cin >> input;

		if(input == "W" || input == "w")
		{
			map.player().movePlayer(0,-1);
		}
		else if(input == "A" || input == "a")
		{
			map.player().movePlayer(-1,0);
		}
		else if(input == "S" || input == "s")
		{
			map.player().movePlayer(0,1);
		}
		else if(input == "D" || input == "d")
		{
			map.player().movePlayer(1,0);
		}

	} while (input != "end");
	/// Player movement control. Need to make a good way to prevent Player from going out of bounds.






	return 0;
}
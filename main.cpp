#include <iostream>
#include <cstring>

using namespace std;



void print_map(char zmap[80][80]) {
	for (unsigned i = 0; i < 80; ++i) {
		for (unsigned j = 0; j < 80; ++j) {
			cout << zmap[i][j];
		}
		cout << endl;
	}
}

class player
{
	private:
		int xpos_;
		int ypos_;
		int health_;
		string name_;

	public: 
		player();
		void setpos(int, int);
		void sethealth(int);
		void setname(string);
		void displayName();
		void movePlayer(int, int);
		
};

void player::setname(string name)
{
	name_ = name ;
}
void player::setpos(int xpos , int ypos)
{
	xpos_ = xpos;
	ypos_ = ypos;
}
player::player(): xpos_(0), ypos_(0)
{
	//do nothing
}
void player::sethealth(int health)
{
	health_ = health;
}
void player::displayName()
{
	cout << name_ << endl;
}
void player::movePlayer(int x, int y)
{
	xpos_ = (xpos_) + x;
	ypos_ = (ypos_) + y; 

}
//////Created a player class that holds name, position, and health.



int main()
{
	player p1;
	string name, pcontrol;




	cout << "Welcome to glowing-nemesis." << endl;

	char map[80][80];
	for (unsigned i = 0; i < 80; ++i) {
		for (unsigned j = 0; j < 80; ++j) {
			map[i][j] = '.';
		}
	}

	print_map(map);

	cout << "Enter the name of your warrior: ";
	cin >> name;
	p1.setname(name);
	p1.sethealth(100);
	//asks user for name of warrior

	while(pcontrol != "end")
	{
		pcontrol = "0";
		cout << "Where would you like to go? (W A S D) :";
		cin >> pcontrol;

		if( pcontrol == "W" || pcontrol== "w")
		{
			p1.movePlayer(0,-1);
		}
		else if(pcontrol == "A" || pcontrol=="a")
		{
			p1.movePlayer(-1,0);
		}
		else if(pcontrol=="S" || pcontrol=="s")
		{
			p1.movePlayer(0,1);
		}
		else if(pcontrol=="D" || pcontrol=="d")
		{
			p1.movePlayer(1,0);
		}

	}
	/// player movement control. Need to make a good way to prevent player from going out of bounds.






	return 0;
}
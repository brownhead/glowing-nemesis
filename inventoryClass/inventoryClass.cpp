#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "inventoryFunctions.h"

using namespace std;
struct Item
{	
	string itemName;
	int itemWeight;
 	string itemCategory;	
};

struct Weapon : public Item
{
	int damage;
};

struct Armor : public Item
{
	int percentReduce;
};

struct Consumable : public Item
{
	// Consubmable_effects effectC; Potential Implementation of effects data struct/class.
	int HP_healed;
};

// Functions that fill item vectors in main.
void Fill_Weapons(vector<Item *> & allWeaponsInventory)
{
	ifstream strInput;
	string nameInput;
	int damageInput;				
	int weightInput;		    	/// If txt file is not filled right								/// Compiler likes to Dump Core
									// Program likes to dump core;
	strInput.open("AllWeapons.txt"); /// 1st Column = Name, 2nd = Weight, 3rd = Damage
	while(strInput >> nameInput)
	{
		Item * vectorUnit  = new Weapon();
		allWeaponsInventory.push_back(vectorUnit);
		vectorUnit->itemCategory = "Weapon";
		vectorUnit->itemName   = nameInput;
		strInput >> weightInput;
		vectorUnit->itemWeight = weightInput;	
		strInput >> damageInput;
		static_cast<Weapon *>(vectorUnit)->damage = damageInput;	
	}
}

void Fill_Armors(vector<Item *> & allWeaponsInventory)
{
	ifstream strInput;
	string nameInput;
	int weightInput;				
	int percentReduceIn;   	/// If txt file is not filled right								/// Compiler likes to Dump Core
									// Program likes to dump core;
	strInput.open("AllArmors.txt"); 
	while(strInput >> nameInput)
	{
		Item * vectorUnit  = new Armor();
		allWeaponsInventory.push_back(vectorUnit);
		vectorUnit->itemCategory = "Armor";
		vectorUnit->itemName   = nameInput;
		strInput >> weightInput;
		vectorUnit->itemWeight = weightInput;	
		strInput >> percentReduceIn;
		static_cast<Armor *>(vectorUnit)->percentReduce = percentReduceIn;	
	}
}

void Fill_Consumables(vector<Item *> & allConsumablesInventory)
{
   ifstream strInput;
	string nameInput;
	int weightInput;				
	int HP_healedIN;   	/// If txt file is not filled right								/// Compiler likes to Dump Core
									// Program likes to dump core;
	strInput.open("AllConsumables.txt"); 
	while(strInput >> nameInput)
	{
		Item * vectorUnit  = new Consumable();
		allConsumablesInventory.push_back(vectorUnit);
		vectorUnit->itemCategory = "Consumable";
		vectorUnit->itemName   = nameInput;
		strInput >> weightInput;
		vectorUnit->itemWeight = weightInput;	
		strInput >> HP_healedIN;
		static_cast<Consumable *>(vectorUnit)->HP_healed = HP_healedIN;
	}  
	
}

int main()			// Vector of Pointers;
{	
	// Vectors of all Items by type. ( Item Pointers)
	vector<Item *> allWeaponsInventory;
	vector<Item *> allArmorsInventory;
	vector<Item *> allConsumablesInventory;

	// Functions that fill the above vectors through file input.
	Fill_Weapons(allWeaponsInventory);
	Fill_Armors(allArmorsInventory);
	Fill_Consumables(allConsumablesInventory);

	// Test Code --- Outputs items in Weapon (pointer) vector.
	cout << "Weapon Name\t" << "Damage" << endl; 
	for (int i = 0; i < 8; ++i)
	{	
		cout << allWeaponsInventory.at(i)->itemName << "\t" << 
		  static_cast<Weapon*>(allWeaponsInventory.at(i))->damage << endl;
	}
	
	// Test Code --- outputs items in armor vector.
	cout << endl;
	cout << "Armor Name\t" << "Percent Reduction" << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << allArmorsInventory.at(i)->itemName << "\t" <<
		static_cast<Armor*>(allArmorsInventory.at(i))->percentReduce << endl;
	}



}

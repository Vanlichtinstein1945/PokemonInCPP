/*
*
*
*	Brenan Patrick
*	Moves.cpp
*
*
*/
// Inclusions
#include "Moves.h"
#include <iostream>
#include <sstream>
#include <fstream>



// Adding Namespace For "cout", "floor", Etc.
using namespace std;



// 2D Array For Checking Type Effectiveness
//                                      NOR   FIR   WAT   GRA   ELE   ICE   FIG   POI   GRO   FLY   PSY   BUG   ROC   GHO   DRA   DAR   STE   FAI
const float effectiveChart[18][18] = { {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.5f, 1.0f}, //Normal
									   {1.0f, 0.5f, 0.5f, 2.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 0.5f, 1.0f, 2.0f, 1.0f}, //Fire
									   {1.0f, 2.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f}, //Water
									   {1.0f, 0.5f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f, 2.0f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f, 1.0f}, //Grass
									   {1.0f, 1.0f, 2.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f}, //Electric
									   {1.0f, 0.5f, 0.5f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f}, //Ice
									   {2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 2.0f, 0.0f, 1.0f, 2.0f, 2.0f, 0.5f}, //Fighting
									   {1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 2.0f}, //Poison
									   {1.0f, 2.0f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.0f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f}, //Ground
									   {1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f}, //Flying
									   {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 1.0f}, //Psychic
									   {1.0f, 0.5f, 1.0f, 2.0f, 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 0.5f, 1.0f, 2.0f, 0.5f, 0.5f}, //Bug
									   {1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f}, //Rock
									   {0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 1.0f}, //Ghost
									   {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 0.0f}, //Dragon
									   {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 0.5f}, //Dark
									   {1.0f, 0.5f, 0.5f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 0.5f, 2.0f}, //Steel
									   {1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f, 0.5f, 1.0f}  //Fairy
};

// Hash Table For Move Statuses
const map<STATUS, Status*> Statuses{
	{
		poison,
		new Status("Poison", " has been poisoned!")
	},
	{
		burn,
		new Status("Burn", " has been burned!")
	},
	{
		sleep,
		new Status("Sleep", " has fallen asleep!")
	},
	{
		paralyze,
		new Status("Paralysis", " is now paralyzed!")
	},
	{
		freeze,
		new Status("Freeze", " is frozen solid!")
	}
};

Move::~Move() {
	for (auto i = Statuses.begin(); i != Statuses.end(); ++i) {
		delete i->second;
	}
}

// Once A Move Hits, This Function Will Determine Damage And Set Off Effects
void Move::hit(int chanceToBonus, BasePokemon* atkPokemon, BasePokemon* defPokemon) const {
	int A;
	int D;
	if (category == Physical) {
		A = atkPokemon->get_stat(ATK);
		D = defPokemon->get_stat(DEF);
	}
	else {
		A = atkPokemon->get_stat(SPATK);
		D = defPokemon->get_stat(SPDEF);
	}
	int crit = 1;
	if (rand() % 17 == 0) { crit = 2; }
	float STAB = 1;
	const TYPES* atkTypes = atkPokemon->get_types();
	if (type == atkTypes[0] || type == atkTypes[1]) { STAB = 1.5f; }
	const TYPES* defTypes = defPokemon->get_types();
	float type1Effective = 1;
	if (defTypes[0] != None) { type1Effective = effectiveChart[type - 1][defTypes[0] - 1]; }
	float type2Effective = 1;
	if (defTypes[1] != None) { type2Effective = effectiveChart[type - 1][defTypes[1] - 1]; }
	float random = (rand() % 16) + 85;
	random /= 100;
	float damage = 2;
	damage *= atkPokemon->get_level();
	damage /= 5;
	damage += 2;
	damage *= power;
	damage *= (float)A / (float)D;
	damage /= 50;
	damage += 2;
	damage *= crit;
	damage *= STAB;
	damage *= type1Effective;
	damage *= type2Effective;
	damage *= random;
	cout << atkPokemon->get_name() << " dealt " << (int)damage << " damage to " << defPokemon->get_name() << "!\n";
	if (type1Effective * type2Effective > 1) { cout << "It was super effective!\n"; }
	else if (type1Effective * type2Effective == 0) { cout << "It had no effect!\n"; }
	else if (type1Effective * type2Effective < 1) { cout << "It wasn't very effective!\n"; }
	if (rand() % 101 < chanceToBonus) {
		cout << defPokemon->get_name() << Statuses.at(status)->get_message() << "\n";
	}
}

// Returns A Move Based On Table Stats From Given Name
Move* CreateMoveFromTable(string name) {
	// Generating Variables For Move Creation
	TYPES type;
	CATEGORIES category;
	int power;
	int accuracy;
	int maxPP;
	STATUS status;

	// Reading File For Specific Move's Stats
	// Based On Given Name
	fstream database;
	database.open("Moves.csv", ios::in);
	string temp;
	while (getline(database, temp, ',')) {
		if (temp == name) {
			getline(database, temp, ',');
			type = (TYPES)stoi(temp);
			getline(database, temp, ',');
			category = (CATEGORIES)stoi(temp);
			getline(database, temp, ',');
			power = stoi(temp);
			getline(database, temp, ',');
			accuracy = stoi(temp);
			getline(database, temp, ',');
			maxPP = stoi(temp);
			getline(database, temp);
			status = (STATUS)stoi(temp);
			break;
		}
		else {
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp, ',');
			getline(database, temp);
		}
		if (database.eof()) { break; }
	}

	database.close();

	return new Move(name, type, category, power, accuracy, maxPP, status);
}
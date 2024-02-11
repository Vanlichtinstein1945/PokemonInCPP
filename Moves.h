#ifndef MOVES_H
#define MOVES_H



#include "Pokemon.h"
#include <iostream>
#include <map>



// Class For Holding Status Information
class Status {
private:
	std::string name;
	std::string startMessage;
public:
	Status(std::string, std::string);
	inline std::string get_message() { return startMessage; }
};

// STATUS Enum
enum STATUS {
	poison,
	burn,
	sleep,
	paralyze,
	freeze
};

// Move Categories
enum CATEGORIES {
	Physical,
	Special,
	StatusChanging
};

// Class For Holding A Moves Data And Performing Its Actions
class Move {
	static float effectiveChart[18][18];
public:
	static std::map<STATUS, Status*> Statuses;
	std::string name;
	TYPES type;
	CATEGORIES category;
	int power;
	int accuracy;
	int maxPP;
	int currPP;
	STATUS status;
	Move(std::string, TYPES, CATEGORIES, int, int, int, STATUS);
	~Move();
	void hit(int, BasePokemon*, BasePokemon*);
};



#endif

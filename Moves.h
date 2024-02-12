#ifndef MOVES_H
#define MOVES_H



#include "Pokemon.h"
#include <iostream>
#include <map>



// STATUS Enum
const enum STATUS {
	poison,
	burn,
	sleep,
	paralyze,
	freeze
};

// Move Categories
const enum CATEGORIES {
	Physical,
	Special,
	StatusChanging
};

extern const float effectiveChart[18][18];


// Class For Holding Status Information
class Status {
private:
	const std::string name;
	const std::string startMessage;
public:
	inline Status(std::string name, std::string startMessage) : name{ name }, startMessage{ startMessage } {}
	inline std::string get_message() const { return startMessage; }
};


extern const std::map<STATUS, Status*> Statuses;


// Class For Holding A Moves Data And Performing Its Actions
class Move {
public:
	const std::string name;
	const TYPES type;
	const CATEGORIES category;
	const int power;
	const int accuracy;
	const int maxPP;
	int currPP;
	const STATUS status;

	inline Move(std::string name, TYPES type, CATEGORIES category, int power, int accuracy, int maxPP, STATUS status)
		: name{ name }, type{ type }, category{ category }, power{ power }, accuracy{ accuracy }, maxPP{ maxPP }, status{ status }
	{
		currPP = maxPP;
	}

	~Move();

	void hit(int, BasePokemon*, BasePokemon*) const;
};

// Move Creation Functions
Move* CreateMoveFromTable(std::string);


// Move Creation Functions
Move* CreateMoveFromTable(std::string);



#endif

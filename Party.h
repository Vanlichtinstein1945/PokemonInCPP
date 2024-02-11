#ifndef PARTY_H
#define PARTY_H



#include "Pokemon.h"
#include <vector>



// Class That Will Hold All Information About Any Given Party
class Party {
private:
	// Array Of Pointers To The Party's Pokemon
	std::vector<BasePokemon*> slots;
public:
	Party();
	~Party();
	BasePokemon* GetSlot(int);
	void InsertPokemon(int, BasePokemon*);
	BasePokemon* RemovePokemon(int);
	void SwapSlots(int, int);
	void PrintParty();
	int GetFirstEmptySlot();
	int GetFirstPokemonWithHealth();
};



#endif

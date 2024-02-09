#ifndef PC_H
#define PC_H



#include "Pokemon.h"
#include <vector>



// Base PC Class That Will Hold All Information About Any Saved Pokemon
class PC {
private:
	vector<BasePokemon*> pokemon;
public:
	BasePokemon* GetPokemonAtIndex(int);
	void DepositPokemonLast(BasePokemon*);
	BasePokemon* RemovePokemonSpecific(int);
	void SwapPokemon(int, int);
	void printPC();
	void savePC();
	void loadPC();
};



#endif
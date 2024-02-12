#ifndef PC_H
#define PC_H



#include "Pokemon.h"
#include <vector>



// Base PC Class That Will Hold All Information About Any Saved Pokemon
class PC {
private:
	std::vector<BasePokemon*> pokemon;

public:
	~PC();
	
	BasePokemon* GetPokemonAtIndex(int) const;
	
	void DepositPokemonLast(BasePokemon*);
	
	BasePokemon* RemovePokemonSpecific(int);
	
	void SwapPokemon(int, int);
	
	void printPC() const;
	
	void savePC() const;
	
	void loadPC();
};



#endif

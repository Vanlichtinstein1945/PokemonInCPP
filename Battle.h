#ifndef BATTLE_H
#define BATTLE_H



#include "Pokemon.h"
#include "Moves.h"



// Class To Hold And Run The Battle From
class Battle {
	static float accuracyStages[];
public:
	int accuracyStage = 0;
	int evasionStage = 0;
	void RunMove(BasePokemon*, BasePokemon*, Move*);
};



#endif

#ifndef BATTLE_H
#define BATTLE_H



#include "Pokemon.h"
#include "Moves.h"



extern const float accuracyStages[];


// Class To Hold And Run The Battle From
class Battle {
public:
    int accuracyStage = 0;
	int evasionStage = 0;

	void RunMove(BasePokemon*, BasePokemon*, Move*) const;
};



#endif

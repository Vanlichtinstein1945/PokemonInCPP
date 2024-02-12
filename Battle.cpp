/*
*
*
*	Brenan Patrick
*	Battle.cpp
*
*
*/
// Inclusions
#include "Pokemon.h"
#include "Moves.h"
#include "Battle.h"
#include <iostream>



// Adding Namespace For "cout", "floor", Etc.
using namespace std;



// Ratios Of Evasion And Accuracy Based On Stage
const float accuracyStages[] = { (float)33 / 100, (float)36 / 100, (float)43 / 100,
				 				   (float)50 / 100, (float)60 / 100, (float)75 / 100,
								   (float)100 / 100, (float)133 / 100, (float)166 / 100,
								   (float)200 / 100, (float)250 / 100, (float)266 / 100,
								   (float)300 / 100 };

// Once A Move Is Decided To Be Used, This Function Will Test If It Hits And Run Its Effects
void Battle::RunMove(BasePokemon* pokemon1, BasePokemon* pokemon2, Move* move) const {
	// Combine Accuracy And Evasion For Move Hit Testing
	int tempAccStage = accuracyStage;
	tempAccStage -= evasionStage;
	// Clamp Stage -7 < 0 < 7
	if (tempAccStage < -6) { tempAccStage = -6; }
	else if (tempAccStage > 6) { tempAccStage = 6; }
	cout << pokemon1->get_name() << " used " << move->name << "!\n";
	// Test If Move Hits, Add 6 To "tempAccStage" For Array Index Correction
	if (rand() % 101 < move->accuracy * (accuracyStages[tempAccStage + 6])) {
		move->hit(30, pokemon1, pokemon2);
	}
	else {
		// Test If Move Missed From Accuracy Or Evasion
		if (fabs(accuracyStage) < fabs(evasionStage)) {
			cout << pokemon2->get_name() << " evaded the attack!\n";
		}
		else {
			cout << "It missed!\n";
		}
	}
}

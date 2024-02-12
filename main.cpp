/*
*
*
*	Brenan Patrick
*	Main.cpp
*
*
*/
// Inclusions
#include "Party.h"
#include "PC.h"
#include "Pokemon.h"
#include "Moves.h"
#include "Battle.h"
#include "GUI.h"
#include <time.h>
#include <SFML/Graphics.hpp>



// Adding Namespace For "cout", "floor", Etc.
using namespace sf;



// Main Function To Test Program Up To This Point
int mainGUI() {
	// Creating SFML Window
	RenderWindow window(VideoMode(800, 600), "Pokemon", Style::Titlebar);

	// Creating Buttons In Center Of Window
	Button button1 = Button(300, 250, 200, 50, "Print Party", 24);
	Button QuitButton = Button(300, 310, 200, 50, "Quit", 24);

	// Creating A Party With A Pokemon At Index "0"
	Party* party = new Party();
	party->InsertPokemon(0, CreateBasePokemonFromTable(1, 50));

	// Looping While The Window Exists
	while (window.isOpen()) {
		Event event;
		// Bool For Preventing Multiple Click Events Off Of Single Mouse Click
		bool lock_click = false;
		// Grab Mouse Position In Window
		Vector2i position = Mouse::getPosition(window);
		// While Testing For Current Events
		while (window.pollEvent(event)) {
			// If Event Is The Window Closing
			if (event.type == Event::Closed) {
				window.close();
			}
			// If Event Is Mouse Button Pressed
			else if (event.type == Event::MouseButtonPressed) {
				// If The Mouse button Was Left-Click And "lock_click" Isn't Preventing Extra Clicks
				if (event.mouseButton.button == Mouse::Left && lock_click != true) {
					// If Click Was Inside Of "button1's" Position
					if (button1.clicked(position)) {
						// Print Our Party To Console
						party->PrintParty();
					}
					// If Click Was Inside Of "QuitButton's" Position
					else if (QuitButton.clicked(position)) {
						// Close The Window
						window.close();
					}
					// Set Click Prevention
					lock_click = true;
				}
			}
			// If Event Is Mouse Button Released
			else if (event.type == Event::MouseButtonReleased) {
				// If Mouse Button Was Left-Click
				if (event.mouseButton.button == Mouse::Left) {
					// Release Click Prevention
					lock_click = false;
				}
			}
		}

		// Shade Button When Mouse Is Overtop
		button1.hoverShade(position);

		// Clear Window, Draw Our Buttons, And Display To User
		window.clear();
		window.draw(button1);
		window.draw(QuitButton);
		window.display();
	}

	// Delete Allocated Pointer
	delete party;
	party = nullptr;

	return 0;
}

int main() {
	// Setting Random Seed
	srand(time(NULL));

	// Creating Poison Move
	Move* move = CreateMoveFromTable("Poison Sting");

	// Creating Two Pokemon Of Level 50
	BasePokemon* pokemon1 = CreateBasePokemonFromTable(1, 50);
	BasePokemon* pokemon2 = CreateBasePokemonFromTable(2, 50);

	// Creating A Battle And Running Our Poison Move
	Battle* battle = new Battle();
	battle->RunMove(pokemon1, pokemon2, move);

	// Deleting Our Allocated Pointers
	delete move;
	move = nullptr;
	delete pokemon1;
	pokemon1 = nullptr;
	delete pokemon2;
	pokemon2 = nullptr;
	delete battle;
	battle = nullptr;

	// Running The GUI
	//mainGUI();

	return 0;
}

/*
*
*
*	Brenan Patrick
*	GUI.cpp
*
*
*/
// Inclusions
#include "GUI.h"
#include <iostream>
#include <SFML/Graphics.hpp>



// Adding Namespace For "cout", "floor", Etc.
using namespace sf;
using namespace std;



// Button Constructor
Button::Button(int X, int Y, int width, int height, string buttonText, int textSize, Color textColor, Color buttonColor, string fontFilepath) {
	this->X = X;
	this->Y = Y;
	this->width = width;
	this->height = height;
	// Load Font And Set Text String/Position/Color
	if (!font.loadFromFile(fontFilepath)) {
		cout << "COULDN'T LOAD FONT: " << fontFilepath << "\n";
	}
	text.setFont(font);
	text.setString(buttonText);
	text.setCharacterSize(textSize);
	text.setFillColor(textColor);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(X + width / 2, Y + height / 2);
	// Creating Rectangle Shape And Setting Position/Color
	rect = RectangleShape(Vector2f(width, height));
	rect.setPosition(X, Y);
	this->buttonColor = buttonColor;
	rect.setFillColor(buttonColor);
}

// Drawing Button And Text To Screen
void Button::draw(RenderTarget& target, RenderStates states) const {
	target.draw(rect, states);
	target.draw(text, states);
}

// Testing If Mouse Is Inside Of Button Area
bool Button::checkMouseInside(Vector2i mousePos) {
	if ((mousePos.x > X && mousePos.x < X + width) && (mousePos.y > Y && mousePos.y < Y + height)) { return true; }
	else { return false; }
}

// Same As "checkMouseInside" But Was Created First For Click Event (May Remove later)
bool Button::clicked(Vector2i mousePos) {
	if (checkMouseInside(mousePos)) { return true; }
	else { return false; }
}

// Shading The Button When Mouse Is Overtop
void Button::hoverShade(Vector2i mousePos) {
	if (checkMouseInside(mousePos)) {
		rect.setFillColor(Color(buttonColor.r-50, buttonColor.g-50, buttonColor.b-50));
	}
	else {
		rect.setFillColor(buttonColor);
	}
}

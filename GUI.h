#ifndef GUI_H
#define GUI_H



#include <iostream>
#include <SFML/Graphics.hpp>



// Adding "std" Namespace For "cout", "floor", Etc.
using namespace sf;
using namespace std;



// Class To Handle Button Creation And Events
class Button : public sf::Drawable{
private:
	int X;
	int Y;
	int width;
	int height;
	Font font;
	Text text;
	Color buttonColor;
	RectangleShape rect;
public:
	Button(int, int, int, int, string, int, Color=Color(0, 0, 0), Color=Color(255, 255, 255), string="arial.ttf");
	virtual void draw(RenderTarget&, RenderStates) const;
	bool checkMouseInside(Vector2i);
	bool clicked(Vector2i);
	void hoverShade(Vector2i);
};



#endif
#ifndef GUI_H
#define GUI_H



#include <iostream>
#include <SFML/Graphics.hpp>



// Class To Handle Button Creation And Events
class Button : public sf::Drawable{
private:
	int X;
	int Y;
	int width;
	int height;
	sf::Font font;
	sf::Text text;
	sf::Color buttonColor;
	sf::RectangleShape rect;
public:
	Button(int, int, int, int, std::string, int, sf::Color=sf::Color(0, 0, 0), sf::Color=sf::Color(255, 255, 255), std::string="arial.ttf");
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool checkMouseInside(sf::Vector2i);
	bool clicked(sf::Vector2i);
	void hoverShade(sf::Vector2i);
};



#endif

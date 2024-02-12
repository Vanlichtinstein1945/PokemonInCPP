#ifndef GUI_H
#define GUI_H



#include <iostream>
#include <SFML/Graphics.hpp>



// Class To Handle Button Creation And Events
class Button : public sf::Drawable{
private:
	float X;
	float Y;
	float width;
	float height;
	sf::Font font;
	sf::Text text;
	sf::Color buttonColor;
	sf::RectangleShape rect;

public:
	Button(float, float, float, float, std::string, int, sf::Color=sf::Color(0, 0, 0), sf::Color=sf::Color(255, 255, 255), std::string="arial.ttf");
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	
	bool checkMouseInside(sf::Vector2i) const;
	
	bool clicked(sf::Vector2i) const;
	
	void hoverShade(sf::Vector2i);
};



#endif

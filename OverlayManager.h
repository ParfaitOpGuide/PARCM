#pragma once
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"

class OverlayManager
{
public:
	static OverlayManager* getInstance();

	void loadLoading();
	bool getIsLoading();

	void draw(sf::RenderWindow* window);
	void update();
	void setFade(int rate);

private:
	OverlayManager() {};
	OverlayManager(OverlayManager const&) {};             // copy constructor is private
	OverlayManager& operator=(OverlayManager const&) {};  // assignment operator is private
	static OverlayManager* sharedInstance;

	const std::string STREAMING_PATH = "Pika/";
	int frameCount = 0;
	int maxImages = 216;
	bool isLoading = true;
	bool fpsconverter = false;
	bool isFading = false;
	int fadeRate;

	std::vector<sf::Texture*> texList;
	sf::Sprite* sprite;
};


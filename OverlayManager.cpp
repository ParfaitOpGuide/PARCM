#include "OverlayManager.h"
#include <stddef.h>
#include <iostream>
#include <filesystem>

OverlayManager* OverlayManager::sharedInstance = NULL;

OverlayManager* OverlayManager::getInstance() {
	if (sharedInstance == NULL) {
		//initialize
		sharedInstance = new OverlayManager();
	}

	return sharedInstance;
}

void OverlayManager::loadLoading()
{
	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) {
		
			//<code here for loading asset>
			auto filePath = entry.path();
			sf::Texture* texture = new sf::Texture();
			texture->loadFromFile(filePath.string());
			texList.push_back(texture);
		}
	this->sprite = new sf::Sprite();
	sf::Texture* texture = texList[frameCount];
	this->sprite->setTexture(*texture);
	

}

bool OverlayManager::getIsLoading()
{
	return isLoading;
}

void OverlayManager::draw(sf::RenderWindow* window)
{
	window->draw(*sprite);
	frameCount++;
}

void OverlayManager::update()
{
	if (fpsconverter)
	{
		if (frameCount > maxImages) {
			frameCount = 0;
		}
		sf::Texture* texture = texList[frameCount];
		this->sprite->setTexture(*texture);

		if (isFading) {
			int alpha = sprite->getColor().a;
			alpha -= fadeRate;
			if (alpha < 0)
			{
				alpha = 0;
				isFading = false;
			}
			sprite->setColor(sf::Color(255, 255, 255, alpha));
		}
	}

	fpsconverter = !fpsconverter;
}

void OverlayManager::setFade(int rate)
{
	isFading = true;
	fadeRate = rate;
}

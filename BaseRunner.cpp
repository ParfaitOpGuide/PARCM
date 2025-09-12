#include "BaseRunner.h"

BaseRunner::BaseRunner() :
	window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::VideoMode::getDesktopMode().bitsPerPixel), "a", sf::Style::Close)
{
	sharedInstance = this;
	this->window.setFramerateLimit(int(FRAME_RATE));

	TextureManager::getInstance()->loadFromAssetList();

	BGObject* bObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	TextureDisplay* display = new TextureDisplay();
	GameObjectManager::getInstance()->addObject(display);

	FPSCounter* fpsCounter = new FPSCounter();
	GameObjectManager::getInstance()->addObject(fpsCounter);
}

void BaseRunner::run()
{
	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

	while (this->window.isOpen()) {
		currentTime = clock.getElapsedTime();
		float deltaTime = currentTime.asSeconds() - previousTime.asSeconds();

		this->fps = floor(1.0f / deltaTime);

		processEvents();
		update(sf::seconds(1.0f / this->fps));
		render();
	}
}

BaseRunner* BaseRunner::getInstance()
{
	return nullptr;
}

float BaseRunner::getFPS()
{
	return 0.0f;
}

void BaseRunner::render()
{
}

void BaseRunner::processEvents()
{
}

void BaseRunner::update(sf::Time elapsedTime)
{
}

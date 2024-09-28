#pragma once

#include "AudioManager.h"
#include "Menu.h"
#include "Worm.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Image icon;

	sf::Font font;
	sf::Text menuText;
	sf::Text readyText;
	sf::Text resetText;

	Worm* worm;

	Menu* menu;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;

	bool keyHeldA, keyHeldD, keyHeldW, keyHeldS, keyHeldM, keyHeldO, keyHeldR;

	bool gameActive, spawnActive, youWonActive;

	sf::Texture backgroundTexture, youWonTitleTexture;
	sf::Sprite backgroundSprite, youWonTitleSprite;

	int selectedLevel, youWonTitleCounter;

	std::vector<std::vector<int>> mapSandBlocks;
	std::vector<std::vector<int>> mapLevelSandBlocks;
	std::vector<std::vector<bool>> supportedSandBlocks;
	std::vector<std::vector<bool>> sandBlocksOnWorm;

	std::vector<SandBlock*> sandBlocks;
	std::vector<SandBlock*> levelSandBlocks;

	void initVariables();
	void initWindow();
	void initAudio();
	void initFonts();
	void initText();
	void initTexture();
	void initSprite();
	void initMenu();
	void initLevels();
	void initWorm();

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	sf::Vector2f getTextureCenterCoordinates(sf::Sprite sprite);
	bool getGameActive();
	void setGameActive(bool value);
	bool getSpawnActive();
	void setSpawnActive(bool value);
	bool getYouWonActive();
	void setYouWonActive(bool value);
	void resetMapsAndBlocks();
	void resetKeysWASD();
	void resetKeysMOR();

	//Modifiers

	//Functions
	const bool getWindowIsOpen() const;
	void pollEvents();
	bool getSandBlocksFallValues();
	bool getSandBlockSide(std::vector<std::vector<int>> map, bool side, int i, int j, int sizeMap, int axis);
	void dfs(int i, int j, const std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks);
	void setSupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);
	void dropUnsupportedBlocks(std::vector<std::vector<int>>& mapSandBlocks, const std::vector<std::vector<bool>>& supportedSandBlocks, std::vector<std::vector<bool>>& sandBlocksOnWorm);
	void spawnBlocks(std::vector<std::vector<int>>& map, std::vector<SandBlock*>& blocks, bool destructible, int x, int y);
	void moveIconLevels(int minIconLevel, int maxIconLevel, int resetIconLevel, int moveIconLevel, int extremeIconLevel, sf::Vector2f extremePosition, sf::Vector2f newPosition);
	bool wormIsFall(bool wormFalls, std::vector<SandBlock*> blocks, int x, int y, bool destructible);

	void updateInput();
	void updateMousePositions();
	void updateButtonScale(sf::Sprite& button, sf::Vector2f scale);
	void updatePressingButtons();
	void updateMenu();
	void updateWorm();
	void updateBlockSides(SandBlock* block, std::vector<std::vector<int>> map, int heightMap, int widthMap, int i, int j);
	void updateBlocks();
	void updateBlockDestruction();
	void updateFall();
	void update();

	void renderMenu(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderBackground(sf::RenderTarget& target);
	void renderYouWonTitle(sf::RenderTarget& target);
	void renderWorm(sf::RenderTarget& target);
	void renderBlocks(sf::RenderTarget& target);
	void render();

	//Utils
	bool checkValidValue(int aLimit, int bLimit, int value);
};

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Block
{
public:
	float sh, sw;
	int r, g, b;
	sf::RectangleShape rect;

	void Init(float x, float y) {
		sh = y;
		sw = x;

		sf::Color color = sf::Color(int(sh), 0, 60);

		rect.setSize(sf::Vector2f(sw, sh));
		rect.setFillColor(color);
	}

	void setPos(float x, float y) {
		rect.setPosition(sf::Vector2f(x, y));
	}

	sf::RectangleShape getRect() {
		return rect;
	}
};


void renderBlocks(Block *barray, float bx, int nb, int scrH, sf::RenderWindow &window) {

	for (int i = 0; i < nb; i++) {
		barray[i].setPos(bx * i, scrH - barray[i].sh);
		window.draw(barray[i].getRect());
	}
}

void randthelist(Block *barray, int nBlocks) {
	int p1 = rand() % (nBlocks - 1) + 1;
	int p2 = rand() % (nBlocks - 1) + 1;

	Block b1 = barray[p1];
	Block b2 = barray[p2];

	barray[p2] = b1;
	barray[p1] = b2;
}

void iterate(Block *barray, int nBlocks) {
	for (int i = 1; i < nBlocks; i++) {
		if (barray[i - 1].sh > barray[i].sh) {
			Block temp = barray[i];
			barray[i] = barray[i - 1];
			barray[i - 1] = temp;


		}
	}
}

void reiterate(Block *barray, int nBlocks) {
	for (int i = 1; i < nBlocks; i++) {
		if (barray[i - 1].sh < barray[i].sh) {
			Block temp = barray[i - 1];
			barray[i - 1] = barray[i];
			barray[i] = temp;
		}
	}
}

int main()
{
	//const int sortedint = 100;

	// Render Window
	int screenH = 1000;
	int screenW = 1000;
	sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Bubble sort", sf::Style::Close);

	const int nBlocks = 500;
	float nBlockSpacing = (screenW / nBlocks);
	Block aBlocks[nBlocks];
	for (int i = 0; i < nBlocks; i++) {
		aBlocks[i].Init(nBlockSpacing, i * int(screenH / nBlocks));
	}

	bool runUp = false;
	bool runDown = false;

	// Sound --
	//sf::SoundBuffer buffer;
	//if (!buffer.loadFromFile("clack.wav")) {
	//	return -1;
	//}
	//sf::Sound sound;
	//sound.setBuffer(buffer);

	// window
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		// DRAW
		window.clear(sf::Color::White);

		renderBlocks(aBlocks, nBlockSpacing, nBlocks, screenH, window); // +1

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			randthelist(aBlocks, nBlocks);
			//sound.setPitch(3.f);
			//sound.play();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			for (int i = 0; i < nBlocks; i++) {
				aBlocks[i].Init(nBlockSpacing, rand() % 999 + 1); // +1
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			for (int i = 0; i < nBlocks; i++) {
				aBlocks[i].Init(nBlockSpacing, i * int(screenH / nBlocks));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			iterate(aBlocks, nBlocks);
			//sound.setPitch(1.f);
			//sound.play();
			runUp = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			reiterate(aBlocks, nBlocks);
			//sound.setPitch(2.f);
			//sound.play();
			runDown = false;
		}


		window.display(); // end the current frame

	}

	return 0;
}
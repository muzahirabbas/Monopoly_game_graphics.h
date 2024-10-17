#include <stdlib.h>
#include<time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <sfml/Window.hpp>
#include <sfml/main.hpp>
#include <sfml/System.hpp>
#include <iostream>
#include <sstream>
#include <string>
#pragma comment(lib, "winmm.lib")
using namespace std;
using namespace sf;
View full;
View game;
class playerC;
float winx = GetSystemMetrics(SM_CXSCREEN);
float winy = GetSystemMetrics(SM_CYSCREEN);
float midx = GetSystemMetrics(SM_CXSCREEN) / 2;
float midy = GetSystemMetrics(SM_CYSCREEN) / 2;
class baseGame;
Font font1;
Font font2;
Event event;
Clock cloick;
static RenderWindow window;
template <typename T>
std::string toString(T value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
Color ColorN(int x){
	switch (x){
	case 1:
		return Color::Blue;
	case 2:
		return Color::Green;
	case 3:
		return Color::Yellow;
	case 4:
		return Color::Red;
	case 5:
		return Color::White;
	case 6:
		return Color::Black;
	default:
		return Color::Black;
	}
}
void startWindow(){
	ContextSettings setting;
	setting = window.getSettings();
	window.create(sf::VideoMode(winx, winy), "window", Style::Fullscreen, setting);
	window.setVerticalSyncEnabled(true);
	full.setCenter(midx, midy);
	full.setSize(winx,winy);
	game.setCenter((3 * (midx / 1.8)) / 2, midy - (midy / 10.5));
	game.setSize(3*(midx/1.7),winy-(midy/10.5));
}
void bankrupt(int x)
{
	Font fontB;
	fontB.loadFromFile("resources/Days.otf");
	Text t,t1;
	t.setFont(fontB);
	t.setCharacterSize(50);
	t.setPosition(midx-(midx/2),midy);
	t.setColor(Color::White);
	t.setString("Player #"+toString(x));
	t1.setFont(fontB);
	t1.setCharacterSize(50);
	t1.setPosition(midx - (midx / 2), midy+(midy/2));
	t1.setColor(Color::White);
	t1.setString("Player bankrupted(lost)\nGame over\n");
	window.clear();
	window.setView(full);
	window.draw(t);
	window.draw(t1);
	window.display();
	Sleep(200);
}
class baseGame{
public:
	Image pturnI[4];
	Texture pturnT[4];
	Sprite pturn[4];
	Text pass;
	Text C, C2;
	int ix0019;
	int ix;
	int iy1427;
	int iy;
	int turn;
	int lk;
	baseGame();
};
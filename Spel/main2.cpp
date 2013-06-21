/*
Let There Be Light
Copyright (C) 2012 Eric Laukien

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#include <LTBL\Constructs.h>
#include <LTBL/Light/LightSystem.h>
#include <LTBL/Light/Light_Point.h>
#include <LTBL/Utils.h>



#include <assert.h>

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>
using namespace std;

string convertInt(int number)
{
	stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}

int main2(int argc, char* args[])
{ 



	sf::VideoMode vidMode;
	vidMode.width = 1300;
	vidMode.height = 1000;
	vidMode.bitsPerPixel = 32;
	//assert(vidMode.isValid());

	sf::RenderWindow win;
	win.create(vidMode, "Let there be Light - Demo");
	win.setFramerateLimit(50);

	sf::View view;
	sf::Vector2u windowSize(win.getSize());
	view.setSize(sf::Vector2f(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)));
	view.setCenter(view.getSize() / 2.0f);

	// ---------------------- Background Image ---------------------

	sf::Texture backgroundImage;

	assert(backgroundImage.loadFromFile("data/background.png"));

	// Tiling background
	backgroundImage.setRepeated(true);

	sf::Sprite backgroundSprite(backgroundImage);
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, vidMode.width * 2, vidMode.height * 2));
	backgroundSprite.setPosition(-400.0f, -400.0f);

	// --------------------- Light System Setup ---------------------

	ltbl::LightSystem ls(AABB(Vec2f(0.0f, 0.0f), Vec2f(static_cast<float>(vidMode.width), static_cast<float>(vidMode.height))), &win, "data/lightFin.png", "data/shaders/lightAttenuationShader.frag");
	// Create a light
	ltbl::Light_Point* testLight = new ltbl::Light_Point();
	testLight->m_intensity = 0.9f;
	testLight->m_center = Vec2f(200.0f, 200.0f);
	testLight->m_radius = 200.0f;
	testLight->m_size = 30.0f;
	testLight->m_spreadAngle = ltbl::pifTimes2/8;
	testLight->m_softSpreadAngle = 0.0f;
	testLight->CalculateAABB();
	testLight->TreeUpdate();

	testLight->m_bleed = 0.4f;
	testLight->m_linearizeFactor = 1.1f;

	ls.AddLight(testLight);


	testLight->SetAlwaysUpdate(false);

	// Create a light
	ltbl::Light_Point* testLight2 = new ltbl::Light_Point();
	testLight2->m_center = Vec2f(200.0f, 1000.0f);
	testLight2->m_radius = 2000.0f;
	testLight2->m_size = 300.0f;
	testLight2->m_intensity = 2.0f;
	testLight2->m_spreadAngle = ltbl::pifTimes2;
	testLight2->m_softSpreadAngle = 1.0f;
	testLight2->CalculateAABB();

	//testLight2->m_bleed = 0.0f;
	//testLight2->m_linearizeFactor = 0.1f;
	ls.AddLight(testLight2);

	//testLight2->SetAlwaysUpdate(true);

	// Create an emissive light
	ltbl::EmissiveLight* emissiveLight = new ltbl::EmissiveLight();

	sf::Texture text;

	if(!text.loadFromFile("data/emissive.png"))
		abort();

	emissiveLight->SetTexture(&text);

	emissiveLight->SetRotation(45.0f);

	emissiveLight->m_intensity = 1.1f;

	ls.AddEmissiveLight(emissiveLight);

	emissiveLight->SetCenter(Vec2f(500.0f, 500.0f));

	// Create a hull by loading it from a file
	ltbl::ConvexHull* testHull = new ltbl::ConvexHull();

	if(!testHull->LoadShape("data/testShape.txt"))
		abort();

	// Pre-calculate certain aspects
	
	testHull->CalculateAABB();
	testHull->CalculateNormals();
	testHull->SetWorldCenter(Vec2f(300.0f, 300.0f));


	testHull->m_renderLightOverHull = false;

	ls.AddConvexHull(testHull);

	// ------------------------- Game Loop --------------------------

	sf::Event eventStructure;

	bool quit = false;

	ls.m_useBloom = true;


	int fps=0;
	sf::Text tekst;
	sf::Font font;
	font.loadFromFile("data/Font.ttf");
	tekst.setFont(font);


	int x=0.0f;

	while(!quit)
	{
		while(win.pollEvent(eventStructure))
			if(eventStructure.type == sf::Event::Closed)
			{
				quit = true;
				break;
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				view.move(sf::Vector2f(-1.0f, 0.0f));
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				view.move(sf::Vector2f(1.0f, 0.0f));

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				view.move(sf::Vector2f(0.0f, -1.0f));
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				view.move(sf::Vector2f(0.0f, 1.0f));

			sf::Vector2i mousePos = sf::Mouse::getPosition(win);
			//testLight2->IncCenter(ltbl::Vec2f(0.1f, 0.0f));
			// Update light
			testLight->SetCenter(Vec2f(static_cast<float>(mousePos.x), static_cast<float>(vidMode.height) - static_cast<float>(mousePos.y)));
			//testLight3->SetCenter(Vec2f(static_cast<float>(mousePos.x), static_cast<float>(vidMode.height) - static_cast<float>(mousePos.y)+50));
			testHull->SetWorldCenter(Vec2f(x,200.0f));
			x++;
			win.clear();

			win.setView(view);
			ls.SetView(view);

			// Draw the background
			win.draw(backgroundSprite);


			// Calculate the lights
			ls.RenderLights();

			// Draw the lights
			ls.RenderLightTexture();

			//ls.DebugRender();


			fps++;
			tekst.setString(convertInt(fps));
			win.draw(tekst);

			win.display();
	}

	win.close();
}
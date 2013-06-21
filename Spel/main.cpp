#include <SFML/Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Network.hpp>

#include <iostream>
#include "DTextBox.h"
#include "DButton.h"
#include "DPanel.h"
#include "DComponent.h"




void bla(){
	std::cout<<"1234";
}
void main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Limit the framerate to 60 frames per second (this step is optional)
	window.setFramerateLimit(60);
	// The main loop - ends as soon as the window is closed
	sf::Style::Resize;
	DButton *serverButton = new DButton(100,20,180,30,sf::String("Server"));
	DButton *clientButton = new DButton(300,20,180,30,sf::String("Client"));
	DPanel *panel = new DPanel(100,100,550,500);

	panel->addComponent(serverButton);
	panel->addComponent(clientButton);
	clientButton->setMouseUpFunc(bla);


	

	while (window.isOpen())
	{
		// Event processing
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed){
				panel->mouseDown(event.mouseButton.button,event.mouseButton.x,event.mouseButton.y);
			}
			if (event.type == sf::Event::MouseButtonReleased){
				panel->mouseUp(event.mouseButton.button,event.mouseButton.x,event.mouseButton.y);
			}
			if (event.type == sf::Event::MouseMoved){
				panel->mouseMove(event.mouseMove.x,event.mouseMove.y);
			}

			if (event.type == sf::Event::KeyPressed){
				panel->keyDown(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased){
				panel->keyUp(event.key.code);
			}

			if (event.type == sf::Event::TextEntered){
				panel->textEntered(event.text.unicode);
			}
		}
		// Clear the whole window before rendering a new frame
		window.clear();
		// Draw some graphical entities
		panel->draw(window);

		// End the current frame and display its contents on screen
		window.display();
	}

}
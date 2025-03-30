#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "misc.hpp"
#include <iostream>
#include "GameTexture.hpp"
#include "TextureHandler.hpp"

#define XORIGIN 200/2
#define YORIGIN 200/2

int main()
{
    vector<string> fileNames = { "Banana", "Center", "Left", "Right" };
    TextureHandler::getInstance().LoadFiles(fileNames);



    GameObject banana("Banana");
    banana.SetSprite("Banana");
    Player plr("Center");
    unordered_map<char, int> keymap;

    
    sf::RenderWindow window(sf::VideoMode({ 1690,900 }), "SFML works!");
    sf::Vector2u windowSize = window.getSize();

   
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
             
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            keymap['A'] = 1;
        }
        else
        {
            keymap['A'] = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            keymap['D'] = 1;
        }
        else
        {
            keymap['D'] = 0;
        }
        
        if (keymap['D'] == 1 && keymap['A'] == 1)
        {
            plr.CenterOut();
        }
        if (keymap['D'] == 1 && keymap['A'] == 0)
        {
            plr.TurnRight();
        }
        if (keymap['A'] == 1 && keymap['D'] == 0)
        {
            plr.TurnLeft();
        }
        if (keymap['A'] == 0 && keymap['D'] == 0)
        {
            plr.CenterOut();
        }

        
        
       
        window.clear();
        
        window.draw(banana.GetSprite());
        banana.MoveObject(0.05);
        window.draw(plr.GetSprite());
        window.display();
    }
}
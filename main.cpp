#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "misc.hpp"
#include <iostream>
#include "GameTexture.hpp"
#include "TextureHandler.hpp"




int main()
{
    vector<string> fileNames = { "Banana", "Center", "Left", "Right", "Sky", "Ground", "Road", "Sun", "Boulder", "Car", "CarJump", "CarBoost", "CarJumpBoost"};
    TextureHandler::getInstance().LoadFiles(fileNames);



    GameObject sky("Sky");
    GameObject ground("Ground");
    GameObject road("Road");
    GameObject sun("Sun");
    GameObject boulder("Boulder");
    ground.SetSprite("Ground");
    road.SetSprite("Road");
    sun.SetSprite("Sun");
    boulder.SetSprite("Boulder");
    sky.SetSprite("Sky");
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
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            keymap['W'] = 1;
        }
        else
        {
            keymap['W'] = 0;
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
        if (keymap['W'] == 1)
        {
            plr.SpeedUp();
        }
        if (keymap['W'] == 0)
        {
            plr.SlowDown();
        }

        
        
       
        window.clear();
        window.draw(sky.GetSprite());
        window.draw(ground.GetSprite());
        window.draw(road.GetSprite());
        window.draw(sun.GetSprite());
        window.draw(plr.GetSprite());
        window.draw(boulder.GetSprite());
        boulder.MoveObject(plr.FetchData().GetSpeed());
        window.display();
    }
}
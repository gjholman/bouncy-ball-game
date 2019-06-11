//
//  main.cpp
//  BouncyBall
//  Created by Garrett Holman on 5/31/19.
//  Copyright © 2019 Garrett Holman. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.cpp"
#include "global_vars.h"

unsigned int gWindowHeight = 1024;
unsigned int gWindowWidth = 1024;
unsigned int fps = 60;

int main(int argc, const char *argv[]) {

    // Local objects
    Ball myBall = Ball();

    sf::RenderWindow window(sf::VideoMode(gWindowWidth, gWindowHeight),
                      "Bouncy Ball");
    
    window.setFramerateLimit(fps);
    
    bool readyForInput = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }
        
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            readyForInput = true;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && readyForInput) {
            myBall.bounce();
            readyForInput = false;
        }

        window.clear();

        // draw objects
        window.draw(myBall.getBall());

        window.display();
        
        myBall.update();
    }

    std::cout << "End of game" << "\n";

    return EXIT_SUCCESS;
}

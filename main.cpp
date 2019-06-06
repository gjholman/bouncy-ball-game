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

// sf::Color green = sf::Color(100, 250, 50);

void draw() {
  // Draw each object
}

void update() {
  // update position of ball, calling the ball.update() method
}

int main(int argc, const char *argv[]) {

    // Local objects
//    sf::CircleShape ball(50.0f);
//    ball.setOrigin(50.f, 50.f);
//    ball.setFillColor(green);
    Ball myBall = Ball();

    sf::RenderWindow window(sf::VideoMode(gWindowWidth, gWindowHeight),
                      "Bouncy Ball");
    
    window.setFramerateLimit(fps);

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

        window.clear();

        // draw objects
        window.draw(myBall.getBall());

        window.display();
        
        myBall.update();
    }

    std::cout << "End of game"
        << "\n";

    return EXIT_SUCCESS;
}

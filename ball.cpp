//
//  ball.cpp
//  BouncyBall
//
//  Created by Garrett Holman on 5/31/19.
//  Copyright © 2019 Garrett Holman. All rights reserved.
//

#include "ball.hpp"
#include "global_vars.h"
#include <SFML/Graphics.hpp>

#define DOWN_ACCEL 0.005f
#define RADIUS 50.f

// sf::Color green = sf::Color(100, 250, 50);

class Ball {
private:
    float dx, dy;
    sf::CircleShape ball;
    float rightBound = (float)gWindowWidth - RADIUS;
    float leftBound = RADIUS;
    float lowerBound = gWindowHeight - RADIUS;
    float upperBound = RADIUS;

public:
    Ball() {
        this->dx = 0.25f;
        this->ball = sf::CircleShape(50.f);
        this->ball.setFillColor(sf::Color(100, 250, 50));
        this->ball.setOrigin(ball.getRadius(), ball.getRadius()); // set origin to center of ball
        this->ball.setPosition(gWindowWidth / 2, gWindowHeight / 2);
    }
//    float getX() { return this->x; }
//    float getY() { return this->y; }
    sf::CircleShape getBall() { return this->ball; }
    void update() {
        // update position
        this->ball.move(dx, dy);
        sf::Vector2f position = this->ball.getPosition();
        if (position.x < leftBound) {
            this->ball.setPosition(leftBound, position.y);
            dx = dx * (-1.f);
        }
        else if(position.x > rightBound) {
            this->ball.setPosition(rightBound, position.y);
            dx = dx * (-1.f);
        }
        if (position.y < upperBound) {
            this->ball.setPosition(position.x, upperBound);
            dy = dy * (-1.f);
        }
        else if (position.y > lowerBound) {
            this->ball.setPosition(position.x, lowerBound);
            dy = dy * (-1.f);

        }
        
        dy += DOWN_ACCEL;
        
    }
};

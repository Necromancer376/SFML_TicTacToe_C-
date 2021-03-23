//
//  main.cpp
//  GUI_tictactoe
//
//  Created by Malhar Dharmadhikari on 12/03/21.
//  Copyright © 2021 Malhar Dharmadhikari. All rights reserved.
//

#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <SFML/System.hpp>

bool turn = false;
int playerInput[3][3];
int isWin = false;
bool isStart = true;


void Grid(sf::RenderWindow &window)
{
    sf::RectangleShape gridLine;
    for(int i=1; i<3; i++)
    {
        gridLine.setSize(sf::Vector2f(2.f, 300.f));
        gridLine.setPosition(i*100.f, 0.f);
        
        window.draw(gridLine);
        
        gridLine.setSize(sf::Vector2f(300.f, 2.f));
        gridLine.setPosition(0.f, i*100.f);
        
        window.draw(gridLine);
    }
}


struct point
{
    int x, y;
};

point* getMouseClick(sf::RenderWindow &window)
{
    point* mousepos = new point;
    
    while(true)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            int x = sf::Mouse::getPosition(window).x;
            int y = sf::Mouse::getPosition(window).y;
            
            int divx = x / 100;
            int divy = y / 100;
            
            mousepos->x = divx;
            mousepos->y = divy;
            
            break;
        }
    }
    return mousepos;
}




bool inset(point* p, bool turn)
{
    if(playerInput[p->x][p->y] == 0)
    {
        playerInput[p->x][p->y] = turn ? 1 : 2;

        return true;
    }
    
    return false;
}

void drawGrid(sf::RenderWindow &window)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(playerInput[i][j] == 1)
            {
                sf::CircleShape circle(30.f);
                circle.setFillColor(sf::Color::Black);
                circle.setPosition(i*100 + 20, j*100 + 20);
            
                circle.setOutlineThickness(10);
                circle.setOutlineColor(sf::Color::White);
                
                window.draw(circle);
            }
            else if(playerInput[i][j] == 2)
            {
                sf::RectangleShape cross;
                cross.setSize(sf::Vector2f(80.f, 8.f));
                cross.setRotation(-45.f);
                cross.setOrigin(40.f, 4.f);
                cross.setPosition((i*100  + 50), (j*100 + 50));
                
                window.draw(cross);
                
                cross.setSize(sf::Vector2f(80.f, 8.f));
                cross.setRotation(-135.f);
                cross.setOrigin(40.f, 4.f);
                cross.setPosition((i*100 + 50), (j*100 + 50));
                
                window.draw(cross);
            }
        }
    }
}


int winCheck()
{
    if(playerInput[0][0] == playerInput[0][1] == playerInput[0][2] && playerInput[0][0] != 0 && playerInput[0][1] != 0 && playerInput[0][2] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    else if(playerInput[1][0] == playerInput[1][1] == playerInput[1][2] && playerInput[1][0] != 0 && playerInput[1][1] != 0 && playerInput[1][2] != 0)
    {
        isWin = true;
        return playerInput[1][0];
    }
    else if(playerInput[2][0] == playerInput[2][1] == playerInput[2][2] && playerInput[2][0] != 0 && playerInput[2][1] != 0 && playerInput[2][2] != 0)
    {
        isWin = true;
        return playerInput[2][0];
    }
    else if(playerInput[0][0] == playerInput[1][0] == playerInput[2][0] && playerInput[0][0] != 0 && playerInput[1][0] != 0 && playerInput[2][0] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    else if(playerInput[0][1] == playerInput[1][1] == playerInput[2][1] && playerInput[0][1] != 0 && playerInput[1][1] != 0 && playerInput[2][1] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    else if(playerInput[0][2] == playerInput[1][2] == playerInput[2][2] && playerInput[0][2] != 0 && playerInput[1][2] != 0 && playerInput[2][2] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    else if(playerInput[0][0] == playerInput[1][1] == playerInput[2][2] && playerInput[0][0] != 0 && playerInput[1][1] != 0 && playerInput[2][2] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    else if(playerInput[0][2] == playerInput[1][1] == playerInput[2][0] && playerInput[0][2] != 0 && playerInput[1][1] != 0 && playerInput[2][0] != 0)
    {
        isWin = true;
        return playerInput[0][0];
    }
    
    return 0;
}


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(300, 400), "TicTacToe");
    window.setKeyRepeatEnabled(false);
    
    sf::Font font;
//    if(!font.loadFromFile("TimesRoman.ttf"))
//    {
//        std::cout << "Error Loading File" << std::endl;
//        system("pause");
//    }
    sf::Text startText;
    startText.setFont(font);
    startText.setString("START");
    startText.setCharacterSize(100);
    startText.setFillColor(sf::Color::White);
    startText.setStyle(sf::Text::Bold);
    startText.setPosition(120, 130);
    
    
    while(window.isOpen())
    {
        sf::Event sfEvent;
        while(window.pollEvent(sfEvent))
        {
            if(sfEvent.type == sf::Event::Closed)
                window.close();
        }
        
        sf::RectangleShape border;
        border.setSize(sf::Vector2f(300.f, 2.f));
        border.setPosition(0.f, 300.f);
        
        int winner = winCheck();
        
        if(isWin == false)
        {
            if(isStart)
            {
                point* p = getMouseClick(window);
                if(p != nullptr)
                {
                    if(inset(p, turn))
                        turn = !turn;
                }
                window.clear();
                window.display();
            
                Grid(window);
                drawGrid(window);
            
                window.display();
            }
//            else
//            {
//                sf::RectangleShape startButton;
//                startButton.setSize(sf::Vector2f(70.f, 50.f));
//                startButton.setPosition(115, 125);
//                startButton.setFillColor(sf::Color::Black);
//                startButton.setOutlineColor(sf::Color::White);
//                startButton.setOutlineThickness(2.f);
//
//                window.clear();
//                window.draw(startButton);
//    //            window.draw(startText);
//                window.display();
//
//                if(sf::Event::MouseButtonPressed && sf::Event::MouseEntered)
//                {
//                    int mousex = sf::Mouse::getPosition(window).x;
//                    int mousey = sf::Mouse::getPosition(window).y;
//
//                    if(mousex >= 115 && mousex <= 185 && mousey >= 125 && mousey <= 175)
//                    {
//                        window.clear();
//                        window.display();
//                        isStart = true;
//                        continue;
//                    }
//                }
//            }
        }
        else
        {
            if(winner == 1)
            {
                sf::RectangleShape crosswin;
                crosswin.setSize(sf::Vector2f(80.f, 8.f));
                crosswin.setRotation(-45.f);
                crosswin.setOrigin(40.f, 4.f);
                crosswin.setPosition(120.f, 320.f);
                
                window.draw(crosswin);
                
                crosswin.setSize(sf::Vector2f(80.f, 8.f));
                crosswin.setRotation(-135.f);
                crosswin.setOrigin(40.f, 4.f);
                crosswin.setPosition(120.f, 320.f);
                
                window.draw(crosswin);
            }
            else
            {
                sf::CircleShape circlewin(30.f);
                circlewin.setFillColor(sf::Color::Black);
                circlewin.setPosition(120.f, 320.f);
                
                circlewin.setOutlineThickness(10);
                circlewin.setOutlineColor(sf::Color::White);
                
                window.draw(circlewin);
            }
        }
    }
    
    return 0;
}

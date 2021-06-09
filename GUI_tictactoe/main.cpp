////
////  main.cpp
////  GUI_tictactoe
////
////  Created by Malhar Dharmadhikari on 12/03/21.
////  Copyright © 2021 Malhar Dharmadhikari. All rights reserved.
////

#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;


sf::RectangleShape grid[4];
int c = -1;

void Grid(RenderWindow &window)
{
    RectangleShape gridLineH;
    RectangleShape gridLineV;
    
    gridLineH.setFillColor(Color::Black);
    gridLineV.setFillColor(Color::Black);
    for(int i=1; i<3; i++)
    {
        gridLineH.setSize(Vector2f(2.f, 300.f));
        gridLineH.setPosition(i*100.f, 0.f);
        
//        window.draw(gridLineH);
        grid[++c] = gridLineH;
        
        gridLineV.setSize(Vector2f(300.f, 2.f));
        gridLineV.setPosition(0.f, i*100.f);
        
//        window.draw(gridLineV);
        grid[++c] = gridLineV;
    }
}


int main()
{
    // Variables
    RenderWindow window(VideoMode(300, 400), "Tic-Tac-Toe");
    Color background = Color::White;
    bool turn = false;
    bool isWin = false;
    int changed[9];
    float xBox = 0,yBox = 0;
    int winner = 0;
    int numTurns = 0;
    
    //Textures
    Texture crossTexture;
    crossTexture.loadFromFile("/Users/malhar/Documents/personal/code/C++/GUI_tictactoe/GUI_tictactoe/res/cross.png");
    Texture circleTexture;
    circleTexture.loadFromFile("/Users/malhar/Documents/personal/code/C++/GUI_tictactoe/GUI_tictactoe/res/circle.png");
    Font myFont;
    myFont.loadFromFile("/Users/malhar/Documents/personal/code/C++/GUI_tictactoe/GUI_tictactoe/res/TimesRoman.ttf");
    
    //Boxes
    RectangleShape boxes[9];
    for(int i=0; i<9; i++)
    {
        boxes[i].setSize(Vector2f(98, 98));
//        boxes[i].setTexture(&crossTexture);
        boxes[i].setPosition(xBox, yBox);
        
        xBox += 100;
        if(i == 2 || i == 5)
        {
            xBox = 0;
            yBox += 100;
        }
        changed[i] = -1;
    }

    // Win window
    Text winText;
    winText.setFont(myFont);
    winText.setFillColor(Color::Black);
    winText.setPosition(75, 310);
    winText.setCharacterSize(24);
    
    RectangleShape divLine;
    divLine.setSize(Vector2f(300.f, 2.f));
    divLine.setFillColor(Color::Black);
    divLine.setPosition(0, 300);
    
    RectangleShape playAgain;
    playAgain.setSize(Vector2f(100 , 35));
    playAgain.setFillColor(Color::White);
    playAgain.setOutlineColor(Color::Black);
    playAgain.setOutlineThickness(2.f);
    playAgain.setPosition(100, 350);
    
    Text resetText;
    resetText.setFont(myFont);
    resetText.setFillColor(Color::Black);
    resetText.setCharacterSize(22);
    resetText.setPosition(120, 350);
    resetText.setString("Reset");
    
    
    window.clear(background);
    Grid(window);
    
    //Gameloop
    while(window.isOpen())
    {
        Event sfEvent;
        while(window.pollEvent(sfEvent))
        {
            if(sfEvent.type == Event::Closed)
                window.close();
        }
        
        Vector2i mousePos = Mouse::getPosition(window);
        
        // Input System
        if(!isWin)
        {
            if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 100 && mousePos.y < 100)
            {
                if(changed[0] == -1)
                {
                    if(turn)
                    {
                        boxes[0].setTexture(&crossTexture);
                        changed[0] = 1;
                    }
                    else
                    {
                        boxes[0].setTexture(&circleTexture);
                        changed[0] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 200 && mousePos.y < 100)
            {
                if(changed[1] == -1)
                {
                    if(turn)
                    {
                        boxes[1].setTexture(&crossTexture);
                        changed[1] = 1;
                    }
                    else
                    {
                        boxes[1].setTexture(&circleTexture);
                        changed[1] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 300 && mousePos.y < 100)
            {
                if(changed[2] == -1)
                {
                    if(turn)
                    {
                        boxes[2].setTexture(&crossTexture);
                        changed[2] = 1;
                    }
                    else
                    {
                        boxes[2].setTexture(&circleTexture);
                        changed[2] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 100 && mousePos.y < 200)
            {
                if(changed[3] == -1)
                {
                    if(turn)
                    {
                        boxes[3].setTexture(&crossTexture);
                        changed[3] = 1;
                    }
                    else
                    {
                        boxes[3].setTexture(&circleTexture);
                        changed[3] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 200 && mousePos.y < 200)
            {
                if(changed[4] == -1)
                {
                    if(turn)
                    {
                        boxes[4].setTexture(&crossTexture);
                        changed[4] = 1;
                    }
                    else
                    {
                        boxes[4].setTexture(&circleTexture);
                        changed[4] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 300 && mousePos.y < 200)
            {
                if(changed[5] == -1)
                {
                    if(turn)
                    {
                        boxes[5].setTexture(&crossTexture);
                        changed[5] = 1;
                    }
                    else
                    {
                        boxes[5].setTexture(&circleTexture);
                        changed[5] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 100 && mousePos.y < 300)
            {
                if(changed[6] == -1)
                {
                    if(turn)
                    {
                        boxes[6].setTexture(&crossTexture);
                        changed[6] = 1;
                    }
                    else
                    {
                        boxes[6].setTexture(&circleTexture);
                        changed[6] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 200 && mousePos.y < 300)
            {
                if(changed[7] == -1)
                {
                    if(turn)
                    {
                        boxes[7].setTexture(&crossTexture);
                        changed[7] = 1;
                    }
                    else
                    {
                        boxes[7].setTexture(&circleTexture);
                        changed[7] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
            else if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x < 300 && mousePos.y < 300)
            {
                if(changed[8] == -1)
                {
                    if(turn)
                    {
                        boxes[8].setTexture(&crossTexture);
                        changed[8] = 1;
                    }
                    else
                    {
                        boxes[8].setTexture(&circleTexture);
                        changed[8] = 0;
                    }
                    
                    turn = !turn;
                    numTurns++;
                }
            }
        }
        if(Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 100 && mousePos.x < 200 && mousePos.y > 350 && mousePos.y < 385)
        {
            isWin = false;
            numTurns = 0;
            for(int i=0; i<9; i++)
            {
                changed[i] = -1;
                boxes[i].setTexture(NULL);
            }
            window.clear(background);
        }
        
        //Win Checker
        if((changed[0] == 0 && changed[1] == 0 && changed[2] == 0) || (changed[0] == 1 && changed[1] == 1 && changed[2] == 1))
        {
            winner = (changed[0] + 1);
            isWin = true;
        }
        else if((changed[3] == 0 && changed[4] == 0 && changed[5] == 0) || (changed[3] == 1 && changed[4] == 1 && changed[5] == 1))
        {
            winner = (changed[3] + 1);
            isWin = true;
        }
        else if((changed[6] == 0 && changed[7] == 0 && changed[8] == 0) || (changed[6] == 1 && changed[7] == 1 && changed[8] == 1))
        {
            winner = (changed[6] + 1);
            isWin = true;
        }
        else if((changed[0] == 0 && changed[3] == 0 && changed[6] == 0) || (changed[0] == 1 && changed[3] == 1 && changed[6] == 1))
        {
            winner = (changed[0] + 1);
            isWin = true;
        }
        else if((changed[1] == 0 && changed[4] == 0 && changed[7] == 0) || (changed[1] == 1 && changed[4] == 1 && changed[7] == 1))
        {
            winner = (changed[1] + 1);
            isWin = true;
        }
        else if((changed[2] == 0 && changed[5] == 0 && changed[8] == 0) || (changed[2] == 1 && changed[5] == 1 && changed[8] == 1))
        {
            winner = (changed[2] + 1);
            isWin = true;
        }
        else if((changed[0] == 0 && changed[4] == 0 && changed[8] == 0) || (changed[0] == 1 && changed[4] == 1 && changed[8] == 1))
        {
            winner = (changed[0] + 1);
            isWin = true;
        }
        else if((changed[2] == 0 && changed[4] == 0 && changed[6] == 0) || (changed[2] == 1 && changed[4] == 1 && changed[6] == 1))
        {
            winner = (changed[2] + 1);
            isWin = true;
        }
        
        std::cout << "1: " << numTurns << std::endl;
        if(isWin)
        {
            std::string temp = "Player ";
            if(winner == 1)
                temp += "1";
            else
                temp += "2";
            temp += " Wins";
            winText.setString(temp);
        }
        else if(numTurns == 9)
        {
            std::cout << "2: " << numTurns << std::endl;
            std::string temp = "Draw";
            winText.setString(temp);
        }
        
        // Render
        window.clear(background);
        
        for(int i=0; i<9; i++)
        {
            window.draw(boxes[i]);
        }
        for(int i=0; i<4; i++)
        {
            window.draw(grid[i]);
        }
        window.draw(playAgain);
        window.draw(resetText);
        window.draw(divLine);
        
        if(isWin)
        {
            window.draw(winText);
        }
        window.display();
    }
}

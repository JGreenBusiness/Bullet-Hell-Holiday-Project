#include "MenuState.h"

#include <iostream>

#include "Font.h"

MenuState::MenuState(Application2D* _app) : IGameState(_app)
{
    m_font = new aie::Font("./font/consolas.ttf", 32);

}

MenuState::~MenuState()
{
    delete m_font;
}

void MenuState::Load()
{
    std::cout << "Loading Menu" << std::endl;
}

void MenuState::UnLoad()
{
    std::cout << "Unloading Menu" << std::endl;
}

void MenuState::Update(float _dt)
{
    
}

void MenuState::Draw()
{
    m_2dRenderer->drawText(m_font,"Menu", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);
}

#include "GameOverState.h"

#include <iostream>

GameOverState::GameOverState(Application2D* _app)  : IGameState(_app)
{
    m_font = _app->GetFont();
}

GameOverState::~GameOverState()
{

}

void GameOverState::Load()
{
    std::cout << "Loading GameOver" << std::endl;
}

void GameOverState::UnLoad()
{
    std::cout << "Unloading GameOver" << std::endl;
}

void GameOverState::Update(float _dt)
{
    m_timer += _dt;

    if(m_timer > 3.0)
    {
        //m_timer = 0;
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PushState("Menu");
    }
}
void GameOverState::Draw()
{
    m_2dRenderer->drawText(m_font,"GameOver!", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);
}
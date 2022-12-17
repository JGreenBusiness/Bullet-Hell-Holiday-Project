#include "SplashState.h"

#include <iostream>

#include "Font.h"


SplashState::SplashState(Application2D* _app)  : IGameState(_app)
{
    m_font = _app->GetFont();
}

SplashState::~SplashState()
{

}

void SplashState::Load()
{
    std::cout << "Loading Splash" << std::endl;
}

void SplashState::UnLoad()
{
    std::cout << "Unloading Splash" << std::endl;
}

void SplashState::Update(float _dt)
{
    m_timer += _dt;

    if(m_timer > 3.0)
    {
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PushState("Menu");
    }
}
void SplashState::Draw()
{
    m_2dRenderer->drawText(m_font,"Splash!", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);
}
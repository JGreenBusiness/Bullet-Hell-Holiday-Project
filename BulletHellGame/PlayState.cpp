#include "PlayState.h"

#include <iostream>

#include "Input.h"

PlayState::PlayState(Application2D* _app)  : IGameState(_app)
{
    m_font = _app->GetFont();
}

PlayState::~PlayState()
{

}

void PlayState::Load()
{
    std::cout << "Loading Play" << std::endl;
}

void PlayState::UnLoad()
{
    std::cout << "Unloading Play" << std::endl;
}

void PlayState::Update(float _dt)
{
    m_timer += _dt;
    
    aie::Input* input = aie::Input::getInstance();

    if(input->wasKeyPressed(aie::INPUT_KEY_SPACE))
    {
        m_app->GetGameStateManager()->SetState("Play", nullptr);

        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PushState("GameOver");
    }

    if(input->wasKeyPressed(aie::INPUT_KEY_P) )
    {
        m_app->GetGameStateManager()->PushState("Pause");
    }
    
}
void PlayState::Draw()
{
    
    
    m_2dRenderer->drawText(m_font,"Play", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);

    int timer = m_timer;
    char timerChar[2 + sizeof(char)];
    std::sprintf(timerChar, "%d", timer);
    
    m_2dRenderer->drawText(m_font,timerChar, 20,20, 1);
}
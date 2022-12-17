#include "PauseState.h"

#include <iostream>

#include "Input.h"

PauseState::PauseState(Application2D* _app) : IGameState(_app)
{
    m_font = _app->GetFont();
}

PauseState::~PauseState()
{
}

void PauseState::Load()
{
    std::cout << "Loading Pause" << std::endl;
}

void PauseState::UnLoad()
{
    std::cout << "Unloading Pause" << std::endl;
}

void PauseState::Update(float _dt)
{
    aie::Input* input = aie::Input::getInstance();
    
    if(input->wasKeyPressed(aie::INPUT_KEY_P) )
    {
        m_app->GetGameStateManager()->PopState();
    }

    if(input->wasKeyPressed(aie::INPUT_KEY_SPACE))
    {
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->SetState("Play", nullptr);
        m_app->GetGameStateManager()->PushState("Menu");
    }
}

void PauseState::Draw()
{
    m_2dRenderer->drawText(m_font,"Paused", m_app->getWindowWidth()/2,m_app->getWindowHeight()/4, 1);
}
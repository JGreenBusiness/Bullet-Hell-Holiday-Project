#include "MenuState.h"

#include <iostream>

#include "Font.h"
#include "Input.h"
#include "PlayState.h"

MenuState::MenuState(Application2D* _app) : IGameState(_app)
{
    m_font = _app->GetFont();

    m_playButton = new Button(Vec2(m_app->getWindowWidth()/2,m_app->getWindowHeight()/2),40.0f,20.0f,m_app);
}

MenuState::~MenuState()
{
    delete m_playButton;
    m_playButton = nullptr;
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
    Vec2* mousePos = new Vec2(m_input->getMouseX(),m_input->getMouseY());
    m_playButton->Update(mousePos);
    delete mousePos;

    if(m_playButton->Clicked())
    {
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->SetState("Play", new PlayState(m_app));
        m_app->GetGameStateManager()->PushState("Play");
        m_playButton->SetClicked(false);
    }
}

void MenuState::Draw()
{
    m_playButton->Draw();
    m_2dRenderer->drawText(m_font,"Menu", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);
}

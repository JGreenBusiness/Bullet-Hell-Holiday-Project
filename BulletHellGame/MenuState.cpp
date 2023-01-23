#include "MenuState.h"

#include <iostream>

#include "Font.h"
#include "Input.h"
#include "PlayState.h"
#include "Text.h"

MenuState::MenuState(Application2D* _app) : IGameState(_app)
{
    m_font = _app->GetFont();
    m_playButton = new Button(Vec2(m_app->getWindowWidth()/2,m_app->getWindowHeight()/2),Vec2(m_app->getWindowWidth()/8,m_app->getWindowHeight()/14),
        0xa4dbe8ff,"Play",m_font,0x000000ff);

    m_quitButton = new Button(Vec2(m_app->getWindowWidth()/2,m_app->getWindowHeight()/4),Vec2(m_app->getWindowWidth()/8,m_app->getWindowHeight()/14),
        0xa4dbe8ff,"Quit",m_font,0x000000ff);

    m_titleText = new Text("Bullet Hell", Vec2(m_app->getWindowWidth()/2,m_app->getWindowHeight() - m_app->getWindowHeight()/8),m_font,0xffffffff);
    m_titleText->SetCenterAlign(true);
}

MenuState::~MenuState()
{
    delete m_playButton;
    m_playButton = nullptr;

    delete m_quitButton;
    m_quitButton = nullptr;

    delete m_titleText;
    m_titleText = nullptr;
}

void MenuState::Load()
{
    //std::cout << "Loading Menu" << std::endl;
}

void MenuState::UnLoad()
{
    //std::cout << "Unloading Menu" << std::endl;
}

void MenuState::Update(float _dt)
{
    Vec2 mousePos = Vec2(m_input->getMouseX(),m_input->getMouseY());
    m_playButton->Update(mousePos);
    m_quitButton->Update(mousePos);

    if(m_playButton->Clicked())
    {
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->SetState("Play", new PlayState(m_app));
        m_app->GetGameStateManager()->PushState("Play");
        m_playButton->SetClicked(false);
    }

    if(m_quitButton->Clicked())
    {
        m_app->quit();
    }



}

void MenuState::Draw()
{
    m_playButton->Draw(m_2dRenderer);
    m_quitButton->Draw(m_2dRenderer);
    m_titleText->Draw(m_2dRenderer);
}

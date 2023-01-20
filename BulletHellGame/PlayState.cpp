#include "PlayState.h"
#include "Vec2.h"
#include <iostream>

#include "Button.h"
#include "Input.h"
#include "Rect.h"

using MathLib::Vec2;
using MathLib::Rect
;

PlayState::PlayState(Application2D* _app)  : IGameState(_app)
{
    m_font = _app->GetFont();

    Vec2 pos = Vec2(m_app->getWindowWidth()/2,m_app->getWindowHeight()/2);
    m_player = new Ship(pos,Vec2(50.0f,50.0f),m_input);
    m_player->Sprite = new aie::Texture("./textures/ship.png");

}

PlayState::~PlayState()
{
    delete m_player;
    m_player = nullptr;
}

void PlayState::Load()
{
    std::cout << "Loading Play" << std::endl;
    m_player->Awake();
}

void PlayState::UnLoad()
{
    std::cout << "Unloading Play" << std::endl;
}

void PlayState::Update(float _dt)
{
    m_player->Update(_dt);
    
    m_timer += _dt;
    
    if(m_input->wasKeyPressed(aie::INPUT_KEY_SPACE))
    {
        m_app->GetGameStateManager()->SetState("Play", nullptr);

        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PushState("GameOver");
    }

    if(m_input->wasKeyPressed(aie::INPUT_KEY_P) )
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

    m_player->Draw(m_2dRenderer);
}
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
    // Vec2 pos = Vec2(300,-400 + m_app->getWindowHeight());
    // Vec2 size = Vec2(m_modifier,m_modifier);
    // Vec2 mousePos =  Vec2(m_input->getMouseX(),m_input->getMouseY());
    //
    // Button button = Button(pos,size,m_app);
    // button.Draw();
    // button.Update(mousePos);
    //
    // if(button.Clicked())
    // {
    //     std::cout << "Clicked" << std::endl;
    //     button.SetClicked(false);
    // }
    
    
    m_2dRenderer->drawText(m_font,"Play", m_app->getWindowWidth()/2,m_app->getWindowHeight()/2, 1);

    int timer = m_timer;
    char timerChar[2 + sizeof(char)];
    std::sprintf(timerChar, "%d", timer);
    
    m_2dRenderer->drawText(m_font,timerChar, 20,20, 1);
}
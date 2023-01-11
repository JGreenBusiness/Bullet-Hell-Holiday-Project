#pragma once

#include "Button.h"
#include "IGameState.h"

class MenuState : public IGameState
{
public:
    MenuState(Application2D* _app);

    ~MenuState() override;

    void Load() override;
    void UnLoad() override;

    void Update(float _dt) override;
    void Draw() override;

protected:
private:
    aie::Font* m_font;
    Button* m_playButton;
    Button* m_quitButton;
    Text* m_titleText;
};

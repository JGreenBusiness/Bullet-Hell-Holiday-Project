#pragma once
#include "IGameState.h"

class GameOverState : public IGameState
{
public:
    GameOverState(Application2D* _app);

    ~GameOverState() override;

    void Load() override;
    void UnLoad() override;

    void Update(float _dt) override;
    void Draw() override;

protected:
private:
    aie::Font* m_font;
    float m_timer = 0;

};

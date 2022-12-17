#pragma once
#include "IGameState.h"

class PauseState : public IGameState
{
public:
    PauseState(Application2D* _app);

    ~PauseState() override;

    void Load() override;
    void UnLoad() override;

    void Update(float _dt) override;
    void Draw() override;

protected:
private:
    aie::Font* m_font;

};

#pragma once
#include "Application2D.h"
#include "Renderer2D.h"

class Application2D;
class  IGameState
{
public:
    IGameState(Application2D* _app)
    {
        m_app = _app;
        m_2dRenderer = m_app->GetRenderer();
    }

    virtual ~IGameState() = default;

    virtual void Load(){}
    virtual void UnLoad(){}

    virtual void Update(float _dt){}
    virtual void Draw(){ }
    

    
    
    
protected:
    aie::Renderer2D*	m_2dRenderer;
    Application2D* m_app;
private:

    
    
};

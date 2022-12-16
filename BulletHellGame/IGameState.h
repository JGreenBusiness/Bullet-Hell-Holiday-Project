#pragma once

class  IGameState
{
public:
    IGameState() = default;
    virtual ~IGameState() = default;

    virtual void Load(){}
    virtual void UnLoad(){}

    virtual void Update(float _dt);
    virtual void Draw(){ }
    

    
    
    
protected:
private:
    
};

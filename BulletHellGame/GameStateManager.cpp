#include "GameStateManager.h"

#include "IGameState.h"

GameStateManager::GameStateManager()
{
    
}

GameStateManager::~GameStateManager()
{
    for(auto iter = m_states.begin(); iter != m_states.end(); iter++ )
    {
        if(iter->second != nullptr)
        {
            iter->second->UnLoad();
            delete iter->second;
        }
        
    }
    m_states.clear();
}

void GameStateManager::Update(float _deltaTime)
{
    // Invoke all recorded commands
    for(auto cmd : m_commands)
    {
        cmd();
    }
    m_commands.clear();

    m_stack.back()->Update(_deltaTime);
}

void GameStateManager::Draw()
{
    for(auto state : m_stack)
    {
        state->Draw();
    }
}

void GameStateManager::SetState(const char* _name, IGameState* _state)
{
    m_commands.push_back([=]()
    {
        if(m_states[_name] != nullptr)
        {
            m_states[_name]->UnLoad();
            delete m_states[_name];
        }
        
        m_states[_name] = _state;

        if(m_states[_name] != nullptr)
        {
            m_states[_name]->Load();
        }
    });
}

void GameStateManager::PushState(const char* _name)
{
    m_commands.push_back([=]()
    {
        m_stack.push_back(m_states[_name]);
    });
}

void GameStateManager::PopState()
{
    m_commands.push_back([=]()
    {
        m_stack.pop_back();
    });
}

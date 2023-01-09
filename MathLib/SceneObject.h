#pragma once

#include <functional>
#include <list>
#include <vector>

#include "Mat3.h"


class SceneObject
{
public:
    virtual ~SceneObject() = default;
    SceneObject();

    SceneObject* parent = nullptr;
    std::list<SceneObject*> children;
    MathLib::Mat3 transform;
    bool isAlive = true;

    SceneObject* GetParent();

    MathLib::Mat3 GetGlobalTransform();
    
    void Update();
    void Draw();
    virtual void OnUpdate();
    virtual void OnDraw();

    void ItemAdd(SceneObject* _child);
    
    void AddChild(SceneObject* _child);

    void ItemRemove(SceneObject* _child);
    
    void RemoveChild(SceneObject* _child);
    void SetParent(SceneObject* _parent);

protected:
    
private:

    // void Run(std::function<void()> _delegate)
    // {
    //     _delegate();
    // }

    // template <typename T>
    // std::vector<std::function<T>(void())> m_updateChildActions;

    
    
};

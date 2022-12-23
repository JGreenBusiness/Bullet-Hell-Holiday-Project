#pragma once

#include <functional>
#include <list>

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

    template <class T>
    void Update();
    void Draw();
    virtual void OnUpdate();
    virtual void OnDraw();

    void ItemAdd(SceneObject* _child);
    template <class T>
    void AddChild(SceneObject* _child);

    void ItemRemove(SceneObject* _child);
    template <class T>
    void RemoveChild(SceneObject* child);
    void SetParent(SceneObject* parent);

protected:
    
private:
    
    template <class ACTION_T>
    std::list<ACTION_T> m_updateChildActions;

    
    
};

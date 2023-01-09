#include "SceneObject.h"

SceneObject::SceneObject()
{
    
}

SceneObject* SceneObject::GetParent()
{
    return parent;
}

MathLib::Mat3 SceneObject::GetGlobalTransform()
{
     return parent == nullptr ? transform : MathLib::Mat3::Multiply(transform,parent->GetGlobalTransform());
}
void SceneObject::Update()
{
    // OnUpdate();
    //
    // if (isAlive == false)
    //     parent->RemoveChild(this);
    //
    // for(auto action : m_updateChildActions)
    // {
    //     action();
    // }
    // m_updateChildActions.clear();
    //
    // for(auto child : children)
    // {
    //     child->Update();
    // }
}

void SceneObject::Draw()
{
    // OnDraw();
    // for(auto child : children)
    // {
    //     child->Draw();
    // }
}

void SceneObject::OnUpdate()
{
}

void SceneObject::OnDraw()
{
}

void SceneObject::ItemAdd(SceneObject* _child)
{
    // if(_child->parent != nullptr)
    //     _child->parent->RemoveChild(_child);
    //
    // _child->parent = this;
    // children.push_back(_child);
}

void SceneObject::ItemRemove(SceneObject* _child)
{
    // if (_child->parent == this)
    // {
    //     _child->parent = nullptr;
    // }
}

void SceneObject::AddChild(SceneObject* _child)
{
    // m_updateChildActions.push_back(ItemAdd(_child));
}

void SceneObject::RemoveChild(SceneObject* _child)
{
}

void SceneObject::SetParent(SceneObject* _parent)
{
}

#pragma once

#include "Application.h"
#include "GameStateManager.h"
#include "Renderer2D.h"

class GameStateManager;

class Application2D : public aie::Application {
public:

	Application2D();
	~Application2D() override;

	bool startup() override;

	void shutdown() override;

	void update(float _deltaTime) override;
	void draw() override;

	GameStateManager* GetGameStateManager()	{return m_gameStateManager;}
	aie::Renderer2D* GetRenderer()	{return m_2dRenderer;}

protected:

private:
	void Awake();
	void Start();

	aie::Renderer2D*	m_2dRenderer;

	GameStateManager* m_gameStateManager;
};
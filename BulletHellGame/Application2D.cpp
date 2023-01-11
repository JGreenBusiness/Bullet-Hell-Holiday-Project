#include "Application2D.h"
#include "Font.h"
#include "GameOverState.h"
#include "Input.h"
#include "IGameState.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameStateManager.h"
#include "PauseState.h"
#include "PlayState.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}

bool Application2D::startup()
{
	Awake();
	Start();
	
	return true;
}

void Application2D::Awake()
{
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
}

void Application2D::Start()
{
	m_gameStateManager = new GameStateManager();

	m_gameStateManager->SetState("Splash", new SplashState(this));
	m_gameStateManager->SetState("Menu", new MenuState(this));
	m_gameStateManager->SetState("Pause", new PauseState(this));
	m_gameStateManager->SetState("GameOver", new GameOverState(this));

	m_gameStateManager->PushState("Splash");
	
}


void Application2D::shutdown()
{
	delete m_gameStateManager;
	delete m_font;
	delete m_2dRenderer;
	
}

void Application2D::update(float _deltaTime)
{

	m_gameStateManager->Update(_deltaTime);
}

void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_gameStateManager->Draw();
	
	m_2dRenderer->end();
}
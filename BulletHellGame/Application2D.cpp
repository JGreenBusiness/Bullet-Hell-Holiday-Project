#include "Application2D.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}

bool Application2D::startup()
{
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	return true;
}

void Application2D::shutdown()
{
	delete m_2dRenderer;
	delete m_font;

}

void Application2D::update(float deltaTime)
{

	
}

void Application2D::draw()
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawText(m_font,"Hello World!", getWindowWidth()/2,getWindowHeight()/2, 1);
	
	
	m_2dRenderer->end();
}
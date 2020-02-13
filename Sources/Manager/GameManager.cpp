#include <Manager/GameManager.h>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace baba_is_GUI
{
    GameManager* GameManager::GetInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new GameManager();

            const sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
            m_instance->m_windowWidth = videoMode.width / 2;
            m_instance->m_windowHeight = videoMode.height / 2;
        }

        return m_instance;
    }

    void GameManager::Start(sf::RenderWindow* window)
    {
        // Set the window
        m_window = window;
    }

    void GameManager::Finish()
    {
        RemoveBackground();
    }

    void GameManager::SetBackground(const char* imageFileName)
    {
        m_backgroundTexture.loadFromFile(std::string(IMAGES_DIR) + imageFileName);
        
        m_backgroundSprite.setTexture(m_backgroundTexture);
        m_backgroundSprite.setOrigin(0.0f, 0.0f);
        m_backgroundSprite.setPosition(0.0f, 0.0f);
        m_backgroundSprite.setScale(
            GetWindowWidth() / m_backgroundSprite.getLocalBounds().width,
            GetWindowHeight() / m_backgroundSprite.getLocalBounds().height);
    }

    void GameManager::RemoveBackground()
    {
        m_backgroundTexture.create(1, 1);

        m_backgroundSprite.setTexture(m_backgroundTexture);
    }

    void GameManager::ClearDrawList()
    {
        RemoveBackground();
    }

    bool GameManager::IsOpen() const
    {
        bool isOpened = m_window->isOpen();

        // Clear screen
        m_window->clear(sf::Color::White);

        return isOpened;
    }

    void GameManager::CloseWindow() const
    {
        m_window->close();
    }

    bool GameManager::HasWindowFocus() const
    {
        return m_window->hasFocus();
    }

    void GameManager::Draw()
    {
        // Draw the background
        m_window->draw(m_backgroundSprite);
    }

    void GameManager::DrawSprite(const GameObject* object)
    {
        if(object->GetActive())
            m_window->draw(object->GetSprite());
    }

    int GameManager::GetWindowWidth() const
    {
        return m_windowWidth;
    }

    int GameManager::GetWindowHeight() const
    {
        return m_windowHeight;
    }
    sf::Vector2i GameManager::GetMousePosition() const
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
        return mousePos;
    }
}
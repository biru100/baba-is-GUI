#ifndef BABA_IS_GUI_GAME_MANAGER_H
#define BABA_IS_GUI_GAME_MANAGER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <Manager/GameObject.hpp>

namespace baba_is_GUI
{
    class GameManager
    {
    public:
        GameManager(const GameManager& other) = delete;
        ~GameManager() = delete;

        static GameManager* GetInstance();

        //! Start the game.
        void Start(sf::RenderWindow* window);

        //! Finish the game.
        void Finish();

        //! Set the background.
        void SetBackground(const char* imageFileName);

        //! Remove the background.
        void RemoveBackground();

        //! Clear draw lists.
        void ClearDrawList();

        //! Returns the window is opened.
        bool IsOpen() const;

        //! Close the window.
        void CloseWindow() const;

        //! Returns the window has focus.
        bool HasWindowFocus() const;

        //! Draw everything.
        void Draw();

        void DrawSprite(const GameObject* object);

        //! Returns the width of the window.
        int GetWindowWidth() const;

        //! Returns the height of the window.
        int GetWindowHeight() const;

        sf::Vector2i GetMousePosition() const;

    private:
        GameManager() = default;

        static GameManager* m_instance;

        sf::RenderWindow* m_window;

        sf::Texture m_backgroundTexture;
        sf::Sprite m_backgroundSprite;

        GameObject* testObject;

        int m_windowWidth;
        int m_windowHeight;

    };
}

#endif

#include <Manager/GameObject.hpp>
#include <Manager/GameManager.h>

namespace baba_is_GUI
{
    GameObject::GameObject(std::string imageFileName)
    {
        SetTexture(imageFileName);
        SetPosition({ 10,10 });
        exist = false;
    }

    void GameObject::SetTexture(std::string imageFileName)
    {
        m_Texture.loadFromFile(std::string(IMAGES_DIR) + imageFileName);

        m_Sprite.setTexture(m_Texture);
        m_Sprite.setOrigin(0.0f, 0.0f);
        m_Sprite.setPosition(0.0f, 0.0f);
        m_Sprite.setScale(1.0f, 1.0f);
    }
    void GameObject::SetPosition(sf::Vector2i pos)
    {
        position = pos;
        float x = (float)pos.x;
        float y = (float)pos.y;
        m_Sprite.setPosition({ x, y });
    }
}
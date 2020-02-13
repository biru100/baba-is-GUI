#ifndef BABA_IS_GUI_GAMEOBJECT
#define BABA_IS_GUI_GAMEOBJECT

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace baba_is_GUI
{
	class GameObject
	{
	public:
		GameObject(std::string imageFileName);
	private:
		sf::Texture m_Texture;
		sf::Sprite m_Sprite;
		bool exist;
	public:
		void SetActive(bool chk) { exist = chk; }
		bool GetActive() const { return exist; } 
		sf::Vector2i position;
		sf::Sprite GetSprite() const { return m_Sprite; }
		void SetTexture(std::string imageFileName);
		void SetPosition(sf::Vector2i pos);
		sf::Vector2i GetPosition() const { return position; }
	};
}
#endif
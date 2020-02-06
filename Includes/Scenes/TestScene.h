#ifndef CMAKE_IMGUI_TEST_SCENE_H
#define CMAKE_IMGUI_TEST_SCENE_H

#include <Scenes/Scene.h>
#include <SFML/Graphics.hpp>
namespace CMake_OpenGL
{
	class TestScene : public Scene
	{
	public:
		TestScene() = default;
		~TestScene() = default;

		void Start() override;

		void Input() override;

		void Update() override;

		void Finish() override;

	private:
		bool IsValidLoginInfo() const;

		ImGuiWindowFlags m_flags = 0;
		ImGuiWindowFlags m_popupFlags = 0;

		bool m_isOpened = true;

		float m_positionX = 0.0f;
		float m_positionY = 0.0f;

		float m_width = 0.0f;
		float m_height = 0.0f;
	private:
		sf::Texture objectTexture;
		sf::Sprite object;
	};
}

#endif
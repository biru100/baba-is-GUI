#ifndef BABA_IS_GUI_TEST_SCENE_H
#define BABA_IS_GUI_TEST_SCENE_H

#include <Scenes/Scene.h>
#include <SFML/Graphics.hpp>
#include <Manager/GameObject.hpp>

#define MAX_OBJECT 10
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
namespace baba_is_GUI
{
	class TestScene : public Scene
	{
	public:
		TestScene() = default;
		~TestScene() = default;

		void Start() override;

		void Input() override;

		void Update() override;

		void Render() override;

		void Finish() override;

		void Brush();

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
		GameObject** object;
		int objectcnt = 0;
		int v[2];
		bool objectchk[MAP_WIDTH][MAP_HEIGHT];
	};
}

#endif
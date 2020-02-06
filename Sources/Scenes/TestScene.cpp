#include <Manager/GameManager.h>

#include <Scenes/TestScene.h>
#include <Utils/ImGuiUtils.h>

#include <regex>

namespace CMake_OpenGL
{
    void TestScene::Start()
    {
        GameManager::GetInstance()->SetBackground("object.png");

        m_flags |= ImGuiWindowFlags_NoResize;
        m_flags |= ImGuiWindowFlags_NoMove;
        m_flags |= ImGuiWindowFlags_NoCollapse;
        m_flags |= ImGuiWindowFlags_NoTitleBar;

        m_popupFlags |= ImGuiWindowFlags_AlwaysAutoResize;
        m_popupFlags |= ImGuiWindowFlags_NoTitleBar;

        m_width = GameManager::GetInstance()->GetWindowWidth() * 0.3f;
        m_height = GameManager::GetInstance()->GetWindowHeight() * 0.4f;

        m_positionX =
            GameManager::GetInstance()->GetWindowWidth() * 0.5f - m_width * 0.5f;
        m_positionY =
            GameManager::GetInstance()->GetWindowHeight() * 0.5f - m_height * 0.5f;
        objectTexture.loadFromFile("object.png");
        object.setTexture(objectTexture);
    }

    void TestScene::Input()
    {
        // Do nothing
    }

    void TestScene::Update()
    {
        GameManager::GetInstance()->DrawSprite(object);
    }

    void TestScene::Finish()
    {
        // Do nothing
    }
}
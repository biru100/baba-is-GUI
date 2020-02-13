#include <Manager/GameManager.h>

#include <Scenes/TitleScene.h>
#include <Utils/ImGuiUtils.h>

#include <regex>

namespace baba_is_GUI
{
    void TitleScene::Start()
    {
        GameManager::GetInstance()->SetBackground("BG.png");

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
    }

    void TitleScene::Input()
    {
        // Do nothing
    }

    void TitleScene::Update()
    {
        ImGui::Begin("Title");
        if (ImGui::Button("Test", ImVec2(300, 50)))
        {
            SceneManager::GetInstance()->ChangeScene("Test");
        }
        if (ImGui::Button("Exit", ImVec2(300, 50)))
        {
            GameManager::GetInstance()->CloseWindow();
        }
        ImGui::End();
    }

    void TitleScene::Render()
    {
        // Do nothing
    }

    void TitleScene::Finish()
    {
        // Do nothing
    }
}
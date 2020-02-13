#include <Manager/GameManager.h>

#include <Scenes/TestScene.h>
#include <Utils/ImGuiUtils.h>

#include <regex>

namespace baba_is_GUI
{
    void TestScene::Start()
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
        object = new GameObject*[MAX_OBJECT];
        for(int i = 0; i < MAX_OBJECT; i++)
            object[i] = new GameObject("baba.png");
        object[0]->SetActive(true);
        for (int i = 0; i < MAP_WIDTH; i++)
        {
            for (int j = 0; j < MAP_HEIGHT; j++)
                objectchk[i][j] = false;
        }
    }

    void TestScene::Input()
    {
        // Do nothing
    }

    void TestScene::Update()
    {
        Brush();
        sf::Vector2i temp = object[objectcnt]->GetPosition();
        v[0] = temp.x;
        v[1] = temp.y;
        ImGui::Begin("hello");
        ImGui::InputInt("object", &objectcnt);
        ImGui::InputInt2("helloworld", v);
        ImGui::End();
        if (objectcnt >= 0 && objectcnt < MAX_OBJECT)
            object[objectcnt]->SetPosition({ v[0],v[1] });
        else if (objectcnt >= 10)
            objectcnt = 9;
        else
            objectcnt = 0;
    }

    void TestScene::Render()
    {
        for(int i = 0;i < MAX_OBJECT; i++)
            GameManager::GetInstance()->DrawSprite(object[i]);
    }

    void TestScene::Finish()
    {
        
        // Do nothing
    }
    
    void TestScene::Brush()
    {
        sf::Vector2i temp = GameManager::GetInstance()->GetMousePosition();
        bool chk = true;
        int tempi = 0, tempj = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int tx = 300 + i * 24;
                int ty = 100 + j * 24;
                if (temp.x <= tx + 24 && temp.x >= tx &&
                    temp.y <= ty + 24 && temp.y >= ty)
                {
                    temp.x = tx;
                    temp.y = ty;
                    object[objectcnt]->SetPosition(temp);
                    chk = false;
                    tempi = i;
                    tempj = j;
                    i = 10;
                    break;
                }
            }
        }
        if(chk)
            object[objectcnt]->SetPosition({ -1090 , -1208 });
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (objectcnt < 9 && !objectchk[tempi][tempj])
            {
                objectchk[tempi][tempj] = true;
                object[++objectcnt]->SetActive(true);
            }
        }
    }
}
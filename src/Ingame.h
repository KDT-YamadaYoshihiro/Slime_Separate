#pragma once
#include "ObjectPool.h"
#include "ScreenBase.h"
#include "DrawImage.h"
#include "Case.h"
#include "Slime.h"
#include <vector>
#include <memory>

class InGame : public ScreenBase {

private:

    ObjectPool<Slime> m_pool;
    std::vector<std::shared_ptr<Slime>> m_slimes;

    std::shared_ptr<DrawImage> bg = nullptr;
    std::shared_ptr<CaseArea> m_leftArea = nullptr;
    std::shared_ptr<CaseArea> m_rightArea = nullptr;

    std::shared_ptr<Slime> m_draggedSlime = nullptr;

    int m_blueImage;
    int m_redImage;

    int m_spawnTimer;
    int m_spawnInterval;
    int m_maxSlime;

    int m_score; // åªç›ÇÃÉXÉRÉA

public:
    InGame();
    void Init() override;
    void Update() override;
    void Render() override;

private:
    void SpawnSlime();
    void CheckSort(std::shared_ptr<Slime> slime);
};

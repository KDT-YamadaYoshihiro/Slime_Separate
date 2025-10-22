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

    // �X���C���I�u�W�F�N�g�v�[��
    ObjectPool<Slime> m_pool;
    // �X���C���x�N�^�[
    std::vector<std::shared_ptr<Slime>> m_slimes;
    // �h���b�O���Ă���X���C��
    std::shared_ptr<Slime> m_dragged_slime = nullptr;

    // �w�i
    std::shared_ptr<DrawImage> bg = nullptr;
    // �P�[�X�G���A
    std::shared_ptr<CaseArea> m_left_area = nullptr;
    std::shared_ptr<CaseArea> m_right_area = nullptr;
    
    static const int repursue = 60;

    // �X���C���̉摜�n���h��
    int m_blue_image;
    // �ԃX���C���̉摜�n���h��
    int m_red_image;
    
    int elapsed_time;

    // �o�ߎ���
    int m_spawn_timer;
    // �X�|�[���Ԋu
    int m_spawn_interval;
    // �ő哯���o����
    int m_max_slime;
    // �����o����
    int m_spawn_slime;
    // ���݂̃X�R�A
    int m_score;

public:
    // ������
    InGame();
    // ������
    void Init() override;
    // �X�V
    void Update() override;
    // �`��
    void Render() override;

private:
    // �X���C���̃X�|�[��
    void SpawnSlime();

};

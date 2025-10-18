#pragma once
#include "ScreenBase.h"
#include "ObjectPool.h"
#include "Enemy.h"

class Ingame : public ScreenBase {

	// 2��ނ̃G�l�~�[
	std::shared_ptr<ObjectPool<Slime>> pool;

	// �c�莞��
	int frame;


public:
	Ingame();
	virtual ~Ingame() = default;
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;

	// �t���[���J�E���g�I��
	bool End();

};
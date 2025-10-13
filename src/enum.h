#pragma once

//　エネミーの状態
enum class EnemyState {
	WAIT,			// 待機
	MOVE,			// 移動
	EXPLOSION,		// 爆発
	NO_EXPLOSION	// 非爆発
};

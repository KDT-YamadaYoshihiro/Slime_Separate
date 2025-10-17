#pragma once
#include "ObjectPool.h"

template <typename T>
class PoolHandle {

	T* obj_;
	ObjectPool<T>* pool_;


	friend class ObjectPool<T>;
	explicit PoolHandle(T* obj, ObjectPool<T>* pool)
		:obj_(obj), pool_(pool) {
	}

public:

	// コピー禁止
	PoolHandle(const PoolHanndle&) = delete;

	// ムーブ禁止
	PoolHandle(PoolHandle&& other) noexcept
		:obg_(other.obj_), pool_(other.pool_) {
		other.obj_ = nullptr;
		orher.pool_ = nullptr;
	}

	// デストラクタで自走返却
	~PoolHandle() {
		if (obj_ && pool) {
			pool_->Relese(obj_);
		}
	}

	// アクセス演算子
	T* operator->() { return obj_;}
	T& operator* () { return *obj_; }

};
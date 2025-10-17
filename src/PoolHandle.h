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

	// �R�s�[�֎~
	PoolHandle(const PoolHanndle&) = delete;

	// ���[�u�֎~
	PoolHandle(PoolHandle&& other) noexcept
		:obg_(other.obj_), pool_(other.pool_) {
		other.obj_ = nullptr;
		orher.pool_ = nullptr;
	}

	// �f�X�g���N�^�Ŏ����ԋp
	~PoolHandle() {
		if (obj_ && pool) {
			pool_->Relese(obj_);
		}
	}

	// �A�N�Z�X���Z�q
	T* operator->() { return obj_;}
	T& operator* () { return *obj_; }

};
#pragma once
#include <vector>
#include <memory>
#include <stack>

template <typename T>
class ObjectPool {

    // 
    friend class PoolHandle<T>;

    // 
    std::vector<std::unique_ptr<T>> objects_;
    // 
    std::stack<T*> free_;

    void Release(T* obj) { free_.push(obj); }


public:
    explicit ObjectPool(size_t capacity) {
        objects_.reserve(capacity);
        for (size_t i = 0; i < capacity; ++i) {
            objects_.emplace_back(std::make_unique<T>());
            free_.push(objects_.back().get());
        }
    }

    // ������������������������
    // �v�[�������ӂꂽ���̏���
    // ����̓G���[��Ԃ��B
    // �v�[�����g������悤�ɕύX
    // ========================

    PoolHandle<T> Acquire() {

        // 
        if (free_.empty()){
            throw std::runtime_error("empty");
        }

        T* obj = free_.top();
        free_.pop();
        return PoolHandle<T>(obj, this);

        //if (free_.empty()) {
        //    // ��: 2�{�Ɋg��
        //    size_t addCount = std::max<size_t>(1, objects_.size());
        //    for (size_t i = 0; i < addCount; ++i) {
        //        objects_.emplace_back(std::make_unique<T>());
        //        free_.push(objects_.back().get());
        //    }
        //}

        //T* obj = free_.top();
        //free_.pop();
        //return PoolHandle<T>(obj, this);


    }

};

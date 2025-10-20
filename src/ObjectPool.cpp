//#include "ObjectPool.h"
//
//template <typename T>
//ObjectPool<T>::ObjectPool(size_t initialCount)
//{
//	for (size_t i = 0; i < initialCount; ++i) {
//		objects_.emplace_back(std::make_unique<T>());
//		free_.push(objects_.back().get());
//	}
//}
//
//template <typename T>
//T* ObjectPool<T>::Acquire()
//{
//	if (free_.empty()) {
//		size_t addCount = std::max<size_t>(1, objects_.size());
//		for (size_t i = 0; i < addCount; ++i) {
//			objects_.emplace_back(std::make_unique<T>());
//			free_.push(objects_.back().get());
//		}
//	}
//
//	T* obj = free_.top();
//	free_.pop();
//	return obj;
//}
//
//template <typename T>
//void ObjectPool<T>::Release(T* obj)
//{
//	free_.push(obj);
//}

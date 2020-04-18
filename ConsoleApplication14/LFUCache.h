#pragma once
#include "LibInclude.h"
class LFUCache {
public:
	LFUCache(int capacity) {
		capacity_ = capacity;
		size_ = 0;
		minF_ = 1;
	}

	int get(int key) {
		/* 不存在key */
		if (keyToVF_.find(key) == keyToVF_.end())    return -1;

		/* 将key从key的频率map中删除，然后加到freq+1的链表中 */
		fToList_[keyToVF_[key].second].erase(keyToIt_[key]);
		fToList_[++keyToVF_[key].second].push_back(key);
		keyToIt_[key] = --fToList_[keyToVF_[key].second].end();

		/* 更新最小频率 */
		if (fToList_[minF_].empty())
			++minF_;
		return keyToVF_[key].first;
	}

	void put(int key, int value) {
		if (capacity_ == 0)  return;
		/* 将频率加一，返回非-1表示存在key，重新设置value即可 */
		if (get(key) != -1)
		{
			keyToVF_[key].first = value;
			return;
		}
		if (size_ == capacity_)
		{
			/* 删除频率最小的链表头 */
			keyToVF_.erase(fToList_[minF_].front());
			keyToIt_.erase(fToList_[minF_].front());
			fToList_[minF_].pop_front();
			--size_;
		}
		/* 添加数据到频率为1的链表中 */
		keyToVF_[key] = std::make_pair(value, 1);
		fToList_[1].push_back(key);
		keyToIt_[key] = --fToList_[1].end();

		minF_ = 1;
		++size_;
	}
private:
	unordered_map<int, std::pair<int, int>> keyToVF_;
	unordered_map<int, list<int>::iterator> keyToIt_;
	unordered_map<int, list<int>> fToList_;
	int capacity_;
	int size_;
	int minF_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

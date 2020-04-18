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
		/* ������key */
		if (keyToVF_.find(key) == keyToVF_.end())    return -1;

		/* ��key��key��Ƶ��map��ɾ����Ȼ��ӵ�freq+1�������� */
		fToList_[keyToVF_[key].second].erase(keyToIt_[key]);
		fToList_[++keyToVF_[key].second].push_back(key);
		keyToIt_[key] = --fToList_[keyToVF_[key].second].end();

		/* ������СƵ�� */
		if (fToList_[minF_].empty())
			++minF_;
		return keyToVF_[key].first;
	}

	void put(int key, int value) {
		if (capacity_ == 0)  return;
		/* ��Ƶ�ʼ�һ�����ط�-1��ʾ����key����������value���� */
		if (get(key) != -1)
		{
			keyToVF_[key].first = value;
			return;
		}
		if (size_ == capacity_)
		{
			/* ɾ��Ƶ����С������ͷ */
			keyToVF_.erase(fToList_[minF_].front());
			keyToIt_.erase(fToList_[minF_].front());
			fToList_[minF_].pop_front();
			--size_;
		}
		/* ������ݵ�Ƶ��Ϊ1�������� */
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

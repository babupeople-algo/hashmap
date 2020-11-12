#pragma once

#include <iostream>
template <typename T>
struct node {
	T data;
	struct node* next;
};

template <typename T>
class hash_node {
public:
	hash_node() : head(nullptr), count(0)	{}
	void set_key(const int _key) { key = _key; }

	void insert_data(const T data)
	{
		// 처음 삽입된 데이터 예외처리
		if (head == nullptr)
		{
			head = new node<T>;
			head->next = nullptr;
			head->data = data;
			return;
		}
		// 새로운 노드 할당 및 데이터 저장
		node<T>* insert = new node<T>;
		insert->next = nullptr;
		insert->data = data;
		// 마지막 노드 탐색
		node<T>* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		// 마지막 노드 연결
		cur->next = insert;
		count++;
	}
	void print()
	{
		node<T>* temp = head;
		while (temp)
		{
			std::cout << temp->data << ",  ";
			temp = temp->next;
		}
		std::cout << std::endl;		
	}

	int get_key() const { return key; }
	int get_data_size() const { return count; }

private:
	
	int key;
	int count;
	node<T>* head;
};
template <typename T>
class hash_map {
public :
	hash_map(int _hash_size) : hash_size(_hash_size)
	{
		table = new hash_node<T>[hash_size];
		for (int i = 0; i < hash_size; i++)
		{
			table[i].set_key(i);			
		}
	}
	int get_key(int data)
	{
		int rtn = 0;
		rtn = data % hash_size;
		return rtn;
	}

	void insert(const T data)
	{
		int key = get_key(data);
		table[key].insert_data(data);
	}
	void print()
	{
		for (int i = 0; i < hash_size; i++)
		{
			std::cout << "hash key = " << i << "   ======================================" << std::endl;
			table[i].print();
			std::cout << "=====================================================" << std::endl<< std::endl;
		}
	}
	~hash_map()
	{

	}

private :
	int hash_size;		// 생성할 해쉬 개수
	int num_of_data;	// 저장되어있는 데이터 개수
	hash_node<T>* table;
};


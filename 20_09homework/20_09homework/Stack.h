#pragma once
template <typename T = int>
class Stack
{
public:
	Stack(const size_t& size, const size_t& step) :
		capacity{ size }, step{ step }, top{-1}
	
	{
		stack = new T[capacity];
	}
	void empty();// очищення	
	void push(const T & data); // нове значення
	void pop();//видалити
private:
	T* stack = nullptr;
	bool full() const;
	void resize();
	size_t capacity;
	size_t counter = 4;
	size_t step;
	int top_;

};

template<typename T>
inline void Stack<T>::empty()
{
	top_ = -1;
}

template<typename T>
inline void Stack<T>::push(const T& data)
{
	top_++;
	if (full()) {
		resize();
	}
	stack[top_] = data;
}

template<typename T>
inline void Stack<T>::pop()
{
	top_--;
}

template<typename T>
inline bool Stack<T>::full() const
{
	return top_  ==  capacity;
}

template<typename T>
inline void Stack<T>::resize()
{
	capacity += step * counter;
	T* tmp = new T[capacity + step];
	for (size_t i = 0; i < top_; i++)
	{
		tmp[i] = stack[i];
	}
	delete[] stack;
	staclk = tmp;
}

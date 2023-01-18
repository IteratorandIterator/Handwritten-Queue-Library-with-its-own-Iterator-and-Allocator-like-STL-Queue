
#include "queue.h"//自定义的queue类，开头引入头文件
#include<iostream>
#include<algorithm>//在自定义的queue类中加入了迭代器，可以调用算法
using namespace std;//里的一些基本函数对queue类对象做处理

bool greater10(float value);

int main()
{
	//题目要求实现功能（1）
	queue<int> Que; //生成一个空对列对象，包含头尾节点指针
	queue<int>::size_type size_ = Que.size();
	cout <<"题目要求实现功能（1）:生成一个空对列对象，包含头尾节点指针\n"
		<< "当前队列长度为：" << size_ << "\n\n";


	//题目要求实现功能（2）
	Que.push(10); Que.push(22); //在已知队列队尾插入元素
	Que.push(100); Que.push(1000);
	queue<int>::iterator ite_begin3 = Que.begin(), ite_end3 = Que.end();
	size_ = Que.size();
	cout << "题目要求实现功能（2）:在已知队列队尾插入元素\n";
	cout << "Que = ( ";
	for (queue<int>::iterator Ite = ite_begin3; Ite != ite_end3; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl<< "当前队列长度为：" << size_ << "\n\n"; 


	//题目要求实现功能（3）
	queue<int>::value_type value_;
	//依次将队列的首元素出队，再输出当前队列的长度
	cout << "题目要求实现功能（3）:依次将队列的首元素出队，再输出当前队列的长度\n";
	cout << "Que = ( ";
	for (queue<int>::iterator Ite = ite_begin3; Ite != ite_end3; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;
	while(size_ > 0) {
		value_ = Que.pop_value();
		size_ = Que.size();
		cout << "队首的值为：" << value_ << "\n当前队列长度为：" << size_ << "\n\n";
	}


	//题目要求实现功能（4）: 撤销队列，删除素有节点，仅留下节点指针
	Que.push(11); Que.push(999);
	ite_begin3 = Que.begin(); ite_end3 = Que.end();
	cout << "Que = ( ";
	for (queue<int>::iterator Ite = ite_begin3; Ite != ite_end3; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;
	size_ = Que.size();
	cout <<"题目要求实现功能（4）:撤销队列，删除素有节点，仅留下节点指针\n"
		<< "撤销前队列长度为：" << size_ << endl;
	Que.erase();
	size_ = Que.size();
	cout << "撤销后队列长度为：" << size_ << "\n\n";



	//新增加功能（1）：仅返回队头元素的引用和常引用但不删除节点
	queue<float> que_1, que_2;
	queue<float>::value_type _value;
	queue<float>::difference_type _size_;
	que_1.push(342.1); que_1.push(115.22); que_1.push(32.8); que_1.push(22);
	que_2.push(654.2); que_2.push(2434.1);
	queue<float>::iterator ite_begin = que_1.begin(), ite_end = que_1.end();
	queue<float>::iterator ite_begin2 = que_2.begin(), ite_end2 = que_2.end();
	_value = que_1.front();
	_value = que_1.const_front();
	_size_ = que_1.size();
	cout << "新增加功能（1）：仅返回队头元素的引用和常引用但不删除节点\n";
	cout << "que_1 = ( ";
	for (queue<float>::iterator Ite = ite_begin; Ite != ite_end; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl<< "队头元素为：" << _value << "\n" << "列队长度为：" << _size_ << "\n\n";

	//新增加功能（2）：仅返回队尾元素的引用和常引用但不删除节点
	_value = que_1.back();
	_value = que_1.const_back();
	_size_ = que_1.size();
	cout << "新增加功能（2）：仅返回队尾元素的引用和常引用但不删除节点\n";
	cout << "que_1 = ( ";
	for (queue<float>::iterator Ite = ite_begin; Ite != ite_end; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl << "队尾元素为：" << _value << "\n" << "列队长度为：" << _size_ << "\n\n";
    
	//新增加功能（3）：判断当前队列是否为空
	bool result;
	result = que_1.empty();
	cout << "新增加功能（3）：判断当前队列是否为空\n"
		<< "返回值为1表示为空，返回值为0表示不为空\n"
		<< "当前容器：" << result << "\n\n";

	//新增加功能（4）：重载运算符，比较当前对列大小（类似于字符串大小比较）
	cout << "新增加功能（4）：重载运算符，比较当前对列大小（类似于字符串大小比较）\n"
		<< "返回值为1表示正确，返回值为0表示错误\n";
	cout << "que_1 = ( ";
	for (queue<float>::iterator Ite = ite_begin; Ite != ite_end; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;
	cout << "que_2 = ( ";
	for (queue<float>::iterator Ite = ite_begin2; Ite != ite_end2; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;
	result = que_1 == que_2;
	cout << "que_1 == que_2 : " << result << endl;
	result = que_1 != que_2;
	cout << "que_1 != que_2 : " << result << endl;
	result = que_1 >= que_2;
	cout << "que_1 >= que_2 : " << result << endl;
	result = que_1 <= que_2;
	cout << "que_1 <= que_2 : " << result << endl;
	result = que_1 < que_2;
	cout << "que_1 < que_2 : " << result << endl;
	result = que_1 > que_2;
	cout << "que_1 > que_2 : " << result << "\n\n";

	//新增加功能（5）：添加了iterator迭代器，可以直接调用C++标准模板库的algorithm中的算法
	//对自己定义的queue类对象进行简单的处理
	auto is_even = [](int const elem) { return !(elem % 2); };
	cout << "新增加功能（5）：添加了iterator迭代器，可以直接调用C++标准模板库的algorithm中的算法\n\n";
	cout << "调用算法algorithm里面的any_of函数，查找queue类对象里的奇数\n";
	cout << "que_1 = ( ";
	for (queue<float>::iterator Ite = ite_begin; Ite != ite_end; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;
	if (any_of(ite_begin, ite_end, is_even))
		cout<< "There's an even element in que_1.\n\n";
	else
		cout<< "There are no even elements in que_1.\n\n";

	cout << "调用算法algorithm里面的count_if函数，查找queue类对象里大于10的个数\n";
	cout << "que_1 = ( ";
	for (queue<float>::iterator Ite = ite_begin; Ite != ite_end; ++Ite)
		cout << *Ite << "  ";
	cout << ")" << endl;

		
	queue<float>::iterator::difference_type result1;
	result1 = count_if(que_1.begin(), que_1.end(), greater10);
	cout << "The number of elements in que_1 greater than 10 is: "
		<< result1 << "." << endl;

	return 0;
}

bool greater10(float value)
{
	return value > 10;
}
// 练习 7.1 使用2.6.1节练习定义的Sales_data类为1.6节的交易处理程序编写一个新版本
// 从一个文件（终端）中读取销售记录，生成每本书的销售报告，显示出售出册数、总销售额和平均售价;
// 输入格式：ISBN号 售出的册数 销售价格
// 输出格式：ISBN号 售出的册数 总销售额 销售平均价格

#include "pch.h"
#include <iostream>
#include <string>

class Sales_data
{
public:
	Sales_data() = default;
	~Sales_data() = default;
	Sales_data &set(std::string cin_isbn, int num, double price);
	void copy(const Sales_data &copy_item);
	Sales_data &combine(Sales_data &plus);
	const std::string get_isbn()const;
	const double get_avg_price()const;
	const int get_volume() const;
	const double get_amount() const;
	void print()const;

private:
	//isbn号
	std::string isbn;
	//平均价格
	double avg_price = 0.0;
	//售出册数
	int volume = 0;
	//售出总金额
	double amount = 0.0;
};

Sales_data &Sales_data::set(std::string cin_isbn, int num, double price)
{
	isbn = cin_isbn;
	volume = num;
	amount = (num*price);
	avg_price = amount / volume;
	return *this;
}

void Sales_data::copy(const Sales_data &copy_item)
{
	isbn = copy_item.get_isbn();
	avg_price = copy_item.get_avg_price();
	amount = copy_item.get_volume();
	volume = copy_item.get_volume();
}

Sales_data &Sales_data::combine(Sales_data &plus)
{
	volume += plus.volume;
	amount += plus.amount;
	avg_price = amount / volume;
	return *this;
}

const std::string Sales_data::get_isbn()const
{
	return isbn;
}

void Sales_data::print() const
{
	std::cout << isbn.c_str() << " " << volume << " " << amount << " " << avg_price << std::endl;
}

const double Sales_data::get_avg_price() const
{
	return avg_price;
}

const int Sales_data::get_volume() const
{
	return volume;
}

const double Sales_data::get_amount() const
{
	return amount;
}

bool read(std::istream &cin, Sales_data &data)
{
	std::string isbn;
	int num = 0;
	double price = 0.0;
	if (std::cin >> isbn >> num >> price)
	{
		data.set(isbn, num, price);
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Sales_data total;
	if(read(std::cin, total))
	{
		Sales_data trans;
		while (read(std::cin, trans))
		{
			if (total.get_isbn() == trans.get_isbn())
			{
				total.combine(trans);
			}
			else
			{
				total.print();
				total.copy(trans);
			}
		}
		total.print();
	}
	else
	{
		std::cout << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}

// the_largest_sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

const int sequence_num = 2;//需要求子段和的序列数量
const int maxn = 100010;//序列最大长度
const int min_num = -1e9;

void get_data(int** a, int* siz) {
    std::ifstream Data;
    int num;
    for (int i = 0; i < sequence_num; ++i) {
        std::string b = "sequence_DATA";
        b = b + char('1' + i);
        b = b + ".txt";
        Data.open(b);
        siz[i] = 0;
        while (Data >> num) {
            a[i][siz[i]++] = num;
        }
        Data.close();
    }
}
void get_largest_sum(int* a, int siz) {
    int now = 0, mx = min_num, now_head = 0, head = 0, tail = 0;
    for (int i = 0; i < siz; ++i) {
        now += a[i];
        if (now > mx) { 
            mx = now; 
            tail = i; 
            head = now_head; 
        }
        if (now < 0){
            now = 0; 
            now_head = i + 1;
        }
    }
    std::cout << "最大子段和为 " << mx << std::endl;
    std::cout << "构成最大子段和的区间的头id为 " << head << std::endl;
    std::cout << "构成最大子段和的区间的尾id为 " << tail << std::endl;
}
int main()
{
    std::cout << "Hello World!\n";
    
    //new存放序列及序列长度的数组
    int** a = new int* [sequence_num];
    for (int i = 0; i < sequence_num; ++i) {
        a[i] = new int[maxn];
    }
    int* siz = new int [sequence_num];
    
    //从文件读入数据
    get_data(a,siz);

    //求最大子段和
    std::cout << "对第一组数据求最大子段和：" << std::endl;
    get_largest_sum(a[0], siz[0]);
    std::cout << "对第二组数据求最大子段和：" << std::endl;
    get_largest_sum(a[1], siz[1]);

    //delete动态空间
    for (int i = 0; i < sequence_num; ++i)delete[]a[i];
    delete[] a;
    delete[]siz;
    return 0;
}

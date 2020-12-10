#include <iostream>
#include "avl.h"
#include <vector>
#include <ctime> // для функции time()
#include <cstdlib> // для функций rand() и srand()
#include <chrono>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <string>
using namespace std;



class AVL{
private:
    int points;
    float *avl_timewr;
    float *avl_timeer;
    
    void arrs(){
        avl_timewr = new float[points];
        avl_timeer = new float[points];
        for (int i = 0; i < points; i++) avl_timewr[i] = 0;
        for (int i = 0; i < points; i++) avl_timeer[i] = 0;
    }
    
public:
    void set_points() {
        std::cout << "число точек" << std::endl;
        std::cin >> points;
        arrs();
    }
    
    void count(){
        std::vector<int> tmp;
        for(int j = 0; j < 1000; j++) {
            node *q;
            q = MakeTree();
            for (int i = 0; i < points; i++) {
                int k = 0;
                k= rand() % 1000;
                tmp.push_back(k);
                auto start = std::chrono::high_resolution_clock::now();
                
                if(i == 0) q->key = tmp.back();
                else q = insert(q, tmp.back());
                
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> durwrite = end - start;
                avl_timewr[i] += durwrite.count() / 1000;
            } 
                
            for (int i = points-1; i > 0; i--) { 
                    auto start1 = std::chrono::high_resolution_clock::now();
                    q = remove(q, tmp.back());
                    auto end1 = std::chrono::high_resolution_clock::now();
                    tmp.pop_back();
                    std::chrono::duration<float> durerase = end1 - start1;
                    avl_timeer[i] += durerase.count() / 999;
            }
            delete[] q;
            }
    }
    
    void write(){
        std::ofstream fout;
        fout.open("write.csv");
        if(!fout.is_open()) std::cout<<"ошибка открытия";

        for (int i = 0; i < points; i++) {
            fout << i <<'\t'<< avl_timewr[i] <<std::endl;
        }

        std::ofstream fouter;
        fouter.open("erase.csv");
        if(!fouter.is_open()) std::cout<<"ошибка открытия";

        for (int i = 0; i < points-1; i++) {
            fouter << i <<'\t'<< avl_timeer[i] <<std::endl;
        }
                
        delete [] avl_timewr;
        delete [] avl_timeer;
    }
    
};


int main(){
    setlocale(LC_ALL, "ru");
    srand(time(0)); // устанавливаем значение системных часов в качестве стартового числа

    AVL avl;
    avl.set_points();
    avl.count();
    avl.write();
    
    system("python graph.py");    
    return 0;
}

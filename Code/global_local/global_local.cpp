//
// Created by weichuandong on 2023/12/2.
//
#include <iostream>
#include "test.cpp"
#include "hh.cpp"

int k1 = 1;
int k2;
static int k3 = 2;
static int k4;

//extern int global;

int main() {
    static int m1 = 2;
    int i = 1;
    char *p;
    char str[10] = "hello";
    char *q = "hello";
    p = (char *) malloc(100);
    static int m2 = 3;
    free(p);
    printf("ջȡ-������ַ     i: %p\n", &i);
    printf("                p��%p\n", &p);
    printf("              str��%p\n", str);
    printf("                q��%p\n", &q);
    printf("������ַ-��̬���룺  %p\n", p);
    printf("ȫ���ⲿ�г�ֵ k1��  %p\n", &k1);
    printf("    �ⲿ�޳�ֵ k2�� %p\n", &k2);
    printf("��̬�ⲿ�г�ֵ k3��  %p\n", &k3);
    printf("    �⾲�޳�ֵ k4�� %p\n", &k4);
    printf("  �ھ�̬�г�ֵ m1�� %p\n", &m1);
    printf("  �ھ�̬�޳�ֵ m2�� %p\n", &m2);
    printf("���ֳ�����ַ    ��  %p, %s\n", q, q);
    printf("��������ַ      ��  %p\n", &main);

    std::cout << global << std::endl;
    add();
    std::cout << global;
    return 0;
}
//
//  wave.cpp
//  TunderClass
//
//  Created by Amy Zhou on 2020/5/3.
//  Copyright © 2020 Amy Zhou. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include "sound.h"
#define pi 3.14159
using namespace std;
#define L1  262    //将"L1"宏定义为低音"1"的频率262Hz 时间是1/262=3826/2 us  取半周期
#define L2  286    //将"L2"宏定义为低音"2"的频率286Hz
#define L3  311    //将"L3"宏定义为低音"3"的频率311Hz
#define L4  349    //将"L4"宏定义为低音"4"的频率349Hz
#define L5  392    //将"L5"宏定义为低音"5"的频率392Hz
#define L6  440    //将"l_a"宏定义为低音"6"的频率440Hz
#define L7  494    //将"L7"宏定义为低音"7"的频率494Hz
//以下是C调中音的音频宏定义
#define Z1    523     //将"Z1"宏定义为中音"1"的频率523Hz
#define Z2    587     //将"Z2"宏定义为中音"2"的频率587Hz
#define Z3  659     //将"Z3"宏定义为中音"3"的频率659Hz
#define Z4    698     //将"Z4"宏定义为中音"4"的频率698Hz
#define Z5    784     //将"Z5"宏定义为中音"5"的频率784Hz
#define Z6    880     //将"Z6"宏定义为中音"6"的频率880Hz
#define Z7    987     //将"Z7"宏定义为中音"7"的频率523H
//以下是C调高音的音频宏定义
#define H1  1046    //将"H1"宏定义为高音"1"的频率1046Hz
#define H2  1174    //将"H2"宏定义为高音"2"的频率1174Hz
#define H3  1318    //将"H3"宏定义为高音"3"的频率1318Hz
#define H4  1396    //将"H4"宏定义为高音"4"的频率1396Hz
#define H5  1567    //将"H5"宏定义为高音"5"的频率1567Hz
#define H6  1760    //将"H6"宏定义为高音"6"的频率1760Hz
#define H7  1975    //将"H7"宏定义为高音"7"的频率1975Hz
char clamp(int n){
    if (n > 255) {
        n = 255;
    } else if (n < 0) {
        n = 0;
    }
    return n;
}
vector<char> chord(float c){
    // 10 k
    int samplefrequency = 10000;
    float frequency = c;
    char volume = 50;
    char sampleLength = int(samplefrequency/4);
    float r = 2.0 * pi * frequency/samplefrequency;
    vector<char> data;
    int i = 0;
    while(i<sampleLength){
        char v = 128 + int(volume * sin(i * r));
        data.push_back(v);
        i += 1;
    }
    return data;
}
int toFcm(){
    vector<float> song={Z6,Z7,H1,Z7,H1,H3,Z7,Z3,Z3,
                Z6,Z5,Z6,H1,Z5,Z3,Z3,Z4,Z3,Z4,H1,
                Z3,H1,H1,H1,Z7,Z4,Z4,Z7,Z7,Z6,Z7,
                H1,Z7,H1,H3,Z7,Z3,Z3,Z6,Z5,Z6,H1,
                Z5,Z3,Z4,H1,Z7,H1,H2,H2,H2,H1,H1,Z6,
                Z7,Z5,Z6,H1,H2,H3,H2,H3,H5,H2,Z5,Z5,
                H1,Z7,H1,H3,H3,Z6,H1,Z7,H2,H1,Z5,Z5,
                H4,H3,H2,H1,H3,Z3,H3,H6,H5,H5,
                H3,H2,H1,H1,H2,H1,H2,H5,H3,H3,
                H6,H5,H3,H2,H1,H1,H2,H1,H2,Z7,Z6,Z6,Z7,Z6};
    vector<char> ds;
    int i = 0;
    while(i<song.size()){
        float c = song[i];
        vector<char> d = chord(c);
        ds.insert(ds.end(),d.begin(),d.end());
        i += 1;
    }
    string filepath = "tiankongzhicheng.wav";
    ofstream fp(filepath, ofstream::binary);
    vector<char> * data;
    data = &ds;
    fp.write(data,ds.size());
    fp.close();
    return 0;
}
int main(){
    toFcm();
    return 0;
}

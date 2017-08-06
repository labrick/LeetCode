## 目录说明

| 题目          | 说明  |
| :------------ | :-----------------            |
| [第04题](/004.Median-Of-Two-Sorted-Arrays)    | 这一题利用了归并排序中的归并思想 |
| [第10题](/010.Regular-Expression-Matching)    | 这道题有点难，一时半时还解不出来 |
| [第11题](/011.Container-With-Most-Water)      | 暴力破解很容易，但不实用，需要证明第二种方法 |
| [第12题](/012.Integer-To-Roman)               | 阿拉伯数字向罗数字的转换，支持1~3999999 |
| [第13题](/013.Roman-To-Integer)               | 支持1~3999999的罗马数字转换为阿拉伯数字 |
| [第14题](/014.Longest-Common-Prefix)          | 这一题比较简单，两个比较O(n)，复杂度也较低 |
| [第15题](/015.3Sum)                           | 采用搜索并去重效率太低，需要另寻他法 |
| [第16题](/015.3Sum-Closest)                   | 直接暴力破解，\>O(N^2)要看target的值为多少 |
| [第17题](/015.Letter-Combinations-of-a-Phone-Number) | 硬性编写，应该没有什么其他更好的方法了吧 |


## 注意

### ubuntu g++默认支持c++ 11

在`~/.bashrc`中加入：

    alias g++='g++ -std=c++11'

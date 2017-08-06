直接暴力破解，两个循环寻找三个数，一个循环遍历Cloest数，公式如下：

```
target + (int)pow(-1, (count-1)) * count / 2
```

**注意：**pow的原型为：double pow(double, double);

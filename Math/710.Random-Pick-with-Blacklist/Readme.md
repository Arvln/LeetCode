# 710.Random-Pick-with-Blacklist

最無腦就是將黑名單外的數存起來再從中隨機取數，會耗費較大空間。可以思考如何從剩餘數字中取數又能避免取到黑名單內的數字。以數字7為例，在[0:3]的區間內隨機取數可能會取到黑名單內的數字，當取到黑名單內的數字能不能將該數映射到後面其他有效的數字？比如將2映射到4、3映射到6。

```
0 1 [2] [3] ｜ 4 [5] 6

Map[2]=4;
Map[3]=6;
```

在這個思路下，把所有數字以有效數字個數做為分界。小於有效數字個數的黑名單數字映射到大於有效數字個數的有效數字。如此只要在0到有效數字個數內隨機取數就一定可以取到黑名單以外的數字。

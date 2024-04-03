# 191.Number-of-1-Bits.cpp

求二進制有幾個1，可以逐個刪除1，要消去最後一個1可以利用x&(x-1)，x-1可以將最後一個1置為0且最後一個1右側全置為1，因此x&(x-1)可去掉最後一個1。這種操作可以跟2次冪搭配使用，2次冪在二進制表示中僅有最左側一個1，因此x&(x-1)==0就可以判斷出數字是否為2次冪，同時因為將右側全置為1，也可以用來對2次冪做求模運算。
# 452.Minimum-Number-of-Arrows-to-Burst-Balloons

跟 #435 思路一樣，重疊的區間都可以被同一支箭射爆，實際要求最多可以有幾個不互相重疊的區間。可以對結束端點做排序，當多個區間重疊時優先選結束端點較早的區間，該區間對後續空間的擠壓會最小，因此後續可能可塞入更多不重疊區間。

```
------ (V)
  ----- (X)
   ----- (X)
         ------- (V)
            ------ (X)
                 ---- (X)
```

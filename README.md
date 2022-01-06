# 問題点

```sample.csv```の49行目の```Hong Kong China```は本来``` "Hong Kong,China" ```である。

しかし、```"Hong Kong,China" ```とすると正常に動作しない。

理由

カンマ(,)で区切られっている。

対策

ダブルコーテーション(" ")内で、カンマ( , )による区切りを無効にする。

問題のソースコード

```c
for(i=0;i<column_nuber;i++){
  char buf[256];
  fgets(buf,255,fp);
  sscanf(buf," %[^,],%[^,],%[^,],%s",name[i],gold[i],shilver[i],blonde[i]);
}
```

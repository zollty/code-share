题目要求读入不超过1000个英文单词，区分大小写，以空格或者回车隔开，以“#”标志读入结束。
然后在这些词里面，找出能够重新排列字符顺序成为一样的词，例如POST 和 STOP（区分大小写），
然后将他们互相抵消掉。最后输出所有不能通过此方法消掉的词。

样例输入

ladder came tape soon leader acme lone peat eye dealer NotE derail drIed
noel Disk mace
#

样例输出

Disk
NotE
derail
drIed
eye
ladder
soon

题目延伸1：改成不区分大小写，例如ScALE LaCeS

题目延伸2：不区分大小写，且类似于RIDE Rides的两个单词也要消去，因为Rides中包含了Ride


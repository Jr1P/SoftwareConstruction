# 日志

十点的时候在远程仓库加了README.md而本地仓库没加(在github网页看到提示要加README.md，就直接在网页那加了)，之后再次向远程仓库提交时出现了远程仓库拒绝更新等提示，如下图

![git](/home/jr1preg/Pictures/远程仓库拒绝更新.png)

**(不管干啥前先备份!)**一番摸索后输入下面命令后，再输入git push origin master命令就可以继续提交了，不加 --allow-unrelated-histories 会出现 fatal：无关联的历史啥的

> git pull git@github.com:ComputerScienceHIT/Lab1-1180800916.git master --allow-unrelated-histories

虽然可能不是正确的应对方法，不过至少看起来解决了问题，仅以此文记录


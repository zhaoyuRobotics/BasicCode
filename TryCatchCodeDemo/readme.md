# 编译:

每个cpp单独编译：   **g++ test.cpp -o a.exe**


# example1：

在try中发生的代码有异常时会直接进入catch()对应的数据类型中，运行完对应catch中的代码(当无对应类型时会进入catch(...)中)后接着运行 try,,,catch,,,后面的代码，不会造成闪退出现core dump，并且尽量在catch中打印出有帮助的日志

<div align=center>
<img src="https://github.com/zhaoyuRobotics/ZY_Study5/blob/master/image/example1.png" width="500" height="100"  align=center/>                                                                                                          
</div>

# example2：

1.throw发出异常信号，catch判断异常类型。

2.异常被抛出后从try块起，到运行throw前（发生异常），这期间在栈上构建的所有对象会自动调用析构函数（25行），如果是指针需要自行delete new出来的空间（26,28行）

<div align=center>
<img src="https://github.com/zhaoyuRobotics/ZY_Study5/blob/master/image/example2.png" width="500" height="100" align=center/>
</div>　　
　　
　　

**不能滥加Try-Catch机制，Try-Catch机制在一定程度上会损耗或影响性能，建议有以下几点准则:**　　

1.尽量给CLR一个明确的异常信息，不要使用Exception去过滤异常    

2.尽量不要将try…catch写在循环中    

3.try尽量少的代码，如果有必要可以使用多个catch块，并且将最有可能抛出的异常类型，书写在距离try最近的位置    



### 本实验是为了对比　Mutex　和　Atomic　的效率  
#### 测试条件:  启动100个线程，每个线程给全局变量 long total　和　结构体　total.a 和　total.b　增加１

<br>

#### long数据类型  
<br>
 atomic ：  
result:100000000  
duration:11528221ms  

<br>  

mutex ：  
result:100000000  
duration:71673838ms  

<br>  

不加锁： 
result:4864343  
duration:1794144ms



#### 自定义数据类型：
mutex锁  
result:100000000:100000000  
duration:72800874ms  

<br>  

原子锁  
result:1000000:1000000  
duration:6771689ms  

<br>

### 结果：　　原子锁　比　互斥锁效率高十倍左右

参考：  
原子锁：https://www.jianshu.com/p/8c1bb012d5f8  
效率对比：https://blog.csdn.net/yockie/article/details/8838686

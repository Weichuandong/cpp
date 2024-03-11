## 

### perf
#### 性能提升
to_excel占据了比较多的时间，并且是一个I/O操作。所以可以尝试多线程生成excel：

将dfs_to_excel函数放到线程中执行：最后执行时间增加，原因应该是由于python的全局解释器的存在，导致程序任何时刻只能有一个线程在运行，并且to_excel函数是同步I/O操作，
多线程生成每个sheet，然后再合并，但是执行时间更长。
可能的方案：

尝试异步I/O

	compare函数中，dataframe的循环操作替换为merge


将dfs_to_excel函数放到线程中执行测试
测试dfs_to_excel多线程生成每个sheet，然后再合并。

	脚本在包含log_path和compare_path的情况下需要解析两个文件，这两个其实没有关系，所以可以使用多进程进行同步解析。

尝试multiprocessing和concurrent.futures的ProcessPoolExecutor

	程序多进程方式编写 + 测试

 增加并行流程的注释
#### 数据统计方式更新
 tpi：pt1.13网络的信息，mm网络的信息，所有网络的汇总信息，各个网络的信息。

       其中，前三张表转换为excel表。后面的所有单个网络的信息都转换为txt文件并打包。

compare_tpi: pt1.13网络的信息对比，mm网络的信息对比，所有网络的汇总信息对比，各个网络的信息对比。

       同样，前三张表转换为excel表。后面的所有单个网络的对比信息都转换为txt文件并打包
1. pt1.13_operator_summary，mm_operator_summary表中，列名device时间占比 修改为 算子在所有网络中device总时长占比； 列名count数占比 修改为 算子在所有网络中count总个数占比
2. 百分数目前保存为字符串，在excel中无法直接求和，看能否保存为excel中能够直接求和的百分数形式

新增：

1. 算子在各网络中device时长占比总和： 计算算子在各个网络中的device时长占比，然后将这些占比求和；最后所有算子的此列如果求和应该等于网络数。

2. 算子在各网络中count数占比总和： 计算算子在各网络中count数占比，然后将这些占比求和；最后所有算子的此列如果求和应该等于网络数

## cnnl_unittest
#### 对proto的op_param里bytes、int64类型参数的支持
json_format.MessageToDict会将bytes给base64编码，和研发对json手填hex string的处理方式不同，需要给出适配案例

int64也会被当作str处理

要遍历树节点，检查类型做一些处理。

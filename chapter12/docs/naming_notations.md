# <a name="main"></a>my naming notations(based on Google)

**<font color=green>version:0.0.0.3.alpha</font>**

## <a name="FN"></a>file names

文件名全部小写，用下划线连接，按项目约定来，尽量让名字意义明确，标明文件后缀。
* my_useful_class.cc
* url_table.cc
* url_table.h
* url_table_inl.h(inline functions that include lots of code)

## <a name="TN"></a>type names

* 常规关键字 int、short等用stdint.h中的定义
    * uint8_t
    * uint16_t
    * uint32_t
* 单词全部小写，用下划线连接，类、结构体、typedef、枚举等结尾带_st，数组带_a
    * class utl_table_st{};
    * struct utl_table_properties_st_tab{}utl_table_properties_st;
    * typedef hash_map<utl_table_properties_st*,string> properties_map_st;
    * enum utl_table_errors_st{};
    * typedef char *cpString;  从右向左读,指针，char，一个指向char的指针
    * const cpString ckpP1 = nullptr;   指针，const，char，一个指向char的常量指针
    * const cpString *ckppP2;  指针，指针，const，char，一个指向（指向char的常量指针）的指针

## <a name="VN"></a>variable names

* 全部单词首字母大写，模块_作用域_类型+名字（帕斯卡）_st or _a or pst
    * 结构体等的内部数据命名——类型+名字（帕斯卡）
    * 枚举类型名_st，成员大写字母，下划线连接
    * 宏命名，大写，下划线连接
    ```
    a_uiArray_a:局部变量，数组，unsigned int
    g_ucVar1:全局变量，unsigned char
    g_ucpVar1:全局变量，指针
    g_StructureVar1_pst:全局变量，指针
    g_StructureVar1_st:全局变量，结构体
    ```
    * global variable：g
    * file static variable：ns
    * function static variable：fs
    * auto variable：**none**  自动变量或局部变量，一般位于函数内，
    * auto variable：**a**  自动推断类型
    * function agr variable:f
    * volatile：vt
    * const：k
    * constexpr：k
    * bit：bt
    * boolean：bl
    * char：c
    * int：i
    * short：s
    * long：l
    * unsigned：u
    * double：d
    * float：f
    * void：vd
    * pointer：p
    * enum：st
    * struct：st
    * union：st
    * class:st or cl
    * reference:r
    * decltype:dt
    * string:str or _cl
    * vector:vct or _cl
    * list:lst or _cl
    * forward_list:flst or _cl
    * deque:dqe or _cl
    * array:_a
    * container:?
    * function point：fp
    * array：后缀 _a
    * 自定义：后缀 _st _pst
    * 变量名：名词
    * 函数名：动词

## <a name="FN"></a>function names

* 帕斯卡命名法，不拘泥，可以名词也可以动词

## <a name="NN"></a>namespace names

* 全部小写，下划线连接，命名基于项目名称和目录结构
    * google_awesome_project

## <a name="EX"></a>exceptions

当命名与现有实体相似的对象时，可参考现有命名约定
* bigopen():参考open()
* uint:typedef 类型定义
* bigpos:struct或class，参考pos
* sparse_hash_map:STL相似实体，参考STL命名约定
* LONGLONG_MAX:类似INT_MAX
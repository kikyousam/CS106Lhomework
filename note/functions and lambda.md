# functions and lambda

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-40-38-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-41-02-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-41-26-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-42-20-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-42-57-image.png)

lambda函数相当于functor

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-07-49-23-image.png)

overaching type总体类型，用auto就好了啊，干嘛用std::function

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-16-03-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-17-24-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-17-49-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-18-35-image.png)

lexicographical comparisons 词法比较

如此多的C++ STL用处：

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-21-53-image.png)

任务：phonetic decoding 语音解码

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-22-30-image.png)

coalesce adjacent duplicates
合并相邻的重复项

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-26-02-image.png)

新的知识：range
![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-28-57-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-29-05-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-29-35-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-30-15-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-31-00-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-33-15-image.png)

views骚操作 能够复合算法，比CS61A中python中的复合函数高明很多。

太秀了!!!

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-39-41-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-39-53-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-40-20-image.png)

这些操作好像不能复合函数，在old STL中还是不错的写法，已经old了吗？

骚操作来了：

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-41-27-image.png)

更秀的：

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-41-47-image.png)

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-43-05-image.png)

在C++的范围库中，"range算法是急切的（eager）"和"views是惰性的（lazy）"体现了两种不同的求值策略。以下是它们的区别和含义：

---

### **1. Range算法是急切的（Eager）**

- **立即执行**：当调用`std::ranges`命名空间下的算法（如`sort`、`transform`、`copy`）时，操作会**立即生效**，直接处理整个数据集并生成结果。

- **修改数据或生成新数据**：这些算法可能直接修改原始数据（如`ranges::sort`）或将结果写入目标范围（如`ranges::transform`）。

- **示例**：
  
  ```cpp
  std::vector<int> data = {3, 1, 4, 1, 5};
  // 急切执行：立即对data排序
  std::ranges::sort(data);  // data变为{1, 1, 3, 4, 5}
  ```

---

### **2. Views是惰性的（Lazy）**

- **延迟执行**：视图（如`std::views::transform`、`std::views::filter`）不会立即执行操作，而是**定义一个转换规则**。实际计算推迟到遍历视图时进行。

- **无中间存储**：视图链（如`A | B | C`）会逐个元素处理，避免创建临时容器，节省内存。

- **依赖原始数据**：视图本身不存储数据，而是引用原始数据。若原始数据变化，遍历视图时会反映新值。

- **示例**：
  
  ```cpp
  std::vector<int> data = {1, 2, 3, 4};
  // 定义视图：不会立即执行操作
  auto view = data 
      | std::views::filter([](int x) { return x % 2 == 0; })  // 过滤偶数
      | std::views::transform([](int x) { return x * 2; });    // 乘以2
  
  // 修改原始数据
  data.push_back(5);  // data变为{1, 2, 3, 4, 5}
  
  // 遍历时才会执行过滤和转换
  for (int x : view) {
      // 输出：4（2*2）、8（4*2）、10（5*2，但5是奇数？这里可能需要再检查示例）
      // 修正：5是奇数，过滤后会被排除，实际输出4和8
      std::cout << x << " ";  
  }
  ```

---

### **关键区别**

| **特性**   | **Range算法（Eager）** | **Views（Lazy）**   |
| -------- | ------------------ | ----------------- |
| **执行时机** | 立即处理整个数据集          | 延迟到遍历时逐个元素处理      |
| **内存占用** | 可能生成中间或最终结果，占用更多内存 | 无中间存储，逐个处理，内存高效   |
| **数据依赖** | 操作完成后与原始数据无关       | 始终引用原始数据，随其变化更新结果 |
| **典型用途** | 需要立即得到结果的场景（如排序）   | 链式操作、流式处理大数据      |

---

### **何时使用哪种？**

- **Range算法**：当需要**立即生效的结果**（如排序、复制数据到新容器）。
- **Views**：当需要**组合多个操作**或处理**大数据流**（避免内存开销）。

通过理解这两种策略，可以更高效地利用C++范围库的特性，根据场景选择合适的工具。

![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-49-57-image.png)

是的，将 **C++ 的 `views`** 比作 **Python 的生成器（generators）** 是一种直观的类比，但两者在底层机制和用途上有相似之处，也有区别。我们通过对比来理解它们的关系：

---

### **1. Python 的生成器（Generators）**

#### **核心特性**

- **惰性求值（Lazy Evaluation）**：生成器不会一次性生成所有数据，而是**按需逐个生成元素**，节省内存。
- **通过 `yield` 定义**：生成器函数使用 `yield` 关键字返回一个值，并暂停执行，直到下一次请求。
- **状态保存**：每次生成器被调用时，会从上一次暂停的位置继续执行。
- **典型用途**：处理大型数据集（如逐行读取文件）、生成无限序列（如斐波那契数列）。

#### **示例**

```python
def simple_generator():
    for i in range(3):
        yield i * 2  # 每次生成一个值后暂停

gen = simple_generator()  # 创建生成器对象
for x in gen:
    print(x)  # 输出: 0 → 2 → 4（按需生成）
```

---

### **2. C++ 的 `views`**

#### **核心特性**

- **惰性求值**：`views` 不会立即操作整个数据集，而是**在遍历时逐个元素处理**。
- **通过管道符 `|` 组合**：可以将多个 `views`（如 `filter`、`transform`）串联成处理链。
- **无数据拷贝**：`views` 是对原始数据的“视图”，不存储数据本身，直接引用原始数据。
- **依赖原始数据**：如果原始数据被修改，遍历 `views` 时会反映最新状态。

#### **示例**

```cpp
#include <vector>
#include <ranges>

std::vector<int> data = {1, 2, 3, 4};
auto view = data 
    | std::views::filter([](int x) { return x % 2 == 0; })  // 过滤偶数
    | std::views::transform([](int x) { return x * 2; });   // 转换为偶数×2

// 遍历时才会执行操作
for (int x : view) {
    // 输出: 4（2×2）、8（4×2）
    std::cout << x << " ";
}
```

---

### **类比：`views` 和生成器的相似性**

| **特性**   | **Python 生成器**     | **C++ 的 `views`** |
| -------- | ------------------ | ----------------- |
| **惰性求值** | 按需生成单个元素           | 遍历时逐个处理元素         |
| **内存效率** | 避免一次性生成所有数据        | 无中间数据存储           |
| **可组合性** | 可通过嵌套生成器组合逻辑       | 通过 `              |
| **状态管理** | 保存执行状态（`yield` 暂停） | 保存对原始数据的引用        |

---

### **关键区别**

| **区别**   | **Python 生成器**        | **C++ 的 `views`**   |
| -------- | --------------------- | ------------------- |
| **数据源**  | 通常是生成数据的函数（如 `yield`） | 总是基于已有的数据范围（如容器、数组） |
| **修改影响** | 生成器独立生成数据，不受外部影响      | 视图依赖原始数据，数据变化会影响结果  |
| **无限序列** | 可直接表示（如无限斐波那契数列）      | 需要配合生成器或其他机制实现      |
| **实现机制** | 基于函数暂停/恢复（协程）         | 基于范围适配器和迭代器抽象       |

---

### **总结**

- **`views` 类似于生成器**：两者都通过**惰性求值**提高效率，避免不必要的计算和内存占用。
- **不同场景适用**：
  - **Python 生成器**：更适合生成数据流（如读取文件、无限序列）。
  - **C++ 的 `views`**：更适合对已有数据进行链式转换（如过滤、映射）。

通过这种类比，可以更直观地理解 C++ 的 `views` 的“惰性”特性，但也要注意它们在数据来源和实现细节上的差异。

太牛逼了，给STL新特性跪了：
![](C:\Users\QZS\AppData\Roaming\marktext\images\2025-04-21-19-55-41-image.png)

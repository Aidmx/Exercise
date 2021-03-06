
# 模板方法

## 实现方式

- 分析目标算法， 确定能否将其分解为多个步骤。 从所有子类的角度出发， 考虑哪些步骤能够通用， 哪些步骤各不相同。
-  创建抽象基类并声明一个模板方法和代表算法步骤的一系列抽象方法。 在模板方法中根据算法结构依次调用相应步骤。 可用 final 最终修饰模板方法以防止子类对其进行重写。
-  虽然可将所有步骤全都设为抽象类型， 但默认实现可能会给部分步骤带来好处， 因为子类无需实现那些方法。
-  可考虑在算法的关键步骤之间添加钩子。
-  为每个算法变体新建一个具体子类， 它必须实现所有的抽象步骤， 也可以重写部分可选步骤。


## 优点
- 你可仅允许客户端重写一个大型算法中的特定部分， 使得算法其他部分修改对其所造成的影响减小。
- 你可将重复代码提取到一个超类中。

## 缺点
- 部分客户端可能会受到算法框架的限制。
- 通过子类抑制默认步骤实现可能会导致违反里氏替换原则。
- 模板方法中的步骤越多， 其维护工作就可能会越困难。


## 与其他模式的关系
- 工厂方法模式是模板方法模式的一种特殊形式。 同时， 工厂方法可以作为一个大型模板方法中的一个步骤。
- 模板方法基于继承机制： 它允许你通过扩展子类中的部分内容来改变部分算法。 策略模式基于组合机制： 你可以通过对相应行为提供不同的策略来改变对象的部分行为。 模板方法在类层次上运作， 因此它是静态的。 策略在对象层次上运作， 因此允许在运行时切换行为。
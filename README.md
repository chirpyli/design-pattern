# design-pattern
Design pattern learning, blogs and codes.

参考书籍：《设计模式——可复用面向对象软件的基础》

核心： 抽象、复用

## 面向对象设计原则

- 依赖倒置原则（DIP）
    - 高层模块（稳定）不应该依赖于低层模块（变化），二者都应该依赖于抽象（稳定）。
    - 抽象（稳定）不应该依赖于实现细节（变化），实现细节应该依赖于抽象（稳定）。
- 开放封闭原则（OCP）
    - 对扩展开发，对更改封闭。
    - 类模块应该是可扩展的，但是不可修改。
- 单一职责原则（SRP）
    - 一个类应该仅有一个引起它变化的原因。
    - 变化的方向隐含着类的责任。
- Liskov替换原则（LSP）
    - 子类必须能够替换它们的基类（IS-A）。
    - 集成表达抽象类型。
- 接口隔离原则（ISP）
    - 不应该强迫客户程序依赖它们不用的方法。
    - 接口应该小而完备。
- 优先使用对象组合，而不是类继承
    - 类继承通常为“白箱复用”，对象组合通常为“黑箱复用”。
    - 继承在某种程度上破坏了封装性，子类父类耦合度高。
    - 而对象组合则只要求被组合的对象具有良好定义的接口，耦合度低。
- 封装变化点
    - 使用封装来创建对象之间的分界层，让设计者可以在分解者的一侧进行修改，而不会对另一侧产生不良的影响，从而实现层次间的松耦合。
- 针对接口编程，而不是针对实现编程
    - 不将变量类型声明为某个特定的具体类，而是 声明为某个接口。
    - 客户程序无需获知对象的具体类型，只需要知道对象所具有的接口。
    - 减少系统中各部分的依赖关系，从而实现“高内聚、松耦合”的类型设计方案。   



## 目录
### 创建型
[工厂模式（Factory Pattern）](https://blog.csdn.net/s_lisheng/article/details/71438616) —— 定义一个用于创建对象的接口，让子类决定将哪一个类实例化，Factory Method使一个类的实例化延迟到其子类。

[抽象工厂模式（Abstract Factory Pattern）](https://blog.csdn.net/s_lisheng/article/details/71438616) —— 提供一个创建一系列相关或互相依赖对象的接口，而无需指定它们具体的类。

[单例模式（Singleton Pattern）](./SingletonPattern/单例模式.md) —— 保证一个类仅有一个实例，并提供一个访问它的全局访问点。

[原型模式（Prototype Pattern）](./PrototypePattern/原型模式.md) —— 用原型实例指定创建对象的种类，并且通过拷贝这个原型来创建新的对象。

[建造者模式（Builder Pattern）](./BuilderPattern/建造者模式.md) —— 将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
### 结构型
适配器模式（Adapter Pattern） —— 将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

[桥接模式（Bridge Pattern）](./BridgePattern/桥接模式.md)—— 将抽象部分与实现部分分离，使它们都可以独立的变化。

[装饰器模式（Decorator Pattern）](https://blog.csdn.net/s_lisheng/article/details/80765803)—— 动态地给一个对象添加一些额外的职责。就扩展功能而言，Decorator模式比生成子类方式更为灵活。
外观模式（Facade Pattern） —— 为子系统中的一组接口提供一个一致的界面，Facade模式定义了一个高级接口，这个接口使得这一子系统更加容易使用。

享元模式（Flyweight Pattern） —— 运用共享技术有效地支持大量细粒度的对象。

[代理模式（Proxy Pattern）](https://blog.csdn.net/s_lisheng/article/details/76911639) —— 为其他对象提供一个代理以控制对这个对象的访问。

[组合模式（Composite Pattern）](https://blog.csdn.net/s_lisheng/article/details/80968711) —— 将对象组合成树形结构以表示“部分-整体”的层次结构。Composite使得客户对单个对象和符合对象的使用具有一致性。
### 行为型
责任链模式（Chain of Responsibility Pattern） —— 为解除请求的发送者和接收者之间耦合，而使得多个对象都有机会处理这个请求。将这些对象连成一条，并沿着这条链传递该请求，直到有一个对象处理它。

命令模式（Command Pattern） —— 将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可取消的操作。

解释器模式（Interpreter Pattern） —— 给定一个语言，定义它的文法的一种表示，并定义一个解释器，该解释器使用该表示来解释语言中的句子。

[迭代器模式（Iterator Pattern）](https://blog.csdn.net/s_lisheng/article/details/76960367) —— 提供一种方法顺序访问一个聚合对象中各个元素，而又不需暴露该对象的内部表示。

中介者模式（Mediator Pattern） —— 用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显示地互相引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

备忘录模式（Memento Pattern） —— 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到保存的状态。

[观察者模式（Observer Pattern）](https://blog.csdn.net/s_lisheng/article/details/81737903) —— 定义对象间的一种一对多的依赖关系，以便当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并自动刷新。

状态模式（State Pattern） —— 允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它所属的类。

[策略模式（Strategy Pattern）](https://blog.csdn.net/s_lisheng/article/details/81606938) —— 定义一系列的算法，把它们一个个封装起来，并且使它们可互相替换。本模式使得算法的变化可独立于使用它的客户。

[模板模式（Template Pattern）](https://blog.csdn.net/s_lisheng/article/details/81566111) —— 定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。Template Method使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

访问者模式（Visitor Pattern） —— 表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。

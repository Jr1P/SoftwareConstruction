# Java学习记录

## 和C++的不同

Java中的许多语法和C++一样，但也有些许不同：

- Java的常量修饰符为**final**而不是**const**，虽然**const**是Java的保留字，但是貌似并没有使用

- Java中的String对象是不可变字符串，即创建了一个String对象后不能修改它的字符，不像C++可以直接修改，想要修改字符串时可以先提取想要的字符再拼接上替换的字符串。如：

    ```java
    greeting = greetins.substring(0, 3) + "P!";
    ```

    这样做是否会降低运行效率呢？ 看起来好像修改一个代码单元要比创建一个新字符串更加简洁。答案是：也对，也不对。的确， 通过拼接"**Hel**"和"**p!**"来创建一个新字符串的效率确实不高。但是，不可变字符串却有一个优点：编译器可以让字符串共享。
    为了弄清具体的工作方式，可以想象将各种字符串存放在公共的存储池中。字符串变量
    指向存储池中相应的位置。如果复制一个字符串变量， 原始字符串与复制的字符串共享相同
    的字符。

    有些时候，需要由较短的字符串构建字符串，采用上述字符串链接方式的效率较低，每次连接字符串都会构建一个新的String对象，既耗时又浪费空间，为了避免这个问题的发生Java还提供了StringBuilder类。首先，构建一个空的字符串构造器：

    ```java
    StringBuilder builder = new StringBuilder();
    ```

    每次需要添加时就调用append方法

    ```java
    builder.append(ch); // 单个字符
    builder.append(str); // 一个字符串
    ```

- 在Java应用程序的main方法中，命令行输入参数时，程序名不会存储在参数数组里，C++会将程序名存在参数数组的首元素

- 在C++中，可以在类的外面定义方法，如果在类的内部定义方法，这个方法将自动地称为内联(inline)方法；在Java中，所有的方法都必须在类的内部定义，但并不表示它们是内联方法。是否将某个方法设置为内联方法是Java虚拟机的任务。即时编译器会监视调用那些简洁、经常被调用、没有被重载以及可优化的方法。

- 在C++中，继承是用':'实现的，而Java中的关键字是**extends**，在Java中继承只有公有继承，没有C++里的保护继承和私有继承；在Java中使用关键字**super**调用超类的方法，而C++中采用超类名加上**域解析运算符::**的形式；Java中子类要调用超类中的构造器时只需调用**super(arg1, arg2, ……)**，而C++使用初始化列表；而且Java中不存在多重继承，即不允许一个类有多个超类，而C++中可以

- Java对某种类的对象进行排序时，可以有多种实现方式。一种是通过Comparator接口，以给Person按height排序为例

    ```java
    public class XXXComparator implements Comparator<Person> {
    	@Override
        public int compare(Person p1, Person p2) {
            return p1.height < p2.height ? -1 : p1.height > p2.height ? 1 : 0;
        }
    }
    // List<Person> persons = new ArrayList<>();
    // Collections.sort(persons, new XXXComparator);
    ```

    第二种是通过Comparable接口

    ```java
    public class Person implements Comparable<Person> {
    	// some codes
        // ...
        // ...
        public int compareTo(Person arg) {
            return height < arg.height ? -1 : height > arg.height ? 1 : 0;
        }
    }
    // Collections.sort(persons);
    ```

- 关于抽象类：Java的抽象类使用关键字**abstract**来表示，抽象类中**可以不**包含抽象方法，但是包含抽象方法的类必须声明为抽象类，且不能被实例化，即不能**创建**这个类的对象，但是可以**定义**一个抽象类的对象变量，但它只能引用非抽象子类的对象，如下面例子中，Person是抽象类，Student和Employee类是它的子类：

    ```java
    Person[] people = new Person[2];
    people[0] = new Employee(. . .);
    people[1] = new Student(. . .);
    for (Person p : people)
    System.out.println(p.getName () + ", " + p.getDescription())；
    ```

    由于不能构造抽象类Person的对象，所以变量 p 永远不会引用 Person 对象， 而是引用诸如 Employee 或 Student 这样的具体子类对象，只要这些对象中定义了getDescription()方法，p就可以调用；而在C++中有一种函数，叫纯虚函数，利用关键字**virtual**以及在函数定义尾部添加**=0**来标识，只要有一个纯虚函数，这个类就是抽象类

- Object类是Java中所有类的始祖，在Java中每个类都是由它扩展而来的，只有基本类型 ( primitive types)不是对象，例如数值、字符和布尔类型的值都不是对象。所有的数组类型，不管是对象数组还是基本类型的数组都扩展了Object类。由于Object类是所有类的始祖，它的熟悉这个类提供的方法十分重要。(在C++中没有像Object这样的始祖类，不过每个指针都可以转换成void*指针

    - equals方法：检测一个对象是否相等，且是通过两个对象是否具有相同的引用(所以其实没有太大用处)
    - hashCode方法：由对象导出一个基本没有规律的整型值散列码，如果两对象不同，它们的散列码基本不会相同；注意hashCode产生的散列码与equals的实现有关，如果重新定义了equals方法，就必须重新定义hashCode方法；Equals与hashCode 的定义必须一致：如果 x.equals(y) 返回true，那么 x.hashCode()就必须与y.hashCode()具有相同的值。

在进行类型转换之前，先查看一下是否能够成功地转换。这个过程简单地使用instanceof 操作符就可以实现。 例如：

```java
if (staff[1] instanceof Manager) {
	boss = (Manager) staff[1];
}
```

最后， 如果这个类型转换不可能成功， 编译器就不会进行这个转换。

在 Java 程序设计语言中，对象变量是多态的。一个超类变量既可以引用一个自身类对象，也可以引用它的任何一个子类的对象

---

## Java接口

### 介绍

首先介绍一下接口(interface)技术，这种技术主要用来**描述**类具有什么功能，而**并不给出**每个功能的**具体实现**。由类来实现(implement)一个或多个接口，并在需要接口的地方，随时使用实现了相应接口的对象。

### 细节

在Java中，接口不是类，而是对类的一组需求描述，这些类要遵从接口描述的统一格式进行定义。接口中的所有方法自动地属于public，因此，在接口中**声明**方法时，不必提供关键字public，但是在类中实现接口中声明的方法时，需要提供关键字public；了解接口不能干什么也很重要：接口**绝不能含有实例域**，在Java SE 8之前也不能在接口中实现方法，不过Java SE 8之后可以在接口中提供简单方法，当然这些方法不能引用实例域。提供实例域和方法实现的任务应该由实现接口的那个类来完成。因此，可以将接口看成是没有实例域的抽象类，不过它们还是有一定的区别：每个类只能从一个类继承，即只能有一个超类；而每个类可以实现多个接口

### 默认方法

关键字default，默认方法：在接口中可以实现默认方法，如

```java
public interface Comparable<T> {
    default int compareTo(T other) { return 0; }
} // 如果在实现了Comparable接口的类中没有实现该函数，就会采用默认方法
```

默认方法有一个重要的用法**接口演化**，以Collection接口为例，这个接口作为Java的一部分已经有很多年了。假设很久以前你提供了这样一个类：

```java
public class Bag implements Collection { ... }
```

后来又为这个接口增加了一个stream方法，如果stream方法不是默认方法，那么原先实现了Collection接口的Bag类就会发生编译错误，因为Bag类中没有实现stream方法。非默认方法不能保证**源代码兼容**

### 默认方法冲突

如果先在一个接口中将一个方法定义为默认方法，然后又在超类或另一个接口中定义了同样的方法，会发生冲突，诸如Scala和C++等语言对于解决这种二义性有一些复杂的规则。幸运的是，Java的相应规则要简单得多。规则如下：

1. **超类优先**，如果超类提供了一个具体方法，同名而且有相同参数类型的**默认方法会被忽略**
2. **接口冲突**，如果一个超接口提供了一个默认方法，另一个接口提供了一个同名而且参数类型(不论是否是默认参数)相同的方法，必须覆盖这个方法来解决冲突，让程序员来解决这个二义性

### 接口的例子

#### 接口与回调

**回调(callback)**是一种常见的设计模式，在这种模式中，可以指定某个事件发生时应该采取的动作，比如java.wing包中有一个Timer类，可以间隔一段时间调用某个函数，将某个类的对象传递给定时器，前提是该类实现了java.awt.event包中的ActionListener接口，下面是这个接口：

```java
public interface ActionListener {
	void actionPerformed(ActionEvent event);
}
```

当间隔的时间到了，定时器就会调用实现了的actionPerformed方法，下面是一个例子

```java
public TimerPrint implements ActionListener {
	public void actionPerformed(ActionEvent event) {
        System.out.println("Now time is" + new Data());
    }
}
```

接下来，构造这个类的一个对象，并将它传递给Timer构造器

```java
ActionListener listener = new TimePrinter();
Timer t = new Timer(10000, listener);
```

Timer构造器的第一个参数是时间间隔，单位是ms，第二个参数是传入的对象。最后，启动定时器：t.start();	之后每隔10秒都会显示时间

#### Comparator接口



----

许多程序员习惯于将每一个类存在一个单独的源文件中。例如，将Employee类存放在文件 Employee.java中，将EmployeeTest类存放在文件EmployeeTest.java中。如果喜欢这样组织文件，将可以有两种编译源程序的方法。一种是使用通配符调用Java编译器：

> javac Employee*.java

于是，所有与通配符匹配的源文件都将被编译成类文件。或者键人下列命令：

> javac EmployeeTest.java

第二种方式并没有显式地编译Employee.java，然而，当Java编译器发现EmployeeTest.java使用了Employee类时会查找名为Employee.class 的文件。如果没有找到这个文件，就会自动地搜索Employee.java, 然后对它进行编译。更重要的是：如果Employee.java版本比已有的 Employee.class文件版本新时，Java编译器就会自动地重新编译这个文件

方法可以访问所属类的私有特性, 而不仅限于访问隐式参数的私有特性

一个源文件只能包含一个公有类，并且文件名必须与公有类匹配。因此，编译器很容易
定位公有类所在的源文件。

## Java 泛型设计


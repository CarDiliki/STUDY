## WebScrap

### Selectorlib的基本用法

1. 第一步就是通过`extract.yaml`文件生成`extractor`
2. 第二步就是使用`extractor`以字典的形式提取出来预先在`extract.yaml`中定义好的键值对

```Python
extractor = selectorlib.Extractor.from_yaml_file("extract.yaml")
value = extractor.extract(src: str)["key"]
```

```yaml
# extract.yaml
key: 
css: #id
```



### PyQt6

GUI应用的思路：一个 window 对应一个class。

基本类
- QApplication
  一切的基础，一开始就要实例化，然后调用`.exec()`
- QWidget
	- Label
	- LineEdit
	- ComboBox
	- PushButton
		- .clicked.connect(self.func1)
	- QTableWidget与QTableWidgetItem
- QMainWindow
	- setCentralWidget
	- .menuBar().addMenu(QAction)
	- addToolBar
- QAction
	- 使用QIcon 在实例化一个Action时为其赋予图标
	- Action就是一个操作
	- QIcon("Path/to/icons.png ")
- QDialog
	- 也应该继承，去自己实现自己的子类
- QToolBar
	- addAction，ToolBar里面放的就是Action
- QLayOot
	- QGridLayout
	- QVBoxLayout
- QMessageBox

- PyQt6 在上述基本类，以mainwindow为基础构建整个window，可以为其添加菜单栏、状态栏、工具栏等等，而mainwindow的核心内容则通过setCentralWidget 设定。

- 工具栏一般是菜单栏中选项的快捷方式，一个快捷的Button。而不管是这个button和菜单栏中的选项都是 对应的 一个 QAction(可以理解为一个操作)。

- 部分可响应的widget 可访问他的各种状态(例如 ： clicked)并通过`.connect(func1)`注册回调

- 当回调需要弹出窗口时要用到`QDialog`类生成会话窗口。
  同理，如前述，应该为这个会话窗口单独写一个类实现

- 每个window都需要实例化各自的 layout对象来指明各个widget如何排布

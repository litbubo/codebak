# 这是一个示例 Python 脚本。

# 按 Shift+F10 执行或将其替换为您的代码。
# 按 双击 Shift 在所有地方搜索类、文件、工具窗口、操作和设置。
import ctypes
import inspect
import threading
import time

i = 10

def _async_raise(tid, exctype):
    """Raises an exception in the threads with id tid"""
    if not inspect.isclass(exctype):
        raise TypeError("Only types can be raised (not instances)")
    res = ctypes.pythonapi.PyThreadState_SetAsyncExc(ctypes.c_long(tid), ctypes.py_object(exctype))
    if res == 0:
        raise ValueError("invalid thread id")
    elif res != 1:
        # """if it returns a number greater than one, you're in trouble,
        # and you should call it again with exc=NULL to revert the effect"""
        ctypes.pythonapi.PyThreadState_SetAsyncExc(tid, None)
        raise SystemError("PyThreadState_SetAsyncExc failed")


def stop_thread(thread):
    _async_raise(thread.ident, SystemExit)

def testchild():
    print(threading.get_ident())
    while True:
        print(2)
        time.sleep(0.5)

def test():
    print(i)
    # print(threading.getName())
    print(threading.get_ident())
    t2 = threading.Thread(target=testchild)
    t2.start()
    time.sleep(5)
    stop_thread(t2)

def print_hi(name):
    global i
    i = 12
    t1 = threading.Thread(target=test)
    t1.start()

    # stop_thread(t1)
    print(name)
    # print(threading.getName())
    print(threading.get_ident())


# 按间距中的绿色按钮以运行脚本。
if __name__ == '__main__':
    print_hi('PyCharm')

# 访问 https://www.jetbrains.com/help/pycharm/ 获取 PyCharm 帮助

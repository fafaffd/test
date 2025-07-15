.PHONY: all static dynamic test clean

# 编译器和编译选项
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# 目录结构
SRCDIR = src
INCDIR = include
BUILDDIR = build
LIBDIR = lib
TESTDIR = test

# 源文件和目标文件
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# 库文件名称
STATIC_LIB = $(LIBDIR)/libmylib.a
DYNAMIC_LIB = $(LIBDIR)/libmylib.dylib

# 默认目标
all: static dynamic

# 创建目录
$(shell mkdir -p $(BUILDDIR) $(LIBDIR))

# 编译源文件
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 构建静态库
static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJECTS)
	ar rcs $@ $^

# 构建动态库
dynamic: $(DYNAMIC_LIB)

$(DYNAMIC_LIB): $(OBJECTS)
	$(CXX) -shared -o $@ $^

# 测试程序
test: $(TESTDIR)/test.cpp $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) -L$(LIBDIR) $< -o $(TESTDIR)/test -lmylib
	chmod +x test

# 清理
clean:
	rm -rf $(BUILDDIR) $(LIBDIR) $(TESTDIR)/test

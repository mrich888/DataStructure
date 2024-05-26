#自定义变量
OBJ=$(patsubst %.c , %.o , $(wildcard ./*.c));
TARGET=main

#动态库
LDFALGS=-L./src_so
LIBS=-lSoAVLT.so


#使用编写$(TARGET) 必须要加 '$' 符号
# gcc $^ -o $@
#@ : @$(CC) $^ -o $@  不显示编译过程

$(TARGET):$(OBJ)
	$(CC) $^ -o $@  

# 模式匹配
%.o :%.c
	$(CC) -c $^ -o $@

#设置伪文件
.PHONY:clean
clean:
	@$(RM) *.o $(TARGET)
#@rm -rf *.o TARGET
# make -s == make clean

show:
	@echo $(RM);
	@echo $(CC);
	@echo $(CXX);
#wildcard 查看某个目录下所有的点c文件
	@echo $(wildcard ./*.c);
#patsubst 将所有.c文件设置成.o文件
	@echo $(patsubst %.c , %.o , $(wildcard ./*.c));
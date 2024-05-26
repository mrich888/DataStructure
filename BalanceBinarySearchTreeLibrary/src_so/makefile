OBJ=$(patsubst %.c , %.o , $(wildcard ./*.c))
TARGET=libSoAVLT.so

$(TARGET):$(OBJ)
	$(CC) -shared -fPIC $^ -o $@
	sudo cp $(TARGET) /usr/lib/

%.o:%.c
	$(CC) -c $^ -o $@

clean:
	$(RM) $(OBJ) $(TARGET) 
	$(RM) /usr/lib/libSoAVLT.so
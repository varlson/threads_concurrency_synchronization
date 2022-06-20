SEM_RC:
	g++ -pthread SEM_RC.cpp -o sem
RUN_SEM_RC:
	./sem

COM_RC:
	g++ -pthread COM_RC.cpp -o com
RUN_COM_RC:
	./com

COM_ATOMIC:
	g++ -std=c++17 ATOMIC.cpp -o atomic -lpthread
RUN_ATOMIC:
	./atomic
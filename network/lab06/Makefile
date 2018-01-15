VPATH = ../wrapper:../unit:../libfree:../lib
bin	 = ../bin
srvl = tcpservselect.o Unistd.o str_echo.o sig_chld.o Select.o Socket.o error.o Writen.o writen.o
srvlPoll = tcpservpoll.o Unistd.o str_echo.o sig_chld.o Select.o Poll.o Socket.o error.o Writen.o writen.o
srvl: $(srvl)
	gcc -g $(srvl) -o $(bin)/e_srvl;\
	make clean-obj
srvlPoll: $(srvlPoll)
	gcc -g $(srvlPoll) -o $(bin)/e_srvlPoll;\
	make clean-obj

clean:
	rm -rf $(bin)/e_*;\
	rm -rf ./*.o
clean-obj:
	rm -rf ./*.o

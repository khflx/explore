VPATH = ../wrapper:../unit:../libfree:../lib
bin	 = ../bin
srvl = echoSrvl.o Unistd.o str_echo.o sig_chld.o signal_posix.o  Socket.o error.o Writen.o writen.o
cli  = echocli.o str_cli.o Inet.o Stdio.o sig_pipe.o Readline.o readline.o Socket.o Unistd.o error.o Writen.o writen.o
srvl: $(srvl)
	gcc -g $(srvl) -o $(bin)/e_srvl;\
	make clean-obj
cli: $(cli)
	gcc -g $(cli) -o $(bin)/e_cli;\
	make clean-obj
clean:
	rm -rf $(bin)/e_*;\
	rm -rf ./*.o
clean-obj:
	rm -rf ./*.o

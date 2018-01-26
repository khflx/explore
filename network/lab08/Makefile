VPATH = ../wrapper:../unit:../libfree:../lib
bin	 = ../bin
srvl = udpsrvl.o Socket.o error.o dg_echo.o
cli = udpcli.o Inet.o Stdio.o Socket.o error.o sock_ntop.o Stdlib.o dg_cli.o
test = test.o Inet.o Socket.o error.o
tcpudpSrvl = tcp+udpselectserv.o Select.o Socket.o error.o str_echo.o Writen.o writen.o Unistd.o  sig_chld.o
srvl: $(srvl)
	gcc -g $(srvl) -o $(bin)/udpsrvl;\
	make clean-obj
cli: $(cli)
	gcc -g $(cli) -o $(bin)/udpcli;\
	make clean-obj
srvlBoth: $(tcpudpSrvl)
	gcc -g $(tcpudpSrvl) -o $(bin)/srvlBoth;\
	make clean-obj
test: $(test)
	gcc -g $(test) -o $(bin)/test;\
	make clean-obj
clean:
	rm -rf $(bin)/e_*;\
	rm -rf ./*.o
clean-obj:
	rm -rf ./*.o

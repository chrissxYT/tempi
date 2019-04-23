all:
	@gcc tempi_rcv.c -O3 -s -lwiringPi -o tempi_rcv
	@gcc tempi_svr.c -O3 -s -o tempi_svr
clean:
	@rm -f tempi_rcv tempi_svr
install: all
	@cp tempi_rcv /usr/bin/tempi_rcv
	@cp tempi_svr /usr/bin/tempi_svr
	@git clone https://git.suckless.org/quark
	@cd quark
	@make install
	@cd ..
	@rm -rf quark

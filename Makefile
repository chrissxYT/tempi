all:
	@g++ tempi.c -O3 -s -lwiringPi -o tempi
clean:
	@rm -f tempi
install: all
	@cp tempi /usr/bin/tempi
	@git clone https://git.suckless.org/quark
	@cd quark
	@make install
	@cd ..
	@rm -rf quark

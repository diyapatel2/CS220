all: sorter estimator toggle 

sorter:
	gcc sorter.c -o sorter

estimator:
	gcc estimator.c estimator.S estimator_zero.S -m32 -std=c89 -g -o estimator

toggle: 
	gcc driver.c toggle.S -m64 -std=c89 -g -o driver 
.PHONY: clean
clean:
	rm -rf sorter.o toggle estimator

include test.make

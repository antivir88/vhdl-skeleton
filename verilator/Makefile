clean:
	rm -rf obj_dir
	rm prog

# холостая компиляция
vbuild:
	verilator -Wall -cc -I.. main.v
	cd obj_dir && make -f Vmain.mk

# компиляция с вейвформами
vwbuild:
	verilator -Wall -cc --trace -I.. main.v
	cd obj_dir && make -f Vmain.mk

# компиляция в автобусе
tbuild:
	iverilog -g2005-sv -DICARUS=1 -o test main.v tmain.v
	vvp test

# обёртка с выключенным трейсом
cbuild:
	g++ -o prog -DTRACED=false -I/usr/share/verilator/include main.cpp /usr/share/verilator/include/verilated.cpp obj_dir/Vmain__ALL.a

# обёртка с включенным трейсом
ctbuild:
	g++ -o prog -DTRACED=true -I/usr/share/verilator/include main.cpp /usr/share/verilator/include/verilated.cpp /usr/share/verilator/include/verilated_vcd_c.cpp obj_dir/Vmain__ALL.a

# ранеры
maketest: vwbuild ctbuild
makerun: vbuild 

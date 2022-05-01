# Falco

Falco is a small soc which has a certain number of peripherals mounted on the wishbone bus, and its core is a 32-bit pipeline and sequential processor written in verilog.

## Implemented ISAs

* RV32I

* Zicsr extension

* M extension

* Machine-level ISA

* ...

## Features

* 32-bit.

* A load/store architecture.

* A pipelined architecture.

* Two modes(M & U).

* Support exception & interrupt

* Address space(wishbone B2):

                            |----0xffff_ffff----|
                            |                   |
                            |                   |
                            |                   |
                            |                   |
                            |                   |
                            |      unused       |
                            |                   |
                            |                   |
                            |                   |
                            |                   |
                            |                   |
                            |                   |
                            |-------------------| <--- 0x6000_0000
                            |        ram        |
                            |-------------------| <--- 0x5000_0000
                            |       clint       |
                            |-------------------| <--- 0x4000_0000
                            |        plic       |
                            |-------------------| <--- 0x3000_0000
                            |        gpio       |
                            |-------------------| <--- 0x2000_0000
                            |        uart       |
                            |-------------------| <--- 0x1000_0000
                            |        rom        |
                            |-------------------| <--- 0x0000_0000

* ...

### Some extra features are planned for the future or under development

* branch predictor

* sdram controller

* flash controller

* supervisor modes

* RV32A support

* debug support(JTAG)

* Replace with AXI4

* MMU(Sv32, for running xv6-riscv or others)

* ...

    Due to lack of time, I will continue to complete the above plans after the end of this semester (July and August 2022).

## Geting Started

```$git clone https://github.com/gzzyyxh/Falco```

Synthesis via Quartus Prime

```$cd cpu```

**Notice**

* Your FPGA board must meet the following conditions:


$ logic elements >= 10,877

$ registers >= 4,155


* ROM and RAM are implemented using Altera IP core. You should pay attention to this.

The actual resource usage depends on EDA, and the above data is for reference only

```cd os```

Compile RVOS

```make```

Connecting serial port equipment

```sudo apt-get install minicom```

```sudo minicom -s```

Select ```serial port steup``` and configure serial device as the corresponding board, ```Bps/Par/Bits``` is ```115200 8N1```.

```sudo minicom```

![welcome to Falco](./img/welcome.png)

## Refrences

## Sources
